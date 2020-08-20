#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return -1 si alguno de los punteros recibidos es NULL y 0 si funciona correctamente
 *
 *
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee, int* proximoId)
{

	int retorno= -1;
	char auxiliarId [ID_LEN];
	char auxiliarNombre [NOMBRE_LEN];
	char auxiliarHorasTrabajadas [HORAS_LEN];
	char auxiliarSueldo[SUELDO_LEN];

	Employee* pEmpleado;


	if(pFile != NULL && pArrayListEmployee != NULL && proximoId != NULL)
	{
		retorno=0;

		do
		{

			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,\n]\n", auxiliarId, auxiliarNombre, auxiliarHorasTrabajadas, auxiliarSueldo)==4)
			{
				retorno = 1;
			  if((pEmpleado=employee_newParametrosTxt(auxiliarId, auxiliarNombre, auxiliarHorasTrabajadas, auxiliarSueldo))!=NULL)
			  {
				  if((ll_add(pArrayListEmployee, pEmpleado)==0))
					{
					  if(atoi(auxiliarId) >= *proximoId)
					  		{
					  		 *proximoId = atoi(auxiliarId)+1;
					  		}

					}
				   else
				   {
					   retorno=-1;
					   break;
					   printf("no se puede cargar las lista con el archivo");

				   }
			  }

			}
		}
		while(feof(pFile)==0);
	}


    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 \return -1 si alguno de los punteros recibidos es NULL y 0 si funciona correctamente *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee, int* proximoId)
{

	Employee empleado;
	Employee* pEmpleado;
	char auxiliarId [ID_LEN];
	char auxiliarNombre [NOMBRE_LEN];
	char auxiliarHorasTrabajadas [HORAS_LEN];
	char auxiliarSueldo[SUELDO_LEN];
	int cantidad=1;
	int retorno=-1;

	if(pFile != NULL && pArrayListEmployee != NULL && proximoId != NULL)
	{
		while(cantidad == 1)
		{


			if((cantidad = fread(&empleado, sizeof(Employee), 1, pFile))==1)
			{

				if(employee_getIdTxt(&empleado, auxiliarId) == 0 &&
				employee_getNombre(&empleado, auxiliarNombre) == 0 &&
				employee_getHorasTrabajadasTxt(&empleado, auxiliarHorasTrabajadas)== 0 &&
				employee_getSueldoTxt(&empleado, auxiliarSueldo) == 0)

				{

					  if((pEmpleado=employee_newParametrosTxt(auxiliarId, auxiliarNombre, auxiliarHorasTrabajadas, auxiliarSueldo))!=NULL)
					  {

						if(ll_add(pArrayListEmployee, pEmpleado )==0)
						  {

							 retorno=0;
							 if(atoi(auxiliarId) >= *proximoId)
							 	{
							 	 *proximoId = atoi(auxiliarId)+1;

							 	}
						 }
					  }
				}

			}

		}
	}


 return retorno;
}

