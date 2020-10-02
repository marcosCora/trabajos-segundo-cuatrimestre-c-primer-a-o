#ifndef PILALISTA_H_INCLUDED
#define PILALISTA_H_INCLUDED
#include "listaEmpleados.h"
#define Pila nodoEmple*

void inicPila(Pila* p);
int pilaVacia(Pila* p);
void apilar(Pila* p, stEmpleado e);
stEmpleado desapilar(Pila* p);
stEmpleado tope(Pila* p);



#endif // PILALISTA_H_INCLUDED
