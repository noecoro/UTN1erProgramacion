/*
 ============================================================================
 Name        : Ejercicio1DeClase1.c
 Author      : yus
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int numeroUno;
	int numeroDos;
	int resultado;
	float division;

	printf("ingrese el primer numero");
	__fpurge(stdin);
	scanf("%d",&numeroUno);

	printf("ingrese el segundo numero");
	__fpurge(stdin);
	scanf("%d",&numeroDos);

	resultado = numeroUno + numeroDos;
	printf("\n la suma es : %d",resultado);

	resultado = numeroUno - numeroDos;
	printf("\n la resta es : %d",resultado);


	resultado = numeroUno * numeroDos;
	printf("\n la multiplicacion es : %d",resultado);

	division = (float) numeroUno / numeroDos;
	printf("\n la division es  : %f",division);

	return EXIT_SUCCESS;
}
