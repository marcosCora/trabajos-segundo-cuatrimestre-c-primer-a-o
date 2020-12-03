#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

typedef struct nodoArbol
{
    int dato;
    struct nodoArbol* izq;
    struct nodoArbol* der;
}nodoArbol;

nodoArbol* inicArbol();
nodoArbol* creaNodoArbol(int dato);
nodoArbol* insertar(nodoArbol* arbol, nodoArbol* nuevo);
void muestraNodoArbol(nodoArbol* arbol);
void preOrder(nodoArbol* arbol);
void inOrder(nodoArbol* arbol);
void postOrder(nodoArbol* arbol);



#endif // ARBOL_H_INCLUDED
