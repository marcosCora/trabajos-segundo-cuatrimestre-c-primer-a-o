#include "fila.h"

void inicFila(Fila* fila)
{
    fila->inicio = inicListaDoble();
    fila->fin = inicListaDoble();
}

void agregar(Fila* fila, stPersona e)
{
    nodo2* nuevo = crearNodo(e);
    fila->fin = agregarAlFinalDoble(fila->fin, nuevo);

    if(fila->inicio == NULL)
    {
        fila->inicio = nuevo;
    }
    fila->fin = nuevo;
}

stPersona primero(Fila* fila)
{
    return verPrimeroDoble(fila->inicio);
}

stPersona extraer(Fila* fila)
{
    stPersona c;
    if(fila->inicio)
    {
        c = verPrimeroDoble(fila->inicio);
        fila->inicio = eliminaPrimerNodoDoble(fila->inicio);
        if(!fila->inicio)
        {
            fila->fin = inicListaDoble();
        }
    }
    return c;
}

int filaVacia(Fila* fila)
{
    int resp=0;
    if(!fila->inicio)    /// if(fila->inicio == NULL)
    {
        resp=1;
    }
    return resp;
}

int filaVaciaPro(Fila* fila)
{
    return (fila->inicio)?0:1;
}

void muestraFila(Fila* fila)
{
    mostrarListaDoble(fila->inicio);
}
