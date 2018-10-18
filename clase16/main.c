#include <stdio.h>
#include <stdlib.h>
#include"empleado.h"
#include"service.h"
#include"user.h"
int main()
{
    /*
    Empleado* auxiliar;
    auxiliar=empleado_newParametros("juan","perez",1.83);
    empleado_print(auxiliar);
    */
/*
    Empleado* listaEmpleados[1000];
    int qtyEmpleados=0;
    int i;
    char auxiliar[50];
    for(i=0;i<100;i++)
    {
        sprintf(auxiliar,"Juan %d",i);
        listaEmpleados[i]=empleado_newParametros(auxiliar,"Perez",1.82);
        qtyEmpleados++;
    }
    ordenar((void*)listaEmpleados,qtyEmpleados,empleado_compareNombre);
    for(i=0;i<qtyEmpleados;i++)
    {
        empleado_print(listaEmpleados[i]);
    }*/

    /*
    Service* listaService[50];
    int qtyService=0;
    int i;
    char auxiliar[50];
    for(i=0;i<20;i++)
    {
        sprintf(auxiliar,"Mensaje  %d",i);
        listaService[i]=service_newParametros(1,auxiliar,qtyService);
        qtyService++;
    }
    for(i=0;i<qtyService;i++)
    {
        service_print(listaService[i]);
    }
*/
    User* listaUser[50];
    int qtyUser=0;
    int i;
    for(i=0;i<20;i++)
    {
        listaUser[i]=user_newParametros(qtyUser,"Nico","tunombre@gmail.com");
        qtyUser++;
    }
    for(i=0;i<qtyUser;i++)
    {
        user_print(listaUser[i]);
    }
    return 0;
}
