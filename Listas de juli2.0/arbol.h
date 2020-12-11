#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED
#include "empleados.h"

typedef struct nodoArbol{
    stEmpleado dato;
    struct nodoArbol* izq;
    struct nodoArbol* der;
}nodoArbol;

nodoArbol* inicArbol();
nodoArbol* crearNodoArbol(stEmpleado e);
nodoArbol* insertar(nodoArbol* arbol, nodoArbol* nuevo);
nodoArbol* insertarSinRepetidos(nodoArbol* arbol, nodoArbol* nuevo);
void mostrarNodoArbol(nodoArbol* nodo);
void preOrder(nodoArbol* arbol);
void inOrder(nodoArbol* arbol);
void postOrder(nodoArbol* arbol);
nodoArbol* buscarPorNombre(nodoArbol* arbol, char dato[]);
int contarHojas(nodoArbol*arbol);
int calcularAltura (nodoArbol* arbol);
nodoArbol* buscarMenorNodoArbol(nodoArbol* arbol);
nodoArbol* eliminarNodoArbol (nodoArbol* arbol, char dni[]);
eliminarNodoArbolPro(nodoArbol* arbol, char dni[]);
int calcularAlturaArbol (nodoArbol* arbol);

#endif // ARBOL_H_INCLUDED
