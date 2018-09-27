#include "utn.h"
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include"pantalla.h"
#include"contratacion.h"
#define QTY_PANTALLAS 5
#define QTY_CONTRATACION 10

/*
PANTALLA
-Id
-tipo
-nombre
-direccion
-precio
-isEmpty

CONTRATACION
-Id
-video
-dias
-IdPantalla
-CuitCliente
-isEmpty

*/
int main()
{
    Pantalla spantalla[QTY_PANTALLAS];
    Contratacion scontratacion[QTY_CONTRATACION];
    int opcion;
    int index;
    int idPantalla;
    int indexContra;
    int cuitCliente;
    arrayInit(spantalla,QTY_PANTALLAS,1);
    arrayInitContra(scontratacion,QTY_CONTRATACION,1);
    setPantalla(spantalla,0,1,"panuno","diruno",1200);
    setPantalla(spantalla,1,1,"pandos","dirdos",1000);
    setPantalla(spantalla,2,0,"pantre","dirtre",900);
    setPantalla(spantalla,3,1,"pancua","dircua",1300);
    do
    {
        utn_getEntero(&opcion,2,"/*Ingrese una opcion\nAlta(1)\tModificacion(2)\tBaja(3)\tContratar una publicidad(4) \tModificar condiciones de publicación(5)\tSALIR(6)\n","Error",1,5);
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
                break;
            case 4:
                printf("Listar pantallas\n");
                listarPantallas(spantalla,QTY_PANTALLAS);
                utn_getEntero(&idPantalla,2,"Dame id de la pantalla","Error",0,QTY_PANTALLAS);
                indexContra=getIndiceVacioContra(scontratacion,QTY_CONTRATACION);
                altaContratacion(scontratacion,QTY_CONTRATACION,indexContra,idPantalla);
                printContratacion(scontratacion,QTY_CONTRATACION);
                break;
            case 5:
                utn_getEntero(&cuitCliente,2,"Ingrese el cuit :","error",0,100);

        }
    }while(opcion!=6);


    return 0;
}
