/*
 * UTN.c
 *int UTN_GetNumero ( int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
 *
 *  Created on: 20 abr. 2020
 *      Author: yusmelis
 */

/* Funcion usada para realizar el calculo de factorial.
Se ingresa un numero entero positivo y devuelve como resultado otro entero positivo
retorna el resultado del factorial
*/
//calculo del factorial
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include <string.h>
#include <ctype.h>
#include <stdio_ext.h>
#include "UTN.h"


int Factorial (int n)
{
	int respuesta;
	if(n==1)
	{
		return 1;
	}
	respuesta= n * Factorial (n-1);
	return respuesta;
}



#include "UTN.h"
/* Funcion usada para verificar el ingreso de caracteres.
 * Chequea para que solo sean admitidas las letras S o N.
Se ingresa void y devuelve un entero sin signo
0 si se ingreso la N
1 si se ingreso la S

*/
unsigned int VerificarCaracter(void)
{
	char letra;

	printf("\n Ingrese opcion... S/ N?");
	letra = toupper (getchar()) ;

	while(letra!='S'&&letra!='N')
	{
		printf("ha ingresado una letra invalida");
		letra=toupper(getchar());
	}

	return (letra=='S');
}

int UTN_GetCaracter(char* pResultado, char* mensaje, char mensajeError, int minimo, int maximo,int reintentos)
{
	char buffer;
	int variableDeRetorno=-1;

	if(pResultado!=NULL && mensaje!=NULL && mensajeError != NULL && minimo<=maximo && reintentos>=0)
	{
		do

			{printf("%s",mensaje);
			__fpurge(stdin);
			scanf("%s",buffer);
			if(buffer>=minimo&&buffer<maximo)
			{
			   *pResultado=buffer;
				variableDeRetorno=0;

			}
			else
			{
				printf("%c",mensajeError);
				reintentos--;
			}
			}while(reintentos>=0);
	}
	return variableDeRetorno;
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

static int GetInt( int* pResultado)
{
	char buffer [50];
	scanf("%s",buffer);

	if (esNumerica(buffer,sizeof(buffer))==1)
	{
	pResultado= atoi(buffer);
	return 1;
	}
}
static int esNumerica (char* cadena, int limite)
{
	 int retorno=-1;
	 int i;
	 if(cadena != NULL && limite > 0)
	 	{
	 		retorno = 1;
			 for(i=0;i <= limite && i!= '/0';i++)
			 {
				if( cadena[0]=='+'||cadena[0]=='-')
				{
					continue;
				}
				if(cadena[i]<'0'|| cadena[i]>'9')
				{
					retorno=0;
					break;
				}
			 }
	 	}
 }


static int myGets(char*cadena, int longitud)
{
	char bufferString[5000];
	int retorno=-1;

	if(cadena != NULL && longitud>0)
	{
		__fpurge(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
		{
			if(bufferString[ strnlen(bufferString,sizeof(bufferString))-1]=='\n')

			{
				bufferString[strnlen(bufferString,sizeof(bufferString))]='\0';
			}
			if(strnlen(bufferString,sizeof(bufferString))<longitud)
			{
				strncpy(cadena,bufferString, longitud);
				retorno=0;
			}


		}

	}
	return retorno;
}












/*
utn_getNumero
utn_getNumeroConSigno
utn_getNumeroConDecimales
utn_getTelefono
utn_getDNI
utn_getCUIT
utn_getEmail
utn_getTexto


utn_getNumero:
◦ getInt
◦ esNumero
utn_getNumeroConDecimales:
◦ getFloat
◦ esNumeroDecimal
utn_getTexto
◦ getString
utn_getEmail:
◦ getString
◦ esEmail*/
