/*
 * Informes.h
 *
 *  Created on: May 5, 2020
 *      Author: Mauro
 */

#ifndef INFORMES_H_
#define INFORMES_H_

int info_imprimirPublicacionesContratadasConElIdCliente(Publicacion* arrayPublicaciones,int limitePublicaciones,Cliente* arrayClientes,int limiteClientes,int* auxiliarId);
int info_imprimirContratacionesConImporte(Publicacion* arrayPublicaciones,int limitePublicaciones,Cliente* arrayPantallas,int limitePantallas,char* auxiliarCuit);
int info_imprimirContratacionesConImportePorCliente(Publicacion* arrayPublicaciones,int limitePublicaciones,Cliente* arrayPantallas,int limitePantallas);
int info_calcularDeudaCliente(Publicacion* arrayPublicaciones,int limitePublicaciones,Cliente* arrayPantallas,int limitePantallas,char* auxiliarCuit, float* deuda);
#endif /* INFORMES_H_ */
