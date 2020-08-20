/*
 * Alumno.h
 *
 *  Created on: 6 jun. 2020
 *      Author: yusmelis
 */

#ifndef ALUMNO_H_
#define ALUMNO_H_
#define NOMBRE_LEN 50

typedef struct
{
	char nombre[NOMBRE_LEN];
	int id;
	float altura;
}Alumno;

int alumno_initArray(Alumno* arrayPuntero[], int limite);
int alumno_buscarLibre(Alumno* arrayPuntero[], int limite);
int alumno_imprimirArray(Alumno* arrayPuntero[], int limite);
int alumno_deleteIndexInArray(Alumno* arrayPuntero[],  int index, int limite);
int alumno_buscarId(Alumno* arrayPuntero[], int limite, int id);
int alumno_agregarAlumno(Alumno* arrayPuntero[], int limite, char* nombre, int id, float altura);
int alumno_EliminarPorId(Alumno* arrayPuntero[], int limite, int id);


Alumno* alumno_new (void);
Alumno* alumno_newParametro (char* nombre, int id, float altura);


#endif /* ALUMNO_H_ */
