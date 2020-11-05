#ifndef ADL_H_INCLUDED
#define ADL_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "listasRegistros.h"

#define AR_REGISTROS "registros.dat"
#define AR_APROBADOS "aprobados.dat"
#define ESC 27

typedef struct
{
    int nota;
    int legajo;
    char nombreApe[30];
    char materia[30];
    int idMateria;
} registroArchivo;

registroArchivo cargaUnRegistro();
void guardaRegistroArchivo(char nombreArch[], registroArchivo r);
void ingresaRegistrosArchivo();
void mostrarUnRegistro (registroArchivo r);
void muestraArchivoDeRegistros(char archivo[]);





#endif // ADL_H_INCLUDED
