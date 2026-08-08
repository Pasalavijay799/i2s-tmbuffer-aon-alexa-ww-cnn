//! Auto Generated on  05_08_2026_11_12_45_.
//! Do Not Modify this file!!
//! ---------------------------------------------------------------------------------------------
//! gpxCLIWrapper Command:
//! 


const uint32_t N_OF_MC_BLOCKS = 7; 

#ifndef USE_COMPILER_MICROCODE
static uint32_t ucode_hex_generic [7][256] =
{
	{
//! BATCH_0:  C:\AmbientScientific\setup\chip\fw\applications\i2s-tmbuffer-aon-alexa-ww-cnn\training_tool_chain\python\temp\GC_05_08_2026_11_12_30\Batch0.hex.gpx
//! HEADER INFORMATION  OR STRUCTURE NAME OR  SECTION INFORMATION
		0x00000000,  //00 NOP
		0xE0000100,  //01 SETBITS sel_oclk rd_addr = 0x00 

		//! ;SETBUFF
		0xD0000080,  //02 SETBUFF outbuff = 8

		//! ;WRIREG_ALL
		0x68000000,  //03 WRREG 16 0x0
		0x68800020,  //04 WRREG 17 0x20
		0x69000000,  //05 WRREG 18 0x0
		0x60000000,  //06 WRREG 0x0 0x0		; o_NEURON
		0x60800001,  //07 WRREG 0x1 0x1		; o_BIAS_NEURON
		0x61000002,  //08 WRREG 0x2 0x2		; o_DENSE_OUT
		0x61800003,  //09 WRREG 0x3 0x3		; o_MATMUL_OUT
		0x62000004,  //0a WRREG 0x4 0x4		; PREG_RESERVED_FOR_S3_ZEROXBAR
		0x62800005,  //0b WRREG 0x5 0x5		; i_BIAS
		0x67800012,  //0c WRREG 0xf 0x12		; o_BIAS_CONV

		//! ;LOOP_ST_2
		0x1D000000,  //0d LOOPST  0x0D

		//! ;WAIT_MAC
		0xE0000400,  //0e SETBITS ld_samples
		0x80113000,  //0f WAIT cc = neurons_valid wr_addr = 0x00 mem_we = both wr_data_sel = neurons

		//! ;ADD_		WRITE 0x0F->0x12 (o_BIAS_CONV), READ 0x05->0x05 (i_BIAS), READ 0x00->0x00 (o_NEURON)
		0x00000005,  //10 NOP rd_addr = 0x05
		0xE0008000,  //11 SETBITS use32 rd_addr = 0x00
		0x000010F5,  //12 NOP rd_addr = 0x05 alu_sel = add wr_addr = 0x0F wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 0
		0x000028F0,  //13 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x0F wr_data_sel = alu mem_we = odd	 in_sel = 1 sign_extend = 0

		//! ;INC_REG
		0x97F00000,  //14 INCREG  0x0F  cc = always
		0x99700000,  //15 INCREG 18 cc = always
		0x99700000,  //16 INCREG 18 cc = always
		0x99700000,  //17 INCREG 18 cc = always
		0x99700000,  //18 INCREG 18 cc = always

		//! ;ZERO_REG_
		0x00000000,  //19 NOP rd_addr = 0x00
		0x00000000,  //1a NOP rd_addr = 0x00
		0x00005000,  //1b NOP rd_addr = 0x00 alu_sel = sub wr_addr = 0x00 wr_data_sel = alu mem_we = even
		0x00006800,  //1c NOP rd_addr = 0x00 alu_sel = sub wr_addr = 0x00 wr_data_sel = alu mem_we = odd  in_sel = 1

		//! ;LOOP_C
		0x20700000,  //1d LOOPC cc = always
		0x00000000,  //1e NOP
		0xE2000000,  //1f SETBITS intr_out
		0x30700000,  //20 JUMP 0 cc = always
//! FOOTER INFORMATION


	},
	{
//! BATCH_1:  C:\AmbientScientific\setup\chip\fw\applications\i2s-tmbuffer-aon-alexa-ww-cnn\training_tool_chain\python\temp\GC_05_08_2026_11_12_30\Batch1.hex.gpx
//! HEADER INFORMATION  OR STRUCTURE NAME OR  SECTION INFORMATION
		0x00000000,  //21 NOP
		0xE0000100,  //22 SETBITS sel_oclk rd_addr = 0x00 

		//! ;SETBUFF
		0xD0000080,  //23 SETBUFF outbuff = 8

		//! ;WRIREG_ALL
		0x68000000,  //24 WRREG 16 0x0
		0x68800020,  //25 WRREG 17 0x20
		0x69000000,  //26 WRREG 18 0x0
		0x60000000,  //27 WRREG 0x0 0x0		; o_NEURON
		0x60800001,  //28 WRREG 0x1 0x1		; o_BIAS_NEURON
		0x61000002,  //29 WRREG 0x2 0x2		; o_DENSE_OUT
		0x61800003,  //2a WRREG 0x3 0x3		; o_MATMUL_OUT
		0x62000004,  //2b WRREG 0x4 0x4		; PREG_RESERVED_FOR_S3_ZEROXBAR
		0x62800005,  //2c WRREG 0x5 0x5		; i_BIAS
		0x67800012,  //2d WRREG 0xf 0x12		; o_BIAS_CONV

		//! ;LOOP_ST_2
		0x14000000,  //2e LOOPST  0x04

		//! ;WAIT_MAC
		0xE0000400,  //2f SETBITS ld_samples
		0x80113030,  //30 WAIT cc = neurons_valid wr_addr = 0x03 mem_we = both wr_data_sel = neurons

		//! ;ADD_		WRITE 0x00->0x00 (o_NEURON), READ 0x00->0x00 (o_NEURON), READ 0x03->0x03 (o_MATMUL_OUT)
		0x00000000,  //31 NOP rd_addr = 0x00
		0xE0008003,  //32 SETBITS use32 rd_addr = 0x03
		0x00001000,  //33 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 0
		0x00002800,  //34 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = odd	 in_sel = 1 sign_extend = 0
		0x98700000,  //35 INCREG 16 cc = always
		0x99700000,  //36 INCREG 18 cc = always
		0x99700000,  //37 INCREG 18 cc = always
		0x99700000,  //38 INCREG 18 cc = always
		0x99700000,  //39 INCREG 18 cc = always

		//! ;WAIT_MAC
		0xE0000400,  //3a SETBITS ld_samples
		0x80113030,  //3b WAIT cc = neurons_valid wr_addr = 0x03 mem_we = both wr_data_sel = neurons

		//! ;ADD_		WRITE 0x00->0x00 (o_NEURON), READ 0x00->0x00 (o_NEURON), READ 0x03->0x03 (o_MATMUL_OUT)
		0x00000000,  //3c NOP rd_addr = 0x00
		0xE0008003,  //3d SETBITS use32 rd_addr = 0x03
		0x00001000,  //3e NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 0
		0x00002800,  //3f NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = odd	 in_sel = 1 sign_extend = 0
		0x98700000,  //40 INCREG 16 cc = always
		0x99700000,  //41 INCREG 18 cc = always
		0x99700000,  //42 INCREG 18 cc = always
		0x99700000,  //43 INCREG 18 cc = always
		0x99700000,  //44 INCREG 18 cc = always

		//! ;WAIT_MAC
		0xE0000400,  //45 SETBITS ld_samples
		0x80113030,  //46 WAIT cc = neurons_valid wr_addr = 0x03 mem_we = both wr_data_sel = neurons

		//! ;ADD_		WRITE 0x00->0x00 (o_NEURON), READ 0x00->0x00 (o_NEURON), READ 0x03->0x03 (o_MATMUL_OUT)
		0x00000000,  //47 NOP rd_addr = 0x00
		0xE0008003,  //48 SETBITS use32 rd_addr = 0x03
		0x00001000,  //49 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 0
		0x00002800,  //4a NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = odd	 in_sel = 1 sign_extend = 0

		//! ;WR_REG
		0x68000000,  //4b WRREG  0x10 0x00

		//! ;ADD_		WRITE 0x0F->0x12 (o_BIAS_CONV), READ 0x05->0x05 (i_BIAS), READ 0x00->0x00 (o_NEURON)
		0x00000005,  //4c NOP rd_addr = 0x05
		0xE0008000,  //4d SETBITS use32 rd_addr = 0x00
		0x000010F5,  //4e NOP rd_addr = 0x05 alu_sel = add wr_addr = 0x0F wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 0
		0x000028F0,  //4f NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x0F wr_data_sel = alu mem_we = odd	 in_sel = 1 sign_extend = 0

		//! ;INC_REG
		0x97F00000,  //50 INCREG  0x0F  cc = always
		0x99700000,  //51 INCREG 18 cc = always
		0x99700000,  //52 INCREG 18 cc = always
		0x99700000,  //53 INCREG 18 cc = always
		0x99700000,  //54 INCREG 18 cc = always

		//! ;ZERO_REG_
		0x00000000,  //55 NOP rd_addr = 0x00
		0x00000000,  //56 NOP rd_addr = 0x00
		0x00005000,  //57 NOP rd_addr = 0x00 alu_sel = sub wr_addr = 0x00 wr_data_sel = alu mem_we = even
		0x00006800,  //58 NOP rd_addr = 0x00 alu_sel = sub wr_addr = 0x00 wr_data_sel = alu mem_we = odd  in_sel = 1

		//! ;LOOP_C
		0x20700000,  //59 LOOPC cc = always
		0x00000000,  //5a NOP
		0xE2000000,  //5b SETBITS intr_out
		0x30700000,  //5c JUMP 0 cc = always
//! FOOTER INFORMATION


	},
	{
//! BATCH_2:  C:\AmbientScientific\setup\chip\fw\applications\i2s-tmbuffer-aon-alexa-ww-cnn\training_tool_chain\python\temp\GC_05_08_2026_11_12_30\Batch2.hex.gpx
//! HEADER INFORMATION  OR STRUCTURE NAME OR  SECTION INFORMATION
		0x00000000,  //5d NOP
		0xE0000100,  //5e SETBITS sel_oclk rd_addr = 0x00 

		//! ;SETBUFF
		0xD0000080,  //5f SETBUFF outbuff = 8

		//! ;WRIREG_ALL
		0x68000000,  //60 WRREG 16 0x0
		0x68800020,  //61 WRREG 17 0x20
		0x69000000,  //62 WRREG 18 0x0
		0x60000000,  //63 WRREG 0x0 0x0		; o_NEURON
		0x60800001,  //64 WRREG 0x1 0x1		; o_BIAS_NEURON
		0x61000002,  //65 WRREG 0x2 0x2		; o_DENSE_OUT
		0x61800003,  //66 WRREG 0x3 0x3		; o_MATMUL_OUT
		0x62000004,  //67 WRREG 0x4 0x4		; PREG_RESERVED_FOR_S3_ZEROXBAR
		0x62800005,  //68 WRREG 0x5 0x5		; i_BIAS
		0x67800012,  //69 WRREG 0xf 0x12		; o_BIAS_CONV

		//! ;LOOP_ST_2
		0x12000000,  //6a LOOPST  0x02

		//! ;WAIT_MAC
		0xE0000400,  //6b SETBITS ld_samples
		0x80113030,  //6c WAIT cc = neurons_valid wr_addr = 0x03 mem_we = both wr_data_sel = neurons

		//! ;ADD_		WRITE 0x00->0x00 (o_NEURON), READ 0x00->0x00 (o_NEURON), READ 0x03->0x03 (o_MATMUL_OUT)
		0x00000000,  //6d NOP rd_addr = 0x00
		0xE0008003,  //6e SETBITS use32 rd_addr = 0x03
		0x00001000,  //6f NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 0
		0x00002800,  //70 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = odd	 in_sel = 1 sign_extend = 0
		0x98700000,  //71 INCREG 16 cc = always
		0x99700000,  //72 INCREG 18 cc = always
		0x99700000,  //73 INCREG 18 cc = always
		0x99700000,  //74 INCREG 18 cc = always
		0x99700000,  //75 INCREG 18 cc = always

		//! ;WAIT_MAC
		0xE0000400,  //76 SETBITS ld_samples
		0x80113030,  //77 WAIT cc = neurons_valid wr_addr = 0x03 mem_we = both wr_data_sel = neurons

		//! ;ADD_		WRITE 0x00->0x00 (o_NEURON), READ 0x00->0x00 (o_NEURON), READ 0x03->0x03 (o_MATMUL_OUT)
		0x00000000,  //78 NOP rd_addr = 0x00
		0xE0008003,  //79 SETBITS use32 rd_addr = 0x03
		0x00001000,  //7a NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 0
		0x00002800,  //7b NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = odd	 in_sel = 1 sign_extend = 0
		0x98700000,  //7c INCREG 16 cc = always
		0x99700000,  //7d INCREG 18 cc = always
		0x99700000,  //7e INCREG 18 cc = always
		0x99700000,  //7f INCREG 18 cc = always
		0x99700000,  //80 INCREG 18 cc = always

		//! ;WAIT_MAC
		0xE0000400,  //81 SETBITS ld_samples
		0x80113030,  //82 WAIT cc = neurons_valid wr_addr = 0x03 mem_we = both wr_data_sel = neurons

		//! ;ADD_		WRITE 0x00->0x00 (o_NEURON), READ 0x00->0x00 (o_NEURON), READ 0x03->0x03 (o_MATMUL_OUT)
		0x00000000,  //83 NOP rd_addr = 0x00
		0xE0008003,  //84 SETBITS use32 rd_addr = 0x03
		0x00001000,  //85 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 0
		0x00002800,  //86 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = odd	 in_sel = 1 sign_extend = 0
		0x98700000,  //87 INCREG 16 cc = always
		0x99700000,  //88 INCREG 18 cc = always
		0x99700000,  //89 INCREG 18 cc = always
		0x99700000,  //8a INCREG 18 cc = always
		0x99700000,  //8b INCREG 18 cc = always

		//! ;WAIT_MAC
		0xE0000400,  //8c SETBITS ld_samples
		0x80113030,  //8d WAIT cc = neurons_valid wr_addr = 0x03 mem_we = both wr_data_sel = neurons

		//! ;ADD_		WRITE 0x00->0x00 (o_NEURON), READ 0x00->0x00 (o_NEURON), READ 0x03->0x03 (o_MATMUL_OUT)
		0x00000000,  //8e NOP rd_addr = 0x00
		0xE0008003,  //8f SETBITS use32 rd_addr = 0x03
		0x00001000,  //90 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 0
		0x00002800,  //91 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = odd	 in_sel = 1 sign_extend = 0
		0x98700000,  //92 INCREG 16 cc = always
		0x99700000,  //93 INCREG 18 cc = always
		0x99700000,  //94 INCREG 18 cc = always
		0x99700000,  //95 INCREG 18 cc = always
		0x99700000,  //96 INCREG 18 cc = always

		//! ;WAIT_MAC
		0xE0000400,  //97 SETBITS ld_samples
		0x80113030,  //98 WAIT cc = neurons_valid wr_addr = 0x03 mem_we = both wr_data_sel = neurons

		//! ;ADD_		WRITE 0x00->0x00 (o_NEURON), READ 0x00->0x00 (o_NEURON), READ 0x03->0x03 (o_MATMUL_OUT)
		0x00000000,  //99 NOP rd_addr = 0x00
		0xE0008003,  //9a SETBITS use32 rd_addr = 0x03
		0x00001000,  //9b NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 0
		0x00002800,  //9c NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = odd	 in_sel = 1 sign_extend = 0
		0x98700000,  //9d INCREG 16 cc = always
		0x99700000,  //9e INCREG 18 cc = always
		0x99700000,  //9f INCREG 18 cc = always
		0x99700000,  //a0 INCREG 18 cc = always
		0x99700000,  //a1 INCREG 18 cc = always

		//! ;WAIT_MAC
		0xE0000400,  //a2 SETBITS ld_samples
		0x80113030,  //a3 WAIT cc = neurons_valid wr_addr = 0x03 mem_we = both wr_data_sel = neurons

		//! ;ADD_		WRITE 0x00->0x00 (o_NEURON), READ 0x00->0x00 (o_NEURON), READ 0x03->0x03 (o_MATMUL_OUT)
		0x00000000,  //a4 NOP rd_addr = 0x00
		0xE0008003,  //a5 SETBITS use32 rd_addr = 0x03
		0x00001000,  //a6 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 0
		0x00002800,  //a7 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = odd	 in_sel = 1 sign_extend = 0

		//! ;WR_REG
		0x68000000,  //a8 WRREG  0x10 0x00

		//! ;ADD_		WRITE 0x0F->0x12 (o_BIAS_CONV), READ 0x05->0x05 (i_BIAS), READ 0x00->0x00 (o_NEURON)
		0x00000005,  //a9 NOP rd_addr = 0x05
		0xE0008000,  //aa SETBITS use32 rd_addr = 0x00
		0x000010F5,  //ab NOP rd_addr = 0x05 alu_sel = add wr_addr = 0x0F wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 0
		0x000028F0,  //ac NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x0F wr_data_sel = alu mem_we = odd	 in_sel = 1 sign_extend = 0

		//! ;INC_REG
		0x97F00000,  //ad INCREG  0x0F  cc = always
		0x99700000,  //ae INCREG 18 cc = always
		0x99700000,  //af INCREG 18 cc = always
		0x99700000,  //b0 INCREG 18 cc = always
		0x99700000,  //b1 INCREG 18 cc = always

		//! ;ZERO_REG_
		0x00000000,  //b2 NOP rd_addr = 0x00
		0x00000000,  //b3 NOP rd_addr = 0x00
		0x00005000,  //b4 NOP rd_addr = 0x00 alu_sel = sub wr_addr = 0x00 wr_data_sel = alu mem_we = even
		0x00006800,  //b5 NOP rd_addr = 0x00 alu_sel = sub wr_addr = 0x00 wr_data_sel = alu mem_we = odd  in_sel = 1

		//! ;LOOP_C
		0x20700000,  //b6 LOOPC cc = always
		0x00000000,  //b7 NOP
		0xE2000000,  //b8 SETBITS intr_out
		0x30700000,  //b9 JUMP 0 cc = always
//! FOOTER INFORMATION


	},
	{
//! BATCH_3:  C:\AmbientScientific\setup\chip\fw\applications\i2s-tmbuffer-aon-alexa-ww-cnn\training_tool_chain\python\temp\GC_05_08_2026_11_12_30\Batch3.hex.gpx
//! HEADER INFORMATION  OR STRUCTURE NAME OR  SECTION INFORMATION
		0x00000000,  //ba NOP
		0xE0000100,  //bb SETBITS sel_oclk rd_addr = 0x00 

		//! ;SETBUFF
		0xD0000080,  //bc SETBUFF outbuff = 8

		//! ;WRIREG_ALL
		0x68000000,  //bd WRREG 16 0x0
		0x68800020,  //be WRREG 17 0x20
		0x69000000,  //bf WRREG 18 0x0
		0x60000000,  //c0 WRREG 0x0 0x0		; o_NEURON
		0x60800001,  //c1 WRREG 0x1 0x1		; o_BIAS_NEURON
		0x61000002,  //c2 WRREG 0x2 0x2		; o_DENSE_OUT
		0x61800003,  //c3 WRREG 0x3 0x3		; o_MATMUL_OUT
		0x62000004,  //c4 WRREG 0x4 0x4		; PREG_RESERVED_FOR_S3_ZEROXBAR
		0x62800005,  //c5 WRREG 0x5 0x5		; i_BIAS
		0x67800012,  //c6 WRREG 0xf 0x12		; o_BIAS_CONV

		//! ;LOOP_ST_2
		0x12000000,  //c7 LOOPST  0x02

		//! ;WAIT_MAC
		0xE0000400,  //c8 SETBITS ld_samples
		0x80113030,  //c9 WAIT cc = neurons_valid wr_addr = 0x03 mem_we = both wr_data_sel = neurons

		//! ;ADD_		WRITE 0x00->0x00 (o_NEURON), READ 0x00->0x00 (o_NEURON), READ 0x03->0x03 (o_MATMUL_OUT)
		0x00000000,  //ca NOP rd_addr = 0x00
		0xE0008003,  //cb SETBITS use32 rd_addr = 0x03
		0x00001000,  //cc NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 0
		0x00002800,  //cd NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = odd	 in_sel = 1 sign_extend = 0
		0x98700000,  //ce INCREG 16 cc = always
		0x99700000,  //cf INCREG 18 cc = always
		0x99700000,  //d0 INCREG 18 cc = always
		0x99700000,  //d1 INCREG 18 cc = always
		0x99700000,  //d2 INCREG 18 cc = always

		//! ;WAIT_MAC
		0xE0000400,  //d3 SETBITS ld_samples
		0x80113030,  //d4 WAIT cc = neurons_valid wr_addr = 0x03 mem_we = both wr_data_sel = neurons

		//! ;ADD_		WRITE 0x00->0x00 (o_NEURON), READ 0x00->0x00 (o_NEURON), READ 0x03->0x03 (o_MATMUL_OUT)
		0x00000000,  //d5 NOP rd_addr = 0x00
		0xE0008003,  //d6 SETBITS use32 rd_addr = 0x03
		0x00001000,  //d7 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 0
		0x00002800,  //d8 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = odd	 in_sel = 1 sign_extend = 0
		0x98700000,  //d9 INCREG 16 cc = always
		0x99700000,  //da INCREG 18 cc = always
		0x99700000,  //db INCREG 18 cc = always
		0x99700000,  //dc INCREG 18 cc = always
		0x99700000,  //dd INCREG 18 cc = always

		//! ;WAIT_MAC
		0xE0000400,  //de SETBITS ld_samples
		0x80113030,  //df WAIT cc = neurons_valid wr_addr = 0x03 mem_we = both wr_data_sel = neurons

		//! ;ADD_		WRITE 0x00->0x00 (o_NEURON), READ 0x00->0x00 (o_NEURON), READ 0x03->0x03 (o_MATMUL_OUT)
		0x00000000,  //e0 NOP rd_addr = 0x00
		0xE0008003,  //e1 SETBITS use32 rd_addr = 0x03
		0x00001000,  //e2 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 0
		0x00002800,  //e3 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = odd	 in_sel = 1 sign_extend = 0
		0x98700000,  //e4 INCREG 16 cc = always
		0x99700000,  //e5 INCREG 18 cc = always
		0x99700000,  //e6 INCREG 18 cc = always
		0x99700000,  //e7 INCREG 18 cc = always
		0x99700000,  //e8 INCREG 18 cc = always

		//! ;WAIT_MAC
		0xE0000400,  //e9 SETBITS ld_samples
		0x80113030,  //ea WAIT cc = neurons_valid wr_addr = 0x03 mem_we = both wr_data_sel = neurons

		//! ;ADD_		WRITE 0x00->0x00 (o_NEURON), READ 0x00->0x00 (o_NEURON), READ 0x03->0x03 (o_MATMUL_OUT)
		0x00000000,  //eb NOP rd_addr = 0x00
		0xE0008003,  //ec SETBITS use32 rd_addr = 0x03
		0x00001000,  //ed NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 0
		0x00002800,  //ee NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = odd	 in_sel = 1 sign_extend = 0
		0x98700000,  //ef INCREG 16 cc = always
		0x99700000,  //f0 INCREG 18 cc = always
		0x99700000,  //f1 INCREG 18 cc = always
		0x99700000,  //f2 INCREG 18 cc = always
		0x99700000,  //f3 INCREG 18 cc = always

		//! ;WAIT_MAC
		0xE0000400,  //f4 SETBITS ld_samples
		0x80113030,  //f5 WAIT cc = neurons_valid wr_addr = 0x03 mem_we = both wr_data_sel = neurons

		//! ;ADD_		WRITE 0x00->0x00 (o_NEURON), READ 0x00->0x00 (o_NEURON), READ 0x03->0x03 (o_MATMUL_OUT)
		0x00000000,  //f6 NOP rd_addr = 0x00
		0xE0008003,  //f7 SETBITS use32 rd_addr = 0x03
		0x00001000,  //f8 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 0
		0x00002800,  //f9 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = odd	 in_sel = 1 sign_extend = 0
		0x98700000,  //fa INCREG 16 cc = always
		0x99700000,  //fb INCREG 18 cc = always
		0x99700000,  //fc INCREG 18 cc = always
		0x99700000,  //fd INCREG 18 cc = always
		0x99700000,  //fe INCREG 18 cc = always

		//! ;WAIT_MAC
		0xE0000400,  //ff SETBITS ld_samples
		0x80113030,  //100 WAIT cc = neurons_valid wr_addr = 0x03 mem_we = both wr_data_sel = neurons

		//! ;ADD_		WRITE 0x00->0x00 (o_NEURON), READ 0x00->0x00 (o_NEURON), READ 0x03->0x03 (o_MATMUL_OUT)
		0x00000000,  //101 NOP rd_addr = 0x00
		0xE0008003,  //102 SETBITS use32 rd_addr = 0x03
		0x00001000,  //103 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 0
		0x00002800,  //104 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = odd	 in_sel = 1 sign_extend = 0

		//! ;WR_REG
		0x68000000,  //105 WRREG  0x10 0x00

		//! ;ADD_		WRITE 0x0F->0x12 (o_BIAS_CONV), READ 0x05->0x05 (i_BIAS), READ 0x00->0x00 (o_NEURON)
		0x00000005,  //106 NOP rd_addr = 0x05
		0xE0008000,  //107 SETBITS use32 rd_addr = 0x00
		0x000010F5,  //108 NOP rd_addr = 0x05 alu_sel = add wr_addr = 0x0F wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 0
		0x000028F0,  //109 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x0F wr_data_sel = alu mem_we = odd	 in_sel = 1 sign_extend = 0

		//! ;INC_REG
		0x97F00000,  //10a INCREG  0x0F  cc = always
		0x99700000,  //10b INCREG 18 cc = always
		0x99700000,  //10c INCREG 18 cc = always
		0x99700000,  //10d INCREG 18 cc = always
		0x99700000,  //10e INCREG 18 cc = always

		//! ;ZERO_REG_
		0x00000000,  //10f NOP rd_addr = 0x00
		0x00000000,  //110 NOP rd_addr = 0x00
		0x00005000,  //111 NOP rd_addr = 0x00 alu_sel = sub wr_addr = 0x00 wr_data_sel = alu mem_we = even
		0x00006800,  //112 NOP rd_addr = 0x00 alu_sel = sub wr_addr = 0x00 wr_data_sel = alu mem_we = odd  in_sel = 1

		//! ;LOOP_C
		0x20700000,  //113 LOOPC cc = always
		0x00000000,  //114 NOP
		0xE2000000,  //115 SETBITS intr_out
		0x30700000,  //116 JUMP 0 cc = always
//! FOOTER INFORMATION


	},
	{
//! BATCH_4:  C:\AmbientScientific\setup\chip\fw\applications\i2s-tmbuffer-aon-alexa-ww-cnn\training_tool_chain\python\temp\GC_05_08_2026_11_12_30\Batch4.hex.gpx
//! HEADER INFORMATION  OR STRUCTURE NAME OR  SECTION INFORMATION
		0x00000000,  //117 NOP
		0xE0000100,  //118 SETBITS sel_oclk rd_addr = 0x00 

		//! ;SETBUFF
		0xD0000080,  //119 SETBUFF outbuff = 8

		//! ;WRIREG_ALL
		0x68000000,  //11a WRREG 16 0x0
		0x68800020,  //11b WRREG 17 0x20
		0x69000000,  //11c WRREG 18 0x0
		0x60000000,  //11d WRREG 0x0 0x0		; o_NEURON
		0x60800001,  //11e WRREG 0x1 0x1		; o_BIAS_NEURON
		0x61000002,  //11f WRREG 0x2 0x2		; o_DENSE_OUT
		0x61800003,  //120 WRREG 0x3 0x3		; o_MATMUL_OUT
		0x62000004,  //121 WRREG 0x4 0x4		; PREG_RESERVED_FOR_S3_ZEROXBAR
		0x62800005,  //122 WRREG 0x5 0x5		; i_BIAS
		0x67800012,  //123 WRREG 0xf 0x12		; o_BIAS_CONV

		//! ;WAIT_MAC
		0xE0000400,  //124 SETBITS ld_samples
		0x80113030,  //125 WAIT cc = neurons_valid wr_addr = 0x03 mem_we = both wr_data_sel = neurons

		//! ;ADD_		WRITE 0x00->0x00 (o_NEURON), READ 0x00->0x00 (o_NEURON), READ 0x03->0x03 (o_MATMUL_OUT)
		0x00000000,  //126 NOP rd_addr = 0x00
		0xE0008003,  //127 SETBITS use32 rd_addr = 0x03
		0x00001000,  //128 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 0
		0x00002800,  //129 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = odd	 in_sel = 1 sign_extend = 0
		0x98700000,  //12a INCREG 16 cc = always
		0x99700000,  //12b INCREG 18 cc = always
		0x99700000,  //12c INCREG 18 cc = always
		0x99700000,  //12d INCREG 18 cc = always
		0x99700000,  //12e INCREG 18 cc = always

		//! ;WAIT_MAC
		0xE0000400,  //12f SETBITS ld_samples
		0x80113030,  //130 WAIT cc = neurons_valid wr_addr = 0x03 mem_we = both wr_data_sel = neurons

		//! ;ADD_		WRITE 0x00->0x00 (o_NEURON), READ 0x00->0x00 (o_NEURON), READ 0x03->0x03 (o_MATMUL_OUT)
		0x00000000,  //131 NOP rd_addr = 0x00
		0xE0008003,  //132 SETBITS use32 rd_addr = 0x03
		0x00001000,  //133 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 0
		0x00002800,  //134 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = odd	 in_sel = 1 sign_extend = 0
		0x98700000,  //135 INCREG 16 cc = always
		0x99700000,  //136 INCREG 18 cc = always
		0x99700000,  //137 INCREG 18 cc = always
		0x99700000,  //138 INCREG 18 cc = always
		0x99700000,  //139 INCREG 18 cc = always

		//! ;WAIT_MAC
		0xE0000400,  //13a SETBITS ld_samples
		0x80113030,  //13b WAIT cc = neurons_valid wr_addr = 0x03 mem_we = both wr_data_sel = neurons

		//! ;ADD_		WRITE 0x00->0x00 (o_NEURON), READ 0x00->0x00 (o_NEURON), READ 0x03->0x03 (o_MATMUL_OUT)
		0x00000000,  //13c NOP rd_addr = 0x00
		0xE0008003,  //13d SETBITS use32 rd_addr = 0x03
		0x00001000,  //13e NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 0
		0x00002800,  //13f NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = odd	 in_sel = 1 sign_extend = 0
		0x98700000,  //140 INCREG 16 cc = always
		0x99700000,  //141 INCREG 18 cc = always
		0x99700000,  //142 INCREG 18 cc = always
		0x99700000,  //143 INCREG 18 cc = always
		0x99700000,  //144 INCREG 18 cc = always

		//! ;WAIT_MAC
		0xE0000400,  //145 SETBITS ld_samples
		0x80113030,  //146 WAIT cc = neurons_valid wr_addr = 0x03 mem_we = both wr_data_sel = neurons

		//! ;ADD_		WRITE 0x00->0x00 (o_NEURON), READ 0x00->0x00 (o_NEURON), READ 0x03->0x03 (o_MATMUL_OUT)
		0x00000000,  //147 NOP rd_addr = 0x00
		0xE0008003,  //148 SETBITS use32 rd_addr = 0x03
		0x00001000,  //149 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 0
		0x00002800,  //14a NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = odd	 in_sel = 1 sign_extend = 0
		0x98700000,  //14b INCREG 16 cc = always
		0x99700000,  //14c INCREG 18 cc = always
		0x99700000,  //14d INCREG 18 cc = always
		0x99700000,  //14e INCREG 18 cc = always
		0x99700000,  //14f INCREG 18 cc = always

		//! ;WAIT_MAC
		0xE0000400,  //150 SETBITS ld_samples
		0x80113030,  //151 WAIT cc = neurons_valid wr_addr = 0x03 mem_we = both wr_data_sel = neurons

		//! ;ADD_		WRITE 0x00->0x00 (o_NEURON), READ 0x00->0x00 (o_NEURON), READ 0x03->0x03 (o_MATMUL_OUT)
		0x00000000,  //152 NOP rd_addr = 0x00
		0xE0008003,  //153 SETBITS use32 rd_addr = 0x03
		0x00001000,  //154 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 0
		0x00002800,  //155 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = odd	 in_sel = 1 sign_extend = 0
		0x98700000,  //156 INCREG 16 cc = always
		0x99700000,  //157 INCREG 18 cc = always
		0x99700000,  //158 INCREG 18 cc = always
		0x99700000,  //159 INCREG 18 cc = always
		0x99700000,  //15a INCREG 18 cc = always

		//! ;WAIT_MAC
		0xE0000400,  //15b SETBITS ld_samples
		0x80113030,  //15c WAIT cc = neurons_valid wr_addr = 0x03 mem_we = both wr_data_sel = neurons

		//! ;ADD_		WRITE 0x00->0x00 (o_NEURON), READ 0x00->0x00 (o_NEURON), READ 0x03->0x03 (o_MATMUL_OUT)
		0x00000000,  //15d NOP rd_addr = 0x00
		0xE0008003,  //15e SETBITS use32 rd_addr = 0x03
		0x00001000,  //15f NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 0
		0x00002800,  //160 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = odd	 in_sel = 1 sign_extend = 0

		//! ;WR_REG
		0x69000000,  //161 WRREG  0x12 0x00

		//! ;ADD_		WRITE 0x00->0x00 (o_NEURON), READ 0x05->0x05 (i_BIAS), READ 0x00->0x00 (o_NEURON)
		0x00000005,  //162 NOP rd_addr = 0x05
		0xE0008000,  //163 SETBITS use32 rd_addr = 0x00
		0x00001005,  //164 NOP rd_addr = 0x05 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 0
		0x00002800,  //165 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = odd	 in_sel = 1 sign_extend = 0
		0x98700000,  //166 INCREG 16 cc = always

		//! ;INC_REG
		0x92F00000,  //167 INCREG  0x05  cc = always
		0x00000000,  //168 NOP
		0xE2000000,  //169 SETBITS intr_out
		0x30700000,  //16a JUMP 0 cc = always
//! FOOTER INFORMATION


	},
	{
//! BATCH_5:  C:\AmbientScientific\setup\chip\fw\applications\i2s-tmbuffer-aon-alexa-ww-cnn\training_tool_chain\python\temp\GC_05_08_2026_11_12_30\Batch5.hex.gpx
//! HEADER INFORMATION  OR STRUCTURE NAME OR  SECTION INFORMATION
		0x00000000,  //16b NOP
		0xE0000100,  //16c SETBITS sel_oclk rd_addr = 0x00 

		//! ;SETBUFF
		0xD0000080,  //16d SETBUFF outbuff = 8

		//! ;WRIREG_ALL
		0x68000000,  //16e WRREG 16 0x0
		0x68800020,  //16f WRREG 17 0x20
		0x69000000,  //170 WRREG 18 0x0
		0x60000000,  //171 WRREG 0x0 0x0		; o_NEURON
		0x60800001,  //172 WRREG 0x1 0x1		; o_BIAS_NEURON
		0x61000002,  //173 WRREG 0x2 0x2		; o_DENSE_OUT
		0x61800003,  //174 WRREG 0x3 0x3		; o_MATMUL_OUT
		0x62000004,  //175 WRREG 0x4 0x4		; PREG_RESERVED_FOR_S3_ZEROXBAR
		0x62800005,  //176 WRREG 0x5 0x5		; i_BIAS
		0x67800012,  //177 WRREG 0xf 0x12		; o_BIAS_CONV

		//! ;WAIT_MAC
		0xE0000400,  //178 SETBITS ld_samples
		0x80113030,  //179 WAIT cc = neurons_valid wr_addr = 0x03 mem_we = both wr_data_sel = neurons

		//! ;ADD_		WRITE 0x00->0x00 (o_NEURON), READ 0x00->0x00 (o_NEURON), READ 0x03->0x03 (o_MATMUL_OUT)
		0x00000000,  //17a NOP rd_addr = 0x00
		0xE0008003,  //17b SETBITS use32 rd_addr = 0x03
		0x00001000,  //17c NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 0
		0x00002800,  //17d NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = odd	 in_sel = 1 sign_extend = 0
		0x98700000,  //17e INCREG 16 cc = always
		0x99700000,  //17f INCREG 18 cc = always
		0x99700000,  //180 INCREG 18 cc = always
		0x99700000,  //181 INCREG 18 cc = always
		0x99700000,  //182 INCREG 18 cc = always

		//! ;WAIT_MAC
		0xE0000400,  //183 SETBITS ld_samples
		0x80113030,  //184 WAIT cc = neurons_valid wr_addr = 0x03 mem_we = both wr_data_sel = neurons

		//! ;ADD_		WRITE 0x00->0x00 (o_NEURON), READ 0x00->0x00 (o_NEURON), READ 0x03->0x03 (o_MATMUL_OUT)
		0x00000000,  //185 NOP rd_addr = 0x00
		0xE0008003,  //186 SETBITS use32 rd_addr = 0x03
		0x00001000,  //187 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 0
		0x00002800,  //188 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = odd	 in_sel = 1 sign_extend = 0
		0x98700000,  //189 INCREG 16 cc = always
		0x99700000,  //18a INCREG 18 cc = always
		0x99700000,  //18b INCREG 18 cc = always
		0x99700000,  //18c INCREG 18 cc = always
		0x99700000,  //18d INCREG 18 cc = always

		//! ;WAIT_MAC
		0xE0000400,  //18e SETBITS ld_samples
		0x80113030,  //18f WAIT cc = neurons_valid wr_addr = 0x03 mem_we = both wr_data_sel = neurons

		//! ;ADD_		WRITE 0x00->0x00 (o_NEURON), READ 0x00->0x00 (o_NEURON), READ 0x03->0x03 (o_MATMUL_OUT)
		0x00000000,  //190 NOP rd_addr = 0x00
		0xE0008003,  //191 SETBITS use32 rd_addr = 0x03
		0x00001000,  //192 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 0
		0x00002800,  //193 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = odd	 in_sel = 1 sign_extend = 0
		0x98700000,  //194 INCREG 16 cc = always
		0x99700000,  //195 INCREG 18 cc = always
		0x99700000,  //196 INCREG 18 cc = always
		0x99700000,  //197 INCREG 18 cc = always
		0x99700000,  //198 INCREG 18 cc = always

		//! ;WAIT_MAC
		0xE0000400,  //199 SETBITS ld_samples
		0x80113030,  //19a WAIT cc = neurons_valid wr_addr = 0x03 mem_we = both wr_data_sel = neurons

		//! ;ADD_		WRITE 0x00->0x00 (o_NEURON), READ 0x00->0x00 (o_NEURON), READ 0x03->0x03 (o_MATMUL_OUT)
		0x00000000,  //19b NOP rd_addr = 0x00
		0xE0008003,  //19c SETBITS use32 rd_addr = 0x03
		0x00001000,  //19d NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 0
		0x00002800,  //19e NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = odd	 in_sel = 1 sign_extend = 0
		0x98700000,  //19f INCREG 16 cc = always
		0x99700000,  //1a0 INCREG 18 cc = always
		0x99700000,  //1a1 INCREG 18 cc = always
		0x99700000,  //1a2 INCREG 18 cc = always
		0x99700000,  //1a3 INCREG 18 cc = always

		//! ;WAIT_MAC
		0xE0000400,  //1a4 SETBITS ld_samples
		0x80113030,  //1a5 WAIT cc = neurons_valid wr_addr = 0x03 mem_we = both wr_data_sel = neurons

		//! ;ADD_		WRITE 0x00->0x00 (o_NEURON), READ 0x00->0x00 (o_NEURON), READ 0x03->0x03 (o_MATMUL_OUT)
		0x00000000,  //1a6 NOP rd_addr = 0x00
		0xE0008003,  //1a7 SETBITS use32 rd_addr = 0x03
		0x00001000,  //1a8 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 0
		0x00002800,  //1a9 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = odd	 in_sel = 1 sign_extend = 0
		0x98700000,  //1aa INCREG 16 cc = always
		0x99700000,  //1ab INCREG 18 cc = always
		0x99700000,  //1ac INCREG 18 cc = always
		0x99700000,  //1ad INCREG 18 cc = always
		0x99700000,  //1ae INCREG 18 cc = always

		//! ;WAIT_MAC
		0xE0000400,  //1af SETBITS ld_samples
		0x80113030,  //1b0 WAIT cc = neurons_valid wr_addr = 0x03 mem_we = both wr_data_sel = neurons

		//! ;ADD_		WRITE 0x00->0x00 (o_NEURON), READ 0x00->0x00 (o_NEURON), READ 0x03->0x03 (o_MATMUL_OUT)
		0x00000000,  //1b1 NOP rd_addr = 0x00
		0xE0008003,  //1b2 SETBITS use32 rd_addr = 0x03
		0x00001000,  //1b3 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 0
		0x00002800,  //1b4 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = odd	 in_sel = 1 sign_extend = 0

		//! ;WR_REG
		0x69000000,  //1b5 WRREG  0x12 0x00

		//! ;ADD_		WRITE 0x00->0x00 (o_NEURON), READ 0x05->0x05 (i_BIAS), READ 0x00->0x00 (o_NEURON)
		0x00000005,  //1b6 NOP rd_addr = 0x05
		0xE0008000,  //1b7 SETBITS use32 rd_addr = 0x00
		0x00001005,  //1b8 NOP rd_addr = 0x05 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 0
		0x00002800,  //1b9 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = odd	 in_sel = 1 sign_extend = 0
		0x98700000,  //1ba INCREG 16 cc = always

		//! ;INC_REG
		0x92F00000,  //1bb INCREG  0x05  cc = always
		0x00000000,  //1bc NOP
		0xE2000000,  //1bd SETBITS intr_out
		0x30700000,  //1be JUMP 0 cc = always
//! FOOTER INFORMATION


	},
	{
//! BATCH_6:  C:\AmbientScientific\setup\chip\fw\applications\i2s-tmbuffer-aon-alexa-ww-cnn\training_tool_chain\python\temp\GC_05_08_2026_11_12_30\Batch6.hex.gpx
//! HEADER INFORMATION  OR STRUCTURE NAME OR  SECTION INFORMATION
		0x00000000,  //1bf NOP
		0xE0000100,  //1c0 SETBITS sel_oclk rd_addr = 0x00 

		//! ;SETBUFF
		0xD0000080,  //1c1 SETBUFF outbuff = 8

		//! ;WRIREG_ALL
		0x68000000,  //1c2 WRREG 16 0x0
		0x68800020,  //1c3 WRREG 17 0x20
		0x69000000,  //1c4 WRREG 18 0x0
		0x60000000,  //1c5 WRREG 0x0 0x0		; o_NEURON
		0x60800001,  //1c6 WRREG 0x1 0x1		; o_BIAS_NEURON
		0x61000002,  //1c7 WRREG 0x2 0x2		; o_DENSE_OUT
		0x61800003,  //1c8 WRREG 0x3 0x3		; o_MATMUL_OUT
		0x62000004,  //1c9 WRREG 0x4 0x4		; PREG_RESERVED_FOR_S3_ZEROXBAR
		0x62800005,  //1ca WRREG 0x5 0x5		; i_BIAS
		0x67800012,  //1cb WRREG 0xf 0x12		; o_BIAS_CONV

		//! ;WAIT_MAC
		0xE0000400,  //1cc SETBITS ld_samples
		0x80113000,  //1cd WAIT cc = neurons_valid wr_addr = 0x00 mem_we = both wr_data_sel = neurons

		//! ;ADD_		WRITE 0x00->0x00 (o_NEURON), READ 0x05->0x05 (i_BIAS), READ 0x00->0x00 (o_NEURON)
		0x00000005,  //1ce NOP rd_addr = 0x05
		0xE0008000,  //1cf SETBITS use32 rd_addr = 0x00
		0x00001005,  //1d0 NOP rd_addr = 0x05 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 0
		0x00002800,  //1d1 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = odd	 in_sel = 1 sign_extend = 0
		0x00000000,  //1d2 NOP
		0xE2000000,  //1d3 SETBITS intr_out
		0x30700000,  //1d4 JUMP 0 cc = always
//! FOOTER INFORMATION


	},
};

#endif
