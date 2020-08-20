/*
 * utn.h
 *
 *  Created on: Apr 6, 2020
 *      Author: Mauro
 */

#ifndef UTN_H_
#define UTN_H_

int utn_getInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getfloat(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);


#endif /* UTN_H_ */
