/*
 * UTN.c
 *
 *  Created on: 18 abr. 2020
 *      Author: yusmelis
 */


int SacarIndiceLibre(int parametroArray [],int cantidad, int valorInicio)
{
    int i;
    for(i=0;i<cantidad;i++)
    {
        if(parametroArray[i]==valorInicio)
        {
            break;
        }
    }
    if(i==cantidad)
    {
        i=-1;
    }
    return i;
}
float SacarPromedio(int parametroArray[],int cantidad, int valorInicio)
{

    int cantidadDeElementos;
    int sumaDeElementos;
    float valorDeRetorno;
    cantidadDeElementos=SacarCantidadDeNumeros(parametroArray,cantidad,valorInicio);
    sumaDeElementos=SacarLaSuma(parametroArray,cantidad,valorInicio);
    valorDeRetorno=(float)sumaDeElementos/cantidadDeElementos;
    return valorDeRetorno;
    /*
    return (float)SacarLaSuma(parametroArray,cantidad,valorInicio)/SacarCantidadDeNumeros(parametroArray,cantidad,valorInicio);*/
}

int SacarCantidadDeNumeros(int parametroArray[],int cantidad, int valorInicio)
{
    int i;
    int valorDeRetorno=0;
    for(i=0;i<cantidad;i++)
    {
        if(parametroArray[i]!=valorInicio)
        valorDeRetorno=valorDeRetorno+1;
    }
    return valorDeRetorno;
}

void InicializarArray(int parametroArray[],int cantidad, int valorInicio)
{
    int i;
    for(i=0;i<cantidad;i++)
    {
        parametroArray[i]=valorInicio;
    }
}
void MostarArray(int parametroArray[],int cantidad)
{
    int i;
     for(i=0;i<cantidad;i++)
    {
        printf("\nel numero #%d : %d",i,parametroArray[i]);
    }
}
int SacarLaSuma(int parametroArray[],int cantidad, int valorInicio)
{
    int acumulador=0;
    int i;

    for(i=0;i<cantidad;i++)
    {
        if(parametroArray[i]!=valorInicio){
             acumulador=acumulador+parametroArray[i];
        }
    }
    return acumulador;
}
void testArray(int parametroArray[],int cantidad)
{
    printf("\n Array es %d",parametroArray[0]);
    printf("\n Array es %d",parametroArray);
    printf("\n puntero 0 es %d",&parametroArray[0]);
    printf("\n puntero 1 es %d",&parametroArray[1]);
    printf("\n puntero  al ultimo es %d",&parametroArray[cantidad-1]);
}
