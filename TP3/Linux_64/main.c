#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir

    Properties
*****************************************************/
/*
Funcion sortLinkedlist
Funcion criterio-->

Funcion reduce-->resume la lista

Nodos ->direcciondel anterior
direccion del proximo

controller_saveAsBinary("data.bin",listaEmpleados);
controller_loadFromBinary("data.bin",listaEmpleados);

*/
int main()
{
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{

        printf("\nMENU\n"
                "1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
                "2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n"
                "3. Alta de empleado\n"
                "4. Modificar datos de empleado\n"
                "5. Baja de empleado\n"
                "6. Listar empleados\n"
                "7. Ordenar empleados\n"
                "8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
                "9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n"
                "10. Salir\n");
        utn_getEntero(&option,1,"INGRESE OPCION: ","ERROR DE OPCION",1,10);
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                printf("Los Datos Han sido Cargados Exitosamente\n");
                break;
            case 2:
                controller_loadFromBinary("data.bin",listaEmpleados);
                printf("Los Datos Han sido Cargados Exitosamente\n");
                break;
            case 3:
                controller_addEmployee(listaEmpleados);
                break;
            case 4:
                controller_editEmployee(listaEmpleados);
                break;
            case 5:
                controller_removeEmployee(listaEmpleados);
                break;
            case 6:
                controller_ListEmployee(listaEmpleados);
                break;
            case 7:
                controller_sortEmployee(listaEmpleados);
                break;
            case 8:
                controller_saveAsText("output.cvs",listaEmpleados);
                break;
            case 9:
                controller_saveAsBinary("data.bin",listaEmpleados);
                printf("\nSe ha Guardado en data.bin Exitosamente\n");
                break;
        }
    }while(option != 10);
    printf("**************\n");
    return 0;
}

/*
int buscarPorID(LinkedList* array,int id)
{
    int i;
    int len= ll_len(array);

    for(i=0;i<len;i++)
    {
        //Cliente* c = array[i];
        Cliente* c=(Cliente*)ll_get(array,i);
        int idCliente=c->id;
        if(idCliente==id)
            return i;
    }
}
*/
