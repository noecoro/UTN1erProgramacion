


/******************************************************************************

Ingresar números hasta que el usuario lo decida. Los números tienen que estar
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

int getInt(char mensaje[], char mensajeError[], int minimo, int maximo);
int esPositivo(int numeroPorParametro);
float promediarNumeros(int acumulador,int contador);

int main()
{
    char respuesta;
    float promedio;
    int ElNumeroEsPositivo;
    int numeroIngresado;


    /*test*/

    numeroIngresado=  getInt("ingrese un numero","reingrese por fa!!!",10,20);
    printf("\n el numero es : %d",numeroIngresado);

    promedio= promediarNumeros(50,3);
     printf("\n%f",promedio);
    respuesta='s';
    printf("\n%c",respuesta);

    int esPositivo(int numeroPorParametro);


    gg
	ElNumeroEsPositivo=esPositivo(0);
    if(ElNumeroEsPositivo==1)
    {
        printf("\nsi es positivo");
    }else
    {
        printf("\nNO es positivo");
    }

    ElNumeroEsPositivo=esPositivo(-555);
    if(ElNumeroEsPositivo==1)
    {
        printf("\nsi es positivo");
    }else
    {
        printf("\nNO es positivo");
    }
   /*fin test*/


    return 0;
}



int getInt(char mensaje[], char mensajeError[], int minimo, int maximo)
{
    int valorDeRetorno;
    int flagError;
    flagError=0;
    do{

        if(flagError==0)
        {
             printf("%s",mensaje);
             flagError=1;
        }else
        {
             printf("%s",mensajeError);
        }
        scanf("%d",&valorDeRetorno);
    }while(valorDeRetorno<minimo || valorDeRetorno>maximo);
    return valorDeRetorno;

}






int esPositivo(int numeroPorParametro)
{
    /*
    int valorDeRetorno;
    if(numeroPorParametro>0)
    {
        valorDeRetorno=1;
        //return 1;
    }else
    {
       valorDeRetorno=0;
        //return 0;
    }

    return valorDeRetorno;
     */
    return numeroPorParametro>0;
}

float promediarNumeros(int acumulador,int contador)
{
    /*
    float valorDeRetorno;
    valorDeRetorno=(float)acumulador/contador;
    return valorDeRetorno;
    */
    return (float)acumulador/contador;

}
/******************************************************************************

Ingresar números hasta que el usuario lo decida. Los números tienen que estar
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

int getInt(char mensaje[], char mensajeError[], int minimo, int maximo);
int esPositivo(int numeroPorParametro);
float promediarNumeros(int acumulador,int contador);

int main()
{
    char respuesta;
    float promedio;
    int ElNumeroEsPositivo;
    int numeroIngresado;


    /*test*/

    numeroIngresado=  getInt("ingrese un numero","reingrese por fa!!!",10,20);
    printf("\n el numero es : %d",numeroIngresado);

    promedio= promediarNumeros(50,3);
     printf("\n%f",promedio);
    respuesta='s';
    printf("\n%c",respuesta);

    ElNumeroEsPositivo=esPositivo(666);
    if(ElNumeroEsPositivo==1)
    {
        printf("\nsi es positivo");
    }else
    {
        printf("\nNO es positivo");
    }


    ElNumeroEsPositivo=esPositivo(0);
    if(ElNumeroEsPositivo==1)
    {
        printf("\nsi es positivo");
    }else
    {
        printf("\nNO es positivo");
    }

    ElNumeroEsPositivo=esPositivo(-555);
    if(ElNumeroEsPositivo==1)
    {
        printf("\nsi es positivo");
    }else
    {
        printf("\nNO es positivo");
    }
   /*fin test*/


    return 0;
}



int getInt(char mensaje[], char mensajeError[], int minimo, int maximo)
{
    int valorDeRetorno;
    int flagError;
    flagError=0;
    do{

        if(flagError==0)
        {
             printf("%s",mensaje);
             flagError=1;
        }else
        {
             printf("%s",mensajeError);
        }
        scanf("%d",&valorDeRetorno);
    }while(valorDeRetorno<minimo || valorDeRetorno>maximo);
    return valorDeRetorno;

}
Ingresar números hasta que el usuario lo decida. Los números tienen que estar
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

int getInt(char mensaje[], char mensajeError[], int minimo, int maximo);
int esPositivo(int numeroPorParametro);
float promediarNumeros(int acumulador,int contador);

int main()
{
    char respuesta;
    float promedio;
    int ElNumeroEsPositivo;
    int numeroIngresado;
    int cantidadDePositivos;
    int cantidadDeNegativos;
    int contadorDeNumeros;
    int sumaDeNumeros;
    int maximoDeLosPositivos;

    cantidadDePositivos=0;
    cantidadDeNegativos=0;


    do{

       contadorDeNumeros++;
       numeroIngresado= getInt("Ingrese numero "," no esta entre el maximo y el minimo",-100,100);
       sumaDeNumeros=sumaDeNumeros+numeroIngresado;

       if(esPositivo(numeroIngresado))
       {
           cantidadDePositivos++;
            // d. De los positivos el máximo.
           if(maximoDeLosPositivos<numeroIngresado ||cantidadDePositivos==1)
           {
                maximoDeLosPositivos=numeroIngresado;
           }

       }else
       {
           if(numeroIngresado!=0)
           {
               cantidadDeNegativos++;
           }
       }

        printf("\ndesea continuar : ");
        __fpurge(stdin);
        scanf("%c",&respuesta);
    }while(respuesta=='s');

    promedio=promediarNumeros(sumaDeNumeros,contadorDeNumeros);


    return 0;
}



int getInt(char mensaje[], char mensajeError[], int minimo, int maximo)
{
    int valorDeRetorno;
    int flagError;
    flagError=0;
    do{

        if(flagError==0)
        {
             printf("%s",mensaje);
             flagError=1;
        }else
        {
             printf("%s",mensajeError);
        }
        scanf("%d",&valorDeRetorno);
    }while(valorDeRetorno<minimo || valorDeRetorno>maximo);
    return valorDeRetorno;

}






int esPositivo(int numeroPorParametro)
{
    /*
    int valorDeRetorno;
    if(numeroPorParametro>0)
    {
        valorDeRetorno=1;
        //return 1;
    }else
    {
       valorDeRetorno=0;
        //return 0;
    }

    return valorDeRetorno;
     */
    return numeroPorParametro>0;
}

float promediarNumeros(int acumulador,int contador)
{
    /*
    float valorDeRetorno;
    valorDeRetorno=(float)acumulador/contador;
    return valorDeRetorno;
    */
    return (float)acumulador/contador;

}





   /*test*/
    /*
    numeroIngresado=  getInt("ingrese un numero","reingrese por fa!!!",10,20);
    printf("\n el numero es : %d",numeroIngresado);

    promedio= promediarNumeros(50,3);
     printf("\n%f",promedio);
    respuesta='s';
    printf("\n%c",respuesta);

    ElNumeroEsPositivo=esPositivo(666);
    if(ElNumeroEsPositivo==1)
    {
        printf("\nsi es positivo");
    }else
    {
        printf("\nNO es positivo");
    }


    ElNumeroEsPositivo=esPositivo(0);
    if(ElNumeroEsPositivo==1)
    {
        printf("\nsi es positivo");
    }else
    {
        printf("\nNO es positivo");
    }

    ElNumeroEsPositivo=esPositivo(-555);
    if(ElNumeroEsPositivo==1)
    {
        printf("\nsi es positivo");
    }else
    {
        printf("\nNO es positivo");
    }*/
   /*fin test*/












