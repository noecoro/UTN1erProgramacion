/*
 ============================================================================
 Name        : JUN_2020_2DO_PARCIAL.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Envio.h"
#include "utn.h"


/****************************************************
    Menu:
     1. Cargar los datos de  envios desde el archivo deseado por el usuario (modo texto).
     2. Imprimir envios.
     3. Calcular costos.
     4. Generar archivo de costos para zona.
     5. Imprimir lista de zonas
     6. Salir

*****************************************************/



int main()
{
    int option = 0;


    LinkedList* listaEnvios = ll_newLinkedList();
    LinkedList* listaf=NULL;




    do{
		utn_getNumero(& option,"\n1-Cargar los datos de  envios desde el archivo deseado por el usuario (modo texto). \n2-Imprimir envios. \n3-Calcular costos.\n4-Generar archivo de costos para zona.\n5- Imprimir lista de zonas\n6-Salir","\nOpcion invalida",1,6,2);

        switch(option)
        {
           case 1:

        	    controller_loadFromText(  listaEnvios);
        	    break;


           case 2:

        	   envio_ImprimirEnvios(listaEnvios);

        	   break;

           case 3:

        	   if(( ll_map (listaEnvios, envio_calcularCostoDeEnvio))==0)
        	   {
        		   envio_ImprimirEnvios(listaEnvios);

        	   }
        	   break;

           case 4:


        	   if((listaf = controller_GenerarNuevoArchivoCostoPorZona( listaEnvios ))!=NULL)
        	   {
        		   printf (" Nuevo archivo generado con exito");
        	   }
        	   break;

           case 5:

        	   envio_ImprimirListaDeZonas(listaEnvios);
        	   break;
        }
    }while(option != 6);
    return 0;
}
