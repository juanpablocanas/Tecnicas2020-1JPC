#include "FuncionesCC.h"


int menu(){
   int opc;
   printf( "\n Centro Comercial CoronaVirus  ¡BIENVENIDO! \n" );
   printf( "============================\n" );
   printf( "1 Agregar Local \n " );
   printf( "2 Mostrar Locales \n ");
   printf( "3 Buscar Local Nombre \n" );
   printf( "4 Mostrar Locales Piso  \n" );
    printf( "5 Cambiar Nombre  \n" );
   printf( "6 Recursion Contar Locales \n" );
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


void agregarLocal(local arreglo[5][10], int counter[10], int ocupados[p][l]){
	srand( time( NULL ) );
	int i,j;
	local newLocal;
	char estado;
	int pisoDeseado,localDeseado;
	int localesDisponibles=0;
	int cate=0;
	newLocal.idLocal=rand()/10;
	
	


	printf("Nombre: "); scanf("%s", newLocal.nombreLocal);
	printf("Piso Deseado: "); scanf("%d", &newLocal.pisoLocal);
	printf("Numero Local x Piso: ");scanf("%d",&newLocal.numLocalxPiso);
	printf("Categoria: 1. Ropa 2.Hogar 3.Electrodomesticos: "); scanf("%d",&newLocal.categoria);
	pisoDeseado=newLocal.pisoLocal;
	localDeseado=newLocal.numLocalxPiso;
	cate=newLocal.categoria;
	
	
	if(counter[pisoDeseado] >= 10){
		printf("No se pudo agregar Local, piso lleno\n");
		return;
	}
	else if(!validarPiso(pisoDeseado)){
		printf("Piso invalido. Recuerde que hay 4 pisos");
	}
	else if(ocupados[pisoDeseado][localDeseado]==1){
		printf("Local invalido. Ya hay un local");
	}
	else if(validarPiso(pisoDeseado) && (ocupados[pisoDeseado][localDeseado]==0)  ){
		arreglo[pisoDeseado][counter[pisoDeseado]] = newLocal; 
		printf(">>> {Nombre :%s  ", newLocal.nombreLocal);
		printf("Piso: %d  ", newLocal.pisoLocal);
		printf("Num Local : %d  ", newLocal.numLocalxPiso); 
		printf("Se registro en categoria: %s  ",getCategoria(cate));
		printf("ID Unico: %d ",newLocal.idLocal);
		ocupados[pisoDeseado][localDeseado]=1;
		counter[pisoDeseado]+=1;
		localesDisponibles= 10-counter[pisoDeseado];
		printf("\n Aviso: En el piso %d quedan %d locales",newLocal.pisoLocal,localesDisponibles);
	}
	printf("\n");
	
	return;
}

void mostrarTodosLocal(local arreglo[5][10],int counter[10],int ocupados[p][l]){
	int i,j;

	for(i=0;i<5;i++){
		for(j=0;j<counter[i];j++){
				printf("Nombre: %s ",arreglo[i][j].nombreLocal);
				printf("Piso: %d ",arreglo[i][j].pisoLocal);
				printf("Num Local %d ",arreglo[i][j].numLocalxPiso);
				printf("ID Unico %d ",arreglo[i][j].idLocal);
				printf("\n \n");
			
		}
	}
}


void mostrarLocalesPiso(local arreglo[5][10],int counter [10]){
	int i;
	int pisoBuscar=0;
	printf("Ingrese el numero de piso para mostrar locales en ese piso");scanf("%d",&pisoBuscar);
	if(validarPiso(pisoBuscar)){
		printf("En el piso %d se encuentran los siguientes locales: \n",pisoBuscar);
	for(i=0;i<counter[pisoBuscar];i++){
		printf(" %s: ",arreglo[pisoBuscar][i].nombreLocal);
		printf("\n ");
	}
	}
}
	

void buscarLocalNombre(local arreglo[5][10]){
	int i,j;
  char name[25];
  
  printf("Ingrese el nombre del local a buscar: ");
  scanf("%s", name);
  for(i = 0; i < 5; i++){
    for(j = 0; j < 10; j++){
      if(!strcmp(arreglo[i][j].nombreLocal, name) ){
        printf("El local %s fue encontrado exitosamente en el sistema\n", arreglo[i][j].nombreLocal);
        printf("%s: ", arreglo[i][j].nombreLocal);
        printf("\n Se encuentra ubicado en el piso %d local %d",arreglo[i][j].pisoLocal,arreglo[i][j].numLocalxPiso);
      }
	   
    }
  }

  return;
}

int contarNumLocales(int ocupados[5][10],int i,int j){
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



void cambiarNombre(local arreglo[5][10]){
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




//FUNCIONES ADICIONALES QUE INTENTE HACER PERO NO LO LOGRE

void modificarPisoLocal(local arreglo[5][10],int counter[10]){
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

void eliminarLocal(local arreglo[5][10],int counter[10],int ocupados[p][l]){
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

void cambiarCategoria(local arreglo[5][10]){
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









    
