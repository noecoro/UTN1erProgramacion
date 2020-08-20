#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
	LinkedList* this;
    this=(LinkedList*)malloc(sizeof(LinkedList));
    if(this==NULL)
    {
    	printf("No queda memoria");
    }
    else
    {
    	this->size=0;
    	this->pFirstNode=NULL;
    }

    return this;
}


/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
    	returnAux= this->size;
    }
    return returnAux;
}
/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* auxiliarNodo=NULL;
    int indice=0;

    if(this!=NULL && nodeIndex>=0 && nodeIndex< ll_len(this))
    {
    	auxiliarNodo= this->pFirstNode;
    	do{
			if(indice == nodeIndex)
			{
				return auxiliarNodo;
				break;

			}
			else
			{
				auxiliarNodo = auxiliarNodo->pNextNode;
				indice++;
			}
		}while(auxiliarNodo!=NULL);

    }


	return NULL;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* pNodoNuevo=NULL;
    Node* pNodoProximo=NULL;
    Node* pNodoPrevio=NULL;

    if(this!=NULL && nodeIndex>=0 && nodeIndex <= ll_len(this))
    {
    	if((pNodoNuevo= (Node*)malloc(sizeof(Node)))!= NULL)
    	{


    		if(nodeIndex==0)
    		{
    			pNodoNuevo->pNextNode = this->pFirstNode;
    			this->pFirstNode = pNodoNuevo;

    		}

    		else if(nodeIndex == ll_len(this)) //enlazo el nodo al final

    		{
    			if((pNodoPrevio = getNode(this,nodeIndex-1))!= NULL)//puntero al nodo anterior
    			{
    				pNodoPrevio->pNextNode= pNodoNuevo;
    				pNodoNuevo->pNextNode =NULL;
    			}
    		}

    		else //agrego el nodo intermedio entre otros dos nodos

    		{
    			if((pNodoProximo = getNode(this,nodeIndex))!= NULL)//puntero proximo nodo nuevo

    			   	{
    					pNodoNuevo->pNextNode = pNodoProximo;
    					if((pNodoPrevio = getNode(this,nodeIndex-1))!= NULL)
    					{
    						pNodoPrevio->pNextNode = pNodoNuevo;
    					}
    			   	}
    		}
    		pNodoNuevo->pElement = pElement;
    		this->size++;
    		returnAux=0;
    	}
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this!=NULL)
    {
    	returnAux= addNode(this,ll_len(this),pElement);
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* AuxiliarNodo = NULL;

    if(this!=NULL && index>=0 && index < ll_len(this))
    {
    	if((AuxiliarNodo = getNode(this, index)) !=NULL)
    	{
    		returnAux=  AuxiliarNodo->pElement;
    	}
    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* AuxiliarNodo=NULL;

    if(this!=NULL && index>=0 && index < ll_len(this))
      {
    	if((AuxiliarNodo = getNode(this, index)) !=NULL)
      	{
    		AuxiliarNodo->pElement = pElement;
    		returnAux=0;
      	}
      }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* nodoAuxiliar = NULL;
    Node* nodoPrevio = NULL;

    if(this!=NULL && index>=0 && index < ll_len(this))
    {
    	if((nodoAuxiliar = getNode(this, index)) !=NULL)
    		{

    			if(index==0)
    			{
    				this->pFirstNode = nodoAuxiliar->pNextNode;
    			}


    			else if ((nodoPrevio = getNode(this,index-1))!=NULL)
    			{
    				if(index==(ll_len(this)-1))
    				{
    					nodoPrevio->pNextNode=NULL;
    				}
    				else
    				{
    					nodoPrevio->pNextNode=nodoAuxiliar->pNextNode;
    				}
    			}

				free(nodoAuxiliar);
        		this->size--;
        		returnAux=0;
        	}
      }


    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int index=ll_len(this);

    if(this!=NULL)
    {
    	while(index>-1)
    	{
    		ll_remove(this, index);

    		index--;
    		returnAux=0;
    	}
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
    	ll_clear(this);
    	free(this);
    	returnAux = 0;
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
	Node* auxiliarNodo=NULL;
    int indice=0;

    if(this!=NULL)
    {


    	    	auxiliarNodo= this->pFirstNode;
    	    	do{

    	    		if(auxiliarNodo->pElement == pElement)
    	    		{
    	    			returnAux=indice;
    	    			break;
    	    		}

    				else
    				{
    					auxiliarNodo=auxiliarNodo->pNextNode;
    					indice++;
    				}
    			}while(indice < ll_len(this));

   }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    int size= ll_len(this);

    if(this!=NULL)
      {
    	if(size>0)
    	{
    		returnAux=0;
    	}

    	else
    	{
    		returnAux= 1;
    	}
      }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;

    if(this!=NULL && index>=0 && index <= ll_len(this))
    {
    	if(addNode(this,  index, pElement)==0)
    	{
    		returnAux=0;
    	}

    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
	void* pElement=NULL;
    void* returnAux = NULL;

    if(this!=NULL && index>=0 && index< ll_len(this))
    {
		if((pElement= ll_get( this, index))!=NULL)
		{
			if(ll_remove(this,index)==0)
			{
				returnAux =  pElement;
			}
		}
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;


    if(this!=NULL)
    {
    	returnAux=0;

    	if(ll_isEmpty(this)==0)
    	{

    		 if((ll_indexOf(this, pElement))!= -1)
    		    {
    			 returnAux = 1;
    		    }
    	}

    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int indexThis2= ll_len (this2)-1;
    void* pElement=NULL;
    int indiceThis;


    if(this!=NULL && this2 != NULL)
    {
    	returnAux =0;

    	if(ll_isEmpty(this)==0 && ll_isEmpty(this2)==0)
    	{
    	  do{

    			if((pElement=ll_get(this2,indexThis2))!=NULL)
    			{
    				if((indiceThis= ll_indexOf(this, pElement))!=-1)
					{
						indexThis2--;
						returnAux=1;
					}
    				else
    				{
    					returnAux =0;
    					break;
    				}
    			}
    		}
    		while(indexThis2 >-1);
    	 }
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
  LinkedList* cloneArray = NULL;
  void* pElement = NULL;
  int index;
  if(this!=NULL && from<to && from>=0 && from <= ll_len(this)-1  && to <=ll_len(this) &&ll_isEmpty(this)==0 )
  {
	  if(( cloneArray = ll_newLinkedList())!=NULL) //creo la lista
	  		{
		  	  for(index = from;index< to; index++ )
		  	  {
		  		if((pElement= ll_get(this, index))!=NULL) //obtengo los elementos a agregar
		  		{

		  			if(ll_add(cloneArray, pElement)!=0) // los llevo a la sublista
		  			{
		  				if((ll_deleteLinkedList(cloneArray))==0)
		  				{
		  				cloneArray=NULL;
		  				break;
		  				}
		  			}

		  		}
		  	  }

	  		}
  }
  return cloneArray;
  }




/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    int from= 0;
    int to= ll_len(this);

    if((cloneArray=ll_subList( this, from, to))!= NULL)
    {
    	  printf("lista clonada con exito");
    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    int flagSwap;
    int nuevoSize = ll_len(this);
    void* pElementUno=NULL;
    void* pElementDos=NULL;
    void* buffer = NULL;
    int i;


    if(this!=NULL && ll_isEmpty(this)==0 && pFunc != NULL && (order==0 || order==1))
    {

    	do
    	{
    		flagSwap=0;
    		for(i=0; i< nuevoSize-1; i++)
    		{
				if((pElementUno=ll_get(this, i))!=NULL && (pElementDos=ll_get(this, i+1))!=NULL)
				{

					if((pFunc(pElementUno,pElementDos)==-1 && order==0)||((pFunc(pElementUno,pElementDos)==1 && order==1)))
					{

						{
							flagSwap=1;
							buffer= pElementUno;
							if(ll_set( this, i, pElementDos) == 0)
							{
								if(ll_set( this, i+1,buffer) == 0)
								{
									continue;
								}
							}

						}
					}

				}


    		}
    		nuevoSize--;

    	}while(flagSwap);
    	returnAux=0;
    }



    return returnAux;

}


int ll_map (LinkedList* this, int (*funcionGenerica) (void* ))
{
	void* pElemento;
	int i;
	int retorno =-1;

	if(this!=NULL && funcionGenerica!=NULL)
	{
		retorno =  0;
		for(i=0; i< ll_len(this); i++)
		{
			if((pElemento=ll_get(this, i))!=NULL)
			{
				if(funcionGenerica(pElemento)<0)
				{
					retorno= -1;
					break;
				}


			}
		}
	}
	return retorno;
}


LinkedList* ll_filter(LinkedList* this , int (*FuncionGenerica)(void*, char*), char* atributoDeseado)
{
	LinkedList* listaFiltrada= NULL;
	int i;
	void* pElement;


	if(this!=NULL && FuncionGenerica!= NULL && atributoDeseado!= NULL)

	{
		if((listaFiltrada = ll_newLinkedList())!=NULL)
		{

			for(i=0; i< ll_len(this); i++)
			{
				if((pElement=ll_get(this, i))!=NULL)
				{
					if(FuncionGenerica(pElement, atributoDeseado)==1)
					{
						ll_add(listaFiltrada,  pElement);

					}
				}

			}

		}
	}
	return listaFiltrada;
}




















