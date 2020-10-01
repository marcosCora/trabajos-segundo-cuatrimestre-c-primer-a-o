#include "empleados.h"

stEmpleado cargaUnEmpleado()
{
    stEmpleado e;

    printf("Ingrese su DNI.................: ");
    fflush(stdin);
    gets(e.persona.dni);


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

///carga de empleados

void cargaEmpleados()
{
    char opcion;
    stEmpleado e;

    while(opcion != ESC)
    {
        printf("Ingrese sus datos:\n\n");

        e = cargaUnEmpleado();
        cargaEmpleArch(e);

        printf("\nESC para salir...\n\n");
        fflush(stdin);
        opcion = getch();
        system("cls");
    }

}

///carga archivo de empleados

stEmpleado cargaEmpleArch(stEmpleado e)
{
    FILE *pArchEmpleado = fopen(AR_EMPLEADOS, "ab");

    if(pArchEmpleado)
    {
        fwrite(&e, sizeof(stEmpleado), 1, pArchEmpleado);
        fclose(pArchEmpleado);
    }

}

///muestra archivo de empleados

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
