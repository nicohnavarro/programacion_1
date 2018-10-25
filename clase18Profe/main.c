#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"

void mostrar(Cliente* arrayPunteroCliente[],int size)
{
    int i;
    int auxId;
    char auxNombre[50];


    for(i=0;i<size;i++)
    {
        cliente_getIdCliente(arrayPunteroCliente[i],&auxId);
        cliente_getNombre(arrayPunteroCliente[i],auxNombre);
        printf("\nID: %d - NOMBRE: %s", auxId,auxNombre);
    }
}

void guardar(Cliente* arrayPunteroCliente[],int size)
{
    int i;
    int auxId;
    char auxNombre[50];
    FILE* pArchivoBkp = fopen("bkp.txt","w");
    if(pArchivoBkp != NULL)
    {
        for(i=0;i<size;i++)
        {
            cliente_getIdCliente(arrayPunteroCliente[i],&auxId);
            cliente_getNombre(arrayPunteroCliente[i],auxNombre);
            fprintf(pArchivoBkp,"\nID: %d - NOMBRE: %s", auxId,auxNombre);
        }
        fclose(pArchivoBkp);
    }
}

int main()
{
    Cliente *arrayPunteroCliente[1024];
    Cliente *auxiliarPunteroCliente;
    int size=0;
    FILE* pArchivoCliente;
    char bufferId[1024];
    char bufferNombre[1024];
    char bufferApellido[1024];
    char bufferIsEmpty[1024];
    int flagOnce=1;

    pArchivoCliente = fopen("data.csv","r");
    while(!feof(pArchivoCliente))
    {
        if(flagOnce)
        {
            fscanf(pArchivoCliente,"%s\n",bufferId);
            flagOnce = 0;
        }
        fscanf(pArchivoCliente,"%[^,],%[^,],%[^,],%[^\n]\n",
                                        bufferId,
                                        bufferNombre,
                                        bufferApellido,
                                        bufferIsEmpty);

        auxiliarPunteroCliente = cliente_newConParametros(
                                        bufferId,
                                        bufferNombre,
                                        bufferApellido);

        if(auxiliarPunteroCliente != NULL)
        {
            arrayPunteroCliente[size] = auxiliarPunteroCliente;
            size++;
        }
    }
    fclose(pArchivoCliente);


    mostrar(arrayPunteroCliente,size);
    guardar(arrayPunteroCliente,size);
    return 0;
}
