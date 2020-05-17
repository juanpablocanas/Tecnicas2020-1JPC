#include "FuncionesCC.c"


int main(){

   int counter[10]={0};
   int id=5;
   int n=sizeof(counter)/sizeof(counter[0]);
   
  int cantLocales=0;
  
   
   
   int pisos, localesPiso;
    printf("Numero de pisos: ");
    scanf("%d", &pisos);
    printf("Numero de locales por piso: ");
    scanf("%d", &localesPiso);
    local** arreglo = crearCC(pisos, localesPiso);
 	int ocupados=malloc(sizeof(int) * pisos);
 	Queue fila = createQueue();
 	consumidor c;
 	
 	load(&arreglo,"Locales.dat");
   int opcion;
   do{
	  opcion=menu();
      switch(opcion){
         case 1:
            agregarLocal(arreglo,pisos,localesPiso,&cantLocales);
            break;
         case 2:
         	mostrarTodosLocal(arreglo,pisos,localesPiso);
            break;
         case 3:
         	buscarLocalNombre(arreglo,  pisos,  localesPiso);
            break;
          case 4:
          	mostrarLocalesPiso(arreglo,pisos);
          	break;
          case 5:
          	cambiarNombre(arreglo);
          	break;
          case 6:
          	printf("Hay %d Locales ", contarNumLocales(ocupados,0,0));
          	break;
          case 7:
          	agregarDeudores(arreglo);
          	printf("Se han agregado. Vea el TXT");
          	break;
          case 8:
          	ordenarTrabajadores(arreglo,cantLocales);
          	printf("Se han ordenado. Vea el TXT");
          	break;
          case 9:
          	printf( "Ingrese nombre consumidor: " ); scanf("%s", c.nombre);
				printf( "Ingrese id consumidor: " ); scanf("%d", &c.id);
				printf( "Ingrese  edad consumidor: " ); scanf("%d", &c.edad);
				fila.put(&fila,c);
          	
          	break;
           case 10:	
				fila.delete( &fila );
				printf( "La persona ha entrado al centro comercial \n" );
				break;
          	case 11:
				fila.display(&fila);
				break;
			case 12:
				fila.delete(&fila);
				printf("Se han borrado toda la fila");
          		break;
			case 13:
				save(&arreglo,"Locales.dat");
				printf("Se ha guardado");
          		break;
          	case 14:
          		ordenarInventario(arreglo,cantLocales);
          		printf("Se han ordenado. Vea el TXT");
          		break;
 
      }
   }while(opcion!=0);
	return 0;
}

