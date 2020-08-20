#ifndef envio_H_INCLUDED
#define envio_H_INCLUDED

#define NOMBRE_LEN 150
#define ZONA_LEN 100
#define ID_LEN 10
#define TIPO_LEN 3


#define TIPO_NORMAL 0
#define TIPO_EXPRESS 1
#define TIPO_SEGUN_DISPONIBILIDAD 2

#include "LinkedList.h"

typedef struct
{
    int idProducto;
    char nombre[NOMBRE_LEN ];
    int idCamion;
    char zona[ZONA_LEN 	];
    float kilometros;
    int tipo;
    float costo;

}Envio;

Envio* envio_new();
Envio* envio_newParametros( char* idProductoStr, char* nombreStr, char* idCamionStr, char* zonaStr, char* kilometrosStr, char* tipoStr, char* costoStr);
Envio* envio_newParametrosBin( int idProducto, char* nombreStr, int idCamion, char* zonaStr, float kilometros, int tipo, float costo);
void envio_delete();

int envio_setIdProducto(Envio* this,int idProducto);
int envio_setIdProductoTxt(Envio* this,char* idProductoStr);
int envio_getIdProducto(Envio* this,int* idProducto);
int envio_getIdProductoTxt(Envio* this,char* idProductoStr);

int envio_setNombre(Envio* this,char* nombre);
int envio_getNombre(Envio* this,char* nombre);


int envio_setIdCamion(Envio* this,int IdCamion);
int envio_setIdCamionTxt(Envio* this,char* IdCamionStr);
int envio_getIdCamion(Envio* this,int* idCamion);
int envio_getIdCamionTxt(Envio* this,char* idCamionStr);

int envio_setZona(Envio* this,char* zonaStr);
int envio_getZona(Envio* this,char* zonaStr);

int envio_setKilometrosRecorridos(Envio* this, float kilometros);
int envio_setKilometrosRecorridosTxt(Envio* this, char*kilometrosStr);
int envio_getKilometrosRecorridos(Envio* this, float* kilometros);
int envio_getKilometrosRecorridosTxt(Envio* this, char* kilometrosStr);



int envio_setTipoDeEntrega(Envio* this, int tipo);
int envio_setTipoDeEntregaTxT(Envio* this,char* tipo);
int envio_getTipoDeEntrega(Envio* this,int* tipo);
int envio_getTipoDeEntregaTxt(Envio* this, char* tipo);



int envio_setCostoDelEnvio(Envio* this,float costo);
int envio_setCostoDeEnvioTxt(Envio* this,char*costoStr);
int envio_getCostoDeEnvios(Envio* this,float* costo);
int envio_getCostoDeEnvioTxt(Envio* this,char* costoStr);

int envio_calcularCostoDeEnvio(void* pElement);
int envio_DeterminarCostoFijo(Envio* pElement, float* costoFijo);

int lecturaEnConjuntoDeAtributos(Envio* this, int* idProducto, char* nombre, int* idCamion, char* zona, float* kilometros, int* tipo, float* costo);

void envio_ImprimirUnElemento(Envio* pElemento);
void envio_ImprimirEnvios(LinkedList* this);
int envio_EsZona(void* pElement,char* zonaDeseada);

int envio_ImprimirListaDeZonas(LinkedList* this);
int BuscarZonaIncluidaEnLista( char* zona, LinkedList* this);

#endif // envio_H_INCLUDED
