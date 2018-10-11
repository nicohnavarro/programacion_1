#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "cliente.h"
#include "ventas.h"
#include <string.h>
#include <stdio_ext.h>
#define QTY_CLIENTES 100
#define QTY_VENTAS 1000
#define ESTADO_ACOBRAR 0
#define ESTADO_COBRADO 1
#define CABA 0
#define ZONASUR 1
#define ZONAOESTE 2
static int generarID(void);

/** \brief Inicializa el Array de Tipo Cliente
 *
 * \param cliente ->Array de Clientes
 * \param lengthCliente ->Limite del Array
 * \param value ->Valor a cargar en este caso (1)
 * \param
 * \return -1 Error // 0 Todo OK
 *
 */
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

/** \brief Encuentra el primer Luegar Libre del Array
 *
 * \param cliente->Array tipo Cliente
 * \param lengthCliente->Limite del Array
 * \param
 * \param
 * \return -1 Error // 0 Todo ok
 *
 */
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

/** \brief Dar de Alta a un Cliente
 *
 * \param cliente->Array tipo Cliente
 * \param lengthCliente->limite del Array
 * \param index->Posicion a cargar el Cliente
 * \param
 * \return -3 Error de Cuit // -1 Error en el Array // 0 Todo ok
 *
 */
int cliente_alta(Cliente* cliente,int lengthCliente,int index)
{
    int ret=-1;
    char nameAux[30];
    char lastNameAux[30];
    char cuitAux[15];
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
                    printf("Se dio de ALTA al Cliente ID[%d]\n\n",cliente[index].id);
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

/** \brief Busca un Cliente por el campo ID
 *
 * \param cliente->Array de Cliente
 * \param lengthCliente->Limite de Array
 * \param id->Id del Cliente
 * \return -1 Error // i Posicion del cliente en el Array
 *
 */
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

/** \brief Modifica un Cliente
 *
 * \param cliente->Array tipo Cliente
 * \param lengthCliente->Limite del Array
 * \param index->Posicion del Cliente a modificar
 * \param
 * \return -3 Error no hay Clientes activos //-1 Error // 0 Todo ok
 *
 */
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
                    strncpy((cliente+index)->name,nameAux,20);
                    strncpy((cliente+index)->lastName,lastNameAux,20);
                    strncpy((cliente+index)->cuit,cuitAux,14);
                    printf("Se MODIFICO al Cliente ID[%d]\n\n",(cliente+index)->id);
                    ret=0;
                }
            }
        }
    }
    else
    {
        printf("NO Hay Clientes");
        ret=-3;
    }
    return ret;
}

/** \brief Dar de Baja a un Cliente
 *
 * \param cliente->Array de Cliente
 * \param lengthCliente->Limite del Array
 * \param index->Posicion en el Array
 * \param
 * \return -1 Error // 0 Todo ok
 *
 */
int cliente_baja(Cliente* cliente,int lengthCliente,int index)
{
    int ret=-1;
    int confirm;
    if((cliente+index)->isEmpty==0)
    {
        utn_getEntero(&confirm,0,"Si da de BAJA al Cliente se eliminaran todas sus ventas..\nEsta de acuerdo? (1)SI (2)NO","1 o 2...",1,2);
        if(confirm==1)
        {
            (cliente+index)->isEmpty=1;
            ret=0;
        }
    }
    else
    {
        printf("NO Hay Clientes");
    }
    return ret;
}

/** \brief Hardcodear un Cliente
 *
 * \param cliente->Array
 * \param lengthCliente->Limite del Array
 * \param index->Posicion
 * \param nombre->Nombre del Cliente
 * \return -1 Error // 0 Todo ok
 *
 */
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
    return ret;
}

/** \brief Imprime los Clientes Activos
 *
 * \param cliente->Array
 * \param lengthCliente->Limite del Array
 * \param index->Posicion
 * \param
 * \return -1 Error Cliente inactivo // 0 Todo ok
 *
 */
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
