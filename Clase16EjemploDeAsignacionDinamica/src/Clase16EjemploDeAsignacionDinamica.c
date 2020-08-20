/*
 ============================================================================
 Name        : Clase16EjemploDeAsignacionDinamica.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "personas.h"


int main(void)
{

	persona* pArrayPersonas;
	int longitudDePersonas=1;
	int seguirCargando;
	int auxiliarNuevaLongitud;
	int i;
	persona* pAuxiliar;

	//creamos el array de personas:

	pArrayPersonas= (persona*)malloc(sizeof(persona));
		if(pArrayPersonas==NULL)
	{
		printf("No hay lugar en memoria");
	}

	while(1)
	{
		printf("\ningrese nombre");
		scanf("%s",(pArrayPersonas+longitudDePersonas-1)->nombre);

		printf("\ningrese edad");
		scanf("%d",&(pArrayPersonas+longitudDePersonas-1)->edad);


		printf("\n Si desea seguir cargando otra persona marque 1 ");
		scanf("%d",&seguirCargando);

		if (seguirCargando==1)
		{
			//calculamos el nuevo tamaño del array:
			auxiliarNuevaLongitud= sizeof(pArrayPersonas)*longitudDePersonas;
			//redimencionamos la lista:
			if((pAuxiliar= (persona*)realloc(pArrayPersonas,auxiliarNuevaLongitud))==NULL)
			{
				printf("\n no hay espacio en memoria");
				break;
			}
			longitudDePersonas++; //incremento el contador de Personas
			pArrayPersonas=pAuxiliar;

		}else
			{

			break;
			}

	}
	for(i=0;i<longitudDePersonas;i++)
	{
		printf("\n nombre: %s", (pArrayPersonas+i)->nombre);
		printf("\n edad: %d", (pArrayPersonas+i)->edad);

	}
	free(pArrayPersonas); //liberamos memoria
	return EXIT_SUCCESS;
}
