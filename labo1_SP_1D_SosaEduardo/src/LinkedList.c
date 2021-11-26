#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../src/LinkedList.h"


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
	LinkedList* this= NULL;
	this = (LinkedList*) malloc(sizeof(LinkedList));
	if(this!=NULL)
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
		returnAux=this->size;
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
	Node* pNode=NULL;
	int lenLista;
	int i;
	lenLista=ll_len(this);
	if(this!=NULL && nodeIndex>-1 && lenLista>nodeIndex)
	{
		pNode=(this->pFirstNode);
		for (i = 0; i < nodeIndex; ++i)
		{
			pNode=pNode->pNextNode;
		}
	}
	return pNode;
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
	int retorno = -1;
	Node* nodoAnterior;
	Node* nodoNew;

	if(this!=NULL && nodeIndex>-1 && nodeIndex<ll_len(this)+1)
	{
		nodoNew= (Node*)malloc(sizeof(Node));

		if(nodoNew!=NULL)
		{
			nodoNew->pElement= pElement;
			nodoNew->pNextNode= NULL;

			if(nodeIndex==0)
			{
				nodoNew->pNextNode=this->pFirstNode; //Aca hago que mi nuevo nodo apunte a lo que apuntaba el primer nodo viejo
				this->pFirstNode=nodoNew; //actualizo a que apunta el primer nodo viejo
			}else
			{
				nodoAnterior = getNode(this,nodeIndex-1);
				nodoNew->pNextNode=nodoAnterior->pNextNode;
				nodoAnterior->pNextNode=nodoNew;
			}
			this->size++;
			retorno=0;
		}
	}
	return retorno;
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
	int retorno =-1;
	if(this!=NULL)
	{
		addNode(this,ll_len(this),pElement);
		retorno=0;
	}
	return retorno;
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
	void* retorno=NULL;
	Node* auxNodo;

	if(this!=NULL&&index>-1&&index<ll_len(this))
	{
		auxNodo=getNode(this, index);
		retorno= auxNodo->pElement;
	}

	return retorno;
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
	int retorno=-1;
	Node* auxNodo;

	if(this!=NULL&&index>-1&&index<ll_len(this))
	{
		auxNodo=getNode(this, index);
		auxNodo->pElement=pElement;
		retorno= 0;
	}
	return retorno;
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
	int retorno = -1;
	Node* nodoAnterior;
	Node* nodo;

	if(this!=NULL && index>-1 && index<ll_len(this))
	{
		nodo=getNode(this, index);

		if(nodo!=NULL)
		{
			if(this->pFirstNode==nodo)
			{
				this->pFirstNode=nodo->pNextNode;

			}
			else
			{
				nodoAnterior=getNode(this, index-1);
				nodoAnterior->pNextNode=nodo->pNextNode;
			}

			this->size--;
			nodo->pElement=NULL;
			free(nodo);
			retorno=0;
		}
	}
	return retorno;
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
	int retorno =-1;

	if(this!=NULL)
	{
		for (int var = 0; var < ll_len(this); ++var)
		{
			ll_remove(this, 0);
		}
		retorno=0;
	}

	return retorno;
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
	int retorno =-1;

	if(this!=NULL)
	{
		ll_clear(this);
		this->pFirstNode=NULL;
		free(this);
		retorno=0;
	}

	return retorno;
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
	if(this!=NULL)
	{
		for (int i = 0; i < ll_len(this); ++i)
		{
			if(ll_get(this, i)==pElement)
			{
				returnAux=i;
				break;
			}
		}
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
	if(this!=NULL)
	{
		returnAux=1;
		for (int i = 0; i < ll_len(this); ++i)
		{
			if(ll_get(this, i)==NULL)
			{
				returnAux=0;
				break;
			}
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
	int retorno =-1;
	if(this!=NULL&& index>-1 && index<ll_len(this)+1)
	{
		addNode(this,index,pElement);

		retorno=0;
	}
	return retorno;
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

	void* returnAux=NULL;

	Node* auxNodeEliminar;

	if(this!=NULL && index>-1 && index<ll_len(this))
	{
		auxNodeEliminar=getNode(this, index);
		returnAux=auxNodeEliminar->pElement;
		ll_remove(this, index);

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
		for (int i = 0; i < ll_len(this); ++i)
		{
			if(ll_get(this, i)==pElement)
			{
				returnAux=1;
				break;
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
	int elementosContenidos=0;
	void* elementoAComparar;

	if(this!=NULL && this2!=NULL)
	{
		returnAux=0;
		for (int i = 0; i < ll_len(this2); ++i)
		{
			elementoAComparar=ll_get(this2, i);

			for (int j = 0; j < ll_len(this); ++j)
			{
				if(ll_get(this, j)==elementoAComparar)
				{
					elementosContenidos++;
					break;
				}
			}
		}
		if(elementosContenidos==ll_len(this2))
		{
			returnAux=1;
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

	if(this!=NULL&&from>-1&&to>from&&to<=ll_len(this))
	{
		cloneArray=ll_newLinkedList();
		if(cloneArray!=NULL)
		{
			for (int j = from; j <= to; ++j)
			{
				ll_add(cloneArray, ll_get(this, j));
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
	if(this!=NULL)
	{
		cloneArray=ll_newLinkedList();
		if(cloneArray!=NULL)
		{
			cloneArray=ll_subList(this, 0, ll_len(this));
		}
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
	int i,j;
	void* pElement;
	void* pElement2;
	int cambio;
	if(this!=NULL && pFunc!=NULL && (order==0 ||order==1) )
	{
		int tam=ll_len(this);
		while(cambio)
		{
			cambio=0;
			for (i=0;i<tam-1;i++)
			{
				for(j=i+1;j<tam;j++)
				{
					pElement=ll_get(this,i);
					pElement2=ll_get(this,j);
					if(pElement!=NULL&&pElement2!=NULL)
					{
						///Mis Dos casos Donde es necesario hacer un intercambio
						if( (pFunc(pElement,pElement2)>0 && order==1) || (pFunc(pElement,pElement2)<0 && order==0))
						{
							ll_set(this,j,pElement);
							ll_set(this,i,pElement2);
							cambio=1;
						}

					}
				}
			}
		}

		returnAux=0;
	}
	return returnAux;

}

LinkedList* ll_map(LinkedList* this, int(*pFunc)(void*))
{

	void* pElement = NULL;
	LinkedList* newList=NULL;

	int tam;

	if(this != NULL && pFunc != NULL)
	{
		tam = ll_len(this);
		newList=ll_clone(this);
		for(int i=0; i<tam; i++)
		{
			pElement = ll_get(newList, i);
			pFunc(pElement);
		}
	}
	return newList;
}


/** @fn LinkedList ll_filter(LinkedList, int()(void))
 * @brief Devuelve un nuevo Linkedlist cargado con los elementos que pasan la funcion filtro.
 *
 * @param LinkedList* this Linkedlist a filtrar.
 * @param int(pFunc)(void) puntero a la funcion que filtra.
 * @return nuevo puntero a LinkedList con los elementos que pasaron la funcion.
 * */

LinkedList* ll_filter(LinkedList* this, int(*pFunc)(void*))
{
	LinkedList* filterlist=NULL;
	    int tam;
	    void* aux=NULL;
	    if(this!=NULL && pFunc!=NULL)
	    {
	        filterlist=ll_newLinkedList();
	        if(filterlist!=NULL)
	        {
	            tam=ll_len(this);
	            for(int i=0;i<tam-1;i++)
	            {
	                aux=ll_get(this, i);
	                if(pFunc(ll_get(this, i)))
	                {
	                    if(ll_add(filterlist,  aux))
	                    {
	                        ll_deleteLinkedList(filterlist);
	                        filterlist=NULL;
	                        break;
	                    }
	                }
	            }
	        }
	    }
	    return filterlist;
}

LinkedList* ll_filterString(LinkedList* this, char* string, int(*pFunc)(void*,char*))
{
	LinkedList* filterlist=NULL;
	    int tam;
	    void* aux=NULL;
	    if(this!=NULL && pFunc!=NULL)
	    {
	        filterlist=ll_newLinkedList();
	        if(filterlist!=NULL)
	        {
	            tam=ll_len(this);
	            for(int i=0;i<tam-1;i++)
	            {
	                aux=ll_get(this, i);
	                if(pFunc(ll_get(this, i),string))
	                {
	                    if(ll_add(filterlist,  aux))
	                    {
	                        ll_deleteLinkedList(filterlist);
	                        filterlist=NULL;
	                        break;
	                    }
	                }
	            }
	        }
	    }
	    return filterlist;
}

LinkedList* ll_filterInt(LinkedList* this, int entero, int(*pFunc)(void*,int))
{
	LinkedList* filterlist=NULL;
	    int tam;
	    void* aux=NULL;
	    if(this!=NULL && pFunc!=NULL)
	    {
	        filterlist=ll_newLinkedList();
	        if(filterlist!=NULL)
	        {
	            tam=ll_len(this);
	            for(int i=0;i<tam-1;i++)
	            {
	                aux=ll_get(this, i);
	                if(pFunc((ll_get(this, i)),entero))
	                {
	                    if(ll_add(filterlist,  aux))
	                    {
	                        ll_deleteLinkedList(filterlist);
	                        filterlist=NULL;
	                        break;
	                    }
	                }
	            }
	        }
	    }
	    return filterlist;
}

LinkedList* ll_filterFloat(LinkedList* this, float flotante , int(*pFunc)(void*,float))
{
	LinkedList* filterlist=NULL;
	    int tam;
	    void* aux=NULL;
	    if(this!=NULL && pFunc!=NULL)
	    {
	        filterlist=ll_newLinkedList();
	        if(filterlist!=NULL)
	        {
	            tam=ll_len(this);
	            for(int i=0;i<tam-1;i++)
	            {
	                aux=ll_get(this, i);
	                if(pFunc((ll_get(this, i)),flotante))
	                {
	                    if(ll_add(filterlist,  aux))
	                    {
	                        ll_deleteLinkedList(filterlist);
	                        filterlist=NULL;
	                        break;
	                    }
	                }
	            }
	        }
	    }
	    return filterlist;
}

LinkedList* ll_filterDosEstructuras(LinkedList* this, void* estructuraGuia , int(*pFunc)(void*,void*))
{
	LinkedList* filterlist=NULL;
	    int tam;
	    void* aux=NULL;
	    if(this!=NULL && pFunc!=NULL)
	    {
	        filterlist=ll_newLinkedList();
	        if(filterlist!=NULL)
	        {
	            tam=ll_len(this);
	            for(int i=0;i<tam-1;i++)
	            {
	                aux=ll_get(this, i);
	                if(pFunc((ll_get(this, i)),estructuraGuia))
	                {
	                    if(ll_add(filterlist,  aux))
	                    {
	                        ll_deleteLinkedList(filterlist);
	                        filterlist=NULL;
	                        break;
	                    }
	                }
	            }
	        }
	    }
	    return filterlist;
}
