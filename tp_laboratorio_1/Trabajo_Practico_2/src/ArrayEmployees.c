/*
 * Producto.c
 *
 *  Created on: Apr 23, 2020
 *      Author: Mauro
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayEmployees.h"
#include "utn.h"

/**
 * \brief Imprime los datos de un empleado
 * \param pElemento Puntero al producto que se busca imprimir
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int emp_imprimir(Employee* pElemento)
{
	int retorno=-1;
	if(pElemento != NULL)
	{
		retorno = 0;
		printf("ID: %d- %s - %s - su salario es %.2f",pElemento->id, pElemento->name, pElemento->lastName, pElemento->salary);
	}
	return retorno;
}

/**
 * \brief Imprime el array de empleados
 * \param array Array de empleados a ser actualizado
 * \param limite Limite del array de clientes
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int emp_imprimirArray(Employee* array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		respuesta = 0;
		for(i=0;i<limite;i++)
		{
			if(array[i].isEmpty != 1)
			{
				printf("\nID: %d - %s - %s - su salario es %.2f",array[i].id,array[i].name,array[i].lastName,array[i].salary);

			}
		}
	}
	return respuesta;
}

/** \brief To indicate that all position in the array are empty,
*
this function put the flag (isEmpty) in TRUE in all
*
position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int emp_initEmployees(Employee* array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		respuesta = 0;
		for(i=0;i<limite;i++)
		{
			array[i].isEmpty = 1;
		}
	}
	return respuesta;
}

/**
 * \brief Da de alta un empleado en una posicion del array
 * \param array Array de empleados a ser actualizado
 * \param limite Limite del array de clientes
 * \param indice Posicion a ser actualizada
 * \param id Identificador a ser asignado al empleado
 *
 */
int emp_addEmployees(Employee* array, int limite, int indice, int* id, char* name,char* lastName ,float* salary,int* sector)
{
	int respuesta = -1;
	Employee auxiliar;
	if(array != NULL && limite > 0 && indice < limite)
	{
			strncpy(auxiliar.name, name, NAME_LEN );
			strncpy(auxiliar.lastName, lastName, LAST_NAME_LEN );
			auxiliar.salary =*salary;
			auxiliar.sector=*sector;
			array[indice] = auxiliar;
			array[indice].isEmpty = 0;
			array[indice].id = *id;
			*id = *id + 1;
			respuesta = 0;
	}

	return respuesta;
}

/**
 * \brief Da de alta un empleado en una posicion del array modo TEST
 * \param array Array de empleados a ser actualizado
 * \param limite Limite del array de empleados
 * \param indice Posicion a ser actualizada
 * \param id ID a ser asignado al empleado
 *  *
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int emp_altaTestArray(Employee* array,int limite, int indice, int* id, Employee auxiliar)
{
	int respuesta = -1;

	if(array != NULL && limite > 0 && indice < limite)
	{
		respuesta = 0;
		array[indice] = auxiliar;
		array[indice].isEmpty = 0;
		array[indice].id = *id;
		*id = *id + 1;
	}
	return respuesta;
}

/**
 * \brief Actualiza los datos de un empleado en una posicion del array
 * \param array Array de empleados a ser actualizado
 * \param limite Limite del array de empleados
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int emp_modificarArray(Employee* array,int limite, int indice)
{
	int respuesta = -1;
	Employee auxiliar;
	int opcion;
	if(array != NULL && limite > 0 && indice < limite)

	if(!utn_getNumero(&opcion,"/nseleccione la opcion  presionando el numero del area que desea  modificar:/n 1-nombre /n2 aṕellido, /n 3 salario, /n 4sector","\nError opcion invalida",1,4,2) )
			{
				switch(opcion)
				{
				case 1:
					utn_getNombre(auxiliar.name, NAME_LEN, "\nNombre?", "\nNombre invalido",2);
					break;
				case 2 :
					utn_getNombre(auxiliar.lastName, LAST_NAME_LEN, "\nApelllido?", "\nApellido invalido",2) ;
					break;
				case 3: utn_getNumeroFlotante(&auxiliar.salary,"\nSalario?","\nSalario invalido",1,1000000,2);
					break;
				case 4: utn_getNumero(&auxiliar.sector,"ingrese numero de sector","error sector ivalido",1,100,2);
					break;

			respuesta = 0;
			array[indice] = auxiliar;
			array[indice].isEmpty = 0;
				}
	}
	return respuesta;
}
/**
 * \brief Actualiza una posicion del array
 * \param array Array de empleados a ser actualizado
 * \param limite Limite del array de empleados
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int emp_bajaArray(Employee* array,int limite, int indice)
{
	int respuesta = -1;
	if(array != NULL && limite > 0 && indice < limite)
	{
		respuesta = 0;
		array[indice].isEmpty = 1;
	}
	return respuesta;
}

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array empleados Array de empleados
* \param limite int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int emp_buscarId(Employee array[], int limite, int valorBuscado)
{
    int retorno=-1;
    int i;
    if(array!= NULL && limite>=0)
    {
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty==0 && array[i].id==valorBuscado)                                                   //cambiar campo ID
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}



/**
 * \brief Buscar primer posicion vacia
 * \param array Array de empleados
 * \param limite Limite del array de empleados
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
int emp_getEmptyIndex(Employee* array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			if(array[i].isEmpty == 1)
			{
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}

/**
 * \brief Ordenar el array de empleados por nombre
 * \param array Array de empleados
 * \param limite Limite del array de empleados
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
int emp_ordenarPorNombre(Employee* array,int limite)
{
	int respuesta = -1;
	int i;
	int flagSwap;
	Employee auxiliar;
	if(array != NULL && limite > 0)
	{
		respuesta = 0;
		do
		{
			flagSwap = 0;
			for(i=0;i<limite-1;i++)
			{

				if(	array[i].isEmpty == 0 &&
					array[i+1].isEmpty == 0 &&
					strncmp(array[i].name, array[i+1].name,NAME_LEN) > 0)
				{
					auxiliar = array[i];
					array[i]= array[i+1];
					array[i+1] = auxiliar;
					flagSwap = 1;
				}
			}
			limite--;
		}while(flagSwap);
	}
	return respuesta;
}



