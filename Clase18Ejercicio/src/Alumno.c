/*
 * Alumno.c
 *
 *  Created on: 6 jun. 2020
 *      Author: yusmelis
 */
#include <stdio.h>
#include <stdlib.h>
#include "Alumno.h"
#include "string.h"



Alumno* alumno_new (void)
{
	return (Alumno*)malloc(sizeof(Alumno));
}

Alumno* alumno_newParametro (char* nombre, int id, float altura)
{

	Alumno* punteroAlumno=NULL;
	punteroAlumno= alumno_new();
	if(punteroAlumno!=NULL)
	{
		strncpy(punteroAlumno->nombre, nombre ,NOMBRE_LEN);
		punteroAlumno->id= id;
		punteroAlumno->altura=altura;
		return punteroAlumno;
	}
	return NULL;
}

void alumno_delete(Alumno* this)
{
	if(this !=NULL)
	{
		free(this);
	}

}
//********************************************************************************
int alumno_deleteIndexInArray(Alumno* arrayPuntero[],  int limite, int index)
{
	int retorno=-1;

	if(arrayPuntero!=NULL && index >=0 && index<limite&& arrayPuntero[index]!=NULL)
	{
		retorno=0;
		alumno_delete(arrayPuntero[index]);
		arrayPuntero[index]= NULL;

	}
	return retorno;
}
int alumno_initArray(Alumno* arrayPuntero[], int limite)
{
	int retorno=-1;
	int i;
	if(arrayPuntero!=NULL && limite > 0)
	{
		retorno=0;
		for(i=0;i<limite;i++)
		{
			arrayPuntero[i]= NULL;
		}
	}
	return retorno;
}


int alumno_buscarLibre(Alumno* arrayPuntero[], int limite)
{
	int retorno=-1;
	int i;
	if(arrayPuntero!=NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			if(arrayPuntero[i]==NULL)
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}


int alumno_imprimirArray(Alumno* arrayPuntero[], int limite)
{
	int retorno=-1;
	int i;
	if(arrayPuntero!=NULL && limite > 0)
	{
		printf("\n------LISTA DE ALUMNOS---------");
		for(i=0;i<limite;i++)
		{

			if(arrayPuntero[i]!=NULL)
			{
				printf("\nnombre: %s - id: %d  altura: %f",arrayPuntero[i]->nombre, arrayPuntero[i]->id, arrayPuntero[i]->altura );
			}
		}
	}
	return retorno;
}

int alumno_buscarId(Alumno* arrayPuntero[], int limite, int id)
{
	int retorno=-1;
	int i;
	if(arrayPuntero!=NULL && limite > 0 && id>0)
	{
		retorno= -2;
		for(i=0;i<limite;i++)
		{
			if(arrayPuntero[i]!=NULL && arrayPuntero[i]->id== id)
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}


int alumno_agregarAlumno(Alumno* arrayPuntero[], int limite, char* nombre, int id, float altura)
{

	int indiceLibre;
	int retorno=-1;

	if(arrayPuntero!=NULL && limite > 0 && nombre!=NULL && id>0)
	{
		indiceLibre=alumno_buscarLibre(arrayPuntero, limite);
			if(indiceLibre>=0)
			{
				arrayPuntero[indiceLibre]= alumno_newParametro(nombre, id, altura);
				retorno=indiceLibre;
			}
	}
	return retorno;
}

int alumno_EliminarPorId(Alumno* arrayPuntero[], int limite, int id)
{
	int retorno=-1;
	int indiceBorrar;
	if(arrayPuntero!=NULL && limite > 0 && id>0)
	{
		retorno= -2;

		indiceBorrar= alumno_buscarId(arrayPuntero, limite,id);

		if(indiceBorrar>=0)
			{
				if(alumno_deleteIndexInArray(arrayPuntero, limite,indiceBorrar)==0)
				{
					retorno=0;
				}
			}
	}
	return retorno;
}
