#include"utn.h"
#include"pantalla.h"
#include<string.h>
#include <stdio.h>
#include <stdlib.h>
#include<stdio_ext.h>
#define QTY_PANTALLAS 100


static int generarID(void);


int arrayInit(Pantalla* pp,int length,int valor)
{
    int i;
    int retorno=-1;
    if(pp!=NULL && length>0)
    {
        for (i=0;i<length;i++)
        {
            pp[i].isEmpty=valor;
            retorno=0;
        }
        return retorno;
    }
    return retorno;
}

int getIndiceVacio(Pantalla* pp,int length)
{
    int i;
    int retorno=-1;
    for (i=0;i<length;i++)
    {
        if(pp[i].isEmpty==1)
        {
            retorno=i;
            break;

        }
    }
    return retorno;
}

int altaPantalla(Pantalla* pp,int index,int length)
{
    int auxTipo;
    char auxNombre[32];
    char auxDireccion[35];
    int retorno=-1;
    if (index<length)
    {
        __fpurge(stdin);
        utn_getLetras(auxNombre,32,1,"Ingrese nombre: ","error");
        utn_getLetras(auxDireccion,35,1,"Ingrese direccion: ","Error");
        utn_getEntero(&auxTipo,2,"Ingrese el tipo de pantalla: [LCD]=1\t [led]=0","Error",0,1);

        strncpy(pp[index].nombre,auxNombre,32);
        strncpy(pp[index].direccion,auxDireccion,35);
        pp[index].tipo=auxTipo;
        pp[index].isEmpty=0;
        pp[index].id=generarID();
        printf("Dado de alta el ID: [%d]",pp[index].id);
        retorno=0;
     }
    return retorno;

}


static int generarID(void)
{
    static int id=-1;
    id++;
    return id;
}
