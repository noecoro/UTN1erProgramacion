/*
 ============================================================================
 Name        : CLase19Parser.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

un parser se encarga de analizar una cadena de caracteres conforme a
ciertas reglas. Generalmente un parser posee un input de datos (binarios o texto) el cual
utiliza para construir una estructura de dato

Por ejemplo, si se quiere representar una persona, y la regla nos dice que los datos de nombre,
 apellido y edad están separados por un carácter especial “,” (coma) y que cada persona estará separada de la siguiente por medio
de otro carácter especial “\n” (enter)

Juan,Perez,33\nJose,Gonzales,45\nCarlos,Gomez,21\n


La cual puede encontrarse escrita en un archivo o provenir de otro medio. Sin embargo, si
debemos representar a la entidad “Persona” en nuestro programa, deberemos definir una
estructura de datos como la siguiente:

	struct S_Persona
		{
		char nombre[32];
		char apellido[32];
		int edad;
		};
	typedef struct S_Persona Persona;

	Persona listaPersonas[3];

Como se observa, nuestro programa tendrá definido en memoria un array de estructuras
“Persona” pero para poder cargar los campos de cada uno de los ítems de este array,
necesitaremos leer el archivo descripto anteriormente, y mediante algún algoritmo, cargar los
campos de las variables “Persona” con el contenido de dicho archivo. Es aquí cuando el proceso
de parsing permite que esto se lleve a cabo.

Para nuestro ejemplo, un parser no será mas que una función, la cual abre un archivo y lo lee
(obtenemos de esta forma el input del parser), y llena un array pasado como parámetro con la
información leída, como se indica en el diagrama anterior.

Mediante la función fscanf, podremos leer de un archivo una cadena de caracteres mientras se
cumpla una regla descripta, que deberá ser pasada a la función como parámetro.
La función analizará la cadena y continuará leyendo mientras se cumpla la regla que se le
pasó. En dicha regla podremos incluir indicaciones, para que la función almacene los datos
encontrados en una variable también pasada como argumento.


1,Juan,Perez,33\n2,Jose,Gonzales,45\n3,Carlos,Gomez,21\n


De esta manera determinamos la regla: "%d,%s,%s,%d\n".Sin embargo, esta regla no
funcionará, ya que “%s” implica una palabra, cualquier conjunto de caracteres menos el
espacio. Esto quiere decir que la coma “,” está incluida dentro del conjunto que se expresa con
“%s”, por lo tanto la función fscanf nos devolverá un 2, solo detectará dos campos, ya que
interpretará el contenido de la siguiente manera

Para solucionar este problema, deberíamos indicar un conjunto de letras en donde estén todas
las letras, menos la coma “,” ya que ésta es la que determinará que el campo termina al
encontrar dicho carácter. Tendríamos el mismo problema con los campos numéricos, pero el
“%d” representa el conjunto de caracteres del 0 al 9, por lo que la coma no esta allí.

Para indicar un conjunto de letras, podemos utilizar corchetes, indicando dentro un rango de
caracteres, por ejemplo: “%[a-z]” o “%[A-Z]”.
También podemos expresar un conjunto negado, es decir “cualquier carácter menos los que
están en este conjunto”, para ello indicamos el conjunto con un “^” delante, por ejemplo: “%
[^,]” indica “cualquier carácter menos la coma”.


------- Creación de estructuras de datos
Para que nuestro parser esté completo, deberemos cambiar el código anterior, para que en vez
de solamente imprimir los datos almacenados en las variables (var1, var2, var3, y var4) por
medio de la función printf, se almacene dicha información en campos de una estructura
perteneciente a un array.
Supongamos que definimos la estructura Persona y un array de personas en nuestro
programa. La idea de la función parseData es que le pasemos el nombre de un archivo, y el
array sin inicializar, y nos devuelva el array cargado:


 <<<<1.4 Parser con creación dinámica de datos



 En el ejemplo anterior trabajamos con un array estático de estructuras, el mismo tenía un
tamaño definido haciendo que debamos ocupar mucha memoria en variables que quizá no
usaremos. Al trabajar con memoria dinámica, este problema está resulto, modificaremos el
código anterior suponiendo que existe una biblioteca “Persona.c” y “Persona.h” la cual posee
funciones para crear en forma dinámica una estructura del tipo Persona.
Las funciones que suponemos que existen son:
Persona* per_newPersona(void);
int per_setId(Persona* p,int id);
int per_setEdad(Persona* p,int edad);
int per_setNombre(Persona* p,char* nombre);
int per_setApellido(Persona* p,char* apellido);

 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	FILE *pFile;
	int r;
	int a,b,c,d;


	pFile = fopen("data.csv","r");
	if(pFile == NULL)
	{
		printf("El archivo no existe");
		exit(EXIT_FAILURE);
	}

	do
	{
		r = fscanf(pFile,"%d,%d,%d,%d\n",&a,&b,&c,&d);

		if(r==4)
		{
		printf("Lei %d %d %d %d\n",a,b,c,d);
		}
		else
			break;

	}while(!feof(pFile));

	fclose(pFile);
	exit(EXIT_SUCCESS);
	return 0;

	/*
	 * La función recibe como primer argumento el puntero al archivo (pFile), luego recibe la regla a
aplicar sobre los datos leídos, y luego recibe una cantidad indefinida de punteros a las
variables (a,b,c y d en este caso) en donde se almacenarán los números encontrados según lo
especificado en la regla pasada como parámetro.La función retornará cuántas variables pudo
cargar, (en este ejemplo 4 si pudo encontrar en la cadena leída todo lo descripto en la regla).
	 **/

char nombre[50];
char apellido[50];
int id,edad;
do
{
	r = fscanf(pFile,"%d,%[^,],%[^,],%d\n",&id,nombre,apellido,&edad);
	if(r==4){
		printf("Lei %d %s %s %d\n",id,nombre,apellido,edad);
	}
}while();



struct S_Persona
{
	int id;
	char nombre[32];
	char apellido[32];
	int edad;
};



typedef struct S_Persona Persona;
int parseData(char* fileName,Persona* arrayPersonas, int len);

int main(void)
{
	Persona personas[8];
	int r,i;
	r = parseData("data.csv",personas,8);
	for(i=0; i<r; i++)
		printf("id:%d nombre:%s apellido:%s edad:%d\n", personas[i].id,
													personas[i].nombre,
													personas[i].apellido,
													personas[i].edad);
	exit(EXIT_SUCCESS);
}




}




int parseData(char* fileName,Persona* arrayPersonas, int len)
{
	FILE *pFile;
	int r,i=0;
	char var1[50],var3[50],var2[50],var4[50];

	pFile = fopen(fileName,"r");

	if(pFile == NULL)
	{
		return -1;
	}

	do
	{
		r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);
		if(r==4)
		{
			arrayPersonas[i].id = atoi(var1);
			strncpy(arrayPersonas[i].nombre,var2,sizeof(arrayPersonas[i].nombre));
			strncpy(arrayPersonas[i].apellido,var3,sizeof(arrayPersonas[i].apellido));
			arrayPersonas[i].edad = atoi(var4);
			i++;
		}

	else
	break;

	}while(!feof(pFile) && i<len);
	fclose(pFile);
	r




	int parseData(char* fileName,Persona* arrayPersonas[], int len)
	//Por último modificamos el bloque “if” y creamos las variables solo cuando podemos leer los
	//datos, y utilizamos las funciones descriptas para cargar los mismos.
	{
	r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);
	if(r==4)
	{
		Persona* pAux = per_newPersona();
		per_setId(pAux,atoi(var1));
		per_setNombre(pAux,var2);
		per_setApellido(pAux,var3);
		per_setEdad(pAux,atoi(var4));
		arrayPersonas[i] = pAux;
		i++;
	}

	}






			}
