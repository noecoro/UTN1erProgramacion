/*
 ============================================================================
 Name        : TP1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "utn.h"



int main(void)
{
	int opcion;
	float x=0;
	float y = 0;
	float sumando;
	float restando;
	float multiplicando;
	float dividiendo;
	float r1;
	float r2;

	do{
			if(!utn_getNumero( &opcion,
					"\n\nSeleccione una opcion:"
					"\n1.Ingresar 1er operando A=?"
					"\n2.Ingresar 2do operando B=?"
					"\n3. Calcular todas las operaciones"
					"\n4.Informar Resultado "
					"\n5.Salir",
					"\n No es una opcion valida", 1,5,3))
			{
				switch (opcion)
				{
					case 1:
						if(utn_getNumeroFlotante(&x, "ingrese un numero","error, no es valido",2)==0)
						{
							printf("\n El primer operando ingresado es A=%.2f",x);
							break;
						}

					case 2:
						if(utn_getNumeroFlotante(&y, "ingrese un numero","error, no es valido",2)==0)
						{
							printf("\n El primer operando ingresado es B=%.2f",y);
							break;
						}
					case 3:

						//a) Calcular la suma (A+B)
						sumando= utn_sumar(x,y);

						//b) Calcular la resta (A-B)
						restando= utn_restar(x,y);

						//d) Calcular la multiplicacion (A*B)
						multiplicando= utn_multiplicar(x,y);

						//c) Calcular la division (A/B)
						if(utn_dividir(&dividiendo, x,y)!=0)
						{
							printf("Error no es posible dividir por cero");
						}
						if (x>=0)
						{
							//e) Calcular el factorial (A!)
							r1= utn_factorial (x);
						}
						if(y>=0)
						{
							//e) Calcular el factorial (B!)
							r2 =utn_factorial (y);
						}
						break;

					case 4:
						//informando resultados:
						printf("\n\nEl resultado de A+B es: %.2f",sumando);
						printf("\nEl resultado de A-B es: %.2f", restando);
						printf("\nEl resultado de A/B es: %.2f",dividiendo);
						printf("\nEl resultado de A*B es: %.2f", multiplicando);
						if(x>=0)
						{
							printf("\nEl factorial de A es: %.2f ",r1);
						}
						if(y>=0)
						{
						printf("\nEl factorial de B es: %.2f ",r2);
						}
						break;
				}
			}
	  }while(opcion!=5);

	return EXIT_SUCCESS;
}

