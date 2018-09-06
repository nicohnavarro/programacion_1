#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"


static int getInt(int* pResultado);


int utn_getEntero(int* pEdad,int reintentos,char* msg,
                          char*msgErr,int min, int max)
{
    int retorno = -1;
    int auxiliarEdad;

    for(;reintentos > 0;reintentos--)
    {
        printf(msg);
        if(getInt(&auxiliarEdad) == 0)
        {
            if(auxiliarEdad >= min && auxiliarEdad < max)
            {
                *pEdad = auxiliarEdad;
                retorno = 0;
                break;
            }
            else
            {
                printf(msgErr);
            }
        }
        else
        {
            printf(msgErr);
            __fpurge(stdin);
        }
    }
    return retorno;
}






static int getInt(int* pResultado)
{
    if(scanf("%d",pResultado) == 1)
        return 0;
    return -1;
}


