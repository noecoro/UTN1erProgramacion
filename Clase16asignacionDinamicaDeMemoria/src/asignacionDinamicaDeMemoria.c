/*
 ============================================================================
 Name        : asignacionDinamicaDeMemoria.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

 	 * Segmento del condigo: guarda las instrucciones en lenguaje maquina del programa
	 * Segmento de Memoria Estatica: se guardan las variables globales del programa
	 * Segmento de pila:cuando se llama a la funcion entra en este segmento y alli se gurdan:
	  los llamados, los parametros, las variables locales y demas informacion mmecesaria del programa
	 *Segmento de heap: se guardan las variables que han sido creadas dinamicamente en tiempoś de ejecucion

	 *******Reserva Dinamica de Memoria*******
	            a diferencia de malloc, la funcion calloc inicializa el vector en 0
				ambas funciones devuelven NULL si la reserva de memoria no puede realizarce

	    ------malloc: void* malloc (unsigned int numBytes);
	    	esta devuelve un puntero de tipo de datos sin tipo, realizar casting

		------calloc: void* malloc (unsigned numElementos,unsigned int numBytes Elemento);

 	 *******Redimensionamiento Dinamica de Memoria*******
 	   ------ realloc(): void* realloc( ptr, cantidad * unsigned int size);
		intenta cambiar el tamaño de un bloque de memoria previamente asignado.
		si el nuevo tamano es mas grande la memoria es agregada al final del bloque, si es mas pequeño
		el sobrante permanece sin cambios

		si el bloque no puede redimensionado  se asigna un nuevo bloque de memoria y se copia el contenido
		anterior generando un nuevo puntero, de lo contrario devuelve NULL

 	 *******Liberacion  Dinamica de Memoria*******

  	  	 -----free:  void free(void* p);
  	  	 Durante la ejecucion del programa puede ser necesario liberar memoria reservada

*/


#include <stdio.h>
#include <stdlib.h>
#include "alfa.h"

int main(void) {
	 int *a;
	 a= (int*)malloc(sizeof(int));
	 *a = 3;
	 if(a==NULL)
	 {
		 printf("NO QUEDA MEMORIA");//para evitar posibles fallos siempre comprobar
	 }

	 int *h;
	 int i;
	 h= (int*)malloc(sizeof(int)*20);
	 if(a!=NULL)
	 {
		 for(i=0;i<20;i++)
		 {
			 *(a+i)=0;
		 }
	 }


	 int *b;
	 b= (int*)calloc(20,sizeof(int)); //arroja un array de 20 elementos inicializado en cero

	 unsigned long int *c;
	 if((c= (unsigned long int*)malloc(sizeof(unsigned long int)))==NULL)
	 exit(0);//salimos del progama

	 struct ALFA* d;
	 if((d= (struct ALFA*)malloc(sizeof(struct ALFA)))==NULL)
		 exit(0);

	 char *f;
	 if((f= (char*)malloc(sizeof(char)))==NULL)
		 exit(0);

	 char* pAuxiliar;
	 pAuxiliar=(char* )realloc(f,4*(sizeof(char)));
	 if (pAuxiliar!=NULL)
	 {
		 f= pAuxiliar;
	 }
	 else
		 printf( "NO QUEDA MEMORIA");



	 int* g;
	 if(( g = (int*)malloc(sizeof(int)))==NULL)
		exit(0);
	free(g);



	return EXIT_SUCCESS;
}
