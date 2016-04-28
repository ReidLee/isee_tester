build:
	@ndk-build
	@echo "ca build finished !!"


clean:
	@-rm -rf obj
	@-rm -rf libs
	@echo "ca clean finished !!"

install:
	@adb wait-for-device
	@adb remount
	@adb push libs/armeabi/tee_env_checker /system/bin
	@adb push libs/armeabi/libmtee.so /system/lib/libmtee.so
	@echo "ca install finished !!"

run:
	@adb shell tee_env_checker

all:clean build install
