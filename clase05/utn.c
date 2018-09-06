
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "utn.h"
static int getInt(int* pResultado);
static int getFloat(float* pResultado);

int utn_getEntero(int* pNumero,int intentos,char* pMsj,char* pMsjEr,int minimo,int maximo)
{
    int retorno=-1;
    int auxEntero;

    for (;intentos>0;intentos--)
    {
        printf(pMsj);
        if(getInt(&auxEntero)==0)
        {
            if (auxEntero>=minimo && auxEntero<maximo)
            {
                *pNumero=auxEntero;
                retorno=0;
                break;
            }
            else
            {
                printf(pMsjEr);
            }
        }
        else
        {
            printf(pMsjEr);
            __fpurge(stdin);
        }


    }
    return retorno;
}

int utn_getDecimal(float* pNumero,int intentos,char* pMsj,char* pMsjEr,int minimo,int maximo)
{
    int retorno=-1;
    float auxEntero;

    for (;intentos>0;intentos--)
    {
        printf(pMsj);
        if(getFloat(&auxEntero)==0)
        {
            if (auxEntero>=minimo && auxEntero<maximo)
            {
                *pNumero=auxEntero;
                retorno=0;
                break;
            }
            else
            {
                printf(pMsjEr);
            }
        }
        else
        {
            printf(pMsjEr);
            __fpurge(stdin);
        }


    }
    return retorno;
}

int utn_getChar(char* pCaracter,int intentos,char* pMsj)
{
    char auxChar;
    int retorno=-1;
    printf(pMsj);
    __fpurge(stdin);
    if(scanf("%c",&auxChar)==1)
    {
        *pCaracter=auxChar;
        retorno=0;
    }
    return retorno;
}

static int getInt(int* pResultado)
{
    int auxResultado;
    int retorno=-1;

    if(scanf("%d",&auxResultado)==1)
    {
        *pResultado=auxResultado;
        retorno=0;
    }

    return retorno;
}

static int getFloat(float* pResultado)
{
    float auxResultado;
    int retorno=-1;

    if(scanf("%f",&auxResultado)==1)
    {
        *pResultado=auxResultado;
        retorno=0;
    }


    return retorno;
}
