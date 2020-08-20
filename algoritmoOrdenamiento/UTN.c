/*
 * UTN.c
 *
 *  Created on: 13 abr. 2020
 *      Author: yusmelis
 */

float promediar(int acumulador, int contador)
{
	float valorDeRetorno;
	valorDeRetorno=(float)acumulador/contador;
	return valorDeRetorno;
}

int esPositivo(int numeroPorParametro)
{
	int valorDeRetorno;
	if(numeroPorParametro>0)
	{
		valorDeRetorno=1;
	}else
	{
		valorDeRetorno=0;
	}
	return valorDeRetorno;
}

int getInt(char mensaje[],char mensajeError[],int minimo, int maximo)
{
	int valorDeRetorno;
	int flag;

	flag=0;
	if(flag==0)
	{
		printf("%s",mensaje);
		flag=1;
	}else
	{
		printf("%s",mensajeError);
	}
	scanf("%d",&valorDeRetorno);
	return valorDeRetorno;
}
