/*
 ============================================================================
 Name        : prueba.c
 Author      : yus
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
	int flag = TRUE;
	int min;
	int max;


	do
	{

		printf("ingrese numero , Con 888 finaliza el ingreso con ):" );
		scanf("%d",&bufferInt);

			if(flag == TRUE )
			{
				min=bufferInt;
				max=bufferInt;
				flag=FALSE;
			}
			else
			{
				if(bufferInt==888)
				{
					break;
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
	}while(1);
	printf("el maximo es: %d y el minimo es %d", max, min);
	return 0;
}



