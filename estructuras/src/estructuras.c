/*
 ============================================================================
 Name        : estructuras.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
/*struct remedios

{

	char laboratorio[20];
	char nombre[10];
	float precio;
};

void funcion1(int a, int b);

void main(void)
{
int x,y,z;
struct remedio medic1;

medic1.precio = 10.60;
strcpy(medic1.nombre,"aspirina");
 strcpy(medic1.laboratorio,"bayer");
}
void funcion1(int a, int b)
{
	struct remedio x, vec[10];
	int suma;
}*/

/*struct alumno
{
	char nombre[10];
	int nota;
};


int main(void)
{
	struct alumno alu[20];
	int i;nombre es %s y su nota es %d",alu[1].nombre,alu[1].nota);

}

	for(i=0;i<20;i++)
	{

	printf("\ningrese su nombre");
	gets(alu[i].nombre);

	printf ("\ningrese su nota");
	scanf("%d",&alu[i].nota);
	__fpurge(stdin);

	printf("su nombre es %s y su nota es %d",alu[i].nombre,alu[i].nota);
	alu[1]=alu[0];
	printf("\nsu nombre es %s y su nota es %d",alu[1].nombre,alu[1].nota);

	}
}*/
// anidar estructuras:

struct fecha {int dia, mes, anio;};
struct gente
{
	char nombre;
	struct fecha f_nacimiento;
}

void main(void)
{
	struct gente persona;
	struct fecha fn;

	printf("ingrese su nombre");
	gets(persona.nombre);

	printf("\n ingrese su dia de nacimiento");
	scanf("%d",fn.dia);

	printf("\n ingrese su mes de nacimiento");
	scanf("%d",fn.mes);


	printf("\n ingrese su año de nacimiento");
	scanf("%d",fn.anio);

	persona.f_nacimiento=fn;

		printf("%d",persona.f_nacimiento);
}

