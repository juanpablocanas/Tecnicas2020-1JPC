all: Program

Program: Funcs Main
	gcc -o out Main.o FuncionesCC.o

Funcs: FuncionesCC.h FuncionesCC.c
	gcc -c FuncionesCC.c

Main: Main.c FuncionesCC.h
	gcc -c Main.c
