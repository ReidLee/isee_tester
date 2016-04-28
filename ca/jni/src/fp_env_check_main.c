#include "stdio.h"
#include <string.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#include "log.h"
#include "common.h"


int ut_fp_entry_fd = 0;

int fp_env_check_main() {
    ENTER_FUNC
    char* inputStr = "hello , I'm a fp client .";
	char* outputStr = "got your msg .";
    if (ut_fp_entry_fd == 0) {
			ut_fp_entry_fd = open(UT_FP_ENTRY_IOCTL_DEVICE, O_RDWR);
	}


    uint8_t* data_buff = my_malloc(IOCTL_BUFFER_SIZE,0);
    memset(data_buff, 0 , IOCTL_BUFFER_SIZE);
    write16(data_buff+12,strlen(inputStr) + 1);
    strcpy(data_buff+16,inputStr);

    int ioresult = ioctl(ut_fp_entry_fd, UT_FP_ENTRY_IOCTL_MAGIC_NO, data_buff);
    char* output = (char*)(data_buff+16);
    if(ioresult == 0){
        if(strcmp(outputStr,output) == 0 ){
            LOG_SUCCESS("fp env checked ,ok !!!");
        }
        else {
            LOG_ERROR("fp env checked , not ok , data_buff = %s ",output);
        }
    }
    else {
        LOG_ERROR("fp env checked , not ok  , result = 0x%08x",ioresult);
    }

    LEAVE_FUNC
    return ioresult;
}
