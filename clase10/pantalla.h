#ifndef PANTALLA_H_INCLUDED
#define PANTALLA_H_INCLUDED
#define QTY_PANTALLAS 5
#include"pantalla.h"

typedef struct {
    int id;
    int tipo;
    char nombre[32];
    char direccion[35];
    float precio;
    int isEmpty;
}Pantalla;
int setPantalla(Pantalla* pp,int length,int tipo,char* nombre,char* direccion,float precio);
int arrayInit(Pantalla* pp,int length,int valor);
int altaPantalla(Pantalla*pp,int length,int valor);
int getIndiceVacio(Pantalla* pp,int length);
int buscarPorId(Pantalla* pp,int length,int idPantalla);
int modificarPantalla(Pantalla* pp,int length,int index);
int darBajaPantalla(Pantalla*pp,int length,int index);
int listarPantallas(Pantalla*pp,int length);
int imprimirPantallas(Pantalla*pp,int index);



#endif // PANTALLA_H_INCLUDED
