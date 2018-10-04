#include "asociado.h"
#include <strings.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include"utn.h"

static int asociado_generarId(void);

static int asociado_generarId(void)
{
    static int id=-1;
    id++;
    return id;
}

int asociado_init(Asociado* aso,int lengthAsociado,int value)
{
    int ret=-1;
    int i;
    for(i=0;i<lengthAsociado;i++)
    {
        aso[i].isEmpty=value;
        ret=0;
    }
    return ret;
}

int asociado_set(Asociado* aso,int lengthAsociado,int index,char* name,char* lastName,char* dni,int age)
{
    int ret=-1;
    if(index<lengthAsociado)
    {
        strcpy(aso[index].name,name);
        strcpy(aso[index].lastName,lastName);
        strncpy(aso[index].dni,dni,8);
        aso[index].age=age;
        aso[index].isEmpty=0;
        aso[index].id=asociado_generarId();
        ret=0;
    }
    return ret;
}

int asociado_getFreePlace(Asociado* aso,int lengthAsociado)
{
    int ret=-1;
    int i;
    if(aso!=NULL && lengthAsociado>0)
    {
        for(i=0;i<lengthAsociado;i++)
        {
            if(aso[i].isEmpty==1)
            {
                ret=i;
                break;
            }
        }
    }
    return ret;
}

int asociado_alta(Asociado* aso,int lengthAsociado,int index)
{
    clearStdin();
    int ret=-1;
    int auxAge=23;
    char auxName[30];
    char auxLastName[30];
    char auxDni[8];

    if(lengthAsociado>index)
    {
        __fpurge(stdin);
        utn_getDni(auxDni,8,1,"INGRESE DNI: ","ERROR DE DNI");
        //utn_getString(auxName,30,2,"INGRESE NOMBRE: ","ERROR DE NOMBRE");
        utn_getLetras(auxName,30,2,"INGRESE NOMBRE: ","ERROR DE NOMBRE");
        //utn_getString(auxLastName,30,2,"INGRESE APELLIDO: ","ERROR DE APELLIDO");

        //getStringLetras("Ingrese nombre",auxName);

        printf("hola");
        strcpy(aso[index].name,auxName);
        printf("hola1");
        strcpy(aso[index].lastName,auxLastName);
        printf("hola2");
        strcpy(aso[index].dni,auxDni);
        printf("hola3");


        aso[index].age=auxAge;
        printf("hola4");
        aso[index].isEmpty=0;
        aso[index].id=asociado_generarId();


        /*if(utn_getString(auxName,30,2,"INGRESE NOMBRE: ","ERROR DE NOMBRE")==0)
        {
            if(utn_getString(auxLastName,30,2,"INGRESE APELLIDO: ","ERROR DE APELLIDO")==0)
            {
                if(utn_getDni(auxDni,8,1,"INGRESE DNI: ","ERROR DE DNI")==0)
                {
                    if(utn_getEntero(&auxAge,2,"INGRESE EDAD: ","ERROR DE EDAD",0,100)==0)
                    {
                        strncpy(aso[index].name,auxName,30);
                        strncpy(aso[index].lastName,auxLastName,30);
                        strncpy(aso[index].dni,auxDni,8);
                        aso[index].age=auxAge;
                        aso[index].isEmpty=0;
                        aso[index].id=asociado_generarId();
                        printf("Dado de ALTA Id[%d]\n",aso[index].id);
                        largo=sizeof(aso[index].name);
                        printf("largo %d",largo);
                        printf("nombre: %s",aso[index].lastName);
                        ret=0;
                    }
                }
            }
        }*/
    }
    return ret;
}
