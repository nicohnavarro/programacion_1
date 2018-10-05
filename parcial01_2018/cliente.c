#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "cliente.h"
#include "ventas.h"
#include <string.h>
#include <stdio_ext.h>
#define QTY_CLIENTES 10
static int generarID(void);
int cliente_init(Cliente* cliente,int lengthCliente,int value)
{
    int ret=-1;
    int i;
    if(cliente!=NULL && lengthCliente>0)
    {
        for(i=0;i<lengthCliente;i++)
        {
            cliente[i].isEmpty=value;
            ret=0;
        }
    }
    return ret;
}

int cliente_getFreePlace(Cliente* cliente,int lengthCliente)
{
    int ret=-1;
    int i;
    if(cliente!=NULL && lengthCliente>0)
    {
        for(i=0;i<lengthCliente;i++)
        {
            if(cliente[i].isEmpty==1)
            {
                ret=i;
                break;
            }
        }
    }
    return ret;
}

static int generarID(void)
{
    static int clienteID=-1;
    clienteID++;
    return clienteID;
}

int cliente_alta(Cliente* cliente,int lengthCliente,int index)
{
    int ret=-1;
    char nameAux[30];
    char lastNameAux[30];
    char cuitAux[14];
    __fpurge(stdin);
    if(cliente!=NULL && lengthCliente>0)
    {
       if(!utn_getLetras(nameAux,30,2,"Ingrese Nombre del Cliente: ","Error de Nombre."))
       {
            if(!utn_getLetras(lastNameAux,30,2,"Ingrese Apellido del Cliente: ","Error de Apellido."))
            {
                if(!utn_getCuit(cuitAux,14,2,"Ingrese su CUIT [XX-XXXXXXXX-X] :","Error de CUIT"))
                {
                    strncpy(cliente[index].name,nameAux,20);
                    strncpy(cliente[index].lastName,lastNameAux,20);
                    strncpy(cliente[index].cuit,cuitAux,14);
                    cliente[index].isEmpty=0;
                    cliente[index].id=generarID();
                    printf("Se dio de ALTA al Cliente ID[%d]",cliente[index].id);
                    ret=0;
                }
                else
                {
                    ret=-3;
                }
            }
       }
    }
    return ret;
}

int cliente_getClienteById(Cliente* cliente,int lengthCliente,int id)
{
    int ret=-1;
    int i;
    if(cliente!=NULL && lengthCliente>0)
    {
        for(i=0;i<lengthCliente;i++)
        {
            if(cliente[i].id==id)
            {
                ret=i;
                break;
            }
        }

    }
    return ret;
}

int cliente_modificar(Cliente* cliente,int lengthCliente,int index)
{
    int ret=-1;
    char nameAux[30];
    char lastNameAux[30];
    char cuitAux[14];
    if(cliente!=NULL && lengthCliente>0 && cliente[index].isEmpty==0)
    {

        if(!utn_getLetras(nameAux,20,2,"Ingrese Nuevo Nombre: ","Error"))
        {
            if(!utn_getLetras(lastNameAux,20,2,"Ingrese Nuevo Apellido: ","Error"))
            {
                if(!utn_getCuit(cuitAux,14,2,"Ingrese Nuevo Cuit: ","Error"))
                {
                    strncpy(cliente[index].name,nameAux,20);
                    strncpy(cliente[index].lastName,lastNameAux,20);
                    strncpy(cliente[index].cuit,cuitAux,14);
                    printf("Se dio MODIFICO al Cliente ID[%d]",cliente[index].id);
                    ret=0;
                }
            }
        }
    }
    else
    {
        printf("NO Hay Clientes");
    }
    return ret;
}

int cliente_baja(Cliente* cliente,int lengthCliente,int index)
{
    int ret=-1;
    int confirm;
    if(cliente[index].isEmpty==0)
    {
        utn_getEntero(&confirm,0,"Si da de BAJA al Cliente se eliminaran todas sus ventas..\nEsta de acuerdo? (1)SI (2)NO","1 o 2...",1,2);
        if(confirm==1)
        {
            cliente[index].isEmpty=1;
            ret=0;
        }
    }
    else
    {
        printf("NO Hay Clientes");
    }
    return ret;
}

int cliente_set(Cliente* cliente,int lengthCliente,int index,char*nombre,char*apellido,char*cuit)
{
    int ret=-1;
    if(cliente!=NULL && lengthCliente>0 && index>=0 && index<lengthCliente && nombre!=NULL && apellido!=NULL && cuit!=NULL)
    {
        strncpy(cliente[index].name,nombre,30);
        strncpy(cliente[index].lastName,apellido,30);
        strncpy(cliente[index].cuit,cuit,14);
        cliente[index].isEmpty=0;
        cliente[index].id=generarID();
        ret=0;
    }
}

int cliente_ImprimirCliente(Cliente* cliente,int lengthCliente,int index)
{
    int ret=-1;
    if(cliente[index].isEmpty==0)
    {
        printf("Nombre : %s- Apellido: %s - CUIT [%s]",cliente[index].name,cliente[index].lastName,cliente[index].cuit);
        ret=0;
    }
    else
    {
        printf("No Existe o esta dado de baja\n");
    }
    return ret;

}

int cliente_cantidadVentas(Cliente* cliente,Ventas* venta,int lengthCliente,int lengthVentas)
{
    int ret=-1;
    int cantidadVentas=0;
    int i;
    for(i=0;i<lengthCliente;i++)
    {
        if(cliente[i].isEmpty==0)
        {

        }
    }

}
