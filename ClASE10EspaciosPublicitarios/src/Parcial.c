/*
 * >>>> Parcial 2020 <<<<
 *

 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include "Cliente.h"
#include "Publicacion.h"
#include "utn.h"

#define CANTIDAD_PUBLICACIONES 1000
#define CANTIDAD_CLIENTES 100

int main(void) {

	Cliente arrayClientes[CANTIDAD_CLIENTES];
	Publicacion arrayPublicacion[CANTIDAD_PUBLICACIONES];
	int idClientes=0;
	int opcion;
	int auxiliarIndiceCliente;
	int auxiliarIndicePublicacion=0;
	int auxiliarId;

	if( pub_inicializarArray(arrayPublicacion, CANTIDAD_PUBLICACIONES)==0)
	{
		printf("Array inicializado correctamente. \n\n");
	}
	if(cli_inicializarArray(arrayClientes,CANTIDAD_CLIENTES) == 0)
	{
		printf("Array inicializado correctamente. \n\n");
	}



	cli_altaForzadaArray(arrayClientes,CANTIDAD_CLIENTES,0,&idClientes,"Juan ", "Gomez", "201932245621" );
	cli_altaForzadaArray(arrayClientes,CANTIDAD_CLIENTES,1,&idClientes,"Pedro ", "Ferro", "201932245620" );
	cli_altaForzadaArray(arrayClientes,CANTIDAD_CLIENTES,2,&idClientes,"Maria ", "Pajaro", "271932245620" );

	do
	{
		if(!utn_getNumero(	&opcion,
							"\n\n1.Cargar un Cliente"
							"\n2.Modificar Datos del  Cliente"
			/*				"\n3.Eliminar un Cliente"
							"\n4.Publicar"
							"\n5.Pausar Publicacion"
							"\n6.Reanudar Publicacion"
							"\n7.Imprimir lista Clientes"
							"\n8.Imprimir lista Publicaciones"
							"\n9.Informar Clientes"
					*/		"\n10.Informar Publicaciones"
							"\n11.Salir\n\n",
							"\nError opcion invalida",1,11,2) )


		{
			switch(opcion)
				{
				case 1://alta de cliente
					auxiliarIndiceCliente = cli_getEmptyIndex(arrayClientes,CANTIDAD_CLIENTES);
					if(auxiliarIndiceCliente >= 0)
					{
						if(cli_altaArray(arrayClientes,CANTIDAD_CLIENTES,auxiliarIndiceCliente,&idClientes) == 0)
						{
							printf("\nCarga realizada con exito el id de este cliente es: &d \n", arrayClientes[auxiliarIndiceCliente].id);
						}
					}
					else
					{
						printf("\nNO HAY MAS LUGAR");
					}
					break;


				case 2://modificacion de datos de cliente
					cli_imprimirArray(arrayClientes,CANTIDAD_CLIENTES);
					if(utn_getNumero(&auxiliarId,"\nIndique el ID del cliente a modificar","\nID invalido",0,idClientes,0) == 0)
					{
						auxiliarIndiceCliente = cli_buscarId(arrayClientes,CANTIDAD_CLIENTES,auxiliarId);
						if(	auxiliarIndiceCliente >= 0 &&
							cli_modificarArray(arrayClientes,CANTIDAD_CLIENTES,auxiliarIndiceCliente) == 0)
						{
							printf("\nModificacion realizada con exito\n");
						}
					}
					break;
	/*
				case 3:
					cli_imprimirArray(arrayClientes,CANTIDAD_CLIENTES);
					if(utn_getNumero(&auxiliarId,"\nIndique el ID del cliente a eliminar","\nID invalido",0,idClientes,0)==0)
					{
						auxiliarIndice = cli_buscarId(arrayClientes,CANTIDAD_CLIENTES,auxiliarId);
						if(	auxiliarIndice >= 0 &&
							cli_bajaArray(arrayClientes,CANTIDAD_CLIENTES,auxiliarIndice)== 0)
						{
							printf("\nBaja realizada con exito\n");
						}
					}
					break;

				case 4://alta de publicacion
					cli_imprimirArray(arrayClientes,CANTIDAD_CLIENTES);
					auxiliarIndicePublicacion=pub_getEmptyIndex(arrayPublicacion,CANTIDAD_PUBLICACIONES);
					if(auxiliarIndicePublicacion>=0)
					{
						cli_imprimirArray(arrayClientes,CANTIDAD_CLIENTES);
						if(utn_getNumero(&auxiliarId, "ingrese su Id","error",0,10000,2)
						{

						}
			*/

					}
		}
	} while(opcion != 11);



	return EXIT_SUCCESS;
}





