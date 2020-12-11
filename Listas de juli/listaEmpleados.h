#ifndef LISTAEMPLEADOS_H_INCLUDED
#define LISTAEMPLEADOS_H_INCLUDED
#include <stdio.h>
#include <malloc.h>
#include "empleados.h"


typedef struct _nodo{
    stEmpleado dato;
    struct _nodo* siguiente;
}nodo;

nodo* inicLista();
nodo* crearNodo(stEmpleado dato);
nodo * agregarAlPrincipio (nodo * lista, nodo * nuevoNodo);
void agregarAlPrincipioPD (nodo ** lista, nodo * nuevoNodo);
void agregarAlPrincipioPDPro (nodo**, nodo* nuevoNodo);
void mostrarNodo (nodo * aMostrar);
void mostrarLista(nodo* lista);
nodo* buscarUltimo(nodo *lista);
nodo* agregarAlFinal(nodo * lista, nodo* nuevo);
nodo* borrarLista (nodo* lista);
nodo * agregarEnOrdenApellido (nodo * lista, nodo * nuevo);
nodo * buscarNodoDNI(char dni[20], nodo * lista);
nodo * borrarNodoDNI(nodo * lista, char dni[20]);
nodo* agregarEnOrdenDNI(nodo* lista, nodo* nuevo);
int cuentaLista(nodo* lista);
nodo* eliminaUltimoNodo (nodo* lista);
nodo* eliminaPrimerNodo(nodo* lista);
void eliminarPrimerNodoPD(nodo** lista);
stEmpleado verPrimero(nodo* lista);
void muestraListaInvertidaRecurisva(nodo* lista);
void borrarNodoDNIPD(nodo ** lista, char dni[20]);
nodo* invertirLista(nodo* lista);
int buscarNodoDNIFlag (nodo * lista, char dni [30]);
nodo* intercalarLista (nodo * listaA, nodo * listaB, nodo * listaDestino);
void mostrarPosPar (nodo* lista);
nodo* invertirListaRecursivo (nodo* lista);
nodo* borrarNodoRecursivo (nodo* lista, int dato);

#endif // LISTAEMPLEADOS_H_INCLUDED
