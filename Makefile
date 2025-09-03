ROOT_DIR := ${shell pwd}

debug:
	@echo ${ROOT_DIR}
	@echo ${GAME}

${GAME}.cpp:
	@cat ${ROOT_DIR}/${GAME}.cpp >> /dev/null

clean:
	@clear
	@echo Cleaning generated files
	@rm -rf *.o

compile: clean ${GAME}.cpp
	@echo Compilation started
	@g++ ${GAME}.cpp dependencies.h -o ${GAME}.o

run: compile
	@echo Starting game...
	@./${GAME}.o

.PHONY: clean

