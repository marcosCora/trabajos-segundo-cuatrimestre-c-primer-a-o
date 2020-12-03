#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED
#include "empleados.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct nodoArbol
{
    stEmpleado dato;
    struct nodoArbol* izq;
    struct nodoArbol* der;

}nodoArbol;

nodoArbol* inicArbol();
nodoArbol* crearNodoArbol(stEmpleado e);
nodoArbol* insertar (nodoArbol* arbol, nodoArbol* nuevo);
void muestraNodoArbol(nodoArbol* nodo);
void preOrder(nodoArbol* arbol);
void inOrder(nodoArbol* arbol);
void postOrder(nodoArbol* arbol);
nodoArbol* buscaNodoArbol(nodoArbol* arbol, char dni[]);
nodoArbol* insertarSinRepetidos(nodoArbol* arbol, nodoArbol* nuevo);
nodoArbol* eliminarNodoArbolPro(nodoArbol* arbol, char dni[]);
nodoArbol* buscarMenorNodoArbol (nodoArbol* arbol);
nodoArbol* buscarMazIzq (nodoArbol* arbol);
nodoArbol* buscarMazDer (nodoArbol* arbol);





#endif // ARBOL_H_INCLUDED
