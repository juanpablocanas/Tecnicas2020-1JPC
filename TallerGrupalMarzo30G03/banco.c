#include "Donantes.h"

void buscarDonante(persona donantes[4][10]){
  int i,j;
  char name[25];
  
  printf("Ingrese el nombre del donante que necesita: ");
  scanf("%s", name);
  for(i = 0; i < 4; i++){
    for(j = 0; j < 10; j++){
      if(!strcmp(donantes[i][j].nombre, name) ){
        printf("El donante %s fue encontrado exitosamente en el sistema\n", donantes[i][j].nombre);
        printf("%s: ", donantes[i][j].nombre);
        if (donantes[i][j].estado==0){
          printf("[+");
        }
        else {printf("[-");}
        printf("%s]", donantes[i][j].tipo);
        return;
      }   
    }
  }
  printf("El donante %s no ha sido ingresado en el sistema", name); 
  return;
}


