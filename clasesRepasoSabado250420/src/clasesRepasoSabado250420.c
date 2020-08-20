/*
 ============================================================================
 Name        : clasesRepasoSabado250420.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
//primera parte de explicacion
#include <stdio.h>
typedef struct{

    int legajo;
    char nombre[20];
    int primeraNota;
    int segundaNota;
    float promedio;

}eAlumno;

int main()
{
    printf("\n\tRepaso estructuras");

    int nota;
    //int=3
    //eAlumno=3;

    eAlumno algunAlumno;
    eAlumno otroAlumno;
    algunAlumno.legajo=3;

    printf("\nsu legajo es: %d",algunAlumno.legajo);
    printf("\n ingrese legajo");
    scanf("%d",&algunAlumno.legajo);
    /*
     scanf("%d",&algunAlumno.legajo);
      scanf("%d",&algunAlumno.legajo);
      scanf("%d",&algunAlumno.legajo);
   */
    printf("\nsu nombre es: %s",algunAlumno.nombre);
    printf("\nsu primeraNota es: %d",algunAlumno.primeraNota);
    printf("\nsu segundaNota es: %d",algunAlumno.segundaNota);
    printf("\nsu promedio es: %f",algunAlumno.promedio);


      printf("\nsu nombre es: %s",otroAlumno.nombre);
    printf("\nsu primeraNota es: %d",otroAlumno.primeraNota);
    printf("\nsu segundaNota es: %d",otroAlumno.segundaNota);
    printf("\nsu promedio es: %f",otroAlumno.promedio);

    return 0;
}

//segunda parte de explicacion

#include "alumno.h"
#include <stdio.h>


int main()
{
    printf("\n\tRepaso estructuras");

    int nota;
    //int=3
    //eAlumno=3;

    eAlumno algunAlumno;
    eAlumno otroAlumno;

    algunAlumno=CargarUnAlumno();


    MostrarAlumno(algunAlumno);
    MostrarAlumno(otroAlumno);


    otroAlumno=algunAlumno;


      printf("\n algunAlumno");
    MostrarAlumno(algunAlumno);
     printf("\n otroAlumno");
    MostrarAlumno(otroAlumno);

    return 0;
}
 3 parte


#include "alumno.h"
#include <stdio.h>
#define CANT_ELEMENTOS 3

int main()
{
    printf("\n\tRepaso estructuras");
    int edades[CANT_ELEMENTOS];
    eAlumno listadoAlumnos[CANT_ELEMENTOS];

    MostrarListadoAlumnos(listadoAlumnos,CANT_ELEMENTOS);
    CargarListadoAlumnos(listadoAlumnos,CANT_ELEMENTOS);
    MostrarListadoAlumnos(listadoAlumnos,CANT_ELEMENTOS);
    return 0;
}
