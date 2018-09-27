#include "utn.h"
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include"pantalla.h"
#include"contratacion.h"
#define QTY_PANTALLAS 5
#define QTY_CONTRATACION 10
/*
PREGUNTAR
1)COMO HAGO PARA MODIFICAR CUANDO TENGO 2 O MAS PANTALLAS EN LA CONTRATACION
2)IDEM CANCELACION
3)CUANDO MUESTRA LAS PANTALLAS DEL CLIENTE TENGO QUE DECIR CUALES ESTAN DADAS DE BAJA
*/
int main()
{
    Pantalla spantalla[QTY_PANTALLAS];
    Contratacion scontratacion[QTY_CONTRATACION];
    int opcion;
    int index;
    int idPantalla;
    int indexContra;
    char cuitCliente[14];
    int pos;

    arrayInit(spantalla,QTY_PANTALLAS,1);
    arrayInitContra(scontratacion,QTY_CONTRATACION,1);
    setPantalla(spantalla,0,1,"Pantalla 1","Avenida Mitre 220",1200);
    setPantalla(spantalla,1,1,"Pantalla 2","Belgrano 1200",1000);
    setPantalla(spantalla,2,0,"Pantalla 3","Las Flores 100",900);
    setPantalla(spantalla,3,1,"Pantalla 4","Puente Pueyrredon",1300);
    setContratacion(scontratacion,0,"20-11017502-2","Video1.mp4",14,1);
    setContratacion(scontratacion,2,"23-11179042-8","Video20.amv",24,2);
    setContratacion(scontratacion,4,"20-11017502-2","Video4.mp4",5,1);
    setContratacion(scontratacion,1,"20-11017502-2","Video1.mp4",7,3);
    do
    {
        utn_getEntero(&opcion,2,"/*Ingrese una opcion\n1-ALTA PANTALLA\n2-MODIFICACION PANTALLA\n3-BAJA PANTALLA\n\n4-CONTRATAR PUBLICIDAD\n5-MODIFICAR CONTRATACION\n6-CANCELAR CONTRATACION \n\n7-CONSULTA FACTURACION \n\n8-LISTAR CONTRATACIONES \n9-LISTAR PANTALLAS\n\n10-INFORMES\n\n11-SALIR\n","Error",1,11);
        switch(opcion)
        {
            case 1:
                index=getIndiceVacio(spantalla,QTY_PANTALLAS);
                if(index>=0)
                {
                    printf("Dar de alta a una Pantalla. ");
                    altaPantalla(spantalla,index,QTY_PANTALLAS);
                    break;
                }
                break;
            case 2:
                printf("Modificar a una Pantalla. ");
                utn_getEntero(&index,2,"Ingrese el ID de la pantalla.","Error",0,100000);
                modificarPantalla(spantalla,QTY_PANTALLAS,buscarPorId(spantalla,QTY_PANTALLAS,index));
                break;
            case 3:
                printf("Dar de baja a una Pantalla");
                utn_getEntero(&index,2,"Ingrese el ID de la pantalla.","Error",0,100000);
                darBajaPantalla(spantalla,QTY_PANTALLAS,index);
                cancelarContratacion(scontratacion,QTY_CONTRATACION,spantalla[index].id);
                break;
            case 4:
                printf("Listar pantallas\n");
                utn_getEntero(&idPantalla,2,"Dame id de la pantalla","Error",0,QTY_PANTALLAS);
                indexContra=getIndiceVacioContra(scontratacion,QTY_CONTRATACION);
                altaContratacion(scontratacion,QTY_CONTRATACION,indexContra,idPantalla);
                break;
            case 5:
                utn_getCuit(cuitCliente,14,2,"Ingrese Cuit [XX-XXXXXXXX-X]:","Error");
                modificarContratacion(scontratacion,QTY_CONTRATACION,cuitCliente,spantalla,QTY_PANTALLAS);
                utn_getEntero(&idPantalla,2,"Ingrese ID de la Pantalla a Modificar: ","Error",0,QTY_PANTALLAS);
                pos=buscarPosicionPorCuit(scontratacion,QTY_CONTRATACION,cuitCliente,idPantalla);
                modificarDiasContratacion(scontratacion,QTY_CONTRATACION,pos);
                break;
            case 6:
                utn_getCuit(cuitCliente,14,2,"Ingrese Cuit [XX-XXXXXXXX-X]:","Error");
                modificarContratacion(scontratacion,QTY_CONTRATACION,cuitCliente,spantalla,QTY_PANTALLAS);
                utn_getEntero(&idPantalla,2,"Ingrese ID de la Pantalla a Cancelar: ","Error",0,QTY_PANTALLAS);
                cancelarContratacion(scontratacion,QTY_CONTRATACION,idPantalla);
                break;
            case 7:
                utn_getCuit(cuitCliente,14,2,"Ingrese Cuit [XX-XXXXXXXX-X]:","Error");
                consultarFacturacion(scontratacion,QTY_CONTRATACION,cuitCliente,spantalla,QTY_PANTALLAS);
                break;
            case 8:
                printf("Listar Contrataciones.\n");
                printContratacion(scontratacion,QTY_CONTRATACION,spantalla,QTY_PANTALLAS);
                break;
            case 9:
                printf("Listar Pantallas.\n");
                listarPantallas(spantalla,QTY_PANTALLAS);
                break;
            case 10:
                listarClientes(scontratacion,spantalla,QTY_CONTRATACION,QTY_PANTALLAS);
                break;

        }
    }while(opcion!=11);
    return 0;
}
