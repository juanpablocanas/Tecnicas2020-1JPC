#ifndef FUNCIONESCC_H_
#define FUNCIONESCC_H_
#include <stdlib.h>
#include <stdio.h>
#include <string.h> 
#include <time.h>
#include "Sorts.h"
#include "arrayqueueConsumidor.h"
//#include <stdexcept>

typedef enum categoria{
   ROPA, HOGAR, ELECTRODOMESTICOS
}categoria_e;



typedef enum opc_validacion{
 	POSITIVO, MINIMO, MAXIMO
}opc_validacion_e;

const int p=5;
const int l=10;
//Local 
typedef struct Local{
	char nombreLocal[35];
	int idLocal; // Calculado automaticamente por su programa
	int pisoLocal;
	int numLocalxPiso;
	categoria_e categoria;
	int numEmpleados;
	int inventario;
	int ventas;
	
	
	
	// Completelo con lo que quiera
} local;


 char* getCategoria(categoria_e cat){
 
   switch (cat){
      case ROPA: return "Ropa";
      case HOGAR: return "Hogar";
      case ELECTRODOMESTICOS: return "Electrodomesticos";
      
   }
}


/*Agregar las funciones que necesite para satisfacer los requerimientos */

local **reservarMemoria(int numPiso, int numLocalxPiso);

void iniciarCentroComercial(local ** centroComercial, int numPiso, int numLocalxPiso); 
		
void agregarLocal(local **arreglo, int pisos, int localesPiso);

void mostrarTodosLocal(local **arreglo,int pisos, int localesPiso);

void buscarLocalNombre(local **arreglo, int pisos, int localesPiso);

void mostrarLocalesPiso(local **arreglo,int pisos);

void cambiarNombre(local **arreglo,int pisos, int localesPiso);

int contarNumLocales(int **ocupados,int i,int j);



int menu();


#endif /* FUNCIONESCC_H_ */
