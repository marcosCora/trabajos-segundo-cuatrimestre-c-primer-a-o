#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "ADL.h"
#include "listasRegistros.h"

#define DIM 70

void muestraMenu();
int buscaPosicionMateria(stCelda adl[], int v, char materia[]);
int agregar(stCelda adl[], int v, char materia[], int idMateria);
int alta(stCelda adl[], int v, notaAlumno n, char materia[], int idMateria);
int archivo2adl(char archivo[], stCelda adl[], int v, int dim);
void muestraADL (stCelda adl[], int v);
void ADL2ArchAprobados(char nombreArch[], stCelda adl[], int v);



int main()
{
    char opcion;
    stCelda adl[DIM];
    int vAdl = 0;

    do
    {
        system("cls");
        muestraMenu();
        opcion = getch();
        system("cls");

        switch(opcion)
        {
        case 49:

            ingresaRegistrosArchivo();

            break;
        case 50:

            muestraArchivoDeRegistros(AR_REGISTROS);
            opcion = getch();

            break;
        case 51:

            vAdl = archivo2adl(AR_REGISTROS, adl, vAdl, DIM);
            printf("Se ha realizado el pasaje de datos.\n");
            opcion = getch();

            break;
        case 52:

            printf("Este es el arreglo de listas:\n\n");
            muestraADL(adl, vAdl);
            opcion = getch();

            break;
        case 53:

            ADL2ArchAprobados(AR_APROBADOS, adl, vAdl);
            printf("Este es el archivo de aprobados:\n");
            muestraArchivoDeRegistros(AR_APROBADOS);
            opcion = getch();

            break;
        case 54:

            break;
        case 55:

            break;
        case 56:

            break;
        }

    }
    while(opcion != ESC);



    return 0;
}


void muestraMenu()
{
     printf("\t\tESCOGA UNA OPCION\n\n");
    printf("1- Carga un registro en un archivo \n");
    printf("2- Muestra registros \n");
    printf("3- Pasa de un archivo a un arreglo de ADL \n");
    printf("4- Muestra ADL \n");
    printf("5- Pasa alumnos aprobados a archivo de aprobados\n");
    printf("6- \n");
    printf("ESC para salir... \n");

}

/*****//**
* \brief Funcion que retorna la posicion de una materia en el arreglo
* \param Recibe el arreglo, validos, la materia a buscar
* \return Retorna -1 si la materia no existe
*********/
int buscaPosicionMateria(stCelda adl[], int v, char materia[])
{
    int pos = -1;
    int i =0;
    while(i<v && pos == -1)
    {
        if(strcmpi(adl[i].materia,materia)==0)
        {
            pos = i;
        }
        i++;
    }
    return pos;
}


/*******//**
* \brief Funcio que agrega una materia al arreglo stCelda
* \param Recibe el arreglo, los validos y la materia a agregar
* \return Retorna los validos
*********/
int agregar(stCelda adl[], int v, char materia[], int idMateria)
{
    strcpy(adl[v].materia,materia); ///en la primer pos libre copiamos la materia en el arreglo
    adl[v].idMateria = idMateria;
    adl[v].listaDeNotas = inicLista(); ///inicio lista
    v++;
    return v;
}


/*******//**
* \brief Funcio
* \param Recibe el arreglo, un alumno, materia y ID de materia
* \return Retorna los validos
*********/
int alta(stCelda adl[], int v, notaAlumno n, char materia[], int idMateria)
{


    nodo* aux = crearNodo(n);
    int pos = buscaPosicionMateria(adl,v,materia);
    if(pos == -1)
    {
        v = agregar(adl,v,materia, idMateria);
        pos = v - 1;
    }
    adl[pos].listaDeNotas = agregarAlFinal(adl[pos].listaDeNotas, aux);
    return v;
}


int archivo2adl(char archivo[], stCelda adl[], int v, int dim)
{
    registroArchivo r;
    notaAlumno n;
    int idMateria;
    char materia[30];

    FILE* archi = fopen(archivo, "rb");
    if(archi)
    {
        while(v<dim && fread(&r,sizeof(registroArchivo),1,archi)>0)
        {
            idMateria = r.idMateria;
            strcpy(materia, r.materia);
            n.legajo = r.legajo;
            strcpy(n.nombreApe, r.nombreApe);
            n.nota = r.nota;
            v = alta(adl, v, n, materia, idMateria);
        }

        fclose(archi);
    }

    return v;
}


void muestraADL (stCelda adl[], int v)
{
    int i=0;
    while(i<v)
    {
        printf("-------------------------------------------------------\n");
        printf("\nID materia.....: %d\n", adl[i].idMateria);
        printf("Materia........: %s\n", adl[i].materia);
        mostrarLista(adl[i].listaDeNotas);
        i++;
    }
}

void ADL2ArchAprobados(char nombreArch[], stCelda adl[], int v)
{
    int i = 0;
    registroArchivo r;

    for(i = 0; i < v ; i++)
    {
        r.idMateria = adl[i].idMateria;
        strcpy(r.materia, adl[i].materia);
        nodo* seg = adl[i].listaDeNotas;
        while(seg)
        {
            r.legajo = seg->dato.legajo;
            r.nota = seg->dato.nota;
            strcpy(r.nombreApe, seg->dato.nombreApe);
            if(seg->dato.nota > 5)
            {
                guardaRegistroArchivo(nombreArch, r);
            }
            seg = seg->siguiente;


        }
    }

}






