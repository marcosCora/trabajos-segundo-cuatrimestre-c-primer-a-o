#include "listaEmpleados.h"


nodo* inicLista()///recibo la lista
{
    return NULL;///retorno la lista en NULL
}

nodo* crearNodo(stPersona dato)///recibo el dato el cual se creara un nodo
{
    nodo* nuevo = (nodo*) malloc(sizeof(nodo));///creo un puntero a la estructura de nodo y lo inicializo
    nuevo->dato = dato;///agrego el dato recibido al nodo creado
    nuevo->siguiente = NULL;///inicializo el nodo siguente en NULL
    return nuevo;///retorno el nodo
}

nodo* agregarAlPrincipio(nodo* lista, nodo* nuevoNodo)///recibo una lista, y el nodo a agregar a esa lista
{
    if(lista == NULL)///si la lista en igual a NULL significa que es la primera
    {
        lista = nuevoNodo;///agregamos directamente el nuevo nodo a la lista
    }
    else
    {
        nuevoNodo->siguiente = lista;///le asigno la direccion de memoria de la lista siguiente a la nueva lista
        lista = nuevoNodo;///a lista le agrego el nuevo nodo
    }
    return lista;
}

void muestraNodo(nodo* aMostrar)///recibo un nodo
{
    muestraUnaPersona(aMostrar->dato);///utilizo la funcion de mostrar un empleado para mostrar el nodo
}

void mostrarLista(nodo* lista)///recibo la lista
{
    nodo* aux = lista;///creo una copia de lista para no correr el riesgo de perder la lista

    while(aux != NULL)///recorro las listas mientras sean distintas a NULL
    {
        muestraNodo(aux);///llamo a muestra nodo
        aux = aux->siguiente;///le asigno la direccion de memoria del sigueinte a aux para ser mostrado
    }
}

void mostrarListaRecursiva(nodo* lista)
{
    if(lista)
    {
        muestraNodo(lista);
        mostrarListaRecursiva(lista->siguiente);
    }
}

nodo* agregarOrdenadoApellido(nodo* lista, nodo* nuevo)
{

    if(lista == NULL)
    {
        lista = nuevo;
    }
    else
    {
        if(atoi(nuevo->dato.dni) < atoi(lista->dato.dni))
        {
            lista = agregarAlPrincipio(lista, nuevo);
        }
        else
        {
            nodo* ante = lista;
            nodo* seg = lista->siguiente;
            while( seg && (atoi(nuevo->dato.dni) > atoi(seg->dato.dni)))
            {
                ante = seg;
                seg = seg->siguiente;
            }
            nuevo->siguiente = seg;
            ante->siguiente = nuevo;
        }
    }


    return lista;
}



/*
int sumaListaRecursiva(nodo* lista)
{
    int suma = 0;

    if(lista)
    {
        suma =lista->dato.sueldo+sumaListaRecursiva(lista->siguiente);
    }
    return suma;
}
*/

nodo* buscoUltimoNodo(nodo* lista)
{
    nodo* aux = lista;

    while(aux->siguiente != NULL)
    {
        aux = aux->siguiente;
    }

    return aux;
}

nodo* agregarAlFinal(nodo* lista, nodo* nuevo)
{
    if(lista == NULL)
    {
        lista = nuevo;
    }
    else
    {
        nodo* ultimo = buscoUltimoNodo(lista);///ultimo almacena el ultimo nodo de la lista
        ultimo->siguiente = nuevo;///el siguiente del ultimo es el nuevo nodo
    }

    return lista;
}


nodo* borrarLista(nodo* lista)
{
    nodo* proximo;///creo dos variables auxiliares
    nodo* seg = lista;

    while(seg)///recorro hasta que seg se convierta en NULL
    {
        proximo = seg->siguiente;///le asigno a proximo el contenido de seg
        free(seg);///libero en memoria los datos que contiene seg
        seg = proximo;///le asigno a seg el contenido de proximo
    }

    return seg;
}

nodo* agregarOrdenadoDNI(nodo* lista, nodo* nuevo)
{

    if(lista == NULL)
    {
        lista = nuevo;
    }
    else
    {
        if(atoi(nuevo->dato.dni) < atoi(lista->dato.dni))
        {
            lista = agregarAlPrincipio(lista, nuevo);
        }
        else
        {
            nodo* ante = lista;
            nodo* seg = lista->siguiente;
            while( seg && (atoi(nuevo->dato.dni) > atoi(seg->dato.dni)))
            {
                ante = seg;
                seg = seg->siguiente;
            }
            nuevo->siguiente = seg;
            ante->siguiente = nuevo;
        }
    }


    return lista;
}


nodo* eliminoNodoPorApellido(nodo* lista, char apellido[])
{
    nodo* seg;
    nodo* ante;

    if(lista && strcmp(lista->dato.apellido, apellido) == 0)
    {
        nodo* aux = lista;
        lista = lista->siguiente;
        free(aux);
    }
    else
    {
        seg = lista;
        while(seg && strcmp(seg->dato.apellido, apellido) != 0)
        {
            ante = seg;
            seg = seg->siguiente;
        }
        if(seg)
        {
            ante->siguiente = seg->siguiente;
            free(seg);
        }
    }

    return lista;
}


nodo * buscarNodoDNI(char dni[20], nodo * lista)
{
    nodo * seg;
    seg = lista;

    while(seg != NULL && (strcmp(dni,seg->dato.dni) != 0))
    {
        seg=seg->siguiente;
    }
    return seg;
}

nodo* invertirLista (nodo* lista)
{
    nodo* invertida = inicLista();
    nodo*aux = lista;

    while(lista)
    {
        aux = lista;
        lista = lista->siguiente;
        aux->siguiente = NULL;
        invertida = agregarAlPrincipio(invertida, aux);
    }
    return invertida;

}

int cuentaLista(nodo* lista)
{
    nodo* seg = lista;
    int cont=0;
    while(seg)  /// while(seg!=NULL)
    {
        cont ++;
        seg = seg->siguiente; /// seg apunta al siguiente dato
    }
    return cont;
}

nodo* eliminaUltimoNodo (nodo* lista)
{
    nodo* aux = lista;
    nodo* ante;
    while(aux->siguiente)
    {
        ante = aux;
        aux = aux->siguiente;
    }
    free(aux);
    ante->siguiente = NULL;

    return lista;
}

nodo* eliminaPrimerNodo(nodo* lista)
{
    nodo* aux = lista;
    lista = lista->siguiente;
    free(aux);
    return lista;
}

void borrarNodoDNIPD(nodo ** lista, char dni[20])
{
    nodo * seg;
    nodo * ante;
    if(lista != NULL && (strcmp(dni, (*lista)->dato.dni)==0))
    {
        nodo * aux = lista;
        (*lista) = (*lista)->siguiente;
        free(aux);
    }
    else
    {
        seg=(*lista);
        while(seg != NULL && (strcmp(dni, seg->dato.dni)!=0))
        {
            ante = seg;
            seg = seg->siguiente;

        }
        if(seg!=NULL)
        {
            ante->siguiente = seg->siguiente;
            free(seg);
        }
    }
}

stPersona verPrimero(nodo* lista)
{
    return lista->dato;
}
