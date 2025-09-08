ROOT_DIR := ${shell pwd}
GAME_1_DIR := ${ROOT_DIR}/game_1
GAME_2_DIR := ${ROOT_DIR}/game_2

debug:
	@echo ${GAME_1_DIR}
	@echo ${GAME_2_DIR}
	@echo ${GAME}

${GAME}.cpp:
ifeq (${GAME}, game_1)
	@cat ${GAME_1_DIR}/${GAME}.cpp >> /dev/null
else ifeq (${GAME}, game_2)
	@cat ${GAME_2_DIR}/${GAME}.cpp >> /dev/null
endif

clean:
	@clear
	@echo Cleaning generated files
	@rm -rf *.o

compile: clean ${GAME}.cpp
ifeq (${GAME}, game_1)
	@echo Compilation started
	@g++ ${GAME_1_DIR}/${GAME}.cpp ${GAME_1_DIR}/dependencies.h -o ${GAME_1_DIR}/${GAME}.o
else ifeq (${GAME}, game_2)
	@echo Compilation started
	@g++ ${GAME_2_DIR}/${GAME}.cpp ${GAME_2_DIR}/dependencies.h -o ${GAME_2_DIR}/${GAME}.o -lvulkan -lglfw
endif

run: compile
	@echo Starting game...
ifeq(${GAME}, game_1)
	@./${GAME_1_DIR}/${GAME}.o
else ifeq(${GAME}, game_2)
	@./${GAME_2_DIR}/${GAME}.o
endif

.PHONY: clean

