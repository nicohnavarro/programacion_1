#include "utn.h"
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include"pantalla.h"
#define QTY_PANTALLAS 100

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
    int opcion;
    int index;
    do
    {
        utn_getEntero(&opcion,2,"/*Ingrese una opcion\nAlta(1)\tModificacion(2)\tBaja(3)\nSALIR(4)","Error",1,4);
        arrayInit(spantalla,QTY_PANTALLAS,1);
        switch(opcion)
        {
            case 1:
                printf("Dar de alta a una Pantalla. ");
                altaPantalla(spantalla,getIndiceVacio(spantalla,QTY_PANTALLAS),QTY_PANTALLAS);
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
        }
    }while(opcion!=4);


    return 0;
}
