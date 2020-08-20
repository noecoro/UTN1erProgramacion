#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \param proximoId int* puntero al proximo Id a generarse
 * \return retorna 0 si logra cargar a data correctamente y
 *		           -1 de lo contrario
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee, int* proximoId)
{
  int retorno=-1;

  FILE* pArchivo;

  	  if(path!= NULL && pArrayListEmployee!= NULL && proximoId != NULL )
  	  {
  		 if((pArchivo= fopen(path, "r"))!=NULL)
  		 {

  			parser_EmployeeFromText( pArchivo ,  pArrayListEmployee,  proximoId);

				retorno= 0 ;
  			fclose(pArchivo);
  		 }

  	  }




	return retorno;

}



/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * * \param proximoId int* puntero al proximo Id a generarse
 * \return retorna 0 si logra cargar a data correctamente y
 *		           -1 de lo contrario
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee, int* proximoId )
{
	int retorno=-1;
	FILE* pArchivo;

	  if(path != NULL && pArrayListEmployee!= NULL && proximoId != NULL )

	  {

		 if((pArchivo= fopen(path , "rb"))!=NULL)
		 {
			if(parser_EmployeeFromBinary( pArchivo ,  pArrayListEmployee,  proximoId)==0)
			{
				retorno= 0 ;
			}


		 } fclose(pArchivo);

	  }




	return retorno;

}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	if(pArrayListEmployee!=NULL)
	{




	}
    return 1;
}




/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return  Retorna    ( 0) Si funciono correctamente
 	 	 	 	 	 	(-1) de lo contrario
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
  int retorno= -1;
  int index;
  Employee* pEmpleado;

  if(pArrayListEmployee!= NULL)
  {	retorno =0;
	  printf("\t ID \t NOMBRE \t HORAS TRABAJADAS \t SUELDO \n");

	    for( index=0; index < ll_len(pArrayListEmployee);index++)
	    {
	  	 if(( pEmpleado = (Employee*)ll_get(pArrayListEmployee, index))!=NULL)
	  		{
	  		 employee_printElement(pEmpleado);
	  		}
	    }

  }


	return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

