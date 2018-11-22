
#include "Empleado.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Empleado* Empleado_new()
{
    Empleado* this;
    this=malloc(sizeof(Empleado));
    return this;
}

void Empleado_delete(Empleado* this)
{
    free(this);
}

Empleado* Empleado_newConParametros(char* id,char* name ,char* horasTrabajadas,char* salario)
{
    Empleado* this;
    this=Empleado_new();
    int auxId=atoi(id);
    int auxSalario=atoi(salario);
    int auxHoras=atoi(horasTrabajadas);


    if(!Empleado_setId(this,auxId) &&
        !Empleado_setName(this,name) &&
        !Empleado_setHorasTrabajadas(this,auxHoras) &&
        !Empleado_setSalario(this,auxSalario))
            return this;

    Empleado_delete(this);
    return NULL;
}

int Empleado_setId(Empleado* this,int id)
{
    int retorno=-1;
    static int proximoId=-1;

    if(this!=NULL && id==-1)
    {
        proximoId++;
        this->id=proximoId;
        retorno=0;
    }
    else if(id>proximoId)
    {
        proximoId=id;
        this->id=proximoId;
        retorno=0;
    }
    return retorno;
}

int Empleado_getId(Empleado* this,int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

int Empleado_setName (Empleado* this,char* name )
{
    int retorno=-1;
    if(this!=NULL && name !=NULL)
    {
        strcpy(this->name ,name );
        retorno=0;
    }
    return retorno;
}

int Empleado_getName (Empleado* this,char* name )
{
    int retorno=-1;
    if(this!=NULL && name !=NULL)
    {
        strcpy(name ,this->name );
        retorno=0;
    }
    return retorno;
}

int Empleado_setHorasTrabajadas(Empleado* this,int horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->horasTrabajadas=horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

int Empleado_getHorasTrabajadas(Empleado* this,int* horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

int Empleado_setSalario(Empleado* this,int salario)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->salario=salario;
        retorno=0;
    }
    return retorno;
}

int Empleado_getSalario(Empleado* this,int* salario)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *salario=this->salario;
        retorno=0;
    }
    return retorno;
}

int em_calcularSueldo(void* pEmpleado)
{
    int retorno=0;
    if(pEmpleado!=NULL && ((Empleado*)pEmpleado)->horasTrabajadas < 120)
    {
        ((Empleado*)pEmpleado)->salario=180;
        retorno=1;
    }
    else if(pEmpleado!=NULL && ((Empleado*)pEmpleado)->horasTrabajadas >= 120 && ((Empleado*)pEmpleado)->horasTrabajadas < 160)
    {
       ((Empleado*)pEmpleado)->salario=240;
        retorno=1;
    }
    else if(pEmpleado!=NULL && ((Empleado*)pEmpleado)->horasTrabajadas >= 160 && ((Empleado*)pEmpleado)->horasTrabajadas <= 240)
    {
       ((Empleado*)pEmpleado)->salario=350;
        retorno=1;
    }
    return retorno;
}
