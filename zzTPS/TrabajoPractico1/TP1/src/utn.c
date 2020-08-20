#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

static int esNumerica(char* cadena, int limite);
static int getInt(int* pResultado);
static int esFlotante(char* cadena);
static int getFloat(float* pResultado);
static int getString(char* cadena, int longitud);

/**
 * \brief 	Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
 * 			un máximo de 'longitud - 1' caracteres.
 * \param pResultado Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param longitud Define el tamaño de cadena
 * \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
 *
 */
static int getString(char* cadena, int longitud)
{
	int retorno=-1;
	char bufferString[4096]; // *****************************

	if(cadena != NULL && longitud > 0)
	{
		__fpurge(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= longitud)
			{
				strncpy(cadena,bufferString,longitud);
				retorno=0;
			}
		}
	}

	//bufferString [4096]
	//bufferString= "hola como estas/n /0"
	//X=15-1


	return retorno;
}

/**
 * \brief Obtien un numero entero
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 *
 */
static int getInt(int* pResultado)
{
    int retorno=-1;
    char bufferString[50];
    if(	pResultado != NULL &&
    	getString(bufferString,sizeof(bufferString)) == 0 &&
    	esNumerica(bufferString,sizeof(bufferString)))
	{
		retorno=0;
		*pResultado = atoi(bufferString) ;

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
 * \brief Solicita un numero al usuario, leuego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 *
 */
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int bufferInt;
	do
	{
		printf("%s",mensaje);
		if(	getInt(&bufferInt) == 0 &&
			bufferInt >= minimo &&
			bufferInt <= maximo)
		{
			retorno = 0;
			*pResultado = bufferInt;
			break;
		}
		printf("%s",mensajeError);
		reintentos--;
	}while(reintentos>=0);

	return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
 *
 */
static int getFloat(float* pResultado)
{
    int retorno=-1;
    char buffer[64];

    if(pResultado != NULL)
    {
    	if(getString(buffer,sizeof(buffer))==0 && esFlotante(buffer))
    	{
			*pResultado = atof(buffer);
			retorno = 0;
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

/**
 * \brief Solicita un numero flotante al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \return Retorna 0 si se obtuvo el numero flotante y -1 si no
 *
 */
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError,  int reintentos)
{
	float bufferFloat;
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getFloat(&bufferFloat) == 0)
		{
				*pResultado = bufferFloat;
				retorno = 0;
				break;

		}
		printf("%s",mensajeError);
	}
	return retorno;
}

/**
 * \brief realiza la adicion de dos operandores flotantes recibidos
 * \param recibe un operador flotante para realizar la operacion
 * \param recibe el segundo operador flotante para realizar la operacion
 * \return Retorna el resultado obtenido de la suma
 */



float utn_sumar(float ope1,float ope2)
{
	float resultado;
	resultado= ope1+ope2;
	return resultado;
}

/**
 * \brief realiza la sustraccion de dos operadores flotantes recibidos
 * \param recibe un operador flotante para realizar la operacion
 * \param recibe el segundo operador flotante para realizar la operacion
 * \return Retorna el resultado obtenido de la resta
 */

float utn_restar(float ope1,float ope2)
{
	float resultado;
	resultado= ope1-ope2;
	return resultado;
}
/**
 * \brief realiza el producto de dos operadores flotantes recibidos
 * \param recibe el primer operador flotante para realizar la operacion
 * \param recibe el segundo operador flotante para realizar la operacion
 * \return Retorna el resultado obtenido de la resta
 */
float utn_multiplicar(float ope1,float ope2)
{
	float resultado;
	resultado= ope1*ope2;
	return resultado;
}


/**
 * \brief escribe en la direccion de memoria recibida el resulrado de la division de dos operadoes si el denominador es distinto de cero
 * \param recibe el primer operador flotante como numerador para realizar la operacion
 * \param recibe el segundo operador flotante como denominador para realizar la operacion
 * \return Retorna 0 si pudo realizar la division con exito y -1 si no
 */
int utn_dividir(float* pResultado, float ope1,float ope2)
{
	int retorno=-1;

	if(pResultado!=NULL && ope2 !=0)
	{
		*pResultado= ope1/ope2;
		retorno=0;
	}
	return retorno;
}

/**
 * \brief realiza el calculo de factorial de un flotante positivo
 * \param recibe el numero positivo que se va a factorial
 * \return el resultado de dicho calculo
 */


float utn_factorial (float n)
{

	float respuesta;
	if(n>=0)
	{
		if(n==1)
		{
			return 1;
		}
		respuesta = n * utn_factorial (n-1);
		return respuesta;
	}
}


int ordenarArraysInt( int* pArray, int limite )
{
	int retorno=-1;
	int flagSwap;
	int contador=0;
	int i;
	int buffer;
	int nuevoLimite;

	if( pArray != NULL && limite >= 0 )
	{
		nuevoLimite=limite-1;
		do
		{
			flagSwap=0;
			for(i=0;i<nuevoLimite-1;i++)
			{
				if(pArray[i] < pArray [i+1])
				{
					flagSwap=1;
					buffer = pArray[i];
					pArray[i]= pArray [i+1];
					pArray [i+1]=buffer;
				}
			contador++;
			nuevoLimite--;
			}
		}while(flagSwap);
		retorno=contador;
	}
	return retorno;

}

