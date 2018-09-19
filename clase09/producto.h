#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED

typedef struct {
    char nombre[32];
    char descripcion[128];
    float precio;
    int isEmpty;
}Producto;

int arrayInit(Producto* pp,int lenght,int valor);
int altaProducto(Producto* pp,int indice,int lenght);


#endif // PRODUCTO_H_INCLUDED
