/*
 * utn.h
 *
 *  Created on: Apr 6, 2020
 *      Author: Mauro
 */

#ifndef UTN_H_
#define UTN_H_

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, int reintentos);
float utn_sumar(float ope1,float ope2);
float utn_restar(float ope1,float ope2);
float utn_multiplicar(float ope1,float ope2);
int utn_dividir(float* pResultado, float ope1,float ope2);
int utn_factorial (float n);
#endif /* UTN_H_ */
