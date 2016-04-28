#include <bta_dev.h>
#include <stdint.h>
#include <stdio.h>
#include "log.h"

const char *host_name = "mteetester";
const BTA_UUID bta_uuid = { 0x01020304, 0x0506, 0x0708, { 0x99, 0x0A, 0x0B,
		0x0C, 0x0D, 0x0E, 0x0F, 0x10 } };
char* inputStr = "hello,I'm a gptee client.";
char* outputStr = "got your msg.";
TEE_Result TA_EXPORT TA_CreateEntryPoint( void )
{
	ENTER_FUNC
	LEAVE_FUNC
    return 0;
}

void TA_EXPORT TA_DestroyEntryPoint( void )
{
	ENTER_FUNC
	LEAVE_FUNC
}


TEE_Result TA_EXPORT TA_OpenSessionEntryPoint(
        uint32_t paramTypes,
        /*[inout]*/ TEE_Param params[4],
        /*[out][ctx] */void** sessionContext )
{
	ENTER_FUNC
	LEAVE_FUNC
	return 0;
}


TEE_Result TA_EXPORT TA_InvokeCommandEntryPoint(
        /*[ctx]*/ void* sessionContext,
        uint32_t commandID,
        uint32_t paramTypes,
        /*[inout]*/ TEE_Param params[4] )
{
	ENTER_FUNC
	TEE_Param inputParam = params[0];
	TEE_Param outputParam = params[1];
	if(strcmp(inputStr,(char*)inputParam.memref.buffer) == 0) {
		LOG_INFO("equal");
		strcpy((char*)outputParam.memref.buffer,outputStr);
	}
	else {
		strcpy((char*)outputParam.memref.buffer,"not equal");
	}
	LEAVE_FUNC
  	return 0;
}


void TA_EXPORT TA_CloseSessionEntryPoint(/*[ctx]*/ void* sessionContext)
{
	ENTER_FUNC
	LEAVE_FUNC
}
