/*
 * >>>> PARCIAL I DE LABORATORIO<<<<
 *
 *	Sistema que permite gestionar publicidad en sitios web y Desarrolla una aplicacion
 *que permite gestionar una array de Clientes
 *
 * */

#include <stdio.h>
#include <stdlib.h>

#include "Cliente.h"
#include "utn.h"
#include "Informes.h"
#include "Publicacion.h"
#define CANTIDAD_CLIENTES 		100
#define CANTIDAD_PUBLICACIONES 1000

int main(void) {

	Publicacion arrayPublicaciones[CANTIDAD_PUBLICACIONES];
	Cliente arrayClientes[CANTIDAD_CLIENTES];
	int idClientes=0;
	int idPublicaciones=0;
	int opcion;
	int auxiliarIndice;
	int auxiliarId;
	int auxiliarIdPublicacion;
	int auxiliarIndicePublicacion;



	if(cli_inicializarArray(arrayClientes,CANTIDAD_CLIENTES) == 0)
	{
		printf("Array inicializado correctamente. \n\n");
	}

	if(pub_inicializarArray(arrayPublicaciones,CANTIDAD_PUBLICACIONES) == 0)
	{
		printf("Array inicializado correctamente. \n\n");
	}

	cli_altaForzadaArray(arrayClientes,CANTIDAD_CLIENTES,0,&idClientes,"Cliente 1","Arraez", 27-95839640-7);
	cli_altaForzadaArray(arrayClientes,CANTIDAD_CLIENTES,1,&idClientes,"Cliente 2","Ferro",20-18211770 );
	cli_altaForzadaArray(arrayClientes,CANTIDAD_CLIENTES,2,&idClientes,"Cliente 3","Rangel", 3043567432-3);


	pub_altaForzadaArray(arrayPublicaciones,CANTIDAD_PUBLICACIONES,0,&idPublicaciones,1,"texto de aviso 1",2);
	pub_altaForzadaArray(arrayPublicaciones,CANTIDAD_PUBLICACIONES,1,&idPublicaciones,1,"texto de aviso 2",10);
	pub_altaForzadaArray(arrayPublicaciones,CANTIDAD_PUBLICACIONES,2,&idPublicaciones,1,"texto de aviso 3",20);
	pub_altaForzadaArray(arrayPublicaciones,CANTIDAD_PUBLICACIONES,3,&idPublicaciones,0,"texto de aviso 4",2);
	pub_altaForzadaArray(arrayPublicaciones,CANTIDAD_PUBLICACIONES,4,&idPublicaciones,0,"texto de aviso 5",10);
	pub_altaForzadaArray(arrayPublicaciones,CANTIDAD_PUBLICACIONES,5,&idPublicaciones,2,"texto de aviso 6",20);

	do{

		if(!utn_getNumero(	&opcion,
							"\n\n1.Cargar un Cliente"
							"\n2.Modificar un cliente"
							"\n3.Eliminar una cliente"
							"\n4.Contratar una publicidad"
							"\n5.Modificar condiciones de publicacion"
							"\n6.Cancelar Contratacion"
							"\n7.Consulta facturación"
							"\n8.Imprimir contratacion"
							"\n9.Imprimir lista pantalla"
							"\n10.Informar"

							"\n11.Salir\n\n",

							"\nError opcion invalida",1,11,2) )
		{
			switch(opcion)
			{
			case 1:
				auxiliarIndice = cli_getEmptyIndex(arrayClientes,CANTIDAD_CLIENTES);
				if(auxiliarIndice >= 0)
				{
					if(cli_altaArray(arrayClientes,CANTIDAD_CLIENTES,auxiliarIndice,&idClientes) == 0)
					{
						printf("\nCarga realizada con exito\n");
					}
				}
				else
				{
					printf("\nNO HAY MAS LUGAR");
				}
				break;
			case 2:
				cli_imprimirArray(arrayClientes,CANTIDAD_CLIENTES);
				if(utn_getNumero(&auxiliarId,"\nIndique el ID del Cliente a modificar","\nID invalido",0,idClientes,0) == 0)
				{
					auxiliarIndice = cli_buscarId(arrayClientes,CANTIDAD_CLIENTES,auxiliarId);
					if(	auxiliarIndice >= 0 &&
							cli_modificarArray(arrayClientes,CANTIDAD_CLIENTES,auxiliarIndice) == 0)
					{
						printf("\nModificacion realizada con exito\n");
					}
				}
				break;

			case 3:
				cli_imprimirArray(arrayClientes,CANTIDAD_CLIENTES);
				if(utn_getNumero(&auxiliarId,"\nIndique el ID de cliente a eliminar","\nID invalido",0,idClientes,0)==0)
				{
					auxiliarIndice = cli_buscarId(arrayClientes,CANTIDAD_CLIENTES,auxiliarId);
					if(	auxiliarIndice >= 0)

					{

					}
						//&&
							//cli_bajaArray(arrayClientes,CANTIDAD_CLIENTES,auxiliarIndice)== 0)
					{
						printf("\nBaja realizada con exito\n");
					}
				}
			break;
				case 4:

				auxiliarIndicePublicacion = pub_getEmptyIndex(arrayPublicaciones,CANTIDAD_PUBLICACIONES);
				if(auxiliarIndicePublicacion >= 0)
				{
					cli_imprimirArray(arrayClientes,CANTIDAD_CLIENTES);
					if(	utn_getNumero(&auxiliarId,"\nId Cliente: ","\nError",0,100,2) == 0 &&
						cli_buscarId(arrayClientes,CANTIDAD_CLIENTES,auxiliarId) != -1)
					{
						pub_altaArray(arrayPublicaciones,CANTIDAD_PUBLICACIONES,auxiliarIndicePublicacion,&idPublicaciones,auxiliarId);
						printf("el aviso ha ido cargado correctamente su  id de esta publicacion es %d",arrayPublicaciones.id[auxiliarIndicePublicacion]);
					}
					else
					{
						printf("\nEL ID DE CLIENTE NO EXISTE");
					}
				}
				break;

				/*Se pedirá que se ingrese el cuit del cliente y se listaran todas las pantallas de
				video que el cliente tiene contratadas mostrando todos sus campos.
				Luego de ingresar el ID de la contratacion, se permitirá modificar la cantidad de días
				contratados para la misma.*/
			case 5:
				if(	!utn_getDni(auxiliarCuit,CUIT_LEN,"\n CUIT? ", "\nError", 2) &&
					!info_imprimirPublicacionesContratadasbyIdClientes(arrayPublicaciones,CANTIDAD_PUBLICACIONES,arrayClientes,CANTIDAD_CLIENTES,auxiliarCuit))
				{

					if(!utn_getNumero(&auxiliarIdPublicacion,"\nID CONTRATACION A MODIFICAR? ","\nERROR",0,10000,2))
					{
						auxiliarIndicePublicacion = pub_buscarId(arrayPublicaciones,CANTIDAD_PUBLICACIONES,auxiliarIdPublicacion);
						if(auxiliarIndicePublicacion != -1)
						{
							pub_modificarArray(arrayPublicaciones,CANTIDAD_PUBLICACIONES,auxiliarIndicePublicacion);
						}
					}
				}
				else
				{
					printf("\nCUIT NO ENCONTRADO");
				}
				break;

			case 6:
				if(	!utn_getDni(auxiliarCuit,CUIT_LEN,"\n CUIT? ", "\nError", 2) &&
					!info_imprimirPublicacionesContratadasbyIdClientes(arrayPublicaciones,CANTIDAD_PUBLICACIONES,arrayClientes,CANTIDAD_CLIENTES,auxiliarCuit))
				{

					if(!utn_getNumero(&auxiliarIdPublicacion,"\nID CONTRATACION A CANCELAR? ","\nERROR",0,10000,2))
					{
						auxiliarIndicePublicacion = pub_buscarId(arrayPublicaciones,CANTIDAD_PUBLICACIONES,auxiliarIdPublicacion);
						if(auxiliarIndicePublicacion != -1)
						{
							pub_bajaArray(arrayPublicaciones,CANTIDAD_PUBLICACIONES,auxiliarIndicePublicacion);
						}
					}
				}
				else
				{
					printf("\nCUIT NO ENCONTRADO");
				}
				break;

			/*Consulta facturación: Se deberá ingresar el cuit del cliente y se deberá listar el importe
			a pagar por cada contratación.*/
			case 7:
				if(	!utn_getDni(auxiliarCuit,CUIT_LEN,"\n CUIT? ", "\nError", 2))
				{
					info_imprimirContratacionesConImporte(arrayPublicaciones,CANTIDAD_PUBLICACIONES,arrayClientes,CANTIDAD_CLIENTES,auxiliarCuit);
				}
				break;

			case 10:
				info_imprimirContratacionesConImportePorCliente(arrayPublicaciones,CANTIDAD_PUBLICACIONES,arrayClientes,CANTIDAD_CLIENTES);
				break;
			case 14:
				cli_ordenarPorNombre(arrayClientes,CANTIDAD_CLIENTES);
				break;

			case 8:
				pub_imprimirArray(arrayPublicaciones,CANTIDAD_PUBLICACIONES);
				break;
			case 9:
				cli_imprimirArray(arrayClientes,CANTIDAD_CLIENTES);
				break;

			}
		}
	}while(opcion != 11);

	return EXIT_SUCCESS;
}




