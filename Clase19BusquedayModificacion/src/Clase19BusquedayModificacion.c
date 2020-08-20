/*
 ============================================================================
 Name        : Clase19BusquedayModificacion.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

 cuando se necesita mover el indicador de posición a algún lugar en particular se pueden usar
 fseek y rewind

 con ftell se encuentra en lugar del indicador de posicion

----- rewind
	Esta función permite llevar el indicador de posición al comienzo del archivo. El prototipo es el
siguiente:
			void rewind (FILE* arch);

-------fseek

	Esta función permite desplazar el indicador de posición del archivo a la posición que se le
indique. El prototipo es:

	int fseek ( FILE *arch , long desplazamiento , int origen);

• arch: Puntero a la estructura FILE asociada con el archivo
• desplazamiento: Es la cantidad de bytes que se desplazará el indicador de posición a
partir de origen
•origen: Es una constante que determina el punto de referencia a partir del cuál se
realiza el desplazamiento.


 Los valores que se le pueden dar a origen figuran en la siguiente tabla. Dichos valores se
encuentran definidos en stdio.h:

 SEEK_SET A partir del comienzo del archivo
SEEK_CUR A partir de la posición actual del archivo
SEEK_END A partir de el final del archivo

 Valor retornado: Si la operación es exitosa devuelve cero , caso contrario retorna un valor
distinto de cero.
La función fseek mueve el indicador de posición del archivo desplazamiento bytes a partir de la
posición indicada por origen.

-------- ftell
	La función ftell me permite obtener la posición actual del indicador de posición. El prototipo es
el siguiente:
long ftell (FILE* arch );

	Donde arch es el puntero a la estructura FILE asociada al archivo.
Valor retornado: Si la operación es exitosa devuelve la cantidad de bytes que hay desde el
commienzo del archivo hasta el lugar en que se encuentra el indicador de posición del archivo ,
en caso contrario devuelve –1L (-1 como tipo long).


 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	fseek ( ptr , 0L , SEEK_SET ); // al comienzo mejor frewind
	fseek ( ptr , 0L , SEEK_END );// a l final
	fseek ( ptr , 20L , SEEK_SET );//Mueve el indicador de posición 20 bytes a partir del comienzo del archivo.
	fseek ( ptr , (long) (-1)*sizeof (struct x) , SEEK_CUR );
	/*Mueve el indicador de posición una estructura para atras a partir de la posición actual.
	Normalmente esta forma se utiliza cuando se estan editando datos del archivo. Al realizar una
	búsqueda se va leyendo cada uno de los datos del archivo por medio de fread, pero cuando
	encontramos el dato el indicador de posición del archivo esta en el dato siguiente al que
	queremos modificar , con lo cual al hacer fwrite para escribirlo se modificará otro dato. Por lo
	tanto antes de escribir se debe mover el indicador de posición una estructura para atrás.
	*/

	FILE *bin;
	long int cant;
	if ((bin=fopen("bin.dat","rb"))==NULL)
	{
	printf("No se pudo abrir el archivo");
	exit(1);
	}
	fseek (bin , 0L , SEEK_END ); //Se envía la posición al final del archivo
	cant=ftell (bin);
	printf("\nEl archivo tiene %ld bytes",cant);
	fclose(bin);
	getch();


	return 0;
}
