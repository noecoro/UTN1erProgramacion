/*
 ============================================================================
 Name        : clase1.c
 Author      : yus
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define MENSAJE "hola mundo ya es hora del recreo\n"

int main(void)
{
	// arranca por aca
	//console.log("hola"); //JS
	//alert("hola!"); //JS
	//document.write("hola"); //JS
	printf(MENSAJE);


	// TIPO NOMBRE;
	// TIPO NOMBRE=VALOR;

	int i;
	i = 27;
	int j=27;
	float pi = 3.14;
	char letra = 'A';
	int k=33;

	//JS
	//var i=27;
	//alert("precio:"+i+" pesos");

	//printf("hola:"+i); // NO se puede

	// %d : int
	// %f : float
	// %c : char

	printf("precio: %d pesos %d lalala %d\n",i,j,k);

	printf("precio:%f\n",pi);

	printf("letra:%c\n",letra);

	//2DA PARTE
	setbuf(stdout,NULL);

	int numero;

	// JS
	// numero = propmt("Ingrese numero:");

	printf("Ingrese numero:");
	//funcion que espera el ingreso
	//numero = scanf(); // NO
	//scanf("%d",direccion de la variable);

	//scanf("%d",numero); // NO!

	scanf("%d",&numero); // NO!

	printf("ingresaste:%d",numero);

	return EXIT_SUCCESS;
}
