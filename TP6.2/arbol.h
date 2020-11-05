#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "funcionesArch.h"

typedef struct
{
    char nombreAnimal [30];
    int cantidad;
    int habitat;
// 1 - selva, 2- savana, 3-bosque, 4-mar
} animal;

typedef struct
{
    animal dato;
    struct nodoArbol * izq;
    struct nodoArbol * der;
} nodoArbol;

typedef struct
{
    int idEspecie;
    char especie [20];
    // "Mamiferos", "Aves"
    // "Reptiles", "Peces"
    nodoArbol * arbolDeAnimales;
} stCeldaEspecie;

nodoArbol* inicArbol();
nodoArbol* crearNodoArbol2(animal a);
nodoArbol* insertar (nodoArbol* arbol, nodoArbol* nuevo);
void muestraUnAnimal(animal a);
void muestraNodoArbol(nodoArbol* nodo);
void inOrder(nodoArbol* arbol);



#endif // ARBOL_H_INCLUDED
