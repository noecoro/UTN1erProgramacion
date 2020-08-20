/*
 * Producto.h
 *
 *  Created on: Apr 23, 2020
 *      Author: Mauro
 */

#ifndef PACIENTE_H_
#define PACIENTE_H_

#define NOMBRE_LEN 50
#define LASTNAME_LEN 20

typedef struct
{
	char nombre[NOMBRE_LEN];
	char dni[LASTNAME_LEN];
	float altura;
	int isEmpty;
	int id;
}Cliente;

int cli_imprimir(Cliente* auxProducto);
int cli_inicializarArray(Cliente* array,int limite);
int cli_altaArray(Cliente* array,int limite, int indice, int* id);
int cli_getEmptyIndex(Cliente* array,int limite);
int cli_imprimirArray(Cliente* array,int limite);
int cli_buscarId(Cliente array[], int limite, int valorBuscado);
int cli_ordenarPorNombre(Cliente* array,int limite);
int cli_modificarArray(Cliente* array,int limite, int indice);
int cli_bajaArray(Cliente* array,int limite, int indice);

#endif /* PACIENTE_H_ */
