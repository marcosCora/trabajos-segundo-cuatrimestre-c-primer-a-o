#include "adl.h"

///FUNCIONES DE LISTA

nodo* inicLista()
{
    return NULL;
}

nodo* crearNodo(stPaciente dato)
{
    nodo* nuevo = (nodo*) malloc(sizeof(nodo));
    nuevo->dato = dato;
    nuevo->siguiente = NULL;

    return nuevo;
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

void muestraUnPaciente(stPaciente p)
{
    printf("\n-------------------------------------------------------\n");
    printf("\n ID registro.................: %d ", p.idRegistro);
    printf("\n ID paciente.................: %d ", p.idPaciente);
    printf("\n Nombre......................: %s ", p.nombrePaciente);
    printf("\n Apellido....................: %s ", p.apellidoPaciente);
    printf("\n Diagnostico.................: %s ", p.diagnostico);
    printf("\n Fecha de atencion...........: %s ", p.fechaAtencion);
    printf("\n Doctor......................: %s ", p.nombreDoctor);
     printf("\n-------------------------------------------------------\n");
}

void muestraNodo(nodo* aMostrar)
{
   muestraUnPaciente(aMostrar->dato);
}


void mostrarLista(nodo* lista)
{
    nodo* aux = lista;
    while(aux != NULL)
    {
        muestraNodo(aux);
        aux = aux->siguiente;
    }
}

///FUNCIONES ADL



/// Funcion que retorna la posicion de una materia en el arreglo
/// Recibe el arreglo, validos, la materia a buscar
/// Retorna -1 si la materia no existe

int buscaPosicionArregloEspecialidad(stEspecialidadMedica adl[], int v, char especialidad[])
{
    int pos = -1;
    int i =0;
    while(i<v && pos == -1)
    {
        if(strcmpi(adl[i].especialidadMedica, especialidad)==0)
        {
            pos = i;
        }
        i++;
    }
    return pos;
}



/// Funcio que agrega una materia al arreglo stCelda
/// Recibe el arreglo, los validos y la materia a agregar
/// Retorna los validos

int agregarAarregloADL(stEspecialidadMedica adl[], int v, char especialidad[], int idEspecialidad)
{
    strcpy(adl[v].especialidadMedica, especialidad); ///en la primer pos libre copiamos la materia en el arreglo
    adl[v].idEspecialidad = idEspecialidad;
    adl[v].listaDePacientes = inicLista(); ///inicio lista
    v++;
    return v;
}



/// Funcio
/// Recibe el arreglo, un alumno, materia y ID de materia
///Retorna los validos

int alta(stEspecialidadMedica adl[], int v, stPaciente p, char especialidad[], int idEspecialidad)
{


    nodo* aux = crearNodo(p);
    int pos = buscaPosicionArregloEspecialidad(adl,v, especialidad);
    if(pos == -1)
    {
        v = agregarAarregloADL(adl,v,especialidad, idEspecialidad);
        pos = v - 1;
    }
    adl[pos].listaDePacientes = agregarAlFinal(adl[pos].listaDePacientes, aux);
    return v;
}


int archivo2adl(char archivo[], stEspecialidadMedica adl[], int v, int dim)
{
    stRegistroMedico registro;
    stPaciente paciente;
    int idEspecialidad;
    char especialidad[30];

    FILE* archi = fopen(archivo, "rb");
    if(archi)
    {
        while(v < dim && fread(&registro,sizeof(stRegistroMedico),1,archi) > 0)
        {
            idEspecialidad = registro.idEspecialidad;
            strcpy(especialidad,registro.especialidadMedica);
            strcpy(paciente.apellidoPaciente,registro.apellidoPaciente);
            strcpy(paciente.diagnostico,registro.diagnostico);
            strcpy(paciente.fechaAtencion, registro.fechaAtencion);
            paciente.idPaciente = registro.idPaciente;
            paciente.idRegistro = registro.idRegistro;
            strcpy(paciente.nombreDoctor, registro.nombreDoctor);
            strcpy(paciente.nombrePaciente, registro.nombrePaciente);
            v = alta(adl, v, paciente, especialidad, idEspecialidad);
        }

        fclose(archi);
    }

    return v;
}

void muestraADL (stEspecialidadMedica adl[], int v)
{
    int i=0;
    while(i<v)
    {
        printf("\n\nID especialidad.....: %d\n", adl[i].idEspecialidad );
        printf("Especialidad........: %s\n", adl[i].especialidadMedica);
        mostrarLista(adl[i].listaDePacientes);
        i++;
    }
}

///EJERCICIO 2

int cargaNuevaEspecialidad(stEspecialidadMedica adl[], int v, int dim)
{
    int  i=0;
    char especialidad[25];
    int idEspecialidad;
    char opcion;
    do
    {
        system("cls");
        printf("Ingrese la especialidad nueva: \n");
        fflush(stdin);
        gets(especialidad);
        idEspecialidad = v;
        v = agregarAarregloADL(adl, v, especialidad, idEspecialidad);

        printf("ESC para salir... \n");
        opcion = getch();

    }
    while(v < dim && opcion != 27);

    return v;

}


///EJERCICIO 4

/*int cargaNuevoEspecialidad(stEspecialidadMedica adl[], int validos, stEspecialidad e, stPaciente p)
{
    nodoLista* nuevo = crearNodo(p);
    int pos = buscaPosicion(adl, validos, e);
    if(pos == -1)
    {
        validos = agregarEspecialidad(adl, validos, e);
        pos = validos-1;
    }
    adl[pos].lista = agregarPpio(adl[pos].lista, nuevo);

    return validos;
}*/

///EJERCICIO 7

int buscaPacienteEspecialidad(stEspecialidadMedica adl[], int v, char nombre[], char apellido[], char especialidad[])
{
    int flag = 0;
    int i = 0;
    int pos = buscaPosicionArregloEspecialidad(adl, v, especialidad);
    if(pos != -1)
    {
        flag = buscaPacienteEnLista(adl[pos].listaDePacientes, nombre, apellido, flag);
        i++;

    }
    else
    {
        printf("No existe esa especialidad...\n");
    }

    return flag;
}


int buscaPacienteEnLista(nodo* lista, char nombre[], char apellido[], int flag)
{
    nodo* aux = lista;



    while(aux != NULL && flag == 0)
    {
        if(strcmpi(aux->dato.nombrePaciente, nombre) == 0 && strcmpi(aux->dato.apellidoPaciente, apellido) == 0)
        {
            flag = 1;
        }
        aux = aux->siguiente;
    }

    return flag;
}












