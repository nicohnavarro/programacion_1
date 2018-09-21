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
-isEmpty

CONTRATACION
-Id
-video
-precio
-dias
-IdPantalla
-CuitCliente
-isEmpty

*/
int main()
{
    Pantalla spantalla[QTY_PANTALLAS];
    int opcion;
    do
    {
        utn_getEntero(&opcion,2,"/*Ingrese una opcion\nAlta(1)\tBaja(2)\tModificacion(3)\nSALIR(4)","Error",1,4);
        arrayInit(spantalla,QTY_PANTALLAS,1);
        switch(opcion)
        {
            case 1:
                printf("Dar de alta a una Pantalla. ");
                altaPantalla(spantalla,getIndiceVacio(spantalla,QTY_PANTALLAS),QTY_PANTALLAS);
                break;
            case 2:
                printf("Dar de baja a una Pantalla. ");
        }
    }while(opcion!=4);


    return 0;
}
