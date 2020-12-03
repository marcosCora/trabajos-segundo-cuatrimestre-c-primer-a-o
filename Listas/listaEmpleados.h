#ifndef LISTAEMPLEADOS_H_INCLUDED
#define LISTAEMPLEADOS_H_INCLUDED
#include "empleados.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>


typedef struct _nodo{
    stEmpleado dato;
    struct _nodo* siguiente;
}nodoEmple;

nodoEmple* inicLista();
nodoEmple* crearNodo(stEmpleado dato);
nodoEmple* agregarAlPrincipio(nodoEmple* lista, nodoEmple* nuevoNodo);
void muestraNodo(nodoEmple* aMostrar);
void mostrarLista(nodoEmple* lista);
nodoEmple* buscoUltimoNodo(nodoEmple* lista);
nodoEmple* agregarAlFinal(nodoEmple* lista, nodoEmple* nuevo);
nodoEmple* borrarLista(nodoEmple* lista);
nodoEmple* agregarOrdenadoDNI(nodoEmple* lista, nodoEmple* nuevo);
nodoEmple* eliminoNodoPorApellido(nodoEmple* lista, char apellido[]);
nodoEmple * buscarNodoDNI(char dni[20], nodoEmple * lista);
nodoEmple* invertirLista (nodoEmple* lista);
int cuentaLista(nodoEmple* lista);
void borrarNodoDNIPD(nodoEmple ** lista, char dni[20]);
nodoEmple* eliminaUltimoNodo (nodoEmple* lista);
nodoEmple* eliminaPrimerNodo(nodoEmple* lista);
stEmpleado verPrimero(nodoEmple* lista);
nodoEmple* borroNodoRecrusivo(nodoEmple* lista, char dato[]);
nodoEmple* insertarEnOrdenRecursivo(nodoEmple* lista, nodoEmple* nuevo);

#endif // LISTAEMPLEADOS_H_INCLUDED
