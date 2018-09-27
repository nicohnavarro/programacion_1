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
    char auxCuit[14];



    __fpurge(stdin);
    utn_getCuit(auxCuit,14,2,"Ingrese CUIT: [XX-XXXXXXXX-X]:","Error");
    utn_getEntero(&auxDias,2,"Ingrese Dias de publicacion","Error",1,30);
    utn_getString(auxVideo,30,2,"Ingrese el video:","Error");


    strncpy(contra[indexContra].CuitCliente,auxCuit,14);
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
                printf("-ID[%d]-DIAS[%d]-IDPANTALLA[%d]-VIDEO[%s]-CLIENTE:[%s]\n",contra[i].id,contra[i].dias,contra[i].IdPantalla,contra[i].video,contra[i].CuitCliente);
                retorno=0;
            }
        }
    }

    return retorno;
}

int modificarContratacion(Contratacion* contra,int lengthContratacion,char* cuit,Pantalla* pp,int lengthPantalla)
{
    int i;
    int retorno=-1;
    int idPantalla;
    int pos;
    for(i=0;i<lengthContratacion;i++)
    {
        if(strcmp(contra[i].CuitCliente,cuit)==0)
        {
            idPantalla=contra[i].IdPantalla;
            pos=buscarPorId(pp,lengthPantalla,idPantalla);
            imprimirPantallas(pp,pos);
        }
    }
    return retorno;
}

int modificarDiasContratacion(Contratacion*contra,int lengthContratatacion,int pos)
{
    int retorno=-1;
    int auxDias;
    if(utn_getEntero(&auxDias,2,"Ingrese Nueva cantidad de dias: ","Error",0,30)==0)
    {
        contra[pos].dias=auxDias;
        retorno=0;
    }
    return retorno;
}

int buscarPosicionPorCuit(Contratacion*contra,int lengthContratacion,char*cuit,int idPan)
{
    int i;
    int retorno=-1;
    for(i=0;i<lengthContratacion;i++)
    {
        if(strcmp(contra[i].CuitCliente,cuit)==0 && idPan==contra[i].IdPantalla)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}


int setContratacion(Contratacion* contra,int pos,char*cuit,char*video,int dias,int idPan)
{
    int retorno=-1;
    if(pos<QTY_CONTRATACION)
    {
        contra[pos].dias=dias;
        contra[pos].IdPantalla=idPan;
        contra[pos].id=generarIDcontra();
        strncpy(contra[pos].CuitCliente,cuit,14);
        strncpy(contra[pos].video,video,30);
        contra[pos].isEmpty=0;
        retorno=0;
    }
    return retorno;
}

int cancelarContratacion(Contratacion* contra,int lengthContratacion,int idPantalla)
{
    int retorno=-1;
    int i;
    for(i=0;i<lengthContratacion;i++)
    {
        if(contra[i].IdPantalla==idPantalla && contra[i].isEmpty==0)
        {
            contra[i].isEmpty=1;
            printf("Dado de Baja la Publicacion ID[%d]",contra[i].id);
            retorno=0;
            break;
        }
    }
    return retorno;
}
