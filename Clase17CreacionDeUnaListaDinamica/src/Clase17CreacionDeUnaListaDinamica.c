/*
 ============================================================================
 Name        : Clase17CreacionDeUnaListaDinamica.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int pedirCantidad (int* numUno);

int main(void) {

	int cantidad;
	int* pArray;
	int i;

	if(pedirCantidad(&cantidad)==0)

	{
		pArray= (int*)malloc(sizeof(int)*cantidad);
		if(pArray!=NULL)
		{
			for(i=0;i<cantidad; i++)
			{
				pArray[i] = 0; //o puedo colocar *(pArray+i)
				printf("\n Array [%d] %d",i, pArray[i]);
			}
		}
	}


	return  0;
}

int pedirCantidad (int* numUno)
{
	int retorno=-1;
	int cantidadFunc;
	if(utn_getNumero(&cantidadFunc, "ingrese un numero","error, No es numero",1,1000,3)==0)
	{
		*numUno= cantidadFunc;
		retorno=0;
	}
	return retorno;
}
