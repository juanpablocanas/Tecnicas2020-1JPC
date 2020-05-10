
#include <stdio.h>
#include <time.h>
#define TAM 500000
#define NOMBREAR "max.txt" //Cambio Nombre Archivo

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  
void selectionSort(int arr[], int n) 
{ 
   int i, j, min_idx; 
  
    for (i = 0; i < n-1; i++) 
    { 
        min_idx = i; 
        for (j = i+1; j < n; j++) 
          if (arr[j] < arr[min_idx]) 
            min_idx = j; 
        swap(&arr[min_idx], &arr[i]); 
    } 
}



void printArray(int arr[], int n) 
{ 
    int i; 
    for (i = 0; i < n; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 


int main(){
	
    FILE    *f;
    int     array[TAM];
    int     i, j, ctr = 0;
	int n = sizeof(arr)/sizeof(arr[0]); 
    f = fopen(NOMBREAR, "r");

    while((!feof(f)) && (ctr < TAM))
    {
        fscanf(f, "%d ", &array[ctr++]);
    }
    
    fclose(f); 

    

    printf("Despues");
   clock_t begin = clock();
    
      selectionSort(array,ctr);
    
    

    

  clock_t end = clock();
  double time_spent = (double)(end - begin);

    FILE    *ff;
     ff = fopen("Final.txt", "ab");
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    fprintf(ff, "antes: %d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);

    for(j=0;j<TAM-1;j++){
	fprintf(ff, "%d  ", array[j]);

     }
    time_t t2 = time(NULL);
    struct tm tm2 = *localtime(&t2);
    fprintf(ff, "despues: %d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);

    fclose(ff);
    




   

}
