#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "empleados.h"
#define ESC 27
#define AR_EMPLEADOS "empleados.dat"
#define DIM_EMP 150

/***************************//**
* \brief Funcion que determina el ultimo ID del ultimo registro del archivo de empleados
* \param Lo retorna. Si esta vacio retorna -1
*****************************/
int ultimoIdEmpleado(){
    stEmpleado e;
    int id = -1;
    FILE * pArchEmpleados = fopen(AR_EMPLEADOS, "rb");

    if(pArchEmpleados){

        fseek(pArchEmpleados,sizeof(stEmpleado)*(-1),SEEK_END);
        if(fread(&e,sizeof(stEmpleado),1,pArchEmpleados)>0){
            id=e.id;
        }
        fclose(pArchEmpleados);
    }
    return id;

}

/********************************//**
* \brief Funcion que verifica si existe un dni de empleado en el archivo
* \param Recibe un DNI en cadena de caracteres
* \return Retorna 1 si esta, y 0 si no esta
******************************************/
int existeDNIEmpleado(char dni []) {
    int flag = 0;
    stEmpleado e;

    FILE * pArchEmpleado = fopen(AR_EMPLEADOS, "rb");

    if (pArchEmpleado) {

        while(flag == 0 && fread(&e, sizeof(stEmpleado),1,pArchEmpleado) > 0) {
            if (strcmp(dni, e.persona.dni) == 0){ ///dni == e.persona.dni
                flag = 1;
            }
        }
    }
    return flag;
}
/****************************//**
* \brief Funcion de tipo stEmpleado que carga un dato de tipo stEmpleado
* \return Retorna el empleado cargado
*
**************************************/
stEmpleado cargaUnEmpleado (){

    stEmpleado e;
    int existe;
    e.id=ultimoIdEmpleado()+1;
    do{
        system("cls");
        printf("\nIngrese DNI.....:");
        fflush(stdin);
        scanf(" %s", e.persona.dni);
        existe = existeDNIEmpleado(e.persona.dni);
    }while(existe); ///es igual a while(existe ==1)

    do{
        printf("\nNombre.....:");
        fflush(stdin);
        scanf(" %s", e.persona.nombre);
    }while(strlen(e.persona.nombre)==0);

    printf("\nApellido.....:");
    fflush(stdin);
    scanf(" %s", e.persona.apellido);

    printf("\nEmail.....:");
    fflush(stdin);
    scanf(" %s", e.email);

    printf("\nCuit....:");
    fflush(stdin);
    gets(e.cuit);

    printf("\nDomicilio Particular:....:");
    fflush(stdin);
    gets(e.domicilioParticular);

    printf("\nTelefono Fijo....:");
    fflush(stdin);
    gets(e.telefonoFijo);

    printf("\nCelular....:");
    fflush(stdin);
    gets(e.telefonoCel);

    printf("\nId tipo....:");
    fflush(stdin);
    scanf("%d", &e.idTipo);

    printf("\nSueldo....:");
    fflush(stdin);
    scanf("%d", &e.sueldo);

    return e;
}
/*********************//**
* \brief Funcion que guarda empleado en el archivo
* \param Recibe un empleado cargado y lo guarda
*
********************************/
void guardaEmpleadoArchivo(char archivoEmpleados[], stEmpleado e){

    FILE * pArchEmpleados = fopen(archivoEmpleados, "ab"); ///ab = abrir para añadir
    if(pArchEmpleados){
        fwrite(&e,sizeof(stEmpleado),1,pArchEmpleados);
        fclose(pArchEmpleados);
    }
}


/**********************//**
* \brief Funcion que ingresa empleados en el archivo de empleados
*
*******************************/
void ingresaEmpleadosArchivo(){

    stEmpleado e;
    char opcion;

    do{
        e = cargaUnEmpleado();
        guardaEmpleadoArchivo(AR_EMPLEADOS,e);
        printf("\n Ingrese ESC para salir...");
        fflush(stdin);
        opcion=getch();

    }while(opcion != 27);
}

/**********************//**
* \brief Funcion que recibe un emleado y lo muestra
*
*****************************/
void mostrarUnEmpleado(stEmpleado e){

      printf("\n-------------------------------\n");
      printf("\nNombre:%s",e.persona.nombre);
      printf("\nApellido:%s",e.persona.apellido);
      printf("\nDni:%s",e.persona.dni);
      printf("\nCuil:%s",e.cuit);
      printf("\nE-mail:%s",e.email);
      printf("\nDomicilio Particular:%s",e.domicilioParticular);
      printf("\nTelefono Fijo:%s",e.telefonoFijo);
      printf("\nTelefono Celular:%s",e.telefonoCel);
      printf("\nId Tipo:%d",e.idTipo);
      printf("\nSueldo:%d\n",e.sueldo);
      printf("\n-------------------------------\n");
}

/*********************//**
* \brief Funcion que muestra archivo de empleados
* \param Recibe el nombre del archivo
*
****************************/
void muestraArchivoDeEmpleados(char archivoEmpleados []){

   stEmpleado e;
   FILE*pArchEmpleados=fopen(AR_EMPLEADOS,"rb");

   printf("\n\tListado de Empleados\n");
   if(pArchEmpleados){
    while(fread(&e,sizeof(stEmpleado),1,pArchEmpleados)>0){
        mostrarUnEmpleado(e);
    }
    fclose(pArchEmpleados);
   }

}

/************************//**
* \brief Funcion que ingresa empleados en un array de stEmpleado
* \param Recibe el arreglo, validos, dimension
* \return Retorna los validos
*
****************************/
int ingresaEmpleadosArray(stEmpleado e[], int v, int dim){

    char opcion =0; ///Iniciamos a 0 para que no tenga basura

    while(opcion!=27 && v < dim){

        e[v] = cargaUnEmpleado();
        v++;

        printf("\n Ingrese ESC para salir...");
        fflush(stdin);
        opcion=getch();

    }

        return v;
}

/******************//**
* \brief Funcion que muestra un arreglo de stEmpleado
* \param Recibe el arreglo y sus validos
*********************/
void muestraArregloEmpleados (stEmpleado e[], int v){
    for(int i=0;i<v;i++){
        mostrarUnEmpleado(e[i]);
    }
}
/*****************************//**
* \brief Funcion que busca la posicion fisica en un registro por DNI
* \param Recibe el DNI
* \return Retorna -1 si no fue encontrado, si fue encontrado la posicion correspondiente
***********************************/
int buscaPosicionDNI(char dni []){
    int pos=-1;
    stEmpleado e;
    FILE * pArchEmpleados = fopen(AR_EMPLEADOS, "rb");
    if (pArchEmpleados){
        while(pos == -1 && fread(&e, sizeof(stEmpleado),1,pArchEmpleados) > 0){
            if(strcmp(dni, e.persona.dni) == 0){
                pos = ftell(pArchEmpleados)/sizeof(stEmpleado)-1;
            }
        }
        fclose(pArchEmpleados);
    }
    return pos;

}
/**********************//**
* \brief Funcion que cuenta la cantidad de registros de tipo stEmpleado
* \param Recibe el nombre del archivo
* \return Retorna el numero de registros cargados en el archivo
*********************************/
int cuentaRegistros(char archivo[], int dataSize){
    int registros=0;
    stEmpleado e;

    FILE * pArchEmpleados = fopen(AR_EMPLEADOS, "rb");
    if (pArchEmpleados){
       while(fread(&e,sizeof(stEmpleado),1,pArchEmpleados)>0){
            fseek(pArchEmpleados,0,SEEK_END);
            registros = ftell(pArchEmpleados)/dataSize;
       }
       fclose(pArchEmpleados);
    }
    return registros;

}

void muestraPorPosicion(int pos)
{
    stEmpleado e;
    int registros =0;
    FILE * pArchEmpleados = fopen(AR_EMPLEADOS, "rb");

    registros = cuentaRegistros(AR_EMPLEADOS, sizeof(stEmpleado));

    if (pArchEmpleados)
    {
        if(pos >=0 && pos < registros)
        {
            fseek(pArchEmpleados,sizeof(stEmpleado)*pos,1);
            fread(&e,sizeof(stEmpleado),1,pArchEmpleados);
            mostrarUnEmpleado(e);

        }
        fclose(pArchEmpleados);

    }

}
void funcion01(){
    char dato [30];
    int pos =0;
    printf("\t\n Ingrese el DNI del empleado que busca:...");
    fflush(stdin);
    scanf(" %s", &dato);

    pos = buscaPosicionDNI(dato);

    muestraPorPosicion(pos);
}

int archivoEmpleados2Arreglo (char archivo [],stEmpleado e [], int v, int dim){
    FILE * pArchEmpleados = fopen(archivo, "rb");
    if(pArchEmpleados){
        while(v<dim && fread(&e[v],sizeof(stEmpleado),1,pArchEmpleados)>0){
            v++;
        }
        fclose(pArchEmpleados);
    }
    return v;
}

int archivoCompletoEmpleados2Arreglo (char archivo [],stEmpleado e [], int dim){
    int v = cuentaRegistros(AR_EMPLEADOS,sizeof(stEmpleado));
    ///v = (v<dim)?dim:v;
    FILE * pArchEmpleados = fopen(archivo, "rb");
    if(pArchEmpleados){
        while(v<dim && fread(&e[v],sizeof(stEmpleado),1,pArchEmpleados)>0){
            v++;
        }
        fclose(pArchEmpleados);
    }
    return v;
}

///CAMBIAR LA FUNCION DE CUNTA REGISTROS, NECESITA RECIBIR EL SIZEOF TAMBIEN
