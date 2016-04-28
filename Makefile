build:
	@cd ca ; make build
	@cd ta ; make build
	@echo "build finished !!"

clean:
	@cd ca ; make clean
	@cd ta ; make clean
	@-rm -rf tee_env_checker
	@-rm tee_env_checker.zip
	@echo "clean finished !!"

install:
	@cd ca ; make install
	@cd ta ; make install
	@echo "install finished !!"

run:
	@cd ca ; make run


release:
	@-rm -rf tee_env_checker
	@-rm tee_env_checker.zip
	@-mkdir tee_env_checker
	@-cp ca/libs/armeabi/libmtee.so ./tee_env_checker
	@-cp ca/libs/armeabi/tee_env_checker ./tee_env_checker
	@-cp ta/obj/fp_ta  ./tee_env_checker
	@-cp ta/obj/gptee_ta  ./tee_env_checker
	@-cp Makefile-release.mk  ./tee_env_checker/Makefile
	@-cp README-release.md  ./tee_env_checker/README.MD
	@-zip -r tee_env_checker.zip tee_env_checker/

all:clean build install
