#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "utn.h"
int main()
{
    /*
    int funcion(void)
    {
        static int i=9;
        i++;
        return i;
    }
    */
    //float numero;
    char caracter;
    /*if(utn_getDecimal(&numero,3,"Ingresa un numero decimal: ","\n error numero NO entero...",0,10)==0)
    {
        printf("\nEl numero es correcto");
    }*/

    if(utn_getChar(&caracter,3,"\nIngrese un caracter: ")==0)
    {
        printf("Es correcto");
    }
    return 0;
}
