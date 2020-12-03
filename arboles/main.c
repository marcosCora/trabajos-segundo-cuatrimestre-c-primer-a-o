#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#include "arbol.h"

int DibujarArbolLinea(nodoArbol * arbol, int esIzq, int inicia, int nivel, char s[20][255]);
int DibujarArbol(nodoArbol * arbol);
int sumaArbolRecursiva(nodoArbol* arbol);


int main()
{

    nodoArbol* arbolito = inicArbol();
    int suma = 0;

    arbolito = insertar(arbolito, creaNodoArbol(8));
    arbolito = insertar(arbolito, creaNodoArbol(7));
    arbolito = insertar(arbolito, creaNodoArbol(10));
    arbolito = insertar(arbolito, creaNodoArbol(2));
    arbolito = insertar(arbolito, creaNodoArbol(9));
    arbolito = insertar(arbolito, creaNodoArbol(12));
    arbolito = insertar(arbolito, creaNodoArbol(15));
    arbolito = insertar(arbolito, creaNodoArbol(6));

    printf("PRE ORDER:\n");
    preOrder(arbolito);
    printf("\nIN ORDER:\n");
    inOrder(arbolito);
    printf("\nPOS ORDER:\n");
    postOrder(arbolito);

    suma = sumaArbolRecursiva(arbolito);
    printf("\n\nEsta es la suma del arbol: %d", suma);

    ///DibujarArbol(arbolito);

    return 0;
}

int DibujarArbolLinea(nodoArbol* arbol, int esIzq, int inicia, int nivel, char s[20][255])
{
    char b[10];
    int ancho = 4; //es el ancho del nodo que dibujo
    int i;

    if (!arbol)
    {
        return 0;

    }

    sprintf(b, "(%d)", arbol->dato); // agrego valor de nodo a la matriz

    int izq  = DibujarArbolLinea(arbol->izq,  1, inicia,                nivel + 1, s);
    int der = DibujarArbolLinea(arbol->der, 0, inicia + izq + ancho, nivel + 1, s);

    //dibujo nodo
    for (i = 0; i < ancho; i++)
    {
        s[2 * nivel][inicia + izq + i] = b[i];
    }


    //dibujo lineas .----+----.
    if (nivel && esIzq)
    {

        for (i = 0; i < ancho + der; i++)
        {
            s[2 * nivel - 1][inicia + izq + ancho/2 + i] = '-';
        }


        s[2 * nivel - 1][inicia + izq + ancho/2] = '.';
        s[2 * nivel - 1][inicia + izq + ancho + der + ancho/2] = '+';

    }
    else if (nivel && !esIzq)
    {

        for (i = 0; i < izq + ancho; i++)
        {
            s[2 * nivel - 1][inicia - ancho/2 + i] = '-';
        }

        s[2 * nivel - 1][inicia + izq + ancho/2] = '.';
        s[2 * nivel - 1][inicia - ancho/2 - 1] = '+';
    }

    //Cerebros quemados everywere!!
    return izq + ancho + der;
}

int DibujarArbol(nodoArbol* arbol)
{
    char s[10][255];
    int i;
    //creo una matriz de char para hacer mi "dibujo"
    for (i = 0; i < 10; i++)
    {
        sprintf(s[i], "%80s", " ");
    }


    //Hago magia
    DibujarArbolLinea(arbol, 0, 0, 0, s);

    //Imprimo matris

    for (i = 0; i < 10; i++)
    {
        printf("\t\t\t%s\n", s[i]);
    }

}

/*
int nivelArbol(nodoArbol* arbol)
{
    int nivel = -1
    nodoArbol* aux = arbol;

    while(arbol)
    {

    }



    return nivel;
}
*/

int sumaArbolRecursiva(nodoArbol* arbol)
{
    int suma;

    if(!arbol)
    {
        suma = 0;
    }
    else
    {
        suma = arbol->dato + sumaArbolRecursiva(arbol->izq) + sumaArbolRecursiva(arbol->der);
    }
    return suma;
}







