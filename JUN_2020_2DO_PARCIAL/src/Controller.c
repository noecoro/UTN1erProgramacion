#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "parser.h"
#include "Controller.h"

#include "Envio.h"
#include "utn.h"

#define NOMBRE_ARCHIVO_LEN 100


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).

 * \param pArrayListEnvios LinkedList*
 * \return int
 *
 */
int controller_loadFromText( LinkedList* pArrayListEnvios)
{
		int retorno = -1 ;
		char nombreDelArchivo[NOMBRE_ARCHIVO_LEN];
		FILE* fpArchivo = NULL;
		if(pArrayListEnvios!= NULL)
		{
			if((utn_getDescripcion(nombreDelArchivo, NOMBRE_ARCHIVO_LEN, " Ingrese el nombre del Archivo", "Error! Nombre invalido", 3))==0)
				{

					strncat(nombreDelArchivo, ".csv", sizeof(nombreDelArchivo));


					fpArchivo = fopen(nombreDelArchivo,"r");
						if(fpArchivo != NULL)
						{

								if(( parser_EnviosFromText(fpArchivo, pArrayListEnvios))==0)
								{
										retorno=0;
										printf("\n carga realizada con exito\n");
								}
								fclose(fpArchivo);

						}
						else{
							 printf("\n archivo no encontrado \n");
							}
				}

		}

	return retorno;

}
/** \brief Crea un archivo de costos generados por la zona decidida por el usuario (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
LinkedList* controller_GenerarNuevoArchivoCostoPorZona(  LinkedList* pArrayListEnvios )
{

	char auxiliarZonaDeseada [ZONA_LEN];
	char zonaFiltro [ZONA_LEN];
	int i;

	int  auxiliarIdProducto;
	char auxiliarNombre [NOMBRE_LEN] ;
	int auxiliarIdCamion;
	char auxiliarZona[ZONA_LEN];
	float auxiliarKilometros;
	int auxiliarTipo;
	float auxiliarCosto;
	LinkedList* listaFiltrada;

	FILE* fpArchivo = NULL;

	Envio* pElement;

			if(pArrayListEnvios!= NULL)
			{
				if(utn_getDescripcion(zonaFiltro, ZONA_LEN ,"ingrese el nombre de la zona que desea filtrar", "Error!, intente nuevamente", 2)==0)
					 {
						strncpy (auxiliarZonaDeseada, zonaFiltro, ZONA_LEN);
						strncat(auxiliarZonaDeseada, ".csv", sizeof(auxiliarZonaDeseada));

							fpArchivo = fopen(auxiliarZonaDeseada,"w");
							if(fpArchivo != NULL)
							{

			        			if((listaFiltrada = ll_filter( pArrayListEnvios , envio_EsZona , zonaFiltro))!= NULL)
			        			{
			        				envio_ImprimirEnvios(listaFiltrada);
			        				fprintf(fpArchivo," \nId Producto  \tNombre Del producto \t Id Del Camion \t Zona De Destino \t  Km Recorridos \t  Tipo de Entrega \t Costo de Envio \n");
			        				for(i=0; i< ll_len(listaFiltrada); i++)
			        						{
			        							if((pElement=(Envio*)ll_get(listaFiltrada, i))!=NULL)
			        							{
			        								if(( lecturaEnConjuntoDeAtributos(pElement, &auxiliarIdProducto, auxiliarNombre, &auxiliarIdCamion, auxiliarZona, &auxiliarKilometros, &auxiliarTipo, &auxiliarCosto))==0)
			        									{
			        										fprintf(fpArchivo,"  %d,  %s,  %d,  %s, %.0f , %d , %.0f \n", auxiliarIdProducto, auxiliarNombre, auxiliarIdCamion, auxiliarZona, auxiliarKilometros, auxiliarTipo, auxiliarCosto);

			        									}

			        							}
			        						}


			        			}
							}

							fclose(fpArchivo);
					 }

			}



	return listaFiltrada;

}

