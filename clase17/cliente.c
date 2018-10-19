#include "cliente.h"
#include <stdio.h>
#include <stdlib.h>
#include"string.h"
Cliente* cliente_new(void)
{
    return (Cliente*)malloc(sizeof(Cliente));
}

int cliente_setName(Cliente* this,char* name)
{
    int retorno=-1;
    if(this!=NULL && name!=NULL)
    {
        strncpy(this->name,name,sizeof(this->name));
        retorno=0;
    }
    return retorno;
}

int cliente_getName(Cliente*this,char*name)
{
    int retorno=-1;
    if(this!=NULL)
    {
        strncpy(name,this->name,sizeof(this->name));
        retorno=0;
    }
    return retorno;
}

int cliente_setLastName(Cliente* this,char* lastName)
{
    int retorno=-1;
    if(this!=NULL && lastName!=NULL)
    {
        strncpy(this->lastName,lastName,sizeof(this->lastName));
        retorno=0;
    }
    return retorno;
}

int cliente_getLastName(Cliente*this,char*lastName)
{
    int retorno=-1;
    if(this!=NULL)
    {
        strncpy(lastName,this->lastName,sizeof(this->lastName));
        retorno=0;
    }
    return retorno;
}

int cliente_setClienteId(Cliente* this,int clienteId)
{
    int retorno=-1;
    if(clienteId>-1)
    {
        this->clienteId=clienteId;
        retorno=0;
    }
    return retorno;
}

int cliente_getClienteId(Cliente* this,int* clienteId)
{
    int retorno=-1;
    if(this!=NULL)
    {
       *clienteId=this->clienteId;
        retorno=0;
    }
    return retorno;
}

int cliente_findEmptyPlace(Cliente* array[],int len)
{
    int retorno=-1;
    int i;
    if(array!=NULL)
    {
        for(i=0;i<len;i++)
        {
            if(array[i]==NULL)
            {
                retorno=i;
                break;
            }
        }
    }

    return retorno;
}

int cliente_init(Cliente* array[],int len)
{
    int retorno=-1;
    int i;
    if(array!=NULL)
    {
        for(i=0;i<len;i++)
        {
            array[i]=NULL;
            retorno=0;
        }
    }

    return retorno;
}

int cliente_findById(Cliente* array[],int len,int clienteId)
{
    int retorno=-1;
    int i;
    Cliente* aux;
    for(i=0;i<len;i++)
    {
        aux=array[i];
        if(aux!=NULL && aux->clienteId==clienteId)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}

int cliente_delete(Cliente*this)
{
    int retorno=-1;
    if(this!=NULL)
    {
        free((void*)this);
        retorno=0;
    }
    return retorno;
}

Cliente* cliente_newParametros(char* name,char* lastName,int clienteId)
{
    Cliente* aux;
    aux=cliente_new();
    if(aux!=NULL)
    {
        if(cliente_setName(aux,name)==-1 ||
            cliente_setLastName(aux,lastName)==-1 ||
            cliente_setClienteId(aux,clienteId)==-1)
        {
            cliente_delete(aux);
            aux=NULL;
        }
    }
    return aux;
}
