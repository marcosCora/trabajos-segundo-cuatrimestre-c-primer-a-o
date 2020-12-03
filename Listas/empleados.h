#ifndef EMPLEADOS_H_INCLUDED
#define EMPLEADOS_H_INCLUDED
#include <stdio.h>
#include <conio.h>

#define ESC 27
#define AR_EMPLEADOS "archEmpleados.dat"

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

stEmpleado cargaUnEmpleado();
int validoDNI(char dni[]);
void muestraUnEmpleado(stEmpleado e);
void cargaEmpleados();
stEmpleado cargaEmpleArch(stEmpleado e);
void muestraArchEmpleado();

#endif // EMPLEADOS_H_INCLUDED
