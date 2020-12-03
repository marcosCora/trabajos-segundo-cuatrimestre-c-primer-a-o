#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <conio.h>

#include "registroArchivo.h"
#include "adl.h"


int main()
{

    stEspecialidadMedica adl[25];
    int vAdl = 0;

    ///EJERCICIO 1

    vAdl = archivo2adl(arRegistro, adl, vAdl, 25);
    printf("Se cargo el arreglo...\n");
    system("pause");
    system("cls");

    ///EJERCICIO 6

    printf("\nEste es el arreglo de listas medicas\n");
    muestraADL(adl, vAdl);
    system("pause");
    system("cls");

    ///EJERCICIO 2

    /*vAdl = cargaNuevaEspecialidad(adl, vAdl, 25);
    printf("\nEste es el arreglo de listas medicas\n");
    muestraADL(adl, vAdl);
    system("pause");
    system("cls");*/

    ///BUSCA ESPECIALIDAD EN ARREGLO RETORNA -1 SI NO EXISTE
    ///EJERCICIO 3

    /*int flag = 0;
    char especialidad[30];
    printf("Ingrese la especialidad a buscar: ");
    fflush(stdin);
    gets(especialidad);

    if(buscaPosicionArregloEspecialidad(adl, vAdl, especialidad) == -1)
    {
        printf("La especialidad no existe\n");
        system("pause");

    }
    else
    {
        printf("La especialidad  existe\n");
        system("pause");
    }*/


    ///EJERCICIO 7

    char nombre[30];
    char apellido[30];
    char especialidad[30];
    int flag = 0;

    printf("Ingrese la especialidad en la que desea buscar el paciente: ");
    fflush(stdin);
    gets(especialidad);

    printf("Ingrese el nombre del paciente a buscar: ");
    fflush(stdin);
    gets(nombre);
    printf("Ingrese el apellido del paciente a buscar: ");
    fflush(stdin);
    gets(apellido);
    flag = buscaPacienteEspecialidad(adl, vAdl, nombre, apellido, especialidad);

    if(flag == 1)
    {
        printf("El pasiente se encunetra en la especialidad que deseo buscar...\n");
        system("pause");
    }
    else
    {
        printf("El pasiente no se encuntra en esa especialidad...\n");
        system("pause");
    }



    return 0;
}








