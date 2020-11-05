#include "funcionesArch.h"


void guardaRegistroArchivo(char nombreArch[], registroArchivo r)
{
    ///FILE* arch = fopen(nombreArch, "ab");
    FILE* arch = fopen(nombreArch, "ab");

    if(arch)
    {
        fwrite(&r, sizeof(registroArchivo), 1, arch);
        fclose(arch);
    }

}

void mostrarUnRegistro (registroArchivo r)
{
    printf("\n-------------------------------");
    printf("\n ANIMAL.........: %s", r.animal);
    printf("\n CANTIDAD.......: %d", r.cant);
    printf("\n HABITAD........: %d /1-Selva/2-Savana/3-Bosque/4-Mar", r.habitat);
    printf("\n ID ESPECIE.....: %d", r.idEspecie);
    printf("\n ESPECIE........: %s", r.especie);
    ///printf("\n-------------------------------\n");
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
