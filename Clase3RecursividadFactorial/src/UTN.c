/*
 * UTN.c
 *
 *  Created on: 20 abr. 2020
 *      Author: yusmelis
 */

/* Funcion usada para realizar el calculo de factorial.
Se ingresa un numero entero positivo y devuelve como resultado otro entero positivo
retorna el resultado del factorial
*/
//calculo del factorial

int Factorial (int n)
{
	int respuesta;
	if(n==1)
	{
		return 1;
	}
	respuesta= n * Factorial (n-1);
	return respuesta;
}



/* Funcion usada para verificar el ingreso de caracteres.
 * Chequea para que solo sean admitidas las letras S o N.
Se ingresa void y devuelve un entero sin signo
0 si se ingreso la N
1 si se ingreso la S

*/
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

