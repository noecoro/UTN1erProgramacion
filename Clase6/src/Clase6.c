

#include <stdio.h>
#include <stdlib.h>
#include "macos.h"
#include "utn.h"

#define QTY_EMPLEADOS 9

int printArrayInt(int* pArray, int limite);
int ordenarArrayIntBubbleSort(int* pArray, int limite);
int ordenarArrayIntMal(int* pArray, int limite);
int ordenarArrayIntInsertion(int* pArray, int limite);


int testSort(int(*ordenar)(int*,int));

int main(void)
{
	char cadena[3000];
/*	while(1)
	{
		myGets(cadena, 10);
		printf("\n-\n%s",cadena);
	}
*/
	macos_pause();
	printf("\n\n TEST INSERTION SORT\n");
	testSort(ordenarArrayIntInsertion);
	macos_clear();
	printf("\n\n TEST INSERTION SORT\n");
/*	printf("\n\n TEST BUBBLE SORT\n");
	testSort(ordenarArrayIntBubbleSort);
	printf("\n\n TEST BUBBLE SORT MAL\n");
	testSort(ordenarArrayIntMal);
*/

	return EXIT_SUCCESS;
}


int testSort(int(*ordenar)(int*,int))
{
	int arrayEdades[QTY_EMPLEADOS] = {54,26,93,17,77,31,44,55,27};
	int respuesta;

	printArrayInt(arrayEdades,QTY_EMPLEADOS);
	respuesta = ordenar(arrayEdades,QTY_EMPLEADOS);
	if( respuesta >= 0)
	{
		printf("\n\n Iteraciones : %d\n\n",respuesta);
	}
	printArrayInt(arrayEdades,QTY_EMPLEADOS);

	respuesta = ordenar(arrayEdades,QTY_EMPLEADOS);
	if( respuesta >= 0)
	{
		printf("\n\n Iteraciones : %d\n\n",respuesta);
	}

	return EXIT_SUCCESS;
}


/**
 * \brief Imprime a modo DEBUG la informacion de un array de enteros
 * \param pArray Es el puntero al array a ser ordenado
 * \param size Es la longitud del array
 * \return 0 si Ok o -1 para indicar un error
 *
 */
int printArrayInt(int* pArray, int limite)
{
	int retorno = -1;
	int i;
	if(pArray != NULL && limite >= 0)
	{
		retorno = 0;
		for(i=0;i<limite;i++)
		{
			printf("\n[DEBUG]  Indice: %d - Valor: %d",i,pArray[i]);
		}
	}
	return retorno;
}

/**
 * \brief Ordena un array de enteros DESC
 * \param pArray Es el puntero al array a ser ordenado
 * \param size Es la longitud del array
 * \return Cantidad de iteraciones necesarias para ordenar si Ok o -1 para indicar un error
 *
 */
int ordenarArrayIntBubbleSort(int* pArray, int limite)
{
	int flagSwap;
	int i;
	int contador=0;
	int retorno = -1;
	int buffer;

	if(pArray != NULL && limite >= 0)
	{
		do
		{
			flagSwap=0;
			for( i=0 ; i<limite - 1 ; i++)
			{
				contador++;
				if(pArray[i] < pArray[i+1])
				{
					flagSwap = 1;
					buffer = pArray[i];
					pArray[i] = pArray[i+1];
					pArray[i+1] = buffer;
				}
			}
			limite--;
		}while(flagSwap);
		retorno = contador;
	}
	return retorno;
}




/**
 * \brief Ordena un array de enteros DESC MAL
 * \param pArray Es el puntero al array a ser ordenado
 * \param size Es la longitud del array
 * \return Cantidad de iteraciones necesarias para ordenar si Ok o -1 para indicar un error
 *
 */
int ordenarArrayIntMal(int* pArray, int limite)
{
	int i;
	int j;
	int contador=0;
	int retorno = -1;
	int buffer;



	if(pArray != NULL && limite >= 0)
	{
		for(i=0;i<limite -1;i++)
		{
			for(j=i+1;j<limite;j++)
			{
				if(pArray[i] < pArray[j])
				{
					buffer = pArray[i];
					pArray[i] = pArray[j];
					pArray[j] = buffer;

				}
				contador++;
			}
		}
		retorno = contador;
	}
	return retorno;
}



/**
 * \brief Ordena un array de enteros DESC INSERTION SORT
 * \param pArray Es el puntero al array a ser ordenado
 * \param size Es la longitud del array
 * \return Cantidad de iteraciones necesarias para ordenar si Ok o -1 para indicar un error
 *
 */
int ordenarArrayIntInsertion(int* pArray, int limite)
{
	int retorno = -1;
	int i;
	int j;
	int buffer;
	int contador=0;

	if(pArray != NULL && limite >= 0)
	{
		for(i=1;i<limite;i++)
		{
			buffer = pArray[i];
			for(j=i ; j>0 && (buffer < pArray[j-1]) ; j--, contador++)
			{
				pArray[j] = pArray[j-1];
			}
			pArray[j] = buffer;
		}
		retorno = contador;
	}
	return retorno;
}




