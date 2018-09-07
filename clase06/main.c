#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#define QTY_EMPLEADOS 6

int main()
{
    int edades[QTY_EMPLEADOS];
    int i;
    int maximo;

    initArray(edades,QTY_EMPLEADOS,-1);
    mostrarArray(edades,QTY_EMPLEADOS);

    for (i=0;i<QTY_EMPLEADOS;i++)
    {
        if(utn_getEntero(&edades[i],2,"Ingresa edad: ","Error\n",0,120))
        //&edades[i] => (edades+i)
        {
          edades[i]=-1;
        }
    }

    printf("\n");
    //mostrarArray(edades+2,QTY_EMPLEADOS-2);
    calcularMaximo(edades,QTY_EMPLEADOS,&maximo);
    printf("el maximo es: %d\n",maximo);
    ordenarArray(edades,QTY_EMPLEADOS,1);
    mostrarArray(edades,QTY_EMPLEADOS);
    printf("\n");
    ordenarArray(edades,QTY_EMPLEADOS,0);
    mostrarArray(edades,QTY_EMPLEADOS);

    return 0;
}




