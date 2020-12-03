#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "listaEmpleados.h"
#include "empleados.h"
#include "pilaLista.h"
#include "listaDoble.h"
#include "fila.h"
#include "arbol.h"

/*****//**
* \brief Funcion
* \param Recibe
* \return Retorna
*********/

///CONSTANTES

#define ESC 27

///PROTOTIPADOS

void muestraMenuPrincipal();
void muestraMenuLista();
void menuPila();
void menuListaDoble();
void MenuArchivo();
void menuFila();
void menuArbol();

int main()
{


    ///stEmpleado empleArch;
    nodoEmple* listaEmple = inicLista();

    char dni[25];
    int DNI = 0;
    int flag;

    Pila pila1;
    inicPila(&pila1);

    nodo2* listaDoble = inicListaDoble();
    stEmpleado primer;

    stEmpleado aBuscar;

    Fila* filita;
    inicFila(&filita);

    nodoArbol* arbolito = inicArbol();
    nodoArbol* encontrado = inicArbol();

    char nombre[25];

    char opcion = 0;
    char opcionArch = 0;
    char opcionLista = 0;
    char opcionPila = 0;
    char opcionFila = 0;
    char opcionListaDoble = 0;
    char opcionArbol = 0;

    do
    {
        system("cls");
        muestraMenuPrincipal();
        opcion=getch();
        system("cls");

        switch(opcion)
        {


        case 49:
///////////////////ARCHIVO/////////////////////////////////////////////////////////////////////////
            do
            {
                system("cls");
                MenuArchivo();
                opcionArch=getch();
                system("cls");
                switch(opcionArch)
                {
                case 49:
                    cargaEmpleados();
                    break;
                case 50:
                    muestraArchEmpleado();
                    opcion = getch();
                    break;
                case 51:

                    break;
                case 52:

                    break;
                }
            }
            while(opcionArch != ESC);
            break;
        case 50:
///////////////////LISTA/////////////////////////////////////////////////////////////////////////
            do
            {
                system("cls");
                muestraMenuLista();
                opcionLista=getch();
                system("cls");
                switch(opcionLista)
                {
                case 49:
                    listaEmple = archivoALista(AR_EMPLEADOS, listaEmple);
                    printf("La lista ya fue cargadan\n");
                    opcion = getch();
                    break;
                case 50:
                    printf("Esta es la lista de empleados:\n\n");
                    mostrarLista(listaEmple);
                    opcion = getch();
                    break;
                case 51:
                    listaEmple = borrarLista(listaEmple);
                    printf("La lista ya fue borrada\n\n"),
                           opcion = getch();

                    break;
                case 52:

                    listaEmple = archivoAListaOrdenadaDni(AR_EMPLEADOS, listaEmple);
                    printf("Esta es la lista ordenada por DNI:\n\n");
                    mostrarLista(listaEmple);
                    opcion = getch();

                    break;
                case 53:

                    printf("Ingrese DNI para realizar la busqueda: ");
                    fflush(stdin);
                    gets(dni);
                    flag = buscarNodoDNIFlag(listaEmple, dni);

                    if(flag == 1)
                    {
                        printf("La persona existe en la lista...");
                    }
                    else
                    {
                        printf("La persona NO existe en la lista...");
                    }

                    opcion = getch();

                    break;

                case 54:

                    listaEmple = invertirLista(listaEmple);
                    printf("Esta es la lista invertida:\n");
                    mostrarLista(listaEmple);
                    opcion = getch();

                    break;

                case 55:

                    pila2lista(&pila1, listaEmple);
                    printf("Ya se cargo la lista");
                    opcion = getch();

                    break;

                case 56:

                    printf("Esto son los nodos en sus posiciones pares:\n");
                    muestraNodosPares(listaEmple);
                    opcion = getch();

                    break;

                case 57:

                    listaEmple = invierteListaRecursiva(listaEmple);
                    printf("Se a invertido la lista de una manera recrusiva");
                    opcion = getch();

                    break;

                case 97:

                    printf("Ingrese DNI del empleado a borrar: ");
                    fflush(stdin);
                    gets(dni);
                    listaEmple = borroNodoRecrusivo(listaEmple, dni);
                    printf("Se a eliminado el empleado deseado");
                    opcion = getch();

                    break;

                case 98:

                    listaEmple = pila2ListaDniPares(listaEmple, pila1);
                    printf("Ya se a cargado la lista");
                    opcion = getch();

                    break;

                case 99:

                    printf("Esta es la lista invertida:\n");
                    mostrarListaRecursivaInvertida(listaEmple);
                    opcion = getch();

                    break;

                case 100:

                    listaEmple = arbol2lista(arbolito, listaEmple);
                    printf("La lista ya a sido cargada...");
                    opcion = getch();

                    break;
                }
            }
            while(opcionLista != ESC);
            break;
        case 51:
///////////////////PILA/////////////////////////////////////////////////////////////////////////
            do
            {
                system("cls");
                menuPila();
                opcionPila=getch();
                system("cls");
                switch(opcionPila)
                {

                case 49:

                    archivoAPila(AR_EMPLEADOS, &pila1);
                    printf("La Pila ya fue cargadan\n");
                    opcion = getch();

                    break;
                case 50:

                    printf("Esta es la Pila:\n");
                    muestraPila(&pila1);
                    opcion = getch();

                    break;

                case 51:

                    lista2pila(&pila1, listaEmple);
                    printf("se realizo el pasaje");
                    opcion = getch();

                    break;
                }
            }
            while(opcionPila != ESC);
            break;
        case 52:
///////////////////FILA/////////////////////////////////////////////////////////////////////////
            do
            {
                system("cls");
                menuFila();
                opcionFila=getch();
                system("cls");
                switch(opcionFila)
                {
                case 49:

                    archivoAFila(AR_EMPLEADOS, &filita);
                    printf("La fila se a cargado");
                    opcion = getch();

                    break;

                case 50:

                    printf("Esta es la fila:\n\n");
                    muestraFila(&filita);
                    opcion = getch();

                    break;

                case 51:

                    aBuscar = cargaUnEmpleado();
                    printf("Ta el empleado");
                    agregar(filita, aBuscar);
                    printf("Se a agregado el empleado");
                    opcion = getch();

                    break;

                }
            }
            while(opcionFila != ESC);
            break;

        case 53:
///////////////////LISTA DOBLE/////////////////////////////////////////////////////////////////////////
            do
            {
                system("cls");
                menuListaDoble();
                opcionListaDoble=getch();
                system("cls");
                switch(opcionListaDoble)
                {
                case 49:

                    listaDoble = archivoAListaDoble(AR_EMPLEADOS, listaDoble);
                    printf("La lista ya fue cargadan\n");
                    opcion = getch();

                    break;

                case 50:

                    printf("Esta es la lista doble:\n\n");
                    mostrarListaDoble(listaDoble);
                    opcion = getch();
                    break;

                case 51:

                    listaDoble = borrarListaDoble(listaDoble);
                    printf("La lista fue borrada");
                    opcion = getch();

                    break;

                case 52:

                    listaDoble = eliminaPrimerNodoDoble(listaDoble);
                    printf("Ahora el primer nodo es:\n");
                    primer = verPrimeroDoble(listaDoble);
                    muestraUnEmpleado(primer);
                    opcion = getch();

                    break;

                case 53:

                    listaDoble = eliminaUltimoNodoDoble(listaDoble);
                    printf("Se a eliminado el ultimo NODO");
                    opcion = getch();
                    break;

                case 54:

                    listaDoble = archivoAListaDobleDNI(AR_EMPLEADOS, listaDoble);
                    printf("Esta es la lista ordenada por DNI:\n");
                    mostrarListaDoble(listaDoble);
                    opcion = getch();

                    break;

                case 55:

                    printf("Ingrese DNI para realizar la busqueda: ");
                    ///scanf("%d", &DNI);
                    fflush(stdin);
                    gets(dni);
                    listaDoble = borrarNodoDobleDNI(listaDoble, dni);
                    printf("Ya se a eliminado el empleado que deseaba");
                    opcion = getch();

                    break;

                case 56:
                    printf("Ingrese DNI para realizar la busqueda: ");
                    fflush(stdin);
                    gets(dni);
                    aBuscar = buscaNodoDniDoble(dni, listaDoble);
                    printf("Este es el empleado buscado:\n");
                    muestraUnEmpleado(aBuscar);
                    opcion = getch();

                    break;

                }
            }
            while(opcionListaDoble != ESC);
            break;

        case 54:
///////////////////ARBOLES//////////////////////////////////////////////////////////////////////////////
            do
            {
                system("cls");
                menuArbol();
                opcionArbol=getch();
                system("cls");
                switch(opcionArbol)
                {
                case 49:

                    arbolito = archivo2Arbol(AR_EMPLEADOS, arbolito);
                    printf("El arbol a sido cargado");
                    opcion = getch();

                    break;

                case 50:

                    printf("Este es el arbol mostrado de manera preOrder\n\n");
                    preOrder(arbolito);
                    opcion = getch();

                    break;
                case 51:

                    printf("Este es el arbol mostrado de manera inOrder\n\n");
                    inOrder(arbolito);
                    opcion = getch();

                    break;
                case 52:

                    printf("Este es el arbol mostrado de manera postOrder\n\n");
                    postOrder(arbolito);
                    opcion = getch();

                    break;

                case 53:

                    printf("Ingrese el DNI a buscar: ");
                    fflush(stdin);
                    gets(dni);
                    system("cls");

                    encontrado = buscaNodoArbol(arbolito, dni);
                    if(encontrado)
                    {
                        printf("Este es el empleado que a buscado:\n\n");
                        muestraNodoArbol(encontrado);
                    }
                    else
                    {
                        printf("El cliente que busca no se encuentra...");
                    }
                    opcion = getch();

                    break;

                case 54:

                    printf("Ingrese el DNI del empleado a eliminar:");
                    fflush(stdin);
                    gets(dni);
                    arbolito = eliminarNodoArbolPro(arbolito, dni);
                    system("cls");
                    printf("Ya se elimino el empleado solicitado.");
                    opcion = getch();

                    break;

                case 55:

                    printf("Ingrese el nombre del empleado: ");
                    fflush(stdin);
                    gets(nombre);

                    encontrado = buscarPorNombre(arbolito, nombre);

                    system("cls");
                    printf("Este es el empleado buscado:\n");
                    muestraNodoArbol(encontrado);

                    opcion = getch();

                    break;

                case 56:

                    printf("Altura: %d\n", calcularAlturaArbol(arbolito));
                    opcion = getch();

                    break;



                    break;

                }
            }
            while(opcionArbol != ESC);

            break;

            system("pause");
        }
    }
    while (opcion != ESC);

    printf("Fin del programa");

    return 0;
}

void muestraMenuPrincipal()
{
    printf("\t\tESCOGA UNA OPCION\n\n");
    printf("1- Menu de archivos \n");
    printf("2- Menu de lista de empleados \n");
    printf("3- Menu de Pila (lista Dobles) \n");
    printf("4- Menu de Fila (lista Dobles) \n");
    printf("5- Menu de Lista Dobles\n");
    printf("6- Menu de arboles binarios\n");
    printf("ESC para salir... \n");
}

void MenuArchivo()
{
    printf("1-Para cargar un empleado en archivo\n");
    printf("2-Muestra archivo de empleados\n");
    printf("ESC para salir... \n");
}

void muestraMenuLista()
{
    printf("1-Paso de un archivo a una lista.\n");
    printf("2-Muestro lista.\n");
    printf("3-Borro lista \n");
    printf("4-Paso de archivo a lista ordenado por DNI y lo muestro\n");
    printf("5-Busca empleado por DNI\n");
    printf("6-Invierte la lista y la muestra\n");
    printf("7-Paso una pila a una lista\n");
    printf("8-Muestro nodos en su posicion PAR recursivo\n");
    printf("9-Invierto lista recrusivo\n");
    printf("A-Elimino nodo por DNI recursivo\n");
    printf("B-Paso de una pila a una lista aquellos empleados con DNI par\n");
    printf("C-Muestro lista invertida de manera recursiva\n");
    printf("D-Paso de un arbol a una lista\n");
    printf("ESC para salir...");
}

void menuPila()
{
    printf("1-Cargo pila con archivo de empleados\n");
    printf("2-Muestro Pila\n");
    printf("3-Paso de una lista a una pila\n");
    printf("ESC para salir...");
}

void menuFila()
{
    printf("1-Pasar archivo a fila\n");
    printf("2-Muestro la FILA\n");
    printf("3-Agregar un empleado a la fila\n");
    printf("ESC para salir... \n");
}

void menuListaDoble()
{
    printf("1-Paso de un archivo a una lista doble\n");
    printf("2-Muestro lista doble\n");
    printf("3-Borras lista doble\n");
    printf("4-Borras primer nodo lista doble\n");
    printf("5-Borras ultimo nodo lista doble\n");
    printf("6-Pasa de un archivo a una lista ordenado por DNI\n");
    printf("7-Eliminar empleado por DNI\n");
    printf("8-Busca empleado por DNI y lo muestra\n");
    printf("ESC para salir...");
}

void menuArbol()
{
    printf("1-Paso de un archivo a un arbol de empleados\n");
    printf("2-Muestro arbol de manera preOrder\n");
    printf("3-Muestro arbol de manera inOrder\n");
    printf("4-Muestro arbol de manera postOrder\n");
    printf("5-Busca nodo por DNI y lo muestra\n");
    printf("6-Elimino nodo por DNI\n");
    printf("7-Busco empleado por nombre y lo muestro\n");
    printf("8-Muestra la altura del arbol\n");
    printf("ESC para salir...");
}




