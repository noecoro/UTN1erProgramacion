/*
 * Cliente.c
 *
 *  Created on: 12 may. 2020
 *      Author: yusmelis
 */
#include <stdio.h>
#include <stdlib.h>
#include "Cliente.h"

 int cli_inicializarArray(Cliente* pArray, int limite)
{
	int retorno=-1;
	int i;

	if(pArray!=NULL && limite>0)
	{
		for(i=0;i<limite;i++)
		{
			pArray[i].isEmpty=1;
			retorno=0;
		}
	}
return retorno;
}

 int cli_altaArray(Cliente* array, int limite, int i)
{

	Cliente bufferCliente;
	int contadorID = 1;
	int respuesta=-1;

	if(array!=NULL && i>=0 && limite>0 && limite>0 && i<limite)
	{

		if(utn_getNombre(bufferCliente.nombre, NOMBRE_LEN, "ingrese nombre", "error ",2) == 0 &&
				utn_getNombre(bufferCliente.apellido, APELLIDO_LEN, "Ingrese su apellido", "error ",2)==0 &&
				utn_getCuit(bufferCliente.cuit, CUIT_LEN,"ingrese Cuit", "error",2)==0)
				{
					respuesta = 0;
					bufferCliente.id = contadorID;
					contadorID++;
					bufferCliente.isEmpty = 0;
					array[i] = bufferCliente;
				}
	}

	return respuesta;
}


int cli_getEmptyIndex(Cliente* array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			if(array[i].isEmpty == 1)
			{
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}


