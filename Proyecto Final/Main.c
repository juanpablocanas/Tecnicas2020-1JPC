#include "FuncionesCC.c"


int main(){
	int cargar;
	int pisos, localesPiso;
	local **arreglo;
	
	do{
		printf("Cargar Arhivo? 1.Si  2.No");
		scanf("%d",&cargar);
		switch(cargar){
			case 1: ;
				FILE *filePisosr = fopen("NumPisos.txt","r");
				FILE *fileLocalesr = fopen("NumLocales.txt","r");
				fscanf(filePisosr,"%d",&pisos);
				fscanf(fileLocalesr,"%d",&localesPiso);
				fclose(filePisosr); fclose(fileLocalesr);
				arreglo= crearCC(pisos,localesPiso);
				loadCC(arreglo,pisos,localesPiso,"CentroC.dat");
				break;
				
			case 2: ;
				FILE *fileDatos= fopen("CentroC.dat","w");
				fclose(fileDatos);
				printf("Numero de pisos: ");
    			scanf("%d", &pisos);
    			printf("Numero de locales por piso: ");
    			scanf("%d", &localesPiso);
    			FILE *filePisosw = fopen("NumPisos.txt","w");
				FILE *fileLocalesw = fopen("NumLocales.txt","w");
				fprintf(filePisosw,"%d", pisos);
				fprintf(fileLocalesw,"%d", localesPiso);
				arreglo = crearCC(pisos, localesPiso);
				fclose(filePisosw); fclose(fileLocalesw);
				break;
		}
	}while(cargar > 2 || cargar < 1);
	
 	Queue fila = createQueue();
 	consumidor c;
 
   int opcion;
   do{
	  opcion=menu();
      switch(opcion){
         case 1:
            agregarLocal(arreglo,pisos,localesPiso);
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
          	cambiarNombre(arreglo,pisos,localesPiso);
          	break;
          case 6:
          	
          case 7:
          	agregarDeudores(arreglo);
          	printf("Se han agregado. Vea el TXT");
          	break;
          case 8:
          	ordenarTrabajadoresQuickSort(arreglo);
          	printf("Se han ordenado. Vea el TXT");
          	break;
          case 9:
          	printf( "Ingrese nombre consumidor: " ); scanf("%s", c.nombre);
				printf( "Ingrese id consumidor: " ); scanf("%d", &c.id);
				printf( "Ingrese  edad consumidor: " ); scanf("%d", &c.edad);
				fila.put(&fila,c);
          	break;
           case 10:	
				fila.del( &fila );
				printf( "La persona ha entrado al centro comercial \n" );
				break;
          	case 11:
				fila.display(&fila);
				break;
			case 12:
				fila.empty(&fila);
				printf("Se han borrado toda la fila");
          		break;
			case 13:
				saveCC(arreglo,pisos,localesPiso,"CentroC.dat");				
				printf("Se ha guardado");
          		break;
          	case 14:
          		ordenarInventario(arreglo);
          		printf("Se han ordenado. Vea el TXT");
          		break;
          	case 15:
          		ordenarVentas(arreglo);
          		break;
          	
 
      }
   }while(opcion!=0);
	return 0;
}

