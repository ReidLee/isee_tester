命令：
make
    编译 ca,fp_ta,gptee_ta
make clean
    清除所有生成的文件
make install
    安装　ca, fp_ta ，　gptee_ta
make all
    1.清除所有生成的文件
    ２．编译 ca,fp_ta,gptee_ta
    ３．安装　ca, fp_ta ，　gptee_ta
make run
    运行测试程序，如果测试成功则会出现如下log,如果不成功，会友红色的log　提示．
    [TEE_ENV_CHECKER][YELLOW]main[9]:ENTER main
    [TEE_ENV_CHECKER][INFO]main[10]:ready to check gptee env .

    [TEE_ENV_CHECKER][YELLOW]gptee_env_check_main[23]:ENTER gptee_env_check_main
    [teei_client_api.c-142/TEEC_InitializeContext][I]Init TEE Context ： mteetester
    [teei_client_api.c-143/TEEC_InitializeContext][I]Init TEE Context return value ： 0
    [teei_client_api.c-453/TEEC_OpenSession][D]init session id [2fd54300]
    [TEE_ENV_CHECKER][INFO]gptee_env_check_main[60]:session id 0x004255b8
    [teei_client_api.c-1067/TEEC_InvokeCommand][E]TEEC_InvokeCommand : cancellation support not yet implemented

    [TEE_ENV_CHECKER][SUCCESS]gptee_env_check_main[117]:gptee env checked , ok !!!
    [TEE_ENV_CHECKER][YELLOW]gptee_env_check_main[132]:LEAVE gptee_env_check_main
    [TEE_ENV_CHECKER][INFO]main[12]:ready to check fp env .

    [TEE_ENV_CHECKER][YELLOW]fp_env_check_main[18]:ENTER fp_env_check_main
    [TEE_ENV_CHECKER][YELLOW]my_malloc[10]:ENTER my_malloc
    [TEE_ENV_CHECKER][YELLOW]my_malloc[20]:LEAVE my_malloc
    [TEE_ENV_CHECKER][SUCCESS]fp_env_check_main[35]:fp env checked ,ok !!!
    [TEE_ENV_CHECKER][YELLOW]fp_env_check_main[45]:LEAVE fp_env_check_main
    [TEE_ENV_CHECKER][YELLOW]main[14]:LEAVE main


make release
    打包编译出来的程序，会生成一个压缩包，直接那压缩包发送给客户即可
