///ESTO VA JUNTO A LAS LIBERIAS DE PILAS .C Y .H

#include <stdio.h>
#include <stdlib.h>
#include "Pila.h"

int main()
{

    Pila p1, p2;
    inicPila(&p1);
    inicPila(&p2);
    int dato = 0;
    int tope1 = 0;
    int vacia = 0;
    int cont = 0;

    if(pilaVacia(p1))
    {
        printf("la pila esta vacia...\n\n");
    }
    else
    {
        printf("La pila no esta vacia...\n\n");
    }


    leer(&p1);
    leer(&p1);
    leer(&p1);

    apilar(&p1, 14);

    printf("\n\n");

    muestraPila(p1);

    printf("\n\n");

    dato = desapilar(&p1);
    muestraPila(p1);

    tope1 = tope(p1);
    printf("\n\nEste es el tope: %d", tope1);

    printf("\n\n");

    ///vacia = pilaVacia(p1);

    if(pilaVacia(p1))
    {
        printf("la pila esta vacia..\n");
    }
    else
    {
        printf("La pila no esta vacia...\n");
    }

    printf("\n");

    cont = cuentaPila(p1);
    printf("\nContiene %d elementos.", cont);

    printf("\n\n");

    muevoPila(&p1, &p2);
    printf("\nPila 1:\n");
    muestraPila(p1);
    printf("\n\n");
    printf("\nPila 2:\n");
    muestraPila(p2);

    copioPila(p2, &p1);
    printf("\nPila 1:\n");
    muestraPila(p1);
    printf("\nPila 2:\n");
    muestraPila(p2);

    printf("\n\n\n");


    return 0;
}


