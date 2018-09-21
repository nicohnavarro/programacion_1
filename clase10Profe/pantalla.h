#define LCD 1
#define LED 2

typedef struct
{
    char nombre[50];
    char direccion[200];
    float precio;
    int tipo;
    //********************
    int id;
    int isEmpty;
}Pantalla;

int pantalla_init(Pantalla* array, int len);
int pantalla_alta(Pantalla* array, int len);
Pantalla* pantalla_getById(Pantalla* array, int len,int id);
int pantalla_modificar(Pantalla* array, int len);
int pantalla_baja(Pantalla* array, int len);
int pantalla_mostrar(Pantalla* array, int len);
int pantalla_ordenar(Pantalla* array, int len);










