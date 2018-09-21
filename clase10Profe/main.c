#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "producto.h"

#define CANTIDAD_PRODUCTOS 4

/*
1)  Definir un tipo de dato que represente un producto.
    El producto tiene un nombre, una descripcion y un precio

2)  Definir un array de 200 productos, indicar de alguna manera
    que la info de cada item no esta cargada.

3)  Realizar una funcion que reciba el array, un indice, y le
    permita al usuario cargar los datos en el item de la posicion especificada por el indice.

4)  Realizar una funcion que reciba el array y un indice e imprima
    los datos del item de la posicion especificada por el indice.

5)  Realizar una funcion que me devuelva el indice de un item vacio (sin cargar).


3) Realizar un programa con un menu de dos opciones:
    a) Cargar un producto
    b) Imprimir lista productos

------
4)  Agregar al tipo de dato el campo ID que represente un identificador unico.
    Modificar el codigo anterior para que el ID se genere automaticamente.
    Se debera cargar el ID automaticamente al cargar un producto, y se debera imprimir al imprimir la lista.

5)  Realizar una funcion que reciba el array y un ID, y me devuelva el indice
    del item con dicho ID.

6)  Realizar una funcion que reciba el array, un indice, y le permita al usuario
    modificar los campos nombre y precio del item del array en la posicion especificada por el indice.


7)  Agregar una opcion en el menu. "Editar producto" que pida al usuario el ID del
    mismo y le permita cambiar el nombre y el precio.

8)  Agregar una opcion en el menu "Borrar producto" que pida al usuario el ID del
    mismo.

*/
int main()
{
    int libre;
    Producto arrayProductos[CANTIDAD_PRODUCTOS];

    producto_init(arrayProductos,CANTIDAD_PRODUCTOS,1);
    producto_altaProducto(arrayProductos,CANTIDAD_PRODUCTOS);

    printf("\n---%s",arrayProductos[0].nombre);

    producto_mostrar(arrayProductos,CANTIDAD_PRODUCTOS);

    return 0;
}






