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
void mostrar(LinkedList*lista);

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
                //mostrar(listaEmpleados);
                break;
            case 2:
                controller_loadFromBinary("data.bin",listaEmpleados);
                printf("Los Datos Han sido Cargados Exitosamente\n");
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                mostrar(listaEmpleados);
                break;
            case 7:
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
    //mostrar(listaEmpleados);
    printf("**************\n");
    //controller_loadFromText("data.csv",listaEmpleados);
    //mostrar(listaEmpleados);
    return 0;
}

void mostrar(LinkedList* lista)
{
    int i;
    int auxId;
    char auxNombre[50];
    Employee* aux;

    for(i=0;i<ll_len(lista);i++)
    {

        //Employee* aux = arrayPunteroEmployee[i];
        aux=(Employee*)ll_get(lista,i);


        Employee_getId(aux,&auxId);
        Employee_getNombre(aux,auxNombre);
        printf("\nID: %d - NOMBRE: %s", auxId,auxNombre);
    }
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
