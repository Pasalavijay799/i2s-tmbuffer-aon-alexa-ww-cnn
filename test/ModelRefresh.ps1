# Model refresh for Eclipse Debug_ModelReferesh prebuild.
# Single script: SDK path setup (ambient / ambient_env) + gpxCLITool run.
# Console: minimal status.  model_log.txt: full gpxCLITool output from cmd redirect.
#
# Optional env (or test\local-env.ps1): AMBIENT_SETUP, AMBIENT_PYTHON, AMBIENT_ARM_GCC_BIN

# --- User settings (edit for your project) ---
$modelName = "wake-word-model.h5"
$gpxProfile = "5"                                      # gpxCLITool -p
$modelOutDir = "../i2s-tmbuffer-aon-alexa-ww-cnn/"     # gpxCLITool -d

$ErrorActionPreference = "Stop"

$script:LogPath = Join-Path $PSScriptRoot "model_log.txt"

# --- Logging (warnings/errors -> model_log.txt) ---

function Add-ModelLog {
    param(
        [Parameter(Mandatory)][string]$Message,
        [ValidateSet('ERROR', 'WARN')]
        [string]$Level = 'ERROR'
    )
    if ([string]::IsNullOrWhiteSpace($Message)) { return }
    $ts = Get-Date -Format "yyyy-MM-dd HH:mm:ss"
    "[$ts][$Level] $($Message.Trim())" | Add-Content -Path $script:LogPath -Encoding utf8
}

function Test-ModelLogLine {
    param([string]$Line)
    if ([string]::IsNullOrWhiteSpace($Line)) { return $false }
    if ($Line -match '^\s*\+\s*(CategoryInfo|FullyQualifiedErrorId)\s*:') { return $false }
    if ($Line -match 'System\.Management\.Automation\.RemoteException') { return $false }
    return $Line -match '(?i)WARNING|ERROR|Error:|failed|ModuleNotFound|Assertion|not recognized|Command execution Failed|Traceback|Exception'
}

function Import-ModelLogLine {
    param([string]$Line)
    if (-not (Test-ModelLogLine $Line)) { return }
    $level = 'WARN'
    if ($Line -match '(?i)ERROR|Error:|failed|ModuleNotFound|Assertion|not recognized|Command execution Failed|Traceback|Exception') {
        $level = 'ERROR'
    }
    Add-ModelLog -Message $Line -Level $level
}

function Import-ModelLogFromFile {
    param([string]$Path)
    if (-not (Test-Path $Path)) { return }
    Get-Content -Path $Path -ErrorAction SilentlyContinue | ForEach-Object {
        Import-ModelLogLine $_
    }
}

function Write-ModelRefreshFailed {
    param([string]$Reason)
    if ($Reason) { Add-ModelLog -Message $Reason -Level 'ERROR' }
    Write-Host "[MODEL_REFRESH_FAILED] see test\model_log.txt"
    exit 1
}

# --- SDK paths (same as "ambient" -> start.bat -> ambient_env) ---

function Find-AmbientSetupRoot {
    param([string]$StartDir)

    if ($env:AMBIENT_SETUP -and (Test-Path $env:AMBIENT_SETUP)) {
        return (Resolve-Path $env:AMBIENT_SETUP).Path
    }

    $dir = $StartDir
    while ($dir) {
        $tool = Join-Path $dir "tools\generic-compiler\BIN\gpxcli\release\gpxCLITool.exe"
        if (Test-Path $tool) {
            return (Resolve-Path $dir).Path
        }
        $parent = Split-Path $dir -Parent
        if (-not $parent -or $parent -eq $dir) { break }
        $dir = $parent
    }

    $legacy = "C:\AmbientScientific\setup"
    if (Test-Path (Join-Path $legacy "tools\generic-compiler\BIN\gpxcli\release\gpxCLITool.exe")) {
        return $legacy
    }

    return $null
}

function Get-AmbientSdkRoot {
    param([string]$SetupRoot)
    return (Resolve-Path (Join-Path $SetupRoot "..")).Path
}

function Read-LinkedPythonExe {
    param([string]$SetupRoot)

    $envConfig = Join-Path $SetupRoot "sw\ambient-tools\env_config.bat"
    if (-not (Test-Path $envConfig)) { return $null }

    foreach ($line in Get-Content $envConfig -ErrorAction SilentlyContinue) {
        if ($line -match '^\s*set\s+LINKED_PY_EXE=(.+)\s*$') {
            $p = $matches[1].Trim().Trim('"')
            if ($p -and (Test-Path $p)) { return (Resolve-Path $p).Path }
        }
    }
    return $null
}

function Find-AmbientSdkPython {
    param([string]$SetupRoot, [string]$SdkRoot)

    if ($env:AMBIENT_PYTHON -and (Test-Path $env:AMBIENT_PYTHON)) {
        return (Resolve-Path $env:AMBIENT_PYTHON).Path
    }

    $candidates = @()
    $venvPy = Join-Path $SdkRoot "ambient_env\Scripts\python.exe"
    if (Test-Path $venvPy) { $candidates += $venvPy }

    $linked = Read-LinkedPythonExe -SetupRoot $SetupRoot
    if ($linked) { $candidates += $linked }

    if ($SetupRoot) {
        $candidates += Join-Path $SetupRoot "sw\Python310\python.exe"
    }

    foreach ($c in $candidates) {
        if ($c -and (Test-Path $c)) {
            return (Resolve-Path $c).Path
        }
    }
    return $null
}

function Find-ArmGccBin {
    param([string]$SetupRoot)

    if ($env:AMBIENT_ARM_GCC_BIN -and (Test-Path $env:AMBIENT_ARM_GCC_BIN)) {
        return $env:AMBIENT_ARM_GCC_BIN
    }

    if ($SetupRoot) {
        $sdkBin = Join-Path $SetupRoot "sw\xPacks\@xpack-dev-tools\arm-none-eabi-gcc\9.2.1-1.1.1\.content\bin"
        if (Test-Path (Join-Path $sdkBin "arm-none-eabi-ld.exe")) { return $sdkBin }
    }

    $xpacks = Join-Path $env:USERPROFILE "xPacks\@xpack-dev-tools\arm-none-eabi-gcc"
    if (Test-Path $xpacks) {
        $ld = Get-ChildItem -Path $xpacks -Recurse -Filter "arm-none-eabi-ld.exe" -ErrorAction SilentlyContinue | Select-Object -First 1
        if ($ld) { return $ld.Directory.FullName }
    }

    foreach ($base in @("C:\xPacks\@xpack-dev-tools\arm-none-eabi-gcc", "C:\Program Files (x86)\GNU Arm Embedded Toolchain")) {
        if (-not (Test-Path $base)) { continue }
        $ld = Get-ChildItem -Path $base -Recurse -Filter "arm-none-eabi-ld.exe" -ErrorAction SilentlyContinue | Select-Object -First 1
        if ($ld) { return $ld.Directory.FullName }
    }
    return $null
}

function Find-WindowsBuildToolsBin {
    param([string]$SetupRoot)

    $candidates = @()
    if ($SetupRoot) {
        $candidates += Join-Path $SetupRoot "sw\xPacks\@gnu-mcu-eclipse\windows-build-tools\2.12.1-1\.content\bin"
    }
    $candidates += "C:\xPacks\@gnu-mcu-eclipse\windows-build-tools\2.12.1-1\.content\bin"

    foreach ($c in $candidates) {
        if ((Test-Path $c) -and (Test-Path (Join-Path $c "make.exe"))) {
            return $c
        }
    }
    return $null
}

function Get-AmbientToolPathList {
    param(
        [string]$SetupRoot,
        [string]$SdkRoot,
        [string]$PythonExe,
        [string]$VenvRoot
    )

    $venvScripts = Join-Path $VenvRoot "Scripts"
    $pythonDir = Split-Path $PythonExe -Parent
    $gpxCli = Join-Path $SetupRoot "tools\generic-compiler\BIN\gpxcli\release"

    $paths = @()
    if (Test-Path $venvScripts) { $paths += $venvScripts }
    if (Test-Path $pythonDir) { $paths += $pythonDir }

    $paths += @(
        (Join-Path $SetupRoot "tools\generic-compiler\BIN\gpx10_ai_compiler\Release"),
        $gpxCli,
        (Join-Path $SetupRoot "tools\generic-compiler\BIN\llvm-project\Release"),
        (Join-Path $SetupRoot "tools\generic-compiler\BIN\onnx-mlir\Release")
    )

    $ambientTools = Join-Path $SetupRoot "sw\ambient-tools"
    if (Test-Path $ambientTools) { $paths += $ambientTools }

    $winBuild = Find-WindowsBuildToolsBin -SetupRoot $SetupRoot
    if ($winBuild) { $paths += $winBuild }

    $armGccSdk = Join-Path $SetupRoot "sw\xPacks\@xpack-dev-tools\arm-none-eabi-gcc\9.2.1-1.1.1\.content\bin"
    if (Test-Path (Join-Path $armGccSdk "arm-none-eabi-gcc.exe")) { $paths += $armGccSdk }

    $armGcc = Find-ArmGccBin -SetupRoot $SetupRoot
    if ($armGcc) { $paths += $armGcc }

    $jdk = Join-Path $SetupRoot "sw\jdk-14.0.1\bin"
    if (Test-Path $jdk) { $paths += $jdk }

    $jlink = "C:\Program Files (x86)\SEGGER\JLink"
    if (Test-Path $jlink) { $paths += $jlink }

    $paths += @(
        "$env:SystemRoot\system32",
        $env:SystemRoot,
        "$env:SystemRoot\System32\Wbem"
    )

    return ($paths | Where-Object { $_ -and (Test-Path $_) } | Select-Object -Unique)
}

function Initialize-AmbientSdkEnvironment {
    param(
        [string]$SetupRoot,
        [string]$SdkRoot,
        [string]$PythonExe
    )

    $venvRoot = Join-Path $SdkRoot "ambient_env"

    $env:VIRTUAL_ENV = $venvRoot
    Remove-Item Env:PYTHONHOME -ErrorAction SilentlyContinue

    if (Test-Path (Join-Path $venvRoot "Lib\site-packages")) {
        $env:PYTHONPATH = @(
            (Join-Path $venvRoot "Lib\site-packages"),
            (Join-Path $venvRoot "Lib")
        ) -join ';'
    } else {
        Remove-Item Env:PYTHONPATH -ErrorAction SilentlyContinue
    }

    $toolPaths = Get-AmbientToolPathList -SetupRoot $SetupRoot -SdkRoot $SdkRoot -PythonExe $PythonExe -VenvRoot $venvRoot
    $env:AMBIENT_PYTHON = $PythonExe
    $env:PATH = ($toolPaths -join ';')

    return [PSCustomObject]@{
        SdkRoot    = $SdkRoot
        VenvRoot   = $venvRoot
        PathPrefix = ($toolPaths -join ';')
    }
}

function Get-ModelRefreshPaths {
    param([string]$TestDir)

    $workDir = (Resolve-Path $TestDir).Path
    $setupRoot = Find-AmbientSetupRoot -StartDir $workDir
    if (-not $setupRoot) {
        throw @"
Cannot find Ambient setup root (gpxCLITool.exe).
Sync the full Ambient tree or set:  AMBIENT_SETUP=C:\AmbientScientific\setup
"@
    }

    $sdkRoot = Get-AmbientSdkRoot -SetupRoot $setupRoot
    $pythonExe = Find-AmbientSdkPython -SetupRoot $setupRoot -SdkRoot $sdkRoot
    if (-not $pythonExe) {
        throw @"
Cannot find SDK Python (ambient_env).
Open cmd, type:  ambient
Then create ambient_env or set AMBIENT_PYTHON to SDK python.exe
"@
    }

    $toolExe = Join-Path $setupRoot "tools\generic-compiler\BIN\gpxcli\release\gpxCLITool.exe"
    if (-not (Test-Path $toolExe)) {
        throw "gpxCLITool.exe not found at $toolExe"
    }

    $sdkEnv = Initialize-AmbientSdkEnvironment -SetupRoot $setupRoot -SdkRoot $sdkRoot -PythonExe $pythonExe

    return [PSCustomObject]@{
        WorkDir    = $workDir
        SetupRoot  = $setupRoot
        SdkRoot    = $sdkRoot
        PythonExe  = $pythonExe
        ToolExe    = $toolExe
        VenvRoot   = $sdkEnv.VenvRoot
        PathPrefix = $sdkEnv.PathPrefix
    }
}

function Ensure-TensorFlow {
    param([string]$PythonExe)

    $prevEap = $ErrorActionPreference
    $ErrorActionPreference = 'Continue'
    $out = & $PythonExe -c "import tensorflow as tf; print(tf.__version__)" 2>&1
    $exit = $LASTEXITCODE
    $ErrorActionPreference = $prevEap

    foreach ($line in @($out)) {
        Import-ModelLogLine "$line"
    }

    if ($exit -eq 0 -and ($out -notmatch 'ModuleNotFoundError|No module named')) {
        return
    }

    Add-ModelLog -Message "TensorFlow missing; installing into SDK Python (ambient_env) ..." -Level 'WARN'

    $req = Join-Path $PSScriptRoot "requirements-gpxcli.txt"
    if (Test-Path $req) {
        & $PythonExe -m pip install -r $req
    } else {
        & $PythonExe -m pip install "tensorflow==2.15.1" keras tf2onnx onnx
    }

    if ($LASTEXITCODE -ne 0) {
        $msg = "pip install failed. In an 'ambient' cmd run: pip install -r `"$req`""
        Add-ModelLog -Message $msg -Level 'ERROR'
        throw $msg
    }
}

# --- Main (runs when executed with -File, not when dot-sourced) ---

function Invoke-ModelRefresh {
    Write-Host "[MODEL_REFRESH_START]"
    Write-Host "[MODEL_NAME] $modelName"
    Write-Host "[GPX_PROFILE] -p $gpxProfile"

    try {
        if (Test-Path "$PSScriptRoot\local-env.ps1") {
            . "$PSScriptRoot\local-env.ps1"
        }

        $env:PYTHONWARNINGS = "ignore"
        $env:TF_CPP_MIN_LOG_LEVEL = "3"
        $env:TF_ENABLE_DEPRECATION_WARNINGS = "0"

        $paths = Get-ModelRefreshPaths -TestDir $PSScriptRoot
        Set-Location $paths.WorkDir

        Ensure-TensorFlow -PythonExe $paths.PythonExe

        $pathPrefix = $paths.PathPrefix
        if (-not $pathPrefix) {
            throw "SDK PATH not initialized. Run from full Ambient setup tree."
        }
        $makeBin = Find-WindowsBuildToolsBin -SetupRoot $paths.SetupRoot
        if (-not $makeBin) {
            Add-ModelLog -Message "make.exe not found (install SDK xPacks windows-build-tools or set PATH)" -Level 'WARN'
        }

        $toolExe = $paths.ToolExe
        $args = "-m $modelName -d $modelOutDir -p $gpxProfile -w 16 -o 16 -s ArmShift"

        # gpxCLITool prompts for "0" to continue/end (often after build). Piping (echo 0) only
        # feeds stdin at start; use a stdin file so each prompt reads the next "0" automatically.
        $stdinFile = Join-Path $paths.WorkDir "gpx_stdin.txt"
        $modelLog = Join-Path $paths.WorkDir "model_log.txt"
        1..30 | ForEach-Object { "0" } | Set-Content -Path $stdinFile -Encoding ASCII
        $cmd = "set ""PATH=$pathPrefix;%PATH%"" && ""$toolExe"" $args < ""$stdinFile"" > ""$modelLog"" 2>&1"

        $ErrorActionPreference = 'Continue'
        $cmdExe = Join-Path $env:SystemRoot "System32\cmd.exe"
        & $cmdExe /c $cmd
        $toolExitCode = $LASTEXITCODE
        $ErrorActionPreference = 'Stop'
        Remove-Item $stdinFile -Force -ErrorAction SilentlyContinue
        if ($toolExitCode -ne 0) {
            Add-ModelLog -Message "gpxCLITool.exe exited with code $toolExitCode" -Level 'ERROR'
            if (Select-String -Path $modelLog -Pattern "ModuleNotFoundError: No module named 'tensorflow'" -Quiet) {
                Add-ModelLog -Message "Fix: open cmd, type 'ambient', then pip install -r test\requirements-gpxcli.txt" -Level 'ERROR'
            }
            if (Select-String -Path $modelLog -Pattern "arm-none-eabi-ld.*not recognized" -Quiet) {
                Add-ModelLog -Message "Fix: set AMBIENT_ARM_GCC_BIN to ARM GCC bin folder (arm-none-eabi-ld.exe)" -Level 'ERROR'
            }
            if (Select-String -Path $modelLog -Pattern "CreateProcess on BUILD Command failed" -Quiet) {
                Add-ModelLog -Message "Fix: sync setup\sw\xPacks (make, arm-none-eabi-gcc) or run prebuild from 'ambient' cmd" -Level 'ERROR'
            }
            Write-ModelRefreshFailed
        }

        & $cmdExe /c "taskkill /F /IM JLinkGDBServerCL.exe >nul 2>&1"
        & $cmdExe /c "taskkill /F /IM arm-none-eabi-gdb.exe >nul 2>&1"
        & $cmdExe /c "taskkill /F /IM JLink.exe >nul 2>&1"

        Write-Host "[MODEL_REFRESH_DONE]"
        exit 0
    }
    catch {
        Add-ModelLog -Message $_.Exception.Message -Level 'ERROR'
        if ($_.InvocationInfo.PositionMessage) {
            Add-ModelLog -Message $_.InvocationInfo.PositionMessage -Level 'ERROR'
        }
        Write-ModelRefreshFailed
    }
}

if ($MyInvocation.InvocationName -ne '.') {
    Invoke-ModelRefresh
}
