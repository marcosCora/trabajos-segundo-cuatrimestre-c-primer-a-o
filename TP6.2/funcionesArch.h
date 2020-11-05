#ifndef FUNCIONESARCH_H_INCLUDED
#define FUNCIONESARCH_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "arbol.h"

#define ESC 27
#define AR_ANIMALES "animales.dat"
typedef struct
{
    char animal[30];
    int cant;
    int habitat;
    int idEspecie;
    char especie[20];
} registroArchivo;


void guardaRegistroArchivo(char nombreArch[], registroArchivo r);
void mostrarUnRegistro (registroArchivo r);
void muestraArchivoDeRegistros(char archivo[]);





#endif // FUNCIONESARCH_H_INCLUDED
