#include "listaEmpleados.h"


nodoEmple* inicLista()///recibo la lista
{
    return NULL;///retorno la lista en NULL
}

nodoEmple* crearNodo(stEmpleado dato)///recibo el dato el cual se creara un nodo
{
    nodoEmple* nuevo = (nodoEmple*) malloc(sizeof(nodoEmple));///creo un puntero a la estructura de nodoEmple y lo inicializo
    nuevo->dato = dato;///agrego el dato recibido al nodo creado
    nuevo->siguiente = NULL;///inicializo el nodo siguente en NULL
    return nuevo;///retorno el nodo
}

nodoEmple* agregarAlPrincipio(nodoEmple* lista, nodoEmple* nuevoNodo)///recibo una lista, y el nodo a agregar a esa lista
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

void muestraNodo(nodoEmple* aMostrar)///recibo un nodo
{
    muestraUnEmpleado(aMostrar->dato);///utilizo la funcion de mostrar un empleado para mostrar el nodo
}

void mostrarLista(nodoEmple* lista)///recibo la lista
{
    nodoEmple* aux = lista;///creo una copia de lista para no correr el riesgo de perder la lista

    while(aux != NULL)///recorro las listas mientras sean distintas a NULL
    {
        muestraNodo(aux);///llamo a muestra nodo
        aux = aux->siguiente;///le asigno la direccion de memoria del sigueinte a aux para ser mostrado
    }
}

nodoEmple* buscoUltimoNodo(nodoEmple* lista)
{
    nodoEmple* aux = lista;

    while(aux->siguiente != NULL)
    {
        aux = aux->siguiente;
    }

    return aux;
}

nodoEmple* agregarAlFinal(nodoEmple* lista, nodoEmple* nuevo)
{
    if(lista == NULL)
    {
        lista = nuevo;
    }
    else
    {
        nodoEmple* ultimo = buscoUltimoNodo(lista);///ultimo almacena el ultimo nodo de la lista
        ultimo->siguiente = nuevo;///el siguiente del ultimo es el nuevo nodo
    }

    return lista;
}


nodoEmple* borrarLista(nodoEmple* lista)
{
    nodoEmple* proximo;///creo dos variables auxiliares
    nodoEmple* seg = lista;

    while(seg)///recorro hasta que seg se convierta en NULL
    {
        proximo = seg->siguiente;///le asigno a proximo el contenido de seg
        free(seg);///libero en memoria los datos que contiene seg
        seg = proximo;///le asigno a seg el contenido de proximo
    }

    return seg;
}

nodoEmple* agregarOrdenadoDNI(nodoEmple* lista, nodoEmple* nuevo)
{

    if(lista == NULL)
    {
        lista = nuevo;
    }
    else
    {
        if(atoi(nuevo->dato.persona.dni) < atoi(lista->dato.persona.dni))
        {
            lista = agregarAlPrincipio(lista, nuevo);
        }
        else
        {
            nodoEmple* ante = lista;
            nodoEmple* seg = lista->siguiente;
            while( seg && (atoi(nuevo->dato.persona.dni) > atoi(seg->dato.persona.dni)))
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


nodoEmple* eliminoNodoPorApellido(nodoEmple* lista, char apellido[])
{
    nodoEmple* seg;
    nodoEmple* ante;

    if(lista && strcmp(lista->dato.persona.apellido, apellido) == 0)
    {
        nodoEmple* aux = lista;
        lista = lista->siguiente;
        free(aux);
    }
    else
    {
        seg = lista;
        while(seg && strcmp(seg->dato.persona.apellido, apellido) != 0)
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


nodoEmple * buscarNodoDNI(char dni[20], nodoEmple * lista)
{
    nodoEmple * seg;
    seg = lista;

    while(seg != NULL && (strcmp(dni,seg->dato.persona.dni) != 0))
    {
        seg=seg->siguiente;
    }
    return seg;
}

nodoEmple* invertirLista (nodoEmple* lista)
{
    nodoEmple* invertida = inicLista();
    nodoEmple*aux = lista;

    while(lista)
    {
        aux = lista;
        lista = lista->siguiente;
        aux->siguiente = NULL;
        invertida = agregarAlPrincipio(invertida, aux);
    }
    return invertida;

}

int cuentaLista(nodoEmple* lista)
{
    nodoEmple* seg = lista;
    int cont=0;
    while(seg)  /// while(seg!=NULL)
    {
        cont ++;
        seg = seg->siguiente; /// seg apunta al siguiente dato
    }
    return cont;
}

nodoEmple* eliminaUltimoNodo (nodoEmple* lista)
{
    nodoEmple* aux = lista;
    nodoEmple* ante;
    while(aux->siguiente)
    {
        ante = aux;
        aux = aux->siguiente;
    }
    free(aux);
    ante->siguiente = NULL;

    return lista;
}

nodoEmple* eliminaPrimerNodo(nodoEmple* lista)
{
    nodoEmple* aux = lista;
    lista = lista->siguiente;
    free(aux);
    return lista;
}

void borrarNodoDNIPD(nodoEmple ** lista, char dni[20])
{
    nodoEmple * seg;
    nodoEmple * ante;
    if(lista != NULL && (strcmp(dni, (*lista)->dato.persona.dni)==0))
    {
        nodoEmple * aux = lista;
        (*lista) = (*lista)->siguiente;
        free(aux);
    }
    else
    {
        seg=(*lista);
        while(seg != NULL && (strcmp(dni, seg->dato.persona.dni)!=0))
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

stEmpleado verPrimero(nodoEmple* lista)
{
    return lista->dato;
}

///FUNCIONES RECURSIVAS

void mostrarListaRecursiva(nodoEmple* lista)
{
    if(lista)
    {
        muestraNodo(lista);
        mostrarListaRecursiva(lista->siguiente);
    }
}


int sumaListaRecursiva(nodoEmple* lista)
{
    int suma = 0;

    if(lista)
    {
        suma =lista->dato.sueldo+sumaListaRecursiva(lista->siguiente);
    }
    return suma;
}



///borro un nodo de la lista recibido por parametro de manera recrusiva

nodoEmple* borroNodoRecrusivo(nodoEmple* lista, char dato[])
{
    nodoEmple* aBorrar = NULL;

    if(lista)
    {
        if(strcmpi(lista->dato.persona.dni, dato) == 0)
        {
            aBorrar = lista;
            lista = lista->siguiente;
            free(aBorrar);
        }
        else
        {
            lista->siguiente = borroNodoRecrusivo(lista->siguiente, dato);
        }
    }
    return lista;
}

///inserto nodo de manera ordenada en una lista(recursivo)

nodoEmple* insertarEnOrdenRecursivo(nodoEmple* lista, nodoEmple* nuevo)
{
    if(!lista)
    {
        lista = nuevo;
    }
    else
    {
        if(nuevo->dato.persona.dni < lista->dato.persona.dni)
        {
            nuevo->siguiente = lista;
            lista = nuevo;
        }
        else
        {
            lista->siguiente = insertarEnOrdenRecursivo(lista->siguiente, nuevo);
        }
    }
    return lista;
}











