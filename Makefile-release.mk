

install:backup
	adb root
	adb wait-for-device
	adb remount
	adb push tee_env_checker /system/bin
	adb push libmtee.so /system/lib/libmtee.so
	adb push fp_ta /system/thh/fp_server
	adb push fp_ta /data/thh/tee_05/tee
	adb push gptee_ta /data/thh/tee_02/tee
	echo "install finished !!"


backup:
	@-rm -rf backup
	@-mkdir backup
	adb root
	adb wait-for-device
	adb remount
	-adb pull /system/lib/libmtee.so  backup/
	-adb pull /system/thh/fp_server backup/fp_ta
	-adb pull  /data/thh/tee_02/tee backup/gptee_ta
	echo "backup finished !!"



restore:
	adb root
	adb wait-for-device
	adb remount
	-adb shell rm -f /system/bin/tee_env_checker
	-adb push backup/libmtee.so /system/lib/libmtee.so
	-adb push backup/fp_ta /system/thh/fp_server
	-adb push backup/fp_ta /data/thh/tee_05/tee
	-adb push backup/gptee_ta /data/thh/tee_02/tee
	echo "restore finished !!"
