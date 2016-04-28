make install
    首先备份手机上可能会被覆盖的文件，安装测试程序


make backup
    对手机上可能会被覆盖的文件进行备份


make restore
    恢复被覆盖的文件



步骤:
    1.运行make install 对手机上的ta进行备份,并且推入测试ta
    2.重启手机,进入adb shell , 运行 tee_env_checker , 如果没有红色字体报错,那么说明tee环境没问题,否则tee 环境有问题 .
    3.运行 make restore 恢复测试前的环境.
