/*
Ejercicio 4.
Tomar el ejercicio 3 y realizar una funcion que reciba el
array, un indice, y le permita al usuario cargar los datos
 en el item de la posicion especificada por el indice.

 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Producto.h"

#define PROD_LEN	100

int main(void) {

	int indice=0;
	Producto productos[PROD_LEN];

	prod_initArray(productos,PROD_LEN);

	if(prod_cargarProducto(productos,PROD_LEN,indice)==1)
	{
		printf("carga exitosa en posicion %d",indice);
	}

	return EXIT_SUCCESS;
}
