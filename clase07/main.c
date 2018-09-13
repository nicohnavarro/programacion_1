#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#define QTY_EMPLEADOS 5

int main()
{
    float edades[QTY_EMPLEADOS];
    int i;

//    utn_init_array(edades,QTY_EMPLEADOS,-1);
//    utn_mostrar_array(edades,QTY_EMPLEADOS);

    for (i=0;i<QTY_EMPLEADOS;i++)
    {
        utn_getFloat(&edades[i],2,"Ingresa edad: ","Error\n",1,120);
        //&edades[i] => (edades+i)
    }

    printf("\n");
    return 0;
}

