#include "arbol.h"

nodoArbol* inicArbol()
{
    return NULL;
}

nodoArbol* crearNodoArbol2(animal a)
{

    nodoArbol* nuevo = (nodoArbol*) malloc(sizeof(nodoArbol));
    nuevo->dato = a;



    nuevo->der = NULL;
    nuevo->izq = NULL;
    return nuevo;

}

nodoArbol* insertar (nodoArbol* arbol, nodoArbol* nuevo)
{

    if(!arbol)
    {
        arbol = nuevo;
    }
    else
    {

        if(nuevo->dato.cantidad > arbol->dato.cantidad)
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


void muestraUnAnimal(animal a)
{
    printf("\n ANIMAL.........: %s ",a.nombreAnimal);
    printf("\n HABITAT........: %d ",a.habitat);
    printf("\n CANTIDA........: %d \n",a.cantidad);
}

void muestraNodoArbol(nodoArbol* nodo)
{
    muestraUnAnimal(nodo->dato);
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













