/*
No usar Ruta absoluta
Usar Ruta relativa

FILE* pArchivo
"r"Lectura
"w"Escritura
"a"
"r+"
"w+"
En la misma funcion hay que cerrarlo
fclose(FILE* pArchivo);
fwrite(void*origen, tamaño(sizeof(), cantidad(int),FILE *arch);
fread(void*destino(a donde),tamaño,cantidad,FILE* arch);
Siempre verificar si es NULL
Cualquier nombre y cualquier extension . ext

TERMINAL
ls - la
chmod -w archivo.ext (lectura)
chmod +w archivo.ext (escritura)
chmod +x archivo.ext (ejecucion)
cat archivo(Lo que dice el archivo

stdout Archivo de consola

Arrancar desde Cero
Generar Estructuras
./generarSettersGetters enter nombre de la entidad;

recibir el id como char* y en el momento del newconParametros atoi()
en todos los Sets agregar el isValidCampos retorno 1
Una vez que tengo las entidades solucionadas
Empiezo con la aplicacion
Array de punteros a cliente
ARRAY DE PUNTEROS A VOID
void mostrar(Cliente* arrayPunteroCliente[],int size)

{
    int i;
    int auxId;
    char auxNombre[50];

    for(i=0;i<size;i++)
    {
        cliente_getIdCliente(arrayPunteroCliente[i],&auxId);
        cliente_getNombre(arrayPunteroCliente[i],auxNombre);
        printf("\nID: %d - NOMBRE %s", auxId,auxNombre);
    }
}



Cliente *arrayPunteroClientes[1024];
int size=0;

FILE* pArchivoCliente;
Cliente *auxiliarPunteroCliente;
char bufferId[1024];
char bufferName[1024];
char bufferLastName[1024];
char bufferIsEmpty[1024];
int flagOnce=1;
pArchivoCliente=fopen("data.ext","r"); solo lectura
while(!feof(pArchivoCliente))
{
    if(flagOnce)
        {
            fscanf(pArchivoCliente,"%s\n",bufferId);
            flagOnce=0;
        }

    fscanf(pArchivoCliente,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId,
                                                        bufferName,
                                                        bufferLastName,
                                                        bufferIsEmpty);

    cliente_newConParametros(bufferId,bufferName,bufferLastName,bufferIsEmpty);
    if(auxiliarPunteroCliente!=NULL)
    {
        arrayPunteroCliente[size]=auxiliarPunteroCliente;
        size++;
    }
    //printf("%s\n",bufferId);

}
fclose(pArchivoCliente);



*/
#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
int main()
{
    //char bufferNombre[1024];
    //char bufferApellido[1024];
    //char bufferId[1024];
    //char nombre[]="Nicolas";
    //char apellido[]="Navarro";
    //int id=100;
    //FILE* pArchivo;
    /*
    pArchivo=fopen("archivo.ext","w");
    if(pArchivo!=NULL)
    {
        //fprintf(stdout,"%d,%s,%s\n",id,nombre,apellido); En la consola
        fprintf(pArchivo,"%d,%s,%s\n",id,nombre,apellido);
        fprintf(pArchivo,"%d,%s,%s\n",id+1,nombre,apellido);
        fprintf(pArchivo,"%d,%s,%s\n",id+2,nombre,apellido);
        fclose(pArchivo);
    }
    else
    {
        printf("El archivo no existe\n");
    }
    */
    /*
    pArchivo=fopen("archivo.ext","r");
    if(pArchivo!=NULL)
    {
       while(!feof(pArchivo))
       {

            fscanf(pArchivo,"%[^,],%[^,],%[^\n]\n",bufferId,bufferNombre,bufferApellido);
            printf("ID[%s]-%s-%s-\n",bufferId,bufferNombre,bufferApellido);
       }
       fclose(pArchivo);
    }
    else
    {
        printf("El archivo no existe\n");
    }
    */


    return 0;
}
