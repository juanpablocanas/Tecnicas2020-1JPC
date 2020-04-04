#include "Donantes.h"

int menu(){
   int opc;
   printf( "\n BANCO DE SANGRE ¡BIENVENIDO! \n" );
   printf( "============================\n" );
   printf( "1 Agregar donante \n " );
   printf( "2 Mostrar donantes \n ");
   printf( "3 Buscar donante \n" );
   printf( "4 Salir \n" );
   printf( "Digite su opcion por favor \n" );
   printf("==>"); scanf( "%d", &opc );
   return opc;
}
