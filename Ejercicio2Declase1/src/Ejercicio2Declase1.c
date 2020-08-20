/*
 ============================================================================
 Name        : Ejercicio2Declase1.c
 Author      : yus
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int numero;
	float promedio;
	int i;
	int contador=0;
	int acumulador=0;

	for(i=0;i<5;i++)
	{
		printf("ingrese un numero:");
		scanf("%d" , &numero);


		acumulador+=numero;
		contador++;
	}
	if(contador!=0)
	{
		promedio=(float)acumulador/contador;
		printf("el promedio es: %f",promedio);
	}




	return EXIT_SUCCESS;
}
