#include <jni.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

#include <tee_client_api.h>
#include "log.h"


const char* host_name = "mteetester";
const TEEC_UUID testTUUID = { 0x01020304, 0x0506, 0x0708, { 0x99, 0x0A, 0x0B,
       0x0C, 0x0D, 0x0E, 0x0F, 0x10 } };


int gptee_env_check_main() {
    ENTER_FUNC
    TEEC_Context context;
    TEEC_Session session;
    TEEC_Operation operation;
    TEEC_SharedMemory inputShareMemory, outputShareMemory;

    TEEC_Result result = -1;
    uint32_t len;
    char* inputStr = "hello,I'm a gptee client.";
    char* outputStr = "got your msg.";
    uint32_t inputShareMemoryLen = strlen(inputStr) + 1;
    uint32_t outputShareMemoryLen = strlen(outputStr) +1;


    result = TEEC_InitializeContext(
               host_name,
               &context);
    if(result != TEEC_SUCCESS) {
        LOG_ERROR("TEEC_InitializeContext failed , result = 0x%08x",result);
        goto cleanup_1;
    }

    memset(&operation, 0, sizeof(operation));
    result = TEEC_OpenSession(
                &context,
                &session,
                &testTUUID,
                TEEC_LOGIN_PUBLIC,
                NULL,
                NULL,
                NULL);

    if(result != TEEC_SUCCESS) {
        LOG_ERROR("TEEC_OpenSession failed , result = 0x%08x",result);
        goto cleanup_2;
    }

    LOG_INFO("session id 0x%08x", session.session_id);


    inputShareMemory.size = inputShareMemoryLen;
    inputShareMemory.flags = 3 ;
    result = TEEC_AllocateSharedMemory(
                &context,
                &inputShareMemory);

    if(result != TEEC_SUCCESS) {
        LOG_ERROR("TEEC_AllocateSharedMemory failed , inputShareMemory  , result = 0x%08x",result);
        goto cleanup_3;
    }


    outputShareMemory.size = outputShareMemoryLen;
    outputShareMemory.flags = 3 ;

    result = TEEC_AllocateSharedMemory(
                &context,
                &outputShareMemory);

    if(result != TEEC_SUCCESS) {
        LOG_ERROR("TEEC_AllocateSharedMemory failed , outputShareMemory , result = 0x%08x",result);
        goto cleanup_4;
    }

    strcpy(inputShareMemory.buffer,inputStr);


    operation.paramTypes = TEEC_PARAM_TYPES(
                                        TEEC_MEMREF_PARTIAL_INPUT,
                            			TEEC_MEMREF_PARTIAL_INOUT,
                                        TEEC_VALUE_OUTPUT,
                                        TEEC_NONE);

    operation.params[0].memref.parent = &inputShareMemory;
    operation.params[0].memref.offset = 0;
    operation.params[0].memref.size = inputShareMemoryLen;

    operation.params[1].memref.parent = &outputShareMemory;
    operation.params[1].memref.offset = 0;
    operation.params[1].memref.size = outputShareMemoryLen;


    result = TEEC_InvokeCommand(
                 &session,
                 0,
                 &operation,
                 NULL);

    if (result != TEEC_SUCCESS)
    {
        LOG_ERROR("TEEC_InvokeCommand failed ,  result = 0x%08x",result);
        goto cleanup_5;
    }
    if(strcmp(outputShareMemory.buffer,outputStr) == 0) {
        LOG_SUCCESS("gptee env checked , ok !!!");
    }
    else {
        LOG_ERROR("got a wrong message : %s",outputShareMemory.buffer);
    }

cleanup_5:
    TEEC_ReleaseSharedMemory(&outputShareMemory);
cleanup_4:
    TEEC_ReleaseSharedMemory(&inputShareMemory);
cleanup_3:
    TEEC_CloseSession(&session);
cleanup_2:
    TEEC_FinalizeContext(&context);
cleanup_1:
    LEAVE_FUNC
    return 0;

}
