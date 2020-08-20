#include "Publicacion.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utn.h"

static const char TXT_ESTADOS[2][9]={"ACTIVA","PAUSADA"};

/**
 * \brief Imprime los datos de una publicacion
 * \param pElemento Puntero a la publicacion que se busca imprimir
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pub_imprimir(Publicacion* pElemento)
{
	int retorno=-1;
	if(pElemento != NULL && pElemento->isEmpty == 0)
	{
		retorno=0;
		printf("\nID: %d - Texto: %s - Estado: %s - Numero de Rubro: %d - IdCliente: %d",pElemento->id,pElemento->texto,TXT_ESTADOS[ pElemento->estado],pElemento->numeroDeRubro,pElemento->idCliente);
	}
	return retorno;
}

/**
 * \brief Imprime el array de Publicaciones
 * \param array Array de Publicaciones a ser actualizado
 * \param limite Limite del array de Publicaciones
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pub_imprimirArray(Publicacion* array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		respuesta = 0;
		for(i=0;i<limite;i++)
		{
			pub_imprimir(&array[i]);
		}
	}
	return respuesta;
}

/**
 * \brief Inicializa el array
 * \param array Array de Publicaciones a ser actualizado
 * \param limite Limite del array de publicaciones
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
 * \brief Da de alta una Publicacion en una posicion del array
 * \param array Array de Publicaciones a ser actualizado
 * \param limite Limite del array de Publicaciones
 * \param indice Posicion a ser actualizada
 * \param id Identificador a ser asignado a la publicacion
 * \param id Identificador del cliente que realiza la publicacion
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pub_altaArray(Publicacion* array,int limite, int indice, int* idPublicacion, int idCliente)
{
	int respuesta = -1;
	Publicacion bufferPublicacion;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && idPublicacion != NULL)
	{
		if(	!utn_getDescripcion(bufferPublicacion.texto,TEXTO_LEN,"\nTexto? ", "\nError",2) &&
			!utn_getNumero(&bufferPublicacion.numeroDeRubro,"\n numeroDeRubro? ", "\nError",1,1000,2))
		{
			respuesta = 0;
			bufferPublicacion.estado = 0;
			bufferPublicacion.idCliente = idCliente;
			bufferPublicacion.id = *idPublicacion;
			bufferPublicacion.isEmpty = 0;
			array[indice] = bufferPublicacion;
			(*idPublicacion)++;
		}
	}
	return respuesta;
}

/**
 * \brief Da de alta una Publicacion en una posicion del array de manera forzada
 * \param array Array de Publicaciones a ser actualizado
 * \param limite Limite del array de Publicaciones
 * \param indice Posicion a ser actualizada
 * \param id Identificador a ser asignado ala Publicacion
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pub_altaForzadaArray(Publicacion* array,int limite, int indice, int* idPublicacion, int idCliente,char* texto,int numeroDeRubro)
{
	int respuesta = -1;
	Publicacion bufferPublicacion;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && idPublicacion != NULL)
	{
		strncpy(bufferPublicacion.texto,texto,TEXTO_LEN);
		bufferPublicacion.estado = 0;
		bufferPublicacion.numeroDeRubro = numeroDeRubro;
		bufferPublicacion.idCliente = idCliente;
		respuesta = 0;
		bufferPublicacion.id = *idPublicacion;
		bufferPublicacion.isEmpty = 0;
		array[indice] = bufferPublicacion;
		(*idPublicacion)++;

	}
	return respuesta;
}


/**
 * \brief Actualiza los datos de una Publicacion en una posicion del array
 * \param array Array de Publicaciones a ser actualizado
 * \param limite Limite del array de Publicaciones
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pub_modificarArray(Publicacion* array,int limite, int indice)
{
	int respuesta = -1;
	int  dias;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0)
	{
		if(	!utn_getNumero(&dias,"\n DIAS? ", "\nError",1,365,2))
		{
			respuesta = 0;
			array[indice].numeroDeRubro = dias;
		}
	}
	return respuesta;
}

/**
 * \brief Actualiza una posicion del array
 * \param array Array de contrataciones a ser actualizado
 * \param limite Limite del array de contrataciones
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pub_bajaArray(Publicacion* array,int limite, int auxiliarId)
{
	int i, respuesta = -1;
	if(array != NULL && limite > 0 )
	{

		for(i=0;i<limite;i++)
		{
			if(array[i].idCliente == auxiliarId)
			{
			array[i].isEmpty = 1;
			respuesta = 0;
			}
		}
	}
	return respuesta;
}


/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array contratacion Array de contratacion
* \param limite int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int pub_buscarId(Publicacion array[], int limite, int valorBuscado)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0 && valorBuscado >= 0)
	{
		for(i=0;i<limite;i++)
		{
			if(array[i].id == valorBuscado)
			{
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}

/**
 * \brief Buscar primer posicion vacia
 * \param array Array de contrataciones
 * \param limite Limite del array de contrataciones
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













