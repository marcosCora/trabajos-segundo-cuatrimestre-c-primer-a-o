#include "fila.h"

void inicFila(Fila* fila){
    fila->inicio = iniciLista2();
    fila->fin = iniciLista2();
}

void agregar(Fila* fila, stEmpleado e){
    nodo2* nuevo = crearNodo2(e);
    fila->fin = agregarAlFinal2(fila->fin,nuevo);
    if(fila->inicio==NULL){
        fila->inicio=nuevo;
    }
    fila->fin = nuevo;
}

stEmpleado extraer(Fila* fila){
    stEmpleado e;
    if(fila->inicio){
        e = verPrimero2(fila->inicio);
        fila->inicio = EliminarPrimerNodo2(fila->inicio);
        if(!fila->inicio){
            fila->fin = iniciLista2();
        }
    }
    return e;
}

int filaVacia(Fila* fila){
    int resp=0;
    if(!fila->inicio){
        resp=1;
    }
    return resp;
}

int filaVaciaPro(Fila* fila){
    return (fila->inicio)?0:1;
}

void muestraFila(Fila* fila){
    mostrarLista2(fila->inicio);
}
