#include "utilidades.h"

///MENU PRINCIPAL.

void menuPrincipal()
{
    printf("\t\t <<MENU PRINCIPAL>>");
    printf("\n\n");
    printf("1- Listado de clientes.\n");
    printf("\n2- Listado de consumos.\n");
    printf("\n\n");
    printf("ESC para salir...");
}

///MENU DE LA LISTA DE CLIENTES.

void menuClientes()
{
    printf("\t\tListado de clientes.");
    printf("\n\n");
    printf("1- Cargar un cliente nuevo...\n\n");
    printf("2- Mostrar lista de clientes...\n\n");
    printf("3- Modificar un cliente...\n\n");
    printf("4- Dar de baja/alta un cliente...\n\n");
    printf("5- Mostrar clientes ordenados por DNI (activos)...\n\n");
    printf("6- Mostrar clientes ordenados por Apellido (activos)...\n\n");
    printf("7- Buscar un cliente por DNI...\n\n");
    printf("8- Mostrar clientes ordenados por mail (inactivos)...\n\n");
    printf("\n\n");
    printf("ESC para salir...");


}
///MENU DE LA LISTA DE CONSUMOS

void menuConsumos()
{
    printf("\t\tConsumos.");
    printf("\n\n");
    printf("1- Carga un consumo... \n\n");
    printf("2- Muestra consumos...\n\n");
    printf("3- Modificar consumo... \n\n");
    printf("4- Dar de baja un consumo...\n\n");
    printf("5- Mostrar consumos por fecha...\n\n");
    printf("6- Cargar consumor random...\n\n");
    printf("7- Estadistica, Indica que mes se consume mas...");
    printf("\n\n");
    printf("ESC para salir...");
}

/// BUSCA UN RANGO AL AZAR, RECIBE EL PARAMETRO INFERIOR Y EL PARAMETRO SUPERIOR

int randomRango(int rangoMin,int rangoMax)
{
    int rango = rangoMin + rand() % (rangoMax +1 - rangoMin);
    return rango;
}

///funcion que intercambia  variables

void intercambio(stCliente *i, stCliente *menor)
{
    stCliente aux;

    aux = *menor;
    *menor = *i;
    *i = aux;
}

/***************************************
VALIDO EMAIL.
RECIBO STRING EMAIL.
RECORRO EL STRING LETRA POR LETRA
COMPRUEBO SI HAY UN "@", si hay flag=1
si no hay flag=-1
RETORNO FLAG. (VERDADERO O FALSO)
***************************************/
int validaEmail(char email[])
{
    int v=strlen(email);
    int i=0;
    int flag=0;
    while(i<v && flag==0)
    {
        if(email[i]==64)  ///64 ES "@" EN ASCII
        {
            flag=1;
        }
        i++;
    }
    return flag;
}

