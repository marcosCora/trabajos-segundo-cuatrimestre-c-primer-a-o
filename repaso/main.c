#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

///constantes

#define ESC 27
#define DIM 30
#define AR_EMPLEADOS "empleados.dat"

///ESTRUCTURAS

typedef struct
{
    char apellido[30];
    char nombre[30];
    char dni[15];
}stPersona;

typedef struct
{
    int id;
    stPersona persona;
    char cuit[15];
    char email[90];
    char domicilioParticular[50];
    char telefonoFijo[15];
    char telefonoCel[15];
    int id_tipo;
    int sueldo;
}stEmpleado;

///PROTOTIPADOS

stEmpleado cargaUnEmpleado();
int validoDNI(char dni[]);
int buscoID();
stEmpleado cargaEmpleArch(stEmpleado e);
void cargaEmpleados();
void muestraMenu();
void muestraUnEmpleado(stEmpleado e);
void muestraArchEmpleado();
int cargaArrayEmple(stEmpleado e[], int dim);
void muestraArrayEmple(stEmpleado e[], int v);
stEmpleado buscaEmpleID(int id);
void buscoEmple();

int main()
{
    char opcion = 0;
    stEmpleado array[DIM];
    int vArray = 0;

    do
    {
        system("cls");
        muestraMenu();
        opcion = getch();
        system("cls");

        switch(opcion)
        {
        case 49:
            cargaEmpleados();
            break;

        case 50:
            muestraArchEmpleado();
            system("pause");
            break;

        case 51:
            vArray = cargaArrayEmple(array, DIM);
            break;

        case 52:
            muestraArrayEmple(array, vArray);
            printf("\n\n");
            system("pause");
            break;

        case 53:
            buscoEmple();
            system("pause");
            break;
        }

    }
    while(opcion != ESC);


    return 0;
}

void muestraMenu()
{
    printf("\t\tEliga una opcion...\n\n");
    printf("1-Carga archivo de empleados.\n");
    printf("2-Muestra archivo de empleados.\n");
    printf("3-Carga array de empleado.\n");
    printf("4-Muestra array de empleados.\n");
    printf("5-Busco empleado por ID.\n");
    printf("\n\nESC para salir.\n");
}


stEmpleado cargaUnEmpleado()
{
    stEmpleado e;
    int existe;
    do
    {
        printf("Ingrese su DNI.................: ");
        fflush(stdin);
        gets(e.persona.dni);

        existe = validoDNI(e.persona.dni);
    }while(existe);

    printf("Nombre.........................: ");
    fflush(stdin);
    gets(e.persona.nombre);

    printf("Apellido.......................: ");
    fflush(stdin);
    gets(e.persona.apellido);

    printf("Cuit...........................: ");
    fflush(stdin);
    gets(e.cuit);

    printf("E-mail.........................: ");
    fflush(stdin);
    gets(e.email);

    printf("Telefono fijo..................: ");
    fflush(stdin);
    gets(e.telefonoFijo);

    printf("Telefono celular...............: ");
    fflush(stdin);
    gets(e.telefonoCel);

    printf("ID empleado....................: ");
    scanf("%d", &e.id_tipo);

    printf("Sueldo.........................: ");
    scanf("%d", &e.sueldo);

    return e;

}


int validoDNI(char dni[])
{
    int flag = 0;
    stEmpleado e;

    FILE *pArchEmpleado = fopen(AR_EMPLEADOS, "rb");

    if(pArchEmpleado)
    {
        while(flag == 0 && fread(&e, sizeof(stEmpleado), 1, pArchEmpleado) > 0)
        {
            if(strcmp(dni, e.persona.dni) == 0)
            {
                flag = 1;
            }
        }
        fclose(pArchEmpleado);
    }


    return flag;
}

int buscoID()
{
    int id = 0;
    stEmpleado e;

    FILE *pArchEmpleados = fopen(AR_EMPLEADOS, "rb");

    if(pArchEmpleados)
    {
        fseek(pArchEmpleados, sizeof(stEmpleado)*(-1), SEEK_END);
        if(fread(&e, sizeof(stEmpleado), 1, pArchEmpleados) > 0)
        {
            id = e.id;
        }
    fclose(pArchEmpleados);
    }


    return id;
}

stEmpleado cargaEmpleArch(stEmpleado e)
{
    FILE *pArchEmpleado = fopen(AR_EMPLEADOS, "ab");

    if(pArchEmpleado)
    {
        fwrite(&e, sizeof(stEmpleado), 1, pArchEmpleado);
        fclose(pArchEmpleado);
    }

}

void cargaEmpleados()
{
    char opcion;
    stEmpleado e;

    while(opcion != ESC)
    {
        printf("Ingrese sus datos:\n\n");

        e = cargaUnEmpleado();
        e.id = buscoID()+1;
        cargaEmpleArch(e);

        printf("\nESC para salir...\n\n");
        fflush(stdin);
        opcion = getch();
        system("cls");
    }

}

void muestraArchEmpleado()
{
    stEmpleado e;

    FILE *pArchEmpleado = fopen(AR_EMPLEADOS, "rb");

    if(pArchEmpleado)
    {
        printf("Esta es la lista de empleados:\n");
        printf("-------------------------------------------------\n");
        while(fread(&e, sizeof(stEmpleado), 1, pArchEmpleado) > 0)
        {
            muestraUnEmpleado(e);
        }
        fclose(pArchEmpleado);
    }
}



void muestraUnEmpleado(stEmpleado e)
{
    printf("DNI......................: %s", e.persona.dni);
    printf("\nNOMBRE...................: %s", e.persona.nombre);
    printf("\nAPELLIDO.................: %s", e.persona.apellido);
    printf("\nCUIT.....................: %s", e.cuit);
    printf("\nE-MAIL...................: %s", e.email);
    printf("\nTELEFONO FIJO............: %s", e.telefonoFijo);
    printf("\nTELEFONO CELULAR.........: %s", e.telefonoCel);
    printf("\nID EMPLEADO..............: %d", e.id_tipo);
    printf("\nSUELDO...................: %d", e.sueldo);
    printf("\n-------------------------------------------------\n");

}

int cargaArrayEmple(stEmpleado e[], int dim)
{
  int v = 0;
  char opcion = 0;

    while(opcion != ESC && v < dim)
    {
        printf("Ingrese sus datos:\n\n");
        e[v] = cargaUnEmpleado();
        v++;

        printf("ESC para salir...");
        opcion = getch();
        system("cls");
    }

  return v;
}

void muestraArrayEmple(stEmpleado e[], int v)
{
    printf("Este es el array de empleados:\n");
    printf("-------------------------------------------------\n");
    for( int i = 0; i<v; i++)
    {
        muestraUnEmpleado(e[i]);
    }
}


void buscoEmple()
{
    int id;
    int ultimoID = 0;
    stEmpleado e;

    do
    {
        printf("Ingrese ID para buscar empleado: ");
        scanf("%d", &id);
        ultimoID = buscoID();
    }
    while(id > ultimoID);

    e = buscaEmpleID(id);
    muestraUnEmpleado(e);


}


stEmpleado buscaEmpleID(int id)
{
    stEmpleado e;
    int flag = 0;

    FILE *pArchEmple = fopen(AR_EMPLEADOS, "rb");

    if(pArchEmple)
    {
        while(flag == 0 && fread(&e, sizeof(stEmpleado), 1, pArchEmple) > 0 )
        {
            if(id == e.id)
            {
                flag = 1;
            }
        }
        fclose(pArchEmple);
    }
    ///fseek(pArchEmple, sizeof(stEmpleado)*(-1), SEEK_CUR);

    return e;
}





