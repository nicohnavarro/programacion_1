#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#define QTY_CLIENTES 10
typedef struct
{
    char name[50];
    char lastName[50];
    char cuit[14];
    int isEmpty;
    int id;
}Cliente;

int cliente_init(Cliente* cliente,int lengthCliente,int value);
int cliente_getFreePlace(Cliente* cliente,int lengthCliente);
int cliente_alta(Cliente* cliente,int lengthCliente,int index);
int cliente_getClienteById(Cliente* cliente,int lengthCliente,int id);
int cliente_baja(Cliente* cliente,int lengthCliente,int index);
int cliente_modificar(Cliente* cliente,int lengthCliente,int index);
int cliente_set(Cliente* cliente,int lengthCliente,int index,char*nombre,char*apellido,char*cuit);
int cliente_ImprimirCliente(Cliente* cliente,int lengthCliente,int index);
#endif // CLIENTE_H_INCLUDED