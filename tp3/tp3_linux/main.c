#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"
#include "parser.h"
/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
    int option = 0;
    int proximoId = 0;

    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
		utn_getNumero(& option,"1. Cargar los datos de los empleados desde el archivo data.csv (modo texto). \n2. Cargar los datos de los empleados desde el archivo data.csv (modo binario). \n3-Calcular costos.\n4-Generar archivo de costos para zona.\n5- Imprimir lista de zonas\n6-Salir","\nOpcion invalida",1,6,2);

        switch(option)
        {
            case 1:
                if(controller_loadFromText("data.csv",listaEmpleados, &proximoId)==0)
                		{ controller_ListEmployee(listaEmpleados);
                			printf("carga realizada con exito");
                		}
                 break;

            case 2:
            	if(controller_loadFromBinary("data.csv",listaEmpleados, &proximoId)==0)
            	{
            		controller_ListEmployee(listaEmpleados);
            	}

            	 break;
        }
    }while(option != 10);
    return 0;
}

