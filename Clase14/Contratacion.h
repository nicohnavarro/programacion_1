#ifndef CONTRATACION_H_INCLUDED
#define CONTRATACION_H_INCLUDED
typedef struct
{
    char cuit[50];
    int idPantalla;
    int dias;
    char archivo[50];
    //------------
    int id;
    int isEmpty;
}Contratacion;

#include "pantalla.h"


int cont_init(Contratacion* array,int limite);
int cont_mostrar(Contratacion* array,int limite);
int cont_mostrarDebug(Contratacion* array,int limite);

int cont_alta(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas);

int cont_baja(Contratacion* array,int limite, int id);
int cont_modificacion(Contratacion* array,int limite, int id);
int cont_ordenar(Contratacion* array,int limite, int orden);
int cont_ordenarCuit(Contratacion* array,int limite, int orden);
//int buscarLugarLibre(Pantalla* array,int limite);
//int proximoId();
//int pantalla_buscarPorId(Pantalla* array,int limite, int id);


int cont_altaForzada(Contratacion* arrayC,int limite,Pantalla* pantallas, int lenPantallas,int idPantalla,char* archivo,char* cuit,int dias);

#endif // PANTALLA_H_INCLUDED


