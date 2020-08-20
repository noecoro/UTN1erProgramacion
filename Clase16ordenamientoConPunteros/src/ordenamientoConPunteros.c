/*
 ============================================================================
 Name        : ordenamientoConPunteros.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Alumno.h"

#define LIM 6

void OrdenarPorNotasAscendente(Alumno* arrayPuntero[],int limite);

int main(void)
{
	int i, auxiliarNota;
	char auxiliarNombre[50];
	Alumno arrayAlumnos[LIM];
	Alumno* punteroArrayAlumno[LIM];

	for(i=0;i<LIM;i++)
	{
		punteroArrayAlumno[i] = &arrayAlumnos[i];
		printf("\ningrese nota");
		scanf("%d",&auxiliarNota);
		arrayAlumnos[i].nota = auxiliarNota;
		printf("\ningrese nombre");
		scanf("%s",auxiliarNombre);
		strcpy(arrayAlumnos[i].nombre,auxiliarNombre);

	}

	for(i=0;i<LIM;i++)
		{
		printf("\n %s    %d", punteroArrayAlumno[i]->nombre,punteroArrayAlumno[i]->nota);

		}

	OrdenarPorNotasAscendente ( punteroArrayAlumno, LIM);

	printf("\n muestro array ordenado");

	for(i=0;i<LIM;i++)
		{
		printf("\n %s    %d", punteroArrayAlumno[i]->nombre,punteroArrayAlumno[i]->nota);

		}

	return 0;
}
void OrdenarPorNotasAscendente(Alumno* arrayPuntero[],int limite)
{
	Alumno*auxiliar;
	int i, flagswat;
	do{
		flagswat=0;
		for(i=0; i<limite-1;i++)
			{
			 flagswat=0;
				if(arrayPuntero[i]->nota > arrayPuntero[i+1]->nota)
				{
					auxiliar= arrayPuntero[i];
					arrayPuntero[i]=arrayPuntero[i+1];
					arrayPuntero[i+1]=auxiliar;
					flagswat=1;
				}
				limite--;
			}
	}while(flagswat==1);
}
