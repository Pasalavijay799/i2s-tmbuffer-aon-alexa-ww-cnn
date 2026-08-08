/*******************************************************************************
* (C) Copyright 2023;  Ambient Scientific Inc
* The attached material and the information contained therein is proprietary
* to Ambient Scientific and is issued only under strict confidentiality
* arrangements.It shall not be used, reproduced, copied in whole or in part,
* adapted,modified, or disseminated without a written license of Ambient Scientific Inc
* It must be returned to Ambient Scientific upon its first
* request.
*
*  File Name           : i2s-tmbuffer-aon-alexa-ww-cnn-application.c
*
*  Description         : GPX10PRO I2S TM-Buffer AON Alexa Wake Word CNN Application
*
*  Change history      :
*
*     Author              Date           Ver                 Description
*  ------------        --------          ---          --------------------------
* Ambient Scientific   6th Apr 2026      0.1               Initial Creation
* User Edit            31st Jul 2026     0.2               Added LED blink on
*                                                           wake word detection
*                                                           (GPIO_PIN_1)
*
*******************************************************************************/

/*******************************************************************************
*                          Include Files
*******************************************************************************/
#include <stdio.h>

#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

#include "trace.h"
#include "sys_clk.h"
#include "hwreg.h"
#include "tm_buffer.h"
#include "sar_adc.h"
#include "i2s.h"
#include "ai_core.h"
#include "fft.h"
#include "wtm.h"
#include "gpio.h"
#include "gc_sensor_data_producer.h"
#include "gpio.h"

#include "spi_oled_ssd1309.h"
/*******************************************************************************
*                          Extern Data Declarations
*******************************************************************************/

/*******************************************************************************
*                          Extern Function Declarations
*******************************************************************************/

/*******************************************************************************
*                          Type & Macro Definitions
*******************************************************************************/
#define NARRAYS						5
#define NRONS						4
#define INPUT_SIZE                  30*16

#define BUFFER_SIZE       			 (480*1)   //1 second buffer
#define PROCESS_SIZE                   10*16
#define OFFSET_SIZE 		    	   480
#define NO_CORE                         5
#define NO_PREG                         16

#define COMPARE_COUNT		((OFFSET_SIZE) /( PROCESS_SIZE))

#define LCD_DISPLAY                      0

/* LED blink parameters for wake-word indication on GPIO_PIN_1 */
#define WAKE_WORD_LED_BLINK_COUNT         3
#define WAKE_WORD_LED_BLINK_DELAY_US      100000   /* ~100ms on / 100ms off */

#ifndef SENSOR_SIM_DEMO
#define ENABLE_WAKE_WORD_STATIC_DATA           1
#else
#define ENABLE_WAKE_WORD_STATIC_DATA           0
#endif
/*******************************************************************************
*                          Static Function Prototypes
*******************************************************************************/

static void wake_word_app_read_task_entry( void *pvParameters );

static void wake_word_app_process_task_entry( void *pvParameters );

static void wake_word_app_process_static_image( void *pvParameters );

static void APP_Start();

static void wake_word_app_config_i2s();

static void wake_word_app_get_preg_data();

static void wake_word_app_enable_i2s();

static void wake_word_ClearPreg(HWREG_CORE_TYPE core) ;
static void wake_word_print_lcd(U8 *string, U32 size);

static void WAKE_WORD_SPI_LCD_INIT();

static void wake_word_led_blink(U8 blink_count, U32 delay_us);
/*******************************************************************************
*                          Static Data Definitions
*******************************************************************************/
static SYS_CLK SysClk;

static SYS_CLK_SOURCE  clock_source;

static U32 master_clk;

static TM_BUFFER wake_word_app_tm_buffer;

static U16 wake_word_app_data[BUFFER_SIZE];

static U32 wake_word_app_data_size;

static U32 wake_word_data_ready;

static U32 wake_word_data_offset;

static U8 wake_word_detect_flag;

static SPI_OLED_Reg  oled;

static SemaphoreHandle_t   aon_semaphore;

static SemaphoreHandle_t   cmd_semaphore;

static GPIO gpio;

U8 *string , length ;

U8 send_time , receive_time ;

static QueueHandle_t WakeWordMsgQueue ;

static QueueHandle_t WakeWordPrintMsgQueue ;

static t_GPX_SENSOR_DATA wake_word_compil_msg ;

static HWREG_CORE_TYPE core = CMD;

static uint32_t wake_word_ucode [] = {

			0x00000000,  //Nop
			0xD0000890,  //SETBUFF
			0x68000000,  //WRREG 16 = 0  //weight addr
			0x68800020,  //WRREG 17 = 32 //xbar wr addr
			0x69000000,  //WRREG 18 = 0  //opm_radro


			0x60000000,  //0-0
			0x60800001,  //1,1
			0x61000002,  //2-2
			0x61800010,  //3-16
			0x62800005,  //5-5
			0x63000006,  //6-6

			0x19000000,  //LOOPST 10 loops

			0x00000005,  //Read 5   Reset dot space
			0x00000002,  //Read 2
			0x00009025,  //Mult even
			0x0000A820,  //mult Odd

			0x1f000000,  //LOOPST 16 loops //Dot Prod
			0xE4000000,  //CLRFULL
			0xE0008000,  //SETBITS USE 32
			0xE0000400,  //SETBIT LD Sample
			0x80113002,  //MAC
			0x00000000,  //1d NO
			0x00001022,  //Add Even
			0x98702820,  //INCREG 16 Add ODD
			0x20700000,  //LOOPC

			0xE0004000,  //SETBITS LOG  //LOG
			0xE0800002,  //SETBITS Shift
			0x00031032,  //LUT Log insel
			0x00031832,  //LUT Log insel
			0x00031032,  //LUT Log insel
			0x00031032,  //LUT Log insel
			0x00032033,  //LUT Log insel

			0x00041033,  //read @3, alu shift 8 bit wr_data_sel =0 mem_wr =1
			0x00042830,  //read @3, alu shift 8 bit wr_data_sel =0 mem_wr =1

			0x68000000,  //WRREG 16 = 0  //weight addr

			0x91f00000,
			0x20700000,  //LOOPC

			0xE2000000,
			0x50000000  //Loop to 0

};

/*******************************************************************************
*                          Extern Data Definitions
*******************************************************************************/
U8 AON_int = 0;
U8 CMD_int = 0;

/*******************************************************************************
*                          Extern Function Definitions
*******************************************************************************/

/*******************************************************************************
* Name       : main
* Description: Initializes system clock, trace, LCD, and starts the wake word
*              application or FreeRTOS scheduler.
* Remarks    :
*******************************************************************************/
void main()
{
	U32 ref_clk = 1024000;
	U32 hclk_div1;
	SYS_CLK_SelectClockSource(HCLK , EXTERNAL_CLK);
	HWREG_DELAY(100);

	clock_source = PLL;
	master_clk = 8000000;       /* source clock is set to this value */
	SystemCoreClock = 8000000;   /* desired value of HCLK */

	hclk_div1 = master_clk/(2*SystemCoreClock);

	/* Set desired Clock  sources & frequencies as per the board specifics */
	SYS_CLK_Init(&SysClk, clock_source, ref_clk, master_clk);
	SYS_CLK_SelectClockSource(HCLK , clock_source);
	SYS_CLK_SetClockDivider(HCLK, hclk_div1, 0);

	HWREG_WRITE32(0x3A8000F4, 0x0000000A);//OD, dummy divider outside VCO

	/* Initialize trace module */
	TRACE_Init(SystemCoreClock);
	WAKE_WORD_SPI_LCD_INIT();
#if LCD_DISPLAY
	SPI_OLED_Display_Configure();
#endif
    TRACE_Printf("\e[0;30m""\033[1m" "\r\n Wake word Application Started\r\n");

#if ENABLE_WAKE_WORD_STATIC_DATA
    aon_semaphore = xSemaphoreCreateBinary();
    NVIC_SetPriority(AON_IRQn, configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY);

   	NVIC_EnableIRQ(AON_IRQn);

   	xTaskCreate(wake_word_app_process_static_image,  /* The function that implements the task. */
   					"Static_image_Task", 					/* The text name assigned to the task - for debug only as it is not used by the kernel. */
   					1024, 			             	    /* The size of the stack to allocate to the task. */
   					(void *)0, 						    /* The parameter passed to the task - just to check the functionality. */
   					tskIDLE_PRIORITY + 3, 		        /* The priority assigned to the task. */
   					NULL );

#else
	/* Start Application */
    APP_Start();
#endif
    /* Start freeRTOS Kernel */
	vTaskStartScheduler();
}

/*******************************************************************************
* Name       : as_aon_handler
* Description: AON interrupt handler, signals the AON semaphore to wake
*              the processing task.
* Remarks    : global ISR defined in vector table
*******************************************************************************/
void as_aon_handler()
{
	U32 val;
	BaseType_t xHigherPriorityTaskWoken = pdFALSE;

	AON_int = 1;


	xSemaphoreGiveFromISR(aon_semaphore, &xHigherPriorityTaskWoken);
	portEND_SWITCHING_ISR(xHigherPriorityTaskWoken);

}

/*******************************************************************************
* Name       : as_cmd_handler
* Description: CMD interrupt handler, signals the CMD semaphore to wake
*              the data read task.
* Remarks    : global ISR defined in vector table
*******************************************************************************/
void as_cmd_handler()
{
	BaseType_t xHigherPriorityTaskWoken = pdFALSE;


	xSemaphoreGiveFromISR(cmd_semaphore, &xHigherPriorityTaskWoken);
	portEND_SWITCHING_ISR(xHigherPriorityTaskWoken);
}

/*******************************************************************************
* Name       : AMBS_HAL_writeArray
* Description: Writes a 32-bit value to an AI core array memory address
*              selected by the chip-select bitmask and active core.
* Remarks    :
*******************************************************************************/
void AMBS_HAL_writeArray(uint32_t address, uint32_t wr_data, uint8_t cs)
{
	volatile uint8_t *addr = (uint8_t *)(address << 2);

	if(core == AON)
	{
		if (cs == 0x1F)
			addr = 0x3A600000 + addr;
		else if (cs & 0x01)
			addr = 0x3A100000 + addr;
		else if (cs & 0x02)
			addr = 0x3A200000 + addr;
		else if (cs & 0x04)
			addr = 0x3A300000 + addr;
		else if (cs & 0x08)
			addr = 0x3A400000 + addr;
		else if (cs & 0x10)
			addr = 0x3A500000 + addr;

		*(uint32_t *)(addr) = wr_data;
	}
	else
	{
		if (cs == 0x1F)
			addr = 0x3B600000 + addr;
		else if (cs & 0x01)
			addr = 0x3B100000 + addr;
		else if (cs & 0x02)
			addr = 0x3B200000 + addr;
		else if (cs & 0x04)
			addr = 0x3B300000 + addr;
		else if (cs & 0x08)
			addr = 0x3B400000 + addr;
		else if (cs & 0x10)
			addr = 0x3B500000 + addr;

		*(uint32_t *)(addr) = wr_data;
	}

	return;
}

/*******************************************************************************
* Name       : AMBS_HAL_writeWeightData
* Description: Loads weight data into all AI core arrays for the specified
*              number of loops.
* Remarks    :
*******************************************************************************/
void AMBS_HAL_writeWeightData(int total_loops)
{
	int wrloop, loopno, arrayno, la_index;
	uint32_t addr;
	uint64_t *wt_data;
	uint8_t cs;

	la_index = 0;
	for (arrayno = 0; arrayno < NARRAYS; arrayno++)
	{
		for (loopno = 0; loopno < total_loops; loopno++)
		{
			cs = (1 << arrayno);
			addr = 0x1400 + (2 * loopno);

			wt_data = loop_arrays[la_index++];
			for (wrloop = 0; wrloop < 31; wrloop++)
			{
				AMBS_HAL_writeArray(addr, (wt_data[wrloop] & 0xffffffff), cs);
				AMBS_HAL_writeArray(addr + 1, ((wt_data[wrloop] >> 32) & 0xffffffff), cs);
				addr = addr + 0x40;
			}
		}
	}
}

/*******************************************************************************
* Name       : get_object_decription
* Description: Callback invoked when the CNN detects a wake word. Disables
*              I2S and TM buffer channels, and prints the detected keyword.
* Remarks    : compiler expect function name as "get_object_decription"
*******************************************************************************/
void get_object_decription(int obj_id)
{
	if(obj_id>0)
	{
		I2S_DISABLE(core);
		I2S_DISABLE(AON);
		GPIO_Clear(GPIO_PIN_1);
		TM_BUFFER_READ_BUF_DISABLE(INPUT_CHANNEL_TO_FFT_READ,core);
		TM_BUFFER_READ_BUF_DISABLE(FFT_TO_OPM_CHANNEL_READ,core);
		wake_word_detect_flag=1;
	}

	if(obj_id==1)
	{
		string="KEYWORD DETECTED";
		length=6;
	}
#if ENABLE_WAKE_WORD_STATIC_DATA
	TRACE_Printf("\e[0;31m""\033[1m" "\r\n %s \r\n",string );
#endif

}

/*******************************************************************************
* Name       : wake_word_led_blink
* Description: Blinks the wake-word indicator LED on GPIO_PIN_1 the given
*              number of times, with the given on/off delay in microseconds.
*              NOTE: this uses a blocking HWREG_DELAY loop, so it must only
*              be called from task context (not from an ISR or from any
*              code path with tight real-time constraints, e.g. the AI core
*              detection callback itself).
* Remarks    :
*******************************************************************************/
static void wake_word_led_blink(U8 blink_count, U32 delay_us)
{
	U8 i;
	for (i = 0; i < blink_count; i++)
	{
		GPIO_Set(GPIO_PIN_1);      /* LED ON  - adjust polarity if board is active-low */
		HWREG_DELAY(delay_us);
		GPIO_Clear(GPIO_PIN_1);    /* LED OFF */
		HWREG_DELAY(delay_us);
	}
}

/*******************************************************************************
*                         Static Function Definitions
*******************************************************************************/

/*******************************************************************************
* Name       : wake_word_app_process_static_image
* Description: FreeRTOS task that runs the CNN inference on a static
*              pre-loaded audio image for testing.
* Remarks    :
*******************************************************************************/
static void wake_word_app_process_static_image( void *pvParameters )
{
	RunTest(NULL , 0);

}
/*******************************************************************************
* Name       : wake_word_app_LCD_DISPLAY_task_entry
* Description: FreeRTOS task that receives detected keyword strings from the
*              print queue and displays them on the LCD and TRACE output.
* Remarks    :
*******************************************************************************/

static void wake_word_app_LCD_DISPLAY_task_entry( void *pvParameters )
{
	U8 *Print_msg;
	static U16 counter;
	while(1)
	{
		xQueueReceive(WakeWordPrintMsgQueue, &Print_msg, portMAX_DELAY );

		/* Blink the wake-word indicator LED - safe here, this runs in
		   task context (not an ISR), so the blocking delay is fine. */
		wake_word_led_blink(WAKE_WORD_LED_BLINK_COUNT, WAKE_WORD_LED_BLINK_DELAY_US);

#if LCD_DISPLAY

		 wake_word_print_lcd(Print_msg, length);

		 wake_word_ClearPreg(core);
		 TM_BUFFER_WriteData(&wake_word_app_tm_buffer,0x00,8192,0x00);
#endif

		 TRACE_Printf("\e[0;31m""\033[1m" "\r\n %s \r\n",Print_msg );
		 memset(wake_word_app_data,0x0,OFFSET_SIZE*2);
		 wake_word_app_data_size=0;
		 wake_word_app_enable_i2s();
#if LCD_DISPLAY
		 HWREG_DELAY(532000);           //for 8Mhz 478000 is 800ms

		 SPI_OLED_Display_fillscreen(BLACK);
		 SPI_OLED_Display_Update_Screen();

		 length=0;
#endif
		TM_BUFFER_READ_BUF_ENABLE(INPUT_CHANNEL_TO_FFT_READ,core);
		 TM_BUFFER_READ_BUF_ENABLE(FFT_TO_OPM_CHANNEL_READ,core);
		 I2S_ENABLE(AON);
		 I2S_ENABLE(core);
		 GPIO_Clear(GPIO_PIN_1);

	}
}

/*******************************************************************************
* Name       : wake_word_app_process_task_entry
* Description: FreeRTOS task that receives audio data from the message queue
*              and runs CNN inference to detect the wake word.
* Remarks    :
*******************************************************************************/

#include "uart.h"

/* BLE UART Instance (Connected to Microchip RN4871 Bluetooth Module on UART2) */
static UART g_ble_uart;
static U8 g_ble_uart_initialized = 0;

extern uint32_t SystemCoreClock;

static void BLE_UART_SendString(const char *msg)
{
	if (!g_ble_uart_initialized)
	{
		/* Initialize UART2 at 115200 baud for Microchip RN4871 BLE module using active SystemCoreClock */
		UART_Init(&g_ble_uart, UART2_HW_INDEX, 115200, SystemCoreClock);
		g_ble_uart_initialized = 1;
	}
	UART_Tx(&g_ble_uart, (U8*)msg, strlen(msg), NULL, NULL, UART_MODE_0);
}

/* Set to 1 for Dual-Model Cascaded Mode (Hey Mynaa -> Alexa), or 0 for Single Model Mode */
#define ENABLE_DUAL_MODEL_CASCADE 1

typedef enum {
    STATE_STAGE1_WAKEWORD_LISTENER = 0,
    STATE_STAGE2_COMMAND_LISTENER  = 1
} app_state_t;

static app_state_t g_app_state = STATE_STAGE1_WAKEWORD_LISTENER;
static uint32_t g_command_timeout_counter = 0;

static void wake_word_app_process_task_entry( void *pvParameters )
{
	U16 *receive_msg;
	static U16 counter;
	while(1)
	{
		xQueueReceive(WakeWordMsgQueue, &receive_msg, portMAX_DELAY );
		wake_word_compil_msg.sensor_data = receive_msg;

#if (ENABLE_DUAL_MODEL_CASCADE == 0)
		/* ================= SINGLE MODEL MODE ================= */
		RunTest(&wake_word_compil_msg, 0);
		if (wake_word_detect_flag == 1)
		{
			wake_word_led_blink(WAKE_WORD_LED_BLINK_COUNT, WAKE_WORD_LED_BLINK_DELAY_US);
			BLE_UART_SendString("BLE_ALERT: HEY MYNAA DETECTED!\r\n");
			xQueueReset(WakeWordMsgQueue);
			xQueueSend(WakeWordPrintMsgQueue, (void*)(&string), portMAX_DELAY );
			wake_word_detect_flag = 0;
		}
#else
		/* ================= DUAL MODEL CASCADED MODE ================= */
		if (g_app_state == STATE_STAGE1_WAKEWORD_LISTENER)
		{
			/* STAGE 1: Run Model 0 ("HEY MYNAA" Always-On Gatekeeper) */
			RunTest(&wake_word_compil_msg, 0);

			if (wake_word_detect_flag == 1)
			{
				wake_word_detect_flag = 0;
				g_app_state = STATE_STAGE2_COMMAND_LISTENER;
				g_command_timeout_counter = 0;

				/* BLINK IN-BUILT LED (GPIO_PIN_1) 2 TIMES FOR STAGE 1 DETECT */
				wake_word_led_blink(2, 60000);

				/* SEND WIRELESS BLUETOOTH ALERT OVER UART2 (RN4871 BLE MODULE) */
				BLE_UART_SendString("BLE_ALERT: HEY MYNAA DETECTED!\r\n");

				/* RE-ENABLE I2S HARDWARE MICROPHONE FOR MODEL 1 LIVE SAMPLING */
				memset(wake_word_app_data, 0x0, OFFSET_SIZE * 2);
				wake_word_app_data_size = 0;
				wake_word_app_enable_i2s();
				TM_BUFFER_READ_BUF_ENABLE(INPUT_CHANNEL_TO_FFT_READ, core);
				TM_BUFFER_READ_BUF_ENABLE(FFT_TO_OPM_CHANNEL_READ, core);
				I2S_ENABLE(AON);
				I2S_ENABLE(core);

				/* UART LOG 1: STAGE 1 DETECTED -> GOING TO MODEL 1 */
				TRACE_Printf("\e[0;32m""\033[1m" "\r\n 🟢 HEY MYNAA DETECTED! Activating Model 1 (Listening for Alexa for 5 seconds)...\r\n");
			}
		}
		else if (g_app_state == STATE_STAGE2_COMMAND_LISTENER)
		{
			/* STAGE 2: Run Model 1 ("ALEXA" Command Detector) on live microphone data */
			RunTest(&wake_word_compil_msg, 1);
			g_command_timeout_counter++;

			if (wake_word_detect_flag == 1)
			{
				wake_word_detect_flag = 0;

				/* BLINK IN-BUILT LED (GPIO_PIN_1) 5 TIMES FOR ALEXA DETECTED! */
				wake_word_led_blink(5, 80000);

				/* SEND WIRELESS BLUETOOTH ALERT OVER UART2 (RN4871 BLE MODULE) */
				BLE_UART_SendString("BLE_ALERT: ALEXA DETECTED! Hello Sir!\r\n");

				/* UART LOG 2: STAGE 2 ALEXA DETECTED -> HELLO SIR */
				string = "ALEXA DETECTED! Hello Sir!";
				TRACE_Printf("\e[0;35m""\033[1m" "\r\n 🤖 %s \r\n", string);

				xQueueReset(WakeWordMsgQueue);
				xQueueSend(WakeWordPrintMsgQueue, (void*)(&string), portMAX_DELAY );
				g_app_state = STATE_STAGE1_WAKEWORD_LISTENER; /* Return to Stage 1 */
			}
			else if (g_command_timeout_counter >= 15) /* ~5 seconds listening window for Alexa */
			{
				/* UART LOG 3: TIMEOUT -> RETURN TO STAGE 1 */
				TRACE_Printf("\e[0;33m""\033[1m" "\r\n ⏳ Timeout (No command heard). Returning to Stage 1 sleep mode...\r\n");
				BLE_UART_SendString("BLE_ALERT: TIMEOUT - Returning to Stage 1\r\n");

				/* Re-enable I2S for Stage 1 */
				memset(wake_word_app_data, 0x0, OFFSET_SIZE * 2);
				wake_word_app_data_size = 0;
				wake_word_app_enable_i2s();
				TM_BUFFER_READ_BUF_ENABLE(INPUT_CHANNEL_TO_FFT_READ, core);
				TM_BUFFER_READ_BUF_ENABLE(FFT_TO_OPM_CHANNEL_READ, core);
				I2S_ENABLE(AON);
				I2S_ENABLE(core);
				
				g_app_state = STATE_STAGE1_WAKEWORD_LISTENER; /* Return to Stage 1 */
			}
		}
#endif
	}
}


/*******************************************************************************
* Name       : wake_word_app_read_task_entry
* Description: FreeRTOS task that initializes the AI core, loads microcode
*              and weights, configures I2S, and continuously reads PREG data
*              to feed the wake word processing pipeline.
* Remarks    :
*******************************************************************************/
static void wake_word_app_read_task_entry( void *pvParameters )
{
	U32 j;
	U32 preg_val[16];
	U32 neuron_mask_val;
	U32 neuron_shift_val;
	U16 *msg_send_ptr;
    U16 *second_pointer;
    U32 remain_data=0;
    U32 data_count=0;
	wake_word_data_offset=0;
	wake_word_detect_flag=0;
	/* Initialize CMD core */
	AI_CORE_OFF(core);
	neuron_mask_val=0xffffffff;
	neuron_shift_val =0x00;
	/* while calling this function , pl see ADC propagation delay is set correctly
	  based on the board  */
	AI_CORE_Init(neuron_mask_val,neuron_shift_val,core,0xa000);
	AI_CORE_LoadMicroCode(&wake_word_ucode[0],(sizeof(wake_word_ucode)/sizeof(U32)),core);
	/* load weights */
	AMBS_HAL_writeWeightData(16);
	wake_word_app_config_i2s();
	TRACE_Printf("\e[0;30m""\033[1m""\r\n WAITING FOR COMMAND\r\n");

	AI_CORE_ON(core);

   while(1)
   {
	   xSemaphoreTake(cmd_semaphore, portMAX_DELAY);

	   if (wake_word_app_data_size >= (BUFFER_SIZE))
	   {
		   memcpy(wake_word_app_data,(wake_word_app_data + (wake_word_data_offset*2)),(wake_word_app_data_size -wake_word_data_offset*2)*2);
		   wake_word_app_data_size=(wake_word_app_data_size -(wake_word_data_offset*2));
		   wake_word_app_enable_i2s();
	   }
	   if (wake_word_app_data_size < (BUFFER_SIZE))
	   {
		   wake_word_data_ready++;
		   wake_word_app_get_preg_data();
		   if(wake_word_data_ready >= COMPARE_COUNT)
		   {
			   msg_send_ptr=wake_word_app_data+wake_word_data_offset;
			   xQueueSend(WakeWordMsgQueue, (void*)(&msg_send_ptr), portMAX_DELAY );
			   wake_word_data_offset +=PROCESS_SIZE;
		   }
	   }
    }
}

/*******************************************************************************
* Name       : APP_Start
* Description: Creates FreeRTOS semaphores, message queues, interrupts, and
*              launches the data read, process, and LCD display tasks.
* Remarks    :
*******************************************************************************/
static void APP_Start()
{
	/* Initialize peripherals */
    aon_semaphore = xSemaphoreCreateBinary();

    cmd_semaphore = xSemaphoreCreateBinary();

	WakeWordMsgQueue = xQueueCreate( 1000,sizeof(void*) );
	WakeWordPrintMsgQueue = xQueueCreate( 2,sizeof(void*) );
	/* Initialize Interrupts  */
    NVIC_SetPriority(AON_IRQn, configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY);
   	NVIC_EnableIRQ(AON_IRQn);
    NVIC_SetPriority(CMD_IRQn, configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY);
	NVIC_EnableIRQ(CMD_IRQn);

	xTaskCreate(wake_word_app_read_task_entry,  /* The function that implements the task. */
				"DataTask", 					/* The text name assigned to the task - for debug only as it is not used by the kernel. */
				1024, 			             	    /* The size of the stack to allocate to the task. */
				(void *)0, 						    /* The parameter passed to the task - just to check the functionality. */
				tskIDLE_PRIORITY + 4, 		        /* The priority assigned to the task. */
				NULL );					    		/* The task handle is not required, so NULL is passed. */

	xTaskCreate(wake_word_app_process_task_entry,  /* The function that implements the task. */
				"ProcessTask", 					/* The text name assigned to the task - for debug only as it is not used by the kernel. */
				1024, 			             	    /* The size of the stack to allocate to the task. */
				(void *)0, 						    /* The parameter passed to the task - just to check the functionality. */
				tskIDLE_PRIORITY + 3, 		        /* The priority assigned to the task. */
				NULL );
	xTaskCreate(wake_word_app_LCD_DISPLAY_task_entry,  /* The function that implements the task. */
					"PrintTask", 					/* The text name assigned to the task - for debug only as it is not used by the kernel. */
					1024, 			             	    /* The size of the stack to allocate to the task. */
					(void *)0, 						    /* The parameter passed to the task - just to check the functionality. */
					tskIDLE_PRIORITY + 2, 		        /* The priority assigned to the task. */
					NULL );
}

/*******************************************************************************
* Name       : wake_word_app_config_i2s
* Description: Configures the I2S interface, TM buffer channels, FFT, and
*              AI core OPM settings for wake word audio capture.
* Remarks    :
*******************************************************************************/
static void wake_word_app_config_i2s()
{
	I2S_INIT(SystemCoreClock,I2S_8Khz,RIGHT_CHAN_MSB,0x0000ffff,core,i_pll_lpo_clk);
	//call AON side also, the clk setting is on AON block though CMD block is used*/
	I2S_INIT(SystemCoreClock,I2S_8Khz,RIGHT_CHAN_MSB,0x0000ffff,AON,i_pll_lpo_clk);
	TM_BUFFER_Init(&wake_word_app_tm_buffer,core);
	TM_BUFFER_WriteData(&wake_word_app_tm_buffer,0x00,8192,0x00);
	TM_BUFFER_AllocateBufferForInputChannel(&wake_word_app_tm_buffer,I2S_CHANNEL,0,4096,31,BYPASS);
	TM_BUFFER_AllocateBufferForInputChannel(&wake_word_app_tm_buffer,FFT_CHANNEL,4096,4096,31,BYPASS);
	TM_BUFFER_READ_BUF_ENABLE(INPUT_CHANNEL_TO_FFT_READ,core);
	TM_BUFFER_READ_BUF_ENABLE(FFT_TO_OPM_CHANNEL_READ,core);
	//call AON side also, the setting is on AON block though CMD block is used*/
	FFT_INIT(FFT_SQUARE_RIGHT_SHIFT_2, ENABLE_FFT_SQUARE, ENABLE_FFT_SATURATION, DISABLE_FFT_SATURATION_MSB,core);
	AI_CORE_INT_CLEAR(core);
	AI_CORE_SET_OPM_WIDTH(OPD_WIDTH_32,core);
	AI_CORE_SET_WTM_WIDTH(WT_WIDTH_16,core);
	AI_CORE_NO_SAMPLES_TO_OPM(16,core);
	AI_CORE_OPM_WAIT_STATE_CLEAR(core);
	I2S_ENABLE(AON);
	I2S_ENABLE(core);

}

/*******************************************************************************
* Name       : wake_word_app_get_preg_data
* Description: Reads AI core PREG output data from multiple cores and stores
*              it into the wake word data buffer.
* Remarks    :
*******************************************************************************/
static void wake_word_app_get_preg_data()
{
	U32 val;
	static U32 addr;
	U32 j;
	U32 k;
	U32 l=1;
	U32 base;
	S16 temp;
	U32 read_preg;
	if (core == AON)
	{
		base = HWREG_AI_CORE_BASE;
	}
	else
	{
		base   = HWREG_AI_CORE_BASE_CMD;
	}
	/*48 data is collected */
	for(l=1;l<((PROCESS_SIZE/NO_PREG)+1);l++)
	{
		for(k=1; k<NO_CORE;k++)            //using only 2 core
		{
			addr  = base + (k*0x100000)+0x40+((l-1)*0x04);

		    read_preg=4;

			for ( j=0; j<read_preg; j++)
			{
				HWREG_READ32(addr,val);
				temp = (S32)val;
				wake_word_app_data[wake_word_app_data_size]= temp;
				wake_word_app_data_size++;
				addr+=0x80;
			}

		}
	}

}

/*******************************************************************************
* Name       : wake_word_app_enable_i2s
* Description: Resets the data offset and ready counter to re-enable I2S
*              audio data capture after a wake word detection event.
* Remarks    :
*******************************************************************************/
static void wake_word_app_enable_i2s()
{
	 wake_word_data_offset=0;
if(wake_word_app_data_size == 0)
	 wake_word_data_ready=0;
else
	wake_word_data_ready=(COMPARE_COUNT-2);
}

/*******************************************************************************
* Name       : WAKE_WORD_SPI_LCD_INIT
* Description: Initializes GPIO pins and the SPI OLED LCD display for
*              wake word detection status output.
* Remarks    :
*******************************************************************************/
static void WAKE_WORD_SPI_LCD_INIT()
{
		GPIO_Init(&gpio);

		U8 gpio_no = GPIO_PIN_4;

		GPIO_Configure(gpio_no,
					   GPIO_OUTPUT,
					   GPIO_INTERRUPT_DIS,
					   NULL);
		GPIO_Configure(GPIO_PIN_1,
					   GPIO_OUTPUT,
					   GPIO_INTERRUPT_DIS,
					   NULL);
		GPIO_Configure(GPIO_PIN_0,
							   GPIO_OUTPUT,
							   GPIO_INTERRUPT_DIS,
							   NULL);

#if LCD_DISPLAY
		SPI_OLED_Display_Init(&oled,SPI2_HW_INDEX,SPI_DIVIDE_16,gpio_no);
#endif
}

/*******************************************************************************
* Name       : wake_word_print_lcd
* Description: Displays a detected keyword string on the SPI OLED LCD screen.
* Remarks    :
*******************************************************************************/
static void wake_word_print_lcd(U8 *string, U32 size)
{
	SPI_OLED_Display_SetCursor(10,20);
	SPI_OLED_Display_SetTextSize(2);
	SPI_OLED_Display_fillscreen(BLACK);
	SPI_OLED_Display_WriteString(string,size,WHITE);
	SPI_OLED_Display_Update_Screen();
}

static void wake_word_ClearPreg(HWREG_CORE_TYPE core)
{
    U32 addr ;

    U32 s_addr ;

    U32 base ;

    if( core == AON)
    {
        base = HWREG_AI_CORE_BROADCAST_BASE_ADDR;
    }
    else
    {
        base = HWREG_AI_CORE_BROADCAST_BASE_ADDR_CMD;
    }


    s_addr = base + HWREG_AI_CORE_PREG0_OFFSET;

    addr = s_addr;

    while(addr <  (s_addr + 0x3fc))
    {
        HWREG_WRITE32(addr,0x00);
        HWREG_WRITE32((addr+4),0x00);
        addr +=8;
    }
}

/*******************************************************************************
*                          End of File
*******************************************************************************/
