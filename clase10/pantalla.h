#ifndef PANTALLA_H_INCLUDED
#define PANTALLA_H_INCLUDED
#define QTY_PANTALLAS 100

typedef struct {
    int id;
    int tipo;
    char nombre[32];
    char direccion[35];
    int isEmpty;
}Pantalla;

int arrayInit(Pantalla* pp,int length,int valor);
int altaPantalla(Pantalla*pp,int length,int valor);
int getIndiceVacio(Pantalla* pp,int length);




#endif // PANTALLA_H_INCLUDED
