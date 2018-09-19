/*
1)Definir un tipo de dato que represente un producto.
El producto tiene un nombre, una descripcion y un precio.

2) Definir un array de 200 productos, indicar
de alguna manera que la info no esta cargada.

3)Realizar una funcion que reciba el array,
un indice,y le permita al usuario cargar los datos en el item de
la posicion especificada por el indice.

*/
#include <stdio.h>
#include <stdlib.h>
#include"producto.h"
#include <string.h>
#include"UTN.h"
#define MAX 200
int main()
{
    Producto p[MAX];
    int i;
    /*for (i=0;i<MAX;i++)
    {
      p[i].isEmpty=1;
    }*/
    arrayInit(p,MAX,1);

    /*strcpy(p[5].nombre,"Cocina");
    strcpy(p[5].descripcion,"asdjasdklsadasldjasd");
    p[5].precio=4554.2;
    p[5].isEmpty=0;

    for (i=0;i<MAX;i++)
    {
      if(p[i].isEmpty==1)
      {
        printf(" NO Esta cargado el producto nro: %d\n",i);
      }
    }*/

    altaProducto(p,100,MAX);

    for (i=0;i<MAX;i++)
    {
      if(p[i].isEmpty==0)
      {
        printf(" Esta cargado el producto nro: %d\n",i);
      }
    }
    return 0;
}
