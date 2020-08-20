/*
 ============================================================================
 Name        : 2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include <string.h>



int esNumero(char* cadena);

int main(void)
{
	char string[100]="XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
	int longitud;
	int edad;
	char bufferStr[4096];



	// NO SE PUEDE string="Jose";
	strcpy(string,"HOLA MUNDO\n");
	printf("%s",string);
	longitud = strlen(string);
	printf("%d\n", longitud);


	printf("Edad?\n");
	//scanf("%d",&edad);
	scanf("%s",bufferStr);
	if(esNumero(bufferStr))
	{
		edad = atoi(bufferStr);
		printf("Tu edad es %d", edad);
	}


	return EXIT_SUCCESS;
}








