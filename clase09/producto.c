#include"UTN.h"
#include"producto.h"
#include<string.h>
#include <stdio.h>
#include <stdlib.h>

int arrayInit(Producto* pp,int lenght,int valor)
{
    int i;
    int retorno=-1;
    for (i=0;i<lenght;i++)
    {
        pp[i].isEmpty=valor;
        //(pp+i)->isEmpty=valor;
        //(*(pp+i)).isEmpty=valor;
        retorno=0;
    }
    return retorno;
}

int altaProducto(Producto*pp,int indice,int lenght)
{
    char auxNombre[50];
    char auxDescrip[200];
    char auxPrecio [500];
    if (indice<lenght)
    {
        getStringLetras("Ingresa el nombre del producto: \n",auxNombre);
        getStringLetras("Ingresa la descripcion del produto: \n",auxDescrip);
        getStringNumerosFlotantes("Ingrese el precio: $",auxPrecio);
        strcpy(pp[indice].nombre,auxNombre);
        strcpy(pp[indice].descripcion,auxDescrip);
        pp[indice].precio=atof(auxPrecio);
        pp[indice].isEmpty=0;
    }
    else
    {
        return -1;
    }
    return 0;
}
