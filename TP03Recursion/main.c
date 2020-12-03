#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

///CONSTANTES

#define ESC 27
#define DIM 10
#define AR_ENTEROS "enteros.dat"

///PROTOTIPADOS

void muestraMenu();
int factorial(int f);
int potencia(int num, int pot);
int cargaArrayRand(int a[], int dim);
void muestraArrayIterativo(int a[], int v);
void muestraArrayRecursivo(int a[], int v, int i);
void muestraArrayRecursivoInverso(int a[], int v, int i);
int sumoArrayRecursivo(int a[], int v, int i);
int buscoMenorArrayRecursivo(int a[], int v, int i);
void cargaArchivoEnteros();
void muestraArchivoEnteros();
void abreYmuestraMenor (char nombre[]);
int buscoMenorArchivoRecursivo(FILE *archEnteros);
int arrayCapicuaRecursivo(int a[], int v, int i);
int cuentaArch(FILE *arch);
int leeArch(FILE *arch);
void escribeArch(FILE *arch, int num);
void inviertoArchEnteros(FILE *arch, int p, int f);

int main()
{
    char opcion = 0;

    int numFactorial, resultadoFactorial;

    int numpotencia, elevado, resultadoPotencia;

    int array1[DIM];
    int vArray1 = 0;

    int sumaArray = 0;

    int menorNumArray = 0;

    int flagCapicua;

    int contArch = 0;

    do
    {
        system("cls");
        muestraMenu();
        opcion = getch();
        system("cls");


        switch(opcion)
        {
            case 49:

                printf("Ingrese un numero a factorizar: ");
                scanf("%d", &numFactorial);
                resultadoFactorial = factorial(numFactorial);
                printf("El factorial de ese numero es %d", resultadoFactorial);
                printf("\n\n");
                opcion = getch();
                break;

            case 50:

                printf("Ingrese el numero que desea elevar y luego a cuanto lo desea elevar:\n");
                scanf("%d", &numpotencia);
                scanf("%d", &elevado);
                resultadoPotencia = potencia(numpotencia, elevado);
                printf("la potencia es: %d", resultadoPotencia);
                printf("\n\n");
                opcion = getch();
                break;

            case 51:

                vArray1 = cargaArrayRand(array1, DIM);
                printf("Este es el arreglo mostrado de manera iterativa:\n\n");
                muestraArrayIterativo(array1, vArray1);
                printf("\n\nEste es el arreglo mostrado de manera recursiva:\n\n");
                muestraArrayRecursivo(array1, vArray1, 0);

                printf("\n\n");
                opcion = getch();
                break;

            case 52:

                vArray1 = cargaArrayRand(array1, DIM);
                printf("Este es el arreglo mostrado de manera iterativa:\n\n");
                muestraArrayIterativo(array1, vArray1);
                printf("\n\nEste es el arreglo mostrado de manera inversa recursivamente:\n\n");
                muestraArrayRecursivoInverso(array1, vArray1, 0);

                printf("\n\n");
                opcion = getch();

                break;

            case 53:

                vArray1 = cargaArrayRand(array1, DIM);
                printf("Este es el array:\n\n");
                muestraArrayRecursivo(array1, vArray1, 0);

                sumaArray = sumoArrayRecursivo(array1, vArray1, 0);

                printf("\n\nLa suma del array es de: %d", sumaArray);

                printf("\n\n");
                opcion = getch();

                break;

            case 54:

                vArray1 = cargaArrayRand(array1, DIM);
                printf("Este es el array:\n\n");
                muestraArrayRecursivo(array1, vArray1, 0);

                menorNumArray = buscoMenorArrayRecursivo(array1, vArray1, 0);

                printf("\n\nEl menor numero es: %d", menorNumArray);

                printf("\n\n");
                opcion = getch();

                break;

            case 55:

                cargaArchivoEnteros();
                muestraArchivoEnteros();
                printf("\n\n");

                abreYmuestraMenor(AR_ENTEROS);

                printf("\n\n");
                opcion = getch();

                break;

            case 56:

                ///vArray1 = cargaArrayRand(array1, DIM);
                array1[0] = 2;
                array1[1] = 0;
                array1[2] = 0;
                array1[3] = 2;
                muestraArrayRecursivo(array1, 4, 0);

                flagCapicua = arrayCapicuaRecursivo(array1, 4, 0);

                if(flagCapicua == 0)
                {
                    printf("\n\nEl arreglo es capicua.");
                }
                else
                {
                    printf("\n\nEl arreglo NO es capicua.");
                }

                printf("\n\n");
                opcion = getch();

                break;

            case 57:
                cargaArchivoEnteros();
                printf("\nArchivo normal:\n");
                muestraArchivoEnteros();
                printf("\n\n");

                FILE *archEnteros = fopen(AR_ENTEROS, "r+b");
                if(archEnteros)
                {
                contArch = cuentaArch(archEnteros);

                inviertoArchEnteros(archEnteros, 0, contArch-1);
                printf("\n\nArchivo invertido:\n");
                muestraArchivoEnteros();
                }


                printf("\n\n");
                opcion = getch();

                break;


        }


}
while(opcion != ESC);




    return 0;
}


void muestraMenu()
{
    printf("\t\tQUE FUNCION DESEA RALIZAR?\n\n");
    printf("1-Calcula factorial de un numero de forma recursiva.\n");
    printf("2-Calcula la potencia de un numero de forma recursiva.\n");
    printf("3-Carga arreglo rand y lo muestra iteractivo y recrusivo.\n");
    printf("4-Carga arreglo rand y lo muestra iteractivo y recrusivo de manera inversa.\n");
    printf("5-Suma array de los puntos anterirores.\n");
    printf("6-Busco menor en array rand.\n");
    printf("7-Carga archivo de enteros de manera rand y se busca el menor.\n");
    printf("8-Se fija si un arreglo es capicua o no de forma recursiva. el arreglo es cargado de forma random.\n");
    printf("9-Invierto los valores de un archivo de numeros enteros\n");
    printf("\nESC para salir.\n");
}



///recibe el numero a factorizar
///llama de forma recursiva a la misma funcion
///retorna el numero facotrizado

int factorial(int f)
{
    int rta;

    if(f == 0)
    {
        rta = 1;
    }
    else
    {
        rta = f * factorial(f - 1);
    }

    return rta;
}


///recibe numero y su potencia a elevar
///eleva ese numero a la potencia recibidia que ingreso el usuario
///retorna la potencia de ese numero

int potencia(int num, int pot)
{
    int rta = 0;

    if(pot == 1)
    {
        rta = num;
    }
    else
    {
        rta = num * (potencia(num, pot-1));
    }
    return rta;
}


///carga arreglo random

int cargaArrayRand(int a[], int dim)
{
    int v;
    for(v = 0; v < dim; v++)
    {
        a[v] = rand()%10;
    }

    return v;
}

///muestra arreglo de manera iterativa

void muestraArrayIterativo(int a[], int v)
{
    int i;
    for(i = 0; i < v; i++)
    {
        printf("|%d|-", a[i]);
    }
}

///muestro array de manera recrusiva
///recibo arreglo, validos y subindice

void muestraArrayRecursivo(int a[], int v, int i)
{

    if(i < v)
    {
        printf("|%d|-", a[i]);
        muestraArrayRecursivo(a, v, i+1);
    }

}


///muestro array de manera inversa  recrusivamente
///recibo arreglo, validos y subindice

void muestraArrayRecursivoInverso(int a[], int v, int i)
{

    if(i < v)
    {
        muestraArrayRecursivoInverso(a, v, i+1);
        printf("|%d|-", a[i]);
    }

}


///recibo el arreglo a sumar
///retorno la suma del total

int sumoArrayRecursivo(int a[], int v, int i)
{
    int suma = 0;

    if(i<v)
    {
        suma = a[i] + sumoArrayRecursivo(a, v, i+1);
    }
    return suma;
}

///busca menor elemento de un arreglo de forma recursiva
///recibo el arreglo con sus validos y subindice
///retorno el menor elemnto

int buscoMenorArrayRecursivo(int a[], int v, int i)
{
    int menor, aux;

    if(i == v)
    {
        menor = a[i];
    }
    else
    {
        menor = buscoMenorArrayRecursivo(a, v, i+1);
        if(a[i] < menor)
        {
            aux = a[i];
        }
        else
        {
            aux = menor;
        }
    }
    return aux;
}



///funcion de carga un archivo de enteros con numeros random

void cargaArchivoEnteros()
{
    int cont = 0;
    int num;
    FILE *archEnteros = fopen(AR_ENTEROS, "ab");

    if(archEnteros)
    {
        while(cont < 15)
        {
            num = rand()%50;
            fwrite(&num, sizeof(int), 1, archEnteros);
            cont++;
        }
        fclose(archEnteros);
    }
}

///muestra archivo de numeros enteros cargados de manera rand

void muestraArchivoEnteros()
{
    int num;

    FILE *archEnteros = fopen(AR_ENTEROS, "rb");

    if(archEnteros)
    {
        while(fread(&num, sizeof(int), 1, archEnteros) > 0)
        {
            printf("|%d|-", num);
        }
        fclose(archEnteros);
    }
}


///recibe el nombre del archivo
///muestra el menor del archivo de enteros

void abreYmuestraMenor (char nombre[])
{
    FILE * archEnteros = fopen(nombre, "rb");
    if(archEnteros)
    {
        int menor = buscoMenorArchivoRecursivo(archEnteros);
        printf("El menor es %d", menor);
    }
    else
    {
        printf("nada.");
    }
}


///recibo el puntero al archivo de numeros enteros
///retorno el menor

int buscoMenorArchivoRecursivo(FILE *archEnteros)
{
    int menor;
    int aux;

    if(fread(&aux,sizeof(int),1, archEnteros)==0)
    {
        fseek(archEnteros, -1 * sizeof(int), SEEK_END);

        fread(&menor,sizeof(int),1,archEnteros);
    }
    else
    {
        menor = buscoMenorArchivoRecursivo(archEnteros);
        if(aux<menor)
        {
            menor = aux;
        }
    }
    return menor;

}

///verifico si un arreglo es capicua
///recibo el arreglo, el subindice y los validos
///retorno 0 si es capicua y 1 si NO es capicua

int arrayCapicuaRecursivo(int a[], int v, int i)
{
    int aux;
    int flag = 0;

    if(a[i] == a[v-1])
    {
        aux = arrayCapicuaRecursivo(a, v-1, i+1);
    }
    else
    {
        flag = 1;
    }
    return flag;
}


///funion que recibe el puntero al archivo
///retorna la cantidad de datos que tiene cargado el archivi en este caso de numeros

int cuentaArch(FILE *arch)
{
    int cont = 0;
    fseek(arch, 0, SEEK_END);
    cont = ftell(arch)/sizeof(int);
    return cont;
}

///intercambio archivo
///recibo el puntero al archivo con la cantidad de datos que contiene el archivo y su inicio

void inviertoArchEnteros(FILE *arch, int p, int f)
{
    int principio = 0;
    int fin = 0;

    if(p < f)
    {
        fseek(arch, sizeof(int)*p, SEEK_SET);///mueve el indicador al principio del archivo
        fread(&principio, sizeof(int), 1, arch);///alamceno en principio el numero del primer lugar del archivo


        fseek(arch, f*sizeof(int), SEEK_SET);///mueve el indicador al final del archivo
        fread(&fin, sizeof(int), 1, arch);///en fin almaceno el ultimo numero del archivo

        fseek(arch, f*sizeof(int), SEEK_SET);///voy al fin del archivo
        fwrite(&principio, sizeof(int), 1, arch);///alamceno el numero del principio al final

        fseek(arch, sizeof(int)*p , SEEK_SET);///voy al principio del archivo
        fwrite(&fin, sizeof(int), 1, arch);///paso el numero del final al principio del arch

        inviertoArchEnteros(arch, p+1, f-1);///hago la llamada recurssiva
    }
}





























