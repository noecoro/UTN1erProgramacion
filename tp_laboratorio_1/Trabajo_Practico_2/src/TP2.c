/*
 * >>>> Trabajo practico 2 <<<<

 *
 * */

#include <stdio.h>
#include <stdlib.h>

#include "ArrayEmployees.h"
#include "utn.h"

#define QTY_EMPLOYEES 1000

int main(void) {

	Employee ArrayEmployees[QTY_EMPLOYEES];
char
	int idEmpleados = 0 ;
	int opcion;
	int auxiliarIndice;
	int auxiliarId;
	char auxiliarNombre[NAME_LEN];
	char auxiliarApellido[LAST_NAME_LEN];
	int auxiliarSector;
	float auxiliarSalario;

	if(emp_initEmployees(ArrayEmployees,QTY_EMPLOYEES) == 0)
	{
		printf("Array inicializado correctamente. \n\n");
	}
	do
	{
		if(!utn_getNumero(	&opcion,
							"\n\n1.Cargar un Empleado"
							"\n2.Modificar un Empleado"
							"\n3.Eliminar un Empleado"
							"\n4.Ordenar lista de Empleados"
							"\n5.Imprimir lista Empleados"
							"\n6.Salir\n\n",
							"\nError opcion invalida",1,6,2) )
		{
			switch(opcion)
			{
			case 1:
				auxiliarIndice = emp_getEmptyIndex(ArrayEmployees,QTY_EMPLOYEES);
				if(auxiliarIndice >= 0 )
				{	if(
						utn_getNombre(auxiliarNombre, NAME_LEN, "\nNombre?", "\nNombre invalido",2) == 0 &&
			 			utn_getNombre(auxiliarApellido, LAST_NAME_LEN, "\nApelllido?", "\nApellido invalido",2) == 0 &&
			 			utn_getNumeroFlotante(&auxiliarSalario,"\nSalario?","\nSalario invalido",1,1000000,2) == 0 &&
						utn_getNumero(&auxiliarSector,"ingrese numero de sector","Error Sector Ivalido",1,100,2)==0)
						{

							if(emp_addEmployees(ArrayEmployees,QTY_EMPLOYEES,auxiliarIndice,&idEmpleados, auxiliarNombre, auxiliarApellido, &auxiliarSalario,& auxiliarSector) == 0)
							{
								printf("\nCarga realizada con exito\n");
							}
						}

					else
					{
					printf("\nNO HAY MAS LUGAR");
					}
				}
				break;
			case 2:

				if(utn_getNumero(&auxiliarId,"\nIndique el ID del empleado a modificar","\nID invalido",0,idEmpleados,0) == 0)
				{
					auxiliarIndice = emp_buscarId(ArrayEmployees,QTY_EMPLOYEES,auxiliarId);
					if(	auxiliarIndice >= 0 &&
						emp_modificarArray(ArrayEmployees,QTY_EMPLOYEES,auxiliarIndice) == 0)
					{
						printf("\nModificacion realizada con exito\n");
					}
				}
				break;

			case 3:
				emp_imprimirArray(ArrayEmployees,QTY_EMPLOYEES);
				if(utn_getNumero(&auxiliarId,"\nIndique el ID del cliente a eliminar","\nID invalido",0,idEmpleados,0)==0)
				{
					auxiliarIndice = emp_buscarId(ArrayEmployees,QTY_EMPLOYEES,auxiliarId);
					if(	auxiliarIndice >= 0 &&
						emp_bajaArray(ArrayEmployees,QTY_EMPLOYEES,auxiliarIndice)== 0)
					{
						printf("\nBaja realizada con exito\n");
					}
				}
				break;
			case 4:
				emp_ordenarPorNombre(ArrayEmployees,QTY_EMPLOYEES);
				break;

			case 5:
				emp_imprimirArray(ArrayEmployees,QTY_EMPLOYEES);
				break;

			}
		}
	}while(opcion != 6);

	return EXIT_SUCCESS;
}





