/*******************************************************************************
* (C) Copyright 2021;  Ambient Scientific India Pvt Ltd, Bangalore
* The attached material and the information contained therein is proprietary
* to Ambient Scientific India Pvt Ltd and is issued only under strict confidentiality
* arrangements.It shall not be used, reproduced, copied in whole or in part,
* adapted,modified, or disseminated without a written license of Ambient Scientific
* India Pvt Ltd.It must be returned to Ambient Scientific India Pvt Ltd upon its first
* request.
*
*  File Name           : gc_sensor_data_producer.h
*
*  Description         : This file defines GPIO driver function declarations
*
*  Change history      :
*
*     Author        	  Date           Ver                 Description
*  ------------    		--------         ---   			---------------------
* Ambient Scientific  6th Apr 2026       1.1               Initial Creation
*
*******************************************************************************/
#ifndef GC_SENSOR_DATA_PRODUCER_H
#define GC_SENSOR_DATA_PRODUCER_H

/*******************************************************************************
*                          Include Files
*******************************************************************************/
#include "data_types.h"

/*******************************************************************************
*                          C++ Declaration Wrapper
*******************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif


/*******************************************************************************
*                          Type & Macro Declarations
*******************************************************************************/


/*******************************************************************************
*                          Type Declarations
*******************************************************************************/

typedef struct GPX_SENSOR_DATA_TAG
{
	U32* sensor_data;
	U32 counter;

}t_GPX_SENSOR_DATA;

/*******************************************************************************
*                          Extern Data Declarations
*******************************************************************************/

/*******************************************************************************
*                          Extern Function Prototypes
*******************************************************************************/


#endif /* GC_SENSOR_DATA_PRODUCER_H */
/*******************************************************************************
*                          End of File
*******************************************************************************/
