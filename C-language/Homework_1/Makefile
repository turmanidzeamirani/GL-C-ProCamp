# makefile

COMPILER := gcc

dir := $(shell pwd)
MD := mkdir
BIN := bin/
OB_DIR := bin/obj/


all: homework_1.o EndianessSwap.o RgbConverter.o Geometry.o
	${COMPILER} -o ${dir}/bin/homework_1 ${dir}/${OB_DIR}homework_1.o ${dir}/${OB_DIR}EndianessSwap.o ${dir}/${OB_DIR}RgbConverter.o ${dir}/${OB_DIR}Geometry.o

clean:
	rm -rf ${BIN}

homework_1.o:
	${MD} -p ${dir}/${OB_DIR}
	${COMPILER} -c ${dir}/homework_1.c -o ${dir}/${OB_DIR}homework_1.o
	
EndianessSwap.o:
	${MD} -p ${dir}/${OB_DIR}
	${COMPILER} -c  ${dir}/EndianessSwap.c -o ${dir}/${OB_DIR}EndianessSwap.o

RgbConverter.o:
	${MD} -p ${dir}/${OB_DIR}
	${COMPILER} -c  ${dir}/RgbConverter.c -o ${dir}/${OB_DIR}RgbConverter.o 

Geometry.o:
	${MD} -p ${dir}/${OB_DIR}
	${COMPILER} -c  ${dir}/Geometry.c -o ${dir}/${OB_DIR}Geometry.o 

