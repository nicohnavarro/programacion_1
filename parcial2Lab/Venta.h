#ifndef VENTA_H_INCLUDED
#define VENTA_H_INCLUDED

typedef struct
{
    int id_venta;
    char fecha_venta[50];
    char codigo_producto [50];
    int cantidad;
    float precio_unitario;
    char cuit_cliente [20];
}Venta;

Venta* Venta_new();
void Venta_delete();
Venta* Venta_newConParametros(char* id_venta,char* fecha_venta,char* codigo_producto ,char* cantidad,char* precio_unitario,char* cuit_cliente );

int Venta_setId_venta(Venta* this,char* id_venta);
int Venta_getId_venta(Venta* this,int* id_venta);

int Venta_setFecha_venta(Venta* this,char* fecha_venta);
int Venta_getFecha_venta(Venta* this,char* fecha_venta);

int Venta_setCodigo_producto (Venta* this,char* codigo_producto );
int Venta_getCodigo_producto (Venta* this,char* codigo_producto );

int Venta_setCantidad(Venta* this,char* cantidad);
int Venta_getCantidad(Venta* this,int* cantidad);

int Venta_setPrecio_unitario(Venta* this,char* precio_unitario);
int Venta_getPrecio_unitario(Venta* this,float* precio_unitario);

int Venta_setCuit_cliente (Venta* this,char* cuit_cliente );
int Venta_getCuit_cliente (Venta* this,char* cuit_cliente );

int venta_cantidadVendidas(void* element);
int venta_cantidadTv(void* element);
int venta_mayores1(void* element);
int venta_mayores2(void* element);
#endif // VENTA_H_INCLUDED
