#include "asociado.h"
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "utn.h"
#define QTY_ASOCIADOS 6

int main()
{
    Asociado sAsociado[QTY_ASOCIADOS];
    asociado_init(sAsociado,QTY_ASOCIADOS,1);
    int index;
    int opcion;
    do
    {
        utn_getEntero(&opcion,2,"INGRESE OPCION: \n1-ALTA DE ASOCIADO\n","ERROR DE OPCION",0,7);
        switch(opcion)
        {
            case 1:
                printf("ALTA DE ASOCIADO");
                index=asociado_getFreePlace(sAsociado,QTY_ASOCIADOS);
                asociado_alta(sAsociado,QTY_ASOCIADOS,index);
                break;
        }
    }while(opcion!=7);
    return 0;
}
