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
    float auxPrecio;
    if (indice<lenght)
    {
        utn_getLetras(auxNombre,50,2,"Ingrese el nombre: \n","Error\n");
        utn_getLetras(auxDescrip,50,2,"Ingrese la descripcion : \n","Error\n");
        utn_getFloat(&auxPrecio,2,"Ingrese el precio: $ \n","Error\n",0,100000);
        strcpy(pp[indice].nombre,auxNombre);
        strcpy(pp[indice].descripcion,auxDescrip);
        pp[indice].precio=auxPrecio;
        pp[indice].isEmpty=0;
    }
    else
    {
        return -1;
    }
    return 0;
}
