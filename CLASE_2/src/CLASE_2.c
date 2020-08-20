/*
 ============================================================================
 Name        : CLASE_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int main(void) {

	int bufferInt;
	int i;
	int flag = TRUE;
	int min;
	int max;

	printf("ingrese un numero");
	scanf("%d",&bufferInt);

	for(i=0;i<5;i++)
	{
		if(flag == TRUE)
		{
			min=bufferInt;
			max=bufferInt;

		}
		else
		{
			if(bufferInt<min)
			{
				min=bufferInt;
			}
			if(bufferInt>max)
			{
				max=bufferInt;
			}
		}
	}
	printf("el maximo es: %d y el minimo es %d", max, min)
	return 0;
}
