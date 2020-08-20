/*
 ============================================================================
 Name        : Clase6_1_1H.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : {54,26,93,17,77,31,44,55,27};
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define QTY_ALUMNOS 9

int printArray(int* pArray, int limite);
int ordenarArray(int* pArray, int limite);
int ordenarArrayMuyMal(int* pArray, int limite);

int main(void)
{
	int edades[QTY_ALUMNOS] = {54,26,93,17,77,31,44,55,27};
	int edades2[QTY_ALUMNOS] = {54,26,93,17,77,31,44,55,27};
	int respuesta;

	printArray(edades,QTY_ALUMNOS);
	respuesta = ordenarArray(edades,QTY_ALUMNOS);
	printf("\nVueltas: %d\n",respuesta);
	printArray(edades,QTY_ALUMNOS);

	respuesta = ordenarArray(edades,QTY_ALUMNOS);
	printf("\nVueltas Ordenado: %d\n",respuesta);
	printArray(edades,QTY_ALUMNOS);

	printf("\nMALLLLLLLLLLLL\n");
	printArray(edades2,QTY_ALUMNOS);
	respuesta = ordenarArrayMuyMal(edades2,QTY_ALUMNOS);
	printf("\nVueltas: %d\n",respuesta);
	printArray(edades2,QTY_ALUMNOS);

	respuesta = ordenarArrayMuyMal(edades2,QTY_ALUMNOS);
	printf("\nVueltas Ordenado: %d\n",respuesta);
	printArray(edades2,QTY_ALUMNOS);
	return EXIT_SUCCESS;
}


int ordenarArray(int* pArray, int limite)
{
	int retorno = -1;
	int i;
	int buffer;
	int flagSwap;
	int contador=0;
	int limiteVariable;
	if(pArray != NULL && limite > 0)
	{
		limiteVariable = limite-1;
		retorno = 0;
		do
		{
			flagSwap=0;
			for(i=0;i<limiteVariable;i++)
			{
				contador++;
				if(pArray[i] < pArray[i+1])
				{
					buffer=pArray[i];
					pArray[i] = pArray[i+1];
					pArray[i+1] = buffer;
					flagSwap = 1;
				}

			}
			limiteVariable--;
		}while(flagSwap);
		retorno = contador;
	}
	return retorno;
}

int ordenarArrayMuyMal(int* pArray, int limite)
{
	int i;
	int j;
	int buffer;
	int contador=0;

	for(i=0;i<limite-1;i++)
	{
		for(j=i+1;j<limite;j++)
		{
			contador++;
			if(pArray[i] < pArray[j])
			{
				buffer=pArray[i];
				pArray[i] = pArray[j];
				pArray[j] = buffer;
			}

		}
	}
	return contador;
}


int printArray(int* pArray, int limite)
{
	int i;
	int retorno = -1;
	if(pArray != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			printf("[DEBUG] INDEX: %d - VALUE: %d\n",i,pArray[i]);
		}
	}
	return retorno;
}












