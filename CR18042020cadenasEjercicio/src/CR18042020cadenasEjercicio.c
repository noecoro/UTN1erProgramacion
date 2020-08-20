******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <string.h>
void strMayuscula(char cadena[]);//En windows usamos strupr
void strMinuscula(char cadena[]);//En windows usamos strlwr

int main()
{
    /*nombre: german ezequiel
    apellido: scarafilo
    apellidoYnombre: Scarafilo, German Ezequiel*/

    char apellido[20] = "sCARAfiLo";
    char nombre[20] = "germaN EZEquiel";
    char apellidoYnombre[100]="basura";

    int i;
    int cantidad;

    strcpy(apellidoYnombre, apellido);
    strcat(apellidoYnombre, ", ");
    strcat(apellidoYnombre, nombre);

    strMinuscula(apellidoYnombre);
     apellidoYnombre[0] = toupper(apellidoYnombre[0]);
    cantidad = strlen(apellidoYnombre);
    for(i=0; i<cantidad; i++)
    {
        if(apellidoYnombre[i] == ' ')
        {
             apellidoYnombre[i+1] = toupper(apellidoYnombre[i+1]);
        }
    }


    puts(apellidoYnombre);





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
