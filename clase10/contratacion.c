#include"utn.h"
#include"pantalla.h"
#include"contratacion.h"
#include<string.h>
#include <stdio.h>
#include <stdlib.h>
#include<stdio_ext.h>
#define QTY_PANTALLAS 5
#define QTY_CONTRATACION 10
static int generarIDcontra(void);
int arrayInitContra(Contratacion* contra,int length,int valor)
{
    int i;
    int retorno=-1;
    if(contra!=NULL && length>0)
    {
        for (i=0;i<length;i++)
        {
            contra[i].isEmpty=valor;
            retorno=0;
        }
        return retorno;
    }
    return retorno;
}

int getIndiceVacioContra(Contratacion* contra,int length)
{
    int i;
    int retorno=-1;
    for (i=0;i<length;i++)
    {
        if(contra[i].isEmpty==1)
        {
            retorno=i;
            break;

        }
    }
    return retorno;
}
static int generarIDcontra(void)
{
    static int idContra=-1;
    idContra++;
    return idContra;
}

int altaContratacion(Contratacion* contra,int lengthContra,int indexContra,int idPantalla)
{
    int retorno=-1;
    char auxVideo[30];
    int auxDias;
    int auxCuit;


    __fpurge(stdin);
    utn_getEntero(&auxCuit,2,"Ingrese el Cuit","Error",0,100);
    utn_getEntero(&auxDias,2,"Ingrese Dias de publicacion","Error",1,30);
    utn_getLetras(auxVideo,30,2,"Ingrese el video:","Error");


    contra[indexContra].CuitCliente=auxCuit;
    strcpy(contra[indexContra].video,auxVideo);
    contra[indexContra].dias=auxDias;
    contra[indexContra].IdPantalla=idPantalla;
    contra[indexContra].id=generarIDcontra();
    contra[indexContra].isEmpty=0;

    retorno=0;

    return retorno;
}

int printContratacion(Contratacion*contra,int length)
{
    int retorno=-1;
    int i;
    if(contra!=NULL && length>0)
    {
        for(i=0;i<length;i++)
        {
            if(contra[i].isEmpty==0)
            {
                printf("Id[%d]-dias[%d]-video[%s]-IDPANTALLA[%d]-\n",contra[i].id,contra[i].dias,contra[i].video,contra[i].IdPantalla);
                retorno=0;
            }
        }
    }

    return retorno;
}

int modificarContratacion(Contratacion* contra,int lengthContratacion,int cuit,Pantalla* pp,int lengthPantalla)
{
    int i;
    int retorno=-1;
    int idPantalla;
    int pos;
    for(i=0;i<lengthContratacion;i++)
    {
        if(contra[i].CuitCliente==cuit)
        {
            idPantalla=contra[i].IdPantalla;
            pos=buscarPorId(pp,lengthPantalla,idPantalla);
            imprimirPantallas(pp,pos);

        }

    }



    return retorno;
}
