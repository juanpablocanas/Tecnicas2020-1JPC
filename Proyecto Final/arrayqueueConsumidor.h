#ifndef ARRAYQUEUE
#define ARRAYQUEUE

#include <stdio.h>
#include <stdlib.h>
#define CAP 100

#define PRINT(x) " (%s %d %d) ", x.nombre, x.id, x.edad

typedef struct Queue Queue;
typedef struct consumidor consumidor;
typedef consumidor type_d;

struct consumidor{
	char nombre[10];
	int id;
	int edad;
	
};

struct Queue{
   type_d a[ CAP ];
   int front, rear, n;
   void (*put) ( Queue *, type_d );
   void (*del) ( Queue * );
   void (*display) ( Queue * );
   int (*empty) ( Queue * );
};

void put( Queue * x, type_d e ){
   if( x->n == CAP ){
      fprintf( stderr, "Error: Queue is full\n" );
      return;
   }
   x->rear = ( x->rear + 1 ) % CAP;
   x->a[ x->rear ] = e;
   x->n++;
   return;
}

void del( Queue * x ){
   x->front = ( x->front + 1 ) % CAP;
   x->n--;
   return;
}


void display( Queue * x ){
   int i; 
   printf( "Queue: [front] " );
   for( i = 1; i <= x->n; i++ )
      printf( PRINT (x->a[ ( x->front + i ) % CAP ]) );
      
   printf( "[rear]\n" );
   return;
}

int empty( Queue * x ){
   return !x->n;
}




Queue createQueue( ){
   Queue q;
   q.front = q.rear = q.n = 0;
   q.put = &put;
   q.del = &del;
   q.display = &display;
   q.empty = &empty;
   
   return q;
} 

#endif
