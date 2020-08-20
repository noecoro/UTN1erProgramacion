/*
 ============================================================================
 Name        : Parcial_1_Lab_1H.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Cliente.h"
#include "utn.h"

int main(void)
{
	Cliente arrayClientes [QWTY_CLIENTES];
	int opcion;
	int auxiliarIndice;
	int auxiliarId;


if(cli_inicializarArray(arrayClientes, QWTY_CLIENTES)==0)
{
	printf("Array clientes Inicializado correctamente");
}

	do{

			if(utn_getNumero( &opcion ," \n\n ingrese una opcion:"
										"\n1-Alta de Cliente"
										"\n2-Modificar Datos de Cliente"
										"\n3-Baja de Cliente"
										"\n4-Publicar"
										"\n5-Pausar Publicacion"
										"\n6-Reanudar Publicacion"
										"\n7-Imprimir Clientes"
										"\n8-Imprimir Publicaciones"
										"\n9-Informar Clientes"
										"\n10-Informar Publicaciones"
										"\n11-Salir",
										"Error, reintente",1,11,2)==0)
				{
					switch (opcion)
					{
					case 1:
					/*Alta de cliente:​ Se da de alta un cliente con nombre,
					 apellido, y cuit. Se generará ,un ID único para este cliente
					  que se imprimirá por pantalla si el alta es correcta.
					 */
						auxiliarIndice= cli_getEmptyIndex(arrayClientes,QWTY_CLIENTES);
						if( auxiliarIndice >= 0)
						{
							if(cli_altaArray(arrayClientes,QWTY_CLIENTES,auxiliarIndice)==0)
							{
								printf("el id generado para este cliente es %d",auxiliarId);
								break;
							}
						}

					case 2:

					case 3:

					case 4:
					case 5:
					case 6:
					case 7:
					case 8:
					case 9:
					case 10:
					}

				}



	}while(opcion != 11);


}
