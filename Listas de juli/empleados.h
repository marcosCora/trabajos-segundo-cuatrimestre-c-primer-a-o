#ifndef EMPLEADOS_H_INCLUDED
#define EMPLEADOS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char apellido [30];
    char nombre [30];
    char dni [10];

}stPersona;


typedef struct {
    int id;
    stPersona persona;
    char cuit [15];
    char email[90];
    char domicilioParticular[50];
    char telefonoFijo[15];
    char telefonoCel[15];
    int idTipo;
    int sueldo;
}stEmpleado;

void muestraMenu();
int ultimoIdEmpleado();
int existeDNIEmpleado(char dni []);
stEmpleado cargaUnEmpleado ();
void ingresaEmpleadosArchivo();
void guardaEmpleadoArchivo(char archivoEmpleados[], stEmpleado e);
void muestraArchivoDeEmpleados(char archivoEmpleados []);
int ingresaEmpleadosArray(stEmpleado e[], int v, int dim);
void muestraArregloEmpleados (stEmpleado e[], int v);
int buscaPosicionDNI(char dni []);
int cuentaRegistros(char archivo[], int dataSize);
void funcion01();
void muestraPorPosicion(int pos);
int archivoEmpleados2Arreglo (char archivo [],stEmpleado e [], int v, int dim);



#endif // EMPLEADOS_H_INCLUDED
