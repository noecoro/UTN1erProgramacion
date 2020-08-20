/*
 ============================================================================
 Name        : pruebaimprimir.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int var1;
	var1=1;
	int var2;
	var2=2;
printf("variable : %d - variable 2: %d \n", var1,var2);


int valorA;
printf("ingrese un numero:");
scanf("%d",&valorA);
printf("Ingresaste: %d \n" ,valorA);

char texto[128];
printf("ingrese un texto");
scanf("%s",texto);//sin el &
printf("Ingresaste: %s",texto);



	return EXIT_SUCCESS;
}
