#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct persona{
   char nombre[ 25 ];
   char tipo[ 2 ];
   int estado;
}persona;

void agregarDonante(persona donantes[4][10], int counter[4]);

void mostrarDonantes(persona donantes[4][10], int counter[4]);

void buscarDonante(persona donantes[4][10]);

int menu();