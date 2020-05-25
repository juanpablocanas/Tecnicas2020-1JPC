#include "FuncionesCC.h"


int menu(){
   int opc;
   printf( "\n  ¡BIENVENIDO! \n" );
																									
   printf( "============================\n" );
   printf( "1 Agregar Local \n" );
   printf( "2 Mostrar Locales \n");
   printf( "3 Buscar Local Nombre \n" );
   printf( "4 Mostrar Locales Piso  \n" );
    printf( "5 Cambiar Nombre  \n" );
   printf( "7 Agregar Deudores \n" );
   printf( "8 Sortear Numero Trabajadores (QuickSort) \n" );
   	printf("\n ");
   printf( "Funciones Queue \n" );printf( "================== \n" );
   printf( "9  Entra a Fila \n" );
   printf( "10  Entra CC \n" );
   printf( "11  Display fila \n" );
   printf( "12 Fila Borrar Todo \n" );
   printf( "================== \n \n" );
   printf( "13 Save Centro Comericial \n" );
   printf( "14 Sortear Inventario (InsertionSort) \n" );
   printf( "15 Sortear Ventas (MergeSort) \n" );
   printf("\n \n ");
   printf( "Digite su opcion por favor \n" );
   printf( "0 para salir \n" );
   printf("==>"); scanf( "%d", &opc );
   return opc;
}
/*
void validarNumeros(int num, opc_validacion_e opcValidacion){ //Para inventario y Trabajadores
  
  switch (opcValidacion){
  	case POSITIVO: 
	    if (num < 0){
    		throw std::logic_error ("El número debe ser positivo \n");
  	    }
  	    break;
  	case MINIMO: 
  		if (num < 10){
    		throw std::logic_error ("Para este CC se necesitan máss de 11 para poder registrarse \n");
  	    }
		break;	
}
}

void validarPiso(int num, opc_validacion_e opcValidacion,int pisos){
  
  switch (opcValidacion){
  	case POSITIVO: 
	    if (num < 0){
    		throw std::logic_error ("El número debe ser positivo \n");
  	    }
  	    break;
  	case MAXIMO: 
  		if (num > pisos){
    		throw std::logic_error ("Su numero se pasa del máximo pisos del CC \n");
  	    }
		break;	
}
}

void validarLocalesPiso(int num, opc_validacion_e opcValidacion,int localesPiso){
  
  switch (opcValidacion){
  	case POSITIVO: 
	    if (num < 0){
    		throw std::logic_error ("El número debe ser positivo \n");
  	    }
  	    break;
  	case MAXIMO: 
  		if (num > localesPiso){
    		throw std::logic_error ("Su numero se pasa del máximo locales por piso del CC \n");
  	    }
		break;	
}
}
*/
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
            
    }

    return arreglo;
}


void agregarLocal(local **arreglo, int pisos, int localesPiso){
	srand( time( NULL ) );
	
	
	
	int pisoDeseado,localDeseado,  idLocal, numEmpleados,cat,inventario,count,ventas;
	FILE    *fileCont;
    fileCont = fopen("Cont.txt", "r+");
    fscanf(fileCont, "%d", &count); //Guardo lo que esta en el arhhivo cont.txt y se lo pongo   count
	fclose(fileCont); // Cierro el archivo ya que lo tengo que abrir despues en W
					
	idLocal=rand()/10;
	
	printf("Piso: "); 
	scanf("%d", &pisoDeseado);
	//validarPiso(*pisoDeseado, POSITIVO);
	//validarPiso(*pisoDeseado, MAXIMO);
	
	
	
	printf("Local: "); 
	scanf("%d", &localDeseado);
	//validarLocalesPiso(*pisoDeseado, POSITIVO,pisos);
	//validarLocalesPiso(*pisoDeseado, MAXIMO,localesPiso);
	
	pisoDeseado--;
	localDeseado--;
	//Resto para poder trabajarlos como indices en la matriz
	
	if(arreglo[pisoDeseado][localDeseado].idLocal!=0){
		printf("El local ya esta ocupado intente de nuevo");
		return;
	}
	printf("Categoria 1. Ropa 2. Hogar 3. Electrodomesticos: "); scanf("%d", &cat);
	printf("Numero empleados: "); scanf("%d", &numEmpleados); 
	//validarNumeros(*numEmpleados, POSITIVO);
	//validarNumeros(*numEmpleados, MINIMO);
	printf("Inventario: "); scanf("%d", &inventario);
	printf("Ventas: "); scanf("%d", &ventas);
	//validarNumeros(*inventario, POSITIVO);
	//validarNumeros(*inventario, MINIMO);
	
	
	

	
	printf("Nombre: "); 
	scanf("%s", arreglo[pisoDeseado][localDeseado].nombreLocal);
	arreglo[pisoDeseado][localDeseado].pisoLocal = pisoDeseado;
	arreglo[pisoDeseado][localDeseado].numLocalxPiso = localDeseado;
	printf("\n ID Unico: %d", idLocal); 
	arreglo[pisoDeseado][localDeseado].idLocal=idLocal;
	printf("\n");
	if(cat==1){
		arreglo[pisoDeseado][localDeseado].categoria=ROPA;
	}
	else if(cat==2){
		arreglo[pisoDeseado][localDeseado].categoria=HOGAR;
	}
	else if(cat==3){
		arreglo[pisoDeseado][localDeseado].categoria=ELECTRODOMESTICOS;
	}
	//arreglo[pisoDeseado][localDeseado].categoria = cat;
	arreglo[pisoDeseado][localDeseado].numEmpleados = numEmpleados;
	arreglo[pisoDeseado][localDeseado].inventario= inventario;
	arreglo[pisoDeseado][localDeseado].ventas=ventas;
	
	
	
	FILE    *fileTrabajadores;
    fileTrabajadores = fopen("Trabajadores.txt", "ab");
	fprintf(fileTrabajadores, " %d  ", numEmpleados);
	fclose(fileTrabajadores);
	printf("\n");
	//Guardo el numero de trabajadores para organizar despues
	
	FILE    *fileInventario;
    fileInventario = fopen("Inventario.txt", "ab");
	fprintf(fileTrabajadores, " %d  ", inventario);
	fclose(fileInventario);
	//Guardo el numero de inventario para organizar despues
	
	FILE    *fileVentas;
    fileVentas = fopen("Ventas.txt", "ab");
	fprintf(fileVentas, " %d  ", ventas);
	fclose(fileVentas);
	//Guardo el numero de ventas para organizar despues
	
	fileCont = fopen("Cont.txt", "w");
	count=count+1;
    fprintf(fileCont, "%d", count);
	printf("Contador despues: %d",count);
	
	fclose(fileCont);
	//Guardo el numero locales ocupados en un TXT para tenerlo asi la consola se cierre

	return;
}

void mostrarTodosLocal(local **arreglo,int pisos, int localesPiso){
	int i,j,cat;

	for(i=0;i<pisos;i++){
		for(j=0;j<localesPiso;j++){
			if(arreglo[i][j].idLocal!=0){
			
				printf("Nombre: %s ",arreglo[i][j].nombreLocal);
				printf("Piso: %d ",arreglo[i][j].pisoLocal+1);
				printf("Num Local %d ",arreglo[i][j].numLocalxPiso+1);
				printf("Ventas: %d ",arreglo[i][j].ventas);
				//cat=getCategoria(arreglo[i][j].categoria);
				//printf("%d",cat);
				printf("Categoria %s", getCategoria(arreglo[i][j].categoria));
				printf("ID Unico %d ",arreglo[i][j].idLocal);
				printf("Num Empleados: %d ",arreglo[i][j].numEmpleados);
				printf("Inventario: %d ",arreglo[i][j].inventario);
				
				printf("\n \n");
				}
			
		}
	}
}


void mostrarLocalesPiso(local **arreglo,int pisos){
	int i;
	int pisoBuscar=0;
	printf("Ingrese el numero de piso para mostrar locales en ese piso: ");scanf("%d",&pisoBuscar);
	pisoBuscar=pisoBuscar-1;
	for(i=0;i<pisos;i++){
		if(arreglo[pisoBuscar][i].idLocal!=0){
		printf(" %s ",arreglo[pisoBuscar][i].nombreLocal);
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

int contarNumLocales(int **ocupados,int pisos, int localesPiso){
	FILE    *fileCont; //Contador Locales
	int count;
    fileCont = fopen("Cont.txt", "r+");
    fscanf(fileCont, "%d", &count); 
	int i,j;
	if(i>pisos){
		return 0;
	}
	else if(j>localesPiso){
		contarNumLocales(ocupados,i+1,0);
	}
	else {
		return ocupados[i][j]+contarNumLocales(ocupados,i,j+1);
	}
}



void cambiarNombre(local **arreglo,int pisos, int localesPiso){
	char name[25];
	char nameCambiar[25];
  printf("Ingrese el nombre del local a buscar: ");
  scanf("%s", name);
	int i,j;
	for(i = 0; i < pisos; i++){
    for(j = 0; j < localesPiso; j++){
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

void ordenarTrabajadoresQuickSort(local **arreglo ){
	FILE    *f; //Trabajodres Guardados
	FILE    *fs; //Trabajadores Sorteado
	FILE    *fileCont; //Contador Locales
	
	int count;
    fileCont = fopen("Cont.txt", "r+");
    fscanf(fileCont, "%d", &count); 
	
    int   array[count]; //arreglo de tamaño de Locales Ocupados
    int     i, j, ctr = 0;
	int n = sizeof(array)/sizeof(array[0]); 
    f = fopen("Trabajadores.txt", "a+");
	fs = fopen("TrabajadoresSorteado.txt", "a+");
    while((!feof(f)) && (ctr < count))
    {
        fscanf(f, "%d ", &array[ctr++]); // Cargo todos los numeros de Trabajadores Guardado en array
    }
    quickSort(array,0,n-1); //Llamo al sort con el arreglo donde cargue lo del TXT
	fprintf(fs, "Sorteado:   ");
	for(j=0;j<count;j++){
		fprintf(fs, "%d  ", array[j]);  //Imprimo el arreglo en Trabajadores Sorteado
     }
	fclose(f); 
	fclose(fs); 
	fclose(fileCont);
}

void ordenarInventario(local **arreglo ){
	FILE    *f; //Invenario Guardado
	FILE    *fs; //Inventario Sorteadp
	FILE    *fileCont; //Contador Locales
	
	int count;
    fileCont = fopen("Cont.txt", "r+");
    fscanf(fileCont, "%d", &count); 
	
    int   array[count];
    int     i, j, ctr = 0;
	int n = sizeof(array)/sizeof(array[0]); 
    f = fopen("Inventario.txt", "a+");
    fs = fopen("InventarioSorteado.txt", "a+");

    while((!feof(f)) && (ctr < count))
    {
        fscanf(f, "%d ", &array[ctr++]); // Cargo todos los numeros de Inventario Guardado en array
    }
    
	insertionSort(array,n);
	fprintf(fs, "Sorteado:   ");
	for(j=0;j<count;j++){
		fprintf(fs, "%d  ", array[j]); //Imprimo array sorteado en el archivo en Inventario Sorteado
     }
	fclose(f); 
	fclose(fs); 
	fclose(fileCont);
}

void ordenarVentas(local **arreglo ){
	FILE    *f;
	FILE    *fs;
	FILE    *fileCont;
	
	int count;
    fileCont = fopen("Cont.txt", "r+");
    fscanf(fileCont, "%d", &count); 
	
    int   array[count];
    int     i, j, ctr = 0;
	int n = sizeof(array)/sizeof(array[0]); 
    f = fopen("Ventas.txt", "a+");
    fs = fopen("VentasSorteado.txt", "a+");

    while((!feof(f)) && (ctr < count))
    {
        fscanf(f, "%d ", &array[ctr++]); // Cargo todos los numeros en array
    }
    
	mergeSort(array,0,count-1);
	fprintf(fs, "Sorteado:   ");
	for(j=0;j<count;j++){
		fprintf(fs, "%d  ", array[j]); //Imprimo array sorteado en el archivo
     }
	fclose(f); 
	fclose(fs); 
	fclose(fileCont);
}

void saveCC(local **arreglo, int pisos, int localesPiso, char* fn){
    int i, j;
    local currentLoc;
    FILE *f = fopen(fn,"wb");

    if (f == NULL){
        printf("Error! opening file");

       
           exit(1);
   }

   for(i = 0; i < pisos; i++){
           for(j = 0; j < localesPiso; j++){
               if(arreglo[i][j].idLocal != 0){
                   currentLoc = arreglo[i][j];
                   fwrite(&currentLoc, sizeof(local), 1, f); 
                   printf("Guardado: %s", currentLoc.nombreLocal);
            }

           }


   }
   fclose(f); 
   printf("Se ha guardado todo el CC");

}

void loadCC(local **arreglo, int pisos, int localesPiso, char* fn){
    int i, j;
    FILE *f = fopen(fn,"rb");
    FILE    *fileCont;
	
	int count;
    fileCont = fopen("Cont.txt", "r+");
    fscanf(fileCont, "%d", &count); 
    
    local currentLoc;
       if (f == NULL){
       printf("Error! opening file");

       
       exit(1);
   }
    	for(i=0;i<count;i++){
		printf("Entro a la ballenita");
		fread(&currentLoc, sizeof(local), 1, f); 
        arreglo[currentLoc.pisoLocal][currentLoc.numLocalxPiso] = currentLoc;
        printf("Cargo: %s", currentLoc.nombreLocal);
		}
        
    
    fclose(f);

}
    

/*
void save ( local **arreglo ,char* fn ){
	FILE *f = fopen( fn, "wb" );
	
	fwrite( &arreglo,sizeof( *arreglo ), 1, f );
	if(fwrite != 0)  
        printf("contents to file written successfully !\n"); 
    else 
        printf("error writing file !\n"); 
	fclose( f );	
}

void saveCC( local **arreglo ,char* fn,int pisos, int localesPiso ){
	FILE* f=fopen(fn,"w");
	int i,j;
	local * currentLoc= malloc(sizeof(local));
	for(i=0;i<pisos;i++){
		for(j=0;j<localesPiso;j++){
			if(arreglo[i][j].idLocal!=0){
			strcpy(currentLoc->nombreLocal,arreglo[i][j].nombreLocal);
			
			currentLoc->idLocal= arreglo[i][j].idLocal;
			currentLoc->numLocalxPiso= arreglo[i][j].numLocalxPiso;
			currentLoc->categoria= arreglo[i][j].categoria;
			currentLoc->numEmpleados= arreglo[i][j].numEmpleados;
			currentLoc->inventario= arreglo[i][j].inventario;
			currentLoc->ventas= arreglo[i][j].ventas;
			}	
		}
	}
	if(f!=NULL){
		fwrite(currentLoc,sizeof(local),1,f);
	}
}

void loadCC(local **arreglo ,char* fn,int pisos, int localesPiso){
	local * currentLoc= malloc(sizeof(local));
	FILE* f=fopen(fn,"w");
	if(f!=NULL){
		while(!feof(f)){
			fread(currentLoc,sizeof(local),1,f);
		}
		
	}
	
}


void load ( local **arreglo ,char* fn ){
	FILE *f = fopen(fn,"rb");
	fread( &arreglo,sizeof( *arreglo ), 1 ,f );
	if (fn == NULL) 
    { 
        fprintf(stderr, "\nError opening file\n"); 
        exit (1); 
    }
	else{
		printf("contents of file read successfully !\n"); 
	}
	     
	fclose( f );	
}

void saveText( local **arreglo ,char* fn,int pisos, int localesPiso ){
	FILE *f = fopen( fn, "w" );
	int i,j;
	fwrite( &arreglo,sizeof( *arreglo ), 1, f );
	if(fwrite != 0)  
        printf("contents to file written successfully !\n"); 
    else 
        printf("error writing file !\n"); 
	fclose( f );	
}

*/






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









    
