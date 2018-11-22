#include <stdio.h>
#include <stdlib.h>
#include "Empleado.h"
#include "LinkedList.h"
#include "Parser.h"

/**
    Realizar un programa que lee de un archivo los datos de empleados y los guarda en un arraylist de entidades
    empleado.
    Luego, debera calcular el campo "sueldo" de cada uno de los empleados leidos, segun la horas que trabajaron, con el
    siguiente criterio:
    Los valores de horas varian entre 80 y 240.
    - Las primeras 120 horas la hora vale $180
    - De 120 a 160 horas, la hora vale $240
    - De 160 a 240 horas, la hora vale $350

    Para hacer este calculo, se debera desarrollar la funcion "map" en al biblioteca ArrayList, La cual recibe la lista y una funcion.
    La funcion map ejecutara la funcion recibida como parametro por cada item de la lista, y le pasaran en cada llamada, uno de los items.
    De esta manera la funcion pasada como parametro podra realizar un calculo con el item recibido, en este caso, calcular el sueldo.

    Una vez cargados los campos sueldo en las entidades, se debera generar un archivo de salida "sueldos.csv" el cual sera igual que el
    original pero con una columna mas al final, en donde se indicara el sueldo calculado.
*/

int generarArchivoSueldos(char* fileName,LinkedList* listaEmpleados);

int main()
{
    // Definir lista de empleados
    LinkedList* listaEmpleados;

    // Crear lista empledos
    //...
    listaEmpleados=ll_newLinkedList();
    // Leer empleados de archivo data.csv
    if(parser_parseEmpleados("data.csv",listaEmpleados)==1)
    {
        // Calcular sueldos
        printf("Calculando sueldos de empleados\n");
        ll_map(listaEmpleados,em_calcularSueldo);
        printf("HOLA.");
        // Generar archivo de salida
        if(generarArchivoSueldos("sueldos.csv",listaEmpleados)==1)
        {
            printf("Archivo generado correctamente\n");
        }
        else
            printf("Error generando archivo\n");
    }
    else
        printf("Error leyando empleados\n");


    return 0;
}

int generarArchivoSueldos(char* fileName,LinkedList* listaEmpleados)
{
    int retorno=0;
    FILE* pFile;
    int i;
    int len=ll_len(listaEmpleados);
    Empleado* aux=NULL;
    int auxId;
    int auxHoras;
    int auxSalario;
    char auxNombre[50];
    if(listaEmpleados!=NULL)
    {
        retorno=1;
        pFile=fopen(fileName,"w");
        for(i=0;i<len;i++)
        {
            aux=ll_get(listaEmpleados,i);
            Empleado_getId(aux,&auxId);
            Empleado_getName(aux,auxNombre);
            Empleado_getHorasTrabajadas(aux,&auxHoras);
            Empleado_getSalario(aux,&auxSalario);
            fprintf(pFile,"%d,%s,%d,%d\n",auxId,auxNombre,auxHoras,auxSalario);
        }
    }
    fclose(pFile);
    return retorno;
}
