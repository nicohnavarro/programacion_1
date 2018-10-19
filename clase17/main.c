#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "string.h"
#define CLIENTES 100
int main()
{
    char nombreAux[50];
    Cliente* aux;
    Cliente* arrayClientes[CLIENTES];
    cliente_init(arrayClientes,CLIENTES);
    int indexEmpty;
    indexEmpty=cliente_findEmptyPlace(arrayClientes,CLIENTES);
    //ALTA
    aux=cliente_new();
    if(aux!=NULL && indexEmpty>=0)
    {
        cliente_setName(aux,"Nicolas");
        arrayClientes[indexEmpty]=aux;
        printf("NOMBRE: %s\n",aux->name);
        cliente_getName(aux,nombreAux);
        printf("NOMBRE AUX: %s\n",nombreAux);
    }
    return 0;
}
