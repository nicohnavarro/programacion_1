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


static int generarIDVentas(void);

/** \brief Inicializa el Array de Tipo Ventas
 *
 * \param ventas ->Array de Ventas
 * \param lengthVentas ->Limite del Array
 * \param value ->Valor a cargar en este caso (1)
 * \param
 * \return -1 Error // 0 Todo OK
 *
 */

int ventas_init(Ventas* ventas,int lengthVentas,int value)
{
    int ret=-1;
    int i;
    if(ventas!=NULL && lengthVentas>0)
    {
        for(i=0;i<lengthVentas;i++)
        {
            ventas[i].isEmpty=value;
            ret=0;
        }
    }
    return ret;
}

/** \brief Encuentra el primer Luegar Libre del Array
 *
 * \param ventas->Array tipo Ventas
 * \param lengthVentas->Limite del Array
 * \param
 * \param
 * \return -1 Error // 0 Todo ok
 *
 */
int ventas_getFreePlace(Ventas* ventas,int lengthVentas)
{
    int ret=-1;
    int i;
    if(ventas!=NULL && lengthVentas>0)
    {
        for(i=0;i<lengthVentas;i++)
        {
            if(ventas[i].isEmpty==1)
            {
                ret=i;
                break;
            }
        }
    }
    return ret;
}

static int generarIDVentas(void)
{
    static int clienteIDVentas=-1;
    clienteIDVentas++;
    return clienteIDVentas;
}

/** \brief Se realiza una venta con el Id de Cliente recibido
 *
 * \param ventas->Array de Ventas
 * \param lengthVentas->Limite del Array de Ventas
 * \param idCliente->Numero de ID del Cliente
 * \param cliente->Array de Cliente
 * \param lengthCliente->Limite del Array de Cliente
 * \return -3 Error en el ID // -1 Error // 0 Todo ok
 *
 */
int ventas_venderAfiche(Ventas* ventas,int lengthVentas,int idCliente,Cliente* cliente,int lengthCliente)
{
    int ret=-1;
    int cantidadAfichesAux;
    char nombreVideoAux[50];
    int zonaAux;
    int index;
    int clienteP;
    clienteP=cliente_getClienteById(cliente,lengthCliente,idCliente);
    index=ventas_getFreePlace(ventas,lengthVentas);
    if(cliente[clienteP].isEmpty==0 && index>=0)
    {
        if(!utn_getEntero(&cantidadAfichesAux,1,"Ingrese cantidad de Afiches MAX 15","Error",1,15))
        {
            if(!utn_getString(nombreVideoAux,30,1,"Ingrese Nombre del video: ","Error"))
            {
                if(!utn_getEntero(&zonaAux,1,"Ingrese zona: \n0-CABA\n1-ZONA SUR\n2-ZONA OESTE\n","Error",0,2))
                {
                    ventas[index].cantidadAfiches=cantidadAfichesAux;
                    strncpy(ventas[index].nombre,nombreVideoAux,30);
                    ventas[index].zona=zonaAux;
                    ventas[index].idCliente=idCliente;
                    ventas[index].id=generarIDVentas();
                    ventas[index].isEmpty=0;
                    ventas[index].estado=0;
                    ret=0;
                    printf("Se ha Vendido ID[%d]- Estado [%d]\n",ventas[index].id,ventas[index].estado);
                    printf("Estado 0 ( A COBRRAR)\nEstado 1 (COBRADO)\n");
                }
            }
        }
    }
    else
    {
        ret=-3;
        printf("ERROR con EL id De Cliente\n");
    }
    return ret;

}

/** \brief Imprime las Ventas Activas
 *
 * \param ventas->Array de Ventas
 * \param lengthVentas->Limite del Array Ventas
 * \param
 * \param
 * \return -1 Error // 0 Todo ok
 *
 */
int ventas_imprimirVentas(Ventas* ventas,int lengthVentas)
{
    int ret=-1;
    int i;
    if(ventas!=NULL && lengthVentas>0)
    {
        for(i=0;i<lengthVentas;i++)
        {
            if(ventas[i].isEmpty==0)
            {
                printf("ID [%d]-NOMBRE : [%s]-CANTIDAD AFICHES [%d]-CLIENTE ID [%d]-ZONA [%d]- ESTADO [%d]\n",
                ventas[i].id,ventas[i].nombre,ventas[i].cantidadAfiches,ventas[i].idCliente,ventas[i].zona,ventas[i].estado);
                ret=0;
            }
        }
    }
    return ret;
}

/** \brief Hardcodea Ventas
 *
 * \param ventas->Array de tipo Ventas
 * \param index->Posicion
 * \param lengthVentas->Limite del Array
 * \param nombre->Nombre de la venta
 * \return -1 Error // 0 Todo ok
 *
 */
int ventas_set(Ventas* ventas,int index,int lengthVentas,char* nombre,int cantidadAfiches,int idCliente,int zona,int estado)
{
    int ret=-1;
    if(ventas!=NULL && lengthVentas>0 && nombre!=NULL)
    {
        strncpy(ventas[index].nombre,nombre,30);
        ventas[index].cantidadAfiches=cantidadAfiches;
        ventas[index].idCliente=idCliente;
        ventas[index].zona=zona;
        ventas[index].estado=estado;
        ventas[index].isEmpty=0;
        ventas[index].id=generarIDVentas();
        ret=0;
    }
    return ret;
}

/** \brief Busca una Venta por el campo ID
 *
 * \param ventas->Array de Ventas
 * \param lengthVentas->Limite del Array
 * \param id->ID de ventas
 * \param
 * \return -1 Error // i Posicion en el Array
 *
 */

int venta_getVentaById(Ventas* ventas,int lengthVentas,int id)
{
    int ret=-1;
    int i;
    if(ventas!=NULL && lengthVentas>0)
    {
        for(i=0;i<lengthVentas;i++)
        {
            if(ventas[i].id==id)
            {
                ret=i;
                break;
            }
        }

    }
    return ret;
}
/** \brief Modifica las Ventas
 *
 * \param ventas->Array de Ventas
 * \param lengthVentas->Limite del Array
 * \param idVenta->Id de la venta a modificar
 * \param
 * \return -3 Error en la Venta -1 Error // 0 Todo ok
 *
 */
int ventas_editar(Ventas* ventas,int lengthVentas,int idVenta)
{
    int ret=-1;
    int index;
    int cantidadAfichesAux;
    int zonaAux;
    index=venta_getVentaById(ventas,lengthVentas,idVenta);
    if(ventas[index].isEmpty==0 && index>=0)
    {
        if(!utn_getEntero(&cantidadAfichesAux,1,"Ingrese NUEVA cantidad de Afiches MAX 15","Error",1,15))
        {
            if(!utn_getEntero(&zonaAux,1,"Ingrese NUEVA zona: \n0-CABA\n1-ZONA SUR\n2-ZONA OESTE\n","Error",0,2))
                {
                    ventas[index].cantidadAfiches=cantidadAfichesAux;
                    ventas[index].zona=zonaAux;
                    ret=0;
                    printf("Se ha MODIFICADO ID[%d]- Estado [%d]\n",ventas[index].id,ventas[index].estado);
                    printf("Estado 0 ( A COBRRAR)\nEstado 1 (COBRADO)\n");
                }
        }
    }
    else
    {
        printf("No Existe esa Venta\n");
        ret=-3;
    }
    return ret;
}

/** \brief Cobrar Ventas pasar de estado 0 a 1
 *
 * \param ventas->Array de Ventas
 * \param lengthVentas->Limite del Array de Ventas
 * \param cliente->Array de Cliente
 * \param lengthCliente->Limite del Array de Cliente
 * \param idVenta->Id de la Venta a Cobrar
 * \return -3 Error la venta ya esta cobrada -1 Error // 0 Todo ok
 *
 */
int ventas_cobrarVentas(Ventas* ventas,int lengthVentas,Cliente* cliente,int lengthClientes,int idVenta)
{
    int ret=-1;
    int index;
    int idClienteAux;
    int clienteP;
    int confirm;
    index=venta_getVentaById(ventas,lengthVentas,idVenta);
    idClienteAux=ventas[index].idCliente;
    clienteP=cliente_getClienteById(cliente,lengthClientes,idClienteAux);
    cliente_ImprimirCliente(cliente,lengthClientes,clienteP);
    if(cliente[clienteP].isEmpty==0 && ventas[index].isEmpty==0 && ventas[index].estado==0)
    {
        utn_getEntero(&confirm,1,"Va a confirmar El cambio de estado...\n(0)SI...\n(1)NO...\n","Error",0,1);
        if(!confirm)
        {
            ventas[index].estado=1;
            printf("\nCambio el ESTADO ...\n");
            ret=0;
        }
    }
    else
    {
        ret=-3;
        printf("\nEl estado ya es (1)COBRADO\n");
    }
    return ret;
}
/** \brief Impirime clientes y cantidad de Ventas de cada Cliente
 *
 * \param cliente->Array de Cliente
 * \param venta->Array de Ventas
 * \param lengthCliente->Limite del Array de Cliente
 * \param lengthVentas->Limite del Array de Ventas
 * \return -1 Error // 0 Todo ok
 *
 */

int ventas_cantidadVentas(Cliente* cliente,Ventas* venta,int lengthCliente,int lengthVentas)
{
    int ret=-1;
    int cantidadVentas;
    int i;
    for(i=0;i<lengthCliente;i++)
    {
        cantidadVentas=0;
        if(cliente[i].isEmpty==0)
        {
            cantidadVentas=ventas_contarVentasDeCliente(venta,lengthVentas,cliente[i].id);
            cliente_ImprimirCliente(cliente,lengthCliente,i);
            printf("- Cantidad de ventas del Cliente [%d]\n\n",cantidadVentas);
            ret=0;
        }
    }
    return ret;
}

/** \brief Cuenta Las ventas de un Cliente en Particular
 *
 * \param ventas->Array de Ventas
 * \param lengthVentas->Limite del Array de Ventas
 * \param idCliente->ID del Cliente a contar
 * \return -1 Error // int Cantidad de Ventas de ese Cliente
 *
 */
int ventas_contarVentasDeCliente(Ventas* ventas,int lengthVentas,int idCliente)
{
    int i;
    int contadorDeVentas=0;
    if(ventas!=NULL && lengthVentas>0)
    {
        for(i=0;i<lengthVentas;i++)
        {
            if(idCliente==ventas[i].idCliente && ventas[i].isEmpty==0)
            {
                contadorDeVentas++;
            }
        }
    }
    return contadorDeVentas;
}
