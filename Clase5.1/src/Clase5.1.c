/*
 ============================================================================
 Name        : 1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"


#define QTY_EMPLEADOS 9

int imprimirArrayInt(int pArray[],int size);
int ordenarOpcionA(int pArray[],int size);
int ordenarOpcionB(int pArray[],int size);
int ordenarOpcionC(int pArray[],int size);

int main(void)
{
	int arrayEdades[QTY_EMPLEADOS] = {54,26,93,17,77,31,44,55,27};
	int arrayEdadesA[QTY_EMPLEADOS] = {54,26,93,17,77,31,44,55,27};
	int arrayEdadesB[QTY_EMPLEADOS] = {54,26,93,17,77,31,44,55,27};
	int arrayEdadesC[QTY_EMPLEADOS] = {54,26,93,17,77,31,44,55,27};
	int arraySalarios[QTY_EMPLEADOS];
	int i;
	int bufferEdad;
	int bufferSalario;
	int respuestaE;
	int respuestaS;
	int respuesta;
	int opcion;
/*
	for(i = 0; i < QTY_EMPLEADOS; i++)
	{
		respuestaE = utn_getNumero(&bufferEdad, "Edad?\n","Error tiene que ser de 18 a 65\n",18,65,2);
		respuestaS = utn_getNumero(&bufferSalario, "Salario?\n","Error tiene que ser de 1000 a 100000\n",1000,100000,2);
		if(respuestaE == 0 && respuestaS == 0)
		{
			arrayEdades[i] = bufferEdad;
			arraySalarios[i] = bufferSalario;
		}
	}
	imprimirArrayInt(arrayEdades,QTY_EMPLEADOS);
	imprimirArrayInt(arraySalarios,QTY_EMPLEADOS);
*/

	do
	{
		respuesta = utn_getNumero(&opcion, "1-Modificar Edad\n2-Modificar Salario\n3-Mostrar\n4-Ordenar Op A\n5-Ordenar Op B\n6-Ordenar Op C\n7-Salir\n","Error tiene que ser de 1 a 6\n",1,6,2);
		if(respuesta == 0)
		{
			switch(opcion)
			{
				case 1:
					respuesta = utn_getNumero(&i, "Indice de la Edad?\n","Error indice fuera de rango\n",0,QTY_EMPLEADOS,2);
					respuestaE = utn_getNumero(&bufferEdad, "Edad?\n","Error tiene que ser de 18 a 65\n",18,65,2);
					if(respuestaE == 0 && respuesta == 0)
					{
						arrayEdades[i] = bufferEdad;
					}
					break;
				case 2:
					respuesta = utn_getNumero(&i, "Indice del salario?\n","Error indice fuera de rango\n",0,QTY_EMPLEADOS,2);
					respuestaS = utn_getNumero(&bufferSalario, "Salario?\n","Error tiene que ser de 1000 a 100000\n",1000,100000,2);
					if(respuestaS == 0 && respuesta == 0)
					{
						arraySalarios[i] = bufferSalario;
					}
					break;
				case 3:
					imprimirArrayInt(arrayEdades,QTY_EMPLEADOS);
					//imprimirArrayInt(arraySalarios,QTY_EMPLEADOS);
					break;
				case 4:
					imprimirArrayInt(arrayEdadesA,QTY_EMPLEADOS);
					respuesta = ordenarOpcionA(arrayEdadesA,QTY_EMPLEADOS);
					if(respuesta > 0)
					{
						printf("\n\nOpcion A - Cantidad de Iteraciones: %d\n\n",respuesta);
					}
					imprimirArrayInt(arrayEdadesA,QTY_EMPLEADOS);
					break;
				case 5:
					imprimirArrayInt(arrayEdadesB,QTY_EMPLEADOS);
					respuesta = ordenarOpcionB(arrayEdadesB,QTY_EMPLEADOS);
					if(respuesta > 0)
					{
						printf("\n\nOpcion B - Cantidad de Iteraciones: %d\n\n",respuesta);
					}
					imprimirArrayInt(arrayEdadesB,QTY_EMPLEADOS);
					break;
				case 6:
					imprimirArrayInt(arrayEdadesC,QTY_EMPLEADOS);
					respuesta = ordenarOpcionC(arrayEdadesC,QTY_EMPLEADOS);
					if(respuesta > 0)
					{
						printf("\n\nOpcion C - Cantidad de Iteraciones: %d\n\n",respuesta);
					}
					imprimirArrayInt(arrayEdadesC,QTY_EMPLEADOS);
					break;

			}
		}
	}while(opcion != 7);

	return EXIT_SUCCESS;
}

/**
 * \brief Ordena un array de enteros de manera ascendente
 * \param pArray Es el puntero al array a ser ordenado
 * \param size Es la longitud del array
 * \return El numero de iteraciones reralizadas o -1 para indicar un error
 *
 */
int ordenarOpcionA(int pArray[],int size)
{
	int flagSwap=1;
	int i;
	int buffer;
	int retorno = -1;
	int contadorIteraciones=0;
	if(pArray != NULL && size > 0)
	{
		while(flagSwap)
		{
			flagSwap = 0;
			for(i = 0 ; i < size-1 ; i++)
			{
				if(pArray[i] > pArray[i+1])
				{
					flagSwap = 1;
					buffer = pArray[i];
					pArray[i] = pArray[i+1];
					pArray[i+1] = buffer;
				}
				contadorIteraciones++;
			}
		}
		retorno = contadorIteraciones;
	}
	return retorno;
}

/**
 * \brief Ordena un array de enteros de manera ascendente
 * \param pArray Es el puntero al array a ser ordenado
 * \param size Es la longitud del array
 * \return El numero de iteraciones reralizadas o -1 para indicar un error
 *
 */
int ordenarOpcionB(int pArray[],int size)
{
	int flagSwap=1;
	int i;
	int buffer;
	int retorno = -1;
	int contadorIteraciones=0;
	int limite;

	if(pArray != NULL && size > 0)
	{
		limite = size-1;
		while(flagSwap)
		{
			flagSwap = 0;
			for(i = 0 ; i < limite ; i++,limite--)
			{
				if(pArray[i] > pArray[i+1])
				{
					flagSwap = 1;
					buffer = pArray[i];
					pArray[i] = pArray[i+1];
					pArray[i+1] = buffer;
				}
				contadorIteraciones++;
			}

		}
		retorno = contadorIteraciones;
	}
	return retorno;
}

/**
 * \brief Ordena un array de enteros de manera ascendente
 * \param pArray Es el puntero al array a ser ordenado
 * \param size Es la longitud del array
 * \return El numero de iteraciones reralizadas o -1 para indicar un error
 *
 */
int ordenarOpcionC(int pArray[],int size)
{
	int flagSwap=1;
	int i;
	int j;
	int buffer;
	int retorno = -1;
	int contadorIteraciones=0;

	if(pArray != NULL && size > 0)
	{
		for(i = 0 ; i < size-1 ; i++)
		{
			for(j = i+1 ; j < size ; j++)
			{
				if(pArray[i] > pArray[j])
				{
					flagSwap = 1;
					buffer = pArray[i];
					pArray[i] = pArray[j];
					pArray[j] = buffer;
				}
				contadorIteraciones++;
			}
		}
		retorno = contadorIteraciones;
	}
	return retorno;
}



/**
 * \brief Imprime a modo DEBUG la informacion de un array de enteros
 * \param pArray Es el puntero al array a ser ordenado
 * \param size Es la longitud del array
 * \return 0 si Ok o -1 para indicar un error
 *
 */
int imprimirArrayInt(int pArray[],int size)
{
	int i;
	int retorno=-1;
	if(pArray != NULL && size > 0)
	{
		for(i = 0; i < size; i++)
		{
			printf("El indice [%d] tiene como valor %d\n", i, pArray[i]);
		}
		retorno=0;
	}
	return retorno;
}






