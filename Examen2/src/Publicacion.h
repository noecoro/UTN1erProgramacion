#ifndef PUBLICACION_H_
#define PUBLICACION_H_


#define ESTADO_ACTIVA 0
#define ESTADO_PAUSADA 1
#define TEXTO_LEN 64


typedef struct
{
	char texto [TEXTO_LEN];
	int estado;
	int isEmpty;
	int id;
	int idCliente;
	int numeroDeRubro;
}Publicacion;

int pub_imprimir(Publicacion* auxProducto);
int pub_inicializarArray(Publicacion* array,int limite);
int pub_altaArray(Publicacion* array,int limite, int indice, int* idPublicacion, int idPantalla);
int pub_getEmptyIndex(Publicacion* array,int limite);
int pub_imprimirArray(Publicacion* array,int limite);
int pub_buscarId(Publicacion array[], int limite, int valorBuscado);
int pub_modificarArray(Publicacion* array,int limite, int indice);
int pub_bajaArray(Publicacion* array,int limite, int indice);
int pub_ordenarPorNombre(Publicacion* array,int limite);

int pub_altaForzadaArray(Publicacion* array,int limite, int indice, int* idPublicacion, int idPantalla,char* archivo,char* cuit,int dias);

#endif /* PUBLICACION_H_ */
