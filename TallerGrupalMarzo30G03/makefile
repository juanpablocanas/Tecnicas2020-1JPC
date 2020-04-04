all: program

program: main menu buscarDonante agregarDonantes mostrarDonantes
	gcc -o bloodBank Main.o menu.o mostrarDonantes.o agregardonantes.o banco.o

mostrarDonantes: mostrarDonantes.c Donantes.h
	gcc -c mostrarDonantes.c
agregarDonantes: agregardonantes.c Donantes.h
	gcc -c agregardonantes.c
buscarDonante: banco.c Donantes.h
	gcc -c banco.c
menu: menu.c Donantes.h
	gcc -c menu.c
main: Main.c Donantes.h
	gcc -c Main.c