#include "arbol.h"

/*****//**
* \brief inicializa un arbol
* \param ninguno
* \return Retorna NULL
*********/
nodoArbol* inicArbol()
{
    return NULL;
}

/*****//**
* \brief crea un nodo con su respectivo dato
* \param dato de tipo empleado
* \return Retorna un nodo de tipo arbol
*********/
nodoArbol* crearNodoArbol(stEmpleado e)
{
    nodoArbol* nuevo = (nodoArbol*) malloc(sizeof(nodoArbol));

    nuevo->dato = e;
    nuevo->der = NULL;
    nuevo->izq = NULL;

    return nuevo;
}

/*****//**
* \brief inserta nodos en un arbol
* \param el arbol y su nodo a insertar
* \return Retorna el arbol
*********/
nodoArbol* insertar (nodoArbol* arbol, nodoArbol* nuevo)
{
    if(!arbol)
    {
        arbol = nuevo;
    }
    else
    {
        if(atoi(nuevo->dato.persona.dni) > atoi(arbol->dato.persona.dni))
        {
            arbol->der = insertar(arbol->der, nuevo);
        }
        else
        {
            arbol->izq = insertar(arbol->izq, nuevo);
        }
    }
    return arbol;
}

/*****//**
* \brief inserta nodos en un arbol sin repetidos
* \param el arbol y su nodo a insertar
* \return Retorna el arbol
*********/
nodoArbol* insertarSinRepetidos(nodoArbol* arbol, nodoArbol* nuevo)
{
    if(!arbol)
    {
        arbol = nuevo;
    }
    else
    {
        if(nuevo->dato.persona.dni > arbol->dato.persona.dni)
        {
            arbol->der = insertar(arbol->der, nuevo);
        }
        else if(nuevo->dato.persona.dni < arbol->dato.persona.dni)
        {
            arbol->izq = insertar(arbol->izq, nuevo);
        }
    }

    return arbol;
}



void muestraNodoArbol(nodoArbol* nodo)
{
    muestraUnEmpleado(nodo->dato);
}


///Raiz, izquierda y derecha
void preOrder(nodoArbol* arbol)
{
    if(arbol)
    {
        muestraNodoArbol(arbol);
        preOrder(arbol->izq);
        preOrder(arbol->der);
    }
}

///izquierda, raiz y derecha
void inOrder(nodoArbol* arbol)
{
    if(arbol)
    {
        inOrder(arbol->izq);
        muestraNodoArbol(arbol);
        inOrder(arbol->der);
    }
}

///izquierda, derecha y raiz
void postOrder(nodoArbol* arbol)
{
    if(arbol)
    {
        postOrder(arbol->izq);
        postOrder(arbol->der);
        muestraNodoArbol(arbol);
    }
}

/*****//**
* \brief Funcion busca un nodo por dni
* \param Recibe un arbol y el DNI
* \return Retorna el nodo pedido
*********/
nodoArbol* buscaNodoArbol(nodoArbol* arbol, char dni[])
{
    nodoArbol* encontrado =  NULL;

    if(arbol)
    {
        if(strcmpi(dni, arbol->dato.persona.dni) == 0)
        {
            encontrado = arbol;
        }
        else
        {
            if(atoi(dni) > atoi(arbol->dato.persona.dni))
            {
                encontrado = buscaNodoArbol(arbol->der, dni);
            }
            else
            {
                encontrado = buscaNodoArbol(arbol->izq, dni);
            }
        }
    }
    return encontrado;
}

/*****//**
* \brief Funcion que elimina un nodo por DNI
* \param Recibe un arbol y un DNI
* \return Retorna el arbol sin el nodo eliminado
*********/
nodoArbol* eliminarNodoArbolPro(nodoArbol* arbol, char dni[])
{
    nodoArbol* aux;
    nodoArbol* masDer;
    nodoArbol* masIzq;
    if(!arbol)
    {
        printf("El elemento buscado no esta en el arbol... \n");
        return arbol;
    }

    if(atoi(dni) < atoi(arbol->dato.persona.dni))
    {
        arbol->izq = eliminarNodoArbolPro(arbol->izq, dni);
    }
    else if(atoi(dni) > atoi(arbol->dato.persona.dni))
    {
        arbol->der = eliminarNodoArbolPro(arbol->der, dni);
        ///A esta altura el nodo fue encontrado
    }
    else
    {
        ///Caso 1: Sin hijo
        if(arbol->izq == NULL && arbol->der == NULL)
        {
            free(arbol);
            arbol = NULL;
            ///Caso 2: 1 hijo
        }
        else if(arbol->izq != NULL)
        {
            masDer = buscarMazDer(arbol->izq);
            arbol->dato = masDer->dato;
            arbol->izq = eliminarNodoArbolPro(arbol->izq, masDer->dato.persona.dni);
        }
        else if(arbol->der != NULL)
        {
            masIzq = buscarMazIzq(arbol->der);
            arbol->dato = masIzq->dato;
            arbol->der = eliminarNodoArbolPro(arbol->der, masIzq->dato.persona.dni);
        }
        else   ///Caso 3: 2 hijos
        {
            aux = buscarMenorNodoArbol(arbol->der);
            arbol->dato = aux->dato;
            arbol->der = eliminarNodoArbolPro(arbol->der, aux->dato.persona.dni);
        }

    }

    return arbol;
}


nodoArbol* buscarMazIzq (nodoArbol* arbol)
{
    nodoArbol* aux = arbol;

    while(aux && aux->izq != NULL)
    {
        aux = aux->izq;
    }
    return aux;
}

nodoArbol* buscarMazDer (nodoArbol* arbol)
{
    nodoArbol* aux = arbol;

    while(aux && aux->der != NULL)
    {
        aux = aux->der;
    }
    return aux;
}


/*****//**
* \brief Funcion que retorna el menor nodo de un arbol binario
* \param Recibe el arbol cargado
* \return Retorna el nodo mas profundo a la izquierda
*********/
nodoArbol* buscarMenorNodoArbol (nodoArbol* arbol)
{
    nodoArbol* aux = arbol;

    while(aux && aux->izq != NULL)
    {
        aux = aux->izq;
    }
    return aux;
}

