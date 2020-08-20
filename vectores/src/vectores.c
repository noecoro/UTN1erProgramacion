/*
 ============================================================================
 Name        : vectores.c
 Author      : yus
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}
/*/int main()
{
    int numeros[T];
    int suma = 0;
    int i;
    //Inicializa el vector
    for(i=0; i<T; i++)
    {
        numeros[i] = 0;

    }
    //Le pide al usuario que ingrese valores (Secuencialmente)
    for(i=0; i<T; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", &numeros[i]);
    }
    //Calcula la suma de todos los elementos
    for(i=0; i<T; i++)
    {
        suma = suma + numeros[i]; // suma+=numeros[i];
    }

    //muestra todos los numeros (del primero al ultimo)
    for(i=0; i<T; i++)
    {
        printf("%d\n", numeros[i]);
    }


    //muestra todos los numeros ( del ultimo al primero)
    printf("A la inversa: \n");
    for(i=T-1; i>-1; i--)
    {
        printf("%d\n", numeros[i]);
    }

    printf("La suma de sus elementos es: %d", suma);


    return 0;
}
/*/


// explicacionde octavio:

*******************************************************************************/
#include <stdio.h>


int main()
{

    int numeroUno=1;
    float altura;
    int listadoEnteros[3]={44,55,66};
    float listadoAlturas[3]={1,3.14,3.3333};
    int listadoEnterosBis[3]={77,88,99};
    double datoDoble=999.999;
    int numeroDos=2;

   // int numeroTres;
    int i=0;
    //numeroTres=3;

    printf("\n numero:%d direccion:%d ",numeroUno,&numeroUno);
    printf("\n numero:%d direccion:%d ",numeroDos,&numeroDos);
    printf("\n doble:%f direccion:%d ",datoDoble,&datoDoble);

    for(i=0;i<3;i++)
    {
        printf("\n indice:#%d numero:%d  direccion:%d",i,listadoEnteros[i],&listadoEnteros[i]);

    }
    int numeroTres;
    numeroTres=3;
    printf("\n numero:%d direccion:%d ",numeroTres,&numeroTres);
    for(i=0;i<3;i++)
    {
        printf("\n indice:#%d numero:%f  direccion:%d",i,listadoAlturas[i],&listadoAlturas[i]);

    }

    printf("\n\n\t mal listado  float\n");
    for(i=0;i<7;i++)
    {
        printf("\n indice:#%d numero:%f  direccion:%d",i,listadoAlturas[i],&listadoAlturas[i]);

    }
     printf("\n\n\t mal listado  enteros\n");
    for(i=0;i<9;i++)
    {
        printf("\n indice:#%d numero:%d  direccion:%d",i,listadoEnteros[i],&listadoEnteros[i]);

    }



    return 0;
}

//explicacionde german de vectorss

/******************************************************************************

Ingresar 10. Los números tienen que estar
comprendidos entre -100 y 100. Determinar:
a. Cantidad de números positivos
b. Cantidad de números negativos.
c. Promedio de números.
d. De los positivos el máximo.

Aplicar las siguientes funciones:
a. int getInt(char[], char[], int, int) para el ingreso y validación de datos de tipo entero.
b. int esPositivo(int) retorna 1 en caso de que el número recibido como parámetro sea positivo, 0 en caso contrario.
c. float promediarNumeros(int,int): recibe el acumulador y el contador de números y retorna el promedio.
Crear estas funciones dentro de una biblioteca llamada Repaso2
*******************************************************************************/
#include <stdio.h>
#include "funciones.h"
#define T 5
#define INV -1
#define ING 1

void inicializarNumeros(int numeros[], int tam);
void cargarNumeros(int numeros[], int tam);
int sumarNumeros(int numeros[], int tam);
void mostrarNumeros(int numeros[], int tam, int orden);
int main()
{
    int numeros[T];
    int suma = 0;
    int i;
    int opcion;
    inicializarNumeros(numeros,T);
    do
    {
        printf("1. Cargar numeros\n2.Calcular suma\n3.Mostrar Ingreso\n4.Mostrar Inversa\n5.Salir\nElija opcion:");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                 cargarNumeros(numeros,T);
            break;
            case 2:
                  suma = sumarNumeros(numeros,T);
                  printf("La suma de sus elementos es: %d", suma);
            break;

            case 3:
                mostrarNumeros(numeros, T, ING);
            break;

            case 4:
                mostrarNumeros(numeros, T, INV);
            break;

        }


    }while(opcion!=5);


    return 0;
}


void inicializarNumeros(int numeros[], int tam)
{
      //Inicializa el vector
      int i;
    for(i=0; i<tam; i++)
    {
        numeros[i] = 0;

    }
}

void cargarNumeros(int numeros[], int tam)
{
    int i;
     //Le pide al usuario que ingrese valores (Secuencialmente)
    for(i=0; i<tam; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", &numeros[i]);
    }
}
int sumarNumeros(int numeros[], int tam)
{

    int suma = 0;
    int i;
    //Calcula la suma de todos los elementos
    for(i=0; i<tam; i++)
    {
        suma = suma + numeros[i]; // suma+=numeros[i];
    }

    return suma;
}

void mostrarNumeros(int numeros[], int tam, int orden)
{

    int i;
      //muestra todos los numeros (del primero al ultimo)

    switch(orden)
    {
        case 1:
          printf("En orden de ingreso: \n");
            for(i=0; i<tam; i++)
            {
                printf("%d\n", numeros[i]);
            }
        break;
        case -1:
            //muestra todos los numeros ( del ultimo al primero)
            printf("A la inversa: \n");
            for(i=tam-1; i>-1; i--)
            {
                printf("%d\n", numeros[i]);
            }
        break;
    }

}







