/*
 ============================================================================
 Name        : Clase.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include "funciones.h"
#define CANTIDADNUMEROS 10
#define VALORINICIO -1


int main()
{
    printf("Clase 04 18 de abril");
    int numero;
    int listadoDeNumeros[CANTIDADNUMEROS];
    int i;
    int sumaNumeros;
    int cantidadDeNumeros;
    float promedio;
    int indiceLibre;


    InicializarArray(listadoDeNumeros,CANTIDADNUMEROS,VALORINICIO);
    listadoDeNumeros[2]=2;
    listadoDeNumeros[1]=9;
    listadoDeNumeros[0]=8;
    /*listadoDeNumeros[4]=2;
    listadoDeNumeros[5]=9;
    listadoDeNumeros[6]=8;
    listadoDeNumeros[7]=2;
    listadoDeNumeros[8]=9;*/
    listadoDeNumeros[9]=8;
    listadoDeNumeros[3]=8;
    testArray(listadoDeNumeros,CANTIDADNUMEROS);
    MostarArray(listadoDeNumeros,CANTIDADNUMEROS);

    sumaNumeros=SacarLaSuma(listadoDeNumeros,CANTIDADNUMEROS,VALORINICIO);
    cantidadDeNumeros=SacarCantidadDeNumeros(listadoDeNumeros,CANTIDADNUMEROS,VALORINICIO);
    promedio=SacarPromedio(listadoDeNumeros,CANTIDADNUMEROS,VALORINICIO);
    indiceLibre=SacarIndiceLibre(listadoDeNumeros,CANTIDADNUMEROS,VALORINICIO);
    printf("\nla suma es : %d",sumaNumeros);
    printf("\nla cantidadDeNumeros es : %d",cantidadDeNumeros);
    printf("\nla promedio es : %f",promedio);
    printf("\nla indiceLibre es : %d",indiceLibre);
    printf("\n\n");

    return 0;
}




















