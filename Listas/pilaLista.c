#include "pilaLista.h"

void inicPila(Pila* p)
{
    (*p) = inicLista();///retorna NULL
}

int pilaVacia(Pila* p)
{
    int rta = 0;

    if((*p) == NULL)
    {
        rta = 1;
    }

    return rta;
}

void apilar(Pila* p, stEmpleado e)
{
    (*p) = agregarAlPrincipio((*p), crearNodo(e));
}

stEmpleado desapilar(Pila* p)
{
    stEmpleado e = verPrimero(p);///(*p)
    (*p) = eliminaPrimerNodo((*p));
    return e;
}


stEmpleado tope(Pila* p)
{
    return verPrimero(*p);
}
