/*
 ============================================================================
 Name        : Clase16EjercicioDeClase.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

Por cada array que gestiono de manera dinamica tengo que tener un size
ya que no me alcanza con el define porque el mismo va ir variando para saber cuando lugares tiene
el array
 */

#include <stdio.h>
#include <stdlib.h>

int initArray(int* pArray, int limite,int valor);
int impimirArray(int* pArray, int limite);
int resizeArray(int** pArray, int *sizeActual,int newSize);

int main(void) {
int* pArrayEdades=NULL;

int sizeArrayEdades=10;

pArrayEdades=(int*)malloc(sizeof(int)*sizeArrayEdades);
if (pArrayEdades!= NULL)
{
	if(!initArray(pArrayEdades, sizeArrayEdades,0))
	 {
		printf("init ok \n");
		 impimirArray(pArrayEdades, sizeArrayEdades);
	 }

	if(!resizeArray(&pArrayEdades,&sizeArrayEdades,25))// aca no puedo pasar el puntero por valor
		//tiene que ser por referencia para que la funcion relloc le pueda imputar las nueva direccion
	{
		printf("resize ok \n");
		impimirArray(pArrayEdades, sizeArrayEdades);
	}
}

return EXIT_SUCCESS;
}

int initArray(int* pArray, int limite,int valor)
{	int retorno =-1;
	int i;
	if(pArray!= NULL && limite>0)
	{
		for(i=0;i<limite; i++)
		{
			retorno=0;
			*(pArray+i)=valor; // si aqui coloco pArray[i]=valor cuando recibo el parametro lo
			// recibir como int pArray[]
		}

	}
	return retorno;
}

int impimirArray(int* pArray, int limite)
{	int retorno =-1;
	int i;
	if(pArray!= NULL && limite>0)
	{
		for(i=0;i<limite; i++)
		{
			retorno=0;
			printf("\n%d",*(pArray+i));

		}

	}
	return retorno;
}


int resizeArray(int** pArray, int *sizeActual,int newSize)
{

	int* pArrayTemporal=NULL;
	int retorno= -1;

	if(pArray != NULL && sizeActual!=NULL && newSize>=0 )
	{
	pArrayTemporal= (int*) realloc(*pArray,(sizeof(int)*newSize));
	if(pArrayTemporal!=NULL)
		{
			*sizeActual = newSize;
			*pArray= pArrayTemporal;
			pArrayTemporal=NULL;
			retorno=0;
		}
	}
return retorno;
}
