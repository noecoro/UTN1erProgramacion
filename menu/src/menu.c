/*
 ============================================================================
 Name        : menu.c
 Author      : Mauro
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main(void)
{
	int opcion;
	int respuesta;
	do
	{
		respuesta = utn_getNumero(	&opcion,
									"Seleccione un opcion"
									"\n"
									"\n1-Leer"
									"\n2-Mostrar"
									"\n3-Salir"
									"\n",
									"No es una opcion valida\n",
									1,
									3,
									2);
		if(!respuesta)
		{
			switch(opcion)
			{
				case 1:
					printf("Entre al caso 1\n");
					break;

				case 2:
					printf("Entre al caso 2\n");
					break;
			}
		}
	}while(opcion != 3);

	return EXIT_SUCCESS;
}
