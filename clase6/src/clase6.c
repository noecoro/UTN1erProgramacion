 Ejercicio 1:
 * Escribir la funcion calcularMayor(). La funcion debe recibir dos
 * numeros int y devolver por referencia, el numero mayor.
 * La funcion debe retornar un 1 si encontro un mayor, o un 0
 * si ambos numeros son iguales.
 */
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int calcularMayor(int* pResultado, int num1, int num2);

int main(void) {

	setbuf(stdout, NULL);
	int resultado;
	int num1,num2;

	// Pedir dos numeros al usuario con utn_getNumber() y guardarlos
	// en num1 y num 2

	utn_getNumero(&num1,"Por favor ingrese el primer numero: ", "No ingreso un numero",-100,1000,2);
	utn_getNumero(&num2,"Por favor ingrese el segundo numero: ", "No ingreso un numero",-100,1000,2);



	// luego llamo a la funcion calcularMayor()

	if(calcularMayor(&resultado,num1,num2)==0)
	{
		printf("Los numeros son iguales\n");
	}
	else
	{
		printf("El mayor es:%d\n",resultado);
	}

	return EXIT_SUCCESS;
}

int calcularMayor(int* pResultado, int num1, int num2)
{
	int retorno=0;

	if(pResultado!=NULL)
	{
		if(num1==num2){
			retorno=0;
		} else {
			if (num1>num2)
			{
				*pResultado=num1;
			}
			else
			{
				*pResultado=num2;
			}
			retorno=1;
		}
	}
	return retorno;
}





