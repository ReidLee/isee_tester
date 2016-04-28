#include "stdio.h"
#include "log.h"


extern int gptee_env_check_main();
extern int fp_env_check_main();

int main(int argc,char** argv) {
    ENTER_FUNC
    LOG_INFO("ready to check gptee env .\n");
    gptee_env_check_main();
    LOG_INFO("ready to check fp env .\n");
    fp_env_check_main();
    LEAVE_FUNC
    return 0;
}
