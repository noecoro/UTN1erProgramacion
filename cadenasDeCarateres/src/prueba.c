/*
 ============================================================================
 Name        : prueba.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#define ELEMENTOS 5

int main(void) {
/*
//inicializar un vector
//char menu [ ][3]={"archivo"," nuevo"," Abrir"};
char texto[20];
char textoDos[20];
int x;
//obtener una cadena a partir del teclado con la funcion GETS:
//comparar una cadena con otr
printf("ingrese su password:");
gets(texto);

if(strcmp("1234",texto)==0)
	{
		printf("password correcto");
	}else
	{
		printf("password Incorrecto");
	}
//copiar una cadena en otra

strncpy(textoDos,texto,sizeof(textoDos));
printf("\n se ingreso: %s y el texto copiado es %s", texto,textoDos);
//medir la cantidad de caracteres escritos que hay en un vector antes del /0 contando los espacios
x=strnlen(textoDos,sizeof(textoDos));
printf( "la cantidad de cararteres de textoDos es : %d", x);
*/

	int i;
	int flagswap;
	int nuevoLimite;
	char auxiliar[50];
	char nombre[ELEMENTOS][50]= {"Pedro","Ernesto","Juan","Carlos","Mario"};
	char apellido[ELEMENTOS][50]= {"Gomez","Fernandez","Paz","Perez","Lopez"};

	nuevoLimite=ELEMENTOS-1;
	do{
		flagswap=0;
		for(i=0;i<nuevoLimite-1;i++)
		{
			;
			if(strcmp(nombre[i],nombre[i+1])>0)
			{	flagswap=1;
				strcpy(auxiliar,nombre[i]);
				strcpy(nombre[i],nombre[i+1]);
				strcpy(nombre[i+1],auxiliar);

				strcpy(auxiliar,apellido[i]);
				strcpy(apellido[i],apellido[i+1]);
				strcpy(apellido[i+1],auxiliar);

			}
			if(strcmp(nombre[i],nombre[i+1])==0)
			{
				if(strcmp(apellido[i],apellido[i+1])>0)
				{
					strcpy(auxiliar,apellido[i]);
					strcpy(apellido[i],apellido[i+1]);
					strcpy(apellido[i+1],auxiliar);
					flagswap=1;
				}


			}

		}

	}while(flagswap==1);

printf("\n\n Lista ordenada por nombres:");

	for(i=0;i<ELEMENTOS;i++)
	{
		printf("\n el nombre es: %s y el apellido es %s",nombre[i],apellido[i]);
	}



return 0;

}*\
