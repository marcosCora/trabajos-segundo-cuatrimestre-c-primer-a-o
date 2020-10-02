#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "listaEmpleados.h"
#include "empleados.h"
#include "pilaLista.h"
#include "listaDoble.h"
#include "fila.h"

///CONSTANTES

#define ESC 27

///PROTOTIPADOS

void muestraMenuPrincipal();
void muestraMenuLista();
void menuPila();
void menuListaDoble();
void MenuArchivo();
void menuFila();




nodoEmple* archivoALista(char nombreArch[], nodoEmple* lista);
nodoEmple* archivoAListaOrdenadaDni(char nombreArch[], nodoEmple* lista);
int buscarNodoDNIFlag (nodoEmple * lista, char dni [30]);
nodoEmple* intercalarLista (nodoEmple * listaA, nodoEmple * listaB, nodoEmple * listaDestino);


void archivoAPila(char nombreArch[], Pila* p);
void muestraPila(Pila p);
void pila2Lista(Pila p, nodoEmple** lista);

nodo2* archivoAListaDoble(char nombreArch[], nodo2* lista);
nodo2* archivoAListaDobleDNI(char nombreArch[], nodo2* lista);

int main()
{

    ///stEmpleado empleArch;
    nodoEmple* listaEmple = inicLista();

    char dni[25];
    ///int DNI = 0;
    int flag;

    Pila pila1;
    inicPila(&pila1);

    nodo2* listaDoble = inicListaDoble();
    stEmpleado primer;

    stEmpleado aBuscar;

    Fila* filita;
    inicFila(&filita);

    char opcion = 0;
    char opcionArch = 0;
    char opcionLista = 0;
    char opcionPila = 0;
    char opcionFila = 0;
    char opcionListaDoble = 0;
    do {
        system("cls");
        muestraMenuPrincipal();
        opcion=getch();
        system("cls");

            switch(opcion){


            case 49:
///////////////////ARCHIVO/////////////////////////////////////////////////////////////////////////
                do{
                system("cls");
                MenuArchivo();
                opcionArch=getch();
                system("cls");
                switch(opcionArch){
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
                }while(opcionArch != ESC);
                break;
            case 50:
///////////////////LISTA/////////////////////////////////////////////////////////////////////////
                do{
                system("cls");
                muestraMenuLista();
                opcionLista=getch();
                system("cls");
                switch(opcionLista){
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
                }
                }while(opcionLista != ESC);
                break;
            case 51:
///////////////////PILA/////////////////////////////////////////////////////////////////////////
                do{
                system("cls");
                menuPila();
                opcionPila=getch();
                system("cls");
                switch(opcionPila){

                    case 49:

                        archivoAPila(AR_EMPLEADOS, &pila1);
                        printf("La Pila ya fue cargadan\n");
                        opcion = getch();

                        break;
                    case 50:

                        printf("Esta es la Pila:");
                        muestraPila(pila1);
                        opcion = getch();

                        break;

                    case 51:

                        lista2pila(&pila1, listaEmple);
                        printf("se realizo el pasaje");
                        opcion = getch();

                        break;
                }
                }while(opcionPila != ESC);
                break;
            case 52:
///////////////////FILA/////////////////////////////////////////////////////////////////////////
                do{
                system("cls");
                menuFila();
                opcionFila=getch();
                system("cls");
                switch(opcionFila){
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
                }while(opcionFila != ESC);
                break;

            case 53:
///////////////////LISTA DOBLE/////////////////////////////////////////////////////////////////////////
                do{
                system("cls");
                menuListaDoble();
                opcionListaDoble=getch();
                system("cls");
                switch(opcionListaDoble){
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
                }while(opcionListaDoble != ESC);
                break;

            system("pause");
    }
    }while (opcion != ESC);

    printf("Fin del programa");

    return 0;
}

void muestraMenuPrincipal()
{
    printf("\t\tESCOGA UNA OPCION\n\n");
    printf("1- menu de archivos \n");
    printf("2- menu de lista de empleados \n");
    printf("3- menu de Pila (lista Dobles) \n");
    printf("4- menu de Fila (lista Dobles) \n");
    printf("5- menu de Lista Dobles\n");
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



