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
			if( arrayPublicaciones[i].isEmpty==0 &&arrayPublicaciones->idCliente==auxiliarIdCliente)
			{
				retorno = 0;
				printf("\nlas siguientes publicaciones seran eliminada:\nID: %d - Texto: %s - Estado: %s - Numero de Rubro: %d - IdCliente: %d",arrayPublicaciones[i].id, arrayPublicaciones[i].texto, TXT_ESTADOS[ arrayPublicaciones[i], arrayPublicaciones[i].numeroDeRubro, arrayPublicaciones[i].idCliente);

			}
		}
	}
	return retorno;
}


int info_imprimirContratacionesConImporte(Publicacion* arrayContrataciones,int limiteContrataciones,Cliente* arrayPantallas,int limitePantallas,char* auxiliarCuit)
{
	int retorno = -1;
	int i;
	int indiceArrayPantalla;
	int idPantalla;
	float auxiliarImporte;
	if(arrayContrataciones != NULL && limiteContrataciones > 0 && arrayPantallas != NULL && limitePantallas > 0 && auxiliarCuit != NULL)
	{
		for(i=0;i<limiteContrataciones;i++)
		{
			if(arrayContrataciones[i].isEmpty)
			{
				continue;
			}
			if(strncmp(arrayContrataciones[i].estado,auxiliarCuit,CUIT_LEN) == 0)
			{
				retorno = 0;
				idPantalla = arrayContrataciones[i].idCliente;
				indiceArrayPantalla = cli_buscarId(arrayPantallas,limitePantallas,idPantalla);
				auxiliarImporte = arrayContrataciones[i].numeroDeRubro * arrayPantallas[indiceArrayPantalla].precio;
				printf("\nID: %d - Archivo: %s - Cuit: %s - Dias: %d - IdPantalla: %d - Importe %.2f"
															,arrayContrataciones[i].id
															,arrayContrataciones[i].texto
															,arrayContrataciones[i].estado
															,arrayContrataciones[i].numeroDeRubro
															,arrayContrataciones[i].idCliente
															,auxiliarImporte);
			}
		}
	}
	return retorno;
}

#define CANTIDAD_CLIENTES 1000

int info_imprimirContratacionesConImportePorCliente(Publicacion* arrayContrataciones,int limiteContrataciones,Cliente* arrayPantallas,int limitePantallas)
{

	int retorno = -1;
	char listaCuit[CANTIDAD_CLIENTES][CUIT_LEN];
	int i;
	int j;
	int flagExisteCuit;
	int indiceCuitLibre = 0;
	float auxiliarDeuda;
	float deudaMaxima;
	int indiceClienteDeudaMaxima;

	for(i=0;i<limiteContrataciones;i++)
	{
		flagExisteCuit = 0;
		if(arrayContrataciones[i].isEmpty == 0)
		{
			for(j=0;j<indiceCuitLibre;j++)
			{
				if(strncmp(arrayContrataciones[i].estado,listaCuit[j],CUIT_LEN ) == 0)
				{
					flagExisteCuit = 1;
					break;
				}
			}
			if(flagExisteCuit == 0)
			{
				strncpy(listaCuit[indiceCuitLibre],arrayContrataciones[i].estado,CUIT_LEN);
				indiceCuitLibre++;
			}
		}
	}

	for(j=0;j<indiceCuitLibre;j++)
	{
		printf("\n\n El cliente con cuit %s\n",listaCuit[j]);
		info_imprimirContratacionesConImporte(arrayContrataciones,limiteContrataciones,arrayPantallas,limitePantallas,listaCuit[j]);
	}



	for(j=0;j<indiceCuitLibre;j++)
	{

		info_calcularDeudaCliente(arrayContrataciones,limiteContrataciones,arrayPantallas,limitePantallas,listaCuit[j], &auxiliarDeuda);
		if(j == 0|| (auxiliarDeuda > deudaMaxima))
		{
			deudaMaxima = auxiliarDeuda;
			indiceClienteDeudaMaxima = 	j;
		}

	}
	printf("\n\n El cliente con mas deuda es cuit %s - debe %.2f\n",listaCuit[indiceClienteDeudaMaxima],deudaMaxima);

	return retorno;



}


int info_calcularDeudaCliente(Publicacion* arrayContrataciones,int limiteContrataciones,Cliente* arrayPantallas,int limitePantallas,char* auxiliarCuit, float* deuda)
{
	int retorno = -1;
	int i;
	int indiceArrayPantalla;
	int idPantalla;
	float auxiliarDeuda=0;
	if(arrayContrataciones != NULL && limiteContrataciones > 0 && arrayPantallas != NULL && limitePantallas > 0 && auxiliarCuit != NULL)
	{
		for(i=0;i<limiteContrataciones;i++)
		{
			if(arrayContrataciones[i].isEmpty)
			{
				continue;
			}
			if(strncmp(arrayContrataciones[i].estado,auxiliarCuit,CUIT_LEN) == 0)
			{
				idPantalla = arrayContrataciones[i].idCliente;
				indiceArrayPantalla = cli_buscarId(arrayPantallas,limitePantallas,idPantalla);
				auxiliarDeuda = auxiliarDeuda + (arrayContrataciones[i].numeroDeRubro * arrayPantallas[indiceArrayPantalla].precio);
			}
		}
		retorno = 0;
		*deuda=auxiliarDeuda;
	}
	return retorno;
}




