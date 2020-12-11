#ifndef LISTA2_H_INCLUDED
#define LISTA2_H_INCLUDED
#include <string.h>
#include <stdio.h>
#include <malloc.h>
#include "empleados.h"

typedef struct _nodo2{
    stEmpleado dato;
    struct _nodo2 * anterior;
    struct _nodo2 * siguiente;
}nodo2;

nodo2 * iniciLista2();
nodo2* crearNodo2(stEmpleado e);
nodo2* agregarAlPrincipio2 (nodo2* lista, nodo2* nuevo);
nodo2* buscarUltimo2(nodo2 * lista);
nodo2* agregarAlFinal2(nodo2* lista, nodo2* nuevo);
void muestraNodo2(nodo2* lista);
void mostrarLista2(nodo2* lista);
nodo2* borrarNodo2(nodo2 * lista, char dni[20]);
stEmpleado verPrimero2(nodo2* lista);
nodo2* EliminarPrimerNodo2(nodo2 * lista);
nodo2* borrarLista2 (nodo2* lista);
nodo2 *borrarUltimoNodo2(nodo2 *lista);
nodo2* borrarNodoDoble(nodo2* lista,char dni[30]);
nodo2* buscarNodo2(nodo2* lista, int dni);
void borrarNodoDoblePD(nodo2** lista,char dni[30]);


#endif // LISTA2_H_INCLUDED
