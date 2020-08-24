///LIBRERIA PUNTO C
#include "Pila.h"


///recibe un puntero a la pila p
///se usa malloc para crear un arreglo de dimension 50
void inicPila(Pila *p)
{
    p->dato = malloc(sizeof(int)*50);
    p->validos = 0;
    p->dim = 50;
}

///recibe un puntero a pila y el valor el cual se le va a agregar
///se fija si tiene espacio la pila y si no tiene le agrega 50 mas de dimension
void apilar(Pila *p, int valor)
{
    if(p->validos == p->dim)
    {
        p->dim += 50;
        p->dato = realloc(p->dato, sizeof(int) * p->dim);
    }
    p->dato[p->validos] = valor;
    p->validos++;
}

///recibe puntero a la pila y le resta uno a los validos
int desapilar(Pila *p)
{
    int aux = p->dato[p->validos-1];
    p->validos--;
    return aux;
}

///recibe la pila y retorna el ultimo numero agregado
int tope(Pila p)
{
    int top = p.dato[p.validos-1];
    return top;
}

///recibe la pila
///si retorna 0 la pila esta vacia
int pilaVacia(Pila p)
{
    int flag = 1;

    if(p.validos > 0)
    {
        flag =  0;
    }

    return flag;///si retorna 0 significa que la pila esta vacia
}

///recibe un puntero a pila
///le pide un numero al usuario
///llama a la funcion de apilar
void leer(Pila *p)
{
    int aux;
    printf("Ingrese un numero..: ");
    scanf("%d", &aux);
    apilar(p, aux);
}

///recibe la pila y la muestra
void mostrar(Pila p)
{
    int i = 0;
    printf("BASE------------------------------------------TOPE\n");
    while(i < p.validos)
    {
        printf("%d -", p.dato[i]);
        i++;
    }
    printf("\nBASE------------------------------------------TOPE\n");
}

///LIBRERIA PUNTO H
#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

typedef struct
{
    int *dato;
    int validos;
    int dim;

}Pila;

void inicPila(Pila *p);
void apilar(Pila *p, int valor);
int desapilar(Pila *p);
int tope(Pila p);
int pilaVacia(Pila p);
void leer(Pila *p);
void mostrar(Pila p);


#endif // PILA_H_INCLUDED





