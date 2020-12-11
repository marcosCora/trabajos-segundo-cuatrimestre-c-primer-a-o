#include "lista2.h"


nodo2 * iniciLista2(){
    return NULL;
}

nodo2* crearNodo2(stEmpleado e){
    nodo2* nuevo = (nodo2*) malloc(sizeof(nodo2));
    nuevo->dato = e;
    nuevo->anterior = NULL;
    nuevo->siguiente = NULL;
    return nuevo;
}

nodo2* agregarAlPrincipio2 (nodo2* lista, nodo2* nuevo){
    nuevo->siguiente = lista;
    if(lista){
        lista->anterior = nuevo;
    }

    return nuevo;
}

nodo2* buscarUltimo2(nodo2 * lista){
    nodo2* seg = lista;
    while(seg->siguiente){ ///esto es igual a while(seg->siguiente != NULL
        seg = seg->siguiente;
    }
    return seg;
}

nodo2* agregarAlFinal2(nodo2* lista, nodo2* nuevo){
    if(!lista){
        lista = nuevo;
    }else{
        nodo2* ultimo = buscarUltimo2(lista);
        ultimo->siguiente = nuevo; ///vinculamos ultimo elemento apuntando al nuevo
        nuevo->anterior = ultimo; ///vinculamos el anterior al ultimo de la lista recibida
    }

    return lista;
}

void muestraNodo2(nodo2* lista){
    printf("\n nodo: %p - nodo->anterior: %p - nodo->siguiente: %p", lista, lista->anterior, lista->siguiente);
    mostrarUnEmpleado(lista->dato);
}

void mostrarLista2(nodo2* lista){
    nodo2* seg = lista;
    while(seg){
        muestraNodo2(seg);
        seg = seg->siguiente;
    }
}

nodo2* borrarNodo2(nodo2 * lista, char dni[20]){
    nodo2 * aBorrar=NULL;
    nodo2 * seg=NULL;

    if(lista!=NULL && (strcmp(dni,lista->dato.persona.dni)==0)){
            aBorrar=lista;
            lista=lista->siguiente;
            if(lista!=NULL){
                lista->anterior=NULL;}
            free(aBorrar);
        }
        else {
            seg=lista->siguiente;
            while(seg!=NULL && strcmp(dni,seg->dato.persona.dni)!=0)
            {
                seg=seg->siguiente;
            }
            if( seg!= NULL) {
                nodo2 * anterior=seg->anterior; /// bajo a una variable el anterior
                anterior->siguiente = seg->siguiente; ///salteo el nodo que quiero eliminar.
                if(seg->siguiente) {   /// si existe el nodo siguiente
                    nodo2 * siguiente = seg->siguiente;
                    siguiente->anterior=anterior;
                }
                free(seg); ///elimino el nodo.
            }
        }

    return lista;
}


stEmpleado verPrimero2(nodo2* lista){
    return lista->dato;
}

nodo2* EliminarPrimerNodo2(nodo2 * lista){
    nodo2* aux = lista;
    lista = lista->siguiente;
    if(lista){
    lista->anterior = NULL;
    }
    free(aux);
    return lista;
}
nodo2* borrarLista2 (nodo2* lista){
    nodo2* proximo;
    nodo2* seg = lista;
    while(seg){
        proximo = seg->siguiente;
        free(seg);
        seg = proximo;
    }
    return seg;
}

nodo2 *borrarUltimoNodo2(nodo2 *lista){
    nodo2*aux=buscarUltimo2(lista);
    nodo2* aux2=aux->anterior;
    aux2->siguiente=NULL;
    free(aux);
    return lista;
}

nodo2* borrarNodoDoble(nodo2* lista,char dni[30])
{
    nodo2 * aux;
    if(lista){
        if(strcmp(dni,lista->dato.persona.dni)==0){
            aux = lista;
            lista = lista->siguiente;
            if(lista){
                lista->anterior = NULL;
            }
            free(aux);
        }else{
            nodo2 *seg=lista->siguiente;

            while(seg != NULL && strcmp(dni,seg->dato.persona.dni) != 0){
                seg = seg->siguiente;
            }
            if (seg != NULL){
                nodo2* ante=seg->anterior;
                nodo2* proximo=seg->siguiente;

                ante->siguiente = seg->siguiente;
                if(proximo){
                    proximo->anterior=ante;
                }
                free(seg);
            }

        }
    }

    return lista;
}

void borrarNodoDoblePD(nodo2** lista,char dni[30])
{
    nodo2 * aux;
    if(*lista){
        if(strcmp(dni,(*lista)->dato.persona.dni)==0){
            aux = (*lista);
            (*lista) = (*lista)->siguiente;
            if(*lista){
                (*lista)->anterior = NULL;
            }
            free(aux);
        }else{
            nodo2 *seg=(*lista)->siguiente;

            while(seg != NULL && strcmp(dni,seg->dato.persona.dni) != 0){
                seg = seg->siguiente;
            }
            if (seg != NULL){
                nodo2* ante=seg->anterior;
                nodo2* proximo=seg->siguiente;

                ante->siguiente = seg->siguiente;
                if(proximo){
                    proximo->anterior=ante;
                }
                free(seg);
            }

        }
    }

}
nodo2* buscarNodo2(nodo2* lista, int dni)
{
    int flag=0;
    nodo2* seg=lista;
    do
    {
        if(dni==seg->dato.persona.dni)
        {
            flag=1;
        }
        else
        {
            seg=seg->siguiente;
        }
    }
    while(seg!=NULL && flag!=1);

    return seg;
}
