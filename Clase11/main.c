#include <stdio.h>
#include <stdlib.h>
#include"asociado.h"
#include<string.h>
#include <stdio.h>
#include <stdlib.h>
#include<stdio_ext.h>
#include"utn.h"
#define QTY_ASOCIADOS 6
int main()
{
    Asociado sAsociado[QTY_ASOCIADOS];
    asociado_init(sAsociado,QTY_ASOCIADOS,1);
    int opcion;
    do
    {
        utn_getEntero(&opcion,2,"INGRESE OPCION: \n1-ALTA DE ASOCIADO\n","ERROR DE OPCION",0,7);
        switch(opcion)
        {
            case 1:
                printf("ALTA DE ASOCIADO");
                asociado_alta(sAsociado,QTY_ASOCIADOS,asociado_getFreePlace(sAsociado,QTY_ASOCIADOS));
                break;
        }
    }while(opcion!=7);
    printf("Hello world!\n");
    return 0;
}
