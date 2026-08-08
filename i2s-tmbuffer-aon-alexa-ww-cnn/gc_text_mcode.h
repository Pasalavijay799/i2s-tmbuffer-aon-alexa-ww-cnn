//! Auto Generated on  07_08_2026_12_54_30_.
//! Do Not Modify this file!!
//! ---------------------------------------------------------------------------------------------
//! gpxCLIWrapper Command:
//! 


const uint32_t N_OF_MC_BLOCKS = 7; 

#ifndef USE_COMPILER_MICROCODE
static uint32_t ucode_hex_generic [7][256] =
{
	{
//! BATCH_0:  C:\AmbientScientific\setup\chip\fw\applications\i2s-tmbuffer-aon-alexa-ww-cnn\test\temp\GC_07_08_2026_12_53_55\Batch0.hex.gpx
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

		//! ;ZERO_REG_
		0x00000000,  //17 NOP rd_addr = 0x00
		0x00000000,  //18 NOP rd_addr = 0x00
		0x00005000,  //19 NOP rd_addr = 0x00 alu_sel = sub wr_addr = 0x00 wr_data_sel = alu mem_we = even
		0x00006800,  //1a NOP rd_addr = 0x00 alu_sel = sub wr_addr = 0x00 wr_data_sel = alu mem_we = odd  in_sel = 1

		//! ;LOOP_C
		0x20700000,  //1b LOOPC cc = always
		0x00000000,  //1c NOP
		0xE2000000,  //1d SETBITS intr_out
		0x30700000,  //1e JUMP 0 cc = always
//! FOOTER INFORMATION


	},
	{
//! BATCH_1:  C:\AmbientScientific\setup\chip\fw\applications\i2s-tmbuffer-aon-alexa-ww-cnn\test\temp\GC_07_08_2026_12_53_55\Batch1.hex.gpx
//! HEADER INFORMATION  OR STRUCTURE NAME OR  SECTION INFORMATION
		0x00000000,  //1f NOP
		0xE0000100,  //20 SETBITS sel_oclk rd_addr = 0x00 

		//! ;SETBUFF
		0xD0000080,  //21 SETBUFF outbuff = 8

		//! ;WRIREG_ALL
		0x68000000,  //22 WRREG 16 0x0
		0x68800020,  //23 WRREG 17 0x20
		0x69000000,  //24 WRREG 18 0x0
		0x60000000,  //25 WRREG 0x0 0x0		; o_NEURON
		0x60800001,  //26 WRREG 0x1 0x1		; o_BIAS_NEURON
		0x61000002,  //27 WRREG 0x2 0x2		; o_DENSE_OUT
		0x61800003,  //28 WRREG 0x3 0x3		; o_MATMUL_OUT
		0x62000004,  //29 WRREG 0x4 0x4		; PREG_RESERVED_FOR_S3_ZEROXBAR
		0x62800005,  //2a WRREG 0x5 0x5		; i_BIAS
		0x67800012,  //2b WRREG 0xf 0x12		; o_BIAS_CONV

		//! ;LOOP_ST_2
		0x14000000,  //2c LOOPST  0x04

		//! ;WAIT_MAC
		0xE0000400,  //2d SETBITS ld_samples
		0x80113030,  //2e WAIT cc = neurons_valid wr_addr = 0x03 mem_we = both wr_data_sel = neurons

		//! ;ADD_		WRITE 0x00->0x00 (o_NEURON), READ 0x00->0x00 (o_NEURON), READ 0x03->0x03 (o_MATMUL_OUT)
		0x00000000,  //2f NOP rd_addr = 0x00
		0xE0008003,  //30 SETBITS use32 rd_addr = 0x03
		0x00001000,  //31 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 0
		0x00002800,  //32 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = odd	 in_sel = 1 sign_extend = 0
		0x98700000,  //33 INCREG 16 cc = always
		0x99700000,  //34 INCREG 18 cc = always
		0x99700000,  //35 INCREG 18 cc = always

		//! ;WAIT_MAC
		0xE0000400,  //36 SETBITS ld_samples
		0x80113030,  //37 WAIT cc = neurons_valid wr_addr = 0x03 mem_we = both wr_data_sel = neurons

		//! ;ADD_		WRITE 0x00->0x00 (o_NEURON), READ 0x00->0x00 (o_NEURON), READ 0x03->0x03 (o_MATMUL_OUT)
		0x00000000,  //38 NOP rd_addr = 0x00
		0xE0008003,  //39 SETBITS use32 rd_addr = 0x03
		0x00001000,  //3a NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 0
		0x00002800,  //3b NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = odd	 in_sel = 1 sign_extend = 0
		0x98700000,  //3c INCREG 16 cc = always
		0x99700000,  //3d INCREG 18 cc = always
		0x99700000,  //3e INCREG 18 cc = always

		//! ;WAIT_MAC
		0xE0000400,  //3f SETBITS ld_samples
		0x80113030,  //40 WAIT cc = neurons_valid wr_addr = 0x03 mem_we = both wr_data_sel = neurons

		//! ;ADD_		WRITE 0x00->0x00 (o_NEURON), READ 0x00->0x00 (o_NEURON), READ 0x03->0x03 (o_MATMUL_OUT)
		0x00000000,  //41 NOP rd_addr = 0x00
		0xE0008003,  //42 SETBITS use32 rd_addr = 0x03
		0x00001000,  //43 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 0
		0x00002800,  //44 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = odd	 in_sel = 1 sign_extend = 0

		//! ;WR_REG
		0x68000000,  //45 WRREG  0x10 0x00

		//! ;ADD_		WRITE 0x0F->0x12 (o_BIAS_CONV), READ 0x05->0x05 (i_BIAS), READ 0x00->0x00 (o_NEURON)
		0x00000005,  //46 NOP rd_addr = 0x05
		0xE0008000,  //47 SETBITS use32 rd_addr = 0x00
		0x000010F5,  //48 NOP rd_addr = 0x05 alu_sel = add wr_addr = 0x0F wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 0
		0x000028F0,  //49 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x0F wr_data_sel = alu mem_we = odd	 in_sel = 1 sign_extend = 0

		//! ;INC_REG
		0x97F00000,  //4a INCREG  0x0F  cc = always
		0x99700000,  //4b INCREG 18 cc = always
		0x99700000,  //4c INCREG 18 cc = always

		//! ;ZERO_REG_
		0x00000000,  //4d NOP rd_addr = 0x00
		0x00000000,  //4e NOP rd_addr = 0x00
		0x00005000,  //4f NOP rd_addr = 0x00 alu_sel = sub wr_addr = 0x00 wr_data_sel = alu mem_we = even
		0x00006800,  //50 NOP rd_addr = 0x00 alu_sel = sub wr_addr = 0x00 wr_data_sel = alu mem_we = odd  in_sel = 1

		//! ;LOOP_C
		0x20700000,  //51 LOOPC cc = always
		0x00000000,  //52 NOP
		0xE2000000,  //53 SETBITS intr_out
		0x30700000,  //54 JUMP 0 cc = always
//! FOOTER INFORMATION


	},
	{
//! BATCH_2:  C:\AmbientScientific\setup\chip\fw\applications\i2s-tmbuffer-aon-alexa-ww-cnn\test\temp\GC_07_08_2026_12_53_55\Batch2.hex.gpx
//! HEADER INFORMATION  OR STRUCTURE NAME OR  SECTION INFORMATION
		0x00000000,  //55 NOP
		0xE0000100,  //56 SETBITS sel_oclk rd_addr = 0x00 

		//! ;SETBUFF
		0xD0000080,  //57 SETBUFF outbuff = 8

		//! ;WRIREG_ALL
		0x68000000,  //58 WRREG 16 0x0
		0x68800020,  //59 WRREG 17 0x20
		0x69000000,  //5a WRREG 18 0x0
		0x60000000,  //5b WRREG 0x0 0x0		; o_NEURON
		0x60800001,  //5c WRREG 0x1 0x1		; o_BIAS_NEURON
		0x61000002,  //5d WRREG 0x2 0x2		; o_DENSE_OUT
		0x61800003,  //5e WRREG 0x3 0x3		; o_MATMUL_OUT
		0x62000004,  //5f WRREG 0x4 0x4		; PREG_RESERVED_FOR_S3_ZEROXBAR
		0x62800005,  //60 WRREG 0x5 0x5		; i_BIAS
		0x67800012,  //61 WRREG 0xf 0x12		; o_BIAS_CONV

		//! ;LOOP_ST_2
		0x12000000,  //62 LOOPST  0x02

		//! ;WAIT_MAC
		0xE0000400,  //63 SETBITS ld_samples
		0x80113030,  //64 WAIT cc = neurons_valid wr_addr = 0x03 mem_we = both wr_data_sel = neurons

		//! ;ADD_		WRITE 0x00->0x00 (o_NEURON), READ 0x00->0x00 (o_NEURON), READ 0x03->0x03 (o_MATMUL_OUT)
		0x00000000,  //65 NOP rd_addr = 0x00
		0xE0008003,  //66 SETBITS use32 rd_addr = 0x03
		0x00001000,  //67 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 0
		0x00002800,  //68 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = odd	 in_sel = 1 sign_extend = 0
		0x98700000,  //69 INCREG 16 cc = always
		0x99700000,  //6a INCREG 18 cc = always
		0x99700000,  //6b INCREG 18 cc = always

		//! ;WAIT_MAC
		0xE0000400,  //6c SETBITS ld_samples
		0x80113030,  //6d WAIT cc = neurons_valid wr_addr = 0x03 mem_we = both wr_data_sel = neurons

		//! ;ADD_		WRITE 0x00->0x00 (o_NEURON), READ 0x00->0x00 (o_NEURON), READ 0x03->0x03 (o_MATMUL_OUT)
		0x00000000,  //6e NOP rd_addr = 0x00
		0xE0008003,  //6f SETBITS use32 rd_addr = 0x03
		0x00001000,  //70 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 0
		0x00002800,  //71 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = odd	 in_sel = 1 sign_extend = 0
		0x98700000,  //72 INCREG 16 cc = always
		0x99700000,  //73 INCREG 18 cc = always
		0x99700000,  //74 INCREG 18 cc = always

		//! ;WAIT_MAC
		0xE0000400,  //75 SETBITS ld_samples
		0x80113030,  //76 WAIT cc = neurons_valid wr_addr = 0x03 mem_we = both wr_data_sel = neurons

		//! ;ADD_		WRITE 0x00->0x00 (o_NEURON), READ 0x00->0x00 (o_NEURON), READ 0x03->0x03 (o_MATMUL_OUT)
		0x00000000,  //77 NOP rd_addr = 0x00
		0xE0008003,  //78 SETBITS use32 rd_addr = 0x03
		0x00001000,  //79 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 0
		0x00002800,  //7a NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = odd	 in_sel = 1 sign_extend = 0
		0x98700000,  //7b INCREG 16 cc = always
		0x99700000,  //7c INCREG 18 cc = always
		0x99700000,  //7d INCREG 18 cc = always

		//! ;WAIT_MAC
		0xE0000400,  //7e SETBITS ld_samples
		0x80113030,  //7f WAIT cc = neurons_valid wr_addr = 0x03 mem_we = both wr_data_sel = neurons

		//! ;ADD_		WRITE 0x00->0x00 (o_NEURON), READ 0x00->0x00 (o_NEURON), READ 0x03->0x03 (o_MATMUL_OUT)
		0x00000000,  //80 NOP rd_addr = 0x00
		0xE0008003,  //81 SETBITS use32 rd_addr = 0x03
		0x00001000,  //82 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 0
		0x00002800,  //83 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = odd	 in_sel = 1 sign_extend = 0
		0x98700000,  //84 INCREG 16 cc = always
		0x99700000,  //85 INCREG 18 cc = always
		0x99700000,  //86 INCREG 18 cc = always

		//! ;WAIT_MAC
		0xE0000400,  //87 SETBITS ld_samples
		0x80113030,  //88 WAIT cc = neurons_valid wr_addr = 0x03 mem_we = both wr_data_sel = neurons

		//! ;ADD_		WRITE 0x00->0x00 (o_NEURON), READ 0x00->0x00 (o_NEURON), READ 0x03->0x03 (o_MATMUL_OUT)
		0x00000000,  //89 NOP rd_addr = 0x00
		0xE0008003,  //8a SETBITS use32 rd_addr = 0x03
		0x00001000,  //8b NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 0
		0x00002800,  //8c NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = odd	 in_sel = 1 sign_extend = 0
		0x98700000,  //8d INCREG 16 cc = always
		0x99700000,  //8e INCREG 18 cc = always
		0x99700000,  //8f INCREG 18 cc = always

		//! ;WAIT_MAC
		0xE0000400,  //90 SETBITS ld_samples
		0x80113030,  //91 WAIT cc = neurons_valid wr_addr = 0x03 mem_we = both wr_data_sel = neurons

		//! ;ADD_		WRITE 0x00->0x00 (o_NEURON), READ 0x00->0x00 (o_NEURON), READ 0x03->0x03 (o_MATMUL_OUT)
		0x00000000,  //92 NOP rd_addr = 0x00
		0xE0008003,  //93 SETBITS use32 rd_addr = 0x03
		0x00001000,  //94 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 0
		0x00002800,  //95 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = odd	 in_sel = 1 sign_extend = 0

		//! ;WR_REG
		0x68000000,  //96 WRREG  0x10 0x00

		//! ;ADD_		WRITE 0x0F->0x12 (o_BIAS_CONV), READ 0x05->0x05 (i_BIAS), READ 0x00->0x00 (o_NEURON)
		0x00000005,  //97 NOP rd_addr = 0x05
		0xE0008000,  //98 SETBITS use32 rd_addr = 0x00
		0x000010F5,  //99 NOP rd_addr = 0x05 alu_sel = add wr_addr = 0x0F wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 0
		0x000028F0,  //9a NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x0F wr_data_sel = alu mem_we = odd	 in_sel = 1 sign_extend = 0

		//! ;INC_REG
		0x97F00000,  //9b INCREG  0x0F  cc = always
		0x99700000,  //9c INCREG 18 cc = always
		0x99700000,  //9d INCREG 18 cc = always

		//! ;ZERO_REG_
		0x00000000,  //9e NOP rd_addr = 0x00
		0x00000000,  //9f NOP rd_addr = 0x00
		0x00005000,  //a0 NOP rd_addr = 0x00 alu_sel = sub wr_addr = 0x00 wr_data_sel = alu mem_we = even
		0x00006800,  //a1 NOP rd_addr = 0x00 alu_sel = sub wr_addr = 0x00 wr_data_sel = alu mem_we = odd  in_sel = 1

		//! ;LOOP_C
		0x20700000,  //a2 LOOPC cc = always
		0x00000000,  //a3 NOP
		0xE2000000,  //a4 SETBITS intr_out
		0x30700000,  //a5 JUMP 0 cc = always
//! FOOTER INFORMATION


	},
	{
//! BATCH_3:  C:\AmbientScientific\setup\chip\fw\applications\i2s-tmbuffer-aon-alexa-ww-cnn\test\temp\GC_07_08_2026_12_53_55\Batch3.hex.gpx
//! HEADER INFORMATION  OR STRUCTURE NAME OR  SECTION INFORMATION
		0x00000000,  //a6 NOP
		0xE0000100,  //a7 SETBITS sel_oclk rd_addr = 0x00 

		//! ;SETBUFF
		0xD0000080,  //a8 SETBUFF outbuff = 8

		//! ;WRIREG_ALL
		0x68000000,  //a9 WRREG 16 0x0
		0x68800020,  //aa WRREG 17 0x20
		0x69000000,  //ab WRREG 18 0x0
		0x60000000,  //ac WRREG 0x0 0x0		; o_NEURON
		0x60800001,  //ad WRREG 0x1 0x1		; o_BIAS_NEURON
		0x61000002,  //ae WRREG 0x2 0x2		; o_DENSE_OUT
		0x61800003,  //af WRREG 0x3 0x3		; o_MATMUL_OUT
		0x62000004,  //b0 WRREG 0x4 0x4		; PREG_RESERVED_FOR_S3_ZEROXBAR
		0x62800005,  //b1 WRREG 0x5 0x5		; i_BIAS
		0x67800012,  //b2 WRREG 0xf 0x12		; o_BIAS_CONV

		//! ;LOOP_ST_2
		0x12000000,  //b3 LOOPST  0x02

		//! ;WAIT_MAC
		0xE0000400,  //b4 SETBITS ld_samples
		0x80113030,  //b5 WAIT cc = neurons_valid wr_addr = 0x03 mem_we = both wr_data_sel = neurons

		//! ;ADD_		WRITE 0x00->0x00 (o_NEURON), READ 0x00->0x00 (o_NEURON), READ 0x03->0x03 (o_MATMUL_OUT)
		0x00000000,  //b6 NOP rd_addr = 0x00
		0xE0008003,  //b7 SETBITS use32 rd_addr = 0x03
		0x00001000,  //b8 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 0
		0x00002800,  //b9 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = odd	 in_sel = 1 sign_extend = 0
		0x98700000,  //ba INCREG 16 cc = always
		0x99700000,  //bb INCREG 18 cc = always
		0x99700000,  //bc INCREG 18 cc = always

		//! ;WAIT_MAC
		0xE0000400,  //bd SETBITS ld_samples
		0x80113030,  //be WAIT cc = neurons_valid wr_addr = 0x03 mem_we = both wr_data_sel = neurons

		//! ;ADD_		WRITE 0x00->0x00 (o_NEURON), READ 0x00->0x00 (o_NEURON), READ 0x03->0x03 (o_MATMUL_OUT)
		0x00000000,  //bf NOP rd_addr = 0x00
		0xE0008003,  //c0 SETBITS use32 rd_addr = 0x03
		0x00001000,  //c1 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 0
		0x00002800,  //c2 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = odd	 in_sel = 1 sign_extend = 0
		0x98700000,  //c3 INCREG 16 cc = always
		0x99700000,  //c4 INCREG 18 cc = always
		0x99700000,  //c5 INCREG 18 cc = always

		//! ;WAIT_MAC
		0xE0000400,  //c6 SETBITS ld_samples
		0x80113030,  //c7 WAIT cc = neurons_valid wr_addr = 0x03 mem_we = both wr_data_sel = neurons

		//! ;ADD_		WRITE 0x00->0x00 (o_NEURON), READ 0x00->0x00 (o_NEURON), READ 0x03->0x03 (o_MATMUL_OUT)
		0x00000000,  //c8 NOP rd_addr = 0x00
		0xE0008003,  //c9 SETBITS use32 rd_addr = 0x03
		0x00001000,  //ca NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 0
		0x00002800,  //cb NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = odd	 in_sel = 1 sign_extend = 0
		0x98700000,  //cc INCREG 16 cc = always
		0x99700000,  //cd INCREG 18 cc = always
		0x99700000,  //ce INCREG 18 cc = always

		//! ;WAIT_MAC
		0xE0000400,  //cf SETBITS ld_samples
		0x80113030,  //d0 WAIT cc = neurons_valid wr_addr = 0x03 mem_we = both wr_data_sel = neurons

		//! ;ADD_		WRITE 0x00->0x00 (o_NEURON), READ 0x00->0x00 (o_NEURON), READ 0x03->0x03 (o_MATMUL_OUT)
		0x00000000,  //d1 NOP rd_addr = 0x00
		0xE0008003,  //d2 SETBITS use32 rd_addr = 0x03
		0x00001000,  //d3 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 0
		0x00002800,  //d4 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = odd	 in_sel = 1 sign_extend = 0
		0x98700000,  //d5 INCREG 16 cc = always
		0x99700000,  //d6 INCREG 18 cc = always
		0x99700000,  //d7 INCREG 18 cc = always

		//! ;WAIT_MAC
		0xE0000400,  //d8 SETBITS ld_samples
		0x80113030,  //d9 WAIT cc = neurons_valid wr_addr = 0x03 mem_we = both wr_data_sel = neurons

		//! ;ADD_		WRITE 0x00->0x00 (o_NEURON), READ 0x00->0x00 (o_NEURON), READ 0x03->0x03 (o_MATMUL_OUT)
		0x00000000,  //da NOP rd_addr = 0x00
		0xE0008003,  //db SETBITS use32 rd_addr = 0x03
		0x00001000,  //dc NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 0
		0x00002800,  //dd NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = odd	 in_sel = 1 sign_extend = 0
		0x98700000,  //de INCREG 16 cc = always
		0x99700000,  //df INCREG 18 cc = always
		0x99700000,  //e0 INCREG 18 cc = always

		//! ;WAIT_MAC
		0xE0000400,  //e1 SETBITS ld_samples
		0x80113030,  //e2 WAIT cc = neurons_valid wr_addr = 0x03 mem_we = both wr_data_sel = neurons

		//! ;ADD_		WRITE 0x00->0x00 (o_NEURON), READ 0x00->0x00 (o_NEURON), READ 0x03->0x03 (o_MATMUL_OUT)
		0x00000000,  //e3 NOP rd_addr = 0x00
		0xE0008003,  //e4 SETBITS use32 rd_addr = 0x03
		0x00001000,  //e5 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 0
		0x00002800,  //e6 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = odd	 in_sel = 1 sign_extend = 0

		//! ;WR_REG
		0x68000000,  //e7 WRREG  0x10 0x00

		//! ;ADD_		WRITE 0x0F->0x12 (o_BIAS_CONV), READ 0x05->0x05 (i_BIAS), READ 0x00->0x00 (o_NEURON)
		0x00000005,  //e8 NOP rd_addr = 0x05
		0xE0008000,  //e9 SETBITS use32 rd_addr = 0x00
		0x000010F5,  //ea NOP rd_addr = 0x05 alu_sel = add wr_addr = 0x0F wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 0
		0x000028F0,  //eb NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x0F wr_data_sel = alu mem_we = odd	 in_sel = 1 sign_extend = 0

		//! ;INC_REG
		0x97F00000,  //ec INCREG  0x0F  cc = always
		0x99700000,  //ed INCREG 18 cc = always
		0x99700000,  //ee INCREG 18 cc = always

		//! ;ZERO_REG_
		0x00000000,  //ef NOP rd_addr = 0x00
		0x00000000,  //f0 NOP rd_addr = 0x00
		0x00005000,  //f1 NOP rd_addr = 0x00 alu_sel = sub wr_addr = 0x00 wr_data_sel = alu mem_we = even
		0x00006800,  //f2 NOP rd_addr = 0x00 alu_sel = sub wr_addr = 0x00 wr_data_sel = alu mem_we = odd  in_sel = 1

		//! ;LOOP_C
		0x20700000,  //f3 LOOPC cc = always
		0x00000000,  //f4 NOP
		0xE2000000,  //f5 SETBITS intr_out
		0x30700000,  //f6 JUMP 0 cc = always
//! FOOTER INFORMATION


	},
	{
//! BATCH_4:  C:\AmbientScientific\setup\chip\fw\applications\i2s-tmbuffer-aon-alexa-ww-cnn\test\temp\GC_07_08_2026_12_53_55\Batch4.hex.gpx
//! HEADER INFORMATION  OR STRUCTURE NAME OR  SECTION INFORMATION
		0x00000000,  //f7 NOP
		0xE0000100,  //f8 SETBITS sel_oclk rd_addr = 0x00 

		//! ;SETBUFF
		0xD0000080,  //f9 SETBUFF outbuff = 8

		//! ;WRIREG_ALL
		0x68000000,  //fa WRREG 16 0x0
		0x68800020,  //fb WRREG 17 0x20
		0x69000000,  //fc WRREG 18 0x0
		0x60000000,  //fd WRREG 0x0 0x0		; o_NEURON
		0x60800001,  //fe WRREG 0x1 0x1		; o_BIAS_NEURON
		0x61000002,  //ff WRREG 0x2 0x2		; o_DENSE_OUT
		0x61800003,  //100 WRREG 0x3 0x3		; o_MATMUL_OUT
		0x62000004,  //101 WRREG 0x4 0x4		; PREG_RESERVED_FOR_S3_ZEROXBAR
		0x62800005,  //102 WRREG 0x5 0x5		; i_BIAS
		0x67800012,  //103 WRREG 0xf 0x12		; o_BIAS_CONV

		//! ;WAIT_MAC
		0xE0000400,  //104 SETBITS ld_samples
		0x80113030,  //105 WAIT cc = neurons_valid wr_addr = 0x03 mem_we = both wr_data_sel = neurons

		//! ;ADD_		WRITE 0x00->0x00 (o_NEURON), READ 0x00->0x00 (o_NEURON), READ 0x03->0x03 (o_MATMUL_OUT)
		0x00000000,  //106 NOP rd_addr = 0x00
		0xE0008003,  //107 SETBITS use32 rd_addr = 0x03
		0x00001000,  //108 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 0
		0x00002800,  //109 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = odd	 in_sel = 1 sign_extend = 0
		0x98700000,  //10a INCREG 16 cc = always
		0x99700000,  //10b INCREG 18 cc = always
		0x99700000,  //10c INCREG 18 cc = always

		//! ;WAIT_MAC
		0xE0000400,  //10d SETBITS ld_samples
		0x80113030,  //10e WAIT cc = neurons_valid wr_addr = 0x03 mem_we = both wr_data_sel = neurons

		//! ;ADD_		WRITE 0x00->0x00 (o_NEURON), READ 0x00->0x00 (o_NEURON), READ 0x03->0x03 (o_MATMUL_OUT)
		0x00000000,  //10f NOP rd_addr = 0x00
		0xE0008003,  //110 SETBITS use32 rd_addr = 0x03
		0x00001000,  //111 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 0
		0x00002800,  //112 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = odd	 in_sel = 1 sign_extend = 0
		0x98700000,  //113 INCREG 16 cc = always
		0x99700000,  //114 INCREG 18 cc = always
		0x99700000,  //115 INCREG 18 cc = always

		//! ;WAIT_MAC
		0xE0000400,  //116 SETBITS ld_samples
		0x80113030,  //117 WAIT cc = neurons_valid wr_addr = 0x03 mem_we = both wr_data_sel = neurons

		//! ;ADD_		WRITE 0x00->0x00 (o_NEURON), READ 0x00->0x00 (o_NEURON), READ 0x03->0x03 (o_MATMUL_OUT)
		0x00000000,  //118 NOP rd_addr = 0x00
		0xE0008003,  //119 SETBITS use32 rd_addr = 0x03
		0x00001000,  //11a NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 0
		0x00002800,  //11b NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = odd	 in_sel = 1 sign_extend = 0
		0x98700000,  //11c INCREG 16 cc = always
		0x99700000,  //11d INCREG 18 cc = always
		0x99700000,  //11e INCREG 18 cc = always

		//! ;WAIT_MAC
		0xE0000400,  //11f SETBITS ld_samples
		0x80113030,  //120 WAIT cc = neurons_valid wr_addr = 0x03 mem_we = both wr_data_sel = neurons

		//! ;ADD_		WRITE 0x00->0x00 (o_NEURON), READ 0x00->0x00 (o_NEURON), READ 0x03->0x03 (o_MATMUL_OUT)
		0x00000000,  //121 NOP rd_addr = 0x00
		0xE0008003,  //122 SETBITS use32 rd_addr = 0x03
		0x00001000,  //123 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 0
		0x00002800,  //124 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = odd	 in_sel = 1 sign_extend = 0
		0x98700000,  //125 INCREG 16 cc = always
		0x99700000,  //126 INCREG 18 cc = always
		0x99700000,  //127 INCREG 18 cc = always

		//! ;WAIT_MAC
		0xE0000400,  //128 SETBITS ld_samples
		0x80113030,  //129 WAIT cc = neurons_valid wr_addr = 0x03 mem_we = both wr_data_sel = neurons

		//! ;ADD_		WRITE 0x00->0x00 (o_NEURON), READ 0x00->0x00 (o_NEURON), READ 0x03->0x03 (o_MATMUL_OUT)
		0x00000000,  //12a NOP rd_addr = 0x00
		0xE0008003,  //12b SETBITS use32 rd_addr = 0x03
		0x00001000,  //12c NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 0
		0x00002800,  //12d NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = odd	 in_sel = 1 sign_extend = 0
		0x98700000,  //12e INCREG 16 cc = always
		0x99700000,  //12f INCREG 18 cc = always
		0x99700000,  //130 INCREG 18 cc = always

		//! ;WAIT_MAC
		0xE0000400,  //131 SETBITS ld_samples
		0x80113030,  //132 WAIT cc = neurons_valid wr_addr = 0x03 mem_we = both wr_data_sel = neurons

		//! ;ADD_		WRITE 0x00->0x00 (o_NEURON), READ 0x00->0x00 (o_NEURON), READ 0x03->0x03 (o_MATMUL_OUT)
		0x00000000,  //133 NOP rd_addr = 0x00
		0xE0008003,  //134 SETBITS use32 rd_addr = 0x03
		0x00001000,  //135 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 0
		0x00002800,  //136 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = odd	 in_sel = 1 sign_extend = 0

		//! ;WR_REG
		0x69000000,  //137 WRREG  0x12 0x00

		//! ;ADD_		WRITE 0x00->0x00 (o_NEURON), READ 0x05->0x05 (i_BIAS), READ 0x00->0x00 (o_NEURON)
		0x00000005,  //138 NOP rd_addr = 0x05
		0xE0008000,  //139 SETBITS use32 rd_addr = 0x00
		0x00001005,  //13a NOP rd_addr = 0x05 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 0
		0x00002800,  //13b NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = odd	 in_sel = 1 sign_extend = 0
		0x98700000,  //13c INCREG 16 cc = always

		//! ;INC_REG
		0x92F00000,  //13d INCREG  0x05  cc = always
		0x00000000,  //13e NOP
		0xE2000000,  //13f SETBITS intr_out
		0x30700000,  //140 JUMP 0 cc = always
//! FOOTER INFORMATION


	},
	{
//! BATCH_5:  C:\AmbientScientific\setup\chip\fw\applications\i2s-tmbuffer-aon-alexa-ww-cnn\test\temp\GC_07_08_2026_12_53_55\Batch5.hex.gpx
//! HEADER INFORMATION  OR STRUCTURE NAME OR  SECTION INFORMATION
		0x00000000,  //141 NOP
		0xE0000100,  //142 SETBITS sel_oclk rd_addr = 0x00 

		//! ;SETBUFF
		0xD0000080,  //143 SETBUFF outbuff = 8

		//! ;WRIREG_ALL
		0x68000000,  //144 WRREG 16 0x0
		0x68800020,  //145 WRREG 17 0x20
		0x69000000,  //146 WRREG 18 0x0
		0x60000000,  //147 WRREG 0x0 0x0		; o_NEURON
		0x60800001,  //148 WRREG 0x1 0x1		; o_BIAS_NEURON
		0x61000002,  //149 WRREG 0x2 0x2		; o_DENSE_OUT
		0x61800003,  //14a WRREG 0x3 0x3		; o_MATMUL_OUT
		0x62000004,  //14b WRREG 0x4 0x4		; PREG_RESERVED_FOR_S3_ZEROXBAR
		0x62800005,  //14c WRREG 0x5 0x5		; i_BIAS
		0x67800012,  //14d WRREG 0xf 0x12		; o_BIAS_CONV

		//! ;WAIT_MAC
		0xE0000400,  //14e SETBITS ld_samples
		0x80113030,  //14f WAIT cc = neurons_valid wr_addr = 0x03 mem_we = both wr_data_sel = neurons

		//! ;ADD_		WRITE 0x00->0x00 (o_NEURON), READ 0x00->0x00 (o_NEURON), READ 0x03->0x03 (o_MATMUL_OUT)
		0x00000000,  //150 NOP rd_addr = 0x00
		0xE0008003,  //151 SETBITS use32 rd_addr = 0x03
		0x00001000,  //152 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 0
		0x00002800,  //153 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = odd	 in_sel = 1 sign_extend = 0
		0x98700000,  //154 INCREG 16 cc = always
		0x99700000,  //155 INCREG 18 cc = always
		0x99700000,  //156 INCREG 18 cc = always

		//! ;WAIT_MAC
		0xE0000400,  //157 SETBITS ld_samples
		0x80113030,  //158 WAIT cc = neurons_valid wr_addr = 0x03 mem_we = both wr_data_sel = neurons

		//! ;ADD_		WRITE 0x00->0x00 (o_NEURON), READ 0x00->0x00 (o_NEURON), READ 0x03->0x03 (o_MATMUL_OUT)
		0x00000000,  //159 NOP rd_addr = 0x00
		0xE0008003,  //15a SETBITS use32 rd_addr = 0x03
		0x00001000,  //15b NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 0
		0x00002800,  //15c NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = odd	 in_sel = 1 sign_extend = 0
		0x98700000,  //15d INCREG 16 cc = always
		0x99700000,  //15e INCREG 18 cc = always
		0x99700000,  //15f INCREG 18 cc = always

		//! ;WAIT_MAC
		0xE0000400,  //160 SETBITS ld_samples
		0x80113030,  //161 WAIT cc = neurons_valid wr_addr = 0x03 mem_we = both wr_data_sel = neurons

		//! ;ADD_		WRITE 0x00->0x00 (o_NEURON), READ 0x00->0x00 (o_NEURON), READ 0x03->0x03 (o_MATMUL_OUT)
		0x00000000,  //162 NOP rd_addr = 0x00
		0xE0008003,  //163 SETBITS use32 rd_addr = 0x03
		0x00001000,  //164 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 0
		0x00002800,  //165 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = odd	 in_sel = 1 sign_extend = 0
		0x98700000,  //166 INCREG 16 cc = always
		0x99700000,  //167 INCREG 18 cc = always
		0x99700000,  //168 INCREG 18 cc = always

		//! ;WAIT_MAC
		0xE0000400,  //169 SETBITS ld_samples
		0x80113030,  //16a WAIT cc = neurons_valid wr_addr = 0x03 mem_we = both wr_data_sel = neurons

		//! ;ADD_		WRITE 0x00->0x00 (o_NEURON), READ 0x00->0x00 (o_NEURON), READ 0x03->0x03 (o_MATMUL_OUT)
		0x00000000,  //16b NOP rd_addr = 0x00
		0xE0008003,  //16c SETBITS use32 rd_addr = 0x03
		0x00001000,  //16d NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 0
		0x00002800,  //16e NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = odd	 in_sel = 1 sign_extend = 0
		0x98700000,  //16f INCREG 16 cc = always
		0x99700000,  //170 INCREG 18 cc = always
		0x99700000,  //171 INCREG 18 cc = always

		//! ;WAIT_MAC
		0xE0000400,  //172 SETBITS ld_samples
		0x80113030,  //173 WAIT cc = neurons_valid wr_addr = 0x03 mem_we = both wr_data_sel = neurons

		//! ;ADD_		WRITE 0x00->0x00 (o_NEURON), READ 0x00->0x00 (o_NEURON), READ 0x03->0x03 (o_MATMUL_OUT)
		0x00000000,  //174 NOP rd_addr = 0x00
		0xE0008003,  //175 SETBITS use32 rd_addr = 0x03
		0x00001000,  //176 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 0
		0x00002800,  //177 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = odd	 in_sel = 1 sign_extend = 0
		0x98700000,  //178 INCREG 16 cc = always
		0x99700000,  //179 INCREG 18 cc = always
		0x99700000,  //17a INCREG 18 cc = always

		//! ;WAIT_MAC
		0xE0000400,  //17b SETBITS ld_samples
		0x80113030,  //17c WAIT cc = neurons_valid wr_addr = 0x03 mem_we = both wr_data_sel = neurons

		//! ;ADD_		WRITE 0x00->0x00 (o_NEURON), READ 0x00->0x00 (o_NEURON), READ 0x03->0x03 (o_MATMUL_OUT)
		0x00000000,  //17d NOP rd_addr = 0x00
		0xE0008003,  //17e SETBITS use32 rd_addr = 0x03
		0x00001000,  //17f NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 0
		0x00002800,  //180 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = odd	 in_sel = 1 sign_extend = 0

		//! ;WR_REG
		0x69000000,  //181 WRREG  0x12 0x00

		//! ;ADD_		WRITE 0x00->0x00 (o_NEURON), READ 0x05->0x05 (i_BIAS), READ 0x00->0x00 (o_NEURON)
		0x00000005,  //182 NOP rd_addr = 0x05
		0xE0008000,  //183 SETBITS use32 rd_addr = 0x00
		0x00001005,  //184 NOP rd_addr = 0x05 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 0
		0x00002800,  //185 NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = odd	 in_sel = 1 sign_extend = 0
		0x98700000,  //186 INCREG 16 cc = always

		//! ;INC_REG
		0x92F00000,  //187 INCREG  0x05  cc = always
		0x00000000,  //188 NOP
		0xE2000000,  //189 SETBITS intr_out
		0x30700000,  //18a JUMP 0 cc = always
//! FOOTER INFORMATION


	},
	{
//! BATCH_6:  C:\AmbientScientific\setup\chip\fw\applications\i2s-tmbuffer-aon-alexa-ww-cnn\test\temp\GC_07_08_2026_12_53_55\Batch6.hex.gpx
//! HEADER INFORMATION  OR STRUCTURE NAME OR  SECTION INFORMATION
		0x00000000,  //18b NOP
		0xE0000100,  //18c SETBITS sel_oclk rd_addr = 0x00 

		//! ;SETBUFF
		0xD0000080,  //18d SETBUFF outbuff = 8

		//! ;WRIREG_ALL
		0x68000000,  //18e WRREG 16 0x0
		0x68800020,  //18f WRREG 17 0x20
		0x69000000,  //190 WRREG 18 0x0
		0x60000000,  //191 WRREG 0x0 0x0		; o_NEURON
		0x60800001,  //192 WRREG 0x1 0x1		; o_BIAS_NEURON
		0x61000002,  //193 WRREG 0x2 0x2		; o_DENSE_OUT
		0x61800003,  //194 WRREG 0x3 0x3		; o_MATMUL_OUT
		0x62000004,  //195 WRREG 0x4 0x4		; PREG_RESERVED_FOR_S3_ZEROXBAR
		0x62800005,  //196 WRREG 0x5 0x5		; i_BIAS
		0x67800012,  //197 WRREG 0xf 0x12		; o_BIAS_CONV

		//! ;WAIT_MAC
		0xE0000400,  //198 SETBITS ld_samples
		0x80113000,  //199 WAIT cc = neurons_valid wr_addr = 0x00 mem_we = both wr_data_sel = neurons

		//! ;ADD_		WRITE 0x00->0x00 (o_NEURON), READ 0x05->0x05 (i_BIAS), READ 0x00->0x00 (o_NEURON)
		0x00000005,  //19a NOP rd_addr = 0x05
		0xE0008000,  //19b SETBITS use32 rd_addr = 0x00
		0x00001005,  //19c NOP rd_addr = 0x05 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = even in_sel = 0 sign_extend = 0
		0x00002800,  //19d NOP rd_addr = 0x00 alu_sel = add wr_addr = 0x00 wr_data_sel = alu mem_we = odd	 in_sel = 1 sign_extend = 0
		0x00000000,  //19e NOP
		0xE2000000,  //19f SETBITS intr_out
		0x30700000,  //1a0 JUMP 0 cc = always
//! FOOTER INFORMATION


	},
};

#endif
