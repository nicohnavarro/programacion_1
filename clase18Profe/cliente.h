typedef struct
{
    int idCliente;
    char nombre[50];
    char apellido[50];
}Cliente;


Cliente* cliente_new();
void cliente_delete();
Cliente* cliente_newConParametros(char* idCliente,char* nombre,char* apellido);

int cliente_setIdCliente(Cliente* this,int idCliente);
int cliente_getIdCliente(Cliente* this,int* idCliente);

int cliente_setNombre(Cliente* this,char* nombre);
int cliente_getNombre(Cliente* this,char* nombre);

int cliente_setApellido(Cliente* this,char* apellido);
int cliente_getApellido(Cliente* this,char* apellido);
