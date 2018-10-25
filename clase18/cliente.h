#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct
{
    char idCliente[1024];
    char name[1024];
    char lastName[1024];
}Cliente;


Cliente* cliente_new();
void cliente_delete();
Cliente* cliente_newConParametros(char* idCliente,char* name,char* lastName);

int cliente_setIdCliente(Cliente* this,char* idCliente);
int cliente_getIdCliente(Cliente* this,char* idCliente);

int cliente_setName(Cliente* this,char* name);
int cliente_getName(Cliente* this,char* name);

int cliente_setLastName(Cliente* this,char* lastName);
int cliente_getLastName(Cliente* this,char* lastName);

#endif // CLIENTE_H_INCLUDED
