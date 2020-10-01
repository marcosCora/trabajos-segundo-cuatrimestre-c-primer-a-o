#include "listaDoble.h"

nodo2* inicListaDoble()
{
    return NULL;
}

nodo2* crearNodoDoble(stEmpleado e)
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
    muestraUnEmpleado(lista->dato);
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
        if(strcmp(nuevo->dato.persona.dni,lista->dato.persona.dni) < 0)
        {
            lista = agregarAlPrincipioDoble(lista, nuevo);
        }
        else
        {
            nodo2* ante = lista;
            nodo2* seg = lista->siguiente;
            while(seg != NULL && (strcmp(nuevo->dato.persona.dni, seg->dato.persona.dni) > 0))
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
/*
nodo2* eliminoNodoPorDniDoble(nodo2* lista, char DNI[30])
{
    nodo2* seg;
    ///nodo2* actual;
    nodo2* ante;

    if(lista != NULL && strcmp(lista->dato.persona.dni, DNI) == 0)
    {
        nodo2* aux = lista;
        lista = lista->siguiente;
        lista->anterior = aux->anterior;
        free(aux);
    }
    else
    {
        seg = lista;
        while(seg != NULL && strcmp(seg->dato.persona.dni, DNI) != 0)
        {
            ante = seg;
            seg = seg->siguiente;
        }
        if(seg != NULL)
        {
            nodo2* aux = seg;
            seg = seg->siguiente;
            seg->anterior = ante;
            free(aux);
        }
    }

    return lista;
}
*/
/*
nodo2* eliminoNodoPorDniDoble(nodo2* lista, int dato)
{
    nodo2 * aBorrar=NULL;
    nodo2 * seg=NULL;

    if(lista!=NULL)
    {
        if(atoi(lista->dato.persona.dni)==dato)
        {
            aBorrar=lista;
            lista=lista->siguiente;
            if(lista!=NULL)
            {
                lista->anterior=NULL;
            }
            free(aBorrar);
        }
        else
        {
            seg=lista->siguiente;
            while(seg!=NULL && atoi(seg->dato.persona.dni)!=dato)
            {
                seg=seg->siguiente;
            }
            if( seg!= NULL)
            {
                nodo2 * anterior=seg->anterior; /// bajo a una variable el anterior
                anterior->siguiente = seg->siguiente; ///salteo el nodo que quiero eliminar.
                if(seg->siguiente)     /// si existe el nodo siguiente
                {
                    nodo2 * siguiente = seg->siguiente;
                    siguiente->anterior=anterior;
                }
                free(seg); ///elimino el nodo.
            }
        }
    }
    return lista;
}
*/

nodo2* eliminoNodoPorDniDoble(nodo2 * lista, char dato[]){
    nodo2 * aBorrar=NULL;
    nodo2 * seg=NULL;

    if(lista!=NULL) {
        if(strcmpi(lista->dato.persona.dni, dato) == 0){
            aBorrar=lista;
            lista=lista->siguiente;
            if(lista!=NULL){
                lista->anterior=NULL;}
            free(aBorrar);
        }
        else {
            seg=lista->siguiente;
            while(seg!=NULL && strcmpi(lista->dato.persona.dni, dato) != 0)
            {
                seg=seg->siguiente;
            }
            if( seg!= NULL) {
                nodo2 * anterior=seg->anterior; /// bajo a una variable el anterior
                anterior->siguiente = seg->siguiente; ///salteo el nodo que quiero eliminar.
                if(seg->siguiente) {   /// si existe el nodo siguiente
                    nodo2 * siguiente = seg->siguiente;
                    siguiente->anterior=anterior;
                }
                free(seg); ///elimino el nodo.
            }
        }
    }
    return lista;
}



///busca un nodo por DNI y lo retorna


stEmpleado buscaNodoDniDoble(char dni[20], nodo2 * lista)
{
    nodo2 * seg;
    stEmpleado e;
    seg = lista;

    while(seg != NULL && (strcmp(dni,seg->dato.persona.dni) != 0))
    {
        seg=seg->siguiente;
    }
    e = seg->dato;
    return e;
}



stEmpleado verPrimeroDoble(nodo2* lista)
{
    return lista->dato;
}
