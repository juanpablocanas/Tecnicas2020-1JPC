#ifndef FUNCIONESCC_H_
#define FUNCIONESCC_H_
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "mongoose.h"
const int p=5;
const int l=10;
//Local 
typedef struct Local{
	char nombreLocal[35];
	int idLocal; // Calculado automaticamente por su programa
	int pisoLocal;
	int numLocalxPiso;
	int categoria;
	// Completelo con lo que quiera
} local;

typedef enum categoria{
   ROPA, HOGAR, ELECTRODOMESTICOS
}categoria;

 char* getCategoria(int cat){
 
   switch (cat){
      case 1: return "Ropa";
      case 2: return "Hogar";
      case 3: return "Electrodomesticos";
      
   }
}


/*Agregar las funciones que necesite para satisfacer los requerimientos */

local **reservarMemoria(int numPiso, int numLocalxPiso);

void iniciarCentroComercial(local ** centroComercial, int numPiso, int numLocalxPiso); 
		
void agregarLocal(local arreglo[5][10],int counter[10], int ocupados[p][l]);

void mostrarTodosLocal(local arreglo[5][10],int counter[10], int ocupados[p][l]);

void buscarLocalNombre(local arreglo[5][10]);

void mostrarLocalesPiso(local arreglo[5][10],int counter [10]);

void cambiarNombre(local arreglo[5][10]);

int contarNumLocales(int ocupados[5][10],int i,int j);



int menu();


#endif /* FUNCIONESCC_H_ */
