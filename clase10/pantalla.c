#include"utn.h"
#include"pantalla.h"
#include<string.h>
#include <stdio.h>
#include <stdlib.h>
#include<stdio_ext.h>
#define QTY_PANTALLAS 5


static int generarID(void);

int setPantalla(Pantalla* pp,int length,int tipo,char* nombre,char* direccion,float precio)
{
    int retorno=-1;
    if(length<QTY_PANTALLAS)
    {
        pp[length].isEmpty=0;
        pp[length].tipo=tipo;
        pp[length].precio=precio;
        strcpy(pp[length].direccion,direccion);
        strcpy(pp[length].nombre,nombre);
        pp[length].id=generarID();
        retorno=0;
    }
    return retorno;
}


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
    if(i==length)
    {
        printf("no hay mas lugar");
        retorno=-1;
    }
    return retorno;
}

int altaPantalla(Pantalla* pp,int index,int length)
{
    int auxTipo;
    char auxNombre[32];
    char auxDireccion[35];
    float auxPrecio;
    int retorno=-1;
    if (index<length)
    {
        //__fpurge(stdin);
        utn_getCuit(auxNombre,13,2,"CUIT?","EERoR");
        utn_getString(auxNombre,32,1,"Ingrese nombre: ","error");
        utn_getString(auxDireccion,35,1,"Ingrese direccion: ","Error");
        utn_getEntero(&auxTipo,2,"Ingrese el tipo de pantalla: [LCD]=1\t [led]=0","Error",0,1);
        utn_getFloat(&auxPrecio,2,"Ingrese precio $ ","error",0,10000);

        strncpy(pp[index].nombre,auxNombre,13);
        strncpy(pp[index].direccion,auxDireccion,35);
        pp[index].tipo=auxTipo;
        pp[index].precio=auxPrecio;
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

int buscarPorId(Pantalla* pp,int length,int idPantalla)
{
    int i;
    int ret=0;
    for (i=0;i<length;i++)
    {
        if(pp[i].isEmpty==0 && pp[i].id==idPantalla)
        {
            ret=i;
            break;
        }
    }
    return ret;
}

int modificarPantalla(Pantalla* pp,int length,int index)
{
    int auxTipo;
    char auxNombre[32];
    char auxDireccion[35];
    float auxPrecio;
    int retorno=1;
    if (index<length)
    {
        __fpurge(stdin);
        utn_getString(auxNombre,32,1,"Ingrese nuevo nombre: ","error");
        utn_getString(auxDireccion,35,1,"Ingrese nueva direccion: ","Error");
        utn_getEntero(&auxTipo,2,"Ingrese el nuevo tipo de pantalla: [LCD]=1\t [led]=0","Error",-1,2);
        utn_getFloat(&auxPrecio,2,"Ingrese nuevo precio $ ","error",0,10000);

        pp[index].precio=auxPrecio;
        strncpy(pp[index].nombre,auxNombre,32);
        strncpy(pp[index].direccion,auxDireccion,35);
        pp[index].tipo=auxTipo;

        printf("MODIFICADO el ID: [%d]",pp[index].id);
        retorno=0;
     }
    return retorno;
}

int darBajaPantalla(Pantalla*pp,int length,int index)
{
    pp[index].isEmpty=1;
    printf("Dado de baja el la Pantalla de ID: [%d]",pp[index].id);
    return 0;
}

int listarPantallas(Pantalla* pp,int length)
{
    int i;
    int retorno=-1;
    if(pp!=NULL && length>0)
    {
        for(i=0;i<length;i++)
        {
            if(pp[i].isEmpty==0)
            {
                printf("Id[%d]-Tipo[%d]-Nombre[%s]-Direccion[%s]-Precio [%.2f]\n",pp[i].id,pp[i].tipo,pp[i].nombre,pp[i].direccion,pp[i].precio);
                retorno=0;
            }
        }
    }


    return retorno;
}

int imprimirPantallas(Pantalla*pp,int index)
{
    printf("Id[%d]-Tipo[%d]-Nombre[%s]-Direccion[%s]-Precio [%.2f]\n",pp[index].id,pp[index].tipo,pp[index].nombre,pp[index].direccion,pp[index].precio);
    return 0;
}
