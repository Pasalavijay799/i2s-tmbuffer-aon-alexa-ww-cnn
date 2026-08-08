	//! VC_TARGET_BASE_PATH: E:\Projects\sdk\ambient-sw\chip\fw\applications\live-wake-word-alexa\live-wake-wprd-alexa-project\

//! ---------------------------------------------------------------------------------------------
//! Auto Generated on  27_07_2022_15_35_37_. 7.4003

	void WRITE_DATA_2PREG(); 		//! Forward Declaration
	void WRITE_DATA_2WTM_OPM(uint16_t , uint16_t );

	//! COMMAND_LINE: -BT 7 -t E:\Projects\sdk\ambient-sw\chip\fw\applications\live-wake-word-alexa\live_wake_word_alexa_vc_input.txt -ute -uart 12 

	//! ---------------------------------------------------------------------------------------------
	//! BACKEND AUTO GENERATED CODE.. DO NOT MODIFY...
	//! AUTHOR: CHANNA@ambientscientific.ai 
	//! Generted on... 2022-07-27 15:35:37+0530
	//! ---------------------------------------------------------------------------------------------
	/****
	INPUT TEMPLATE FILE: E:\Projects\sdk\ambient-sw\chip\fw\applications\live-wake-word-alexa\live_wake_word_alexa_vc_input.txt

	@com_result_port=46
	@baud_rate=9600
	@wtm_width=16
	@opm_width=32
	@bias_width=16
	@no_of_cores=5
	@opm_delay=20
	@wtm_delay=100
	@wtm_log=0	//! 1 for true and 0 for false
	@opm_log=0
	@bias_log=0
	@model=DNN
	@no_of_h_layers=3
	@no_of_h_neurons=20, 20, 20
	@no_of_outputs=1
	@bias_flag=1	 //! for each layer  0=NO_BIAS,  1=ADD_BIAS, //! single value 1=  ADD_BIAS for all layers //! single value 0=  NO_BIAS for all layers
	@type_of_activation=-1,{1:1:3},{1:1:3},-1,1	//! for each layer -1=NONE, 0=TANH, 1=SIGMOID, 2=RELU, 3=LINEAR //! single value -1 =  NO-ACTIVATION  for all layers
	@type_of_layers=0,2,2,1,1	//!  0=NONE, 1=DENSE, 2=GRU, 3=LSTM
	@task_name=COMPLEX_MAC_DEMONSTRATION
	@task_description=This demonstrates the MAC operation on GPX processor
	@target_base_path=..\..\..\..\fw\applications\live-wake-word-alexa\live-wake-wprd-alexa-project\
	@target_file_path=..\..\..\..\fw\applications\live-wake-word-alexa\inc\
	@target_file_to_append=mal_mac_tc.hpp
	@target_header_driver=mal_mac_tc_call.hpp
	@quantization=0
	@target_packer_out=2		//! 1 for msb select(first 16bits) 0 for lsb select(last 16 bits
	@no_of_samples=1
	@no_of_features=16
	@input=0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	@wtm_stloc = 16
	@last_layer_wfix=1
	@inf_type=1	//! 0 for AHB, 1 for LIVE   -1 for no-inference
	@threshhold=0x06
	@sensitivity=0x50
	@dp_mult_val=0x0080
	@dp_log_val=0xFFF6
	@use_32bit_bias=0,{0:0:0},{0:0:0},0,0
	@use_sign_ext=0,{0:0:0},{0:0:0},1,0
	@mac_out_shift=7
	@xbar_out_shift=7
	@opm_out_shift=0
	@comment=----------------------------------------------------------------------
	@bias=   -8, 7, 23, 9, -9, 40, 34, 13,    10, 34, 2, -6, -4, -1, 10, 1,    8, 14, 14, -1, -9, 1, 9, 9,    21, 25, 11, 6, 25, 3, 11, 8,    13, -5, 5, 9, -8, 57, 31, 22,    -15, -48, -20, -22, -32, 40, 
	@weights=12, -6, -15, -4, 17, -19, 22, 9,    31, -22, 12, 31, -27, -30, 4, -20,    27, 41, 0, -32, 15, 58, -24, -22,    -5, -21, 21, 31, 31, 2, 20, 57,    12, 35, -15, 16, 67, 28, -4, 37,    42, -14, 
	@rec_weights=3, -22, -8, 2, -61, 31, 0, -28,    3, 3, 3, 38, -13, 9, 4, -3,    -18, 21, -21, 45, -26, -5, 24, 33,    51, 28, 24, 10, 18, 4, 33, 26,    -34, 37, 21, -25, -7, 35, 19, 13,    -27, 66, -8,
	****/
	/***************************************************
	_HARDWARE_INFO:

	WTM  WIDTH:    16
	OPM  WIDTH:    32
	BIAS WIDTH:    16 			_TOTAL_NEURONS_AVAILABLE_FROM_ALL_CORES: 20

	_MODEL_OPERATION_REQUESTED: DNN		_TOTAL_LAYERS:  5 ( Including input [Layer- 0] and the output [Layer- 4] )

	_NEURAL_NETWORK_INFO:

	_Layer:   0  SHAPE: 1x16x1x1  TOTAL_NEURONS:   0  TOTAL_WEIGHTS:   0  NO_OF_CORES:   0  
	_Inputs:
	0x00000000 0x00000000 0x00000000 0x00000000 0x00000000 0x00000000 0x00000000 0x00000000 0x00000000 0x00000000 0x00000000 0x00000000 0x00000000 0x00000000 0x00000000 0x00000000 
	
	//! ENABLED_BIAS_FOR_ALL_LAYERS... 		//! ACTIVATION_SIGMOID_e	//! ACTIVATION_SIGMOID_e	//! ACTIVATION_LINEAR_e
	_Layer:   1  SHAPE: 16X20  TOTAL_NEURONS:  20  TOTAL_WEIGHTS: 320  TOTAL_REC_WEIGHTS: 400  NO_OF_CORES:   5	LAYER_GRU_e
	_Weights:
	UPDATE GATE INPUT WEIGHTS:
	12	32	39	-15	43	-7	10	-5	10	27	-5	9	-12	0	2	-30
	-6	-19	22	-16	13	6	22	22	9	52	44	20	10	-17	1	-6
	-15	-29	-1	4	-14	-33	1	-26	-4	-20	-31	24	-26	-5	35	6
	-4	-22	-4	-6	-8	4	41	1	-43	22	44	17	-19	13	-23	25
	17	-18	-14	-14	-20	-28	1	27	13	22	33	41	5	-23	-24	16
	-19	-3	-34	3	14	-27	15	-18	10	9	12	-31	-27	19	-22	-27
	22	-12	-2	-55	31	-33	-55	-22	-33	-26	-10	-21	-35	-41	-12	-21
	9	17	-27	11	11	22	52	-21	7	-9	37	36	32	-10	-11	19
	31	-24	-12	-11	-29	25	-60	-34	28	-16	20	10	6	39	-10	27
	-22	-21	-3	16	-26	29	-19	28	-5	-16	-14	13	7	-45	-15	29
	12	-16	22	-1	36	8	35	14	-43	1	1	12	-12	-20	-5	-13
	31	-23	1	26	28	-21	15	44	1	-20	6	-3	36	-14	10	-23
	-27	6	23	-24	-12	-25	-11	0	10	28	-11	29	24	17	4	-25
	-30	-9	-29	5	-37	24	19	14	-20	43	13	2	-24	31	-23	8
	4	24	15	13	36	-11	31	-13	15	22	-27	17	7	-21	-5	-18
	-20	22	-25	25	-9	-20	43	20	-6	37	-17	13	-1	7	-30	12
	27	40	-6	17	2	26	-7	-32	15	30	20	-23	-14	10	-8	18
	41	-9	-3	-20	-37	-3	-19	-11	43	-8	19	-5	-10	-6	-33	-21
	0	11	-40	-25	-36	35	2	-11	15	7	-38	2	-5	12	-3	33
	-32	11	12	-2	19	6	-17	-2	45	-22	-3	-48	-49	-28	8	-5
	UPDATE GATE RECURRENT WEIGHTS:
	3	54	-35	-13	18	18	-2	-5	34	-5	-12	13	-21	-6	-10	-13	4	10	9	-28
	-22	1	-14	-35	13	-8	7	10	-7	4	-4	-40	41	17	16	-26	33	-18	8	-11
	-8	-7	46	37	-11	17	-3	45	-17	6	26	-25	-2	9	-22	33	17	-23	38	9
	2	10	-16	66	-1	30	-10	7	-9	1	4	-24	5	11	35	16	41	-10	-9	0
	-61	5	-10	-17	-38	15	60	-31	-3	23	-14	9	18	0	-7	-42	45	15	-24	-23
	31	3	40	1	-27	26	17	3	-24	9	21	-1	-38	-38	-1	1	23	-30	29	27
	0	-9	33	28	-15	-11	-49	47	56	20	-7	-33	-3	6	-21	9	-33	35	22	-20
	-28	2	2	0	42	0	-36	4	37	-21	-32	-18	10	-14	-4	35	-9	8	-5	15
	3	26	6	25	-16	-30	-9	33	32	3	-36	14	29	-32	23	16	-32	4	-22	7
	3	-3	48	-30	3	7	3	-1	1	25	10	-32	-40	-17	5	-7	21	31	9	-32
	3	3	-33	-15	3	-7	-5	25	-28	-28	20	17	9	18	18	27	-21	3	22	15
	38	16	-40	30	-16	30	-8	3	-23	-33	-17	-5	11	-31	-20	-17	-10	23	31	-11
	-13	12	16	-34	3	7	25	-37	5	26	7	-7	-14	0	-17	-30	18	-46	-25	-19
	9	6	-3	-9	-16	-34	14	19	6	12	-8	30	3	29	-18	-37	-23	8	-8	-5
	4	22	-8	22	0	-3	-18	62	-12	21	-27	38	5	3	-3	24	-37	19	13	-41
	-3	2	3	-7	13	3	11	-17	50	10	54	-42	-3	-16	-28	-27	6	-9	19	-34
	-18	-16	3	-28	6	8	-6	-11	-18	-35	-9	6	14	9	-13	-31	1	2	-20	9
	21	24	-18	29	-9	7	0	2	27	7	23	-6	6	34	6	-18	-18	-12	-11	15
	-21	23	34	19	7	-16	13	19	24	16	38	-10	-53	-14	17	-18	38	-10	15	34
	45	-55	-9	-10	19	-11	37	6	-12	27	-25	-20	25	6	0	1	33	11	9	35
	RESET GATE INPUT WEIGHTS:
	15	-5	6	-2	34	30	28	-1	-4	-45	-63	-3	16	-29	-20	6
	58	36	-47	-1	24	58	26	-29	26	7	17	7	-39	-22	-3	22
	-24	2	-11	1	0	-6	5	-2	23	-9	10	-39	28	-39	-32	-5
	-22	-4	1	6	-79	-15	-41	-11	-43	14	7	5	-7	-45	-37	-15
	-5	-11	20	40	-29	-23	-18	-6	36	-13	-10	58	5	-7	1	30
	-21	-35	4	14	-15	-32	-11	23	3	0	-17	18	-13	36	-24	-29
	21	10	-28	-30	-11	-27	9	6	-27	37	27	16	27	58	-29	7
	31	87	16	-1	32	49	49	19	44	26	-26	10	-36	19	80	20
	31	-19	-2	43	-42	-1	1	-50	2	49	29	15	60	48	-43	27
	2	-23	-6	-34	2	10	21	-1	14	10	-6	32	30	-23	-13	-12
	20	33	-1	-10	-18	12	-5	-24	-28	-35	-2	7	-8	8	-22	28
	57	7	-24	24	45	19	21	18	-7	-28	-17	26	6	25	-10	39
	12	25	43	-16	15	-42	1	-22	48	-11	31	-2	-4	-17	-11	-36
	35	8	-26	25	29	-5	0	14	-42	38	9	16	-38	28	-40	-29
	-15	-7	-31	-32	-24	16	60	21	41	-9	-23	-26	4	-56	-18	16
	16	-6	-3	-38	46	34	-22	41	62	10	-19	13	-15	-13	8	-29
	67	12	23	15	37	42	29	30	-46	-34	-13	-27	-9	-20	-1	8
	28	-10	-4	28	-9	-32	11	29	-4	12	41	-18	-20	21	53	34
	-4	8	3	-6	25	7	15	-7	12	50	10	13	-61	33	41	-17
	37	37	7	53	-43	-9	6	40	19	-15	13	-12	-12	-8	41	17
	RESET GATE RECURRENT WEIGHTS:
	-26	22	-5	43	7	7	2	-14	-9	-4	-17	14	-45	5	-3	9	-10	-4	-12	-27
	-5	-22	5	-1	8	-5	7	44	7	-30	16	4	2	-15	5	16	-57	-8	-5	-63
	24	-6	31	34	-40	27	9	33	7	0	1	3	-47	-28	19	1	10	21	29	43
	33	-17	-42	-13	-54	-43	-11	-6	12	6	-11	-11	-11	-16	45	14	-19	-17	17	-35
	51	18	14	54	-9	30	37	59	-8	38	0	6	8	-19	-9	-15	-9	5	45	6
	28	-20	37	17	-10	11	-15	58	-21	43	32	25	7	-21	-6	-5	35	-6	17	25
	24	4	19	11	-13	4	-28	26	19	-1	12	4	-3	-4	31	20	-41	-3	26	20
	10	-46	-9	51	-38	34	15	13	62	10	10	45	-56	32	-12	31	-22	-26	-11	58
	18	-1	-12	4	46	-19	7	36	-12	23	25	-35	-21	45	-6	1	-3	-40	25	-25
	4	10	-4	-16	-45	-33	-25	28	19	0	-60	-15	7	-5	8	-33	-29	-6	7	5
	33	-33	11	3	7	14	-22	-22	-4	-13	44	34	1	-62	-33	8	20	-21	17	2
	26	-27	4	-18	-4	57	-13	50	15	32	8	-49	-27	-25	12	46	-12	36	12	25
	-34	-6	23	-5	3	40	28	-21	-31	16	22	-29	-21	-38	-33	3	14	-15	16	3
	37	-6	-9	33	14	5	-33	33	-13	57	-15	-31	13	16	0	-4	-22	-44	16	1
	21	-31	23	4	-9	-16	-24	-34	47	14	19	-48	-7	-42	23	0	-28	-5	25	-7
	-25	0	-23	39	-3	-9	-2	16	21	-12	-2	20	-5	-25	-41	-23	24	17	-14	7
	-7	-31	16	-7	16	11	13	-13	-2	-5	-24	-29	-48	34	-15	10	-6	33	55	2
	35	-26	26	-6	-50	7	-1	45	14	2	-5	23	16	-6	49	18	-19	36	23	31
	19	-29	7	33	-21	24	-28	-12	33	52	-8	-17	-6	-4	32	26	-43	22	34	-40
	13	-61	14	39	5	5	33	-11	-16	-9	-25	-16	-10	-35	45	9	-44	-10	14	19
	COMPUTE GATE INPUT WEIGHTS:
	42	-10	-2	33	-11	-11	-34	-4	23	-16	-17	-12	-2	23	-3	-7
	-14	35	-11	21	3	18	-20	1	18	-4	-31	25	48	-31	20	3
	12	14	-14	11	-1	0	-13	-26	18	13	-17	-15	-6	-4	4	0
	16	-21	-2	8	7	24	1	2	23	-34	-3	-24	-12	-20	-6	-17
	22	-9	29	-18	29	-12	17	-10	-15	0	42	0	-18	49	21	25
	-25	1	13	18	20	-16	-25	24	8	-19	4	-5	31	4	7	37
	-22	22	4	18	-3	-19	3	5	21	50	-11	-6	19	22	-19	13
	10	-25	-11	-10	25	13	34	-22	23	18	4	-46	-24	-42	-13	34
	-21	15	0	-43	17	-18	17	40	33	2	27	10	27	36	-9	-2
	-20	18	-6	28	-2	14	-8	34	-2	26	-22	-25	-30	7	-31	-27
	12	-26	20	13	-22	-24	-7	43	5	2	-4	-25	-5	15	37	29
	-7	4	-6	-3	35	9	-38	-13	24	-19	-24	8	-1	19	-3	-51
	-2	15	17	4	-35	4	-28	-38	-7	-25	-3	-47	-10	1	-5	-18
	-30	-1	-30	-22	17	15	18	15	-47	48	-4	-33	-17	35	-41	17
	-9	-48	6	-12	-12	-20	24	32	28	4	5	-18	7	20	11	-50
	-3	-5	-42	17	15	32	-26	22	41	-21	2	1	-15	-33	-33	-10
	-28	40	0	-39	-23	-9	-40	0	16	-2	-53	-22	28	17	-39	15
	-9	-4	1	11	-9	-22	-28	37	-18	-19	5	6	20	-20	-18	12
	2	28	-25	16	-16	-8	10	24	-1	-19	22	23	-4	5	-40	-11
	-1	8	-30	10	-3	-5	-19	-6	-18	-8	7	-38	14	23	13	20
	COMPUTE GATE RECURRENT WEIGHTS:
	-27	-22	8	-49	-15	15	-12	-16	5	13	24	1	17	-18	2	-25	-11	-3	32	20
	66	3	-4	1	41	-16	49	27	-30	-12	-5	23	6	0	-12	-16	-29	23	-67	-20
	-8	28	30	-39	13	-7	-5	-21	33	0	-34	-4	-17	-16	46	49	25	16	56	-5
	-28	49	1	1	-7	11	8	22	-25	-46	-4	23	-21	13	-58	-6	29	19	-36	-20
	14	13	-47	-9	8	-25	22	-23	-60	-59	-20	6	-5	-24	19	-32	-16	55	-27	-26
	-48	-39	-13	50	11	30	13	-26	-1	-18	23	-43	-22	-32	-55	-8	26	-20	-5	34
	-47	-28	-12	22	-13	20	-27	4	31	-34	23	-55	4	12	-22	-53	44	1	-57	-7
	26	-5	33	-21	-4	24	-4	-14	-18	29	15	-16	11	-35	29	39	1	-5	18	30
	-15	39	1	-35	-13	-17	0	13	9	9	31	-2	8	-12	53	35	-31	26	47	40
	-4	0	-13	-39	49	-1	-36	3	6	26	-3	-11	13	-16	23	14	-7	42	26	38
	-63	26	-22	26	15	-9	50	-48	18	-46	-7	-20	-17	24	-36	-29	35	2	9	-20
	31	-5	9	-16	-18	17	5	36	25	4	12	-17	-64	-25	22	38	-3	-61	-24	-3
	5	19	-13	29	-38	17	-8	3	37	5	4	17	6	11	-25	-48	-67	2	14	9
	19	-12	-38	28	34	-42	-26	36	21	21	3	14	-11	7	8	-7	1	-5	0	-21
	7	-33	4	-82	2	-5	-12	14	-1	64	14	16	-25	-46	29	43	11	12	25	15
	12	-3	15	-43	37	9	16	3	1	-6	15	13	-6	-2	20	10	-46	-9	-24	15
	-7	24	-8	-6	38	-12	-18	-29	-28	10	31	-26	-37	-2	-30	-27	-10	50	3	-5
	12	6	-10	-48	18	-34	-6	-9	4	12	-11	43	-48	5	15	44	-34	31	-37	-18
	-4	47	24	-70	20	-40	10	1	-8	37	22	13	-21	-6	43	55	-21	34	-12	-15
	-32	26	39	18	23	26	-24	-8	-14	15	24	-7	-18	13	25	35	21	38	29	-13
	_Bias:
	0xfffffff8 	0x0007 	0x0017 	0x0009 	0xfffffff7 	0x0028 	0x0022 	0x000d 	0x000a 	0x0022 	0x0002 	0xfffffffa 	0xfffffffc 	0xffffffff 	0x000a 	0x0001 	0x0008 	0x000e 	0x000e 	0xffffffff 
	0xfffffff7 	0x0001 	0x0009 	0x0009 	0x0015 	0x0019 	0x000b 	0x0006 	0x0019 	0x0003 	0x000b 	0x0008 	0x000d 	0xfffffffb 	0x0005 	0x0009 	0xfffffff8 	0x0039 	0x001f 	0x0016 
	0xfffffff1 	0xffffffd0 	0xffffffec 	0xffffffea 	0xffffffe0 	0x0028 	0x0021 	0xfffffff1 	0x001f 	0xffffffeb 	0x0023 	0xfffffffe 	0x000f 	0xffffffe8 	0xffffffec 	0xffffffeb 	0xfffffffe 	0xffffffcc 	0xffffffdd 	0xffffffee 


	//! ENABLED_BIAS_FOR_ALL_LAYERS... 		//! ACTIVATION_SIGMOID_e	//! ACTIVATION_SIGMOID_e	//! ACTIVATION_LINEAR_e
	_Layer:   2  SHAPE: 20X20  TOTAL_NEURONS:  20  TOTAL_WEIGHTS: 400  TOTAL_REC_WEIGHTS: 400  NO_OF_CORES:   5	LAYER_GRU_e
	_Weights:
	UPDATE GATE INPUT WEIGHTS:
	12	20	0	20	25	41	32	10	9	-14	26	-18	-39	-32	-13	-22	-8	-13	-34	-4
	-19	29	7	22	32	54	42	-43	14	1	27	-22	-29	-19	-27	-13	25	-8	-9	19
	-17	-22	-3	-16	-35	12	8	22	-17	3	-22	-4	8	10	-12	23	-12	-47	11	-13
	-13	-2	-8	10	-3	19	50	-36	11	-35	26	-27	-17	-40	-14	-37	54	-4	-22	-42
	-34	-29	11	-9	-43	19	27	6	4	12	-1	6	23	3	-8	-6	10	7	-5	14
	-13	9	-3	11	9	17	12	-4	5	-18	8	-6	-19	-11	-14	0	10	-8	-2	-3
	30	-2	0	9	-12	-12	19	-14	-20	-26	-4	21	-1	-13	0	-12	5	-2	-9	-8
	-24	-15	17	-30	24	19	14	-66	12	-27	37	-27	-5	6	-42	-5	35	12	-16	-14
	25	19	26	-3	12	36	28	10	13	-13	21	-3	-2	-32	-30	15	-20	0	-3	-7
	-13	20	5	4	34	36	33	22	18	-36	28	-24	-29	-32	-26	7	4	-15	-2	-6
	-5	26	-8	20	30	54	22	-11	4	-25	49	-24	-46	-31	-18	0	-5	-26	-1	-11
	-15	6	-2	-3	1	27	1	-15	-13	-23	14	6	15	-19	-19	-51	5	-11	14	-7
	-12	14	16	15	25	50	23	2	7	-24	25	-28	-40	-31	-8	-26	-5	-17	2	-1
	7	19	10	14	21	15	15	-2	2	-17	21	-16	-23	-24	-19	-24	-9	-5	0	-1
	40	45	5	29	35	10	8	32	23	2	32	-16	-7	-21	-12	-15	3	-15	20	3
	19	-19	-5	32	-14	4	-44	8	14	1	2	5	-33	-1	-1	4	-8	-26	3	42
	-22	18	11	17	42	74	24	-19	16	-31	20	-20	-42	-47	-18	-30	-10	-24	-17	-7
	6	5	6	12	8	21	12	-44	4	-5	39	-21	-15	-22	-7	-17	20	3	-8	-1
	-27	23	3	27	21	32	25	-1	6	-20	20	-6	-40	-36	-25	-5	-1	-12	-26	1
	10	36	7	28	21	50	45	-28	7	-44	20	2	-18	-32	-6	-37	-22	-11	-5	12
	UPDATE GATE RECURRENT WEIGHTS:
	5	5	34	36	25	10	65	-1	-55	-13	16	-10	-1	42	22	14	-22	-28	-17	-24
	49	-45	61	16	49	2	79	-59	-52	-10	24	-28	17	-16	-1	39	25	18	-15	-30
	13	5	-20	13	-3	-26	2	14	19	-19	-21	6	-15	13	0	20	-1	30	5	15
	38	-21	63	62	75	54	67	-47	-69	11	25	-54	11	37	11	22	11	0	10	-29
	-7	-19	14	-33	-5	-10	36	-10	1	4	-34	1	-19	-26	-23	6	-35	22	-12	10
	82	-60	27	32	23	70	39	-27	-39	-55	106	-58	49	50	63	19	77	-87	57	-127
	-24	21	16	-22	-12	-9	16	-10	-4	-26	-16	-15	14	21	9	40	-17	20	3	-18
	14	35	-30	-5	36	27	-30	55	-52	-7	-1	-19	24	3	46	47	0	-6	17	-8
	15	-31	33	-18	14	-2	33	28	-36	-6	-4	-28	-21	-35	22	37	-17	6	-23	37
	18	-58	40	68	34	46	106	-23	-62	-45	24	-50	57	26	77	37	36	-26	0	-54
	12	-48	16	11	45	24	56	-23	-38	2	-15	-20	-11	24	38	29	38	-17	8	-43
	27	-14	53	24	22	-17	40	31	-25	10	10	18	-20	-25	-2	9	-14	33	18	21
	47	-51	7	33	43	12	59	-34	-66	-23	39	-46	42	-23	37	43	72	-30	27	-48
	71	-62	28	51	26	18	46	0	-26	-71	71	-64	39	61	59	4	30	-33	14	-76
	15	-37	26	20	18	-1	42	-4	2	2	51	-25	5	16	6	-10	17	-20	-5	-8
	15	5	-10	13	-10	-4	5	22	-42	-4	-7	16	13	-4	-4	-15	-5	0	22	2
	66	-47	5	39	42	-19	85	-50	-35	-39	52	-58	38	0	67	25	-16	-66	8	-72
	-7	-12	33	8	24	-27	24	6	3	21	7	-8	2	19	10	38	19	23	-3	-28
	84	-32	25	40	22	25	50	-14	-69	-111	57	-43	49	54	64	5	70	-74	80	-104
	53	-22	25	38	26	-9	46	2	-4	18	-8	-47	18	17	54	39	42	-8	-18	1
	RESET GATE INPUT WEIGHTS:
	18	-71	-4	-44	-22	-32	-27	27	-9	-8	-44	18	22	13	17	-2	17	-12	-24	-23
	15	-35	29	-25	-18	15	-22	18	47	52	-1	32	13	-20	30	-1	-18	48	53	21
	21	-3	-12	7	-44	-83	-10	25	-2	-21	-69	60	3	32	35	-1	-35	0	-7	23
	41	-17	-21	-10	-25	-67	-41	26	0	28	-68	29	15	65	27	44	-13	37	1	35
	25	-11	17	7	7	-10	-10	-19	8	52	-61	7	-15	-3	41	-26	9	51	62	16
	-41	52	-4	18	43	47	44	-46	-19	-38	39	-23	-11	-17	-12	-11	31	-29	-55	-6
	49	-34	49	-3	-24	-19	3	9	0	-24	11	14	21	-6	5	-6	-25	10	2	20
	16	-37	39	33	-20	-30	-7	-15	1	23	-54	17	2	12	-7	38	-35	61	37	46
	-6	-26	-34	-21	11	25	58	-10	16	-17	26	17	2	-32	-53	-31	26	-76	-37	-26
	11	-44	26	-20	-37	-2	-18	45	38	31	-45	-6	32	28	24	-40	4	26	9	20
	-46	68	-36	30	68	78	55	-18	9	-40	54	-43	-69	-10	-6	-17	-15	-55	8	-4
	32	-28	-29	3	-26	-78	-17	12	36	-2	-12	14	9	37	22	14	-20	8	-5	29
	-47	43	5	-4	56	23	53	6	-17	-64	60	-23	-3	-26	-11	-25	14	1	-7	-5
	23	-26	46	1	14	12	-5	33	3	-10	-16	-23	-34	-50	-13	-5	-18	44	38	32
	17	0	43	15	15	-13	-45	51	27	3	5	-14	13	26	39	-1	-7	44	36	16
	54	-11	40	23	16	-18	-32	61	60	42	-19	15	-20	27	15	50	-48	12	-5	41
	-1	-15	-15	2	-35	-48	7	-19	7	6	-11	40	7	44	7	9	-26	15	39	15
	-4	-51	8	-39	-8	3	5	-7	-1	9	-27	0	55	35	35	-26	-10	29	23	-3
	-38	31	-16	20	20	18	31	-21	14	-34	-13	8	-7	-28	33	-15	22	-52	-32	9
	18	-52	30	13	-40	-90	-57	-25	14	46	-30	29	20	39	1	3	23	56	56	10
	RESET GATE RECURRENT WEIGHTS:
	-9	9	-6	-53	-25	-8	-13	36	20	-1	-14	-3	-11	-60	-25	-12	17	-11	-16	12
	-26	21	-32	-21	-6	-8	0	45	15	0	-14	10	-27	-57	-7	-25	-38	-8	5	30
	-42	86	-23	-18	-15	-16	-31	-16	52	28	-76	57	-65	-54	-91	-29	-41	29	-68	98
	-59	20	-36	-47	-15	-18	-59	34	41	0	-33	53	-53	-14	-54	-22	-22	30	-52	41
	-41	20	1	3	3	-45	2	-23	19	18	-43	-26	-3	-15	-46	-41	-22	0	-2	71
	14	-26	24	20	-14	9	1	-35	-1	-22	37	-19	-4	24	17	-13	43	27	20	-30
	-65	21	-26	-15	-24	-21	-35	16	5	21	-19	52	-5	-2	-28	4	-23	9	-47	58
	18	22	-3	25	-24	-4	-5	-13	-9	16	-22	32	-30	-20	-23	12	0	-15	-23	-14
	8	-33	70	36	34	0	45	-29	19	11	-17	-15	16	5	-14	55	-10	1	-27	-17
	-16	-1	-22	-19	5	7	38	9	16	-2	-38	2	2	-7	-17	-16	-1	-14	-19	-11
	12	14	-7	3	56	3	16	-4	-8	13	10	-7	13	-2	15	19	9	15	9	1
	-37	56	-28	-60	-31	-76	-38	35	34	26	-32	4	-46	-60	-19	7	-49	20	-45	36
	7	-12	26	13	12	44	13	-6	-2	-10	16	0	18	2	13	13	8	-5	8	-36
	15	37	-17	-37	-3	-31	-24	-8	7	26	-50	28	-18	1	-34	16	-36	8	-13	-2
	13	-3	2	-8	-4	15	15	1	11	30	1	31	-4	-4	-8	-9	-6	-6	-8	10
	-41	21	-9	-39	-10	-1	16	14	38	53	-12	7	3	7	-14	5	-8	-28	-19	49
	-19	30	-18	-59	-31	-54	-27	-21	15	62	-20	44	-57	-15	-13	13	-63	17	-51	39
	-15	15	-36	-29	-12	-14	-31	0	56	-6	-16	16	-36	-23	-19	24	-18	36	-5	45
	37	-50	23	63	-3	35	10	-1	19	-39	12	-74	42	17	1	6	33	-15	-5	-29
	4	-2	19	14	20	-5	1	2	5	-31	-12	35	-38	-13	-8	7	0	12	-17	-9
	COMPUTE GATE INPUT WEIGHTS:
	-17	4	2	12	-3	14	4	-5	-4	-5	-4	14	-8	-2	3	12	15	0	10	-6
	11	3	13	-16	2	-34	-10	36	1	16	-9	-8	-2	25	-18	-4	10	-11	17	17
	-19	-2	-8	-27	-11	42	18	23	-21	-5	19	-24	6	-24	1	-21	-2	-24	6	-4
	-10	3	4	-12	2	44	22	5	10	-21	7	8	4	-11	3	1	20	-37	-4	-34
	-22	9	7	-25	4	19	19	-25	3	7	19	-8	-8	-3	4	-20	4	6	15	-20
	-18	7	-2	7	8	11	5	-15	0	-5	9	-6	-12	-9	-10	5	7	-6	-3	-4
	21	3	24	-28	-11	40	2	5	-5	27	18	34	-16	-13	8	15	18	-19	0	27
	11	24	24	-8	16	-2	-25	2	14	13	-4	0	7	-11	-10	14	-5	17	8	-5
	25	-1	1	16	0	-21	-15	29	-17	10	-2	-3	-1	17	-10	2	-3	8	21	14
	18	-24	-2	-8	-2	-32	-13	10	3	19	-6	3	18	20	-4	1	-25	12	13	12
	-26	5	-7	-19	15	20	14	7	-12	-1	10	2	-6	-14	4	-4	15	-1	-1	-20
	22	-4	12	15	-12	-38	-4	1	-3	-11	5	23	-4	26	-27	10	21	18	13	0
	-25	10	-1	0	19	31	18	-8	-3	-11	16	-8	-10	-16	4	0	-8	-12	-9	-11
	16	2	-5	13	9	9	7	2	2	4	2	-3	-6	-14	5	26	-20	2	-13	1
	13	23	-2	12	25	2	2	-19	3	9	-8	0	-6	0	14	14	-20	26	-5	-6
	-28	-10	50	-6	16	14	-19	-16	0	18	35	-7	2	18	1	33	-22	-11	-7	41
	-17	-4	0	-25	28	25	28	-3	-14	-12	2	3	-21	-32	7	-7	2	-3	-31	-25
	19	-4	32	18	-6	-12	-10	34	6	12	4	-7	7	14	-10	7	-2	2	18	15
	-1	11	-8	6	9	29	13	-14	4	4	14	-11	-14	-3	-11	-10	-13	-10	5	-18
	7	-23	-11	-3	-23	-30	-9	25	11	23	-10	-17	17	10	-7	4	10	0	7	15
	COMPUTE GATE RECURRENT WEIGHTS:
	6	-9	37	29	19	-27	1	-23	23	6	-47	-60	-43	-9	-22	14	-18	-5	-24	-45
	-4	-29	-22	-12	20	18	-21	15	-46	39	-5	30	12	-30	-16	27	-39	12	-14	22
	-5	18	7	25	0	-13	17	-17	25	-11	-2	-9	-3	3	60	18	23	24	4	-32
	-2	-11	33	1	-8	35	-7	-6	39	0	-16	-35	3	23	31	-2	11	2	19	4
	-23	8	-1	26	17	4	7	-4	-23	0	24	-38	-49	-10	18	24	-5	4	-13	-23
	12	5	52	38	54	-76	28	-23	2	0	-49	-54	-14	22	35	9	16	-19	-47	-55
	-11	29	20	5	16	-6	-22	-13	-1	-12	-3	-16	48	14	5	33	12	18	-48	15
	8	-10	-8	-30	-14	27	-3	-12	-7	12	65	-10	7	1	-14	20	-4	15	24	6
	19	16	-26	9	-13	23	-26	-8	-24	-40	13	4	-46	15	21	-3	-16	29	-36	0
	-38	15	-32	-29	7	-28	-12	6	-1	-34	21	15	2	-24	-20	-12	-23	3	23	39
	47	-14	28	22	11	-26	49	-34	39	-7	-81	-1	-19	54	28	17	9	-7	-30	-35
	-12	-12	13	-7	-8	19	-4	-30	-87	-7	-13	-4	-22	-44	-20	-21	-10	-2	14	28
	47	-18	12	12	30	20	34	-9	25	12	-14	-14	-30	22	24	-21	14	-13	-2	-20
	32	3	12	23	29	-2	-21	8	20	-21	-19	-24	-41	-26	7	-12	-7	-35	-12	-33
	4	-12	7	25	-25	0	-7	-2	84	-24	-41	-12	-9	-3	-28	-19	17	-10	28	11
	-18	8	20	-2	23	1	-41	12	33	9	3	8	36	1	27	-20	20	-7	-6	0
	-2	-4	48	6	16	-16	-9	2	44	-12	-12	-14	-2	21	-1	-12	28	23	5	-12
	-13	-1	-14	-14	-38	26	-24	45	-41	6	12	7	33	0	-5	-6	-37	11	44	3
	2	1	41	18	34	18	43	-30	11	-14	-40	-55	6	38	11	12	17	-26	-61	-8
	12	-3	-47	-44	7	8	34	25	-50	3	38	6	30	14	-60	13	-31	16	32	5
	_Bias:
	0x004d 	0x004d 	0x0011 	0x0045 	0x001f 	0x007f 	0x0011 	0x0013 	0xffffffee 	0x007f 	0x0043 	0x001b 	0x007f 	0x007f 	0x0036 	0x0016 	0x007f 	0x0018 	0x007f 	0x0036 
	0xffffffee 	0xfffffff9 	0xffffffc3 	0xffffffd7 	0xfffffff8 	0x0005 	0xffffffe1 	0xffffffda 	0x001f 	0x0004 	0x000f 	0xffffffc7 	0x0000 	0x001d 	0xfffffff4 	0xfffffffd 	0xffffffd4 	0xfffffff9 	0x0000 	0xffffffe5 
	0x0005 	0xfffffff2 	0x002c 	0x002d 	0x0027 	0xffffffde 	0x004d 	0xffffffe1 	0xffffff9a 	0xfffffffe 	0xfffffff9 	0xffffffd2 	0xfffffffb 	0x0007 	0x000a 	0x0041 	0x0004 	0x0010 	0xfffffffa 	0xfffffff4 


	//! ENABLED_BIAS_FOR_ALL_LAYERS... 		//! ACTIVATION_NONE_e
	_Layer:   3  SHAPE: 20X20  TOTAL_NEURONS:  20  TOTAL_WEIGHTS: 400  TOTAL_REC_WEIGHTS:   0  NO_OF_CORES:   5	LAYER_FCN_e
	_Weights:
	0x0028 	0xfffffff0 	0x0019 	0x001d 	0xffffffcb 	0x0027 	0x0012 	0x002c 	0xffffffd6 	0x000c 	0x000a 	0x003f 	0xffffffd4 	0xffffffff 	0xffffffd1 	0xffffffe7 	0xffffffb6 	0x0034 	0x0023 	0xffffffdc 	
	0xffffffef 	0x0001 	0xfffffffd 	0xffffffe9 	0x000b 	0xfffffff6 	0xffffffdd 	0x0010 	0xfffffffa 	0x000b 	0xfffffffc 	0xffffffe5 	0x0023 	0xfffffff0 	0x000a 	0x0010 	0xfffffffd 	0x0014 	0xffffffed 	0x0000 	
	0x0001 	0x0000 	0xffffffff 	0xffffffff 	0x0000 	0x0001 	0xffffffff 	0x0001 	0x0000 	0x0003 	0x0001 	0x0001 	0x0001 	0xffffffff 	0x0001 	0x0000 	0x0001 	0xffffffff 	0x0001 	0x0001 	
	0xfffffffc 	0x0003 	0xffffffe2 	0x0018 	0x0007 	0xfffffffa 	0x0005 	0x0006 	0xffffffea 	0x0009 	0x000b 	0xfffffff1 	0x0001 	0x0003 	0x0000 	0xfffffffa 	0xfffffff4 	0x0009 	0x000e 	0xffffffff 	
	0xffffffff 	0x0001 	0xfffffffe 	0x0001 	0x0000 	0x0000 	0x0000 	0x0000 	0xffffffff 	0x0001 	0x0000 	0xffffffff 	0x0001 	0x0000 	0x0000 	0x0000 	0xffffffff 	0x0000 	0x0001 	0xffffffff 	
	0x0046 	0x0005 	0x0008 	0x0029 	0xffffffc5 	0x001e 	0x0045 	0x0005 	0xffffffc5 	0x0019 	0x0036 	0x0037 	0xfffffffa 	0x003f 	0xffffffc1 	0xffffffc6 	0xffffffcb 	0x000f 	0x000e 	0xffffffbd 	
	0x0000 	0x0000 	0x0000 	0x0001 	0x0000 	0x0000 	0x0001 	0x0001 	0x0000 	0x0000 	0x0000 	0x0002 	0x0000 	0x0000 	0xffffffff 	0x0000 	0xffffffff 	0x0000 	0x0000 	0x0001 	
	0xffffffff 	0x0001 	0x0003 	0xfffffffb 	0xfffffffd 	0x0000 	0xffffffff 	0x0001 	0x0003 	0xfffffffc 	0xffffffff 	0xfffffff7 	0xfffffffc 	0x0001 	0x0004 	0xfffffffc 	0xfffffffc 	0xfffffff2 	0xfffffffe 	0xfffffffb 	
	0xfffffffe 	0x0004 	0x0007 	0x0002 	0xffffffff 	0x0009 	0xfffffffb 	0xfffffffc 	0x0007 	0xfffffffc 	0x0009 	0x000f 	0xfffffffd 	0x0006 	0xfffffffd 	0xfffffffb 	0x000a 	0xfffffffb 	0xfffffff7 	0xfffffffa 	
	0xffffffc1 	0xffffffda 	0xffffffed 	0xffffffb9 	0x0007 	0xffffffd1 	0xffffffb6 	0xfffffff2 	0x0004 	0xffffffe2 	0xffffffcd 	0xffffffc9 	0x0021 	0xffffffbf 	0x0001 	0x001d 	0x002c 	0xffffffe2 	0xffffffcf 	0x0030 	
	0x0006 	0x0031 	0x0018 	0x0038 	0xfffffffe 	0x0006 	0x002f 	0x003e 	0xffffffd7 	0x0012 	0x002f 	0x0017 	0x0001 	0x0012 	0xffffffe2 	0xffffffd4 	0xffffffd5 	0x0036 	0x003b 	0xffffffe5 	
	0xfffffffd 	0x0000 	0xfffffff6 	0x0007 	0x0002 	0xfffffffd 	0xfffffffb 	0x0004 	0xfffffffc 	0xfffffff9 	0x0004 	0x0001 	0xfffffffe 	0xfffffffa 	0x0001 	0xfffffffe 	0x0007 	0xfffffff7 	0x0006 	0xfffffff6 	
	0x0030 	0x0041 	0x003d 	0x002f 	0xffffffe2 	0x0030 	0x0014 	0x003b 	0xffffffd1 	0x0041 	0x001f 	0x0004 	0xfffffff1 	0x005f 	0xffffffbb 	0xffffffeb 	0xffffffe6 	0x004e 	0x0016 	0xffffffdd 	
	0x0016 	0x0046 	0x0014 	0x0043 	0xffffffbc 	0x003e 	0x001e 	0x003b 	0xffffffd4 	0x000c 	0x004a 	0x0015 	0xffffffe3 	0x002e 	0xffffffbf 	0xffffffb9 	0xffffffe7 	0x001e 	0x0028 	0xffffffbe 	
	0x0006 	0xffffffee 	0x000a 	0x0017 	0x0011 	0xffffffef 	0x000f 	0x0015 	0xfffffff4 	0xffffffff 	0x0000 	0x0002 	0xfffffff6 	0xffffffed 	0x000f 	0x000a 	0xffffffe3 	0x001f 	0x0024 	0xfffffffe 	
	0x0000 	0x0002 	0xfffffffe 	0x0001 	0xffffffff 	0x0001 	0x0000 	0xfffffffe 	0xffffffff 	0x0001 	0x0000 	0x0001 	0xfffffffd 	0x0001 	0xffffffff 	0xffffffff 	0xffffffff 	0x0002 	0x0001 	0x0001 	
	0xfffffff5 	0x000b 	0x0028 	0x000d 	0xffffffce 	0x0027 	0xffffffff 	0x0008 	0xffffffe6 	0x0038 	0x0006 	0x0026 	0xffffffda 	0x0006 	0xffffffe7 	0xffffffe0 	0xffffffbc 	0x000d 	0xffffffe7 	0xfffffff7 	
	0xfffffff6 	0xffffffec 	0x0012 	0x000e 	0x0011 	0xfffffffb 	0xfffffff8 	0xffffffeb 	0x000e 	0x0004 	0xffffffec 	0x0007 	0x0016 	0x0000 	0x0007 	0x0006 	0xffffffef 	0xffffffe6 	0x001a 	0xfffffff9 	
	0x0045 	0x003f 	0x0009 	0x0049 	0xffffffbd 	0x0022 	0x002f 	0x0041 	0xffffffc9 	0x0038 	0x0022 	0x0024 	0xffffffdc 	0x0040 	0xfffffff3 	0xffffffcc 	0xffffffcd 	0x0004 	0x0029 	0xffffffc9 	
	0x0010 	0xfffffff3 	0xfffffff9 	0xffffffe3 	0x0026 	0xffffffef 	0xffffffed 	0xffffffdf 	0xffffffde 	0xffffffd6 	0xfffffff5 	0xfffffff0 	0x0016 	0xffffffda 	0x000e 	0x001a 	0x0022 	0x0005 	0x001b 	0x001e 	
	_Bias:
	0xffffffff 	0xfffffffd 	0x001f 	0x0002 	0x0007 	0xfffffffc 	0xfffffffe 	0x0006 	0x0005 	0xfffffff7 	0x0007 	0x0011 	0xfffffff8 	0xfffffffc 	0x0004 	0xfffffffc 	0x0001 	0x000a 	0x0005 	0xfffffff0 


	//! ENABLED_BIAS_FOR_ALL_LAYERS... 		//! ACTIVATION_SIGMOID_e
	_Layer:   4  SHAPE: 20X1  TOTAL_NEURONS:   1  TOTAL_WEIGHTS:  20  TOTAL_REC_WEIGHTS:   0  NO_OF_CORES:   1	LAYER_FCN_e
	_Weights:
	0xfffffffb 	
	0xfffffffc 	
	0xffffffff 	
	0xfffffffe 	
	0x0004 	
	0xfffffffc 	
	0xfffffffb 	
	0xfffffffd 	
	0x0002 	
	0xfffffffe 	
	0xfffffffc 	
	0x0000 	
	0x0001 	
	0xfffffffd 	
	0x0004 	
	0x0002 	
	0x0002 	
	0x0000 	
	0xfffffffc 	
	0x0003 	
	_Bias:
	0xffffff81 

	*************************/
void SETUP_AND_INITIALIZE_HW_DEVICE_()
{

	rprintf_color(br_blue_fg "\r\n----------------------------------------------------------------------------------------------------------------------------------------\r\n");
	rprintf_color(br_cyan_fg "THIS TASK-CODE IS AUTO-GENARATED on 2022-07-27 15:35:37+0530 BY THE GPX-COMPILER Version: 7.4003\r\n");
	rprintf_color(cyan_fg "AUTHOR: channa@ambientscientific.ai\r\n");
	//! -------------------------------------------------------------------------------------------------------------------
	uint16_t              opm_width =	32;
	uint16_t              wtm_width =	16;
	uint32_t           no_of_cores_ =	5;
	uint32_t            packer_out_ =	2;	//! 1 for msb select, 0 for lsb select

	uint32_t width_bits = Get_OPM_WTM_WidthBits(opm_width, wtm_width);
	SETUP_HARDWARE_REGS(width_bits, packer_out_);
	SETUP_INFERENCE_TYPE( 1 );
	PREG_ZEROIN_ALL_CORES(false);
	WTM_ZEROIN_ALL_CORES();

	rprintf_color("WRITE_DATA_2PREG...\r\n");
	WRITE_DATA_2PREG();
	rprintf_color("WRITE_INFERENCE_DATA_2PREG...\r\n");
	WRITE_INF_DATA_2PREG();
	rprintf_color("WRITE_WEIGHT_COEFFICIENTS...\r\n");
	WRITE_WEIGHT_COEFFICIENTS();
	rprintf_color("WRITE_DATA_2WTM_OPM...\r\n");
	WRITE_DATA_2WTM_OPM(opm_width, wtm_width);
	rprintf_color("WRITE_ACTIVATION_FN...\r\n");
	WRITE_ACT();

	rprintf_color("CHANNEL_INIT_FN...\r\n\r\n");
	APP_CONFGURE_INPUT_CHANNEL( 0 );

	//! ------------------------------------------------------------------------------------------
	//! AUTO GENERATED MICROCODE CODE.. DO NOT MODIFY...

	/****
	INPUT ADDRESS MAP FILE: 

	****/
	uint32_t mCode_AutoGenerated[] = 
	{

		//!  Generating microcode for layer:0 LAYER_INPUT_e ... 
		//! Processing                 OPRN_INIT_REG_
		0x00000000,  //00 NOP
		0xD0000890,  //01 SETBUFF outbuff = 9  SETBUFF fftrdbuff = 8  

		//! ;WRIREG_ALL
		0x68000000,  //02 WRREG 16 0x0
		0x68800020,  //03 WRREG 17 0x20
		0x69000000,  //04 WRREG 18 0x0
		0x60000000,  //05 WRREG 0x0 0x0		; o_NEURON
		0x60800001,  //06 WRREG 0x1 0x1		; i_BIAS
		0x6100000A,  //07 WRREG 0x2 0xa		; o_BIAS_NEURON
		0x6180000B,  //08 WRREG 0x3 0xb		; o_BIAS_NEURON_STATE
		0x6200000C,  //09 WRREG 0x4 0xc		; o_GRU_Zt
		0x6280000D,  //0a WRREG 0x5 0xd		; o_GRU_Zt_State
		0x6300000E,  //0b WRREG 0x6 0xe		; o_GRU_Rt
		0x6380000F,  //0c WRREG 0x7 0xf		; o_GRU_Rt_State
		0x64000011,  //0d WRREG 0x8 0x11		; o_gru_Ht_x_1_Zt
		0x64800018,  //0e WRREG 0x9 0x18		; i_INIT_COUNT_1
		0x6500001D,  //0f WRREG 0xa 0x1d		; i_STATE
		0x65800017,  //10 WRREG 0xb 0x17		; i_INIT_COUNT_0
		0x66000012,  //11 WRREG 0xc 0x12		; i_DENSE_OUT
		0x66800019,  //12 WRREG 0xd 0x19		; i_ACTIVATION_COUNT
		0x6700001A,  //13 WRREG 0xe 0x1a		; i_DETECTION_COUNT
		0x6780001B,  //14 WRREG 0xf 0x1b		; i_SENISITIVITY

		//! Processing                     OPRN_FFT_e

		//! DOT_PRODUCT

		//! ;MUL_		WRITE 0x02->0x0A (o_BIAS_NEURON), READ 0x0B->0x17 (i_INIT_COUNT_0), READ 0x02->0x0A (o_BIAS_NEURON)
		0x0000000B,  //15 NOP rd_addr = 0x0B
		0x00000002,  //16 NOP rd_addr = 0x02
		0x0000942B,  //17 NOP rd_addr = 0x0B alu_sel = mult wr_addr = 0x02 wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 1
		0x0000AC20,  //18 NOP rd_addr = 0x00 alu_sel = mult wr_addr = 0x02 wr_data_sel = alu mem_we = odd  in_sel = 1 sign_extend = 1

		//! ;LOOP_ST
		0x1F000000,  //19 LOOPST  0x0F
		0xE4000000,  //1a SETBITS clr_opm_full rd_addr = 0x00 
		0xE0008400,  //1b SETBITS use32 rd_addr = 0x00 SETBITS ld_samples rd_addr = 0x00 

		//! ;WAIT_MAC_3		WRITE 0x00->0x00 (o_NEURON), READ 0x02->0x0A (o_BIAS_NEURON), READ 0x02->0x0A (o_BIAS_NEURON)
		0x80113002,  //1c WAIT cc = neurons_valid wr_addr = 0x00 mem_we = both wr_data_sel = neurons rd_addr = 0x02

		//! ;ADD_2		WRITE 0x02->0x0A (o_BIAS_NEURON), READ 0x02->0x0A (o_BIAS_NEURON), READ 0x00->0x00 (o_NEURON)
		0x00000000,  //1d NOP rd_addr = 0x00
		0x00001022,  //1e NOP rd_addr = 0x02 alu_sel = add wr_addr = 0x02 wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 0
		0x00002822,  //1f NOP rd_addr = 0x02 alu_sel = add wr_addr = 0x02 wr_data_sel = alu mem_we = odd	in_sel = 1 sign_extend = 0
		0x98700000,  //20 INCREG 16 cc = always

		//! ;LOOP_C
		0x20700000,  //21 LOOPC cc = always
		//! LOG2
		0xE0004000,   //SETBITS LOG
		0xE0800002,  //SETBITS Shift & LOG
		0x00031032,  //LUT Log insel
		0x00031832,  //LUT Log insel
		0x00031032,  //LUT Log insel
		0x00031032,  //LUT Log insel
		0x00032033,  //LUT Log insel
		0x00041033,  //read @3, alu shift 8 bit wr_data_sel =0 mem_wr =1
		0x00042830,  //read @3, alu shift 8 bit wr_data_sel =0 mem_wr =1

		//! MUL_256

		//! ;WR_REG
		0x65800014,  //2a WRREG  0x0B 0x14

		//! ;MUL_		WRITE 0x03->0x0B (o_BIAS_NEURON_STATE), READ 0x0B->0x17 (i_INIT_COUNT_0), READ 0x03->0x0B (o_BIAS_NEURON_STATE)
		0x0000000B,  //2b NOP rd_addr = 0x0B
		0x00000003,  //2c NOP rd_addr = 0x03
		0x0000943B,  //2d NOP rd_addr = 0x0B alu_sel = mult wr_addr = 0x03 wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 1
		0x0000AC30,  //2e NOP rd_addr = 0x00 alu_sel = mult wr_addr = 0x03 wr_data_sel = alu mem_we = odd  in_sel = 1 sign_extend = 1
		0xF000C000,  //2f RESETBITS sel_log rd_addr = 0x00 RESETBITS use32 rd_addr = 0x00 

		//! ;WR_REG
		0x65800017,  //30 WRREG  0x0B 0x17

		//!  Generating microcode for layer:1 LAYER_GRU_e ... 
		//!                 OPRN_GRU_   Layer: 1
		//! --------------LAYER:  1-----------------
		//! Layer-1:   UPDATE GATE CALCULATION : UC_GRU_MAL::GRU_COMPUTE_Zt_Ex@  97  BIAS Pointing to:  1 (0x01 )

		//! ;WR_REG
		0x68800000,  //31 WRREG  0x11 0x00
		0xE0700800,  //32 SETBITS xbar_valid rd_addr = 0x00 SETBITS shift_bits = 7 rd_addr = 0x00 

		//! ;WAIT_XBAR_3	WRITE 0x00->0x00 (o_NEURON), READ 0x03->0x0B (o_BIAS_NEURON_STATE), READ 0x00->0x00 (o_NEURON)
		0x80000003,  //33 WAIT cc = xbar_load_done rd_addr = 0x03
		0x80113000,  //34 WAIT cc = neurons_valid mem_we = both wr_addr = 0x00 wr_data_sel = neurons rd_addr = 0x00

		//! ;SHIFT_2_REG
		0x00000000,  //35 NOP rd_addr = 0x00
		0x00041000,  //36 NOP rd_addr = 0x00 alu_sel = shift wr_addr = 0x00 wr_data_sel = alu mem_we = even
		0x00042801,  //37 NOP rd_addr = 0x01 alu_sel = shift wr_addr = 0x00 wr_data_sel = alu mem_we = odd  in_sel = 1

		//! ;ADD
		0x98701020,  //38 INCREG 16 cc = always rd_addr = 0x00 alu_sel = add wr_addr = 0x02 wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 0
		0x00002822,  //39 NOP rd_addr = 0x02 alu_sel = add wr_addr = 0x02 wr_data_sel = alu mem_we = odd in_sel = 1  sign_extend = 0

		//! ;WR_REG
		0x68800020,  //3a WRREG  0x11 0x20

		//! ;LOOP_ST_2
		0x11000000,  //3b LOOPST  0x01
				//! Weight Slice Pointing to: 1
		0xE0700800,  //3c SETBITS xbar_valid rd_addr = 0x00 SETBITS shift_bits = 7 rd_addr = 0x00 

		//! ;WAIT_XBAR_3	WRITE 0x00->0x00 (o_NEURON), READ 0x0A->0x1D (i_STATE), READ 0x00->0x00 (o_NEURON)
		0x8000000A,  //3d WAIT cc = xbar_load_done rd_addr = 0x0A
		0x80113000,  //3e WAIT cc = neurons_valid mem_we = both wr_addr = 0x00 wr_data_sel = neurons rd_addr = 0x00

		//! ;SHIFT_2_REG
		0x00000000,  //3f NOP rd_addr = 0x00
		0x00041000,  //40 NOP rd_addr = 0x00 alu_sel = shift wr_addr = 0x00 wr_data_sel = alu mem_we = even
		0x00042802,  //41 NOP rd_addr = 0x02 alu_sel = shift wr_addr = 0x00 wr_data_sel = alu mem_we = odd  in_sel = 1

		//! ;ADD
		0x00001030,  //42 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x03 wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 0
		0x00002833,  //43 NOP rd_addr = 0x03 alu_sel = add wr_addr = 0x03 wr_data_sel = alu mem_we = odd in_sel = 1  sign_extend = 0

		//! ;ACT_		WRITE 0x04->0x0C (o_GRU_Zt), READ 0x03->0x0B (o_BIAS_NEURON_STATE)
		0x00030043,  //44 NOP rd_addr = 0x03 wr_addr = 0x04 wr_data_sel = act
		0x00031843,  //45 NOP rd_addr = 0x03 wr_addr = 0x04 wr_data_sel = act  in_sel = 1 mem_we = even
		0x00032044,  //46 NOP rd_addr = 0x04 wr_addr = 0x04 wr_data_sel = act  in_sel = 0 mem_we = odd

		//! ;MULT_EVEN_ODD
		0x0000000A,  //47 NOP rd_addr = 0x0A
		0x98709454,  //48 INCREG 16 cc = always rd_addr = 0x04 alu_sel = mult wr_addr = 0x05 wr_data_sel = alu mem_we = even in_sel = 0  sign_extend = 1
		0x90F0AC55,  //49 INCREG 1 cc = always rd_addr = 0x05 alu_sel = mult wr_addr = 0x05 wr_data_sel = alu mem_we = odd  in_sel = 1  sign_extend = 1
				//! Weight Slice Pointing to: 2
				//! Incrementing BIAS via In-Direct Addressing... Gen-Reg: 0x01

		//! Layer-1:   RESET GATE CALCULATION : UC_GRU_MAL::GRU_COMPUTE_Rt_Ex@ 157  BIAS Pointing to:  1 (0x01 )
		0xE0700400,  //4a SETBITS ld_samples rd_addr = 0x00 SETBITS shift_bits = 7 rd_addr = 0x00 

		//! ;WAIT_MAC_3		WRITE 0x00->0x00 (o_NEURON), READ 0x01->0x01 (i_BIAS), READ 0x00->0x00 (o_NEURON)
		0x80113000,  //4b WAIT cc = neurons_valid wr_addr = 0x00 mem_we = both wr_data_sel = neurons rd_addr = 0x00

		//! ;SHIFT_2_REG
		0x00000000,  //4c NOP rd_addr = 0x00
		0x00041000,  //4d NOP rd_addr = 0x00 alu_sel = shift wr_addr = 0x00 wr_data_sel = alu mem_we = even
		0x00042801,  //4e NOP rd_addr = 0x01 alu_sel = shift wr_addr = 0x00 wr_data_sel = alu mem_we = odd  in_sel = 1

		//! ;ADD
		0x00001020,  //4f NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x02 wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 0
		0x98702822,  //50 INCREG 16 cc = always rd_addr = 0x02 alu_sel = add wr_addr = 0x02 wr_data_sel = alu mem_we = odd in_sel = 1  sign_extend = 0
				//! Weight Slice Pointing to: 3
		0xE0700800,  //51 SETBITS xbar_valid rd_addr = 0x00 SETBITS shift_bits = 7 rd_addr = 0x00 

		//! ;WAIT_XBAR_3	WRITE 0x00->0x00 (o_NEURON), READ 0x0A->0x1D (i_STATE), READ 0x00->0x00 (o_NEURON)
		0x8000000A,  //52 WAIT cc = xbar_load_done rd_addr = 0x0A
		0x80113000,  //53 WAIT cc = neurons_valid mem_we = both wr_addr = 0x00 wr_data_sel = neurons rd_addr = 0x00

		//! ;SHIFT_2_REG
		0x00000000,  //54 NOP rd_addr = 0x00
		0x00041000,  //55 NOP rd_addr = 0x00 alu_sel = shift wr_addr = 0x00 wr_data_sel = alu mem_we = even
		0x00042802,  //56 NOP rd_addr = 0x02 alu_sel = shift wr_addr = 0x00 wr_data_sel = alu mem_we = odd  in_sel = 1

		//! ;ADD
		0x00001030,  //57 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x03 wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 0
		0x00002833,  //58 NOP rd_addr = 0x03 alu_sel = add wr_addr = 0x03 wr_data_sel = alu mem_we = odd in_sel = 1  sign_extend = 0

		//! ;ACT_		WRITE 0x06->0x0E (o_GRU_Rt), READ 0x03->0x0B (o_BIAS_NEURON_STATE)
		0x00030063,  //59 NOP rd_addr = 0x03 wr_addr = 0x06 wr_data_sel = act
		0x00031863,  //5a NOP rd_addr = 0x03 wr_addr = 0x06 wr_data_sel = act  in_sel = 1 mem_we = even
		0x00032066,  //5b NOP rd_addr = 0x06 wr_addr = 0x06 wr_data_sel = act  in_sel = 0 mem_we = odd

		//! ;MUL_2		WRITE 0x07->0x0F (o_GRU_Rt_State), READ 0x06->0x0E (o_GRU_Rt), READ 0x0A->0x1D (i_STATE)
		0x0000000A,  //5c NOP rd_addr = 0x0A
		0x00009476,  //5d NOP rd_addr = 0x06 alu_sel = mult wr_addr = 0x07 wr_data_sel = alu mem_we = even in_sel = 0  sign_extend = 1
		0x0000AC70,  //5e NOP rd_addr = 0x00 alu_sel = mult wr_addr = 0x07 wr_data_sel = alu mem_we = odd  in_sel = 1  sign_extend = 1
		0x98700000,  //5f INCREG 16 cc = always
		0x90F00000,  //60 INCREG 1 cc = always
				//! BIAS pointing to 0x2
				//! Weight Slice Pointing to: 4
				//! Incrementing BIAS via In-Direct Addressing... Gen-Reg: 0x01

		//! Layer-1:   OUTPUT GATE CALCULATION : UC_GRU_MAL::GRU_COMPUTE_Ht_Ex@ 188  BIAS Pointing to:  1 (0x01 )
		0xE0700400,  //61 SETBITS ld_samples rd_addr = 0x00 SETBITS shift_bits = 7 rd_addr = 0x00 

		//! ;WAIT_MAC_3		WRITE 0x00->0x00 (o_NEURON), READ 0x01->0x01 (i_BIAS), READ 0x00->0x00 (o_NEURON)
		0x80113000,  //62 WAIT cc = neurons_valid wr_addr = 0x00 mem_we = both wr_data_sel = neurons rd_addr = 0x00

		//! ;SHIFT_2_REG
		0x00000000,  //63 NOP rd_addr = 0x00
		0x00041000,  //64 NOP rd_addr = 0x00 alu_sel = shift wr_addr = 0x00 wr_data_sel = alu mem_we = even
		0x00042801,  //65 NOP rd_addr = 0x01 alu_sel = shift wr_addr = 0x00 wr_data_sel = alu mem_we = odd  in_sel = 1

		//! ;ADD
		0x98701020,  //66 INCREG 16 cc = always rd_addr = 0x00 alu_sel = add wr_addr = 0x02 wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 0
		0x00002822,  //67 NOP rd_addr = 0x02 alu_sel = add wr_addr = 0x02 wr_data_sel = alu mem_we = odd in_sel = 1  sign_extend = 0
				//! Weight Slice Pointing to: 5
		0xE0700800,  //68 SETBITS xbar_valid rd_addr = 0x00 SETBITS shift_bits = 7 rd_addr = 0x00 

		//! ;WAIT_XBAR_3	WRITE 0x00->0x00 (o_NEURON), READ 0x07->0x0F (o_GRU_Rt_State), READ 0x00->0x00 (o_NEURON)
		0x80000007,  //69 WAIT cc = xbar_load_done rd_addr = 0x07
		0x80113000,  //6a WAIT cc = neurons_valid mem_we = both wr_addr = 0x00 wr_data_sel = neurons rd_addr = 0x00
				//! Calculate Ht'

		//! ;SHIFT_2_REG
		0x00000000,  //6b NOP rd_addr = 0x00
		0x00041000,  //6c NOP rd_addr = 0x00 alu_sel = shift wr_addr = 0x00 wr_data_sel = alu mem_we = even
		0x00042802,  //6d NOP rd_addr = 0x02 alu_sel = shift wr_addr = 0x00 wr_data_sel = alu mem_we = odd  in_sel = 1

		//! ;ADD
		0x00001030,  //6e NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x03 wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 0
		0x00002833,  //6f NOP rd_addr = 0x03 alu_sel = add wr_addr = 0x03 wr_data_sel = alu mem_we = odd in_sel = 1  sign_extend = 0
				//! Calculate  (Ht' * (1 - Zt))

		//! ;MUL1a_Ex		WRITE 0x08->0x11 (o_gru_Ht_x_1_Zt), READ 0x04->0x0C (o_GRU_Zt), READ 0x03->0x0B (o_BIAS_NEURON_STATE)
		0x0000C084,  //70 NOP rd_addr = 0x04 alu_sel = multi wr_addr = 0x08
		0x0000D083,  //71 NOP rd_addr = 0x03 alu_sel = multi wr_addr = 0x08 wr_data_sel = alu mem_we = even
		0x0008E888,  //72 NOP rd_addr = 0x08 alu_sel = multi wr_addr = 0x08 wr_data_sel = alu mem_we = odd  in_sel = 1 swap_input

		//! 0xE2000000, 0x30700000, //! break point

				//! Calculate  GRU output Ht and copy it to the iSTATE0=0x0a location...

		//! ;ADD_2		WRITE 0x0A->0x1D (i_STATE), READ 0x08->0x11 (o_gru_Ht_x_1_Zt), READ 0x05->0x0D (o_GRU_Zt_State)
		0x00000005,  //73 NOP rd_addr = 0x05
		0x000014A8,  //74 NOP rd_addr = 0x08 alu_sel = add wr_addr = 0x0A wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 1
		0x00002CAA,  //75 NOP rd_addr = 0x0A alu_sel = add wr_addr = 0x0A wr_data_sel = alu mem_we = odd	in_sel = 1 sign_extend = 1
		0x98700000,  //76 INCREG 16 cc = always
		0x90F00000,  //77 INCREG 1 cc = always
				//! BIAS pointing to 0x3
				//! Weight Slice Pointing to: 6
				//! Incrementing BIAS via In-Direct Addressing... Gen-Reg: 0x01

		//! Calculate MAC result for the next loop

		//! ;WR_REG
		0x68800000,  //78 WRREG  0x11 0x00
		0xE0700800,  //79 SETBITS xbar_valid rd_addr = 0x00 SETBITS shift_bits = 7 rd_addr = 0x00 

		//! ;WAIT_XBAR_3	WRITE 0x00->0x00 (o_NEURON), READ 0x0A->0x1D (i_STATE), READ 0x00->0x00 (o_NEURON)
		0x8000000A,  //7a WAIT cc = xbar_load_done rd_addr = 0x0A
		0x80113000,  //7b WAIT cc = neurons_valid mem_we = both wr_addr = 0x00 wr_data_sel = neurons rd_addr = 0x00

		//! ;SHIFT_2_REG
		0x00000000,  //7c NOP rd_addr = 0x00
		0x00041000,  //7d NOP rd_addr = 0x00 alu_sel = shift wr_addr = 0x00 wr_data_sel = alu mem_we = even
		0x00042801,  //7e NOP rd_addr = 0x01 alu_sel = shift wr_addr = 0x00 wr_data_sel = alu mem_we = odd  in_sel = 1

		//! ;ADD
		0x98701420,  //7f INCREG 16 cc = always rd_addr = 0x00 alu_sel = add wr_addr = 0x02 wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 1
		0x95702C22,  //80 INCREG 10 cc = always rd_addr = 0x02 alu_sel = add wr_addr = 0x02 wr_data_sel = alu mem_we = odd in_sel = 1  sign_extend = 1
				//! Weight Slice Pointing to: 7

		//! ;WR_REG
		0x68800020,  //81 WRREG  0x11 0x20

		//! ;LOOP_C
		0x20700000,  //82 LOOPC cc = always
		0x78700000,  //83 DECREG  0x10  cc = always
				//! Weight Slice Pointing to: 12
		0x75700000,  //84 DECREG  0x0A  cc = always

		//!  Generating microcode for layer:3 LAYER_FCN_e ... 
		//!               OPRN_DENSE_   Layer: 3
		//! --------------LAYER:  3-----------------ACTIVATION_FLAG: -1
		0xE0700800,  //85 SETBITS xbar_valid rd_addr = 0x00 SETBITS shift_bits = 7 rd_addr = 0x00 

		//! ;WAIT_XBAR_3	WRITE 0x00->0x00 (o_NEURON), READ 0x0A->0x1D (i_STATE), READ 0x00->0x00 (o_NEURON)
		0x8000000A,  //86 WAIT cc = xbar_load_done rd_addr = 0x0A
		0x80113000,  //87 WAIT cc = neurons_valid mem_we = both wr_addr = 0x00 wr_data_sel = neurons rd_addr = 0x00

		//! ;SHIFT_2_REG
		0x00000000,  //88 NOP rd_addr = 0x00
		0x00041000,  //89 NOP rd_addr = 0x00 alu_sel = shift wr_addr = 0x00 wr_data_sel = alu mem_we = even
		0x00042801,  //8a NOP rd_addr = 0x01 alu_sel = shift wr_addr = 0x00 wr_data_sel = alu mem_we = odd  in_sel = 1

		//! ;ADD_2		WRITE 0x02->0x0A (o_BIAS_NEURON), READ 0x01->0x01 (i_BIAS), READ 0x00->0x00 (o_NEURON)
		0x00000000,  //8b NOP rd_addr = 0x00
		0x00001421,  //8c NOP rd_addr = 0x01 alu_sel = add wr_addr = 0x02 wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 1
		0x00002C22,  //8d NOP rd_addr = 0x02 alu_sel = add wr_addr = 0x02 wr_data_sel = alu mem_we = odd	in_sel = 1 sign_extend = 1
		0x90F00000,  //8e INCREG 1 cc = always
		0x98700000,  //8f INCREG 16 cc = always
				//! BIAS pointing to 0x4
				//! Weight Slice Pointing to: 13
				//! Incrementing BIAS via In-Direct Addressing... Gen-Reg: 0x01

		//!  Generating microcode for layer:4 LAYER_FCN_e ... 
		//!               OPRN_DENSE_   Layer: 4
		//! --------------LAYER:  4-----------------ACTIVATION_FLAG: 1
		0xE0700800,  //90 SETBITS xbar_valid rd_addr = 0x00 SETBITS shift_bits = 7 rd_addr = 0x00 

		//! ;WAIT_XBAR_3	WRITE 0x00->0x00 (o_NEURON), READ 0x02->0x0A (o_BIAS_NEURON), READ 0x00->0x00 (o_NEURON)
		0x80000002,  //91 WAIT cc = xbar_load_done rd_addr = 0x02
		0x80113000,  //92 WAIT cc = neurons_valid mem_we = both wr_addr = 0x00 wr_data_sel = neurons rd_addr = 0x00

		//! ;SHIFT_2_REG
		0x00000000,  //93 NOP rd_addr = 0x00
		0x00041000,  //94 NOP rd_addr = 0x00 alu_sel = shift wr_addr = 0x00 wr_data_sel = alu mem_we = even
		0x00042801,  //95 NOP rd_addr = 0x01 alu_sel = shift wr_addr = 0x00 wr_data_sel = alu mem_we = odd  in_sel = 1

		//! ;ADD_2		WRITE 0x02->0x0A (o_BIAS_NEURON), READ 0x01->0x01 (i_BIAS), READ 0x00->0x00 (o_NEURON)
		0x00000000,  //96 NOP rd_addr = 0x00
		0x00001021,  //97 NOP rd_addr = 0x01 alu_sel = add wr_addr = 0x02 wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 0
		0x00002822,  //98 NOP rd_addr = 0x02 alu_sel = add wr_addr = 0x02 wr_data_sel = alu mem_we = odd	in_sel = 1 sign_extend = 0

		//! ;ACT_		WRITE 0x0C->0x12 (i_DENSE_OUT), READ 0x02->0x0A (o_BIAS_NEURON)
		0x000300C2,  //99 NOP rd_addr = 0x02 wr_addr = 0x0C wr_data_sel = act
		0x000318C2,  //9a NOP rd_addr = 0x02 wr_addr = 0x0C wr_data_sel = act  in_sel = 1 mem_we = even
		0x000320CC,  //9b NOP rd_addr = 0x0C wr_addr = 0x0C wr_data_sel = act  in_sel = 0 mem_we = odd

		//! Processing                    OPRN_INF_MC

		//! ;JUMPF_IF_SIGN_BIT
		0x0000000C,  //9c NOP rd_addr = 0x0C
		0x0000000F,  //9d NOP rd_addr = 0x0F
		0x3230400D,  //9e JUMP 0x04 cc = neg rd_addr = 0x0D alu_sel = sub

		//! ;ZERO_REG_
		0x0000000B,  //9f NOP rd_addr = 0x0B
		0x000090D0,  //a0 NOP rd_addr = 0x00 alu_sel = mult wr_addr = 0x0D wr_data_sel = alu mem_we = even

		//! ;JUMP_TO_START
		0x50000000,  //a1 JUMPI 0

		//! ;ADD_EVEN
		0x00000009,  //a2 NOP rd_addr = 0x09
		0x000010D0,  //a3 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x0D wr_data_sel = alu mem_we = even in_sel = 0

		//! ;WR_REG
		0x67800016,  //a4 WRREG  0x0F 0x16

		//! ;JUMPF_IF_SIGN_BIT
		0x0000000D,  //a5 NOP rd_addr = 0x0D
		0x0000000F,  //a6 NOP rd_addr = 0x0F
		0x3130400E,  //a7 JUMP 0x02 cc = neg rd_addr = 0x0E alu_sel = sub

		//! ;JUMP_TO_START
		0x50000000,  //a8 JUMPI 0

		//! ;ADD_EVEN
		0x00000009,  //a9 NOP rd_addr = 0x09
		0x000010E0,  //aa NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x0E wr_data_sel = alu mem_we = even in_sel = 0

		//! ;WR_REG
		0x6780001B,  //ab WRREG  0x0F 0x1B

		//! Processing                     OPRN_DEINIT_
	     //! OPRN_DEINIT_
		0x00000000,  //ac NOP
		0xE2000000,  //ad SETBITS intr_out
		0x30700000,  //ae JUMP 0 cc = always
	};

	uint32_t mc_size = sizeof(mCode_AutoGenerated) / sizeof(mCode_AutoGenerated[0]);
	AMBS_WriteMicrocode(&mCode_AutoGenerated[0], mc_size, width_bits);


	rprintf_color(br_blue_fg "\r\n------------------\r\n");

}//! END OF THE MAIN TASK... SUCCESS!!

void GET_MODEL_RESULT_AND_VERIFY(uint32_t no_of_cores_, uint32_t** test_result, int i_frame_in)		//! Function Definition
{
	int32_t result_preg_loc_[] =	{ 18, };
	int32_t    get_result_buffer_flag =	true;	
	int32_t*           test_result_ =	0;	
	int32_t        neurons_per_core =	4;	
	int32_t          neurons_2_read =	1;	
	int32_t                     n2r =	neurons_2_read;	

	if( get_result_buffer_flag  == true )
	{
		int32_t nor_ = 0, noc_ = 0, nol_ = 0, total_size = 0;

		nor_	= sizeof_a(result_preg_loc_);	//! number of registers to read.

		if( nor_ > 1 )	//! if no of registers to read is more than 1, display in full
		{
			noc_	= no_of_cores_;
			nol_	= 4;	//! nuumber of locations
			total_size	= (nor_ * noc_ * nol_) * sizeof(uint32_t);
			n2r	= 0;
		}
		else
		{
			total_size	= (nor_ * n2r) * sizeof(uint32_t);
		}
		test_result_ = (int32_t*)malloc( total_size );
		memset( test_result_, 0x0, total_size );
	}

	int32_t t_count = AMBS_ReadPreg_3(0, _P1( result_preg_loc_ ), test_result_, false, 4, n2r);
	*test_result = test_result_;
}

int INCR_PREG(int* prreg_loc, int cl_flag)
{
	(*prreg_loc)++;
	if (cl_flag && *prreg_loc == 0xA)
	{
		*prreg_loc = 0x13;	 //0x13 next available free slot
	}
	return *prreg_loc;
}

void WRITE_DATA_2PREG()		//! Function Definition
{

	int32_t prreg_loc =  1;
	int32_t cl_flag =  1;

	//! RC_CODE_GENERATOR::LOOP_FOR_PREG_WRITES
	//! FUNCTION SIGNATURE:
	//! void AMBS_writeToPreg_Ex(uint32_t core, const int32_t* data, const int data_size, const int32_t* shape, const int shape_size, const int32_t* preg_loc, const int preg_loc_size, bool b_log);
		//! Generating PREG code...
	//! Write PREG data...LAYER: 1	//! Total BIAS Values to be written: 60
	{
		int32_t bias_array_layer_1[][ 4] =
							{{ -8,   7,  23,   9},
							 { -9,  40,  34,  13},
							 { 10,  34,   2,  -6},
							 { -4,  -1,  10,   1},
							 {  8,  14,  14,  -1},
							 { -9,   1,   9,   9},
							 { 21,  25,  11,   6},
							 { 25,   3,  11,   8},
							 { 13,  -5,   5,   9},
							 { -8,  57,  31,  22},
							 {-15, -48, -20, -22},
							 {-32,  40,  33, -15},
							 { 31, -21,  35,  -2},
							 { 15, -24, -20, -21},
							 { -2, -52, -35, -18}};

		int32_t bias_rows = sizeof_a( bias_array_layer_1 );
		int32_t bias_cols = sizeof_a( bias_array_layer_1[0] );
		int32_t i_total_cores = 5;

		for(int core_i = 0, r_row_ = 0; r_row_ < bias_rows; core_i++, r_row_++)
		{
			if ( core_i >= i_total_cores )
			{
				core_i = 0;
				INCR_PREG(&prreg_loc, 1);
			}
			uint32_t r_shape_[] = { 1, bias_cols };
			uint32_t r_locat_[] = { prreg_loc };
			AMBS_writeToPreg_Ex ( core_i, _P3( bias_array_layer_1[r_row_], r_shape_, r_locat_ ), false );
		}
		INCR_PREG(&prreg_loc, 1);
	}
	//! Write PREG data...LAYER: 2	//! Total BIAS Values to be written: 60
	{
		int32_t bias_array_layer_2[][ 4] =
							{{  77,   77,   17,   69},
							 {  31,  127,   17,   19},
							 { -18,  127,   67,   27},
							 { 127,  127,   54,   22},
							 { 127,   24,  127,   54},
							 { -18,   -7,  -61,  -41},
							 {  -8,    5,  -31,  -38},
							 {  31,    4,   15,  -57},
							 {   0,   29,  -12,   -3},
							 { -44,   -7,    0,  -27},
							 {   5,  -14,   44,   45},
							 {  39,  -34,   77,  -31},
							 {-102,   -2,   -7,  -46},
							 {  -5,    7,   10,   65},
							 {   4,   16,   -6,  -12}};

		int32_t bias_rows = sizeof_a( bias_array_layer_2 );
		int32_t bias_cols = sizeof_a( bias_array_layer_2[0] );
		int32_t i_total_cores = 5;

		for(int core_i = 0, r_row_ = 0; r_row_ < bias_rows; core_i++, r_row_++)
		{
			if ( core_i >= i_total_cores )
			{
				core_i = 0;
				INCR_PREG(&prreg_loc, 1);
			}
			uint32_t r_shape_[] = { 1, bias_cols };
			uint32_t r_locat_[] = { prreg_loc };
			AMBS_writeToPreg_Ex ( core_i, _P3( bias_array_layer_2[r_row_], r_shape_, r_locat_ ), false );
		}
		INCR_PREG(&prreg_loc, 1);
	}
	//! Write PREG data...LAYER: 3	//! Total BIAS Values to be written: 20
	{
		int32_t bias_array_layer_3[][ 4] =
							{{ -1,  -3,  31,   2},
							 {  7,  -4,  -2,   6},
							 {  5,  -9,   7,  17},
							 { -8,  -4,   4,  -4},
							 {  1,  10,   5, -16}};

		int32_t bias_rows = sizeof_a( bias_array_layer_3 );
		int32_t bias_cols = sizeof_a( bias_array_layer_3[0] );
		int32_t i_total_cores = 5;

		for(int core_i = 0, r_row_ = 0; r_row_ < bias_rows; core_i++, r_row_++)
		{
			if ( core_i >= i_total_cores )
			{
				core_i = 0;
				INCR_PREG(&prreg_loc, 1);
			}
			uint32_t r_shape_[] = { 1, bias_cols };
			uint32_t r_locat_[] = { prreg_loc };
			AMBS_writeToPreg_Ex ( core_i, _P3( bias_array_layer_3[r_row_], r_shape_, r_locat_ ), false );
		}
		INCR_PREG(&prreg_loc, 1);
	}
	//! Write PREG data...LAYER: 4	//! Total BIAS Values to be written: 4
	{
		int32_t bias_array_layer_4[][ 4] =
							{{-127,    0,    0,    0},
							 {-127,    0,    0,    0},
							 {-127,    0,    0,    0},
							 {-127,    0,    0,    0},
							 {-127,    0,    0,    0},
							 };

		int32_t bias_rows = sizeof_a( bias_array_layer_4 );
		int32_t bias_cols = sizeof_a( bias_array_layer_4[0] );
		int32_t i_total_cores = 5;

		for(int core_i = 0, r_row_ = 0; r_row_ < bias_rows; core_i++, r_row_++)
		{
			if ( core_i >= i_total_cores )
			{
				core_i = 0;
				INCR_PREG(&prreg_loc, 1);
			}
			uint32_t r_shape_[] = { 1, bias_cols };
			uint32_t r_locat_[] = { prreg_loc };
			AMBS_writeToPreg_Ex ( core_i, _P3( bias_array_layer_4[r_row_], r_shape_, r_locat_ ), false );
		}
		INCR_PREG(&prreg_loc, 1);
	}
	//! ahb_write_reg(0x3A600054,  0x001b001b);
	//! ahb_write_reg(0x3A6000D4,  0x001b001b);
	reg_delay(20);
}

void WRITE_INF_DATA_2PREG()		//! Function Definition
{
		//! Generating Inference Data Write Code...
	{

		int32_t preg_loc = 0x1b;	//! SENSITIVITY_PREG_e
		int32_t value_array_[][ 4] = {{ 0x50, 0x50, 0x50, 0x50,  }};

		int32_t bias_rows = sizeof_a( value_array_ );
		int32_t bias_cols = sizeof_a( value_array_[0] );
		int32_t i_total_cores = 5;

		for(int core_i = 0, r_row_ = 0; core_i < i_total_cores; core_i++)
		{
			uint32_t r_shape_[] = { 1, bias_cols };
			uint32_t r_locat_[] = { preg_loc };
			AMBS_writeToPreg_Ex ( core_i, _P3( value_array_[r_row_], r_shape_, r_locat_ ), false );
		}
	}
	{

		int32_t preg_loc = 0x16;	//! THRESHOLD_PREG_e
		int32_t value_array_[][ 4] = {{ 0x6, 0x6, 0x6, 0x6,  }};

		int32_t bias_rows = sizeof_a( value_array_ );
		int32_t bias_cols = sizeof_a( value_array_[0] );
		int32_t i_total_cores = 5;

		for(int core_i = 0, r_row_ = 0; core_i < i_total_cores; core_i++)
		{
			uint32_t r_shape_[] = { 1, bias_cols };
			uint32_t r_locat_[] = { preg_loc };
			AMBS_writeToPreg_Ex ( core_i, _P3( value_array_[r_row_], r_shape_, r_locat_ ), false );
		}
	}
	{

		int32_t preg_loc = 0x17;	//! INIT_CNT_0_PREG_e
		int32_t value_array_[][ 4] = {{ 0, 0, 0, 0,  }};

		int32_t bias_rows = sizeof_a( value_array_ );
		int32_t bias_cols = sizeof_a( value_array_[0] );
		int32_t i_total_cores = 5;

		for(int core_i = 0, r_row_ = 0; core_i < i_total_cores; core_i++)
		{
			uint32_t r_shape_[] = { 1, bias_cols };
			uint32_t r_locat_[] = { preg_loc };
			AMBS_writeToPreg_Ex ( core_i, _P3( value_array_[r_row_], r_shape_, r_locat_ ), false );
		}
	}
	{

		int32_t preg_loc = 0x18;	//! INIT_CNT_1_PREG_e
		int32_t value_array_[][ 4] = {{ 0x1, 0x1, 0x1, 0x1,  }};

		int32_t bias_rows = sizeof_a( value_array_ );
		int32_t bias_cols = sizeof_a( value_array_[0] );
		int32_t i_total_cores = 5;

		for(int core_i = 0, r_row_ = 0; core_i < i_total_cores; core_i++)
		{
			uint32_t r_shape_[] = { 1, bias_cols };
			uint32_t r_locat_[] = { preg_loc };
			AMBS_writeToPreg_Ex ( core_i, _P3( value_array_[r_row_], r_shape_, r_locat_ ), false );
		}
	}
	{

		int32_t preg_loc = 0x14;	//! DOT_PRODUCT_MULT_e
		int32_t value_array_[][ 4] = {{ 0x80, 0x80, 0x80, 0x80,  }};

		int32_t bias_rows = sizeof_a( value_array_ );
		int32_t bias_cols = sizeof_a( value_array_[0] );
		int32_t i_total_cores = 5;

		for(int core_i = 0, r_row_ = 0; core_i < i_total_cores; core_i++)
		{
			uint32_t r_shape_[] = { 1, bias_cols };
			uint32_t r_locat_[] = { preg_loc };
			AMBS_writeToPreg_Ex ( core_i, _P3( value_array_[r_row_], r_shape_, r_locat_ ), false );
		}
	}
	{

		int32_t preg_loc = 0x15;	//! DOT_PRODUCT_LOG_e
		int32_t value_array_[][ 4] = {{ 0xfff6, 0xfff6, 0xfff6, 0xfff6,  }};

		int32_t bias_rows = sizeof_a( value_array_ );
		int32_t bias_cols = sizeof_a( value_array_[0] );
		int32_t i_total_cores = 5;

		for(int core_i = 0, r_row_ = 0; core_i < i_total_cores; core_i++)
		{
			uint32_t r_shape_[] = { 1, bias_cols };
			uint32_t r_locat_[] = { preg_loc };
			AMBS_writeToPreg_Ex ( core_i, _P3( value_array_[r_row_], r_shape_, r_locat_ ), false );
		}
	}
	reg_delay(20);
}

void WRITE_DATA_2WTM_OPM(uint16_t opm_width, uint16_t wtm_width)		//! Function Definition
{
	int32_t              opm_delay_ =	20;
	int32_t              wtm_delay_ =	100;
		//! Generating OPM/WTM code...
	//! Write WTM data...LAYER: 1
	//! FUNCTION SIGNATURE:
	//! int AMBS_writeToWTM_Ex(int WTM_WIDTH, int CORE, int SLICE, const uint32_t* v_data, const int data_size, int* v_Shape, int shape_size);
	{

		uint32_t v_WEIGHTS_SLICE_16[][64] = {
							{ 12,  -6, -15,  -4,  32, -19, -29, -22,  39,  22,  -1,  -4, -15, -16,   4,  -6,  43,  13, -14,  -8, 
							  -7,   6, -33,   4,  10,  22,   1,  41,  -5,  22, -26,   1,  10,   9,  -4, -43,  27,  52, -20,  22, 
							  -5,  44, -31,  44,   9,  20,  24,  17, -12,  10, -26, -19,   0, -17,  -5,  13,   2,   1,  35, -23, 
							 -30,  -6,   6,  25},
							
							{ 17, -19,  22,   9, -18,  -3, -12,  17, -14, -34,  -2, -27, -14,   3, -55,  11, -20,  14,  31,  11, 
							 -28, -27, -33,  22,   1,  15, -55,  52,  27, -18, -22, -21,  13,  10, -33,   7,  22,   9, -26,  -9, 
							  33,  12, -10,  37,  41, -31, -21,  36,   5, -27, -35,  32, -23,  19, -41, -10, -24, -22, -12, -11, 
							  16, -27, -21,  19},
							
							{ 31, -22,  12,  31, -24, -21, -16, -23, -12,  -3,  22,   1, -11,  16,  -1,  26, -29, -26,  36,  28, 
							  25,  29,   8, -21, -60, -19,  35,  15, -34,  28,  14,  44,  28,  -5, -43,   1, -16, -16,   1, -20, 
							  20, -14,   1,   6,  10,  13,  12,  -3,   6,   7, -12,  36,  39, -45, -20, -14, -10, -15,  -5,  10, 
							  27,  29, -13, -23},
							
							{-27, -30,   4, -20,   6,  -9,  24,  22,  23, -29,  15, -25, -24,   5,  13,  25, -12, -37,  36,  -9, 
							 -25,  24, -11, -20, -11,  19,  31,  43,   0,  14, -13,  20,  10, -20,  15,  -6,  28,  43,  22,  37, 
							 -11,  13, -27, -17,  29,   2,  17,  13,  24, -24,   7,  -1,  17,  31, -21,   7,   4, -23,  -5, -30, 
							 -25,   8, -18,  12},
							
							{ 27,  41,   0, -32,  40,  -9,  11,  11,  -6,  -3, -40,  12,  17, -20, -25,  -2,   2, -37, -36,  19, 
							  26,  -3,  35,   6,  -7, -19,   2, -17, -32, -11, -11,  -2,  15,  43,  15,  45,  30,  -8,   7, -22, 
							  20,  19, -38,  -3, -23,  -5,   2, -48, -14, -10,  -5, -49,  10,  -6,  12, -28,  -8, -33,  -3,   8, 
							  18, -21,  33,  -5},
							
							
						};

		int32_t v_SHAPE_SLICE_16[] = { 16,  4 };
		int32_t i_total_cores = 5;
		int32_t i_no_of_cores2write = sizeof_a(v_WEIGHTS_SLICE_16);
		for(int core_i_ = 0; core_i_ < i_no_of_cores2write; core_i_++)
		{
			AMBS_writeToWTM_Ex (wtm_width, core_i_, SLICE_16, _P2( v_WEIGHTS_SLICE_16[core_i_], v_SHAPE_SLICE_16 ), false, wtm_delay_ );
		}
	}

	{

		uint32_t v_WEIGHTS_SLICE_17[][80] = {
							{  3, -22,  -8,   2,  54,   1,  -7,  10, -35, -14,  46, -16, -13, -35,  37,  66,  18,  13, -11,  -1, 
							  18,  -8,  17,  30,  -2,   7,  -3, -10,  -5,  10,  45,   7,  34,  -7, -17,  -9,  -5,   4,   6,   1, 
							 -12,  -4,  26,   4,  13, -40, -25, -24, -21,  41,  -2,   5,  -6,  17,   9,  11, -10,  16, -22,  35, 
							 -13, -26,  33,  16,   4,  33,  17,  41,  10, -18, -23, -10,   9,   8,  38,  -9, -28, -11,   9,   0},
							
							{-61,  31,   0, -28,   5,   3,  -9,   2, -10,  40,  33,   2, -17,   1,  28,   0, -38, -27, -15,  42, 
							  15,  26, -11,   0,  60,  17, -49, -36, -31,   3,  47,   4,  -3, -24,  56,  37,  23,   9,  20, -21, 
							 -14,  21,  -7, -32,   9,  -1, -33, -18,  18, -38,  -3,  10,   0, -38,   6, -14,  -7,  -1, -21,  -4, 
							 -42,   1,   9,  35,  45,  23, -33,  -9,  15, -30,  35,   8, -24,  29,  22,  -5, -23,  27, -20,  15},
							
							{  3,   3,   3,  38,  26,  -3,   3,  16,   6,  48, -33, -40,  25, -30, -15,  30, -16,   3,   3, -16, 
							 -30,   7,  -7,  30,  -9,   3,  -5,  -8,  33,  -1,  25,   3,  32,   1, -28, -23,   3,  25, -28, -33, 
							 -36,  10,  20, -17,  14, -32,  17,  -5,  29, -40,   9,  11, -32, -17,  18, -31,  23,   5,  18, -20, 
							  16,  -7,  27, -17, -32,  21, -21, -10,   4,  31,   3,  23, -22,   9,  22,  31,   7, -32,  15, -11},
							
							{-13,   9,   4,  -3,  12,   6,  22,   2,  16,  -3,  -8,   3, -34,  -9,  22,  -7,   3, -16,   0,  13, 
							   7, -34,  -3,   3,  25,  14, -18,  11, -37,  19,  62, -17,   5,   6, -12,  50,  26,  12,  21,  10, 
							   7,  -8, -27,  54,  -7,  30,  38, -42, -14,   3,   5,  -3,   0,  29,   3, -16, -17, -18,  -3, -28, 
							 -30, -37,  24, -27,  18, -23, -37,   6, -46,   8,  19,  -9, -25,  -8,  13,  19, -19,  -5, -41, -34},
							
							{-18,  21, -21,  45, -16,  24,  23, -55,   3, -18,  34,  -9, -28,  29,  19, -10,   6,  -9,   7,  19, 
							   8,   7, -16, -11,  -6,   0,  13,  37, -11,   2,  19,   6, -18,  27,  24, -12, -35,   7,  16,  27, 
							  -9,  23,  38, -25,   6,  -6, -10, -20,  14,   6, -53,  25,   9,  34, -14,   6, -13,   6,  17,   0, 
							 -31, -18, -18,   1,   1, -18,  38,  33,   2, -12, -10,  11, -20, -11,  15,   9,   9,  15,  34,  35},
							
							
						};

		int32_t v_SHAPE_SLICE_17[] = { 20,  4 };
		int32_t i_total_cores = 5;
		int32_t i_no_of_cores2write = sizeof_a(v_WEIGHTS_SLICE_17);
		for(int core_i_ = 0; core_i_ < i_no_of_cores2write; core_i_++)
		{
			AMBS_writeToWTM_Ex (wtm_width, core_i_, SLICE_17, _P2( v_WEIGHTS_SLICE_17[core_i_], v_SHAPE_SLICE_17 ), false, wtm_delay_ );
		}
	}

	{

		uint32_t v_WEIGHTS_SLICE_18[][64] = {
							{ 15,  58, -24, -22,  -5,  36,   2,  -4,   6, -47, -11,   1,  -2,  -1,   1,   6,  34,  24,   0, -79, 
							  30,  58,  -6, -15,  28,  26,   5, -41,  -1, -29,  -2, -11,  -4,  26,  23, -43, -45,   7,  -9,  14, 
							 -63,  17,  10,   7,  -3,   7, -39,   5,  16, -39,  28,  -7, -29, -22, -39, -45, -20,  -3, -32, -37, 
							   6,  22,  -5, -15},
							
							{ -5, -21,  21,  31, -11, -35,  10,  87,  20,   4, -28,  16,  40,  14, -30,  -1, -29, -15, -11,  32, 
							 -23, -32, -27,  49, -18, -11,   9,  49,  -6,  23,   6,  19,  36,   3, -27,  44, -13,   0,  37,  26, 
							 -10, -17,  27, -26,  58,  18,  16,  10,   5, -13,  27, -36,  -7,  36,  58,  19,   1, -24, -29,  80, 
							  30, -29,   7,  20},
							
							{ 31,   2,  20,  57, -19, -23,  33,   7,  -2,  -6,  -1, -24,  43, -34, -10,  24, -42,   2, -18,  45, 
							  -1,  10,  12,  19,   1,  21,  -5,  21, -50,  -1, -24,  18,   2,  14, -28,  -7,  49,  10, -35, -28, 
							  29,  -6,  -2, -17,  15,  32,   7,  26,  60,  30,  -8,   6,  48, -23,   8,  25, -43, -13, -22, -10, 
							  27, -12,  28,  39},
							
							{ 12,  35, -15,  16,  25,   8,  -7,  -6,  43, -26, -31,  -3, -16,  25, -32, -38,  15,  29, -24,  46, 
							 -42,  -5,  16,  34,   1,   0,  60, -22, -22,  14,  21,  41,  48, -42,  41,  62, -11,  38,  -9,  10, 
							  31,   9, -23, -19,  -2,  16, -26,  13,  -4, -38,   4, -15, -17,  28, -56, -13, -11, -40, -18,   8, 
							 -36, -29,  16, -29},
							
							{ 67,  28,  -4,  37,  12, -10,   8,  37,  23,  -4,   3,   7,  15,  28,  -6,  53,  37,  -9,  25, -43, 
							  42, -32,   7,  -9,  29,  11,  15,   6,  30,  29,  -7,  40, -46,  -4,  12,  19, -34,  12,  50, -15, 
							 -13,  41,  10,  13, -27, -18,  13, -12,  -9, -20, -61, -12, -20,  21,  33,  -8,  -1,  53,  41,  41, 
							   8,  34, -17,  17},
							
							
						};

		int32_t v_SHAPE_SLICE_18[] = { 16,  4 };
		int32_t i_total_cores = 5;
		int32_t i_no_of_cores2write = sizeof_a(v_WEIGHTS_SLICE_18);
		for(int core_i_ = 0; core_i_ < i_no_of_cores2write; core_i_++)
		{
			AMBS_writeToWTM_Ex (wtm_width, core_i_, SLICE_18, _P2( v_WEIGHTS_SLICE_18[core_i_], v_SHAPE_SLICE_18 ), false, wtm_delay_ );
		}
	}

	{

		uint32_t v_WEIGHTS_SLICE_19[][80] = {
							{-26,  -5,  24,  33,  22, -22,  -6, -17,  -5,   5,  31, -42,  43,  -1,  34, -13,   7,   8, -40, -54, 
							   7,  -5,  27, -43,   2,   7,   9, -11, -14,  44,  33,  -6,  -9,   7,   7,  12,  -4, -30,   0,   6, 
							 -17,  16,   1, -11,  14,   4,   3, -11, -45,   2, -47, -11,   5, -15, -28, -16,  -3,   5,  19,  45, 
							   9,  16,   1,  14, -10, -57,  10, -19,  -4,  -8,  21, -17, -12,  -5,  29,  17, -27, -63,  43, -35},
							
							{ 51,  28,  24,  10,  18, -20,   4, -46,  14,  37,  19,  -9,  54,  17,  11,  51,  -9, -10, -13, -38, 
							  30,  11,   4,  34,  37, -15, -28,  15,  59,  58,  26,  13,  -8, -21,  19,  62,  38,  43,  -1,  10, 
							   0,  32,  12,  10,   6,  25,   4,  45,   8,   7,  -3, -56, -19, -21,  -4,  32,  -9,  -6,  31, -12, 
							 -15,  -5,  20,  31,  -9,  35, -41, -22,   5,  -6,  -3, -26,  45,  17,  26, -11,   6,  25,  20,  58},
							
							{ 18,   4,  33,  26,  -1,  10, -33, -27, -12,  -4,  11,   4,   4, -16,   3, -18,  46, -45,   7,  -4, 
							 -19, -33,  14,  57,   7, -25, -22, -13,  36,  28, -22,  50, -12,  19,  -4,  15,  23,   0, -13,  32, 
							  25, -60,  44,   8, -35, -15,  34, -49, -21,   7,   1, -27,  45,  -5, -62, -25,  -6,   8, -33,  12, 
							   1, -33,   8,  46,  -3, -29,  20, -12, -40,  -6, -21,  36,  25,   7,  17,  12, -25,   5,   2,  25},
							
							{-34,  37,  21, -25,  -6,  -6, -31,   0,  23,  -9,  23, -23,  -5,  33,   4,  39,   3,  14,  -9,  -3, 
							  40,   5, -16,  -9,  28, -33, -24,  -2, -21,  33, -34,  16, -31, -13,  47,  21,  16,  57,  14, -12, 
							  22, -15,  19,  -2, -29, -31, -48,  20, -21,  13,  -7,  -5, -38,  16, -42, -25, -33,   0,  23, -41, 
							   3,  -4,   0, -23,  14, -22, -28,  24, -15, -44,  -5,  17,  16,  16,  25, -14,   3,   1,  -7,   7},
							
							{ -7,  35,  19,  13, -31, -26, -29, -61,  16,  26,   7,  14,  -7,  -6,  33,  39,  16, -50, -21,   5, 
							  11,   7,  24,   5,  13,  -1, -28,  33, -13,  45, -12, -11,  -2,  14,  33, -16,  -5,   2,  52,  -9, 
							 -24,  -5,  -8, -25, -29,  23, -17, -16, -48,  16,  -6, -10,  34,  -6,  -4, -35, -15,  49,  32,  45, 
							  10,  18,  26,   9,  -6, -19, -43, -44,  33,  36,  22, -10,  55,  23,  34,  14,   2,  31, -40,  19},
							
							
						};

		int32_t v_SHAPE_SLICE_19[] = { 20,  4 };
		int32_t i_total_cores = 5;
		int32_t i_no_of_cores2write = sizeof_a(v_WEIGHTS_SLICE_19);
		for(int core_i_ = 0; core_i_ < i_no_of_cores2write; core_i_++)
		{
			AMBS_writeToWTM_Ex (wtm_width, core_i_, SLICE_19, _P2( v_WEIGHTS_SLICE_19[core_i_], v_SHAPE_SLICE_19 ), false, wtm_delay_ );
		}
	}

	{

		uint32_t v_WEIGHTS_SLICE_20[][64] = {
							{ 42, -14,  12,  16, -10,  35,  14, -21,  -2, -11, -14,  -2,  33,  21,  11,   8, -11,   3,  -1,   7, 
							 -11,  18,   0,  24, -34, -20, -13,   1,  -4,   1, -26,   2,  23,  18,  18,  23, -16,  -4,  13, -34, 
							 -17, -31, -17,  -3, -12,  25, -15, -24,  -2,  48,  -6, -12,  23, -31,  -4, -20,  -3,  20,   4,  -6, 
							  -7,   3,   0, -17},
							
							{ 22, -25, -22,  10,  -9,   1,  22, -25,  29,  13,   4, -11, -18,  18,  18, -10,  29,  20,  -3,  25, 
							 -12, -16, -19,  13,  17, -25,   3,  34, -10,  24,   5, -22, -15,   8,  21,  23,   0, -19,  50,  18, 
							  42,   4, -11,   4,   0,  -5,  -6, -46, -18,  31,  19, -24,  49,   4,  22, -42,  21,   7, -19, -13, 
							  25,  37,  13,  34},
							
							{-21, -20,  12,  -7,  15,  18, -26,   4,   0,  -6,  20,  -6, -43,  28,  13,  -3,  17,  -2, -22,  35, 
							 -18,  14, -24,   9,  17,  -8,  -7, -38,  40,  34,  43, -13,  33,  -2,   5,  24,   2,  26,   2, -19, 
							  27, -22,  -4, -24,  10, -25, -25,   8,  27, -30,  -5,  -1,  36,   7,  15,  19,  -9, -31,  37,  -3, 
							  -2, -27,  29, -51},
							
							{ -2, -30,  -9,  -3,  15,  -1, -48,  -5,  17, -30,   6, -42,   4, -22, -12,  17, -35,  17, -12,  15, 
							   4,  15, -20,  32, -28,  18,  24, -26, -38,  15,  32,  22,  -7, -47,  28,  41, -25,  48,   4, -21, 
							  -3,  -4,   5,   2, -47, -33, -18,   1, -10, -17,   7, -15,   1,  35,  20, -33,  -5, -41,  11, -33, 
							 -18,  17, -50, -10},
							
							{-28,  -9,   2,  -1,  40,  -4,  28,   8,   0,   1, -25, -30, -39,  11,  16,  10, -23,  -9, -16,  -3, 
							  -9, -22,  -8,  -5, -40, -28,  10, -19,   0,  37,  24,  -6,  16, -18,  -1, -18,  -2, -19, -19,  -8, 
							 -53,   5,  22,   7, -22,   6,  23, -38,  28,  20,  -4,  14,  17, -20,   5,  23, -39, -18, -40,  13, 
							  15,  12, -11,  20},
							
							
						};

		int32_t v_SHAPE_SLICE_20[] = { 16,  4 };
		int32_t i_total_cores = 5;
		int32_t i_no_of_cores2write = sizeof_a(v_WEIGHTS_SLICE_20);
		for(int core_i_ = 0; core_i_ < i_no_of_cores2write; core_i_++)
		{
			AMBS_writeToWTM_Ex (wtm_width, core_i_, SLICE_20, _P2( v_WEIGHTS_SLICE_20[core_i_], v_SHAPE_SLICE_20 ), false, wtm_delay_ );
		}
	}

	{

		uint32_t v_WEIGHTS_SLICE_21[][80] = {
							{-27,  66,  -8, -28, -22,   3,  28,  49,   8,  -4,  30,   1, -49,   1, -39,   1, -15,  41,  13,  -7, 
							  15, -16,  -7,  11, -12,  49,  -5,   8, -16,  27, -21,  22,   5, -30,  33, -25,  13, -12,   0, -46, 
							  24,  -5, -34,  -4,   1,  23,  -4,  23,  17,   6, -17, -21, -18,   0, -16,  13,   2, -12,  46, -58, 
							 -25, -16,  49,  -6, -11, -29,  25,  29,  -3,  23,  16,  19,  32, -67,  56, -36,  20, -20,  -5, -20},
							
							{ 14, -48, -47,  26,  13, -39, -28,  -5, -47, -13, -12,  33,  -9,  50,  22, -21,   8,  11, -13,  -4, 
							 -25,  30,  20,  24,  22,  13, -27,  -4, -23, -26,   4, -14, -60,  -1,  31, -18, -59, -18, -34,  29, 
							 -20,  23,  23,  15,   6, -43, -55, -16,  -5, -22,   4,  11, -24, -32,  12, -35,  19, -55, -22,  29, 
							 -32,  -8, -53,  39, -16,  26,  44,   1,  55, -20,   1,  -5, -27,  -5, -57,  18, -26,  34,  -7,  30},
							
							{-15,  -4, -63,  31,  39,   0,  26,  -5,   1, -13, -22,   9, -35, -39,  26, -16, -13,  49,  15, -18, 
							 -17,  -1,  -9,  17,   0, -36,  50,   5,  13,   3, -48,  36,   9,   6,  18,  25,   9,  26, -46,   4, 
							  31,  -3,  -7,  12,  -2, -11, -20, -17,   8,  13, -17, -64, -12, -16,  24, -25,  53,  23, -36,  22, 
							  35,  14, -29,  38, -31,  -7,  35,  -3,  26,  42,   2, -61,  47,  26,   9, -24,  40,  38, -20,  -3},
							
							{  5,  19,   7,  12,  19, -12, -33,  -3, -13, -38,   4,  15,  29,  28, -82, -43, -38,  34,   2,  37, 
							  17, -42,  -5,   9,  -8, -26, -12,  16,   3,  36,  14,   3,  37,  21,  -1,   1,   5,  21,  64,  -6, 
							   4,   3,  14,  15,  17,  14,  16,  13,   6, -11, -25,  -6,  11,   7, -46,  -2, -25,   8,  29,  20, 
							 -48,  -7,  43,  10, -67,   1,  11, -46,   2,  -5,  12,  -9,  14,   0,  25, -24,   9, -21,  15,  15},
							
							{ -7,  12,  -4, -32,  24,   6,  47,  26,  -8, -10,  24,  39,  -6, -48, -70,  18,  38,  18,  20,  23, 
							 -12, -34, -40,  26, -18,  -6,  10, -24, -29,  -9,   1,  -8, -28,   4,  -8, -14,  10,  12,  37,  15, 
							  31, -11,  22,  24, -26,  43,  13,  -7, -37, -48, -21, -18,  -2,   5,  -6,  13, -30,  15,  43,  25, 
							 -27,  44,  55,  35, -10, -34, -21,  21,  50,  31,  34,  38,   3, -37, -12,  29,  -5, -18, -15, -13},
							
							
						};

		int32_t v_SHAPE_SLICE_21[] = { 20,  4 };
		int32_t i_total_cores = 5;
		int32_t i_no_of_cores2write = sizeof_a(v_WEIGHTS_SLICE_21);
		for(int core_i_ = 0; core_i_ < i_no_of_cores2write; core_i_++)
		{
			AMBS_writeToWTM_Ex (wtm_width, core_i_, SLICE_21, _P2( v_WEIGHTS_SLICE_21[core_i_], v_SHAPE_SLICE_21 ), false, wtm_delay_ );
		}
	}

	//! Write WTM data...LAYER: 2
	//! FUNCTION SIGNATURE:
	//! int AMBS_writeToWTM_Ex(int WTM_WIDTH, int CORE, int SLICE, const uint32_t* v_data, const int data_size, int* v_Shape, int shape_size);
	{

		uint32_t v_WEIGHTS_SLICE_22[][80] = {
							{ 12, -19, -17, -13,  20,  29, -22,  -2,   0,   7,  -3,  -8,  20,  22, -16,  10,  25,  32, -35,  -3, 
							  41,  54,  12,  19,  32,  42,   8,  50,  10, -43,  22, -36,   9,  14, -17,  11, -14,   1,   3, -35, 
							  26,  27, -22,  26, -18, -22,  -4, -27, -39, -29,   8, -17, -32, -19,  10, -40, -13, -27, -12, -14, 
							 -22, -13,  23, -37,  -8,  25, -12,  54, -13,  -8, -47,  -4, -34,  -9,  11, -22,  -4,  19, -13, -42},
							
							{-34, -13,  30, -24, -29,   9,  -2, -15,  11,  -3,   0,  17,  -9,  11,   9, -30, -43,   9, -12,  24, 
							  19,  17, -12,  19,  27,  12,  19,  14,   6,  -4, -14, -66,   4,   5, -20,  12,  12, -18, -26, -27, 
							  -1,   8,  -4,  37,   6,  -6,  21, -27,  23, -19,  -1,  -5,   3, -11, -13,   6,  -8, -14,   0, -42, 
							  -6,   0, -12,  -5,  10,  10,   5,  35,   7,  -8,  -2,  12,  -5,  -2,  -9, -16,  14,  -3,  -8, -14},
							
							{ 25, -13,  -5, -15,  19,  20,  26,   6,  26,   5,  -8,  -2,  -3,   4,  20,  -3,  12,  34,  30,   1, 
							  36,  36,  54,  27,  28,  33,  22,   1,  10,  22, -11, -15,  13,  18,   4, -13, -13, -36, -25, -23, 
							  21,  28,  49,  14,  -3, -24, -24,   6,  -2, -29, -46,  15, -32, -32, -31, -19, -30, -26, -18, -19, 
							  15,   7,   0, -51, -20,   4,  -5,   5,   0, -15, -26, -11,  -3,  -2,  -1,  14,  -7,  -6, -11,  -7},
							
							{-12,   7,  40,  19,  14,  19,  45, -19,  16,  10,   5,  -5,  15,  14,  29,  32,  25,  21,  35, -14, 
							  50,  15,  10,   4,  23,  15,   8, -44,   2,  -2,  32,   8,   7,   2,  23,  14, -24, -17,   2,   1, 
							  25,  21,  32,   2, -28, -16, -16,   5, -40, -23,  -7, -33, -31, -24, -21,  -1,  -8, -19, -12,  -1, 
							 -26, -24, -15,   4,  -5,  -9,   3,  -8, -17,  -5, -15, -26,   2,   0,  20,   3,  -1,  -1,   3,  42},
							
							{-22,   6, -27,  10,  18,   5,  23,  36,  11,   6,   3,   7,  17,  12,  27,  28,  42,   8,  21,  21, 
							  74,  21,  32,  50,  24,  12,  25,  45, -19, -44,  -1, -28,  16,   4,   6,   7, -31,  -5, -20, -44, 
							  20,  39,  20,  20, -20, -21,  -6,   2, -42, -15, -40, -18, -47, -22, -36, -32, -18,  -7, -25,  -6, 
							 -30, -17,  -5, -37, -10,  20,  -1, -22, -24,   3, -12, -11, -17,  -8, -26,  -5,  -7,  -1,   1,  12},
							
							
						};

		int32_t v_SHAPE_SLICE_22[] = { 20,  4 };
		int32_t i_total_cores = 5;
		int32_t i_no_of_cores2write = sizeof_a(v_WEIGHTS_SLICE_22);
		for(int core_i_ = 0; core_i_ < i_no_of_cores2write; core_i_++)
		{
			AMBS_writeToWTM_Ex (wtm_width, core_i_, SLICE_22, _P2( v_WEIGHTS_SLICE_22[core_i_], v_SHAPE_SLICE_22 ), false, wtm_delay_ );
		}
	}

	{

		uint32_t v_WEIGHTS_SLICE_23[][80] = {
							{  5,  49,  13,  38,   5, -45,   5, -21,  34,  61, -20,  63,  36,  16,  13,  62,  25,  49,  -3,  75, 
							  10,   2, -26,  54,  65,  79,   2,  67,  -1, -59,  14, -47, -55, -52,  19, -69, -13, -10, -19,  11, 
							  16,  24, -21,  25, -10, -28,   6, -54,  -1,  17, -15,  11,  42, -16,  13,  37,  22,  -1,   0,  11, 
							  14,  39,  20,  22, -22,  25,  -1,  11, -28,  18,  30,   0, -17, -15,   5,  10, -24, -30,  15, -29},
							
							{  -7,   82,  -24,   14,  -19,  -60,   21,   35,   14,   27,   16,  -30,  -33,   32,  -22,   -5, 
							   -5,   23,  -12,   36,  -10,   70,   -9,   27,   36,   39,   16,  -30,  -10,  -27,  -10,   55, 
							    1,  -39,   -4,  -52,    4,  -55,  -26,   -7,  -34,  106,  -16,   -1,    1,  -58,  -15,  -19, 
							  -19,   49,   14,   24,  -26,   50,   21,    3,  -23,   63,    9,   46,    6,   19,   40,   47, 
							  -35,   77,  -17,    0,   22,  -87,   20,   -6,  -12,   57,    3,   17,   10, -127,  -18,   -8},
							
							{  15,   18,   12,   27,  -31,  -58,  -48,  -14,   33,   40,   16,   53,  -18,   68,   11,   24, 
							   14,   34,   45,   22,   -2,   46,   24,  -17,   33,  106,   56,   40,   28,  -23,  -23,   31, 
							  -36,  -62,  -38,  -25,   -6,  -45,    2,   10,   -4,   24,  -15,   10,  -28,  -50,  -20,   18, 
							  -21,   57,  -11,  -20,  -35,   26,   24,  -25,   22,   77,   38,   -2,   37,   37,   29,    9, 
							  -17,   36,   38,  -14,    6,  -26,  -17,   33,  -23,    0,    8,   18,   37,  -54,  -43,   21},
							
							{ 47,  71,  15,  15, -51, -62, -37,   5,   7,  28,  26, -10,  33,  51,  20,  13,  43,  26,  18, -10, 
							  12,  18,  -1,  -4,  59,  46,  42,   5, -34,   0,  -4,  22, -66, -26,   2, -42, -23, -71,   2,  -4, 
							  39,  71,  51,  -7, -46, -64, -25,  16,  42,  39,   5,  13, -23,  61,  16,  -4,  37,  59,   6,  -4, 
							  43,   4, -10, -15,  72,  30,  17,  -5, -30, -33, -20,   0,  27,  14,  -5,  22, -48, -76,  -8,   2},
							
							{  66,   -7,   84,   53,  -47,  -12,  -32,  -22,    5,   33,   25,   25,   39,    8,   40,   38, 
							   42,   24,   22,   26,  -19,  -27,   25,   -9,   85,   24,   50,   46,  -50,    6,  -14,    2, 
							  -35,    3,  -69,   -4,  -39,   21, -111,   18,   52,    7,   57,   -8,  -58,   -8,  -43,  -47, 
							   38,    2,   49,   18,    0,   19,   54,   17,   67,   10,   64,   54,   25,   38,    5,   39, 
							  -16,   19,   70,   42,  -66,   23,  -74,   -8,    8,   -3,   80,  -18,  -72,  -28, -104,    1},
							
							
						};

		int32_t v_SHAPE_SLICE_23[] = { 20,  4 };
		int32_t i_total_cores = 5;
		int32_t i_no_of_cores2write = sizeof_a(v_WEIGHTS_SLICE_23);
		for(int core_i_ = 0; core_i_ < i_no_of_cores2write; core_i_++)
		{
			AMBS_writeToWTM_Ex (wtm_width, core_i_, SLICE_23, _P2( v_WEIGHTS_SLICE_23[core_i_], v_SHAPE_SLICE_23 ), false, wtm_delay_ );
		}
	}

	{

		uint32_t v_WEIGHTS_SLICE_24[][80] = {
							{ 18,  15,  21,  41, -71, -35,  -3, -17,  -4,  29, -12, -21, -44, -25,   7, -10, -22, -18, -44, -25, 
							 -32,  15, -83, -67, -27, -22, -10, -41,  27,  18,  25,  26,  -9,  47,  -2,   0,  -8,  52, -21,  28, 
							 -44,  -1, -69, -68,  18,  32,  60,  29,  22,  13,   3,  15,  13, -20,  32,  65,  17,  30,  35,  27, 
							  -2,  -1,  -1,  44,  17, -18, -35, -13, -12,  48,   0,  37, -24,  53,  -7,   1, -23,  21,  23,  35},
							
							{ 25, -41,  49,  16, -11,  52, -34, -37,  17,  -4,  49,  39,   7,  18,  -3,  33,   7,  43, -24, -20, 
							 -10,  47, -19, -30, -10,  44,   3,  -7, -19, -46,   9, -15,   8, -19,   0,   1,  52, -38, -24,  23, 
							 -61,  39,  11, -54,   7, -23,  14,  17, -15, -11,  21,   2,  -3, -17,  -6,  12,  41, -12,   5,  -7, 
							 -26, -11,  -6,  38,   9,  31, -25, -35,  51, -29,  10,  61,  62, -55,   2,  37,  16,  -6,  20,  46},
							
							{ -6,  11, -46,  32, -26, -44,  68, -28, -34,  26, -36, -29, -21, -20,  30,   3,  11, -37,  68, -26, 
							  25,  -2,  78, -78,  58, -18,  55, -17, -10,  45, -18,  12,  16,  38,   9,  36, -17,  31, -40,  -2, 
							  26, -45,  54, -12,  17,  -6, -43,  14,   2,  32, -69,   9, -32,  28, -10,  37, -53,  24,  -6,  22, 
							 -31, -40, -17,  14,  26,   4, -15, -20, -76,  26, -55,   8, -37,   9,   8,  -5, -26,  20,  -4,  29},
							
							{-47,  23,  17,  54,  43, -26,   0, -11,   5,  46,  43,  40,  -4,   1,  15,  23,  56,  14,  15,  16, 
							  23,  12, -13, -18,  53,  -5, -45, -32,   6,  33,  51,  61, -17,   3,  27,  60, -64, -10,   3,  42, 
							  60, -16,   5, -19, -23, -23, -14,  15,  -3, -34,  13, -20, -26, -50,  26,  27, -11, -13,  39,  15, 
							 -25,  -5,  -1,  50,  14, -18,  -7, -48,   1,  44,  44,  12,  -7,  38,  36,  -5,  -5,  32,  16,  41},
							
							{ -1,  -4, -38,  18, -15, -51,  31, -52, -15,   8, -16,  30,   2, -39,  20,  13, -35,  -8,  20, -40, 
							 -48,   3,  18, -90,   7,   5,  31, -57, -19,  -7, -21, -25,   7,  -1,  14,  14,   6,   9, -34,  46, 
							 -11, -27, -13, -30,  40,   0,   8,  29,   7,  55,  -7,  20,  44,  35, -28,  39,   7,  35,  33,   1, 
							   9, -26, -15,   3, -26, -10,  22,  23,  15,  29, -52,  56,  39,  23, -32,  56,  15,  -3,   9,  10},
							
							
						};

		int32_t v_SHAPE_SLICE_24[] = { 20,  4 };
		int32_t i_total_cores = 5;
		int32_t i_no_of_cores2write = sizeof_a(v_WEIGHTS_SLICE_24);
		for(int core_i_ = 0; core_i_ < i_no_of_cores2write; core_i_++)
		{
			AMBS_writeToWTM_Ex (wtm_width, core_i_, SLICE_24, _P2( v_WEIGHTS_SLICE_24[core_i_], v_SHAPE_SLICE_24 ), false, wtm_delay_ );
		}
	}

	{

		uint32_t v_WEIGHTS_SLICE_25[][80] = {
							{ -9, -26, -42, -59,   9,  21,  86,  20,  -6, -32, -23, -36, -53, -21, -18, -47, -25,  -6, -15, -15, 
							  -8,  -8, -16, -18, -13,   0, -31, -59,  36,  45, -16,  34,  20,  15,  52,  41,  -1,   0,  28,   0, 
							 -14, -14, -76, -33,  -3,  10,  57,  53, -11, -27, -65, -53, -60, -57, -54, -14, -25,  -7, -91, -54, 
							 -12, -25, -29, -22,  17, -38, -41, -22, -11,  -8,  29,  30, -16,   5, -68, -52,  12,  30,  98,  41},
							
							{-41,  14, -65,  18,  20, -26,  21,  22,   1,  24, -26,  -3,   3,  20, -15,  25,   3, -14, -24, -24, 
							 -45,   9, -21,  -4,   2,   1, -35,  -5, -23, -35,  16, -13,  19,  -1,   5,  -9,  18, -22,  21,  16, 
							 -43,  37, -19, -22, -26, -19,  52,  32,  -3,  -4,  -5, -30, -15,  24,  -2, -20, -46,  17, -28, -23, 
							 -41, -13,   4,  12, -22,  43, -23,   0,   0,  27,   9, -15,  -2,  20, -47, -23,  71, -30,  58, -14},
							
							{  8, -16,  12, -37, -33,  -1,  14,  56,  70, -22,  -7, -28,  36, -19,   3, -60,  34,   5,  56, -31, 
							   0,   7,   3, -76,  45,  38,  16, -38, -29,   9,  -4,  35,  19,  16,  -8,  34,  11,  -2,  13,  26, 
							 -17, -38,  10, -32, -15,   2,  -7,   4,  16,   2,  13, -46,   5,  -7,  -2, -60, -14, -17,  15, -19, 
							  55, -16,  19,   7, -10,  -1,   9, -49,   1, -14,  15,  20, -27, -19,   9, -45, -17, -11,   1,  36},
							
							{  7,  15,  13, -41, -12,  37,  -3,  21,  26, -17,   2,  -9,  13, -37,  -8, -39,  12,  -3,  -4, -10, 
							  44, -31,  15,  -1,  13, -24,  15,  16,  -6,  -8,   1,  14,  -2,   7,  11,  38, -10,  26,  30,  53, 
							  16, -50,   1, -12,   0,  28,  31,   7,  18, -18,  -4,   3,   2,   1,  -4,   7,  13, -34,  -8, -14, 
							  13,  16,  -9,   5,   8, -36,  -6,  -8,  -5,   8,  -6, -28,   8, -13,  -8, -19, -36,  -2,  10,  49},
							
							{-19, -15,  37,   4,  30,  15, -50,  -2, -18, -36,  23,  19, -59, -29,  63,  14, -31, -12,  -3,  20, 
							 -54, -14,  35,  -5, -27, -31,  10,   1, -21,   0,  -1,   2,  15,  56,  19,   5,  62,  -6, -39, -31, 
							 -20, -16,  12, -12,  44,  16, -74,  35, -57, -36,  42, -38, -15, -23,  17, -13, -13, -19,   1,  -8, 
							  13,  24,   6,   7, -63, -18,  33,   0,  17,  36, -15,  12, -51,  -5,  -5, -17,  39,  45, -29,  -9},
							
							
						};

		int32_t v_SHAPE_SLICE_25[] = { 20,  4 };
		int32_t i_total_cores = 5;
		int32_t i_no_of_cores2write = sizeof_a(v_WEIGHTS_SLICE_25);
		for(int core_i_ = 0; core_i_ < i_no_of_cores2write; core_i_++)
		{
			AMBS_writeToWTM_Ex (wtm_width, core_i_, SLICE_25, _P2( v_WEIGHTS_SLICE_25[core_i_], v_SHAPE_SLICE_25 ), false, wtm_delay_ );
		}
	}

	{

		uint32_t v_WEIGHTS_SLICE_26[][80] = {
							{-17,  11, -19, -10,   4,   3,  -2,   3,   2,  13,  -8,   4,  12, -16, -27, -12,  -3,   2, -11,   2, 
							  14, -34,  42,  44,   4, -10,  18,  22,  -5,  36,  23,   5,  -4,   1, -21,  10,  -5,  16,  -5, -21, 
							  -4,  -9,  19,   7,  14,  -8, -24,   8,  -8,  -2,   6,   4,  -2,  25, -24, -11,   3, -18,   1,   3, 
							  12,  -4, -21,   1,  15,  10,  -2,  20,   0, -11, -24, -37,  10,  17,   6,  -4,  -6,  17,  -4, -34},
							
							{-22, -18,  21,  11,   9,   7,   3,  24,   7,  -2,  24,  24, -25,   7, -28,  -8,   4,   8, -11,  16, 
							  19,  11,  40,  -2,  19,   5,   2, -25, -25, -15,   5,   2,   3,   0,  -5,  14,   7,  -5,  27,  13, 
							  19,   9,  18,  -4,  -8,  -6,  34,   0,  -8, -12, -16,   7,  -3,  -9, -13, -11,   4, -10,   8, -10, 
							 -20,   5,  15,  14,   4,   7,  18,  -5,   6,  -6, -19,  17,  15,  -3,   0,   8, -20,  -4,  27,  -5},
							
							{ 25,  18, -26,  22,  -1, -24,   5,  -4,   1,  -2,  -7,  12,  16,  -8, -19,  15,   0,  -2,  15, -12, 
							 -21, -32,  20, -38, -15, -13,  14,  -4,  29,  10,   7,   1, -17,   3, -12,  -3,  10,  19,  -1, -11, 
							  -2,  -6,  10,   5,  -3,   3,   2,  23,  -1,  18,  -6,  -4,  17,  20, -14,  26, -10,  -4,   4, -27, 
							   2,   1,  -4,  10,  -3, -25,  15,  21,   8,  12,  -1,  18,  21,  13,  -1,  13,  14,  12, -20,   0},
							
							{-25,  16,  13, -28,  10,   2,  23, -10,  -1,  -5,  -2,  50,   0,  13,  12,  -6,  19,   9,  25,  16, 
							  31,   9,   2,  14,  18,   7,   2, -19,  -8,   2, -19, -16,  -3,   2,   3,   0, -11,   4,   9,  18, 
							  16,   2,  -8,  35,  -8,  -3,   0,  -7, -10,  -6,  -6,   2, -16, -14,   0,  18,   4,   5,  14,   1, 
							   0,  26,  14,  33,  -8, -20, -20, -22, -12,   2,  26, -11,  -9, -13,  -5,  -7, -11,   1,  -6,  41},
							
							{-17,  19,  -1,   7,  -4,  -4,  11, -23,   0,  32,  -8, -11, -25,  18,   6,  -3,  28,  -6,   9, -23, 
							  25, -12,  29, -30,  28, -10,  13,  -9,  -3,  34, -14,  25, -14,   6,   4,  11, -12,  12,   4,  23, 
							   2,   4,  14, -10,   3,  -7, -11, -17, -21,   7, -14,  17, -32,  14,  -3,  10,   7, -10, -11,  -7, 
							  -7,   7, -10,   4,   2,  -2, -13,  10,  -3,   2, -10,   0, -31,  18,   5,   7, -25,  15, -18,  15},
							
							
						};

		int32_t v_SHAPE_SLICE_26[] = { 20,  4 };
		int32_t i_total_cores = 5;
		int32_t i_no_of_cores2write = sizeof_a(v_WEIGHTS_SLICE_26);
		for(int core_i_ = 0; core_i_ < i_no_of_cores2write; core_i_++)
		{
			AMBS_writeToWTM_Ex (wtm_width, core_i_, SLICE_26, _P2( v_WEIGHTS_SLICE_26[core_i_], v_SHAPE_SLICE_26 ), false, wtm_delay_ );
		}
	}

	{

		uint32_t v_WEIGHTS_SLICE_27[][80] = {
							{  6,  -4,  -5,  -2,  -9, -29,  18, -11,  37, -22,   7,  33,  29, -12,  25,   1,  19,  20,   0,  -8, 
							 -27,  18, -13,  35,   1, -21,  17,  -7, -23,  15, -17,  -6,  23, -46,  25,  39,   6,  39, -11,   0, 
							 -47,  -5,  -2, -16, -60,  30,  -9, -35, -43,  12,  -3,   3,  -9, -30,   3,  23, -22, -16,  60,  31, 
							  14,  27,  18,  -2, -18, -39,  23,  11,  -5,  12,  24,   2, -24, -14,   4,  19, -45,  22, -32,   4},
							
							{-23,  12, -11,   8,   8,   5,  29, -10,  -1,  52,  20,  -8,  26,  38,   5, -30,  17,  54,  16, -14, 
							   4, -76,  -6,  27,   7,  28, -22,  -3,  -4, -23, -13, -12, -23,   2,  -1,  -7,   0,   0, -12,  12, 
							  24, -49,  -3,  65, -38, -54, -16, -10, -49, -14,  48,   7, -10,  22,  14,   1,  18,  35,   5, -14, 
							  24,   9,  33,  20,  -5,  16,  12,  -4,   4, -19,  18,  15, -13, -47, -48,  24, -23, -55,  15,   6},
							
							{ 19, -38,  47, -12,  16,  15, -14, -12, -26, -32,  28,  13,   9, -29,  22,  -7, -13,   7,  11,  -8, 
							  23, -28, -26,  19, -26, -12,  49,  -4,  -8,   6, -34, -30, -24,  -1,  39, -87, -40, -34,  -7,  -7, 
							  13,  21, -81, -13,   4,  15,  -1,  -4, -46,   2, -19, -22,  15, -24,  54, -44,  21, -20,  28, -20, 
							  -3, -12,  17, -21, -16, -23,   9, -10,  29,   3,  -7,  -2, -36,  23, -30,  14,   0,  39, -35,  28},
							
							{ 47,  32,   4, -18, -18,   3, -12,   8,  12,  12,   7,  20,  12,  23,  25,  -2,  30,  29, -25,  23, 
							  20,  -2,   0,   1,  34, -21,  -7, -41,  -9,   8,  -2,  12,  25,  20,  84,  33,  12, -21, -24,   9, 
							 -14, -19, -41,   3, -14, -24, -12,   8, -30, -41,  -9,  36,  22, -26,  -3,   1,  24,   7, -28,  27, 
							 -21, -12, -19, -20,  14,  -7,  17,  20, -13, -35, -10,  -7,  -2, -12,  28,  -6, -20, -33,  11,   0},
							
							{ -2, -13,   2,  12,  -4,  -1,   1,  -3,  48, -14,  41, -47,   6, -14,  18, -44,  16, -38,  34,   7, 
							 -16,  26,  18,   8,  -9, -24,  43,  34,   2,  45, -30,  25,  44, -41,  11, -50, -12,   6, -14,   3, 
							 -12,  12, -40,  38, -14,   7, -55,   6,  -2,  33,   6,  30,  21,   0,  38,  14,  -1,  -5,  11, -60, 
							 -12,  -6,  12,  13,  28, -37,  17, -31,  23,  11, -26,  16,   5,  44, -61,  32, -12,   3,  -8,   5},
							
							
						};

		int32_t v_SHAPE_SLICE_27[] = { 20,  4 };
		int32_t i_total_cores = 5;
		int32_t i_no_of_cores2write = sizeof_a(v_WEIGHTS_SLICE_27);
		for(int core_i_ = 0; core_i_ < i_no_of_cores2write; core_i_++)
		{
			AMBS_writeToWTM_Ex (wtm_width, core_i_, SLICE_27, _P2( v_WEIGHTS_SLICE_27[core_i_], v_SHAPE_SLICE_27 ), false, wtm_delay_ );
		}
	}

	//! Write WTM data...LAYER: 3
	//! FUNCTION SIGNATURE:
	//! int AMBS_writeToWTM_Ex(int WTM_WIDTH, int CORE, int SLICE, const uint32_t* v_data, const int data_size, int* v_Shape, int shape_size);
					/**

						{{ 40, -16,  25,  29},
						 {-17,   1,  -3, -23},
						 {  1,   0,  -1,  -1},
						 { -4,   3, -30,  24},
						 { -1,   1,  -2,   1},
						 { 70,   5,   8,  41},
						 {  0,   0,   0,   1},
						 { -1,   1,   3,  -5},
						 { -2,   4,   7,   2},
						 {-63, -38, -19, -71},
						 {  6,  49,  24,  56},
						 { -3,   0, -10,   7},
						 { 48,  65,  61,  47},
						 { 22,  70,  20,  67},
						 {  6, -18,  10,  23},
						 {  0,   2,  -2,   1},
						 {-11,  11,  40,  13},
						 {-10, -20,  18,  14},
						 { 69,  63,   9,  73},
						 { 16, -13,  -7, -29}}
					***/
	{

		uint32_t       v_WEIGHTS[] =	
						{0x28, 0xfffffff0, 0x19, 0x1d, 0xffffffef, 0x1, 0xfffffffd, 0xffffffe9, 
						 0x1,   0, 0xffffffff, 0xffffffff, 0xfffffffc, 0x3, 0xffffffe2, 0x18, 
						 0xffffffff, 0x1, 0xfffffffe, 0x1, 0x46, 0x5, 0x8, 0x29, 
						   0,   0,   0, 0x1, 0xffffffff, 0x1, 0x3, 0xfffffffb, 
						 0xfffffffe, 0x4, 0x7, 0x2, 0xffffffc1, 0xffffffda, 0xffffffed, 0xffffffb9, 
						 0x6, 0x31, 0x18, 0x38, 0xfffffffd,   0, 0xfffffff6, 0x7, 
						 0x30, 0x41, 0x3d, 0x2f, 0x16, 0x46, 0x14, 0x43, 
						 0x6, 0xffffffee, 0xa, 0x17,   0, 0x2, 0xfffffffe, 0x1, 
						 0xfffffff5, 0xb, 0x28, 0xd, 0xfffffff6, 0xffffffec, 0x12, 0xe, 
						 0x45, 0x3f, 0x9, 0x49, 0x10, 0xfffffff3, 0xfffffff9, 0xffffffe3};

		uint32_t         v_SHAPE[] =	{ 20,4,};
		AMBS_writeToWTM_Ex (wtm_width, CORE_00, SLICE_28, _P2( v_WEIGHTS, v_SHAPE ), false, wtm_delay_ );
	}

					/**

						{{-53,  39,  18,  44},
						 { 11, -10, -35,  16},
						 {  0,   1,  -1,   1},
						 {  7,  -6,   5,   6},
						 {  0,   0,   0,   0},
						 {-59,  30,  69,   5},
						 {  0,   0,   1,   1},
						 { -3,   0,  -1,   1},
						 { -1,   9,  -5,  -4},
						 {  7, -47, -74, -14},
						 { -2,   6,  47,  62},
						 {  2,  -3,  -5,   4},
						 {-30,  48,  20,  59},
						 {-68,  62,  30,  59},
						 { 17, -17,  15,  21},
						 { -1,   1,   0,  -2},
						 {-50,  39,  -1,   8},
						 { 17,  -5,  -8, -21},
						 {-67,  34,  47,  65},
						 { 38, -17, -19, -33}}
					***/
	{

		uint32_t       v_WEIGHTS[] =	
						{0xffffffcb, 0x27, 0x12, 0x2c, 0xb, 0xfffffff6, 0xffffffdd, 0x10, 
						   0, 0x1, 0xffffffff, 0x1, 0x7, 0xfffffffa, 0x5, 0x6, 
						   0,   0,   0,   0, 0xffffffc5, 0x1e, 0x45, 0x5, 
						   0,   0, 0x1, 0x1, 0xfffffffd,   0, 0xffffffff, 0x1, 
						 0xffffffff, 0x9, 0xfffffffb, 0xfffffffc, 0x7, 0xffffffd1, 0xffffffb6, 0xfffffff2, 
						 0xfffffffe, 0x6, 0x2f, 0x3e, 0x2, 0xfffffffd, 0xfffffffb, 0x4, 
						 0xffffffe2, 0x30, 0x14, 0x3b, 0xffffffbc, 0x3e, 0x1e, 0x3b, 
						 0x11, 0xffffffef, 0xf, 0x15, 0xffffffff, 0x1,   0, 0xfffffffe, 
						 0xffffffce, 0x27, 0xffffffff, 0x8, 0x11, 0xfffffffb, 0xfffffff8, 0xffffffeb, 
						 0xffffffbd, 0x22, 0x2f, 0x41, 0x26, 0xffffffef, 0xffffffed, 0xffffffdf};

		uint32_t         v_SHAPE[] =	{ 20,4,};
		AMBS_writeToWTM_Ex (wtm_width, CORE_01, SLICE_28, _P2( v_WEIGHTS, v_SHAPE ), false, wtm_delay_ );
	}

					/**

						{{-42,  12,  10,  63},
						 { -6,  11,  -4, -27},
						 {  0,   3,   1,   1},
						 {-22,   9,  11, -15},
						 { -1,   1,   0,  -1},
						 {-59,  25,  54,  55},
						 {  0,   0,   0,   2},
						 {  3,  -4,  -1,  -9},
						 {  7,  -4,   9,  15},
						 {  4, -30, -51, -55},
						 {-41,  18,  47,  23},
						 { -4,  -7,   4,   1},
						 {-47,  65,  31,   4},
						 {-44,  12,  74,  21},
						 {-12,  -1,   0,   2},
						 { -1,   1,   0,   1},
						 {-26,  56,   6,  38},
						 { 14,   4, -20,   7},
						 {-55,  56,  34,  36},
						 {-34, -42, -11, -16}}
					***/
	{

		uint32_t       v_WEIGHTS[] =	
						{0xffffffd6, 0xc, 0xa, 0x3f, 0xfffffffa, 0xb, 0xfffffffc, 0xffffffe5, 
						   0, 0x3, 0x1, 0x1, 0xffffffea, 0x9, 0xb, 0xfffffff1, 
						 0xffffffff, 0x1,   0, 0xffffffff, 0xffffffc5, 0x19, 0x36, 0x37, 
						   0,   0,   0, 0x2, 0x3, 0xfffffffc, 0xffffffff, 0xfffffff7, 
						 0x7, 0xfffffffc, 0x9, 0xf, 0x4, 0xffffffe2, 0xffffffcd, 0xffffffc9, 
						 0xffffffd7, 0x12, 0x2f, 0x17, 0xfffffffc, 0xfffffff9, 0x4, 0x1, 
						 0xffffffd1, 0x41, 0x1f, 0x4, 0xffffffd4, 0xc, 0x4a, 0x15, 
						 0xfffffff4, 0xffffffff,   0, 0x2, 0xffffffff, 0x1,   0, 0x1, 
						 0xffffffe6, 0x38, 0x6, 0x26, 0xe, 0x4, 0xffffffec, 0x7, 
						 0xffffffc9, 0x38, 0x22, 0x24, 0xffffffde, 0xffffffd6, 0xfffffff5, 0xfffffff0};

		uint32_t         v_SHAPE[] =	{ 20,4,};
		AMBS_writeToWTM_Ex (wtm_width, CORE_02, SLICE_28, _P2( v_WEIGHTS, v_SHAPE ), false, wtm_delay_ );
	}

					/**

						{{-44,  -1, -47, -25},
						 { 35, -16,  10,  16},
						 {  1,  -1,   1,   0},
						 {  1,   3,   0,  -6},
						 {  1,   0,   0,   0},
						 { -6,  63, -63, -58},
						 {  0,   0,  -1,   0},
						 { -4,   1,   4,  -4},
						 { -3,   6,  -3,  -5},
						 { 33, -65,   1,  29},
						 {  1,  18, -30, -44},
						 { -2,  -6,   1,  -2},
						 {-15,  95, -69, -21},
						 {-29,  46, -65, -71},
						 {-10, -19,  15,  10},
						 { -3,   1,  -1,  -1},
						 {-38,   6, -25, -32},
						 { 22,   0,   7,   6},
						 {-36,  64, -13, -52},
						 { 22, -38,  14,  26}}
					***/
	{

		uint32_t       v_WEIGHTS[] =	
						{0xffffffd4, 0xffffffff, 0xffffffd1, 0xffffffe7, 0x23, 0xfffffff0, 0xa, 0x10, 
						 0x1, 0xffffffff, 0x1,   0, 0x1, 0x3,   0, 0xfffffffa, 
						 0x1,   0,   0,   0, 0xfffffffa, 0x3f, 0xffffffc1, 0xffffffc6, 
						   0,   0, 0xffffffff,   0, 0xfffffffc, 0x1, 0x4, 0xfffffffc, 
						 0xfffffffd, 0x6, 0xfffffffd, 0xfffffffb, 0x21, 0xffffffbf, 0x1, 0x1d, 
						 0x1, 0x12, 0xffffffe2, 0xffffffd4, 0xfffffffe, 0xfffffffa, 0x1, 0xfffffffe, 
						 0xfffffff1, 0x5f, 0xffffffbb, 0xffffffeb, 0xffffffe3, 0x2e, 0xffffffbf, 0xffffffb9, 
						 0xfffffff6, 0xffffffed, 0xf, 0xa, 0xfffffffd, 0x1, 0xffffffff, 0xffffffff, 
						 0xffffffda, 0x6, 0xffffffe7, 0xffffffe0, 0x16,   0, 0x7, 0x6, 
						 0xffffffdc, 0x40, 0xfffffff3, 0xffffffcc, 0x16, 0xffffffda, 0xe, 0x1a};

		uint32_t         v_SHAPE[] =	{ 20,4,};
		AMBS_writeToWTM_Ex (wtm_width, CORE_03, SLICE_28, _P2( v_WEIGHTS, v_SHAPE ), false, wtm_delay_ );
	}

					/**

						{{-74,  52,  35, -36},
						 { -3,  20, -19,   0},
						 {  1,  -1,   1,   1},
						 {-12,   9,  14,  -1},
						 { -1,   0,   1,  -1},
						 {-53,  15,  14, -67},
						 { -1,   0,   0,   1},
						 { -4, -14,  -2,  -5},
						 { 10,  -5,  -9,  -6},
						 { 44, -30, -49,  48},
						 {-43,  54,  59, -27},
						 {  7,  -9,   6, -10},
						 {-26,  78,  22, -35},
						 {-25,  30,  40, -66},
						 {-29,  31,  36,  -2},
						 { -1,   2,   1,   1},
						 {-68,  13, -25,  -9},
						 {-17, -26,  26,  -7},
						 {-51,   4,  41, -55},
						 { 34,   5,  27,  30}}
					***/
	{

		uint32_t       v_WEIGHTS[] =	
						{0xffffffb6, 0x34, 0x23, 0xffffffdc, 0xfffffffd, 0x14, 0xffffffed,   0, 
						 0x1, 0xffffffff, 0x1, 0x1, 0xfffffff4, 0x9, 0xe, 0xffffffff, 
						 0xffffffff,   0, 0x1, 0xffffffff, 0xffffffcb, 0xf, 0xe, 0xffffffbd, 
						 0xffffffff,   0,   0, 0x1, 0xfffffffc, 0xfffffff2, 0xfffffffe, 0xfffffffb, 
						 0xa, 0xfffffffb, 0xfffffff7, 0xfffffffa, 0x2c, 0xffffffe2, 0xffffffcf, 0x30, 
						 0xffffffd5, 0x36, 0x3b, 0xffffffe5, 0x7, 0xfffffff7, 0x6, 0xfffffff6, 
						 0xffffffe6, 0x4e, 0x16, 0xffffffdd, 0xffffffe7, 0x1e, 0x28, 0xffffffbe, 
						 0xffffffe3, 0x1f, 0x24, 0xfffffffe, 0xffffffff, 0x2, 0x1, 0x1, 
						 0xffffffbc, 0xd, 0xffffffe7, 0xfffffff7, 0xffffffef, 0xffffffe6, 0x1a, 0xfffffff9, 
						 0xffffffcd, 0x4, 0x29, 0xffffffc9, 0x22, 0x5, 0x1b, 0x1e};

		uint32_t         v_SHAPE[] =	{ 20,4,};
		AMBS_writeToWTM_Ex (wtm_width, CORE_04, SLICE_28, _P2( v_WEIGHTS, v_SHAPE ), false, wtm_delay_ );
	}

	//! Write WTM data...LAYER: 4
	//! FUNCTION SIGNATURE:
	//! int AMBS_writeToWTM_Ex(int WTM_WIDTH, int CORE, int SLICE, const uint32_t* v_data, const int data_size, int* v_Shape, int shape_size);
					/**

						{{-5,  0,  0,  0},
						 {-4,  0,  0,  0},
						 {-1,  0,  0,  0},
						 {-2,  0,  0,  0},
						 { 4,  0,  0,  0},
						 {-4,  0,  0,  0},
						 {-5,  0,  0,  0},
						 {-3,  0,  0,  0},
						 { 2,  0,  0,  0},
						 {-2,  0,  0,  0},
						 {-4,  0,  0,  0},
						 { 0,  0,  0,  0},
						 { 1,  0,  0,  0},
						 {-3,  0,  0,  0},
						 { 4,  0,  0,  0},
						 { 2,  0,  0,  0},
						 { 2,  0,  0,  0},
						 { 0,  0,  0,  0},
						 {-4,  0,  0,  0},
						 { 3,  0,  0,  0}}
					***/
	{

		uint32_t       v_WEIGHTS[] =	
						{0xfffffffb,  0,  0,  0, 0xfffffffc,  0,  0,  0, 0xffffffff,  0, 
						  0,  0, 0xfffffffe,  0,  0,  0, 0x4,  0,  0,  0, 
						 0xfffffffc,  0,  0,  0, 0xfffffffb,  0,  0,  0, 0xfffffffd,  0, 
						  0,  0, 0x2,  0,  0,  0, 0xfffffffe,  0,  0,  0, 
						 0xfffffffc,  0,  0,  0,  0,  0,  0,  0, 0x1,  0, 
						  0,  0, 0xfffffffd,  0,  0,  0, 0x4,  0,  0,  0, 
						 0x2,  0,  0,  0, 0x2,  0,  0,  0,  0,  0, 
						  0,  0, 0xfffffffc,  0,  0,  0, 0x3,  0,  0,  0};

		uint32_t         v_SHAPE[] =	{ 20,4,};
		AMBS_writeToWTM_Ex (wtm_width, CORE_00, SLICE_29, _P2( v_WEIGHTS, v_SHAPE ), false, wtm_delay_ );
		AMBS_writeToWTM_Ex (wtm_width, CORE_01, SLICE_29, _P2( v_WEIGHTS, v_SHAPE ), false, wtm_delay_ );
		AMBS_writeToWTM_Ex (wtm_width, CORE_02, SLICE_29, _P2( v_WEIGHTS, v_SHAPE ), false, wtm_delay_ );
		AMBS_writeToWTM_Ex (wtm_width, CORE_03, SLICE_29, _P2( v_WEIGHTS, v_SHAPE ), false, wtm_delay_ );
		AMBS_writeToWTM_Ex (wtm_width, CORE_04, SLICE_29, _P2( v_WEIGHTS, v_SHAPE ), false, wtm_delay_ );
	}

}

	//! CODE-GENERATION SUCCESS!!...
void COMPLEX_MAC_DEMONSTRATION_27_07_2022_15_35_37_()		//! Function Definition
{
	SETUP_AND_INITIALIZE_HW_DEVICE_();
	uint32_t            no_of_cores =	5;
	uint16_t              opm_width =	32;
	uint16_t              wtm_width =	16;
	int32_t              opm_delay_ =	20;
	int32_t                     n2r =	1;	
	int32_t         opm_shift_value =	0;
	uint32_t            inf_det_reg =	26;	
	uint32_t         i_scale_factor =	0;	

	uint32_t width_bits = Get_OPM_WTM_WidthBits(opm_width, wtm_width);
	PROCESS_LIVE_INPUT(width_bits);

}
