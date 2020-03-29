#include <stdio.h>
#define CAP 60

typedef struct Persona{
  char nombre[ 20 ];
  int dia;
  int mes;
  int anio;
} Persona;

typedef enum meses_e{
   ENE, FEB, MAR, ABR, MAY, JUN, JUL, AGO, SEP, OCT, NOV, DIC
}meses_e;

const char* getMes(int mes){
 
   switch (mes){
      case 1: return "Enero";
      case 2: return "Febrero";
      case 3: return "Marzo";
      case 4: return "Abril";
      case 5: return "Mayo";
      case 6: return "Junio";
      case 7: return "Julio";
      case 8: return "Agosto";
      case 9: return "Septiembre";
      case 10: return "Octubre";
      case 11: return "Noviembre";
      case 12: return "Diciembre";
   }
}


int ocuparMes(int *ocupMes,int mes){
	if(ocupMes[mes]<=5){
		ocupMes[mes]++;
		return 1;	
	}
	else if(ocupMes[mes]>5){
		printf("Mes LLENO!!!");
		return 0;	
	}
		
}


int menu(){
   int opc;

   printf("1) Ingresar Persona\n");
   printf("2) Buscar cumpleanios por el mes\n");
   printf("3) Recursion\n");
   printf("4) Ejemplo con enums,condicional,etc\n");
   printf("5) Imprimir\n");
   printf("0) Salir\n");
   printf("Opcion: ");
   scanf("%d", &opc);

   return opc;
}

int contarMes(int num){
   int cont = 0;
   while(num > 0){
      if(num % 2 == 0){
         cont ++;
      }
   num--; 
   contarMes(num);
   }

   return cont;
}


int main(void){
   int opcion, posicion = 0, mesBuscar, mes, resultado, i, mesEnum, contador,mesTemp;
   Persona arreglo[ CAP ];
   int ocupMes[12]={0,0,0,0,0,0,0,0,0,0,0,0};
   int sal=0;
   

   do{
      opcion = menu();
      switch (opcion){
         case 1: 

		 		do{
		 		printf("Digite su nombre: ");
                 scanf("%s", arreglo[ posicion ].nombre );
                 printf("Digite el mes: ");
				 scanf("%d", &arreglo[ posicion ].mes);
				 mesTemp=arreglo[ posicion ].mes;
				 printf("Digite el dia: ");
                 scanf("%d", &arreglo[ posicion ].dia);
                 printf("Digite el anio: ");
                 scanf("%d", &arreglo[ posicion++ ].anio);
				 if(ocuparMes(ocupMes , mesTemp)){
				 	printf("Mes Disponible! Se ha agreado la persona!");
				 	sal=1;
				 	break;
				 }
				 else{
				 	printf("Mes LLeno. Intente de nuevo con otro mes \n ");
				 }
                 
                 }	while(sal!=1);
                 break;

         case 2: printf("Digite mes a buscar\n ");
                 scanf("%d", &mesBuscar);
                 for ( i = 0; i < posicion; i++){
                    if(mesBuscar==arreglo[ i ].mes){
                    printf("[ %s ] cumple en %d \n", arreglo[ i ].nombre, arreglo[ i ].mes);
                    }
                 }
                 break;

         case 3: printf("Digite el # del mes: ");
                 scanf("%d", &mes);
                 if(mes == 2){
                    resultado = contarMes(28);
                 }
                 else {
                    resultado = contarMes(30);
                 }
                 printf("Cantidad de dias pares del mes:[ %d ] : %d\n", mes, resultado);
                 break;

         case 4: //un condicional, un ciclo y enums. 
                 printf("Escriba el numero de un mes para saber que mes es: ");
                 scanf("%d", &mesEnum);
                 for (i = ENE; i <= DIC; i++){
                    if(i == mesEnum){
                       printf("%s \n", getMes(mesEnum));
                       break; 
                   }
             
                 }
                 break;
              
        case 5:
        	for(i = 0; i < posicion; i++){
	           printf("[ %s, %d, %d, %d ]\n", arreglo[ i ].nombre, arreglo[ i ].dia, arreglo[ i ].mes, arreglo[ i ].anio);
                }
                break;
		case 6:
		
			//printf("%d ",ocupMes[0]);  
			//printf("\n");          

        case 0: break;
      }
     
   }while(opcion != 0);

  return 0;
}
