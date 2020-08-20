/*
 * Producto.c
 *
 *  Created on: Apr 23, 2020
 *      Author: ernesto
 */
#include "Producto.h"
#include <stdio.h>


int prod_cargarProducto(Producto* pArray,int limite,int indice)
{
	int retorno = -1;
	char auxNombre[50];
	char auxDescripcion[50];
	float auxPrecio;
	int i;
	if(pArray != NULL && limite>0 && indice<limite)
	{
		if(!utn_getNombre(auxNombre,50,"\nIngrese nombre: ","Error nombre",2))
		{
			if(!utn_getNombre(auxDescripcion,50,"\nIngrese Descripcion: ","Error descripcion",2))
			{
				if(!utn_getNumeroFlotante(&auxPrecio,"Ingrese Precio","Error precio",0.00,900.50,2))
				{
					strncpy(pArray[indice].nombre,auxNombre,50);
					strncpy(pArray[indice].descripcion,auxDescripcion,50);
					pArray[indice].precio=auxPrecio;
					pArray[indice].isEmpty=0;
					retorno = 0 ;
				}
			}
		}
	}
	return retorno;
}

int prod_cargarProductov2(Producto* pArray,int limite,int indice)
{
	int retorno = -1;
	Producto prodAux;
	int i;
	if(pArray != NULL && limite>0 && indice<limite)
	{
		if(!utn_getNombre(prodAux.nombre,50,"\nIngrese nombre: ","Error nombre",2))
		{
			if(!utn_getNombre(prodAux.descripcion,50,"\nIngrese Descripcion: ","Error descripcion",2))
			{
				if(!utn_getNumeroFlotante(&prodAux.precio,"Ingrese Precio","Error precio",0.00,900.50,2))
				{
					pArray[indice] = prodAux; // copia magica

					pArray[indice].isEmpty=0;
					retorno = 0 ;
				}
			}
		}
	}
	return retorno;
}


//int prod_initArray(Producto array[], int len)
int prod_initArray(Producto* array, int len)
{
	int ret=-1;
	if(array!=NULL && len>=0)
	{
		// iterar el array y por cada elemento
		// cargar el campo isEmpty = 1
		int i;
		for(i=0; i<len; i++)
		{
			//i : indice del array 0...99
			// array[i] es una variable Producto
			array[i].isEmpty=1;
		}
		ret=0;
	}
	return ret;
}









void prod_imprimirProducto(Producto prod)
{
	printf("%s %s Precio:%f\n",prod.nombre,
			                   prod.descripcion,
							   prod.precio);

}

void prod_imprimirProductoPorReferencia(Producto* pProd)
{
	printf("%s %s Precio:%f\n", pProd->nombre,
								pProd->descripcion,
								pProd->precio);

}
