/*
 ============================================================================
 Name        : Clase18Ejercicio.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Alumno.h"

#define QTY_ALUMNO 100

int main(void) {

	Alumno* arrayPunteroAlumno[QTY_ALUMNO];



	if(alumno_initArray(arrayPunteroAlumno, QTY_ALUMNO)==0)
		{
			printf("INIT OK");


			if(alumno_agregarAlumno(arrayPunteroAlumno, QTY_ALUMNO,"juan", 123, 1.87)>=0)
			{
				printf("alta ok");
			}

			if(alumno_agregarAlumno(arrayPunteroAlumno, QTY_ALUMNO,"Ana", 123, 1.57)>=0)
				{
				printf("alta ok");
				}


		alumno_imprimirArray(arrayPunteroAlumno, QTY_ALUMNO);
	}

		if(alumno_EliminarPorId(arrayPunteroAlumno, QTY_ALUMNO,123)==0)
		{
			printf("\neliminacion exitosa");
			alumno_imprimirArray(arrayPunteroAlumno, QTY_ALUMNO);
		}

	return EXIT_SUCCESS;
}
