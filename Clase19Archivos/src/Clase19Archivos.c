/*
 ============================================================================
 Name        : Clase19Archivos.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================


 -----Trabajo sobre archivos:

 Las dos categorias de funciones con las que se puede trabajar sobre archivos son  las que usan buffer
 y las que acceden directamente al archivo. Solo vamos a trabajar la escritura o lectura sobre el archivo
 mediante el buffer sin acceso directo en este proyecto

 algunas funciones usadas para trabajar con archivos:

 FILE *fopen(char *nombre,char *modo);
int fclose(FILE *fp);
int fcloseall(void);
int fread(void *memoria,int num,int cont,FILE *fp);
int fwrite(void *memoria,int num,int cont,FILE *fp);
int fclose(FILE *f);
int feof(FILE *f);
int ferror(FILE *fp);
void rewind(FILE *fp);
int fseek(FILE *fp,long num,int origen);
long ftell(FILE *f);
int getc(FILE *fp);
int putc(int ch,FILE *fp);
char* fgets(char *str,int n,FILE *fp);
int fputs(const char *str,FILE *fp);
int fscanf(FILE *fp,const char *formato[,dirección,...]);
int fprintf(FILE *fp,const char *formato[,argumento,...]);

 fread () realiza la lectura y fwrite la escritura  son funciones que permiten manipular el archivo
 tomando o dejando esos datos en el archivo

------------Apertura de un archivo
FILE * fopen (const char *Nombre_de_archivo , const char *Modo)

Nombre_de_archivo: se pone la ruta y el nombre del archivo
Modo: como sera abierto el archivo
r txt de lectura, rb binario de lectura, r+b binario de escritura mas lectura y r+ txt de lectura y escitura
w txt de escritura wb binario de escritura, w+b binario de escritura mas lectura y w+ txt de lectura y escitura
a txt de añadir datos ab binario de añadir datos, a+b binario de escritura mas lectura y w+ txt de lectura y escitura

modo escritura Si el archivo que se desea abrir tiene atributo de solo lectura o el disco esta lleno, etc. la
función 'fopen()' devuelve error.

Modo lectura ( r ): Si se abre un archivo para operaciones de lectura ( r , rb , r+b , r+ ) , si
el archivo no existe la función 'fopen()' devuelve error.

Modo append ( a ): Si se abre un archivo para agregar datos ( a , ab , a+b , a+ ) y el
archivo no existe se creará, caso contrario el indicador de posición del archivo queda
posicionado al final del mismo de forma de poder agregar datos.
Cada vez que se agregan datos se hace al final del archivo.


Valor retornado: Si el archivo es abierto exitosamente , la función devuelve un puntero a la
estructura FILE asociada al archivo. En caso de detectarse un error devuelve NULL
A tener en cuenta:
•
Se pueden abrir varios archivos al mismo tiempo siempre y cuando exista por lo menos
un puntero a FILE para cada uno.
•
La cantidad de archivos que se pueden abrir al mismo tiempo depende del sistema
operativo.
•
No se debe modificar el valor del puntero devuelto por 'fopen()'.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	{
		FILE *parch;
		char nombre[20];

			printf("\nIngrese el nombre y ruta del archivo que desea abrir: ");
			gets(nombre);
			if((parch=fopen( nombre ,"rb"))==NULL)
			{
					if((parch=fopen( nombre ,"wb"))==NULL)
					{
						printf("\nEl archivo %s no puede ser abierto",nombre);
						exit (1);
					}
					fclose(parch);
			}
		}
	return 0;
}
