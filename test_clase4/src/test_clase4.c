/*
 ============================================================================
 Name        : test_clase4.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main()
{
    int acumulador=0; // A
    int numero;  // B
    int contador=0; // C
    float promedio; // D
    int respuesta;

    while(1) // E
    {
        respuesta = utn_getNumero(&numero, "Ingrese un numero:\n","Error\n",0,1000,3); // F
        if(respuesta == 0 && numero!=1000) // G
        {
            acumulador = acumulador + numero; // H
            contador++;
        }
        else
        {
            break; // I
        }
    }
    promedio = (float)acumulador/contador; // J
    printf("\n La promedio es: %f",promedio);
    return 0;
}
