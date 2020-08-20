#ifndef CONTRATACION_H_
#define CONTRATACION_H_

#define NOMBRE_LEN 50
#define RAZA_LEN 20

typedef struct
{
	char archivo[NOMBRE_LEN];
	char cuit[RAZA_LEN];
	//float altura;
	int isEmpty;
	int id;
	int idPantalla; // agregado
	int dias; // agregado
}Contratacion;

int cli_imprimir(Contratacion* auxProducto);
int cli_inicializarArray(Contratacion* array,int limite);
int cli_altaArray(Contratacion* array,int limite, int indice, int* id);
int cli_getEmptyIndex(Contratacion* array,int limite);
int cli_imprimirArray(Contratacion* array,int limite);
int cli_buscarId(Contratacion array[], int limite, int valorBuscado);
int cli_modificarArray(Contratacion* array,int limite, int indice);
int cli_bajaArray(Contratacion* array,int limite, int indice);
int cli_ordenarPorNombre(Contratacion* array,int limite);

#endif /* CONTRATACION_H_ */
