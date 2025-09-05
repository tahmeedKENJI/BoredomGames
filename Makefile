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
ifeq (${GAME}, game_1)
	@echo Compilation started
	@g++ ${GAME_DIR}/${GAME}.cpp ${GAME_DIR}/dependencies.h -o ${GAME}.o
else ifeq (${GAME}, game_2)
	@echo Compilation started
	@g++ ${GAME_DIR}/${GAME}.cpp ${GAME_DIR}/dependencies.h -o ${GAME}.o -lvulkan -lglfw
endif

run: compile
	@echo Starting game...
	@./${GAME}.o

.PHONY: clean

