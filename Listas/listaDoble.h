#ifndef LISTADOBLE_H_INCLUDED
#define LISTADOBLE_H_INCLUDED
#include "empleados.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct _nodo2
{
    stEmpleado dato;
    struct nodo2* anterior;
    struct nodo2* siguiente;
}nodo2;

nodo2* inicListaDoble();
nodo2* crearNodoDoble(stEmpleado e);
nodo2* agregarAlPrincipioDoble(nodo2* lista, nodo2* nuevo);
nodo2* buscoUltimoDoble(nodo2* lista);
nodo2* agregarAlFinalDoble(nodo2* lista, nodo2* nuevo);
void muestraNodoDoble(nodo2* lista);
void mostrarListaDoble(nodo2* lista);
nodo2* eliminaUltimoNodoDoble (nodo2* lista);
nodo2* eliminaPrimerNodoDoble(nodo2* lista);
nodo2* borrarListaDoble(nodo2* lista);
nodo2* buscarUltimoDobleRecursivo(nodo2* lista);
nodo2* agregarOrdenadoDNIDoble(nodo2* lista, nodo2* nuevo);
nodo2* borrarNodoDobleDNI(nodo2* lista,char dni[30]);
stEmpleado buscaNodoDniDoble(char dni[20], nodo2 * lista);
stEmpleado verPrimeroDoble(nodo2* lista);


#endif // LISTADOBLE_H_INCLUDED
