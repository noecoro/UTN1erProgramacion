/*
 ============================================================================
pedir numeros al usuario hasta que quiera que sean entre -100 y 100 se requiere:
la cantidad de negativos
la cantidas de positivos, de estos el maximo
el promedio
use funciones

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "UTN.h"


int main(void)
{
	char respuesta;
	int numeroIngresado;
	int contadorNumeros=0;
	int acumulador=0;
	float promedio;
	int cantidadPositivos=0;
	int contadorDeNegativos=0;
	int maximoDeLosPositivos;

	do
	{
		numeroIngresado=getInt("ingrese un numero","Error es invalido",-100,100);
		contadorNumeros++;
		acumulador+=numeroIngresado;

		if(esPositivo(numeroIngresado))
		{
			cantidadPositivos++;
			if(cantidadPositivos==1||numeroIngresado>maximoDeLosPositivos)
			{
				maximoDeLosPositivos=numeroIngresado;
			}
		}else
		{
			if(numeroIngresado!=0)
			{
				contadorDeNegativos++;
			}
		}

		printf("\n si desea continuar escriba: s");
		__fpurge(stdin);
		scanf("%c",&respuesta);
	}while(respuesta=='s');

	promedio=promediar(acumulador,contadorNumeros);
	printf("\n el promedio es: %f ",promedio);
	printf("\n la cantidad de Positivos es  %d ",cantidadPositivos);
	printf("\n el maximo de los Positivos es  %d ",maximoDeLosPositivos);
	printf("\n la cantidad de Negativos es  %d ",contadorDeNegativos);

	return EXIT_SUCCESS;
}


