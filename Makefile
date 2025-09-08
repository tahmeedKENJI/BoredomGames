debug:
	@echo ${GAME}

${GAME}.cpp:
	@cat ${GAME}/${GAME}.cpp >> /dev/null

clean:
	@clear
	@echo Cleaning generated files
	@rm -rf *.o

compile: clean ./${GAME}.cpp
ifeq (${GAME}, game_1)
	@echo Compilation started
	@g++ ${GAME}/${GAME}.cpp ${GAME}/dependencies.h -o ${GAME}/${GAME}.o
else ifeq (${GAME}, game_2)
	@echo Compilation started
	@g++ ${GAME}/${GAME}.cpp ${GAME}/dependencies.h -o ${GAME}/${GAME}.o -lvulkan -lglfw
endif

run:
	@echo Starting game...
	@${GAME}/${GAME}.o

.PHONY: clean

