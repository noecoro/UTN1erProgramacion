/*
 ============================================================================
 Name        : punterosAfunciones.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void saludar();
void mostrar(int varUno, float* varDos);
void sumar( int numUno, int numDos, int* pResultado);
void restar(int numUno,int numDos, int* pResultado);
int calcular(int numUno,int numDos,void(*pFuncion)(int,int, int*));



int main(void) {

	void (*pFuncion)();
	pFuncion = saludar;
	pFuncion();

	float numero = 3.14;
	void(*pFuncionDos)(int,float*);
	pFuncionDos = mostrar;
	pFuncionDos(22,&numero);

	int varUno=2;
	int varDos=4;
	int resultado;

	resultado= calcular(varUno,varDos, restar);

	printf("\n la resta es %d", resultado);

	resultado= calcular(varUno,varDos, sumar);
	printf("\n la suma es %d", resultado);



	return EXIT_SUCCESS;
}

void saludar()
{
	printf("HOLA!!!");
}

void mostrar(int varUno, float* varDos)
{
	printf("\n A:%d -B:%.2f",varUno,(*varDos));
}

void sumar( int numUno, int numDos, int* pResultado)
{
	*pResultado= numUno+numDos;
}

void restar(int numUno,int numDos, int* pResultado)
{
	*pResultado = numUno-numDos;
}
int calcular(int numUno,int numDos,void(*pFuncion)(int,int, int*))
{
	int auxiliar;
	pFuncion(numUno , numDos , &auxiliar);
	return auxiliar;
}
