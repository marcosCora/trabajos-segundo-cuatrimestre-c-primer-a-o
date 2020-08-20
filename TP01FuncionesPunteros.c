#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

///constantes

#define ESC 27
#define DIM 10
#define FILAS 12
#define COLUMNAS 31
#define MAX_CHAR 50

///prototipados

void muestraMenu();
void inicializoArrayInt(int a[], int dim);
void muestraArrayInt(int a[], int v);
int cargaArrayInt(int a[], int dim);
int sumaArrayInt(int a[], int v);
int conteoArrayInt(int a[], int v);
float promedioArrayInt(int a[], int v);
int cargaString (char a[], int dim);
void muestraString (char a[], int v);
void inviertoString (int v, char a[]);
int buscoPosMax(int a[], int v);
int arrayToDecimal (int a[], int v);
void cargaMatrizRand(int filas, int columnas, int m[filas][columnas]);
void muestroMatriz(int filas, int columnas, int m[filas][columnas]);
int buscoMayorPrecipitacion(int mes, int columnas, int a[mes][columnas]);
int arrayPrecipitaciones(int filas, int columnas, int m[filas][columnas], int a[]);
int palindromo (char c []);
void intercambio (int *i, int *a);
int ordenoArray(int vA, int vB, int a[], int b[], int c[], int dim);
int cargaArrayParalelo(int edades[], int chars, char apellido[][chars], int dim);
void muestraArrayParalelo(int edades[], int chars, char apellido[][chars], int v);
int cargaRandArray(int a[], int dim);
int buscaMoyorArray(int a[], int v);
int buscaMenorArray(int a[], int v);
void punto10(int a[], int dim, int *mayor, int *menor, float *promedio);


int main()
{
    char opcion;
    int arrayInt[DIM];
    int VarrayInt = 0;
    float promedio = 0;

    char arrayChar[DIM];
    int vArrayChar = 0;

    int posMayor = 0;
    int decimal = 0;

    int palindromoFlag = 0;

    int precipitaciones[FILAS][COLUMNAS];

    int arrayA[DIM];
    int vArrayA = 0;
    int arrayB[DIM];
    int vArrayB = 0;
    int arrayC[DIM];
    int vArrayC = 0;

    int edades[DIM];
    char apellidos[DIM][MAX_CHAR];
    int vParalelos = 0;
    int mayorEdad = 0;

    int mayor = 0;
    int menor = 0;

    int max, mes;
    int arrayPrecipitacones[FILAS];
    int vArrayPrecipitaciones = 0;


    do
    {
        system("cls");
        muestraMenu();
        opcion = getch();
        system("cls");

        switch(opcion)
        {
        case 49:
            inicializoArrayInt(arrayInt, DIM);
            printf("Este es el arreglo inicializado:\n\n");
            muestraArrayInt(arrayInt, DIM);
            printf("\n\n");
            system("pause");
            system("cls");

            VarrayInt = cargaArrayInt(arrayInt, DIM);
            printf("Este es el arreglo de enteros:\n\n");
            muestraArrayInt(arrayInt, VarrayInt);
            opcion = getch();

            promedio = promedioArrayInt(arrayInt, VarrayInt);
            system("cls");

            printf("Este es el promedio del array: %.2f", promedio);
            opcion = getch();

            break;

        case 50:

            vArrayChar = cargaString(arrayChar, DIM);

            printf("Este es el arreglo de string:\n\n");
            muestraString(arrayChar, vArrayChar);
            printf("\n\n");
            opcion = getch();

            inviertoString(vArrayChar, arrayChar);
            printf("\nEste es el string invertido: \n\n");
            muestraString(arrayChar, vArrayChar);
            opcion = getch();

            break;

        case 51:

            posMayor = buscoPosMax(arrayInt, VarrayInt);
            printf("El mayor numero se encuentra en la posicion %d", posMayor);
            opcion = getch();

            break;

        case 52:

            decimal = arrayToDecimal(arrayInt, VarrayInt);
            printf("NRO de arreglo en decimal = %d", decimal);
            opcion = getch();

            break;

        case 53:

            cargaMatrizRand(FILAS, COLUMNAS, precipitaciones);
            muestroMatriz(FILAS, COLUMNAS, precipitaciones);
            opcion = getch();

            printf("\n\nIngrese el mes a buscar mayor precipitacion: ");
            scanf("%d", &mes);
            mes--;

            max = buscoMayorPrecipitacion(mes, COLUMNAS, precipitaciones);

            printf("\n\nEsta es la mayor precipitacion de el mes seleccionado: %d", max);

            opcion = getch();

            vArrayPrecipitaciones = arrayPrecipitaciones(FILAS, COLUMNAS, precipitaciones, arrayPrecipitacones);
            printf("\n\nEste es el array con las maximas precipitaciones de cada mes del a%co:\n\n", 164);
            muestraArrayInt(arrayPrecipitacones, vArrayPrecipitaciones);

            opcion = getch();

            break;

        case 54:

            printf("Ingrese una palabra: ");
            fflush(stdin);
            scanf("%s", arrayChar);
            printf("\n\n");

            palindromoFlag = palindromo(arrayChar);

            if(palindromoFlag == 0)
            {
                printf("\nLa palabra   %s  es palindromo.", arrayChar);
            }
            else
            {
                printf("\nLa palabra  %s  NO es palindromo.", arrayChar);
            }
            opcion = getch();

            break;

        case 55:

            printf("Cargue el Array A:\n");
            vArrayA = cargaArrayInt(arrayA, DIM);
            system("cls");
            printf("Cargue el Array B:\n");
            vArrayB = cargaArrayInt(arrayB, DIM);

            printf("Este es el array A:");
            muestraArrayInt(arrayA, vArrayA);
            printf("\n\nEste es el array B:");
            muestraArrayInt(arrayB, vArrayB);

            opcion = getch();

            vArrayC = ordenoArray(vArrayA, vArrayB, arrayA, arrayB, arrayC, DIM);

            printf("\n\nEste es el arreglo C:\n");
            muestraArrayInt(arrayC, vArrayC);
            opcion = getch();

            break;

        case 56:

            printf("Ingrese sus datos:\n\n");
            vParalelos = cargaArrayParalelo(edades, MAX_CHAR, apellidos, DIM);

            printf("Estas son las personas:\n\n");
            muestraArrayParalelo(edades, MAX_CHAR, apellidos, vParalelos);
            opcion = getch();
            system("cls");

            mayorEdad = buscoPosMax(edades, vParalelos);
            printf("Esta es la persona con mayor edad:\n");
            printf("Apellido.....: %s", apellidos[mayorEdad]);
            printf("\nEdad.........: %d", edades[mayorEdad]);
            printf("\n---------------------------------------\n");

            opcion = getch();

            break;

        case 57:

            punto10(arrayInt, DIM, &mayor, &menor, &promedio);
            printf("\n\n");
            printf("MAYOR: %d\nMENOR: %d\nPROMEDIO: %.2f", mayor, menor, promedio);
            opcion = getch();

            break;
        }


    }while(opcion != ESC);




    return 0;
}

void muestraMenu()
{
    printf("\t\tEscoga una opcion...\n\n");
    printf("1-Carga arreglo de enteros y se saca su promedio.\n");
    printf("2-Carga arreglo de caracteres y lo invierte.\n");
    printf("3-Busca y retorna la posicion del mayor valor del arreglo de la opcion 1.\n");
    printf("4-Paso de arreglo a numero decimal(arreglo del ejercicio 1)\n");
    printf("5-Muestro las precipitaciones de el a%co y hago la terea correspondeinte\n", 164);
    printf("6-Verifico si una palabra es palindromo\n");
    printf("7-Carga dos arreglos ordenados y lo intercambia en uno ordenado\n");
    printf("8-Carga edad y apellido. Buesca apellido de mayor edad\n");
    printf("9-Saca promedio, mayor y menor de un arreglo cargado rand\n");
    printf("\n\tESC para salir.");
}

/**********************************//**
/*\brief inicializo arreglo en -1
/*\param recibo arreglo
/*\param recibo dimension
/**************************************/

void inicializoArrayInt(int a[], int dim)
{
    int i;
    for(i = 0; i<dim; i++)
    {
        a[i] = -1;
    }
}

void muestraArrayInt(int a[], int v)
{
    int i = 0;
    for(i = 0; i<v; i++)
    {
        printf("|%d|-", a[i]);
    }
}

int cargaArrayInt(int a[], int dim)
{
    char opcion = 0;
    int v = 0;

    while(opcion != ESC && v < dim)
    {
        printf("Ingrese numero entero: ");
        scanf("%d", &a[v]);
        v++;

        printf("Esc para salir...");
        opcion = getch();
        system("cls");
    }

    return v;
}

int sumaArrayInt(int a[], int v)
{
    int i, suma = 0;
    for(i = 0; i<v; i++)
    {
        suma+= a[i];
    }

    return suma;
}

int conteoArrayInt(int a[], int v)
{
    int i, conteo = 0;

    for(i = 0; i<v; i++)
    {
        conteo++;
    }

    return conteo;
}


float promedioArrayInt(int a[], int v)
{
   int suma, conteo;
   float promedio = 0;

   suma = sumaArrayInt(a, v);
   conteo = conteoArrayInt(a, v);

   promedio = (float)suma/conteo;

   return promedio;

}


///carga arreglo de caracteres

int cargaString (char a[], int dim)
{
    char opcion = 0;
    int v = 0;
    while(opcion != ESC && v < dim)
    {
        printf("Ingrese una letra: ");
        fflush(stdin);
        scanf("%c", &a[v]);
        v++;

        printf("ESC para salir...");
        opcion = getch();
        system("cls");
    }


    return v;
}


///muestra array caracteres

void muestraString (char a[], int v)
{
    int i;

    for(i = 0; i<v; i++)
    {
        printf("|%c| -", a[i]);
    }
}


///invierto arreglo

void inviertoString (int v, char a[])
{
    int i = 0;
    int f = v-1;
    char aux = 0;

    while( i <= f )
    {
        aux = a[i];
        a[i] = a[f];
        a[f] = aux;
        i++;
        f--;

    }

}


///busca posicion mayor en arreglo int

int buscoPosMax(int a[], int v)
{
    int i = 0;
    int pos;
    int mayor = a[i];

    for(i = 1; i<v; i++)
    {
        if(mayor < a[i])
        {
            pos = i;
            mayor = a[i];
        }
    }
    return pos;
}

///de arreglo a numero decimal

int arrayToDecimal (int a[], int v)
{
    int i=0;
    int x=v;
    int acum=0;
    while (i<v)
    {
        acum = acum + (a[i]*pow(10,(x-1)));
        i++;
        x--;
    }

    return acum;
}


///EJERCICIO 5----------------------------------------------------------------------------

///matriz aleatoria de precipitaciones

void cargaMatrizRand(int filas, int columnas, int m[filas][columnas])
{
    int f, c;

    for(f = 0; f < filas; f++)
    {
        for(c = 0; c < columnas; c++)
        {
            m[f][c] = rand()%25;
        }
    }
}

///muestro matriz de precipitaciones

void muestroMatriz(int filas, int columnas, int m[filas][columnas])
{
    int f, c;

    for(f = 0; f < filas; f++)
    {
        for(c = 0; c < columnas; c++)
        {
            printf("|%d|", m[f][c]);
        }
        printf("\n");
    }
}

///recibo el mes y busco su mayor precipitacion

int buscoMayorPrecipitacion(int mes, int columnas, int a[mes][columnas])
{
    int max = 0;
    int c = 0;

    max = a[mes][c];

    for(c = 1; c<columnas; c++)
    {
        if(a[mes][c] > max)
        {
            max = a[mes][c];
        }
    }
    return max;
}

///cargo array con las maximas precipitaciones de cada mes

int arrayPrecipitaciones(int filas, int columnas, int m[filas][columnas], int a[])
{
    int v;
    int mes = 0;
    int max = 0;

    for(v = 0; v<filas; v++)
    {
        max = buscoMayorPrecipitacion(mes, columnas, m);
        a[v] = max;
        mes++;
    }
    return v;
}


///--------------------------------------------------------------------------------------------

int palindromo (char c [])
{

    int longitud = strlen(c);
    int x=longitud-1;
    int i=0;
    int flag=0;

    while(i<longitud)
    {
        printf("Comparando posicion %d (%c) con %d (%c)\n", i, c[i], x, c[x]);
        if(c[i]==c[x])
        {
            flag=0;
        }
        else
        {
            flag=1;
        }
        i++;
        x--;
    }
    return flag;
}


///intercambio de variables

void intercambio (int *i, int *a)
{
    int aux;
    aux = *i;
    *i = *a;
    *a = aux;
}




///intercambio array a uno ordenado

int ordenoArray(int vA, int vB, int a[], int b[], int c[], int dim)
{
    int vC = 0;
    int iA = 0;
    int iB = 0;

    while(vC < dim && iA < vA && iB < vB)
    {
        if(a[iA] < b[iB])
        {
            c[vC] = a[iA];
            vC++;
            iA++;
        }
        else
        {
            c[vC] = b[iB];
            vC++;
            iB++;
        }
    }

    return vC;
}



///carga arreglos paralelos

int cargaArrayParalelo(int edades[], int chars, char apellido[][chars], int dim)
{
    int v = 0;
    char opcion = 0;

    while(opcion != ESC && v < dim)
    {
        printf("Ingrese su apellido: ");
        fflush(stdin);
        gets(apellido[v]);

        printf("Ingrese su edad: ");
        scanf("%d", &edades[v]);
        v++;

        printf("ESC para salir");
        opcion = getch();
        system("cls");
    }



    return v;
}

///muestra arreglo paralelo

void muestraArrayParalelo(int edades[], int chars, char apellido[][chars], int v)
{
    int i;

    printf("\n---------------------------------------\n");
    for(i = 0; i<v; i++)
    {
      printf("Apellido.....: %s", apellido[i]);
      printf("\nEdad.........: %d", edades[i]);
      printf("\n---------------------------------------\n");
    }


}

///carga random de arreglo

int cargaRandArray(int a[], int dim)
{
    int v;

    for(v = 0; v<dim; v++)
    {
        a[v] = rand()%25;
    }
    return v;
}


///punto 10

void punto10(int a[], int dim, int *mayor, int *menor, float *promedio)
{
    int v = 0;

    v = cargaRandArray(a, dim);
    muestraArrayInt(a, v);

    *mayor = buscaMoyorArray(a, v);
    *menor = buscaMenorArray(a, v);
    *promedio = promedioArrayInt(a, v);

}

int buscaMoyorArray(int a[], int v)
{
    int i = 0;
    int mayor = a[i];

    for(i = 1; i<v; i++)
    {
        if(a[i] > mayor)
        {
            mayor = a[i];
        }
    }

    return mayor;
}

int buscaMenorArray(int a[], int v)
{
    int i = 0;
    int menor = a[i];

    for(i = 1; i<v; i++)
    {
        if(a[i] < menor)
        {
            menor = a[i];
        }
    }

    return menor;
}

