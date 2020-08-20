/*
 * UTN.h
 *
 *  Created on: 20 abr. 2020
 *      Author: yusmelis
 */


#ifndef UTN_H_
#define UTN_H_


unsigned int VerificarCaracter(void);
int Factorial (int n);
int utn_GetNumero ( int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
static int GetInt( int* pResultado);
static int esNumerica (char* cadena, int limite);
static int myGets(char*cadena, int longitud);
