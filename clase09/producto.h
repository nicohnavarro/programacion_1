#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED

typedef struct {
    char nombre[32];
    char descripcion[128];
    float precio;
    int isEmpty;
    int id;
}Producto;

int arrayInit(Producto* pp,int lenght,int valor);
int altaProducto(Producto* pp,int indice,int length);
int imprimirProducto(Producto* pp,int indice);
int getIndiceVacio(Producto* pp,int length);
void menuProducto(Producto*pp);
int listarProductos(Producto* pp,int length);
#endif // PRODUCTO_H_INCLUDED
