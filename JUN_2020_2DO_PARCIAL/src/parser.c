#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Envio.h"

/** \brief Parsea los datos los datos de los envios desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEnvios LinkedList*
 * \return el proximo id si lo logro correctamente o -1 de los contrario
 *
 */
int parser_EnviosFromText(FILE* pFile , LinkedList* pArrayListEnvios)
{
	int retorno = -1;
	char auxiliarIdProducto [4096];
	char auxiliarNombre[4096];
	char auxiliarIdCamion[4096];
	char auxiliarZona[4096];
	char auxiliarKilometros[4096];
	char auxiliarTipo[4096];
	char auxiliarCosto [4096] = "0";
	Envio* pEnvio;

		if( pFile != NULL && pArrayListEnvios !=NULL )
			{
				do
				{
					if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,\n]\n",auxiliarIdProducto, auxiliarNombre, auxiliarIdCamion, auxiliarZona, auxiliarKilometros, auxiliarTipo )== 6)
					{
						retorno = 1;

						if((pEnvio = envio_newParametros( auxiliarIdProducto, auxiliarNombre, auxiliarIdCamion, auxiliarZona, auxiliarKilometros, auxiliarTipo, auxiliarCosto )) != NULL)
							{
								if(ll_add(pArrayListEnvios, pEnvio)==0)
								{
									retorno=0;

								}


							}
					}

				}while(!feof(pFile));

				}


    return retorno;
}
