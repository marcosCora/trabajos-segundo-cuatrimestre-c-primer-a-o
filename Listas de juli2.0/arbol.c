#include "arbol.h"
#include <stddef.h>

nodoArbol* inicArbol(){
    return NULL;
}

nodoArbol* crearNodoArbol(stEmpleado e){
    nodoArbol* nuevo = (nodoArbol*)malloc(sizeof(nodoArbol));
    nuevo->dato = e;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    return nuevo;
}
///atoi: "40096183" -> 40096183

///Funcion que no carga DNI iguales
nodoArbol* insertar(nodoArbol* arbol, nodoArbol* nuevo){
    if(!arbol){
        arbol=nuevo;
    }else{
        if(strcmpi(nuevo->dato.persona.dni, arbol->dato.persona.dni)== 1){ ///atoi(nuevo->dato.persona.dni) > atoi(arbol->dato.persona.dni)
            arbol->der= insertar(arbol->der, nuevo);
        }else if(atoi(nuevo->dato.persona.dni) < atoi(arbol->dato.persona.dni)){
            arbol->izq = insertar(arbol->izq, nuevo);
        }
    }
    return arbol;
}

nodoArbol* insertarSinRepetidos(nodoArbol* arbol, nodoArbol* nuevo){
    if(!arbol){
        arbol=nuevo;
    }else{
        if(strcmpi(nuevo->dato.persona.dni, arbol->dato.persona.dni)== 1){
            arbol->der= insertar(arbol->der, nuevo);
    }else if(strcmpi(nuevo->dato.persona.dni, arbol->dato.persona.dni)== -1){
            arbol->izq=insertar(arbol->izq, nuevo);
        }
    }
    return arbol;
}

void mostrarNodoArbol(nodoArbol* nodo){
    mostrarUnEmpleado(nodo->dato);
}
/// primero nodo raiz, luego izq, luego der
void preOrder(nodoArbol* arbol){
    if(arbol){
        mostrarNodoArbol(arbol);
        preOrder(arbol->izq);
        preOrder(arbol->der);
    }
}
///primero izq, luego raiz, luego der
void inOrder(nodoArbol* arbol){
    if(arbol){
        inOrder(arbol->izq);
        mostrarNodoArbol(arbol);
        inOrder(arbol->der);
    }
}
///primero izq, luego der, luego raiz
void postOrder(nodoArbol* arbol){
    if(arbol){
        postOrder(arbol->izq);
        postOrder(arbol->der);
        mostrarNodoArbol(arbol);
    }
}
/******************//**
* \brief Funcion que busca un nombre con pre order
* \param Recibe el arbol
* \return Retorna el dato buscado, si es NULL no fue encontrado
*****************************/
nodoArbol* buscarPorNombre(nodoArbol* arbol, char dato[]){
    nodoArbol* buscado = NULL;

    if(arbol){ ///evaluo el primer dato, si es lo igualamos a arbol
        if(strcmpi(dato,arbol->dato.persona.nombre)==0){
            buscado = arbol;
        }
        else{ ///si no es, buscamos por izquierda
            buscado = buscarPorNombre(arbol->izq,dato);
            if(!buscado){ ///si no es encontrado por izquierda, buscamos por derecha:
                buscado = buscarPorNombre(arbol->der,dato);
            }
        }
    }
    return buscado;
}

int sumaSueldosArbol (nodoArbol* arbol){
    int sum = 0;
    if(arbol){
        sum = arbol->dato.sueldo + sumaSueldosArbol(arbol->izq) + sumaSueldosArbol(arbol->der);
    }
    return sum;
}

int cuentaNodos (nodoArbol* arbol){
    int cont = 0;
    if(arbol){
        cont = 1 + cuentaNodos(arbol->izq) + cuentaNodos(arbol->der);
    }
    return cont;
}

/***************//**
* \brief Funcion que calcula la altura de un arbol
* \param Recie el arbol
* \return Retorna la altura
************************/
int calcularAltura (nodoArbol* arbol){
    int count=0;

    if (!arbol){
        count= 0;
    }else{
        count = count + 1 + calcularAltura(arbol->izq), calcularAltura(arbol->der);
    }
    return count;
}

/***************//**
* \brief Funcion que calcula la altura de un arbol
* \param Recibe el arbol
* \return Retorna 0 si el arbol no esta cargado, sino, la altura
**********************/
int calcularAlturaArbol (nodoArbol* arbol){
    int count;
    if(!arbol){ ///si el arbol no tiene nodos retorna 0
        count=0;
    }else{ ///si tiene nodos
        int izqDepth = calcularAlturaArbol(arbol->der); ///recorro hasta el fondo del lazo izquierdo
        int derDepth = calcularAlturaArbol(arbol->izq); ///recorro hasta el fondo del lado derecho

        if(izqDepth > derDepth){ ///comparo cual de las dos variables tiene mayor peso
            count = izqDepth+1;
        }else{
            count = derDepth+1;
        }
    }

    return count; ///retorno la altura
}
/****************//**
* \brief Funcion que cuenta hojas de un arbol
* \param Recibe el arbol cargado o no
* \return Retorna la cantidad de hojas
*************************/
int contarHojas(nodoArbol*arbol)
{
    int rta=0;
    if(arbol)
    {
        if((arbol->der!=NULL)&&(arbol->izq!=NULL))
        {
            rta=contarHojas(arbol->der)+contarHojas(arbol->izq);
        }
        else
        {
            rta=rta+1;
        }
    }
    return rta;
}
/***************//**
* \brief Funcion que retorna el menor nodo de un arbol binario
* \param Recibe el arbol cargado
* \return Retorna el nodo mas profundo a la izquierda
***********************/
nodoArbol* buscarMenorNodoArbol (nodoArbol* arbol){
    nodoArbol* aux = arbol;

    while(aux && aux->izq != NULL){
        aux = aux->izq;
    }
    return aux;
}
/**************//**
* \brief Funcion que busca el nodo mas izq de un arbol
* \param Recibe el arbol
* \return Retorna el nodo mas izq del arbol
**********************/
nodoArbol* buscarMazIzq (nodoArbol* arbol){
    nodoArbol* aux = arbol;

    while(aux && aux->izq != NULL){
        aux = aux->izq;
    }
    return aux;
}
/**************//**
* \brief Funcion que busca el nodo mas der de un arbol
* \param Recibe el arbol
* \return Retorna el nodo mas der del arbol
**********************/
nodoArbol* buscarMazDer (nodoArbol* arbol){
    nodoArbol* aux = arbol;

    while(aux && aux->der != NULL){
        aux = aux->der;
    }
    return aux;
}

/***************//**
* \brief Funcion que elimina un nodo por DNI y deja el arbol acomodado
* \param Recibe el arbol, y el dni
* \return Retorna el arbol modificado
**************************/
eliminarNodoArbolPro2(nodoArbol* arbol, char dni[]){
    nodoArbol* aux;
    nodoArbol* masDer;
    nodoArbol* masIzq;
    if(!arbol){
        printf("El elemento buscado no esta en el arbol... \n");
        return arbol;
    }

    if(atoi(dni) < atoi(arbol->dato.persona.dni)){
        arbol->izq = eliminarNodoArbolPro2(arbol->izq, dni);
    }else if(atoi(dni) > atoi(arbol->dato.persona.dni)){
        arbol->der = eliminarNodoArbolPro2(arbol->der, dni);
    ///A esta altura el nodo fue encontrado
    }else{
            ///Caso 1: Sin hijo
            if(arbol->izq == NULL && arbol->der == NULL){
                free(arbol);
                arbol = NULL;
            ///Caso 2: 1 hijo
            }else if(arbol->izq != NULL){
                masDer = buscarMazDer(arbol->izq);
                arbol->dato = masDer->dato;
                arbol->izq = eliminarNodoArbolPro2(arbol->izq, masDer->dato.persona.dni);
            }else if(arbol->der != NULL){
                masIzq = buscarMazIzq(arbol->der);
                arbol->dato = masIzq->dato;
                arbol->der = eliminarNodoArbolPro2(arbol->der, masIzq->dato.persona.dni);
            }else{ ///Caso 3: 2 hijos
                aux = buscarMenorNodoArbol(arbol->der);
                arbol->dato = aux->dato;
                arbol->der = eliminarNodoArbolPro2(arbol->der, aux->dato.persona.dni);
            }

    }

    return arbol;
}

///------------------------------------------
/*
nodoArbol* arbol = inicArbol();

arbol->dato.persona.dni;
arbol->consumos.fecha.dia;

typedef struct nodoArbol{
    stEmpleado dato;
    nodo* consumos;
    struct nodoArbol* izq;
    struct nodoArbol* der;
}nodoArbol;

*/

/*
typedef struct{
    stCliente c;
    nodo* consumos;
}stCelda;

stCelda adl[100];
ald[x].c.persona.dni;
adl[x].consumos->fecha.dia;
*/

