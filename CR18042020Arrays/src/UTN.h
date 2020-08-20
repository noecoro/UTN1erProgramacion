/*
 * UTN.h
 *
 *  Created on: 18 abr. 2020
 *      Author: yusmelis
 */

#ifndef UTN_H_
#define UTN_H_

void testArray(int parametroArray[],int cantidad);


/**
 *
 *
 *
 * */
void InicializarArray(int parametroArray[],int cantidad, int valorInicio);

/**
 *
 *
 * */
void MostarArray(int parametroArray[],int cantidad);
int SacarLaSuma(int parametroArray[],int cantidad, int valorInicio);
int SacarCantidadDeNumeros(int parametroArray[],int cantidad, int valorInicio);
float SacarPromedio(int parametroArray[],int cantidad, int valorInicio);
int SacarIndiceLibre(int parametroArray[],int cantidad, int valorInicio);

#endif /* UTN_H_ */
