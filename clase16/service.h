#ifndef SERVICE_H_INCLUDED
#define SERVICE_H_INCLUDED

typedef struct
{
    int gravedad;
    char mensaje[65];
    int serviceId;
}Service;

Service* service_new();
Service*service_newParametros(int gravedad, char* mensaje,int serviceId);
void service_delete(Service* this);
int service_setGravedad(Service*this,int gravedad);
int service_getGravedad(Service*this,int* gravedad);
int service_setMensaje(Service*this,char* mensaje);
int service_getMensaje(Service*this,char* mensaje);
int service_setServiceId(Service*this,int serviceId);
int service_getServiceId(Service*this,int* serviceId);
void service_print(Service* this);
#endif // SERVICE_H_INCLUDED
