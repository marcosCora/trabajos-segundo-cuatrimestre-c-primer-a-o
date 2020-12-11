#include "listaEmpleados.h"

nodo* inicLista(){
    return NULL;
}

nodo* crearNodo(stEmpleado dato){
    nodo* nuevo = (nodo*)malloc(sizeof(nodo));
    nuevo->dato = dato;
    nuevo->siguiente = NULL;
    return nuevo;
}


nodo * agregarAlPrincipio (nodo * lista, nodo * nuevoNodo){
    if (lista==NULL){
        lista = nuevoNodo; ///si la lista estara vacia apuntara al nuevoNodo
    }
    else{ ///si no esta vacia
        nuevoNodo->siguiente = lista; ///el nuevo nodo
        lista = nuevoNodo;
    }

    return lista;
}

void agregarAlPrincipioPD (nodo ** lista, nodo * nuevoNodo){
    if (*lista==NULL){
        (*lista) = nuevoNodo; ///si la lista estara vacia apuntara al nuevoNodo
    }
    else{ ///si no esta vacia
        nuevoNodo->siguiente = (*lista); ///el nuevo nodo
        (*lista) = nuevoNodo;
    }
}

void agregarAlPrincipioPDPro (nodo** lista, nodo* nuevoNodo){
    nuevoNodo->siguiente = (*lista);
    (*lista) = nuevoNodo;
}

void mostrarNodo (nodo * aMostrar){
    printf("\n Mi direccion: %p - direccion del siguiente: %p", aMostrar, aMostrar->siguiente);
    mostrarUnEmpleado(aMostrar->dato);
}

void mostrarLista(nodo* lista){ ///recibimos la lista (direcc de memoria del primer nodo)
    nodo* seg = lista; ///variable seguidora de la lista
    while(seg){ /// while(seg!=NULL)
        //seg = seg->siguiente; /// seg apunta al siguiente dato
        mostrarNodo(seg);
        seg = seg->siguiente; /// seg apunta al siguiente dato
    }
}

void muestraListaRecurisva(nodo* lista){
    if(lista){
        mostrarNodo(lista);
        muestraListaRecurisva(lista->siguiente);
    }
}

void muestraListaInvertidaRecurisva(nodo* lista){
    if(lista){
        muestraListaRecurisva(lista->siguiente);
        mostrarNodo(lista);
    }
}
int sumaListaRecursiva(nodo* lista){
    int suma;
    if(!lista){ ///solucion trivial = a que la lista no exista
        suma=0;
    }else{
        suma=lista->dato.sueldo+sumaListaRecursiva(lista->siguiente);
    }

    return suma;
}

int sumaListaRecursivaPro(nodo* lista){ ///solucion trivial implicita
    int suma=0;
    if(lista){
        suma=lista->dato.sueldo+sumaListaRecursivaPro(lista->siguiente);
    }
    return suma;
}

int sumalistaRecursivaSuperPro (nodo* lista){
    return(lista)?lista->dato.sueldo+sumalistaRecursivaSuperPro(lista->siguiente):0;
}

nodo* buscarUltimo(nodo *lista){
    nodo *seg= lista;
    while(seg->siguiente){
        seg = seg->siguiente;
    }
    return seg;
}

nodo* agregarAlFinal(nodo * lista, nodo* nuevo){
    if(lista== NULL){
        lista = nuevo;
    }else{
        nodo * ultimo = buscarUltimo(lista); ///ultimo = ultimo nodo de la lista
        ultimo->siguiente = nuevo; ///el siguiente del ultimo = nuevo nodo
    }
    return lista;
}

nodo* borrarLista (nodo* lista){
    nodo* proximo;
    nodo* seg = lista; ///primer nodo
    while(seg){ ///mientras seg tenga datos (no sea NULL)
        proximo = seg->siguiente; ///proximo es el siguiente nodo
        free(seg);///borro nodo actual
        seg = proximo; ///seg va a ser el siguiente nodo que estaba en proximo
    }
    return seg; /// seg va a terminar siendo NULL
}

nodo * agregarEnOrdenApellido (nodo * lista, nodo * nuevo){
    ///si la lista esta vacia:
    if(lista==NULL){
        lista = nuevo;
    }else{
        ///si el dato del nuevo nodo es menor al dato de la lista:
        if(strcmp(nuevo->dato.persona.apellido, lista->dato.persona.apellido) < 0){
            lista = agregarAlPrincipio(lista,nuevo);
        }else{
            ///
            nodo *ante=lista;
            nodo *seg = lista->siguiente;
            while(seg && strcmp(nuevo->dato.persona.apellido, seg->dato.persona.apellido) >0 ){
                ante = seg;
                seg = seg->siguiente;
            }
            nuevo->siguiente = seg;
            ante->siguiente = nuevo;
        }


    }
    return lista;
}
/*********************//**
* \brief Funcion que busca un nodo por DNI
* \param Recibe el DNI a buscar (char) y la lista
* \return Retorna la direccion de memoria. Si es NULL no se encontraba
***********************************/
nodo * buscarNodoDNI(char dni[20], nodo * lista){
    nodo * seg;
    seg = lista;

    while(seg != NULL && (strcmp(dni,seg->dato.persona.dni) != 0)){
        seg=seg->siguiente;
    }
    return seg;
}

nodo * borrarNodoDNI(nodo * lista, char dni[20]){
    nodo * seg;
    nodo * ante;
    if(lista != NULL && (strcmp(dni, lista->dato.persona.dni)==0)){
        nodo * aux = lista;
        lista = lista->siguiente;
        free(aux);
    }else{
        seg=lista;
        while(seg != NULL && (strcmp(dni, seg->dato.persona.dni)!=0)){
            ante = seg;
            seg = seg->siguiente;

        }
        if(seg!=NULL){
            ante->siguiente = seg->siguiente;
            free(seg);
        }
    }
    return lista;
}


nodo* agregarEnOrdenDNI(nodo* lista, nodo* nuevo){
    if(lista==NULL){
        lista = nuevo;
    }else{
        if(atoi(nuevo->dato.persona.dni) < atoi(lista->dato.persona.dni)){
            lista = agregarAlPrincipio(lista, nuevo);
        }else{
            nodo* ante = lista;
            nodo* seg = lista->siguiente;
            while(seg && (atoi(nuevo->dato.persona.dni) > atoi(seg->dato.persona.dni))){
                ante = seg;
                seg = seg->siguiente;
            }
            nuevo->siguiente = seg;
            ante->siguiente = nuevo;
        }
    }
    return lista;
}


int cuentaLista(nodo* lista){
    nodo* seg = lista;
    int cont=0;
    while(seg){ /// while(seg!=NULL)
        cont ++;
        seg = seg->siguiente; /// seg apunta al siguiente dato
    }
    return cont;
}

nodo* eliminaUltimoNodo (nodo* lista){
    nodo* aux = lista;
    nodo* ante;
    while(aux->siguiente){
        ante = aux;
        aux = aux->siguiente;
    }
    free(aux);
    ante->siguiente = NULL;

    return lista;
}

nodo* eliminaPrimerNodo(nodo* lista){
    nodo* aux = lista;
    lista = lista->siguiente;
    free(aux);
    return lista;
}

void eliminarPrimerNodoPD(nodo** lista){
    nodo* aux = (*lista);
    (*lista) = (*lista)->siguiente;
    free(aux);
}

stEmpleado verPrimero(nodo* lista){
    return lista->dato;
}

void borrarNodoDNIPD(nodo ** lista, char dni[20]){
    nodo * seg;
    nodo * ante;
    if(lista != NULL && (strcmp(dni, (*lista)->dato.persona.dni)==0)){
        nodo * aux = lista;
        (*lista) = (*lista)->siguiente;
        free(aux);
    }else{
        seg=(*lista);
        while(seg != NULL && (strcmp(dni, seg->dato.persona.dni)!=0)){
            ante = seg;
            seg = seg->siguiente;

        }
        if(seg!=NULL){
            ante->siguiente = seg->siguiente;
            free(seg);
        }
    }
}

nodo* invertirLista(nodo* lista){
    nodo* invertida = inicLista();
    nodo* aux;
    while(lista){
        aux = lista;
        lista = lista->siguiente;
        aux->siguiente = NULL;

        invertida = agregarAlPrincipio(invertida, aux);
    }
    return invertida;
}

int buscarNodoDNIFlag (nodo * lista, char dni [30]){
    int flag=0;
    nodo*seg = lista;
    while(seg){
        if(strcmp(dni,seg->dato.persona.dni)==0){
            flag=1;
        }
        seg=seg->siguiente;
    }
    return flag;
}

nodo* intercalarLista (nodo * listaA, nodo * listaB, nodo * listaDestino){
    nodo * aux;
    while(listaA && listaB){ ///mientras las dos tengan datos
        if(listaA->dato.id < listaB->dato.id){
            aux = listaA;
            listaA = listaA->siguiente; ///le damos movimiento
            aux->siguiente = NULL;
            listaDestino = agregarAlFinal(listaDestino,aux);
        }else{
            aux = listaB;
            listaA = listaB->siguiente; ///le damos movimiento
            aux->siguiente = NULL;
            listaDestino = agregarAlFinal(listaDestino,aux);
        }

    }
    if(listaA){ ///si A quedo con datos
        listaDestino = agregarAlFinal(listaDestino, listaA); /// vinculamos la lista A al final de la Lista destino
    }
    if(listaB){ ///si B quedo con datos
        listaDestino = agregarAlFinal(listaDestino, listaB); /// vinculamos la lista B al final de la Lista destino
    }

    return listaDestino;
}

void mostrarPosPar (nodo* lista){
    if(lista){
        lista = lista->siguiente;
    if(lista){
        mostrarNodo(lista);
        mostrarPosPar(lista->siguiente);
        }
    }
}

nodo* invertirListaRecursivo (nodo* lista){
    /**
        si esta vacia, retorno NULL
        si tiene un solo nodo, retorna lista
        si tiene mas de un nodo, tomo el 1er nodo, inverto lo que sigue y
        lo agrego al final de la lista invertida

        nos vamos a ayudar con la funcion agregar al final

        primero tengo que desvincular al nodo de la lista
        OJO no perder las referencias...
        */
    nodo* primero =NULL;
    if(lista){
        primero = lista;
        lista=lista->siguiente;
        primero->siguiente=NULL;
        lista=agregarAlFinal(invertirListaRecursivo(lista),primero);
    }
}
/*
nodo* borrarNodoRecursivo (nodo* lista, int dato){
    nodo* aBorrar = NULL;

    if(lista){
        if(lista->dato == dato){
            aBorrar=lista;
            lista=lista->siguiente;
            free(aBorrar);
        }else{
            lista->siguiente=borrarNodoRecursivo(lista->siguiente,dato);
        }
    }
    return lista;
}
*/
