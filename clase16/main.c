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
    }

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

    User* listaUser[50];
    int qtyUser=0;
    int j;
    char auxiliar2[50];
    for(j=0;j<20;j++)
    {
        sprintf(auxiliar2,"Name %d",j);
        listaUser[j]=user_newParametros(qtyUser,auxiliar2,"tunombre@gmail.com");
        qtyUser++;
    }
    for(j=0;j<qtyUser;j++)
    {
        user_print(listaUser[j]);
    }
    */
    return 0;
}
