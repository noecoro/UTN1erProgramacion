/*
 * cliente.h
 *
 *  Created on: 12 may. 2020
 *      Author: yusmelis
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_


#define NOMBRE_LEN 50
#define LASTNAME_LEN 50
#define CUIT_LEN 20
#define QWTY_CLIENTES 100
#define QWTY_PUBLICACIONES 1000

typedef struct
{
	char nombre[NOMBRE_LEN];
	char apellido[LASTNAME_LEN];
	char cuit[CUIT_LEN];
	int id;
	int isEmpty;

}Cliente;

int cli_inicializarArray(Cliente* pArray, int limite);
int cli_altaArray(Cliente* array, int limite, int i);
int cli_getEmptyIndex(Cliente* array,int limite);




#endif /* CLIENTE_H_ */
