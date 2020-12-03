#ifndef ADL_H_INCLUDED
#define ADL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <conio.h>
#include "registroArchivo.h"

typedef struct
{
    int idRegistro;
    int idPaciente;
    char nombrePaciente[30];
    char apellidoPaciente[30];
    char diagnostico[100];
    char fechaAtencion[11];
    char nombreDoctor[30];
} stPaciente;

typedef struct nodo
{
    stPaciente dato;
    struct nodo* siguiente;
} nodo;

typedef struct
{
    int idEspecialidad;
    char especialidadMedica[30];
    nodo* listaDePacientes;

} stEspecialidadMedica;



///FUNCIONES DE LISTA

nodo* inicLista();
nodo* crearNodo(stPaciente dato);
nodo* agregarAlPrincipio(nodo* lista, nodo* nuevoNodo);
nodo* buscoUltimoNodo(nodo* lista);
nodo* agregarAlFinal(nodo* lista, nodo* nuevo);
void muestraUnPaciente(stPaciente p);
void muestraNodo(nodo* aMostrar);
void mostrarLista(nodo* lista);

///FUNCIONES DE ADL

int buscaPosicionArregloEspecialidad(stEspecialidadMedica adl[], int v, char especialidad[]);
int alta(stEspecialidadMedica adl[], int v, stPaciente p, char especialidad[], int idEspecialidad);
int archivo2adl(char archivo[], stEspecialidadMedica adl[], int v, int dim);
void muestraADL (stEspecialidadMedica adl[], int v);
///int cargaNuevoEspecialidad(stEspecialidadMedica adl[], int validos, stEspecialidad e, stPaciente p);
int buscaPacienteEspecialidad(stEspecialidadMedica adl[], int v, char nombre[], char apellido[], char especialidad[]);
int buscaPacienteEnLista(nodo* lista, char nombre[], char apellido[], int flag);







#endif // ADL_H_INCLUDED
