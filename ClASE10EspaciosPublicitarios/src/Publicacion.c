#include "Publicacion.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utn.h"



/**
 * \brief Inicializa el array
 * \param array Array de clientes a ser actualizado
 * \param limite Limite del array de Publicaciones
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pub_inicializarArray(Publicacion* array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		respuesta = 0;
		for(i=0;i<limite;i++)
		{
			array[i].isEmpty = 1;
		}
	}
	return respuesta;
}

/**
 * \brief Buscar primer posicion vacia
 * \param array Array de Publicaciones
 * \param limite Limite del array de Publicaciones
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
int pub_getEmptyIndex(Publicacion* array,int limite)
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


