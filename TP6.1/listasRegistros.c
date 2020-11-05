#include "listasRegistros.h"

nodo* inicLista()
{
    return NULL;
}

nodo* crearNodo(notaAlumno dato)
{
    nodo* nuevo = (nodo*) malloc(sizeof(nodo));
    nuevo->dato = dato;
    nuevo->siguiente = NULL;

    return nuevo;
}

nodo* agregarAlPrincipio(nodo* lista, nodo* nuevoNodo)///recibo una lista, y el nodo a agregar a esa lista
{
    if(lista == NULL)///si la lista en igual a NULL significa que es la primera
    {
        lista = nuevoNodo;///agregamos directamente el nuevo nodo a la lista
    }
    else
    {
        nuevoNodo->siguiente = lista;///le asigno la direccion de memoria de la lista siguiente a la nueva lista
        lista = nuevoNodo;///a lista le agrego el nuevo nodo
    }
    return lista;
}


nodo* buscoUltimoNodo(nodo* lista)
{
    nodo* aux = lista;

    while(aux->siguiente != NULL)
    {
        aux = aux->siguiente;
    }

    return aux;
}


nodo* agregarAlFinal(nodo* lista, nodo* nuevo)
{
    if(lista == NULL)
    {
        lista = nuevo;
    }
    else
    {
        nodo* ultimo = buscoUltimoNodo(lista);///ultimo almacena el ultimo nodo de la lista
        ultimo->siguiente = nuevo;///el siguiente del ultimo es el nuevo nodo
    }

    return lista;
}

void muestraUnaNotaAlumno(notaAlumno n)
{
    printf("\n Alumno.........: %s ",n.nombreApe);
    printf("\n Legajo.........: %d ",n.legajo);
    printf("\n Nota...........: %d \n",n.nota);
}


void muestraNodo(nodo* aMostrar)
{
    muestraUnaNotaAlumno(aMostrar->dato);
}


void mostrarLista(nodo* lista)
{
    nodo* aux = lista;
    while(aux != NULL)
    {
        muestraNodo(aux);
        aux = aux->siguiente;
    }
}





















