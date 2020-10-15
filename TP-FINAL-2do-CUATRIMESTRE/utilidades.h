#ifndef UTILIDADES_H_INCLUDED
#define UTILIDADES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <time.h>
#include "clientes.h"

#define AR_CLIENTES "clientes.dat"
#define AR_CONSUMOS "consumos.dat"
#define ESC 27
#define DIM_CLI 100


int randomRango(int rangoMin,int rangoMax);
void menuPrincipal();
void menuClientes();
void menuConsumos();
void intercambio(stCliente *i, stCliente *menor);
int validaEmail(char email[]);


#endif // UTILIDADES_H_INCLUDED
