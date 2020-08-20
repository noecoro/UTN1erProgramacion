/*
 ============================================================================
 Name        : cadenaDeCaracteres.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <string.h>
void strMayuscula(char cadena[]);//En windows usamos strupr
void strMinuscula(char cadena[]);//En windows usamos strlwr
/*
gets o fgets
puts

-string-
strlen
strcpy o strncpy
strcmp stricmp strcasecmp
strupr o strlwr
strcat

*/
int main()
{
   char cadena1[150] = "casamiento";
   char cadena2[15] = "DIVORCIO";


   int len;

   int comp;

  /* printf("Ingrese una cadena: ");
   __fpurge(stdin);
   //scanf("%s", cadena1);
   //gets(cadena1);
   fgets(cadena1,15,stdin);

   //int strlen(char*)

   len = strlen(cadena1);

   cadena1[len-1] = '\0';

   len = strlen(cadena1);

   printf("El largo: %d\n", len);*/

   //char* strcpy(char*, const char*);


   //strncpy(cadena2, cadena1, 5);


   //int strcmp(const char*, const char*);
   //retorno: 0, 1, -1

  /* comp = strcasecmp(cadena1, cadena2);


   printf("%d", comp);*/

   /*if(strcmp(cadena1,"hola")==0)
   {

   }*/

   //strcat(cadena1, cadena2);
  strMinuscula(cadena2);
  puts(cadena2);
puts(cadena1);
    return 0;
}

void strMayuscula(char cadena[])
{
    int i=0;
    while(cadena[i]!='\0')
    {
        cadena[i] = toupper(cadena[i]);
        i++;
    }
}
void strMinuscula(char cadena[])
{
    int i=0;
    while(cadena[i]!='\0')
    {
        cadena[i] = tolower(cadena[i]);
        i++;
    }
}
