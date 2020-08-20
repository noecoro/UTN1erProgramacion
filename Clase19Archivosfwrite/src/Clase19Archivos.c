/*
 ============================================================================
 Name        : Clase19Archivos.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

Lectura de un archivo
	Para realizar la lectura de un archivo se utiliza la función fread que tiene el siguiente prototipo
int fread ( void * destino , size_t tamaño , size_t cantidad , FILE *arch );
Donde:
• destino: Es un puntero al lugar donde se va a dejar el dato leido con fread
• tamaño: Es el tamaño en bytes del dato a leer
• cantidad: Es la cantidad de elementos de longitud tamaño que se van a leer
• arch: Es el puntero a la estructura FILE asociada al archivo desde el que se va a leer.

Valor retornado: Devuelve el número de datos leidos (cantidad). Si el valor retornado es
menor al que se indicó por medio de la variable cantidad , significa que hubo un error en la
lectura o que se llegó al final de archivo.

A diferencia de lo que ocurre en la escritura, se debe verificar que se realice la lectura mientras
no se haya llegado al final del archivo. Esta operación se realiza por medio de la función feof.


La función feof determina si se ha llegado al final de el archivo , el prototipo es:
int feof (FILE* arch );

Donde arch es el puntero a la estructura FILE asociada con el archivo. El valor retornado por la
función es 0 si no se llegó al final del archivo y distinto de cero si se llegó al final del archivo.

 */

#include <stdio.h>
#include <stdlib.h>

	struct a
	{
	char nombre[10];
	int edad;
	};

void main (void)
{
	FILE *bin;
	struct a pers;
	int cant;

	if ((bin=fopen("bin.dat","rb"))==NULL)
	{
		printf("No se pudo abrir el archivo");
		exit(1);
	}

	while(!feof(bin))
	{
			cant=fread(&pers,sizeof(pers),1,bin);
		if(cant!=1)
		{
			if(feof(bin))
			break;
		else
		{
			error("No leyo el ultimo registro");
			break;
		}
	}

	printf("\n%s\t%d",pers.nombre,pers.edad);
	}

	fclose(bin);

	getch();
}
