
#include "cliente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static int isValidIdCliente(char* idCliente);
static int isValidName(char* name);
static int isValidLastName(char* lastName);

Cliente* cliente_new()
{
    Cliente* this;
    this=malloc(sizeof(Cliente));
    return this;
}

void cliente_delete(Cliente* this)
{
    free(this);
}

Cliente* cliente_newConParametros(char* idCliente,char* name,char* lastName)
{
    Cliente* this;
    this=cliente_new();

    if(
    !cliente_setIdCliente(this,idCliente)&&
    !cliente_setName(this,name)&&
    !cliente_setLastName(this,lastName))
        return this;

    cliente_delete(this);
    return NULL;
}

int cliente_setIdCliente(Cliente* this,char* idCliente)
{
    int retorno=-1;
    if(this!=NULL && isValidIdCliente(idCliente))
    {
        strcpy(this->idCliente,idCliente);
        retorno=0;
    }
    return retorno;
}

int cliente_getIdCliente(Cliente* this,char* idCliente)
{
    int retorno=-1;
    if(this!=NULL && idCliente!=NULL)
    {
        strcpy(idCliente,this->idCliente);
        retorno=0;
    }
    return retorno;
}

int cliente_setName(Cliente* this,char* name)
{
    int retorno=-1;
    if(this!=NULL && isValidName(name))
    {
        strcpy(this->name,name);
        retorno=0;
    }
    return retorno;
}

int cliente_getName(Cliente* this,char* name)
{
    int retorno=-1;
    if(this!=NULL && name!=NULL)
    {
        strcpy(name,this->name);
        retorno=0;
    }
    return retorno;
}

int cliente_setLastName(Cliente* this,char* lastName)
{
    int retorno=-1;
    if(this!=NULL && isValidLastName(lastName))
    {
        strcpy(this->lastName,lastName);
        retorno=0;
    }
    return retorno;
}

int cliente_getLastName(Cliente* this,char* lastName)
{
    int retorno=-1;
    if(this!=NULL && lastName!=NULL)
    {
        strcpy(lastName,this->lastName);
        retorno=0;
    }
    return retorno;
}

static int isValidIdCliente(char* idCliente)
{
    int retorno=-1;
    if(idCliente!=NULL)
    {
        retorno=0;
    }
    return retorno;
}

static int isValidName(char* name)
{
    int retorno=-1;
    if(name!=NULL)
    {
        retorno=0;
    }
    return retorno;
}

static int isValidLastName(char* lastName)
{
    int retorno=-1;
    if(lastName!=NULL)
    {
        retorno=0;
    }
    return retorno;
}
