/*
 * Producto.h
 *
 *  Created on: Apr 23, 2020
 *      Author:
 */


#ifndef CLIENTE_H_
#define CLIENTE_H_



#define NOMBRE_LEN 50
#define LASTNAME_LEN 50
#define CUIT_LEN 20



typedef struct
{
	char nombre[NOMBRE_LEN];
	char apellido[LASTNAME_LEN];
	char cuit;
	int isEmpty;
	int id;
}Cliente;

int cli_imprimir(Cliente* auxProducto);
int cli_inicializarArray(Cliente* array,int limite);
int cli_altaArray(Cliente* array,int limite, int indice, int* id);
int cli_getEmptyIndex(Cliente* array,int limite);
int cli_imprimirArray(Cliente* array,int limite);
int cli_buscarId(Cliente array[], int limite, int valorBuscado);
int cli_modificarArray(Cliente* array,int limite, int indice);
int cli_altaForzadaArray(Cliente* array,int limite, int indice, int* id,char* nombre,char* apellido, char cuit);

#endif /* CLIENTE_H_ */
