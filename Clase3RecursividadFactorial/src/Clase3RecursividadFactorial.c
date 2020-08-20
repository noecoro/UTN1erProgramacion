/*
 ============================================================================
 Name        : Clase3RecursividadFactorial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "UTN.h"



int main(void) {

	int numeroIngresado;
	int resultado;

	printf("ingrese un numero");
	scanf("%d",&numeroIngresado );
	resultado = Factorial (numeroIngresado);
	printf("el resultado es : %d",resultado);
	return EXIT_SUCCESS;
}


