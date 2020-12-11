#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "empleados.h"
#include "listaEmpleados.H"
#include "pila.h"
#include "lista2.h"
#include "fila.h"
#include "arbol.h"
#include "ADL.h"
#define ESC 27
#define AR_EMPLEADOS "empleados.dat"
#define AR_EMPLEADOS_PRUEBAS "empleadosPruebas.dat"
#define DIM_EMP 150
void muestraMenuPrincipal();
void funcion02(nodo * lista);
int buscarNodoDNIFlag (nodo * lista, char dni [30]);
nodo* archivo2lista (char nombreArchivo[], nodo* lista);
nodo* intercalarLista (nodo * listaA, nodo * listaB, nodo * listaDestino);
nodo* invertirLista(nodo* lista);
nodo* archivo2listaPD (char nombreArchivo[], nodo* lista);
void archivo2listaPDPro (char nombreArchivo[], nodo** lista);
void archivo2Pila (char nombreArchivo[], Pila *p);
void muestraPila(Pila p);
nodo2* archivo2lista2(char arEmpleados[], nodo2* lista);
void archivo2fila (char nombreArchivo[], Fila* f);
void lista2pila (Pila*p, nodo* lista);
void pila2lista(Pila* p, nodo** lista);
void PilaToArch(char nombreArchivo[], Pila* p);
void pila2listaDoble(Pila* p, nodo** lista);
int lista2arreglo(nodo* lista, stEmpleado e[], int v, int dim);
void lista2Fila (nodo* lista, Fila* f);
nodoArbol* archivo2Arbol(char nombreArchivo[], nodoArbol* arbol);
nodo* arbol2Lista(nodoArbol* arbol, nodo* lista);
int arbol2Array(nodoArbol* arbol, stEmpleado a[], int v, int dim);
int cargaArreglo(stEmpleado a[], int v, int dim, stEmpleado dato);
void arbol2archivo(nodoArbol* arbol, char archivo[]);

int main()
{

    stEmpleado empleados [DIM_EMP];
    int vEmpleados=0;


    nodo* listaEmpleados = inicLista(); ///declaracion e inicializacion de mi lista
    nodo* listaEmpleadosPD = inicLista();
    nodo2* listaEmpleados2 = iniciLista2();
    Pila pila;
    inicPila(&pila);
    Fila filaEmpleados;
    inicFila(&filaEmpleados);

    nodoArbol* arbol = inicArbol();
    nodoArbol* aux = inicArbol();

    int hojas;


    char opcion;
    char opcionArch;
    char opcionLista;
    char opcionLista2;
    char opcionPila;
    char opcionFila;
    char opcionArbol;
    do {
        system("cls");
        muestraMenuPrincipal();
        opcion=getch();

            switch(opcion){


            case 49:

                do{
                system("cls");
                MenuArchivo();
                opcionArch=getch();
                switch(opcionArch){
                    case 49:
                        ingresaEmpleadosArchivo();
                        break;
                    case 50:
                        system("cls");
                        muestraArchivoDeEmpleados(AR_EMPLEADOS);
                        system("pause");
                        break;
                    case 51:
                        vEmpleados = archivoEmpleados2Arreglo(AR_EMPLEADOS,empleados,vEmpleados,DIM_EMP);
                        system("pause");
                        break;
                    case 52:
                        system("cls");
                        muestraArregloEmpleados(empleados,vEmpleados);
                        system("pause");
                        break;
                }
                }while(opcionArch != ESC);
                break;
            case 50:

                do{
                system("cls");
                menuLista();
                opcionLista=getch();
                switch(opcionLista){
                    case 49:
                        listaEmpleados = archivo2lista(AR_EMPLEADOS, listaEmpleados);
                        system("pause");
                        break;
                    case 50:
                        mostrarLista(listaEmpleados);
                        system("pause");
                        break;
                    case 51:
                        printf("El nodo correspondiente al DNI es: \n");
                        mostrarNodo(buscarNodoDNI("40096183", listaEmpleados));
                        system("pause");
                    case 52:
                        listaEmpleadosPD = archivo2listaPD(AR_EMPLEADOS,listaEmpleadosPD);
                        system("pause");
                        break;
                    case 53:
                        mostrarLista(listaEmpleadosPD);
                        system("pause");
                        break;
                    case 54:
                        borrarNodoDNIPD(&listaEmpleados,"12457896");
                        system("pause");
                        break;
                    case 55:
                        listaEmpleados = invertirLista(listaEmpleados);
                        system("pause");
                        break;
                    case 57:
                        listaEmpleados = arbol2Lista(arbol, listaEmpleados);
                        system("pause");
                        break;

                }
                }while(opcionLista != ESC);
                break;
            case 51:

                do{
                system("cls");
                menuPila();
                opcionPila=getch();
                system("cls");
                switch(opcionPila){

                    case 49:
                        archivo2Pila(AR_EMPLEADOS,&pila);
                        system("pause");
                        break;
                    case 50:
                        muestraPila(pila);
                        system("pause");
                        break;
                    case 51:
                        lista2pila(&pila,listaEmpleados);
                        system("pause");
                        break;
                    case 52:
                        PilaToArch(AR_EMPLEADOS_PRUEBAS,&pila);
                        system("pause");
                        system("cls");
                        muestraArchivoDeEmpleados(AR_EMPLEADOS_PRUEBAS);
                        system("pause");
                        break;
                    case 53:
                        pila2lista(&pila,listaEmpleados);
                        system("pause");
                        system("cls");
                        mostrarLista(listaEmpleados);
                        system("pause");
                        break;
                    case 54:
                        pila2listaDoble(&pila, listaEmpleados2);
                        system("pause");
                        system("cls");
                        mostrarLista2(listaEmpleados2);
                        system("pause");
                        break;
                }
                }while(opcionPila != ESC);
                break;
            case 52:

                do{
                system("cls");
                menuFila();
                opcionFila=getch();
                switch(opcionFila){
                    case 49:
                        system("cls");
                        archivo2fila(AR_EMPLEADOS,&filaEmpleados);
                        system("pause");
                        break;
                    case 50:
                        system("cls");
                        muestraFila(&filaEmpleados);
                        system("pause");
                        break;
                    case 51:
                        system("cls");
                        lista2Fila(listaEmpleados,&filaEmpleados);
                        system("pause");
                        break;

                }
                }while(opcionFila != ESC);
                break;
            case 53:

                do{
                system("cls");
                menuLista2();
                opcionLista2=getch();
                system("cls");
                switch(opcionLista2){

                    case 49:
                        listaEmpleados2 = archivo2lista2(AR_EMPLEADOS, listaEmpleados2);
                        system("pause");
                        break;
                    case 50:
                        mostrarLista2(listaEmpleados2);
                        system("pause");
                        break;
                    case 51:
                        listaEmpleados2 = EliminarPrimerNodo2(listaEmpleados2);
                        system("pause");
                        break;
                    case 52:
                        listaEmpleados2 = borrarLista2(listaEmpleados2);
                        system("pause");
                        break;
                    case 53:
                        listaEmpleados2 = borrarNodoDoble(listaEmpleados2,"1111");
                        system("pause");
                        break;
                    case 54:
                        listaEmpleados2 = borrarUltimoNodo2(listaEmpleados2);
                        system("pause");
                        break;
                    case 55:
                        borrarNodoDoblePD(&listaEmpleados2,"12457896");
                        system("pause");
                        break;
                }
                }while(opcionLista2 != ESC);
                break;

                case 54:

                do {
                    system("cls");
                    menuArbol();
                    opcionArbol=getch();
                    system("cls");
                    switch(opcionArbol){

                    case 49:
                        arbol = archivo2Arbol(AR_EMPLEADOS, arbol);
                        system("pause");
                        break;
                    case 50:
                        preOrder(arbol);
                        system("pause");
                        break;
                    case 51:
                        inOrder(arbol);
                        system("pause");
                        break;
                    case 52:
                        postOrder(arbol);
                        system("pause");
                        break;
                    case 53:
                        hojas = contarHojas(arbol);
                        printf("El arbol tiene %d hojas \n", hojas);
                        system("pause");
                        break;
                    case 54:
                        hojas = cuentaNodos(arbol);
                        printf("El arbol tiene %d nodos \n", hojas);
                        system("pause");
                        break;
                    case 55:
                        aux = buscarPorNombre(arbol,"julian");
                        if(aux==NULL){
                            printf("El nombre del nodo que estaba buscando no fue encontrado\n");
                        }else{
                            printf("El dato que esta buscando corresponde a: \n");
                            mostrarNodoArbol(aux);
                        }
                        system("pause");
                        break;
                    case 56:
                        hojas = calcularAlturaArbol(arbol);
                        printf("La altura del arbol es: %d", hojas);
                        system("pause");
                        break;
                    case 57:
                        printf("El menor nodo del arbol corresponde a: \n");
                        mostrarNodoArbol(buscarMenorNodoArbol(arbol));
                        system("pause");
                        break;
                    case 97:
                        arbol = eliminarNodoArbolPro2(arbol,"6");
                        system("pause");
                        break;
                    case 98:
                        hojas = sumaSueldosArbol(arbol);
                        printf("La suma de los sueldos de los nodos del arbol fue: %d \n", hojas);
                        system("pause");
                        break;
                    case 99:
                        vEmpleados = arbol2Array(arbol,empleados, vEmpleados,10);
                        system("pause");
                        printf("El arreglo: \n");
                        muestraArregloEmpleados(empleados, vEmpleados);
                        system("pause");
                        break;
                    case 100:
                        arbol2archivo(arbol,AR_EMPLEADOS_PRUEBAS);
                        system("pause");
                        muestraArchivoDeEmpleados(AR_EMPLEADOS_PRUEBAS);
                        system("pause");
                        break;
                    }
                }while(opcionArbol != ESC);
            /********************************/

            system("pause");
    }
    }while (opcion != ESC);

    printf("Fin del programa");

    return 0;
}

void muestraMenuPrincipal(){
    printf("\t -1- Para menu de archivos \n");
    printf("\t -2- Para menu de lista de empleados \n");
    printf("\t -3- Para menu de Pila (pd) \n");
    printf("\t -4- Para menu de Fila (pd) \n");
    printf("\t -5- Para menu de lista de empleados2 (lista2) \n");
    printf("\t -6- Para menu de lista arbol\n");
    printf("\t ESC para salir... \n");
}

void MenuArchivo(){
    printf("\t -1- Para cargar un empleado en archivo \n");
    printf("\t -2- Para mostrar lista de empleados del archivo\n");
    printf("\t -3- Carga arreglo de Empleados \n");
    printf("\t -4- Muestra arreglo de empleados \n");
    printf("\t ESC para salir... \n");
}

void menuLista(){
    printf("\t -1- Para pasar empleados del archivo a lista \n");
    printf("\t -2- Para mostrar lista de empleados (nodos) \n");
    printf("\t -3- Buscar empleado por DNI en lista \n");
    printf("\t -4- Pasar empleadops del archivo a lista PD \n");
    printf("\t -5- Para mostrar lista de empleados PD \n");
    printf("\t -6- Eliminar empleado por DNI en lista PD \n");
    printf("\t -7- Invertir lista \n");
    printf("\t -8- Buscar dato flag (FUNCION SIN USO) \n");
    printf("\t -9- Pasar de arbol a lista (CUIDADO!, tener arbol cargado primeramente) \n");
    printf("\t ESC para salir... \n");
}
void menuLista2(){
    printf("\t -1- Para pasar empleados del archivo a lista2 \n");
    printf("\t -2- Para mostrar lista de empleados de lista2 \n");
    printf("\t -3- Para eliminar el primer nodo2 \n");
    printf("\t -4- Para eliminar lista2 \n");
    printf("\t -5- Para eliminar por dni \n");
    printf("\t -6- Para eliminar ultimo nodo2 \n");
    printf("\t -7- Para eliminar por dni PD \n");
    printf("\t ESC para salir... \n");
}

void menuPila(){
    printf("\t -1- Pasar archivo a pila \n");
    printf("\t -2- Mostrar Pila de empleados \n");
    printf("\t -3- Lista2Pila \n");
    printf("\t -4- Pasar Pila a archivo \n");
    printf("\t -5- Pasar lista a pila \n");
    printf("\t -6- Pasar pila a lista2 \n");
    printf("\t ESC para salir... \n");

}

void menuFila(){
    printf("\t -1- Pasar archivo a fila\n");
    printf("\t -2- Mostrar fila\n");
    printf("\t -3- Lista a fila\n");
    printf("\t ESC para salir... \n");
}

void menuArbol(){
    printf("\t -1- Pasar archivo a arbol \n");
    printf("\t -2- Mostrar preOrder \n");
    printf("\t -3- Mostrar inOrder \n");
    printf("\t -4- Mostrar postOrder \n");
    printf("\t -5- Contra Hojas \n");
    printf("\t -6- Contar cantidad de nodos \n");
    printf("\t -7- Buscar por nombre \n");
    printf("\t -8- Calcular altura arbol \n");
    printf("\t -9- Buscar el menor nodo del arbol \n");
    printf("\t -a- Eliminar nodo arbol \n");
    printf("\t -b- Sumar sueldos de arbol \n");
    printf("\t -c- Pasar arbol a array \n");
    printf("\t -d- Pasar arbol a archivo \n");
    printf("\t ESC para salir... \n");
}

nodo* archivo2lista (char nombreArchivo[], nodo* lista){
    FILE *archi = fopen(nombreArchivo, "rb");
    stEmpleado e;
    if(archi){
        while(fread(&e, sizeof(stEmpleado),1,archi) > 0){
            //lista = agregarAlPrincipio(lista, crearNodo(e));
            lista = agregarEnOrdenDNI(lista,crearNodo(e));
            //lista = agregarAlPrincipioPD(&lista,crearNodo(e));
        }
        fclose(archi);
    }
    return lista;
}


/********************************************************/
/// QUE TENGO Y QUE TENGO QUE PASAR?
nodo* archivo2listaPD (char nombreArchivo[], nodo* lista){ ///PUNTERO SIMPLE
    FILE *archi = fopen(nombreArchivo, "rb");
    stEmpleado e;
    if(archi){
        while(fread(&e, sizeof(stEmpleado),1,archi) > 0){
            agregarAlPrincipioPD(&lista,crearNodo(e));
        }
        fclose(archi);
    }
    return lista;
}

void archivo2listaPDPro (char nombreArchivo[], nodo** lista){ ///PUNTERO DOBLE SIN RETURN
    FILE *archi = fopen(nombreArchivo, "rb");
    stEmpleado e;
    if(archi){
        while(fread(&e, sizeof(stEmpleado),1,archi) > 0){
            agregarAlPrincipioPD(lista,crearNodo(e));
        }
        fclose(archi);
    }
}

void archivo2Pila (char nombreArchivo[], Pila *p){ ///PUNTERO DOBLE SIN RETURN
    FILE *archi = fopen(nombreArchivo, "rb");
    stEmpleado e;
    if(archi){
        while(fread(&e, sizeof(stEmpleado),1,archi) > 0){
            apilar(p,e);
        }
        fclose(archi);
    }
}

void pila2lista(Pila* p, nodo** lista){
    Pila aux;
    inicPila(&aux);
    stEmpleado e;
    while(!pilaVacia(p)){
        e = tope(p);
        agregarAlPrincipio((*lista),crearNodo(e));
    while(!pilaVacia(&aux)){
        apilar(p, desapilar(&aux));
        }
    }
}

void pila2listaDoble(Pila* p, nodo** lista){
    Pila aux;
    inicPila(&aux);
    stEmpleado e;
    while(!pilaVacia(p)){
        e = tope(p);
        agregarAlPrincipio2((*lista),crearNodo2(e));
    while(!pilaVacia(&aux)){
        apilar(p, desapilar(&aux));
        }
    }
}

nodo2* archivo2lista2(char arEmpleados[], nodo2* lista){
    FILE *pArchi = fopen(arEmpleados, "rb");
    stEmpleado c;
    if(pArchi){
        while(fread(&c, sizeof(stEmpleado), 1, pArchi)>0){
            //lista=agregarAlPrincipio2(lista, crearNodo2(c));
            lista=agregarAlFinal2(lista,crearNodo2(c));
        }
        fclose(pArchi);
    }
    return lista;
}

void archivo2fila (char nombreArchivo[], Fila* f){
    FILE *pArchi = fopen(AR_EMPLEADOS, "rb");
    stEmpleado e;
    if(pArchi){
        while(fread(&e, sizeof(stEmpleado),1,pArchi)>0){
            agregar(f,e);
        }
        fclose(pArchi);
    }

}

void lista2Fila (nodo* lista, Fila* f){
    nodo* seg= lista;
    while(seg){
        agregar(f,seg->dato);
        seg=seg->siguiente;
    }
}

void lista2pila (Pila*p, nodo* lista){
    nodo* seg= lista;
    while(seg){
        apilar(p, seg->dato);
        seg = seg->siguiente;
    }
}

void PilaToArch(char nombreArchivo[], Pila* p){
    FILE *archi = fopen(nombreArchivo,"ab");
    Pila *aux;
    stEmpleado e;
    inicPila(&aux);
    if(archi){
        while(!pilaVacia(p)){
            e = tope(p);
            fwrite(&e,sizeof(stEmpleado),1,archi);
            apilar(&aux,desapilar(*p));
        }

        fclose(archi);
    }

}

int lista2arreglo(nodo* lista, stEmpleado e[], int v, int dim){
    nodo* seg = lista;
    while(seg && v<dim){
        e[v]=seg->dato;
        v++;
        seg = seg->siguiente;
    }
    return v;

}

nodoArbol* archivo2Arbol(char nombreArchivo[], nodoArbol* arbol)
{
    stEmpleado e;
    FILE* arch = fopen(nombreArchivo, "rb");

    if(arch)
    {
        while(fread(&e, sizeof(stEmpleado), 1, arch) > 0)
        {
            arbol = insertar(arbol, crearNodoArbol(e));
        }


        fclose(arch);
    }
    return arbol;
}

nodo* arbol2Lista(nodoArbol* arbol, nodo* lista){
    if(arbol){
        lista = arbol2Lista(arbol->izq, lista);
        lista = agregarAlFinal(lista, crearNodo(arbol->dato));
        lista = arbol2Lista(arbol->der, lista);
    }

    return lista;
}


int arbol2Array(nodoArbol* arbol, stEmpleado a[], int v, int dim){
    if(arbol){
        v = arbol2Array(arbol->izq,a,v,dim);
        v = cargaArreglo(a,v,dim, arbol->dato);
        v = arbol2Array(arbol->der,a,v,dim);
    }
    return v;
}

int cargaArreglo(stEmpleado a[], int v, int dim, stEmpleado dato){
    if(v<dim){
        a[v] = dato;
        v++;
    }
    return v;
}

void arbol2archivo(nodoArbol* arbol, char archivo[]){
    FILE *archi = fopen(archivo,"ab");
    stEmpleado e;
    if(archi){
        if(arbol){
            e = arbol->dato;
            fwrite(&e, sizeof(stEmpleado),1,archi);
            arbol2archivo(arbol->izq,archivo);
            arbol2archivo(arbol->der,archivo);
        }
        fclose(archi);
    }
}
/**
   Pseudocodigo para recorrer una coleccion generica
   mientras (la-coleccion-tenga-datos) entonces
        utilizo el-dato-actual
        me-muevo-al-siguiente-dato
   fin-mientras
                            |   arreglo    |        pila      |    archivo          |     lista           |     arbol    |
la-coleccion-tenga-datos      i < validos     !pilavacia()        fread() > 0          lista!=NULL           ya lo veremos
el-dato-actual                  arreglo[i]         tope()         la variable leida     lista                ya lo veremos
me-muevo-al-siguiente-dato        i++            desapilar()      lo hace fread        lista=lista->sig      ya lo veremos
*/
