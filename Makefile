SRC_FILES := ${GAME}/*.cpp
HDR_FILES := ${GAME}/*.h

debug:
	@echo ${GAME}

${GAME}.cpp:
	@cat ${GAME}/${GAME}.cpp >> /dev/null

clean:
	@clear
	@echo Cleaning generated files
	@rm -rf game_*/*.o

compile: clean ./${GAME}.cpp
ifeq (${GAME}, game_2)
	@echo Compilation started
	@g++ ${SRC_FILES} ${HDR_FILES} -o ${GAME}/${GAME}.o -lvulkan -lglfw
else
	@echo Compilation started
	@g++ ${SRC_FILES} ${HDR_FILES} -o ${GAME}/${GAME}.o
endif

run:
	@echo Starting game...
	@${GAME}/${GAME}.o

.PHONY: debug clean compile run

