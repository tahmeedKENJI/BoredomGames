GAME_DIR := ${shell pwd}/games/

debug:
	@echo ${GAME_DIR}
	@echo ${GAME}

${GAME}.cpp:
	@cat ${GAME_DIR}/${GAME}.cpp >> /dev/null

clean:
	@clear
	@echo Cleaning generated files
	@rm -rf *.o

compile: clean ${GAME}.cpp
	@echo Compilation started
	@g++ ${GAME_DIR}/${GAME}.cpp ${GAME_DIR}/dependencies.h -o ${GAME}.o

run: compile
	@echo Starting game...
	@./${GAME}.o

.PHONY: clean

