#include "pila.h"


void inicPila (Pila **p){
    (*p) = inicLista(); ///a lo que apunta (un puntero) P retornamos NULL (apunta a NULL)
}

int pilaVacia (Pila ** p){
    int rta =0;
    if ((*p==NULL)){
        rta=1;
    }
    return rta;
}

int pilaVaciaPro(Pila **p){
    return ((*p)==NULL) ?1:0; ///si es veradera retornamos 1, sino retorna 0
}

void apilar(Pila ** p, stEmpleado e){
    (*p)=agregarAlPrincipio((*p),crearNodo(e)); /// a la lista P le pasamos agregar al principio el dato que ya recibimos por parametro
}

void apilarPD(Pila* p, stEmpleado e){
    agregarAlPrincipioPD(p,crearNodo(e));
}

stEmpleado desapilar(Pila* p){
    stEmpleado e = verPrimero(p); ///agarramos el primer dato de la lista
    (*p) = eliminaPrimerNodo(*p); ///eliminamos el primero
    return e; ///retornamos el primero
}

stEmpleado tope(Pila* p){
    return verPrimero(*p);
}

void muestraPila(Pila p){
    Pila aux;
    inicPila(&aux);
    while(!pilaVacia(&p)){
        mostrarUnEmpleado(tope(&p));
        apilar(&aux, desapilar(&p));
    }
}
