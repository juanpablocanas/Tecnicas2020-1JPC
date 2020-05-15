#include "FuncionesCC.h"


int menu(){
   int opc;
   printf( "\n Centro Comercial CoronaVirus  �BIENVENIDO! \n" );
   printf( "============================\n" );
   printf( "1 Agregar Local \n " );
   printf( "2 Mostrar Locales \n ");
   printf( "3 Buscar Local Nombre \n" );
   printf( "4 Mostrar Locales Piso  \n" );
    printf( "5 Cambiar Nombre  \n" );
   printf( "6 Recursion Contar Locales \n" );
   printf( "7 Agregar Deudores \n" );
   printf( "8 Sortear Numero Trabajadores \n" );
   printf( "Funciones Queue \n" );printf( "================== \n" );
   printf( "9 Queue Put \n" );
   printf( "10 Queue Entra CC \n" );
   printf( "11 Queue Display \n" );
   printf( "12 Queue Borrar \n" );
   printf( "Digite su opcion por favor \n" );
   printf( "0 para salir \n" );
   printf("==>"); scanf( "%d", &opc );
   return opc;
}

int validarPiso(int piso){
	if(piso<5){
		return 1;
	}
	else{
		return 0;
	}
}

local ** reservarMemoriaCentroComercial(int numPiso, int numLocalxPiso){
   int i;
   local **centroComercial = malloc(numPiso * sizeof(local*));
   if(centroComercial != NULL){
      for(i = 0; i < numPiso; i++){
         centroComercial[i] = malloc(numLocalxPiso * sizeof(local));
         if(centroComercial[i] == NULL){
            printf("Hubo un error \n");
            break;
         }
      }
   }
   else{
      printf("Hubo un error reservando \n");
   }
   return centroComercial; 

}

local** crearCC(int pisos, int localesPiso)
{
    local** arreglo = malloc(sizeof(local*) * pisos);

    int i, j;
    for(i = 0; i < pisos; i++)
    {
        arreglo[i] = malloc(sizeof(local) * localesPiso);
        for (j = 0; j < localesPiso; j++)
            //Inicia todos los id en 0 para representar que los locales estan vacios
            arreglo[i][j].idLocal = 0;
            printf("Entro");
    }

    return arreglo;
}







void agregarLocal(local **arreglo, int pisos, int localesPiso,int* cantLocales){
	srand( time( NULL ) );
	
	
	
	int pisoDeseado,localDeseado,  idLocal, numEmpleados,cat;
	
	 idLocal=rand()/10;
	
	printf("Piso: "); 
	scanf("%d", &pisoDeseado);
	if(pisoDeseado>pisos){
		//throw std::out_of_range;
	}
		
	printf("Local: "); scanf("%d", &localDeseado);
	printf("Categoria: "); scanf("%d", &cat);
	printf("Numero empleados: "); scanf("%d", &numEmpleados);
	
	
	
	pisoDeseado--;
	localDeseado--;

	
	printf("Nombre: "); 
	scanf("%s", arreglo[pisoDeseado][localDeseado].nombreLocal);
	arreglo[pisoDeseado][localDeseado].pisoLocal = pisoDeseado;
	arreglo[pisoDeseado][localDeseado].numLocalxPiso = localDeseado;
	printf("\n ID Unico: %d", idLocal); 
	arreglo[pisoDeseado][localDeseado].idLocal=idLocal;
	printf("\n");
	arreglo[pisoDeseado][localDeseado].categoria = cat;
	arreglo[pisoDeseado][localDeseado].numEmpleados = numEmpleados;
	
	*cantLocales=*cantLocales+1;
	FILE    *fileTrabajadores;
    fileTrabajadores = fopen("Trabajadores.txt", "ab");

	fprintf(fileTrabajadores, " %d  ", numEmpleados);
	fclose(fileTrabajadores);
	printf("\n");
	
	printf("%d",*cantLocales);
	
	return;
}

void mostrarTodosLocal(local **arreglo,int pisos, int localesPiso){
	int i,j;

	for(i=0;i<pisos;i++){
		for(j=0;j<localesPiso;j++){
			if(arreglo[i][j].idLocal!=0){
			
				printf("Nombre: %s ",arreglo[i][j].nombreLocal);
				printf("Piso: %d ",arreglo[i][j].pisoLocal+1);
				printf("Num Local %d ",arreglo[i][j].numLocalxPiso+1);
				//printf("Categoria %d", getCategoria(&arreglo[i][j].categoria));
				printf("ID Unico %d ",arreglo[i][j].idLocal);
				printf("\n \n");
				}
			
		}
	}
}


void mostrarLocalesPiso(local **arreglo,int pisos){
	int i;
	int pisoBuscar=0;
	printf("Ingrese el numero de piso para mostrar locales en ese piso");scanf("%d",&pisoBuscar);
	if(validarPiso(pisoBuscar)){
		printf("En el piso %d se encuentran los siguientes locales: \n",pisoBuscar);
	for(i=0;i<pisos;i++){
		
		printf(" %s: ",arreglo[pisoBuscar][i].nombreLocal);
		printf("\n ");
	}
	}
}
	

void buscarLocalNombre(local **arreglo, int pisos, int localesPiso){
	int i,j;
  char name[25];
  
  printf("Ingrese el nombre del local a buscar: ");
  scanf("%s", name);
  for(i = 0; i < 5; i++){
    for(j = 0; j < 10; j++){
      if(!strcmp(arreglo[i][j].nombreLocal, name) ){
        printf("El local %s fue encontrado exitosamente en el sistema\n", arreglo[i][j].nombreLocal);
        printf("%s: ", arreglo[i][j].nombreLocal);
        printf("\n Se encuentra ubicado en el piso %d local %d",arreglo[i][j].pisoLocal+1,arreglo[i][j].numLocalxPiso+1);
      }
	   
    }
  }

  return;
}

int contarNumLocales(int **ocupados,int i,int j){
	if(i>4){
		return 0;
	}
	else if(j>9){
		contarNumLocales(ocupados,i+1,0);
	}
	else {
		return ocupados[i][j]+contarNumLocales(ocupados,i,j+1);
	}
}



void cambiarNombre(local **arreglo){
	char name[25];
	char nameCambiar[25];
  printf("Ingrese el nombre del local a buscar: ");
  scanf("%s", name);
	int i,j;
	for(i = 0; i < 5; i++){
    for(j = 0; j < 10; j++){
	if(!strcmp(arreglo[i][j].nombreLocal, name) ){
        printf("El local %s fue encontrado exitosamente en el sistema\n", arreglo[i][j].nombreLocal);
        printf("Ingrese el NUEVO nombre del local : ");
  		scanf("%s", arreglo[i][j].nombreLocal);
    }
	
}
}
}


void agregarDeudores(local **arreglo){
	int i,j;
	printf("Numero de piso de local"); scanf("%d",&i);
	printf("Numero Local x Piso"); scanf("%d",&j);
	i--;
	j--;
	FILE    *ff;
     ff = fopen("Deudores.txt", "ab");
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    fprintf(ff, "Registrado a hora: %d-%02d-%02d %02d:%02d:%02d \n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
    fprintf(ff, "\n ");
	fprintf(ff, "Nombre %s  ", arreglo[i][j].nombreLocal);
	fprintf(ff, "Piso: %d ",arreglo[i][j].pisoLocal+1);
	fprintf(ff,"Num Local %d ",arreglo[i][j].numLocalxPiso+1);
	fprintf(ff,"ID Unico %d ",arreglo[i][j].idLocal);
	fprintf(ff, "=====================================");
	fprintf(ff, "\n \n");

     
    

    fclose(ff);
    
	
}

void ordenarTrabajadores(local **arreglo,int* cantLocales ){
	FILE    *f;
	printf("Cantidad locales: %d",cantLocales);
    int     array[2];
    int     i, j, ctr = 0;
	int n = sizeof(array)/sizeof(array[0]); 
    f = fopen("Trabajadores.txt", "a+");

    while((!feof(f)) && (ctr < 2))
    {
        fscanf(f, "%d ", &array[ctr++]);
    }
    
	quickSort(array,0,n-1);
	fprintf(f, "Sorteado:   ");
	for(j=0;j<2;j++){
	fprintf(f, "%d  ", array[j]);

     }
	fclose(f); 
}




//FUNCIONES ADICIONALES QUE INTENTE HACER PERO NO LO LOGRE

void modificarPisoLocal(local **arreglo,int counter[10]){
	int newPiso,i,j;
	char name[25];
	printf("Ingrese el nombre del local a buscar para cambiar de piso: ");
  scanf("%s", name);
  for(i = 0; i < 5; i++){
    for(j = 0; j < 10; j++){
      if(!strcmp(arreglo[i][j].nombreLocal, name) ){
        printf("El local %s fue encontrado exitosamente en el sistema\n", arreglo[i][j].nombreLocal);
        printf("%s: ", arreglo[i][j].nombreLocal);
        printf("Cual es el nuevo piso que desea?");scanf("%d",&newPiso);
        if(counter[newPiso] >= 10){
		printf("No se pudo agregar Local, piso lleno\n");
		return;
	}else{
		arreglo[i][j].pisoLocal=newPiso;
		counter[newPiso]+=1;
	}
        
      }   
    }
  }

}

void eliminarLocal(local **arreglo,int counter[10],int ocupados[p][l]){
	 char name[25];
  printf("Ingrese el nombre del local a buscar: ");
  scanf("%s", name);
	int i,j;
  printf("Ingrese el nombre del local a buscar: ");
  scanf("%s", name);
	for(i = 0; i < 5; i++){
    for(j = 0; j < 10; j++){
	if(!strcmp(arreglo[i][j].nombreLocal, name) ){
        printf("El local %s fue encontrado exitosamente en el sistema\n", arreglo[i][j].nombreLocal);
        printf("Se procede a borrarlo");
        //arreglo[i][j].nombreLocal="Vacio";
        arreglo[i][j].idLocal=0;
        arreglo[i][j].categoria=0;
        ocupados[i][j]=0;
        printf("%d",ocupados[i][j]);
        
    }
}
}
	
}

void cambiarCategoria(local **arreglo){
	int i,j;
  char name[25];
  int newCat=0; 
  printf("Ingrese el nombre del local a cambiar la categoria: ");
  scanf("%s", name);
  printf("Nueva Categoria: 1. Ropa 2.Hogar 3.Electrodomesticos: ");scanf("%d", &newCat);
  for(i = 0; i < 5; i++){
    for(j = 0; j < 10; j++){
    	if(!strcmp(arreglo[i][j].nombreLocal, name) ){
    		arreglo[i][j].categoria=newCat;
    		printf("Se cambio la categoria a: %s", getCategoria(newCat));
    		
    	}
}
}
}









    
