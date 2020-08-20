/*
 * Ejercicio 2:
 * crear un programa que permita registrar el valor de temperatura maxima de cada dia de un mes.
 * Definir un array de floats de 31 posiciones. Cada posicion corresponderá a un dia
 * del mes. Hacer un programa con un menu de dos opciones, 1.imprimir array y 2.cargar array
 * Al elegir la opcion 1, se imprimira el indice y el valor de cada posicion del array.
 * Al elegir la opcion 2 que le pida al usuario que ingrese un numero de dia (1 a 31)
 * y luego que ingrese un valor de temperatura. Almacenar el valor en el indice correspondiente
 * Ambas opciones deben volver al menu ppal.
 * Utilizar la funcion utn_getNumeroFloat() de la biblioteca utn.h
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "utn.h"

#define LEN 31

int main(void) {

	float temperaturasDias[LEN]; // 0...30
	int opcionesMenu;
	int i;
	int dia;
	float temp;

	do{
		printf("Menu de opciones\n"
			   "1-Imprimir Array\n"
			   "2-Cargar Array\n"
			   "3-Salir\n");

		if(utn_getInt(&opcionesMenu, "Ingrese la opcion Deseada: ", "ERROR-Opcion no valida", 0,3,2)==0)
		{
			switch(opcionesMenu)
			{
				case 1:
					for(i=0;i<LEN;i++)
					{
						printf("Dia: %d -- Valor: %.2f\n", i+1, temperaturasDias[i]);
					}
					break;
				case 2:
					/*
					for(i=0; i<LEN; i++)
					{
						if(utn_getfloat(&temperaturasDias[i], "Ingrese la temperatura: ", "ERROR, numero invalido", 0, 100, 2)==0){
							printf("Usted ingreso la temperatura %.2f en la posicion %d\n", temperaturasDias[i], i);
						}
					}*/
					if(utn_getInt(&dia, "Ingrese dia[1-31]: ", "ERROR-Dia no valida", 1,31,2)==0)
					{
						// dia : 1..31

						if(utn_getfloat(&temp, "Ingrese la temperatura: ", "ERROR, numero invalido", 0, 100, 2)==0)
						{
							// cargar la temp en el array en la pos que corresponde
							temperaturasDias[dia-1] = temp;
						}
					}
					break;
			}
		}
		else
		{
			printf("Se acabaron tus reintentos");
		}
	}while(opcionesMenu != 3);

}
