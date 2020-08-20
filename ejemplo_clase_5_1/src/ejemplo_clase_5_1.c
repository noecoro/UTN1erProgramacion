/******************************************************************
* Programa: Ejemplo Clase 5
*
* Objetivo:
*   Solicitar al usuario 5 numeros, permitir listarlos por pantalla
*   indicando el maximo, el minimo y el promedio
*   Permitir Modificar el valor de cualquiera de los numeros cargados
*   indicando el indice del mismo y su nuevo valor.
*
* Aspectos a destacar:
*   -Utilizacion de array
*
* Version: 0.2 del 2 de abril de 2020
* Autor: Mauricio Davila
* Revision: Ernesto Gigliotti
*
* *******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

#define CANTIDAD 5 // constante con tamano del array

int main()
{
    int arrayDeNumeros[CANTIDAD];
    int numeroIngresado;
    int indiceArray;
    int valorIngresado;
    int opcionMenu = 0;

    for(indiceArray = 0 ; indiceArray < CANTIDAD ; indiceArray++ )
    {
            numeroIngresado = getInt("Ingrese el valor: \n");
            arrayDeNumeros[indiceArray] = numeroIngresado;
    }

    while(opcionMenu != 3)
    {
         opcionMenu = getInt("\n1 - Mostrar \n2 - Modificar \n3 - Salir\n");
         switch(opcionMenu)
         {
            case 1:
                printf("\n\nINDICE - VALOR\n");
                for(indiceArray = 0 ; indiceArray < CANTIDAD ; indiceArray++ )
                {
                    printf("  %d    -   %d \n",indiceArray,arrayDeNumeros[indiceArray]);
                }
                break;

            case 2:
                indiceArray = getInt("\nIngrese el indice a modificar: ");
                if(indiceArray >= 0 && indiceArray < CANTIDAD)
                {
                    valorIngresado = getInt("Ingrese el valor: \n");
                    arrayDeNumeros[indiceArray] = valorIngresado;
                }
                else
                {
                    printf("\nEl indice ingresado esta fuera de rango!!!!");
                }
                break;
         } // fin switch
    } // fin while

    return 0;
}

