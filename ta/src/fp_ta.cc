#include "stdio.h"
#include <string.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include "fp_server.h"

#include "log.h"
#include "common.h"
// EXTERNC int fp_main(void);


EXTERNC_BEGIN

void init_main(){
	ENTER_FUNC
	LEAVE_FUNC
}

int main(int argc,char** argv) {
	ENTER_FUNC
	fp_main();
	LEAVE_FUNC
	return 0;
}

//ut_fp_invokeCommand
//teei_fp_invokeCommand
int teei_fp_invokeCommand(void* param, void*  data,
		uint32_t param_length) {
	ENTER_FUNC
	char* inputStr = "hello , I'm a fp client .";
	char* outputStr = "got your msg .";
	char* outputData = (char*)data;
	LOG_INFO("param_length = %d",param_length);
	LOG_INFO("**** -param- ****");
	LOG_INFO("data = %s",data);
	if(strcmp(inputStr,(char*)data) == 0) {
		strcpy((char*)outputData,outputStr);
	}
	else {
		strcpy((char*)outputData,"error");
	}
	LEAVE_FUNC
	return 0;
}
EXTERNC_END
