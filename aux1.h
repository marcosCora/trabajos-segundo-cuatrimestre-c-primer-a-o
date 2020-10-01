#ifndef AUX1_H_INCLUDED
#define AUX1_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "listaEmpleados.h"
#include "empleados.h"
#include "pilaLista.h"
#include "listaDoble.h"
#include "fila.h"

nodoEmple* archivoALista(char nombreArch[], nodoEmple* lista);
nodoEmple* archivoAListaOrdenadaDni(char nombreArch[], nodoEmple* lista);
int buscarNodoDNIFlag (nodoEmple * lista, char dni [30]);
nodoEmple* intercalarLista (nodoEmple * listaA, nodoEmple * listaB, nodoEmple * listaDestino);
void muestraPila(Pila p);
void pila2Lista(Pila p, nodoEmple** lista);
nodo2* archivoAListaDoble(char nombreArch[], nodo2* lista);
nodo2* archivoAListaDobleDNI(char nombreArch[], nodo2* lista);
void archivoAFila(char archivo[20], Fila* fila);


#endif // AUX1_H_INCLUDED
