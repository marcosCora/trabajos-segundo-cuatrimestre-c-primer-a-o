#include "ADL.h"
#include "listasRegistros.h"

registroArchivo cargaUnRegistro()
{
    registroArchivo r;

    printf("Ingrese ID de materia: ");
    scanf("%d", &r.idMateria);

    printf("Ingrese el legajo: ");
    scanf("%d", &r.legajo);

    printf("Ingrese la materia: ");
    fflush(stdin);
    gets(r.materia);

    printf("Ingrese La nota: ");
    scanf("%d", &r.nota);

    printf("Ingrese nombre y apellido: ");
    fflush(stdin);
    gets(r.nombreApe);

    return r;
}


void guardaRegistroArchivo(char nombreArch[], registroArchivo r)
{
    FILE* arch = fopen(nombreArch, "ab");

    if(arch)
    {
        fwrite(&r, sizeof(registroArchivo), 1, arch);
        fclose(arch);
    }

}


void ingresaRegistrosArchivo()
{
    registroArchivo r;
    char opcion;

    while(opcion != ESC)
    {
        r = cargaUnRegistro();
        guardaRegistroArchivo(AR_REGISTROS, r);

        printf("ESC para salir...\n\n");
        fflush(stdin);
        opcion = getch();

    }

}


void mostrarUnRegistro (registroArchivo r){
    printf("\n-------------------------------");
    printf("\n Id Materia: %d", r.idMateria);
    printf("\n Legajo: %d", r.legajo);
    printf("\n Materia: %s", r.materia);
    printf("\n Nota: %d", r.nota);
    printf("\n Nombre y apellido: %s", r.nombreApe);
    printf("\n-------------------------------\n");
}

void muestraArchivoDeRegistros(char archivo[])
{
    registroArchivo r;
    FILE* arch = fopen(archivo, "rb");

    if(arch)
    {
        while(fread(&r,sizeof(registroArchivo),1,arch) > 0)
        {
            mostrarUnRegistro(r);
        }
        fclose(arch);
    }
}




















