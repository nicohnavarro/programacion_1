#include "cliente.h"
#include "ventas.h"
#include "utn.h"
#include <stdio.h>
#include <stdlib.h>
#include "informes.h"

void informes_menu(Cliente* cliente,Ventas* ventas,int lengthCliente,int lengthVentas)
{
    int opcion;
    do
    {
        printf("Menu de Informes \n1)Cliente con menos ventas a Cobrar\n2)Cliente con menos ventas Cobradas\n"
        "3)Cliente con menos ventas\n4)Zona con mas Afiches Vendidos\n5)Cliente que compro menos Afiches\n"
        "6)Cliente con mas afiches a cobrar\n7)Clientes que compraron mas de 500 afiches\n8)Afiches Vendidos "
        "por cada una de las 3 zonas\n9)Afiches vendidos promedio por cliente\n10)Listar ventas Ordenadas por Zona\n11)Salir\n");
        utn_getEntero(&opcion,2,"Ingrese opcion : ","Error de Opcion",0,11);
        switch(opcion)
        {
            case 1:
                system("clear");
                printf("\n1)Cliente con menos ventas a Cobrar\n");
                informes_ClienteMenosVentasAcobrar(cliente,ventas,lengthCliente,lengthVentas);
                break;
            case 2:
                system("clear");
                printf("\n2)Cliente con menos ventas Cobradas\n");
                informes_ClienteMenosVentasCobradas(cliente,ventas,lengthCliente,lengthVentas);
                break;
            case 3:
                system("clear");
                printf("\n3)Cliente con menos ventas\n");
                informes_menosVentas(cliente,ventas,lengthCliente,lengthVentas);
                break;
            case 4:
                system("clear");
                printf("\n4)Zona con Mas Afiches\n");
                informes_zonaConMasAfiches(ventas,lengthVentas,3);
                break;
            case 5:
                system("clear");
                printf("\n5)Cliente que Compro menos Afiches\n");
                informes_ClienteMenosAfiches(cliente,ventas,lengthCliente,lengthVentas);
                break;
        }
    }while(opcion!=11);
    system("clear");
}

int informes_ClienteMenosVentasAcobrar(Cliente* cliente,Ventas* ventas,int lengthCliente,int lengthVentas)
{
    int ret=-1;
    int i;
    int cantidadVentasACobrar;
    int cantidadVentas;
    int minimoVentasACobrar=999;
    int posicionDelMinimo=0;
    if(cliente!=NULL && lengthCliente>0)
    {
        for(i=0;i<lengthCliente;i++)
        {
            cantidadVentasACobrar=0;
            if(cliente[i].isEmpty==0)
            {
                cantidadVentasACobrar=informes_contarVentasDeCliente(ventas,lengthVentas,cliente[i].id,0);
                cantidadVentas=informes_contarVentasTotal(ventas,lengthCliente,cliente[i].id);
                if(cantidadVentas!=0 && cantidadVentasACobrar<=minimoVentasACobrar)
                {
                    minimoVentasACobrar=cantidadVentasACobrar;
                    posicionDelMinimo=i;
                    ret=0;
                }
            }

        }
        printf("\nEl cliente con menos Ventas a cobrar es : [%s %s]\n\n",cliente[posicionDelMinimo].name,cliente[posicionDelMinimo].lastName);
    }
    return ret;
}

int informes_ClienteMenosVentasCobradas(Cliente* cliente,Ventas* ventas,int lengthCliente,int lengthVentas)
{
    int ret=-1;
    int i;
    int cantidadVentas;
    int cantidadVentasCobradas;
    int minimoVentasCobradas=999;
    int posicionDelMinimo=0;
    if(cliente!=NULL && lengthCliente>0)
    {
        for(i=0;i<lengthCliente;i++)
        {
            cantidadVentasCobradas=0;
            if(cliente[i].isEmpty==0)
            {
                cantidadVentasCobradas=informes_contarVentasDeCliente(ventas,lengthVentas,cliente[i].id,1);
                cantidadVentas=informes_contarVentasTotal(ventas,lengthCliente,cliente[i].id);
                if(cantidadVentas !=0 && cantidadVentasCobradas<=minimoVentasCobradas )
                {
                    minimoVentasCobradas=cantidadVentasCobradas;
                    posicionDelMinimo=i;
                    ret=0;
                }
            }

        }
        printf("\nEl cliente con menos Ventas Cobradas es : [%s %s]\n\n",cliente[posicionDelMinimo].name,cliente[posicionDelMinimo].lastName);
    }
    return ret;
}

int informes_contarVentasDeCliente(Ventas* ventas,int lengthVentas,int idCliente,int estado)
{
    int i;
    int contadorDeVentas=0;
    if(ventas!=NULL && lengthVentas>0)
    {
        for(i=0;i<lengthVentas;i++)
        {
            if(idCliente==ventas[i].idCliente && ventas[i].isEmpty==0 && ventas[i].estado==estado && ventas[i].cantidadAfiches>0)
            {
                contadorDeVentas++;
            }
        }
    }
    return contadorDeVentas;
}

int informes_contarVentasTotal(Ventas* ventas,int lengthVentas,int idCliente)
{
    int i;
    int contadorDeVentas=0;
    if(ventas!=NULL && lengthVentas>0)
    {
        for(i=0;i<lengthVentas;i++)
        {
            if(idCliente==ventas[i].idCliente && ventas[i].isEmpty==0 )
            {
                contadorDeVentas++;
            }
        }
    }
    return contadorDeVentas;
}

int informes_menosVentas(Cliente* cliente,Ventas* ventas,int lengthCliente,int lengthVentas)
{
    int ret=-1;
    int i;
    int minimoVentas=999;
    int posicionDelMinimo=0;
    int cantidadVentas;
    if(cliente!=NULL && lengthCliente>0)
    {
        for(i=0;i<lengthCliente;i++)
        {
            cantidadVentas=0;
            if(cliente[i].isEmpty==0)
            {
                cantidadVentas=informes_contarVentasTotal(ventas,lengthVentas,cliente[i].id);
                if(cantidadVentas<=minimoVentas)
                {
                    minimoVentas=cantidadVentas;
                    posicionDelMinimo=i;
                    ret=0;
                }
            }

        }
        printf("\nEl cliente con menos Ventas es : [%s %s]\n\n",cliente[posicionDelMinimo].name,cliente[posicionDelMinimo].lastName);
    }
    return ret;
}

int informes_cantidadDeAfichesPorZona(Ventas* ventas,int lengthVentas,int zona)
{
    int ret=-1;
    int i;
    int contadorAfichesPorZona=0;
    if(ventas!=NULL && lengthVentas>0)
    {
      for(i=0;i<lengthVentas;i++)
      {
        if(ventas[i].zona==zona && ventas[i].isEmpty==0)
        {
            contadorAfichesPorZona+=ventas[i].cantidadAfiches;
            ret=0;
        }
      }
      printf("\nLa Zona [%d] tiene [%d]Afiches\n\n",zona,contadorAfichesPorZona);
    }
    return ret;
}

int informes_zonaConMasAfiches(Ventas* ventas,int lengthVentas,int cantidadZonas)
{
    int ret=-1;
    int i;
    int afichesporZona;
    int zonaMasAfiches=0;
    int zona=0;
    if(ventas!=NULL && lengthVentas>0)
    {
        for(i=0;i<cantidadZonas;i++)
        {
            afichesporZona=informes_cantidadDeAfichesPorZona(ventas,lengthVentas,i);
            if(afichesporZona>=zonaMasAfiches)
            {
                zonaMasAfiches=afichesporZona;
                zona=i;
                ret=0;
            }
        }
        printf("\nLa Zona con Mas Afiches Vendidos es :[%d]\n",zona);
        printf("\n0-CABA\n1-ZONA SUR\n2-ZONA OESTE\n\n");

    }
    return ret;
}

int informes_ClienteMenosAfiches(Cliente* cliente,Ventas* ventas,int lengthClientes,int lengthVentas)
{
    int ret=-1;
    int i;
    int menosAfiches;
    int clienteMenosAfiches=999;
    int afichesClientes=0;
    if(cliente!=NULL && lengthClientes>0)
    {
        for(i=0;i<lengthClientes;i++)
        {
            if(cliente[i].isEmpty==0)
            {
                afichesClientes=informes_CantidadAfichesporCliente(ventas,lengthVentas,cliente[i].id);
                if(afichesClientes!=0 && afichesClientes<=clienteMenosAfiches)
                {
                    clienteMenosAfiches=afichesClientes;
                    menosAfiches=i;
                    ret=0;
                }
            }
        }
    }
    printf("\nEl Cliente que tiene menos afiches es: [%s %s] con [%d]Afiches \n\n",cliente[menosAfiches].name,cliente[menosAfiches].lastName,clienteMenosAfiches);
    return ret;
}

int informes_CantidadAfichesporCliente(Ventas* ventas,int lengthVentas,int idCliente)
{
    int ret=-1;
    int i;
    int contadorAfichesPorCliente=0;
    if(ventas!=NULL && lengthVentas>0)
    {
        for(i=0;i<lengthVentas;i++)
        {
            if(ventas[i].isEmpty==0 && ventas[i].idCliente==idCliente)
            {
                contadorAfichesPorCliente+=ventas[i].cantidadAfiches;
            }
        }
        ret=contadorAfichesPorCliente;
    }
    return ret;
}
