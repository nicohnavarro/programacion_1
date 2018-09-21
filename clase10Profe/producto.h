
//Definir un tipo de dato que represente un producto.
//El producto tiene un nombre, una descripcion y un precio
typedef struct
{
    char nombre[50];
    char descripcion[200];
    float precio;
    int idProducto;
    int isEmpty;
}Producto;

int producto_altaProducto(Producto arrayProducto[],int len);
int producto_mostrar(Producto arrayProducto[],int len);
int producto_init(Producto arrayProducto[],int len,int valor);
