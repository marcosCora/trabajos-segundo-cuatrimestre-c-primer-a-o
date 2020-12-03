#ifndef LISTAEMPLEADOS_H_INCLUDED
#define LISTAEMPLEADOS_H_INCLUDED
#include "persona.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>


typedef struct _nodo{
    stPersona dato;
    struct _nodo* siguiente;
}nodo;

nodo* inicLista();
nodo* crearNodo(stPersona dato);
nodo* agregarAlPrincipio(nodo* lista, nodo* nuevoNodo);
void muestraNodo(nodo* aMostrar);
void mostrarLista(nodo* lista);
nodo* buscoUltimoNodo(nodo* lista);
nodo* agregarAlFinal(nodo* lista, nodo* nuevo);
nodo* borrarLista(nodo* lista);
nodo* agregarOrdenadoDNI(nodo* lista, nodo* nuevo);
nodo* eliminoNodoPorApellido(nodo* lista, char apellido[]);
nodo * buscarNodoDNI(char dni[20], nodo * lista);
nodo* invertirLista (nodo* lista);
int cuentaLista(nodo* lista);
void borrarNodoDNIPD(nodo ** lista, char dni[20]);
nodo* eliminaUltimoNodo (nodo* lista);
nodo* eliminaPrimerNodo(nodo* lista);
stPersona verPrimero(nodo* lista);
nodo* agregarOrdenadoApellido(nodo* lista, nodo* nuevo);


#endif // LISTAEMPLEADOS_H_INCLUDED
