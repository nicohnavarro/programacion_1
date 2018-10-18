#include <stdio.h>
#include <stdlib.h>
#include "service.h"
#include <string.h>

static int isValidGravedad(int gravedad);
static int isValidMensaje(char* mensaje);
static int isValidServiceId(int ServiceId);

Service* service_new(void)
{

    return (Service*) malloc(sizeof(Service));
}

Service*service_newParametros(int gravedad, char* mensaje,int serviceId)
{
    Service* this=service_new();
    if(this==NULL ||
        service_setGravedad(this,gravedad) ||
        service_setMensaje(this,mensaje) ||
        service_setServiceId(this,serviceId))
    {
        service_delete(this);
        this=NULL;
    }

    return this;
}

void service_delete(Service* this)
{
    free(this);
}

int service_setGravedad(Service*this,int gravedad)
{
    int retorno=-1;
    if(this !=NULL && !isValidGravedad(gravedad))
    {

       this->gravedad=gravedad;
        retorno=0;
    }
    return retorno;
}

int service_getGravedad(Service*this,int* gravedad)
{
    int retorno=-1;
    if(this !=NULL)
    {
        *gravedad=this->gravedad;
        retorno=0;
    }
    return retorno;
}

static int isValidGravedad(int gravedad)
{
    int retorno=-1;
    if(gravedad!=0)
    {
        retorno=0;
    }
    return retorno;
}

int service_setMensaje(Service*this,char* mensaje)
{
    int retorno=-1;
    if(this !=NULL && !isValidMensaje(mensaje))
    {
        strcpy(this->mensaje,mensaje);
        retorno=0;
    }
    return retorno;
}

int service_getMensaje(Service*this,char* mensaje)
{
    int retorno=-1;
    if(this !=NULL)
    {
        strcpy(mensaje,this->mensaje);
        retorno=0;
    }
    return retorno;
}

static int isValidMensaje(char* mensaje)
{
    int retorno=-1;
    if(mensaje!=NULL)
    {
        retorno=0;
    }
    return retorno;
}

int service_setServiceId(Service*this,int serviceId)
{
    int retorno=-1;
    if(this !=NULL && !isValidServiceId(serviceId))
    {

       this->serviceId=serviceId;
        retorno=0;
    }
    return retorno;
}

int service_getServiceId(Service*this,int* serviceId)
{
    int retorno=-1;
    if(this !=NULL)
    {
        *serviceId=this->serviceId;
        retorno=0;
    }
    return retorno;
}

static int isValidServiceId(int serviceId)
{
    int retorno=-1;
    if(serviceId>-1)
    {
        retorno=0;
    }
    return retorno;
}

void service_print(Service* this)
{
    printf("\n- Gravedad %d - Mensaje :%s - ServiceId [%d]",this->gravedad,this->mensaje,this->serviceId);
}
