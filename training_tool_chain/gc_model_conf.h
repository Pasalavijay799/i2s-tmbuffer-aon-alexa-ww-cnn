//! Auto Generated on  05_08_2026_11_12_48_.  Version: 9.1.3-dirty
//! Do Not Modify this file!!
//! ---------------------------------------------------------------------------------------------

//! Gpx-Utils Command:
//! gpx-utils.exe  --EmitModelConfig --OPMWidth=32 --WTMWidth=16 --BT=S7 --InputModelType=CNN --packer_out=-1 --shiftAlgorithm=ArmShift C:\AmbientScientific\setup\chip\fw\applications\i2s-tmbuffer-aon-alexa-ww-cnn\training_tool_chain\python\temp\GC_05_08_2026_11_12_30\final_try.onnx.mlir -o C:\AmbientScientific\setup\chip\fw\applications\i2s-tmbuffer-aon-alexa-ww-cnn\training_tool_chain\ 



#define GC_DEBUG_MODE
#define CNN_MODEL
#define USE_COMPILER_MICROCODE

typedef struct LayerQuantization {
  int layerType;
  int activationType;
  float leakageCoeff;
  int effectiveSize;
  float* effectiveScale;
  float* effectiveBiasDefault;

  int effectiveBiasSparseSize;
  int* effectiveBiasIndex;
  float* effectiveBiasVal;

  int effectiveSize2;
  float* effectiveScale2;
  float* effectiveBias2;

  int inputSize;
  float* inputScale;
  int* inputZeroPoint;

  int weightSize;
  float* weightScale;
  int* weightZeroPoint;

  int biasSize;
  float* biasScale;
  int* biasZeroPoint;

  int outputSize;
  float* outputScale;
  int* outputZeroPoint;
  
  int actSize;
  float* actScale;
  int* actZeroPoint;

  int bnMulOpSize;
  float* bnMulOpEScale;
  float* bnMulOpEBias;
  
  int bnAddOpSize;
  float* bnAddOpEScale;
  float* bnAddOpEBias;	
}LayerQuantization;


#define dtype  uint32_t

uint32_t* v_INPUTS_PAD =  0;
uint32_t* v_OUTPUTS =  0;
uint32_t N_OF_FRAMES;

uint32_t TOTAL_INPUTS;
uint32_t MAX_INPUTS_PER_BATCH;

extern void write_wtm_0(int64_t val);
extern void write_pregs_0(int64_t val);
extern void wr_generic_ucode_0(int64_t val);

void (*wtm_ptr[])(int64_t) = {write_wtm_0};
void (*preg_ptr[])(int64_t) = {write_pregs_0};
void (*ucode_ptr[])(int64_t) = {wr_generic_ucode_0};

const uint32_t MAX_INPUTGRIDS_PER_FRAME = 13;
const uint32_t MAX_INPUTS_PER_OPM_LOC_CNN = 31;
const uint32_t MAX_KERNELS_PER_SPLIT =  20;
const uint32_t MAX_INPUTS_PER_OPM_LOC_DNN =  20;
const uint32_t MAX_OPM_LOCS = 8;
const int32_t LSTM_DIRECTION = 0;
const int32_t QUANTIZED_MAX_SCALE_VALUE = 127;
const uint32_t OPM_WIDTH =	32;
const uint32_t WTM_WIDTH =	16;
const uint32_t NO_OF_CORES =	5;

typedef struct LayerBatchNorm {
  int layerNumber;
  int layerDepth;
  int actLayerPos;
  float* bnMulOpValues;
  float* bnAddOpValues;
}LayerBatchNorm;

typedef struct {
        uint32_t INPUT_DIM_H;
        uint32_t INPUT_DIM_W;
        uint32_t TRANSPOSE_INPUT;
        uint32_t CHANNEL_OPTION;
        uint32_t N_OF_FEATURES;
        uint32_t N_OF_LAYERS;


	uint8_t  SHIFT_ALGO;
	int8_t packer_out;
	int8_t IS_MODEL_HAVE_BN;
        int8_t size_quant;
	int8_t inputFuncType;

        uint32_t* N_OF_BLOCKS; 
        uint32_t* N_OF_CHANNELS; 
        uint32_t* KERNEL_DIM; 
        uint32_t* KERNEL_STRIDE; 
        uint32_t* LAYER_ACT_FLAG; 
        uint32_t* N_OF_OUTPUT_NEURONS; 
        uint32_t* LAYER_POOL_FLAG; 
        uint32_t* POOL_DIM; 
        uint32_t* POOL_STRIDE; 
        uint32_t* POOL_PADDING_SIZE; 
        uint32_t* PADDING_SIZE; 
        uint32_t* LAYER_TYPE; 
 				
        uint16_t*  LAYER_DEPTH; 
 		
        int32_t* LSTM_TIME_STEP_COUNT; 
        int32_t* LSTMHiddenStateShape; 
 	
        uint32_t* N_OF_LSTM_OUTPUT_NEURONS; 
        uint32_t* LSTM_INPUTS_PER_EACH_TIME; 
        uint32_t* RETURN_SEQUENCES; 
        uint32_t* RETURN_STATES; 
        uint32_t* STATE_PROP; 
 	
        uint32_t* LSTM_ACTIVATION; 
        uint32_t* LSTM_RECACTIVATION; 
 	
        float* coeffOfLeakage; 
        int* convLayerBNStatus;
	int* BNLayerInfoFromH5File;
        LayerBatchNorm* layerBatchNormDetails;
	LayerQuantization* layerquantDetails;
} modelConfig;

modelConfig load_Models[] = { 


{30, 16, 0, 4, 480, 5, 4, -1, 0, 0, 3 ,
 (uint32_t[]){1, 1, 1, 1, 1, },
 (uint32_t[]){1, 10, 20, 0, 0, },
 (uint32_t[]){3, 3, 3, 3, 3, 3, 0, 1, 0, 1, },
 (uint32_t[]){1, 1, 1, 1, 1, 1, 0, 0, },
 (uint32_t[]){2, 2, 2, 2, 3, },
 (uint32_t[]){10, 20, 30, 30, 2, },
 (uint32_t[]){1, 1, 1, },
 (uint32_t[]){2, 2, 2, 2, 2, 2, },
 (uint32_t[]){2, 2, 2, 2, 2, 2, },
 (uint32_t[]){0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
 (uint32_t[]){1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, },
 (uint32_t[]){2, 2, 2, 1, 1, },
 (uint16_t[]){0, 0, 0, },
 (int32_t[]){},
 (int32_t[]){},
 (uint32_t[]){},
 (uint32_t[]){},
 (uint32_t[]){},
 (uint32_t[]){},
 (uint32_t[]){},
 (uint32_t[]){},
 (uint32_t[]){},
 (float[]){0.00000000000, 0.00000000000, 0.00000000000, 0.00000000000, 0.00000000000, },
 (int[]){0, 0, 0, 0, 0, },
 (int[]){0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
 (LayerBatchNorm[]) {
{1, 0, 0,
 (float[]){},
 (float[]){}},
{2, 0, 0,
 (float[]){},
 (float[]){}},
{3, 0, 0,
 (float[]){},
 (float[]){}},
{4, 0, 0,
 (float[]){},
 (float[]){}},
{5, 0, 0,
 (float[]){},
 (float[]){}},
},
 (LayerQuantization[]) {} // This works because of gcc, this is non standard c
},

};


//! Below include is a text version of microcode,
//! where the contents will be included only when USE_COMPILER_MICROCODE is NOT defined
#include "gc_text_mcode.h"
