#include <stdio.h>
#include <stdlib.h>
#include "Compra.h"
#include "LinkedList.h"
#include "Parser.h"

/**
    Realizar un programa que lee de un archivo los datos de compras de productos realizadas por clientes.
    Luego se le pedira al usuario que ingrese un id de un producto y el programa deberá imprimir por pantalla:
    - 1. Lista de compras filtrada segun el producto ingresado
    - 2. Monto total de cada compra considerando el valor del iva indicado.

    - 3. Por ultimo la lista filtrada obtenida con los datos ya calculados, debera ser escrita en un archivo separado por
    comas llamado "informe.csv", con el mismo formato que el original pero con una columna mas al final, en donde se
    indicara el monto total calculado.

    Para realizar el punto 1, se debera utilizar la funcion "filter".
    Para realizar el punto 2, se debera utilizar la funcion "map".
    Para imprimir por pantalla la lista, utilizar iterator.
*/

int generarArchivoInforme(char* fileName,LinkedList* listaCompras);

int main()
{
    // Definir lista de compras
    LinkedList* listaCompras;
    LinkedList* listaFiltrada;

    // Crear lista compras
    //...

    // Leer compras de archivo data.csv
    if(parser_parseCompras("data.csv",listaCompras)==1)
    {
        // Filtrar
        printf("Ingrese id de producto:");
        //TODO

        // Calcular montos
        printf("Calculando montos totales...\n");
        //TODO

        // Generar archivo de salida
        if(generarArchivoInforme("informe.csv",listaFiltrada)==1)
        {
            printf("Archivo generado correctamente\n");
        }
        else
            printf("Error generando archivo\n");
    }
    else
        printf("Error leyendo compras\n");


    return 0;
}

int generarArchivoInforme(char* fileName,LinkedList* listaCompras)
{
    return 1;
}
