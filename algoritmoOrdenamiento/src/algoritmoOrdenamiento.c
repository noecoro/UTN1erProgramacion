/*
 ============================================================================
 Name        : algoritmoOrdenamiento.c
 Author      : yus
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "UTN.h"

#define QTY_EMPLEADOS 9


int ordenarArraysInt( int* pArray, int limite );
int main(void)
{
	int arrayEdades[QTY_EMPLEADOS]={54,26,93,17,77,31,44,55,27};
	int respuesta;

	printArrayInt(arrayEdades,QTY_EMPLEADOS);

	respuesta= ordenarArraysInt(arrayEdades,QTY_EMPLEADOS);
	if (respuesta>0)
	{
		printf("\n iteracciones: %d",respuesta);
	}
	printArrayInt(arrayEdades,QTY_EMPLEADOS);
	return EXIT_SUCCESS;
}
int ordenarArraysInt( int* pArray, int limite )
{
	int retorno=-1;
	int flagSwap;
	int contador=0;
	int i;
	int buffer;
	int nuevoLimite;

	if( pArray != NULL && limite >= 0 )
	{
		nuevoLimite=limite-1;
		do
		{
			flagSwap=0;
			for(i=0;i<nuevoLimite-1;i++)
			{
				if(pArray[i] < pArray [i+1])
				{
					flagSwap=1;
					buffer = pArray[i];
					pArray[i]= pArray [i+1];
					pArray [i+1]=buffer;
				}
			contador++;
			nuevoLimite--;
			}
		}while(flagSwap);
		retorno=contador;
	}
	return retorno;

}

