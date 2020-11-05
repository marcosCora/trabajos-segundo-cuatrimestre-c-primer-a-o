#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "funcionesArch.h"
#include "arbol.h"

#define DIM 50
#define AR_ANIMALES2 "animales2.dat"


void muestraMenu();
int buscaPosEspecie(stCeldaEspecie ada[], int v, char especie[]);
int agregar(stCeldaEspecie ada[], int v, char especie2[], int idEspecie);
int alta(stCeldaEspecie ada[], int v, animal a, char especie[], int idEspecie);
int archivo2ada(char archivo[], stCeldaEspecie ada[], int v, int dim);
void muestraADA (stCeldaEspecie ada[], int v);
void ADAToArchAnimales (char nombreArch[], stCeldaEspecie ada[], int v);
void arbol2arch(char nombreArch[], nodoArbol* arbol);
void mostrarArchivoAnimales2(char nombreArch[]);


int main()
{
    char opcion;
    stCeldaEspecie ada[DIM];
    int vAda = 0;


    do
    {
        system("cls");
        muestraMenu();
        opcion = getch();
        system("cls");

        switch(opcion)
        {
        case 49:

            printf("Este es el archivo de animales:\n");
            muestraArchivoDeRegistros(AR_ANIMALES);
            opcion = getch();

            break;
        case 50:

            vAda = archivo2ada(AR_ANIMALES, ada, vAda, DIM);
            printf("Se a relizado el pasaje de datos\n");
            opcion = getch();

            break;
        case 51:

            printf("Este es el ARREGLO DE ARBOLES:\n");
            muestraADA(ada, vAda);
            opcion = getch();

            break;
        case 52:

            ADAToArchAnimales(AR_ANIMALES2, ada, vAda);
            printf("Se a relizado el pasaje de datos\n");
            opcion = getch();

            break;
        case 53:

            printf("Este es el archivo de animales 2:\n");
            mostrarArchivoAnimales2(AR_ANIMALES2);
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
    printf("1- Muestra archivo de animales \n");
    printf("2- Paso de archivo a ADA \n");
    printf("3- Muestro ADA \n");
    printf("4- Paso de ADA a archivo de animales 2 \n");
    printf("5- \n");
    printf("6- \n");
    printf("ESC para salir... \n");

}

/*****//**
* \brief Funcion que retorna la posicion de una especie en un arreglo
* \param Recibe el arreglo, validos, la especie a buscar
* \return Retorna -1 si la materia no existe
*********/
int buscaPosEspecie(stCeldaEspecie ada[], int v, char especie[])
{
    int i = 0;
    int pos = -1;

    while(i < v && pos == -1)
    {
        if(strcmpi(ada[i].especie, especie)==0)
        {
            pos = i;
        }
        i++;
    }

    return pos;
}

/*******//**
* \brief Funcio que agrega una especie al arreglo stCelda
* \param Recibe el arreglo, los validos y la especie a agregar
* \return Retorna los validos
*********/
int agregar(stCeldaEspecie ada[], int v, char especie2[], int idEspecie)
{

    strcpy(ada[v].especie, especie2);
    ada[v].idEspecie = idEspecie;
    ada[v].arbolDeAnimales = inicArbol();
    v++;

    return v;
}


int alta(stCeldaEspecie ada[], int v, animal a, char especie[], int idEspecie)
{

    nodoArbol* aux = crearNodoArbol2(a);
    int pos = buscaPosEspecie(ada, v, especie);

    if(pos == -1)
    {
        v = agregar(ada, v, especie, idEspecie);
        pos = v - 1;
    }
    ada[pos].arbolDeAnimales = insertar(ada[pos].arbolDeAnimales, aux);

    return v;
}

int archivo2ada(char archivo[], stCeldaEspecie ada[], int v, int dim)
{
    registroArchivo r;
    animal a;
    char especie[30];
    int idEspecie;

    FILE* arch = fopen(archivo, "rb");

    if(arch)
    {
        while(v < dim && fread(&r, sizeof(registroArchivo), 1, arch) > 0)
        {

            strcpy(especie, r.especie);
            idEspecie = r.idEspecie;
            a.cantidad = r.cant;
            strcpy(a.nombreAnimal, r.animal);
            a.habitat = r.habitat;
            v = alta(ada, v, a, especie, idEspecie);

        }
        fclose(arch);
    }


    return v;
}


void muestraADA (stCeldaEspecie ada[], int v)
{
    int i=0;
    while(i < v)
    {
        printf("-------------------------------------------------------\n");
        printf("\n ID ESPECIE.....: %d\n", ada[i].idEspecie);
        printf(" ESPECIE........: %s\n", ada[i].especie);
        inOrder(ada[i].arbolDeAnimales);
        i++;
    }
}

void ADAToArchAnimales (char nombreArch[], stCeldaEspecie ada[], int v)
{
    int i =0;
    animal d;

    for (i=0; i<v; i++)
    {
        nodoArbol* seg = ada[i].arbolDeAnimales;
        arbol2arch(nombreArch, seg);
    }
}


void arbol2arch(char nombreArch[], nodoArbol* arbol)
{
    nodoArbol* aux = arbol;
    animal a;

    FILE* arch = fopen(nombreArch, "ab");

    if(arch)
    {
        if(aux)
        {
            a = aux->dato;
            a.cantidad = 1;
            fwrite(&a, sizeof(animal), 1, arch);
            arbol2arch(nombreArch, arbol->izq);
            arbol2arch(nombreArch, arbol->der);
        }

        fclose(arch);
    }

}

void mostrarArchivoAnimales2(char nombreArch[])
{
    animal a;
    FILE* arch = fopen(nombreArch, "rb");

    if(arch)
    {
        while(fread(&a, sizeof(animal), 1, arch) > 0)
        {
            muestraUnAnimal(a);
        }

        fclose(arch);
    }
}



