/*
 * Producto.c
 *
 *  Created on: Apr 23, 2020
 *      Author: ernesto
 */

pro

unsigned int VerificarCaracter(void)
{
	char letra;

	printf("\n Ingrese opcion... S/ N?");
	letra=toupper(getchar());
	while(letra!='S'&&letra!='N')
	{
		printf("ha ingresado una letra invalida");
		letra=toupper(getchar());
	}

	return (letra=='S');
}
