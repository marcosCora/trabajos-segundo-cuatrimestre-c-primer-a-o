#include "listaDoble.h"

nodo2* inicListaDoble()
{
    return NULL;
}

nodo2* crearNodoDoble(stPersona e)
{
    nodo2* nuevo = (nodo2*) malloc(sizeof(nodo2));
    nuevo->dato = e;
    nuevo->siguiente = NULL;
    nuevo->anterior = NULL;
    return nuevo;
}

nodo2* agregarAlPrincipioDoble(nodo2* lista, nodo2* nuevo)
{
    nuevo->siguiente = lista;
    if(lista)
    {
        lista->anterior = nuevo;
    }
    return nuevo;
}

nodo2* buscoUltimoDoble(nodo2* lista)
{
    nodo2* seg = lista;
    while(seg->siguiente)
    {
        seg = seg->siguiente;
    }

    return seg;
}


nodo2* agregarAlFinalDoble(nodo2* lista, nodo2* nuevo)
{
    if(!lista)
    {
        lista = nuevo;
    }
    else
    {
        nodo2* ultimo = buscoUltimoDoble(lista);
        ultimo->siguiente = nuevo;
        nuevo->anterior = ultimo;
    }

    return lista;
}

void muestraNodoDoble(nodo2* lista)
{
    muestraUnaPersona(lista->dato);
}

void mostrarListaDoble(nodo2* lista)
{
    nodo2* seg = lista;

    while(seg)
    {
        printf("\nANTERIOR = %p - ACTUAL = %p - SIGUIENTE = %p\n\n", seg->anterior, seg, seg->siguiente);
        muestraNodoDoble(seg);
        seg = seg->siguiente;
    }
}


nodo2* eliminaPrimerNodoDoble(nodo2* lista)
{
    nodo2* aux = lista;
    lista = lista->siguiente;
    lista->anterior = NULL;
    free(aux);
    return lista;
}


nodo2* eliminaUltimoNodoDoble (nodo2* lista)
{
    nodo2* aux = lista;
    nodo2* ante;
    while(aux->siguiente)
    {
        ante = aux;
        aux = aux->siguiente;
    }
    free(aux);
    ante->siguiente = NULL;

    return lista;
}


nodo2* borrarListaDoble(nodo2* lista)
{
    nodo2* proximo;///creo dos variables auxiliares
    nodo2* seg = lista;

    while(seg)///recorro hasta que seg se convierta en NULL
    {
        proximo = seg->siguiente;///le asigno a proximo el contenido de seg
        free(seg);///libero en memoria los datos que contiene seg
        seg = proximo;///le asigno a seg el contenido de proximo
    }

    return seg;
}

nodo2* buscarUltimoDobleRecursivo(nodo2* lista)
{
    nodo2* respuesta;

    if(lista == NULL)
    {
        respuesta = NULL;
    }
    else
    {
        if(lista->siguiente == NULL)
        {
            respuesta = lista;
        }
        else
        {
            respuesta = buscarUltimoDobleRecursivo(lista->siguiente);
        }
    }

    return respuesta;
}



nodo2* agregarOrdenadoDNIDoble(nodo2* lista, nodo2* nuevo)
{

    if(lista == NULL)
    {
        lista = nuevo;
    }
    else
    {
        if(strcmp(nuevo->dato.dni,lista->dato.dni) < 0)
        {
            lista = agregarAlPrincipioDoble(lista, nuevo);
        }
        else
        {
            nodo2* ante = lista;
            nodo2* seg = lista->siguiente;
            while(seg != NULL && (strcmp(nuevo->dato.dni, seg->dato.dni) > 0))
            {
                ante = seg;
                seg = seg->siguiente;
            }

            ante->siguiente = nuevo;
            nuevo->anterior = ante;
            nuevo->siguiente = seg;
            if(seg != NULL)
            {
                seg->anterior = nuevo;
            }

        }
    }

    return lista;
}

nodo2* borrarNodoDobleDNI(nodo2* lista,char dni[30])
{
    nodo2 * aux;
    if(lista){
        if(strcmp(dni,lista->dato.dni)==0){
            aux = lista;
            lista = lista->siguiente;
            if(lista){
                lista->anterior = NULL;
            }
            free(aux);
        }else{
            nodo2 *seg=lista->siguiente;

            while(seg != NULL && strcmp(dni,seg->dato.dni) != 0){
                seg = seg->siguiente;
            }
            if (seg != NULL){
                nodo2* ante=seg->anterior;
                nodo2* proximo=seg->siguiente;

                ante->siguiente = seg->siguiente;
                if(proximo){
                    proximo->anterior=ante;
                }
                free(seg);
            }

        }
    }

    return lista;
}


///busca un nodo por DNI y lo retorna


stPersona buscaNodoDniDoble(char dni[20], nodo2 * lista)
{
    nodo2 * seg;
    stPersona e;
    seg = lista;

    while(seg != NULL && (strcmp(dni,seg->dato.dni) != 0))
    {
        seg=seg->siguiente;
    }
    e = seg->dato;
    return e;
}



stPersona verPrimeroDoble(nodo2* lista)
{
    return lista->dato;
}
