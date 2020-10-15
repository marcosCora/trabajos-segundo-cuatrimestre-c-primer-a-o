#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <time.h>
#include "utilidades.h"
#include "clientes.h"
#include "consumos.h"

///CONSTANTES

#define AR_CLIENTES "clientes.dat"
#define AR_CONSUMOS "consumos.dat"
#define ESC 27
#define DIM_CLI 100

int main()
{
    stCliente Lista[DIM_CLI];
    int vLista = 0;
    stConsumo Consumos[30];
    char opcion;
    char opcionCli;
    char opcionCon;
    int mesmax;
    int Array[mesmax];
    int vArreglo=1;
    int mes=0;
    srand (time(NULL));

    do
    {
        system("cls");
        menuPrincipal();
        opcion=getch();
        system("cls");
        switch(opcion)
        {
        case '1':
            do
            {
                system("cls");
                menuClientes();
                opcionCli=getch();
                system("cls");
                switch(opcionCli)
                {
                case '1':
                    cargarArchListaClientes();
                    break;
                case '2':
                    mostrarArchClientes();
                    printf("\n\n");
                    system("pause");
                    break;
                case '3':
                    encontrarClienteArch();
                    break;
                case '4':
                    funcion05();
                    printf("\n\n");
                    system("pause");
                    break;
                case '5':
                    ordenacionSeleccionArchivoDNI();
                    system("pause");
                    break;
                case '6':
                    ordenacionSeleccionArchivoApellido();
                    system("pause");
                    break;
                case '7':
                    muestraBuscaCliente();
                    system("pause");
                    break;
                case '8':
                    ordenacionSeleccionArchivoEmail();
                    system("pause");
                    break;

                }
            }
            while(opcionCli!=ESC);
            break;
        case '2':
            do
            {
                system("cls");
                menuConsumos();
                opcionCon=getch();
                system("cls");
                srand (time(NULL));
                switch(opcionCon)
                {

                case '1':
                    cargaArchListaConsumos();
                    system("cls");
                    break;

                case '2':
                    mostrarArchConsumos();
                    system("pause");
                    break;
                case '3':
                    modificacionConsumo();
                    break;
                case '4':
                    modificoBajaConsumo();
                    break;
                case '5':
                    preguntaFechaConsumo();
                    system("pause");
                    break;
                case '6':
                    CargaUnConsmoRandom();
                    system("pause");
                    break;
                case '7':

                    mesmax=buscarMesMAX();
                    vArreglo=cargarArreglo(Array,vArreglo,mesmax);
                    mostrarArreglo(Array,vArreglo);
                    system("pause");
                    system("cls");
                    mes=comprarMesMayor(Array,vArreglo);
                    printf("El mes con datos mas consumidos es %d.\n\n",mes);
                    system("pause");
                    break;

                }

            }
            while(opcionCon!=ESC);

        }
    }
    while(opcion!=ESC);

    return 0;
}
