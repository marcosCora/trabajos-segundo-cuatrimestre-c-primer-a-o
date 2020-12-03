#include "arbol.h"

nodoArbol* inicArbol()
{
    return NULL;
}

nodoArbol* creaNodoArbol(int dato)
{
    nodoArbol*  nuevo = (nodoArbol*) malloc(sizeof(nodoArbol));

    nuevo->dato = dato;
    nuevo->izq = NULL;
    nuevo->der = NULL;

    return nuevo;
}

nodoArbol* insertar(nodoArbol* arbol, nodoArbol* nuevo)
{
    if(!arbol)
    {
        arbol = nuevo;
    }
    else
    {
        if(nuevo->dato > arbol->dato)
        {
            arbol->der = insertar(arbol->der, nuevo);
        }
        else
        {
            arbol->izq = insertar(arbol->izq, nuevo);
        }
    }
    return arbol;
}

void muestraNodoArbol(nodoArbol* arbol)
{
    printf("%d - ", arbol->dato);
}

void preOrder(nodoArbol* arbol)
{
    if(arbol)
    {
        muestraNodoArbol(arbol);
        preOrder(arbol->izq);
        preOrder(arbol->der);
    }
}

void inOrder(nodoArbol* arbol)
{
    if(arbol)
    {
        inOrder(arbol->izq);
        muestraNodoArbol(arbol);
        inOrder(arbol->der);
    }
}

void postOrder(nodoArbol* arbol)
{
    if(arbol)
    {
        postOrder(arbol->izq);
        postOrder(arbol->der);
        muestraNodoArbol(arbol);
    }
}

