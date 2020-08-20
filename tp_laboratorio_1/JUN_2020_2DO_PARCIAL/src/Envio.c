#include "Envio.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include <ctype.h>

static int isValidNombre(char* cadena,int longitud);
static int esNumerica(char* cadena, int limite);
static int isValidZona(char* cadena,int longitud);
static int esFlotante(char* cadena);

static const char TXT_TIPOS [3] [25]={"Normal","expess","Segun Disponibilidad"};

/** \brief Reserva un espacio de memoria para una variable de tipo  Envio de manera dinamica
 *  \param void
 *  \return h* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
Envio* envio_new()
{
	Envio* auxiliarP = NULL;
	auxiliarP = (Envio*) malloc(sizeof(Envio));
	return auxiliarP;
}
/** \brief Reserva un espacio de memoria para una variable de tipo  Envio de manera dinamica y le asigna a los campos los atributos recibidos
 *  \param idProducto int identificador del producto a incorporar;
 *  \param nombre char* nombre a incoporar
 *  \param idCamion int identificador del camion a incorporar
 *  \param zonaStr char* zona de destino del producto a incorporar
 *  \param horasTrabajada int horas trabajadas por el empleado
 *  \param  sueldo int salario devengado por el empleado
 *  \return h* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
Envio* envio_newParametrosBin( int idProducto, char* nombreStr, int idCamion, char* zonaStr, float kilometros, int tipo, float costo)
{
			Envio* this = NULL;

			this = envio_new();

			if(this != NULL && idProducto >=0  && nombreStr != NULL && idCamion>= 0 && zonaStr!= NULL && kilometros>= 0 && tipo >= 0 && costo>= 0)
						{
							if(	envio_setIdProducto( this, idProducto) == -1 ||
								envio_setNombre( this, nombreStr) == -1 ||
								envio_setIdCamion(this, idCamion)== -1 ||
								envio_setZona( this, zonaStr) == -1 ||
								envio_setKilometrosRecorridos( this, kilometros)== -1||
								envio_setTipoDeEntrega( this,  tipo) == -1||
								envio_setCostoDelEnvio(this, costo)==-1)
								{
									envio_delete(this);
									this = NULL;
								}
						}

			return this;
}
/** \brief Reserva un espacio de memoria para una variable de tipo  Empleado de manera dinamica y le asigna a los campos los atributos recibidos
 *  \param idProductoStr char* identificador  del producto a incorporar;
 *  \param nombreStr char*  nombre a incoporar
 *  \param idCamionStr char* identificador del camion a incorporar
 *  \param zonaStr char* zona de destino del producto a incorporar;
 *  \param horasTrabajadasStr char* horas trabajadas por el empleado
 *  \param  sueldoStr char* salario devengado por el empleado
 *  \return h* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */

Envio* envio_newParametros(char* idProductoStr,char* nombreStr, char* idCamionStr, char* zonaStr, char* kilometrosStr, char* tipo, char* costoStr)
{
		Envio* this = NULL;

		this = envio_new();

		if(this != NULL && idProductoStr != NULL && nombreStr != NULL && idCamionStr != NULL && zonaStr != NULL && kilometrosStr != NULL && tipo != NULL && costoStr != NULL)
				{
						if( envio_setIdProductoTxt(this, idProductoStr) == -1 ||
							envio_setNombre( this, nombreStr) == -1 ||
							envio_setIdCamionTxt( this, idCamionStr)||
							envio_setZona( this, zonaStr) == -1 ||
							envio_setKilometrosRecorridosTxt( this, kilometrosStr)== -1||
							envio_setTipoDeEntregaTxT(this,tipo) == -1||
							envio_setCostoDeEnvioTxt( this, costoStr))
							{
								envio_delete(this);
								this = NULL;
							}
					}

		return this;

}

/** \brief libera un espacio de memoria de un elemento de tipo  Empleado creado de manera dinamica
 *  \param this Employee* puntero al elemento a ser eliminado
 *  \return h* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */


void envio_delete(Envio* this )
{
	if(this != NULL)
	{
		free(this);
	}
}

/*
 *brief Modifica el campo id de un elemento de la lista de empleados
 *
 * \param this Envio* Puntero a la lista de envios
 * \param int idProducto valor del  nuevo id del producto
 * \return int Retorna  (-1) Error: si el puntero al elemento lista es NULL o si el atributo recibido es NULL
                        ( 0) Si funciono correctamente
 */
int envio_setIdProducto(Envio* this,int idProducto)
{
	int retorno = -1;
	if(this != NULL && idProducto >= 0)
	{
		retorno = 0;
		this->idProducto = idProducto;
	}
	return retorno;
}
/*
 *brief Modifica el campo id Producto de un elemento de la lista de envios
 *
 * \param this Envio* Puntero a la lista de envios
 * \param char idProducto* Puntero al nuevo id del producto
 * \return int Retorna  (-1) Error: si el puntero al elemento lista es NULL o si el atributo recibido es NULL
                        ( 0) Si funciono correctamente
 */
int envio_setIdProductoTxt(Envio* this,char* idProductoStr)
{
		int retorno = -1;
		int auxiliarId;
		if(this != NULL && idProductoStr != NULL)
		{
			if(esNumerica(idProductoStr,strnlen(idProductoStr,ID_LEN))==1)
			{
				if((auxiliarId = atoi(idProductoStr))>=0)
				{
				this->idProducto = auxiliarId;
				retorno = 0;
				}
			}
		}
		return retorno;

}
/** \brief Permite leer el id del producto asignado a un elemento
 **\param this Envio* Puntero a la lista de envios
 * \param idProducto int* Puntero al id del producto a ser cargado
 * \return void* Retorna    (-1) Error: si el puntero al elemento lista es NULL o si  el puntero a id es NULL
                            ( 0) Si funciono correctamente
 */
int envio_getIdProducto(Envio* this,int* idProducto)
{
	int retorno = -1;
		if(this != NULL && idProducto!= NULL)
		{
			retorno = 0;
			*idProducto = this->idProducto;
		}
		return retorno;
}

/** \brief Permite leer el id del producto asignado a un elemento
 *  \param this Envio* Puntero a la lista de envios
 * \param id char* Puntero al id a ser cargado
 * \return void* Retorna    (-1) Error: si el puntero al elemento lista es NULL o si  el puntero a id es NULL
                            ( 0) Si funciono correctamente
 */
int envio_getIdProductoTxt(Envio* this,char* idProductoStr)
{
	int retorno = -1;
		if(this != NULL && idProductoStr != NULL)
		{
			retorno = 0;
			sprintf(idProductoStr,"%d",this->idProducto);
		}
		return retorno;
}
/*
 *brief Modifica  el campo nombre del producto de un elemento de la lista de envios
 *
 * \param this Envio* Puntero a la lista de envios
 * \param nombre char* Puntero al nuevo nombre del producto
 * \return int Retorna  (-1) Error: si el puntero al elemento lista es NULL o si el atributo recibido es NULL
                        ( 0) Si funciono correctamente
 */
int envio_setNombre(Envio* this,char* nombre)
{
	int retorno = -1;
		if(this != NULL && nombre != NULL)
		{
			if(isValidNombre(nombre,NOMBRE_LEN))
			{
				retorno = 0;
				strncpy(this->nombre,nombre,NOMBRE_LEN);
			}
		}
		return retorno;

}

/** \brief Permite leer el nombre del producto asignado a un elemento
 * \param  this Envio* Puntero a la lista de envios
 * \param nombre char* Puntero al nombre de producto a cargarse
 * \return void* Retorna    (-1) Error: si el puntero al elemento lista es NULL o si el  puntero al atributo recibido es NULL
                            ( 0) Si funciono correctamente
 */
int envio_getNombre(Envio* this,char* nombre)
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
 *brief Modifica el campo id de camion de un elemento de la lista de envios
 * \param this Envio* Puntero a la lista de envios
 * \param int idCamion valor del  nuevo id del camion
 * \return int Retorna  (-1) Error: si el puntero al elemento lista es NULL o si el atributo recibido es NULL
                        ( 0) Si funciono correctamente
 */
int envio_setIdCamion(Envio* this,int IdCamion)
{
	int retorno = -1;
	if(this != NULL && IdCamion >= 0)
	{
		retorno = 0;
		this->idCamion = IdCamion;
	}
	return retorno;
}
/*
 *brief Modifica el campo idCamion  de un elemento de la lista de envios
 *
 * \param this Envio* Puntero a la lista de envios
 * \param char idCamion* Puntero al nuevo id del camion
 * \return int Retorna  (-1) Error: si el puntero al elemento lista es NULL o si el atributo recibido es NULL
                        ( 0) Si funciono correctamente
 */
int envio_setIdCamionTxt(Envio* this,char* IdCamionStr)
{
		int retorno = -1;
		int auxiliarId;
		if(this != NULL && IdCamionStr != NULL)
		{
			if(esNumerica(IdCamionStr,strnlen(IdCamionStr,ID_LEN))==1)
			{
				if((auxiliarId = atoi(IdCamionStr))>=0)
				{
				this->idCamion = auxiliarId;
				retorno = 0;
				}
			}
		}
		return retorno;

}
/** \brief Permite leer el id del camion asignado a un elemento
 **\param this Envio* Puntero a la lista de envios
 * \param idCamion int* Puntero al id del camion a ser cargado
 * \return void* Retorna    (-1) Error: si el puntero al elemento lista es NULL o si  el puntero a id es NULL
                            ( 0) Si funciono correctamente
 */
int envio_getIdCamion(Envio* this,int* idCamion)
{
	int retorno = -1;
		if(this != NULL && idCamion != NULL)
		{
			retorno = 0;
			*idCamion = this->idCamion;
		}
		return retorno;
}

/** \brief Permite leer el id del camion asignado a un elemento
 *  \param this Envio* Puntero a la lista de envios
 * \param idCamion char* Puntero al id del camion a ser cargado
 * \return void* Retorna    (-1) Error: si el puntero al elemento lista es NULL o si  el puntero a id es NULL
                            ( 0) Si funciono correctamente
 */
int envio_getIdCamionTxt(Envio* this,char* idCamionStr)
{
	int retorno = -1;
		if(this != NULL && idCamionStr!= NULL)
		{
			retorno = 0;
			sprintf(idCamionStr,"%d", this->idCamion );
		}
		return retorno;
}





/*
 *brief Modifica  el campo zona de destino del producto de un elemento de la lista de envios
 *
 * \param this Envio* Puntero a la lista de envios
 * \param zonaStr char* Puntero a la zona de destino del producto
 * \return int Retorna  (-1) Error: si el puntero al elemento lista es NULL o si el atributo recibido es NULL
                        ( 0) Si funciono correctamente
 */
int envio_setZona(Envio* this,char* zonaStr)
{
		int retorno = -1;

		if(this != NULL && zonaStr!= NULL)
		{
			if(isValidZona( zonaStr,strnlen(zonaStr, ZONA_LEN)))
			{
				retorno = 0;
				strncpy(this->zona , zonaStr, ZONA_LEN);
			}
		}
		return retorno;

}

/** \brief Permite leer la zona de destino del producto asignado a un elemento
 * \param  this Envio* Puntero a la lista de envios
 * \param zonaStr char* Puntero a la zona de destino  del producto a cargarse
 * \return void* Retorna    (-1) Error: si el puntero al elemento lista es NULL o si el  puntero al atributo recibido es NULL
                            ( 0) Si funciono correctamente
 */
int envio_getZona(Envio* this,char* zonaStr)
{
	int retorno = -1;
		if(this != NULL && zonaStr != NULL)
		{
			retorno = 0;

			strncpy(zonaStr,this->zona ,ZONA_LEN);
		}
		return retorno;
}



/*
 *brief Modifica  el campo de kilometros recorridos de un elemento de la lista de envios
 * \param this Envios* Puntero a la lista de envios
 * \param kilometros float la cantidad de kilometros recorridos
 * \return int Retorna  (-1) Error: si el puntero al elemento lista es NULL o si el atributo recibido es menor a 0
                        ( 0) Si funciono correctamente
 */



int envio_setKilometrosRecorridos(Envio* this,float kilometros)
{
	int retorno = -1;

	if(this != NULL && kilometros >= 0)
	{
		retorno = 0;
		this->kilometros = kilometros;
	}
	return retorno;
}
/*
 *brief Modifica  el campo kilometros reocorridos de un elemento de la lista de envios
 * \param this Envios* Puntero a la lista de envios
 * \param kilometros char*  puntero  a  los kilometros recorridos
 * \return int Retorna  (-1) Error: si el puntero al elemento lista es NULL o si el atributo recibido es menor a 0
                        ( 0) Si funciono correctamente
 */

int envio_setKilometrosRecorridosTxt(Envio* this,char*kilometrosStr)
{
	int retorno = -1;
	int auxiliarKm;

	if(this != NULL && kilometrosStr!= NULL)
	{
		if(esFlotante(kilometrosStr)==1)
		{
			if((auxiliarKm= atoi(kilometrosStr))>=0)
			{
				this->kilometros = auxiliarKm;
				retorno = 0;
			}
		}
	}
	return retorno;
}


/** \brief Permite leer la cantidad de KilometrosRecorridos asignadas a un elemento
 * \param this Envio* Puntero a un elemento de la lista de envio
 * \param kilometros float* Puntero a los kilometros recorridos  a ser cargado
 * \return void* Retorna    (-1) Error: si el puntero al elemento lista es NULL o si el puntero al atributo recibido es NULL
                            ( 0) Si funciono correctamente
 */

int envio_getKilometrosRecorridos(Envio* this,float* kilometros)
{
	int retorno = -1;
	if(this != NULL && kilometros != NULL)
	{
		 retorno = 0;
		* kilometros = this->kilometros;
	}
	return retorno;
}

/** \brief Permite leer la cantidad de KilometrosRecorridos asignadas a un elemento
 * \param this Envio* Puntero a un elemento de la lista de envio
 * \param kilometros char* Puntero de kilometros recorridos  a ser cargado
 * \return void* Retorna    (-1) Error: si el puntero al elemento lista es NULL o si el puntero al atributo recibido es NULL
                            ( 0) Si funciono correctamente
 */


int envio_getKilometrosRecorridosTxt(Envio* this,char* kilometrosStr)
{

	int retorno = -1;
			if(this != NULL && kilometrosStr != NULL)
			{
				retorno = 0;
				sprintf(kilometrosStr,"%f",this->kilometros);
			}
			return retorno;

}

/*
 *brief Modifica  el campo tipo de entrega de un elemento de la lista de envios
 * \param this Envio* Puntero a la lista de envios
 * \param tipo int valor correspondiente al tipo de entrega elegido
 * \return int Retorna  (-1) Error: si el puntero al elemento lista es NULL o si el atributo recibido es NULL
                        ( 0) Si funciono correctamente
 */

int envio_setTipoDeEntrega(Envio* this, int tipo)
{
	int retorno = -1;

		if(this != NULL && tipo >= 0 && tipo < 3)
			{
				retorno = 0;
				this->tipo = tipo;
			}

		return retorno;
}
/*
 *brief Modifica  el campo tipo de entrega de un elemento de la lista de envios
 * \param this Envio* Puntero a la lista de envios
 * \param tipo char* al tipo de entrega
 * \return int Retorna  (-1) Error: si el puntero al elemento lista es NULL o si el atributo recibido es NULL
                        ( 0) Si funciono correctamente
 */

int envio_setTipoDeEntregaTxT(Envio* this,char* tipo)
{
	{
		int retorno = -1;
		int auxiliarTipo;

		if(this != NULL && tipo != NULL)
			{

				if(esNumerica(tipo,TIPO_LEN) == 1)
				{

					if((auxiliarTipo = atoi (tipo))>= 0)
					{
						this->tipo = auxiliarTipo;
						retorno = 0;
					}

				}

			}

		return retorno;
	}
}

/** \brief Permite leer el tipo de entrega asignada a un elemento
 * \param this Envio* Puntero a un elemento de la lista de envios
 * \param tipo  int* Puntero a la tipo de entrega  a ser cargada
 * \return void* Retorna    (-1) Error: si el puntero al elemento lista es NULL o si puntero al atributo es NULL
                            ( 0) Si funciono correctamente
 */

int envio_getTipoDeEntrega(Envio* this,int* tipo)
{
		int retorno = -1;
		if(this != NULL && tipo != NULL)
		{
			retorno = 0;
			*tipo = this->tipo;
		}
		return retorno;

}


/** \brief Permite leer el tipo de entrega asignada a un elemento
 * \param this Envio* Puntero a un elemento de la lista de envios
 * \param tipo char* Puntero del tipo de entrega  a ser cargado
 * \return void* Retorna    (-1) Error: si el puntero al elemento lista es NULL o si el puntero al atributo recibido es NULL
                            ( 0) Si funciono correctamente
 */

int envio_getTipoDeEntregaTxt(Envio* this, char* tipo)
{

	int retorno = -1;
			if(this != NULL && tipo != NULL)
			{
				retorno = 0;
				sprintf(tipo,"%d",this->tipo);
			}
			return retorno;

}



/*
 *brief Modifica  el campo de costo de envio de un elemento de la lista de envios
 * \param this Envios* Puntero a un elemento de  la lista de envios
 * \param costo float la valor del costo de envio
 * \return int Retorna  (-1) Error: si el puntero al elemento lista es NULL o si el atributo recibido es menor a 0
                        ( 0) Si funciono correctamente
 */

int envio_setCostoDelEnvio(Envio* this,float costo)
{
	int retorno = -1;

	if(this != NULL && costo >= 0)
	{
		retorno = 0;
		this->costo = costo;
	}
	return retorno;
}
/*
 *brief Modifica  el campo de costo de un elemento de la lista de envios
 * \param this Envios* Puntero a un elemento de la lista de envios
 * \param costo char*  puntero  correspondiente al valor  del envio
 * \return int Retorna  (-1) Error: si el puntero al elemento lista es NULL o si el atributo recibido es menor a 0
                        ( 0) Si funciono correctamente
 */

int envio_setCostoDeEnvioTxt(Envio* this,char*costoStr)
{
	int retorno = -1;
	int auxiliarCosto;

	if(this != NULL && costoStr!= NULL)
	{
		if(esFlotante(costoStr)==1)
		{
			if((auxiliarCosto= atoi(costoStr))>=0)
			{
				this->costo = auxiliarCosto;
				retorno = 0;
			}
		}
	}
	return retorno;
}


/** \brief Permite leer en costo de envio asignado a un elemento
 * \param this Envio* Puntero a un elemento de la lista de envio
 * \param costo float* Puntero a los costos de envios causados  a ser cargado
 * \return void* Retorna    (-1) Error: si el puntero al elemento lista es NULL o si el puntero al atributo recibido es NULL
                            ( 0) Si funciono correctamente
 */

int envio_getCostoDeEnvios(Envio* this,float* costo)
{
	int retorno = -1;
	if(this != NULL && costo != NULL)
	{
		 retorno = 0;
		* costo = this->costo;
	}
	return retorno;
}

/** \brief Permite leer el costo de envio asignado a un elemento
 * \param this Envio* Puntero a un elemento de la lista de envio
 * \param costo char* Puntero costo causado por el envio  a ser cargado
 * \return void* Retorna    (-1) Error: si el puntero al elemento lista es NULL o si el puntero al atributo recibido es NULL
                            ( 0) Si funciono correctamente
 */


int envio_getCostoDeEnvioTxt(Envio* this,char* costoStr)
{

	int retorno = -1;
			if(this != NULL && costoStr != NULL)
			{
				retorno = 0;
				sprintf(costoStr,"%f",this->costo);
			}
			return retorno;

}



int lecturaEnConjuntoDeAtributos(Envio* this, int* idProducto, char* nombre, int* idCamion, char* zona, float* kilometros, int* tipo, float* costo)
{
	int retorno = -1;
	if((envio_getIdProducto( this, idProducto)==0)&&
		 (envio_getNombre( this, nombre)==0)&&
		 (envio_getIdCamion( this, idCamion)==0)&&
		 (envio_getZona( this, zona)==0)&&
		 (envio_getKilometrosRecorridos( this,  kilometros)==0)&&
		 (envio_getTipoDeEntrega( this, tipo)==0) &&
		 (envio_getCostoDeEnvios( this, costo)==0))
		{
			retorno= 0;
		}
	return retorno;
}


/* brief permite obtener el costo total del envio
* \param pElement puntero al elemento de la lista de envios
* \return void* Retorna    (-1) Error: si el puntero al elemento lista es NULL o si el puntero al atributo recibido es NULL
                            ( 0) Si funciono correctamente
 */
int envio_calcularCostoDeEnvio(void* pElement)
{
	int retorno= -1;
	Envio* pEnvio;
	float precioPorKilometro;
	float auxiliarKilometros;
	float costoFijo;
	float costoTotal;


	if( pElement!= NULL)
	{
		pEnvio= (Envio*) pElement;
		if((envio_DeterminarCostoFijo(pElement, &costoFijo))==0) //con el tipo del elemento veo el costo corresṕondiente
		{
			if((envio_getKilometrosRecorridos( pElement, &auxiliarKilometros))==0) // obtengo los kilometros
			{
				if(auxiliarKilometros < 50)
				{
					precioPorKilometro= 150;
				}else
				{
					precioPorKilometro= 100;
				}

				costoTotal= (auxiliarKilometros *precioPorKilometro)+ costoFijo;
				if(envio_setCostoDelEnvio(pEnvio, costoTotal)==0)
				{
					retorno = 0 ;
				}
			}


		}

	}
	return retorno;
}



int envio_DeterminarCostoFijo(Envio* pElement, float* costoFijo)
{
	int auxiliarTipo;
	int retorno= -1;

	if(pElement!=NULL && costoFijo!= NULL)
	{
		if((envio_getTipoDeEntrega(pElement, &auxiliarTipo))==0)
		{
			retorno=0;
			switch(auxiliarTipo)
			{
				case 0:
					*costoFijo= 350;
					break;

				case 1:
					*costoFijo= 420;
					 break;
				case 2:
					*costoFijo= 275;
					 break;
			}

		}
	}
return retorno;
}

void envio_ImprimirUnElemento(Envio* pElement)
{


		printf( "%d \t \t  %s \t\t\t %d \t \t %s \t\t\t %.0f \t\t\t %s \t\t\t\t  %.0f \n", pElement->idProducto,pElement-> nombre, pElement->idCamion, pElement->zona, pElement->kilometros, TXT_TIPOS[pElement->tipo],pElement-> costo);


}


void envio_ImprimirEnvios(LinkedList* this)
{
	int index;
	Envio* pElement;

	if(this!= NULL)
	{
		printf("\nId Producto  \tNombre Del producto \t Id Del Camion \t\t Zona De Destino \t  Km Recorridos \t  Tipo de Entrega \t Costo de Envio \n");

		for(index=0; index <ll_len(this); index++)
		{

		  if((pElement = (Envio*) ll_get(this, index))!=NULL)
        	   {

			      envio_ImprimirUnElemento( pElement);

        	   }
		}
	}
}

/*******************************************************/
int envio_EsZona(void* pElement,char* zonaDeseada)
{
	int retorno= 0;
	Envio* pElemento= (Envio*) pElement;
	char zona [ZONA_LEN];


	if(( envio_getZona(pElemento,zona))==0)
	{
		if((strncmp(zona, zonaDeseada, ZONA_LEN ))==0)
		 {
			 retorno= 1;
		 }
	}
	return retorno;
}




int envio_ImprimirListaDeZonas(LinkedList* this)
{
	int retorno= -1;
	int i;
	Envio* pElemento = NULL;
	char zonaUno [ZONA_LEN];
	LinkedList* listaDeZonas =ll_newLinkedList();

	if(listaDeZonas!= NULL)
	{ retorno=0;
		for(i=0; i<ll_len(this)-1;i++)
		{
				if((pElemento=ll_get( this,  i))!=NULL)
				{
					if(envio_getZona(pElemento, zonaUno)==0 )
					{
							if(i==0||((BuscarZonaIncluidaEnLista( zonaUno, listaDeZonas))!=0))
								{
									ll_add(listaDeZonas,  pElemento);
								 printf("\n%s\n", zonaUno);
								}

							else
							{
								continue;
							}
					}


				}
		}
	}
	return retorno;
}

int BuscarZonaIncluidaEnLista( char* zona, LinkedList* this)
{
	int retorno= -1;
	int i;

	Envio* pElement=NULL;
	char zonaUno [ZONA_LEN];

	if(zona != NULL && this!= NULL)
	{
		for(i=0; i<ll_len(this);i++)
			{
			  if((pElement=ll_get( this,  i))!=NULL)
				{
				  if(envio_getZona(pElement, zonaUno)==0 )
				  {

					  if((strncmp(zonaUno, zona, ZONA_LEN))==0)
					  {
						  retorno= 0;
						  break;
					  }
				  }
				}
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
static int isValidNombre(char* cadena,int longitud)
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

/**
 * \brief Verifica si la cadena ingresada es una descripcion valida
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 *
 */
static int isValidZona(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if(cadena[i] != '.' &&  ( cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ) && (cadena[i] < '0' || cadena[i] > '9' ) )
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}


/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (vardadero) si la cadena es flotante y 0 (falso) si no lo es
 *
 */
static int esFlotante(char* cadena)
{
	int i=0;
	int retorno = 1;
	int contadorPuntos=0;

	if(cadena != NULL && strlen(cadena) > 0)
	{
		for(i=0 ; cadena[i] != '\0'; i++)
		{
			if(i==0 && (cadena[i] == '-' || cadena[i] == '+'))
			{
				continue;
			}
			if(cadena[i] < '0' || cadena[i] > '9' )
			{
				if(cadena[i] == '.' && contadorPuntos == 0)
				{
					contadorPuntos++;
				}
				else
				{
					retorno = 0;
					break;
				}
			}
		}
	}
	return retorno;
}

