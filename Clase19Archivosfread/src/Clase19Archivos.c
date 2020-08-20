	/*
 ============================================================================
 Name        : Clase19Archivos.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================




 int fwrite ( void * origen , size_t tamaño , size_t cantidad , FILE *arch);
Donde:
•origen: Es un puntero al lugar desde donde se obtienen los datos para escribir en el
archivo
• tamaño: Es el tamaño en bytes del dato que se va a escribir
• cantidad: Es la cantidad de datos de longitud tamaño que se van a escribir
• arch: Es el puntero a FILE asociado al archivo
Nota: size_t es un unsigned int definido en stdio.h
Valor retornado: Devuelve el número de datos escritos (cantidad). Si el valor retornado es
menor al que se indicó por medio de la variable cantidad , significa que hubo un error en la
escritura.



 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
{
	//Ejemplo: Si queremos escribir en un archivo de texto:
	FILE *parch;
	char texto[ ]="Prueba de escritura";
	int cant , longi;

	if((parch=fopen("prueba.txt","w"))==NULL) //Se abre en modo escritura
	{
		printf("\nEl archivo no puede ser abierto");
		exit (1);
	}

	longi=strlen (texto );

	cant=fwrite ( texto , sizeof ( char ) , longi , parch ); //Se escribe al archivo

	if (cant<longi)
		printf("\nError al escribir el archivo");
	else
		printf("\nSe escribieron %d caracteres", cant);

	fclose(parch);


	//Si se trata de un archivo binario el programa será el siguiente:

	struct a

	{
		char nombre[10];
		int edad;
	};

	void main (void)
	{
	FILE *bin;
	struct a pers;
	bin=fopen("bin.dat","wb");
	printf("\nIngrese el nombre: ");
	gets(pers.nombre);
	printf("Ingrese la edad: ");
	scanf("%d",&pers.edad);
	fflush(stdin);
	fwrite(&pers,sizeof(pers),1,bin);
	fclose(bin);
}

	return 0;

}
