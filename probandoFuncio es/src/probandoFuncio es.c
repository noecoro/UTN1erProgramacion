/*
 ============================================================================
 Name        : probandoFuncio.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
int utn_GetNumero ( int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

int main(void) {
	int numero;
	numero= utn_GetNumero(&numero, "ingrese un numero", "error", 1,9,3);
	printf("el numero es %d", numero);

	return EXIT_SUCCESS;
}

int utn_GetNumero ( int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)

{
	int retorno=-1;
	int bufferInt;
	if(pResultado != NULL && mensaje!= NULL && mensajeError != NULL && minimo<maximo && reintentos>=0)
	{
		do{
				printf("%s", mensaje);

				if(getInt(&bufferInt)==1 &&
						bufferInt >= minimo &&
						bufferInt <= maximo)
				{
					*pResultado= bufferInt;
					retorno=0;
					break;
				}
				__fpurge(stdin);
				printf("%s", mensajeError);
				reintentos--;

		}while(reintentos>=0);
	return retorno;

	}
}
