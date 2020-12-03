#include "aux1.h"

///paso de archivo a lista
///recibo el nombre del archivo y la lista
///retorno la lista

nodoEmple* archivoALista(char nombreArch[], nodoEmple* lista)
{
    stEmpleado e;
    FILE *arch = fopen(nombreArch, "rb");

    if(arch)
    {
        while(fread(&e, sizeof(stEmpleado), 1, arch) > 0)
        {
            lista = agregarAlPrincipio(lista, crearNodo(e));
        }

        fclose(arch);
    }
    return lista;
}

///pasaje de archivo a lista ordenado por dni

nodoEmple* archivoAListaOrdenadaDni(char nombreArch[], nodoEmple* lista)
{
    stEmpleado e;
    FILE *arch = fopen(nombreArch, "rb");

    if(arch)
    {
        while(fread(&e, sizeof(stEmpleado), 1, arch) > 0)
        {
            lista = agregarOrdenadoDNI(lista, crearNodo(e));
        }

        fclose(arch);
    }
    return lista;
}

///busca empleado por dni retorna 1 o 0

int buscarNodoDNIFlag (nodoEmple * lista, char dni [30])
{
    int flag=0;
    nodoEmple*seg = lista;
    while(seg)
    {
        if(strcmp(dni,seg->dato.persona.dni)==0)
        {
            flag=1;
        }
        seg=seg->siguiente;
    }
    return flag;
}

///intercala dos listas ordenadas en una sola

nodoEmple* intercalarLista (nodoEmple * listaA, nodoEmple * listaB, nodoEmple * listaDestino)
{
    nodoEmple * aux;
    while(listaA && listaB)  ///mientras las dos tengan datos
    {
        if(listaA->dato.id < listaB->dato.id)
        {
            aux = listaA;
            listaA = listaA->siguiente; ///le damos movimiento
            aux->siguiente = NULL;
            listaDestino = agregarAlFinal(listaDestino,aux);
        }
        else
        {
            aux = listaB;
            listaA = listaB->siguiente; ///le damos movimiento
            aux->siguiente = NULL;
            listaDestino = agregarAlFinal(listaDestino,aux);
        }

    }
    if(listaA)  ///si A quedo con datos
    {
        listaDestino = agregarAlFinal(listaDestino, listaA); /// vinculamos la lista A al final de la Lista destino
    }
    if(listaB)  ///si B quedo con datos
    {
        listaDestino = agregarAlFinal(listaDestino, listaB); /// vinculamos la lista B al final de la Lista destino
    }

    return listaDestino;
}

///pasa de un archivo a una pila de tipo lista

void archivoAPila(char nombreArch[], Pila* p)
{
    stEmpleado e;
    FILE *arch = fopen(nombreArch, "rb");

    if(arch)
    {
        while(fread(&e, sizeof(stEmpleado), 1, arch) > 0)
        {
            apilar(p, e);
        }

        fclose(arch);
    }

}

///muestra pila

void muestraPila(Pila* p)
{
    /*Pila aux;
    inicPila(&aux);
    while(!pilaVacia(p))
    {
        muestraUnEmpleado(tope(p));
        apilar(&aux, desapilar(p));
    }
     while(!pilaVacia(&aux))
    {
        apilar(p, desapilar(&aux));
    }*/

    Pila aux;
    inicPila(&aux);
    while(!pilaVacia(p)){
        muestraUnEmpleado(tope(p));
        apilar(&aux, desapilar(p));
    }
    while(!pilaVacia(&aux)){
        apilar(p, desapilar(&aux));
    }

}


///paso de un archivo a una lista doble

nodo2* archivoAListaDoble(char nombreArch[], nodo2* lista)
{
    stEmpleado e;
    FILE *arch = fopen(nombreArch, "rb");

    if(arch)
    {
        while(fread(&e, sizeof(stEmpleado), 1, arch) > 0)
        {
            lista = agregarAlPrincipioDoble(lista, crearNodoDoble(e));
            ///lista = agregarOrdenadoDNIDoble(lista, crearNodo(e));
        }

        fclose(arch);
    }
    return lista;
}

///paso de un archivo a una lista doble ordenado por DNI

nodo2* archivoAListaDobleDNI(char nombreArch[], nodo2* lista)
{
    stEmpleado e;
    FILE *arch = fopen(nombreArch, "rb");

    if(arch)
    {
        while(fread(&e, sizeof(stEmpleado), 1, arch) > 0)
        {
            lista = agregarOrdenadoDNIDoble(lista, crearNodo(e));
        }

        fclose(arch);
    }
    return lista;
}

///paso de archivo a fila

void archivoAFila(char archivo[20], Fila* fila)
{
    stEmpleado e;
    FILE* arch = fopen(archivo, "rb");

    if(arch)
    {
        while(fread(&e, sizeof(stEmpleado), 1, arch) > 0)
        {
            agregar(fila, e);
        }

        fclose(arch);
    }
}

void pila2lista(Pila* p, nodoEmple** lista)
{
    Pila aux;
    inicPila(&aux);
    stEmpleado e;
    while(!pilaVacia(p))
    {
        e = tope(p);
        agregarAlPrincipio((*lista),crearNodo(e));
        while(!pilaVacia(&aux))
        {
            apilar(p, desapilar(&aux));
        }
    }
}


void lista2pila (Pila*p, nodoEmple* lista)
{
    nodoEmple* seg= lista;
    while(seg)
    {
        apilar(p, seg->dato);
        seg = seg->siguiente;
    }
}

///paso de una pila a una lista aquellos DNI que sean pares

nodoEmple* pila2ListaDniPares(nodoEmple* lista, Pila pila)
{
    Pila p;
    inicPila(&p);
    p = pila;

    while(!pilaVacia(&p))
    {
        printf("caca\n");
        if(atoi(p->dato.persona.dni) %2 == 0)
        {
            lista = agregarAlFinal(lista, p);
        }
        desapilar(&p);
    }

    return lista;
}

nodoEmple* invierteListaRecursiva(nodoEmple* lista)
{
    nodoEmple* primero = NULL;

    if(lista)
    {
        primero = lista;
        lista = lista->siguiente;
        primero->siguiente = NULL;
        lista = agregarAlFinal(invertirLista(lista), primero);
    }
}

///muestras los nodos ubicados en las posiciones pares

void muestraNodosPares(nodoEmple* lista)
{
    if(lista)
    {
        lista = lista->siguiente;
        if(lista)
        {
            muestraNodo(lista);
            muestraNodosPares(lista->siguiente);
        }
    }
}



void mostrarListaRecursivaInvertida(nodoEmple* lista)
{
    if(lista)
    {
        mostrarListaRecursiva(lista->siguiente);
        muestraNodo(lista);
    }
}

nodoArbol* archivo2Arbol(char nombreArchivo[25], nodoArbol* arbol)
{
    stEmpleado e;
    FILE* arch = fopen(nombreArchivo, "rb");

    if(arch)
    {
        while(fread(&e, sizeof(stEmpleado), 1, arch) > 0)
        {
            ///arbol = insertarSinRepetidos(arbol, crearNodoArbol(e));
            arbol = insertar(arbol, crearNodoArbol(e));
        }


        fclose(arch);
    }
    return arbol;
}


nodoEmple* arbol2lista(nodoArbol* arbol, nodoEmple* lista)
{
    if(arbol)
    {
        lista = arbol2lista(arbol->izq, lista);
        lista = agregarAlFinal(lista, crearNodo(arbol->dato));
        lista = arbol2lista(arbol->der, lista);
    }
    return lista;
}


/******//**
* \brief Funcion que busca un nombre con pre order
* \param Recibe el arbol
* \return Retorna el dato buscado, si es NULL no fue encontrado
***********/
nodoArbol* buscarPorNombre(nodoArbol* arbol, char dato[])
{
    nodoArbol* buscado = NULL;

    if(arbol)  ///evaluo el primer dato, si es lo igualamos a arbol
    {
        if(strcmpi(dato,arbol->dato.persona.nombre)==0)
        {
            buscado = arbol;
        }
        else  ///si no es, buscamos por izquierda
        {
            buscado = buscarPorNombre(arbol->izq,dato);
            if(!buscado)  ///si no es encontrado por izquierda, buscamos por derecha:
            {
                buscado = buscarPorNombre(arbol->der,dato);
            }
        }
    }
    return buscado;
}


/*****//**
* \brief Funcion que calcula la altura de un arbol
* \param Recie el arbol
* \return Retorna la altura
********/
int calcularAlturaArbol (nodoArbol* arbol)
{

    int count;
    if(!arbol)
    {
        count=0;
    }
    else
    {
        int izqDepth = calcularAlturaArbol(arbol->der);
        int derDepth = calcularAlturaArbol(arbol->izq);

        if(izqDepth > derDepth)
        {
            count = izqDepth+1;
        }
        else
        {
            count = derDepth+1;
        }
    }

    return count;

}


void arbol2archivo(nodoArbol* arbol, char archivo[])
{
    FILE *archi = fopen(archivo,"ab");
    stEmpleado e;
    if(archi)
    {
        if(arbol)
        {
            e = arbol->dato;
            fwrite(&e, sizeof(stEmpleado),1,archi);
            arbol2archivo(arbol->izq,archivo);
            arbol2archivo(arbol->der,archivo);
        }
        fclose(archi);
    }
}













