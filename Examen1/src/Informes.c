/*
 * Informes.c
 *
 *  Created on: May 5, 2020
 *      Author: Mauro
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Informes.h"

#include "Cliente.h"
#include "Publicacion.h"

static const char TXT_ESTADOS[2][9]={"ACTIVA","PAUSADA"};

int info_imprimirPublicacionesContratadasConElIdCliente(Publicacion* arrayPublicaciones,int limitePublicaciones,int* auxiliarIdCliente)
{
	int retorno = -1;
	int i;

	if(arrayPublicaciones != NULL && limitePublicaciones> 0  && auxiliarIdCliente!= NULL)
	{
		for(i=0;i<limitePublicaciones;i++)
		{
			if( arrayPublicaciones[i].isEmpty==0 && arrayPublicaciones[i].idCliente == *auxiliarIdCliente)
			{
				retorno = 0;
				printf("\nlas siguientes publicaciones seran eliminada:\nID: %d - Texto: %s - Estado: %s - Numero de Rubro: %d - IdCliente: %d",arrayPublicaciones[i].id, arrayPublicaciones[i].texto, TXT_ESTADOS[ arrayPublicaciones[i].estado], arrayPublicaciones[i].numeroDeRubro, arrayPublicaciones[i].idCliente);

			}
		}
	}
	return retorno;
}



