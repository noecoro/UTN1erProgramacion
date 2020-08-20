/*
 ============================================================================
 Name        : Clase.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================


#include <stdio.h>
#include <stdlib.h>

#define L 100
int main(void) {

/*carga secuencuencial
	int i;
	int edad [L];
	float salario [L],suma=0,promedio;

	for(i=0; i<L; i++)
	{
		printf("ingrese la edad del legajo %d", i+1);
		scanf("%d",&edad[i]);

		printf("\n ingrese el salario del legajo %d", i+1);
		scanf("%f",&salario[i]);
		suma+=salario[i];

	}
	promedio=suma/L;
	printf("el promedio del salario es %f",promedio);


 */
	//carga aleatoria
#include <stdio.h>
#define MAX 100
void main(void)
{
int edad[MAX],i,leg;
float sueldo[MAX],suma=0,prom,aux;
char seguir;
for(i=0;i<MAX;i++)
{
edad[i]=0;
sueldo[i]=0;
}
do
{
printf("Ingrese Legajo");
scanf("%d",&leg);
printf("Ingrese Edad");
scanf("%d",&edad[leg-1]);
printf("Ingrese el sueldo");
scanf("%f",&aux);
sueldo[i]=aux;
printf("Desea ingresar otro dato S/N?");
scanf("%c",&seguir);
}while(seguir=='s');
for(i=0;i<MAX;i++)
suma=suma+sueldo[i];
prom=suma/MAX;
printf("El sueldo promedio es %.2f",prom);


