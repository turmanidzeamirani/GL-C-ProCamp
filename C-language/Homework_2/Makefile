# makefile

COMPILER := gcc

dir := $(shell pwd)
MD := mkdir
BIN := bin/
OB_DIR := bin/obj/


all: homework_2.o linked_list_lib.o int_arr_lib.o
	${COMPILER} -o ${dir}/bin/homework_2 ${dir}/${OB_DIR}homework_2.o ${dir}/${OB_DIR}linked_list_lib.o ${dir}/${OB_DIR}int_arr_lib.o

clean:
	rm -rf ${BIN}

homework_2.o:
	${MD} -p ${dir}/${OB_DIR}
	${COMPILER} -c ${dir}/homework_2.c -o ${dir}/${OB_DIR}homework_2.o
	
linked_list_lib.o:
	${MD} -p ${dir}/${OB_DIR}
	${COMPILER} -c  ${dir}/linked_list_lib.c -o ${dir}/${OB_DIR}linked_list_lib.o

int_arr_lib.o:
	${MD} -p ${dir}/${OB_DIR}
	${COMPILER} -c  ${dir}/int_arr_lib.c -o ${dir}/${OB_DIR}int_arr_lib.o
