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
void mostrar(LinkedList*lista);

int main()
{
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    /*do{
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                mostrar(listaEmpleados);
                break;
        }
    }while(option != 10);*/
    mostrar(listaEmpleados);
    printf("**************\n");
    controller_loadFromText("data.csv",listaEmpleados);
    mostrar(listaEmpleados);
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
