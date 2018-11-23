#include <stdio_ext.h>
#include <stdlib.h>
#include "Venta.h"
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"


int parser_parseVentas(char* fileName, LinkedList* lista)
{

    int retorno=0;
    char* tokenIdventa;
    char* tokenFecha;
    char* tokenCodigo;
    char* tokenCantidad;
    char* tokenPrecioUnitario;
    char* tokenCuitCliente;
    char* delim=",";
    char* delim2="\n";
    int valueF;
    int contadorEntradas=0;
    char line[1024];
    Venta* auxiliarPunteroVenta;
    FILE* pFile;
    pFile=fopen(fileName,"r");
    if(pFile != NULL)
    {
        fscanf(pFile,"%[^\n]\n",line);
        while(!feof(pFile))
        {
            valueF=fscanf(pFile,"%[^\n]\n",line);
            if(valueF!=1)
            {
                retorno=-1;
                break;
            }
            tokenIdventa=strtok(line,delim);
            tokenFecha=strtok(NULL,delim);
            tokenCodigo=strtok(NULL,delim);
            tokenCantidad=strtok(NULL,delim);
            tokenPrecioUnitario=strtok(NULL,delim);
            tokenCuitCliente=strtok(NULL,delim2);
            auxiliarPunteroVenta=Venta_newConParametros(tokenIdventa,tokenFecha,tokenCodigo,tokenCantidad,tokenPrecioUnitario,tokenCuitCliente);

            if(auxiliarPunteroVenta!=NULL)
            {
                contadorEntradas++;
                ll_add(lista,auxiliarPunteroVenta);
                retorno=1;
            }

        }
        printf("Se cargaron %d Ventas. \n",contadorEntradas);
    }
    fclose(pFile);
    return retorno;
}

