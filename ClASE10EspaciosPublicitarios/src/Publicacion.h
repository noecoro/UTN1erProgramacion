#ifndef PUBLICACION_H_
#define PUBLICACION_H_


#define TEXTO_LEN 64




typedef struct
{

	char texto[TEXTO_LEN];
	int nRubro;
	int isEmpty;
	int id;
	int idClientes; //agregado
	int status; // agregado!
}Publicacion;

int pub_inicializarArray(Publicacion* array,int limite);

int pub_getEmptyIndex(Publicacion* array,int limite);


#endif /* PUBLICACION_H_ */
