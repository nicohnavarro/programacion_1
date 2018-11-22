#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"Empleado.h"
int parser_parseEmpleados(char* fileName, LinkedList* listaEmpleados)
{
    int retorno=0;
    char* tokenId;
    char* tokenNombre;
    char* tokenHoras;
    char* delim=",";
    char* delim2="\n";
    int valueF;
    int contadorEntradas=0;
    char line [1024];
    Empleado* pEmpleado=NULL;
    FILE* pFile;
    pFile=fopen(fileName,"r");
    if(pFile!=NULL)
    {
        fscanf(pFile,"%[^\n]\n",line);
        while(!feof(pFile))
        {
            valueF=fscanf(pFile,"%[^\n]\n",line);
            if(valueF!=1)
            {
                break;
            }

            tokenId=strtok(line,delim);
            tokenNombre=strtok(NULL,delim);
            tokenHoras=strtok(NULL,delim2);

            pEmpleado=Empleado_newConParametros(tokenId,tokenNombre,tokenHoras,"0");
            if(pEmpleado!=NULL)
            {
                contadorEntradas++;
                ll_add(listaEmpleados,pEmpleado);
                retorno=1;
            }
        }
        printf("Se cargaron %d empleados \n",contadorEntradas);
    }
    fclose(pFile);
    return retorno; // OK
}

