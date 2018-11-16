#ifndef COMPRA_H_INCLUDED
#define COMPRA_H_INCLUDED

struct S_Compra
{
  char nombreCliente[128];
  int idProducto;
  float precioUnitario;
  int unidades;
  float iva;
  float montoTotal;
};
typedef struct S_Compra Compra;

void com_calcularMonto(void* p);

#endif // COMPRA_H_INCLUDED
