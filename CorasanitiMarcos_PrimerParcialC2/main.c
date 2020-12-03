#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include "persona.h"
#include "listaEmpleados.h"
#include "listaDoble.h"
#include "fila.h"

nodo* archivo2lista (char nombreArchivo[], nodo* lista);
int sumarValorListaR(nodo* lista);
int retornarUltimoValorDni(char dni[]);
int  menorPersona(nodo * lista, int edad );
void listaTofila(nodo* lista, Fila* fila, char letra);
///int cuentaEdadesMayores(nodo* lista, int mayor, int cont);
///int cuentaEdadesMayores (nodo* lista, int edad);
int CantPersonasPorEdad (nodo* lista, int edad);
int PersonaMayoraXEdad (stPersona persona, int edad);


int main()
{
    char opcion;
    int sumaEdades;
    int menorEdad;
    int edadesMayor;

    nodo* listaSimple = inicLista();
    Fila* filita;
    inicFila(&filita);
    char letra;

    ///EJERCICIO 1

    listaSimple = archivo2lista(AR_PERSONAS, listaSimple);
    printf("Esta es la lista ordenada por DNI:\n\n");
    mostrarLista(listaSimple);
    opcion = getch();
    system("cls");

    ///EJERCICIO 2

    sumaEdades = sumarValorListaR(listaSimple);
    printf("Esta es la suma de las edades: %d", sumaEdades);
    opcion = getch();
    system("cls");

    ///EJERCICIO 3

    menorEdad = menorPersona(listaSimple, menorEdad);
    printf("Esta es la menor edad: %d", menorEdad);
    opcion = getch();
    system("cls");

    ///EJERCICIO 4

    printf("Ingrese la letra: ");
    scanf("%c", &letra);
    listaTofila(listaSimple, &filita, letra);
    muestraFila(&filita);
    opcion = getch();
    system("cls");

    ///EJERCICIO 5

    ///edadesMayor = CantPersonasPorEdad(listaSimple, edadesMayor);
    ///printf("Edades mayores a : %d", edadesMayor);
    ///opcion = getch();
    ///system("cls");

    return 0;
}



///EJERCICIO 1
nodo* archivo2lista (char nombreArchivo[], nodo* lista)
{
    FILE *archi = fopen(nombreArchivo, "rb");
    stPersona e;
    if(archi)
    {
        while(fread(&e, sizeof(stPersona),1,archi) > 0)
        {
            lista = agregarOrdenadoApellido(lista,crearNodo(e));
        }
        fclose(archi);
    }
    return lista;
}


///EJERCICIO 2
int sumarValorListaR(nodo* lista)
{
    int suma=0;
    if(lista)
    {
        if ((retornarUltimoValorDni (lista->dato.dni)   %2 == 0) && (lista->dato.edad >= 18))
        {
            suma = lista->dato.edad + sumarValorListaR (lista->siguiente);
        }
        else
        {
            suma = sumarValorListaR (lista->siguiente);
        }
    }
    return suma;
}

int retornarUltimoValorDni(char dni[])
{
    int dim = strlen(dni);
    int ultimo = (int) dni[dim-1];
    return ultimo;
}

///EJERCICIO 3

int  menorPersona(nodo * lista, int edad)
{
    edad=100;
    if(lista)
    {
        edad = menorPersona(lista->siguiente,edad);
        if(lista->dato.edad <= edad)
        {
            edad = lista->dato.edad;
        }
    }
    return edad;
}

///ejercicio 4

void listaTofila(nodo* lista, Fila* fila, char letra)
{
    while(lista != NULL)
    {
        if(strcmpi(lista->dato.apellido[0],letra)==0)
        {

            agregar(fila, lista->dato);
        }

        lista = lista->siguiente;
    }
}

///EJERCICIO 5

int CantPersonasPorEdad (nodo* lista, int edad)
{
    int total;
    if ((lista)==NULL)
    {
        total =0;
    }
    else
    {
        if (PersonaMayoraXEdad(lista->dato, edad)==1)
        {
            total = total + 1;
        }
        retornarCantPersonasPorEdad(lista->siguiente, edad);

    }
    return total;
}

int PersonaMayoraXEdad (stPersona persona, int edad)
{
    int cont =0;

    if (persona.edad>edad)
    {
        cont = 1;
    }
    return cont;
}

///EJERCICIO 6

float porcentaje (nodo*lista, int edad)
{
    nodo*aux = lista;
    int personasmayores = 0;
    int cantpersonas = 0;
    float porcentaje = 0;
    while (aux!= NULL)
    {
        if (PersonaMayoraTalEdad(aux->dato, edad)==1)
        {
            personasmayores++;
        }
        aux=aux->siguiente;
        cantpersonas++;
    }
    porcentaje = ((float)personasmayores/(float)cantpersonas) ;
    return porcentaje;
}
*/




