/*
 ============================================================================
 Name        : ClaseRepaso25042020german.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include "alumno.h"
#include <stdio.h>
#define CANT_ELEMENTOS 5


typedef struct{
    int legajo;
    char nombre[20];
    int primeraNota;
    int segundaNota;
    float promedio;
}eAlumno;


void MostrarAlumno(eAlumno parametroAlumno);
eAlumno CargarUnAlumno();
void MostrarListadoAlumnos(eAlumno [],int);
void CargarListadoAlumnos(eAlumno [],int);
void MostrarAlumnosPromocionados(eAlumno[], int);
void MostrarAlumnosPorNombre(eAlumno[], int, char*);



int main()
{
    printf("\n\tRepaso estructuras\n");


    eAlumno listadoAlumnos[CANT_ELEMENTOS]={{100,"Maria",7,7,7},
                                            {101,"Juan",5,4,4.5},
                                            {102,"Pedro",7,6,6.5},
                                            {103,"Ana",8,8,8},
                                            {104,"Juan",3,4,3.5}};

    printf("LISTADO DE ALUMNOS\n");
    MostrarListadoAlumnos(listadoAlumnos,CANT_ELEMENTOS);
    printf("LISTADO DE ALUMNOS PROMOCIONADOS\n");
    MostrarAlumnosPromocionados(listadoAlumnos, CANT_ELEMENTOS);
    //CargarListadoAlumnos(listadoAlumnos,CANT_ELEMENTOS);
    //MostrarListadoAlumnos(listadoAlumnos,CANT_ELEMENTOS);
   printf("LISTADO DE ALUMNOS QUE SE LLAMAN JUAN\n");
   MostrarAlumnosPorNombre(listadoAlumnos, CANT_ELEMENTOS, "Juan");





    return 0;
}




void MostrarListadoAlumnos(eAlumno arrayAlumnos[],int cantidad){

    int i;
    for(i=0;i<cantidad;i++)
    {
        MostrarAlumno(arrayAlumnos[i]);
    }

}


void CargarListadoAlumnos(eAlumno arrayAlumnos[],int cantidad){

    int i;
    for(i=0;i<cantidad;i++)
    {
       arrayAlumnos[i]=CargarUnAlumno();
    }
}


eAlumno CargarUnAlumno(){

    eAlumno auxAlumno;

    printf("\n ingrese legajo:");
    scanf("%d",&auxAlumno.legajo);
    printf("\n ingrese Nombre:");
    __fpurge(stdin);
    fgets(auxAlumno.nombre,20,stdin);
    printf("\n ingrese primeraNota:");
    scanf("%d",&auxAlumno.primeraNota);
    printf("\n ingrese segundaNota:");
    scanf("%d",&auxAlumno.segundaNota);
    auxAlumno.promedio=(float)(auxAlumno.primeraNota+auxAlumno.segundaNota)/2;
    return auxAlumno;
}
void MostrarAlumno(eAlumno parametroAlumno){

    printf("%8d %20s %8d %8d %8.2f\n", parametroAlumno.legajo, parametroAlumno.nombre, parametroAlumno.primeraNota,parametroAlumno.segundaNota, parametroAlumno.promedio);

}

void MostrarAlumnosPromocionados(eAlumno listadoDeAlumnos[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(listadoDeAlumnos[i].primeraNota>=6 && listadoDeAlumnos[i].segundaNota>=6)
        {
            MostrarAlumno(listadoDeAlumnos[i]);
        }
    }

}

void MostrarAlumnosPorNombre(eAlumno listadoDeAlumnos[], int tam, char* nombre)
{
     int i;
    for(i=0; i<tam; i++)
    {
        if(strcmp(nombre, listadoDeAlumnos[i].nombre)==0)
        {
            MostrarAlumno(listadoDeAlumnos[i]);
        }
    }
}


//2da parte german
alumno.h

#include "alumno.h"
#include <stdio_ext.h>
#include <stdio.h>


void MostrarListadoAlumnos(eAlumno arrayAlumnos[],int cantidad){

    int i;
    for(i=0;i<cantidad;i++)
    {
        MostrarAlumno(arrayAlumnos[i]);
    }

}


void CargarListadoAlumnos(eAlumno arrayAlumnos[],int cantidad){

    int i;
    for(i=0;i<cantidad;i++)
    {
       arrayAlumnos[i]=CargarUnAlumno();
    }
}





#include "alumno.h"
#include <stdio.h>
#define CANT_ELEMENTOS 5



//main
int main()
{
    printf("\n\tRepaso estructuras\n");


    eAlumno listadoAlumnos[CANT_ELEMENTOS]={{100,"Maria",7,7,7},
                                            {101,"Juan",5,4,4.5},
                                            {102,"Pedro",7,6,6.5},
                                            {103,"Ana",8,8,8},
                                            {104,"Juan",3,4,3.5}};

    printf("LISTADO DE ALUMNOS\n");
    MostrarListadoAlumnos(listadoAlumnos,CANT_ELEMENTOS);
    printf("LISTADO DE ALUMNOS PROMOCIONADOS\n");
    MostrarAlumnosPromocionados(listadoAlumnos, CANT_ELEMENTOS);
    //CargarListadoAlumnos(listadoAlumnos,CANT_ELEMENTOS);
    //MostrarListadoAlumnos(listadoAlumnos,CANT_ELEMENTOS);
   printf("LISTADO DE ALUMNOS QUE SE LLAMAN JUAN\n");
   MostrarAlumnosPorNombre(listadoAlumnos, CANT_ELEMENTOS, "Juan");

     printf("LISTADO DE ALUMNOS ORDENADOS POR NOMBRE\n");
    OrdenarListadoPorNombre(listadoAlumnos, CANT_ELEMENTOS);
    MostrarListadoAlumnos(listadoAlumnos,CANT_ELEMENTOS);


    return 0;
}

//.c

#include "alumno.h"
#include <stdio_ext.h>
#include <stdio.h>


void MostrarListadoAlumnos(eAlumno arrayAlumnos[],int cantidad){

    int i;
    for(i=0;i<cantidad;i++)
    {
        MostrarAlumno(arrayAlumnos[i]);
    }

}


void CargarListadoAlumnos(eAlumno arrayAlumnos[],int cantidad){

    int i;
    for(i=0;i<cantidad;i++)
    {
       arrayAlumnos[i]=CargarUnAlumno();
    }
}
