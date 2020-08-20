/*
 ============================================================================
 Name        : arrays.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "UTN.h"

#define EDADESSIZE	5

void imprimirArray(int listaDeEdades[],int len);

int main(void)
{

	// EJERCICIO: Pedirle al usuario 5 edades y LUEGO
	// imprimir las 5 edades. Definir un array de 5 posiciones.
	// y usar la funcion utn_getNumero() para pedir los valores


	int edad;

	int edades[EDADESSIZE];
	int i;

	// recorro para cargar en forma secuencial
	for(i=0; i<EDADESSIZE; i++)
	{
		if(utn_getNumero(&edad,"Ingrese edad:","Esta edad no va\n",1,120,3)==0)
		//if(utn_getNumero(&  (edades[i]) ,"Ingrese edad:","Esta edad no va\n",1,120,3)==0)
		{
			 //en edades escribo edad en la posicion "i"
			 edades[i] = edad; // guardo edad en el casillero "i"
		}
		else
		{
			printf("Sonaste no tenes idea lo que es una eda'\n");
		}
	}

	// recorro para imprimir
	imprimirArray(edades,EDADESSIZE);

	return EXIT_SUCCESS;
}

//EL NOMBRE DEL ARRAY ES LA DIRECCCION DE MEMORIA DONDE COMIENZA EL ARRAY
//Al recibir un array, tambien se recibe su tamaño

// recibir array -> por referencia (no se hace una copia, es el meesmo)
//void imprimirArray(int* listaDeEdades)
void imprimirArray(int listaDeEdades[],int len)
{
	int i;
	for(i=0; i<len; i++)
	{
		printf("%d ",listaDeEdades[i]);
	}
}
