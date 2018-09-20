#include"UTN.h"
#include"producto.h"
#include<string.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 200
#include<stdio_ext.h>

int arrayInit(Producto* pp,int length,int valor)
{
    int i;
    int retorno=-1;
    for (i=0;i<length;i++)
    {
        pp[i].isEmpty=valor;
        //(pp+i)->isEmpty=valor;
        //(*(pp+i)).isEmpty=valor;
        retorno=0;
    }
    return retorno;
}

int altaProducto(Producto*pp,int indice,int length)
{
    char auxNombre[50];
    char auxDescrip[200];
    float auxPrecio;
    if (indice<length)
    {
        utn_getLetras(auxNombre,50,2,"Ingrese el nombre: ","Error\n");
        utn_getLetras(auxDescrip,50,2,"Ingrese la descripcion : ","Error\n");
        utn_getFloat(&auxPrecio,2,"Ingrese el precio: $ ","Error\n",0,100000);
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

int imprimirProducto(Producto* pp,int indice)
{
    if (pp[indice].isEmpty==0)
    {
        printf("El nombre del producto es: %s\nLa descripcion del producto es: %s\nEl Precio del producto es: %.2f\n",
        pp[indice].nombre,
        pp[indice].descripcion,
        pp[indice].precio);
    }
    else
    {
        printf("El producto no esta cargado \n");
    }
    return 0;
}

int getIndiceVacio(Producto* pp,int length)
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

int listarProductos(Producto* pp,int length)
{
    int i;
    for (i=0;i<length;i++)
    {
        if(pp[i].isEmpty==0)
            imprimirProducto(pp,i);
    }
    return 0;
}

void menuProducto(Producto* pp)
{

    char opcion;

    arrayInit(pp,MAX,1);

    do
    {
        printf("a)Cargar producto \nb)Imprimir lista de Productos \nPulse cualquier tecla para salir \nIngresar opcion: \n");
        __fpurge(stdin);
        scanf("%c",&opcion);
        switch(opcion)
        {
            case 'a':
                altaProducto(pp,getIndiceVacio(pp,MAX),MAX);
                break;
            case 'b':
                listarProductos(pp,MAX);
                break;
            default:
                printf("SALIENDO");

        }

    }while(opcion=='a' || opcion=='b');
}
