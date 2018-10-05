#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED

typedef struct
{
    int idCliente;
    int cantidadAfiches;
    char nombre[50];
    int zona;
    int id;
    int isEmpty;
    int estado;
}Ventas;

int ventas_init(Ventas* ventas,int lengthVentas,int value);
int ventas_getFreePlace(Ventas* ventas,int lengthVentas);
int ventas_venderAfiche(Ventas* ventas,int lengthVentas,int idCliente,Cliente* cliente,int lengthCliente);
int ventas_imprimirVentas(Ventas* ventas,int lengthVentas);
int ventas_set(Ventas* ventas,int index,int lengthVentas,char* nombre,int cantidadAfiches,int idCliente,int zona,int estado);
int ventas_editar(Ventas* ventas,int lengthVentas,int idVenta);
int venta_getVentaById(Ventas* ventas,int lengthVentas,int id);
int ventas_cobrarVentas(Ventas* ventas,int lengthVentas,Cliente* cliente,int lengthClientes,int idVenta);


#endif // VENTAS_H_INCLUDED
