#include <stdio.h>
#include <stdlib.h>
#include "Venta.h"
#include "LinkedList.h"
#include "Parser.h"
#include "generadorInformes.h"
int main()
{
    // Definir lista de empleados
    LinkedList* listaVentas;
    listaVentas=ll_newLinkedList();
    // Crear lista empledos
    //...

    // Leer empleados de archivo data.csv
    if(parser_parseVentas("data.csv",listaVentas)==1)
     {
        if(generarInformes("informes.txt",listaVentas)==0)
        {
            printf("Archivo Informes.txt generado con exito...\n");
        }
     }


    return 0;
}
