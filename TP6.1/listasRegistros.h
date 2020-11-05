#ifndef LISTASREGISTROS_H_INCLUDED
#define LISTASREGISTROS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "ADL.h"

#define AR_REGISTROS "registros.dat"
#define ESC 27

typedef struct
{
    int nota;
    int legajo;
    char nombreApe[30];

} notaAlumno;

typedef struct nodo
{
    notaAlumno dato;
    struct nodo *siguiente;
} nodo;


typedef struct
{
    int idMateria;
    char materia[30];
    nodo * listaDeNotas;
} stCelda;

nodo* inicLista();
nodo* crearNodo(notaAlumno dato);
nodo* agregarAlPrincipio(nodo* lista, nodo* nuevoNodo);
nodo* buscoUltimoNodo(nodo* lista);
nodo* agregarAlFinal(nodo* lista, nodo* nuevo);
void muestraUnaNotaAlumno(notaAlumno n);
void muestraNodo(nodo* aMostrar);
void mostrarLista(nodo* lista);





#endif // LISTASREGISTROS_H_INCLUDED
