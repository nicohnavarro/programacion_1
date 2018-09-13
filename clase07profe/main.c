#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"


#define CANTIDAD_EMPLEADOS 6

int main()
{
    float edades[CANTIDAD_EMPLEADOS] = {50,10,30,1,10,22};

    char nombres[15][50];


    int i;
    for(i=0;i < CANTIDAD_EMPLEADOS;i++)
    {
        if(utn_getFloat(&edades[i],"\nEdad?","\nEdad fuera de rango",1.2,10.4,2)==-1)
        {
            edades[i] = -1;
        }
    }



    return 0;
}
