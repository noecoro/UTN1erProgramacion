/*
 * Producto.h
 *
 *  Created on: Apr 23, 2020
 *      Author: Mauro
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#define NAME_LEN 51
#define LAST_NAME_LEN 51

typedef struct
{
	char name[NAME_LEN]; //
	char lastName[LAST_NAME_LEN];
	float salary;
	int isEmpty;//
	int id;//
	int sector;
}Employee;

int emp_imprimir(Employee* auxProducto);
int emp_initEmployees(Employee* array,int limite);
int emp_getEmptyIndex(Employee* array,int limite);
int emp_imprimirArray(Employee* array,int limite);
int emp_buscarId(Employee array[], int limite, int valorBuscado);
int emp_ordenarPorNombre(Employee* array,int limite);
int emp_modificarArray(Employee* array,int limite, int indice);
int emp_bajaArray(Employee* array,int limite, int indice);
int emp_addEmployees(Employee* array, int limite, int indice, int* id, char* name,char* lastName ,float* salary,int* sector);


#endif /* ARRAYEMPLOYEES_H_ */
