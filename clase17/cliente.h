#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
typedef struct
{
    char name [32];
    char lastName[32];
    int clienteId;
}Cliente;

Cliente* cliente_new(void);
int cliente_setName(Cliente* this,char* name);
int cliente_getName(Cliente*this,char*name);
int cliente_setLastName(Cliente* this,char* lastName);
int cliente_getLastName(Cliente*this,char*lastName);
int cliente_setClienteId(Cliente* this,int clienteId);
int cliente_getClienteId(Cliente* this,int* clienteId);
int cliente_findEmptyPlace(Cliente* array[],int len);
int cliente_init(Cliente* array[],int len);
int cliente_findById(Cliente* array[],int len,int clienteId);
Cliente* cliente_newParametros(char* name,char* lastName,int clienteId);
#endif // CLIENTE_H_INCLUDED
