#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "utn.h"
#include "string.h"
static int getInt(int* pResultado);
static int getFloat(float* pBuffer);

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

int utn_getFloat(float* pNumero,int reintentos,char* pMsj,char pMsjEr[],float minimo,float maximo)
{
    int retorno=-1;
    float buffer;
    if(pNumero!=NULL && pMsj!=NULL && pMsjEr!=NULL && minimo<=maximo && reintentos>=0)
    {
        do
        {
            reintentos--;
            printf("%s",pMsj);
            if(getFloat(&buffer)==0 && buffer>=minimo && buffer<=maximo)
            {
              *pNumero=buffer;
              retorno=0;
              break;
            }
            else
            {
                printf("%s",pMsjEr);
            }

        //Continue----------------
        }while(reintentos>=0);
        //Break-------------------
    }

    return retorno;
   /* int retorno=-1;
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
    return retorno;*/
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
/*{
    int auxResultado;
    int retorno=-1;
    char buffer[500];
    if(scanf("%d",&auxResultado)==1)
    {
        *pResultado=auxResultado;
        retorno=0;
    }
    return retorno;
}*/
{
    char cadena[64];
    int aux;
    int retorno=-1;
    scanf("%s",cadena);

    if(utn_es_numero(cadena)==1)
    {
        aux=atoi(cadena);
        *pResultado=aux;
        retorno=0;

    }
    return retorno;
}
int isFloat(char* pBuffer)
{
    return 1;
}
static int getFloat(float* pBuffer)
{
    char bufferString[4080];
    int retorno=-1;
    char* retornoFgets;
    __fpurge(stdin);
    retornoFgets=fgets(bufferString, sizeof(bufferString),stdin);
    printf("SALIDA ---_> %s\n",bufferString);

    if(bufferString[strlen(bufferString)-1]=='\n')
    {
        bufferString[strlen(bufferString)-1]='\0';
        printf("Todo bien-----\n");
        *pBuffer=atof(bufferString);       /* * operador de indireccion*/
        retorno=0;
    }
    else
    {
        printf("Todo mal-----\n");
    }



    return retorno;
}

int utn_es_numero(char* pArray)
{
    int i=0;
    int retorno=1;
    /*while (pArray[i]='\0')
    {
        if(pArray[i]<'0'|| pArray[i]>'9')
        {
            retorno=-1
            break;
        }
        i++;
    }*/
    while(pArray[i]!=0)//expresiones regulares
    {
        if(pArray[i]<48 || pArray[i]>57)
        {
            retorno=-1;
            break;
        }
        i++;

    }
    return retorno;
}

int utn_ordenar_array(int* pArray,int limite,int orden)
{
    int i;
    int auxiliar;
    int flag=1;
    int retorno=-1;

    while(flag==1)
    {
        flag=0;
        retorno=-1;
        for(i=0;i<(limite-1);i++)
        {
            if((pArray[i]>pArray[i+1] && orden==0) || (pArray[i]<pArray[i+1] && orden==1))
            {
                auxiliar=pArray[i];
                pArray[i]=pArray[i+1];
                pArray[i+1]=auxiliar;
                flag=1;
            }
        }
        retorno=0;
    }
    return retorno;
}

int utn_mostrar_array(int* pArray,int limite) //pArray[]
{
    int i;
    for(i=0;i<limite;i++)
    {
        printf("el empleado %d \t tiene la edad: %d -- %p \n",i,pArray[i],pArray+i);//*pArray+i -- &pArray[i]
    }
    return 0;
}

int utn_init_array(int* pArray,int limite,int valor)
{
    int retorno=-1;
    int i;
    if(pArray!=NULL && limite>0)
    {
        for(i=0;i<limite;i++)
        {
            pArray[i]=valor;
            //*(pArray+1)=valor;
        }
        retorno=0;
    }



    return retorno;
}

int utn_calcular_maximo(int* pArray,int limite,int*pMaximo)
{
    int i;
    int auxMaximo=0;
    int flag=0;
    for(i=0;i<limite;i++)
    {
        if(flag==0)
        {
            auxMaximo=pArray[i];
            flag=1;
        }
        else if (pArray[i]>auxMaximo)
        {
            auxMaximo=pArray[i];
        }

    }
    *pMaximo=auxMaximo;
    return 0;
}

void utn_quick_sort(int* pArray, int limite_izq, int limite_der)
{
    int izquierda;
    int derecha;
    int auxiliar;
    int pivote;

    izquierda=limite_izq;
    derecha=limite_der;
    pivote=pArray[(izquierda+derecha)/2];
    do {
        while(pArray[izquierda]<pivote && izquierda<limite_der)izquierda++;
        while(pivote<pArray[derecha] && derecha>limite_izq)derecha--;
        if(izquierda<=derecha)
        {
            auxiliar=pArray[izquierda];
            pArray[izquierda]=pArray[derecha];
            pArray[derecha]=auxiliar;
            izquierda++;
            derecha--;
        }
    }while(izquierda<=derecha);
    if(limite_izq<derecha)
    {
        utn_quick_sort(pArray,limite_izq,derecha);
    }
    if(limite_der>izquierda)
    {
        utn_quick_sort(pArray,izquierda,limite_der);
    }

}
void utn_qs(int* pArray,int limite)
{
    utn_quick_sort(pArray,0,limite-1);
}

static int getString(char* pBuffer, int limite)
{
    char bufferString[4085];
    int retorno=-1;
    if(pBuffer!= NULL && limite >0)
    {
        __fpurge(stdin);
        fgets(bufferString, sizeof(bufferString),stdin);
        if(bufferString[strlen(bufferString)-1]=='\n')
        {
            bufferString[strlen(bufferString)-1]='\0';
        }
        if(strlen(bufferString)<=limite)
        {
            strncpy(pBuffer,bufferString,limite);
            retorno=0;
        }

    }
    return retorno;

}
