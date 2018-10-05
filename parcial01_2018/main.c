#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "cliente.h"
#include "ventas.h"
#include <string.h>
#include <stdio_ext.h>
#define QTY_CLIENTES 10
#define QTY_VENTAS 20
#define ESTADO_ACOBRAR 0
#define ESTADO_COBRADO 1
#define CABA 0
#define ZONASUR 1
#define ZONAOESTE 2

int main()
{
    Cliente cliente[QTY_CLIENTES];
    cliente_init(cliente,QTY_CLIENTES,1);
    cliente_set(cliente,QTY_CLIENTES,0,"Nicolas","Navarro","20-37354627-2");
    cliente_set(cliente,QTY_CLIENTES,1,"Felipe","Perez","20-34354657-4");
    cliente_set(cliente,QTY_CLIENTES,3,"Hernan","Rodriguez","20-31352627-5");
    Ventas ventas[QTY_VENTAS];
    ventas_init(ventas,QTY_VENTAS,1);
    ventas_set(ventas,0,QTY_VENTAS,"Video_1.mp4",10,2,2,0);
    ventas_set(ventas,1,QTY_VENTAS,"Video_4.amv",5,1,0,0);
    ventas_set(ventas,2,QTY_VENTAS,"Video3.mp4",2,1,2,1);

    int opcion;
    int index;
    int idCliente;
    int idVenta;
    do
    {
        printf("Menu de Clientes \n1-Alta de Cliente\n2-Modificar el Cliente\n"
        "3-Baja de Cliente\n4-Vender Afiches\n5-Editar Venta\n"
        "6-Cobrar venta\n7-Impirimir Clientes\n8-Salir\n");
        utn_getEntero(&opcion,2,"Ingrese opcion : ","Error de Opcion",0,8);
        switch(opcion)
        {
         case 1:
            printf("Alta de Cliente\n");
            index=cliente_getFreePlace(cliente,QTY_CLIENTES);
            cliente_alta(cliente,QTY_CLIENTES,index);
            break;
        case 2:
            printf("Modificacion de Cliente\n");
            utn_getEntero(&idCliente,2,"Ingrese ID del Cliente que desea MODIFICAR","Error de id",0,QTY_CLIENTES);
            index=cliente_getClienteById(cliente,QTY_CLIENTES,idCliente);
            cliente_modificar(cliente,QTY_CLIENTES,index);
            break;
        case 3:
            printf("Baja de Cliente\n");
            utn_getEntero(&idCliente,2,"Ingrese ID del Cliente que desea dar de BAJA","Error de id",0,QTY_CLIENTES);
            index=cliente_getClienteById(cliente,QTY_CLIENTES,idCliente);
            cliente_baja(cliente,QTY_CLIENTES,index);
            break;
        case 4:
            printf("Vender Afiche\n");
            utn_getEntero(&idCliente,2,"Ingrese ID del Cliente para la Venta","Error de id",0,QTY_CLIENTES);
            ventas_venderAfiche(ventas,QTY_VENTAS,idCliente,cliente,QTY_CLIENTES);
            break;
        case 5:
            printf("Editar Venta \n");
            ventas_imprimirVentas(ventas,QTY_VENTAS);
            utn_getEntero(&idVenta,2,"Ingrese ID de la Venta","Error de id",0,QTY_VENTAS);
            ventas_editar(ventas,QTY_VENTAS,idVenta);
            break;
        case 6:
            printf("Cobrar Venta \n");
            ventas_imprimirVentas(ventas,QTY_VENTAS);
            utn_getEntero(&idVenta,2,"Ingrese ID de la Venta","Error de id",0,QTY_VENTAS);
            ventas_cobrarVentas(ventas,QTY_VENTAS,cliente,QTY_CLIENTES,idVenta);
        }

    }while(opcion!=8);


    return 0;
}
