#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"

/**********************************************************************/

/**
 * \brief Verifica si la cadena ingresada es un nombre valido
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 *
 */
static int esNombre(char* cadena,int longitud);
static int esNumerica(char* cadena, int limite);


/** \brief Reserva un espacio de memoria para una variable de tipo  Empleado de manera dinamica
 *  \param void
 *  \return  Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */

Employee* employee_new()
{
	Employee* auxiliarP = NULL;
	auxiliarP = (Employee*) malloc(sizeof(Employee));
	return auxiliarP;
}


/** \brief Reserva un espacio de memoria para una variable de tipo  Empleado de manera dinamica y le asigna a los campos los parametros correspodientes recibidos
 *  \param idint identificador a incorporar;
 *  \param nombreStr char*  nombre a incoporar
 *  \param horasTrabajadas int horas trabajadas por el empleado
 *  \param  sueldo int salario devengado por el empleado
 *  \returnRetorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */


Employee* employee_newParametros(int id,char* nombreStr,int horasTrabajadas,int sueldo)
{
	Employee* punteroEmpleado = NULL;


	if (id >=0 && nombreStr != NULL && horasTrabajadas >=0 && sueldo >=0)
	{
			punteroEmpleado =  employee_new();
			if(punteroEmpleado != NULL)
			{
				if( employee_setNombre( punteroEmpleado,nombreStr)==-1 ||
						employee_setHorasTrabajadas(punteroEmpleado,horasTrabajadas)==-1 ||
						employee_setId(punteroEmpleado, id) ==-1 ||
						employee_setSueldo(punteroEmpleado, sueldo)==-1)
						{
							employee_delete(punteroEmpleado );
							punteroEmpleado = NULL;
						}
			}
	}
	return punteroEmpleado;
}

/** \brief Reserva un espacio de memoria para una variable de tipo  Empleado de manera dinamica y le asigna a los campos los parametros correspodientes recibidos
 *  \param idStr char* identificador a incorporar;
 *  \param nombre char*  nombre a incoporar
 *  \param horasTrabajadas char* horas trabajadas por el empleado
 *  \param  sueldo char* salario devengado por el empleado
 *  \returnRetorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */


Employee* employee_newParametrosTxt(char* id,char* nombre, char*  horasTrabajadas,char*  sueldo)
{
	Employee* punteroEmpleado = NULL;


	if ( id != NULL && nombre != NULL && horasTrabajadas  != NULL && sueldo != NULL)
	{
			punteroEmpleado =  employee_new();
			if(punteroEmpleado != NULL)
			{
					if(employee_setIdTxt(punteroEmpleado, id) == -1 ||
						employee_setNombre(punteroEmpleado,nombre) == -1 ||
							employee_setHorasTrabajadasTxt(punteroEmpleado, horasTrabajadas)== -1 ||
								employee_setSueldoTxt(punteroEmpleado, sueldo)==-1 )
						{
							employee_delete(punteroEmpleado );
							punteroEmpleado = NULL;
						}
			}
	}
	return punteroEmpleado;
}

/** \brief libera un espacio de memoria de un elemento de tipo  Empleado creado de manera dinamica
 *  \param this Employee* puntero al elemento a ser eliminado
 *  \return  Retorna (NULL)  de no consegurir el puntero al espacio reservado
 */


void employee_delete(Employee* this )
{
	if(this != NULL)
	{
		free(this);
	}
}


/*
 *brief Modifica el campo id de un elemento de la lista
 *
 * \param this Employee* Puntero al elemento de  la lista de empleados
 * \param char id* Puntero al nuevo id
 * \return int Retorna  (-1) Error: si el puntero al elemento lista es NULL o si el atributo recibido es NULL
                        ( 0) Si funciono correctamente
 */

int employee_setIdTxt(Employee* this,char* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		if(esNumerica(id,ID_LEN))
		{
			retorno = 0;
			this->id = atoi(id);
		}
	}
	return retorno;
}




/*
 *brief Modifica el campo id de un elemento de la lista de empleados
 *
 * \param this Employee* Puntero a un elemento de la lista de empleados
 * \param id int* valor del nuevo id
 * \return int Retorna  (-1) Error: si el puntero al elemento lista es NULL o si el id es menor a cero
                        ( 0) Si funciono correctamente
 */
int employee_setId(Employee* this, int id)
{
	int retorno = -1;
	if(this != NULL && id >= 0)
	{
		retorno = 0;
		this->id = id;
	}
	return retorno;
}

/** \brief Permite leer el id asignado a un elemento
 * \param this Employee* Puntero a un elemento de la lista de empleados
 * \param id int* Puntero al id a ser cargado
 * \return void* Retorna    (-1) Error: si el puntero al elemento lista es NULL o si  el puntero a id es NULL
                            ( 0) Si funciono correctamente
 */

int employee_getId(Employee* this,int* id)

{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		retorno = 0;
		*id = this->id;
	}
	return retorno;
}

/** \brief Permite leer el id asignado a un elemento
 * \param this Employee* Puntero a un elemento de la lista de empleados
 * \param id char * Puntero al id a ser cargado
 * \return void* Retorna    (-1) Error: si el puntero al elemento lista es NULL o si  el puntero a id es NULL
                            ( 0) Si funciono correctamente
 */


int employee_getIdTxt(Employee* this,char* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		retorno = 0;
		snprintf(id,ID_LEN,"%d",this->id);
	}
	return retorno;
}


/*
 *brief Modifica  el campo nombre de un elemento de la lista de empleados
 *
 * \param this Employee* Puntero a un elemento de la lista de empleados
 * \param nombre char* Puntero al nuevo nombre
 * \return int Retorna  (-1) Error: si el puntero al elemento lista es NULL o si el otro parametro recibido es NULL
                        ( 0) Si funciono correctamente
 */


int employee_setNombre(Employee* this,char* nombre)

{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{


		if(esNombre(nombre,NOMBRE_LEN))
		{
			retorno = 0;
			strncpy(this->nombre,nombre,NOMBRE_LEN);
		}
	}
	return retorno;
}


/** \brief Permite leer el nombre asignado a un elemento
 * \param this Employee* Puntero a un elemento de la lista de empleados
 * \param noombre char* Puntero al nombre a cargarse
 * \return  Retorna  (-1) Error: si el puntero al elemento lista es NULL o si el otro parametro recibido es NULL
                            ( 0) Si funciono correctamente
 */
int employee_getNombre(Employee* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		retorno = 0;

		strncpy(nombre,this->nombre,NOMBRE_LEN);
	}
	return retorno;
}


/*
 *brief Modifica  el campo horas trabajadas de un elemento de la lista de empleados
 *
 * \param this Employee* Puntero a un elemento de  la lista de empleados
 * \param horasTrabajadas int valor de  las horas trabajadas
 * \return int Retorna  (-1) Error: si el puntero al elemento lista es NULL o si parametro recibido es menor a 0
                        ( 0) Si funciono correctamente
 */

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno = -1;

	if(this != NULL && horasTrabajadas >= 0)
	{
		retorno = 0;
		this->horasTrabajadas = horasTrabajadas;
	}
	return retorno;
}
/*
 *brief Modifica  el campo horas trabajadas de un elemento de la lista de empleados
 *
 * \param this Employee* Puntero a un elemento de la lista de empleados
 * \param horasTrabajadas char* Puntero a las horas trabajadas
 * \return int Retorna  (-1) Error: si el puntero al elemento lista es NULL o si el otro parametro recibido es NULL
                        ( 0) Si funciono correctamente
 */

int employee_setHorasTrabajadasTxt(Employee* this, char* horasTrabajadas)
{
	int retorno = -1 ;


	if(this != NULL && horasTrabajadas != NULL)
	{
		if(esNumerica(horasTrabajadas,HORAS_LEN)== 1)
		{
			if((this->horasTrabajadas = atoi(horasTrabajadas))>=0)
			{
				retorno = 0;
			}

		}

	}
	return retorno;
}

/** \brief Permite leer la cantidad de horas trabajadas asignadas a un elemento
 * \param this Employee* Puntero a un elemento de la lista de empleados
 * \param horas trabajadas int* Puntero de horas trabajadas  a ser cargado
 * \return void* Retorna    (-1) Error: si el puntero al elemento lista es NULL o si el otro paramentro recibido es NULL
                            ( 0) Si funciono correctamente
 */


int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas)
{
	int retorno = -1;
	if(this != NULL && horasTrabajadas != NULL)
	{
		 retorno = 0;
		* horasTrabajadas = this->horasTrabajadas;
	}
	return retorno;
}

/** \brief Permite leer la cantidad de horas trabajadas asignadas a un elemento
 * \param this Employee* Puntero a un elemento de la lista de empleados
 * \param horas trabajadas char * Puntero de horas trabajadas  a ser cargado
 * \return void* Retorna    (-1) Error: si el puntero al elemento lista es NULL o si el otro paramentro recibido es NULL
                            ( 0) Si funciono correctamente
 */
int employee_getHorasTrabajadasTxt(Employee* this, char* horasTrabajadas)
{
	int retorno = -1;
	if(this != NULL && horasTrabajadas != NULL)
	{
		 retorno = 0;

		snprintf(horasTrabajadas, HORAS_LEN, "%d", this->horasTrabajadas);
	}
	return retorno;
}


/*
 *brief Modifica  el campo sueldo de un elemento de la lista de empleados
 *
 * \param this Employee* Puntero a un elementos de la lista de empleados
 * \param sueldo int valor del sueldo del elemento
 * \return int Retorna  (-1) Error: si el puntero al elemento lista es NULL o si el otro parametro recibido es mayor a cero
                        ( 0) Si funciono correctamente
 */

int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno = -1;

	if(this != NULL && sueldo >= 0)

		{
			retorno = 0;
			this->sueldo = sueldo;
		}


	return retorno;
}
/*
 *brief Modifica  el campo sueldo de un elemento de la lista de empleados
 *
 * \param this Employee* Puntero a un elemento de la lista de empleados
 * \param sueldo char*  puntero al sueldo correspodiente del elemento
 * \return int Retorna  (-1) Error: si el puntero al elemento lista es NULL o si el otro parametro recibido es NUL
                        ( 0) Si funciono correctamente
 */

int employee_setSueldoTxt(Employee* this,char* sueldo)
{
	int retorno = -1;
	int auxiliarSueldo;

	if(this != NULL && sueldo != NULL)
		{

			if(esNumerica(sueldo,SUELDO_LEN) == 1)
			{

				if((auxiliarSueldo = atoi (sueldo))>= 0)
				{
					this->sueldo = auxiliarSueldo;
					retorno = 0;
				}


			}


		}


	return retorno;
}

/** \brief Permite leer el sueldo asignado a un elemento
 * \param this Employee* Puntero a un elemento de la lista de empleados
 * \param sueldo  int* Puntero de sueldo  a ser cargado
 * \return void* Retorna    (-1) Error: si el puntero al elemento lista es NULL o si e otro parametro recibido es NULL
                            ( 0) Si funciono correctamente
 */

int employee_getSueldo(Employee* this, int* sueldo)
{
	int retorno = -1;
	if(this != NULL && sueldo != NULL)
	{
		retorno = 0;
		*sueldo  = this->sueldo;
	}
	return retorno;
}


/** \brief Permite leer el sueldo asignado a un elemento
 * \param this Employee* Puntero a un elemento de la lista de empleados
 * \param sueldo char* Puntero de sueldo  a ser cargado
 * \return void* Retorna    (-1) Error: si el puntero al elemento lista es NULL o si e otro parametro recibido es NULL
                            ( 0) Si funciono correctamente
 */

int employee_getSueldoTxt(Employee* this, char* sueldo)
{
	int retorno = -1;
	if(this != NULL && sueldo != NULL)
	{
		retorno = 0;
		snprintf(sueldo, SUELDO_LEN, "%d", this->sueldo);
	}
	return retorno;
}

/** \brief Permite imprimir por pantalla los valores de los campos asignados de un elemento recibido
 * \param this Employee* Puntero a un elemento de la lista de empleados
 * \return  Retorna    (-1) Error: si el puntero al elemento lista es NULL
                            ( 0) Si funciono correctamente
 */
int employee_printElement(Employee* this)
{
	int retorno= -1;
	int auxiliarId;
	char auxiliarNombre [NOMBRE_LEN];
	int auxiliarHorasTrabajadas;
	int auxiliarSueldo;

	if(this!=NULL)
	{
		if(employee_getId(this, &auxiliarId) == 0 &&
			employee_getNombre(this, auxiliarNombre)== 0 &&
			employee_getHorasTrabajadas(this, &auxiliarHorasTrabajadas)== 0 &&
			employee_getSueldo(this, &auxiliarSueldo)==0)
				 {

					 printf("\t %d \t %s \t  \t \t %d \t\t %d \n" , auxiliarId, auxiliarNombre,auxiliarHorasTrabajadas, auxiliarSueldo);
					 retorno = 0;
				 }
	}

	return retorno;
}

/**********************************************************************/

/**
 * \brief Verifica si la cadena ingresada es un nombre valido
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 *
 */
static int esNombre(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es numerica, 0 (falso) si no lo es y -1 en caso de error
 *
 */
static int esNumerica(char* cadena, int limite)
{
	int retorno = -1; // ERROR
	int i;
	if(cadena != NULL && limite > 0)
	{
		retorno = 1; // VERDADERO
		for(i=0;i<limite && cadena[i] != '\0';i++)
		{
			if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
			{
				continue;
			}
			if(cadena[i] < '0'||cadena[i] > '9')
			{
				retorno = 0;
				break;
			}
			//CONTINUE
		}
		//BREAK
	}
	return retorno;
}




