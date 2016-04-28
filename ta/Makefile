build:
	@make -f Makefile-fp.mk
	@make -f Makefile-gptee.mk
	@echo "ta build finished !!"


clean:
	@-rm -rf obj
	@echo "ta clean finished !!"



install:
	adb root
	adb wait-for-device
	adb remount
	adb push obj/fp_ta /system/thh/fp_server
	adb push obj/fp_ta /data/thh/tee_05/tee
	@adb push obj/gptee_ta /data/thh/tee_02/tee
	@echo "ta install finished !!"



all:clean build install
