
#include "Donantes.h"

//muestra todos los donanates en la matriz donanates[][]
//donanates[][] guarda todos los donanates
//counter[] cuenta cuantos usuarios han donado por tipo de sangre
void mostrarDonantes(persona donantes[4][10], int counter[4]){
	
  int i,j;
  printf("===Donantes===\n");
	for(i = 0; i < 4; i++){
    switch( i ){
    	case 0:
      	printf("==Tipo A==\n");
      	break;
      case 1:
      	printf("==Tipo B==\n");
      	break;
      case 2:
      	printf("==Tipo AB==\n");
      	break;
      case 3:
      	printf("==Tipo O==\n");
      	break;
    }
  	for(j = 0; j < counter[i]; j++){
  		printf("{%s: ", donantes[i][j].nombre);
      if(donantes[i][j].estado == 0)
      	printf("+");
      else printf("-");
		printf("%s}", donantes[i][j].tipo);
    }
	printf("\n");
  }
  printf("\n=========\n\n");
	return;
}