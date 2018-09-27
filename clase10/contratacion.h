#ifndef CONTRATACION_H_INCLUDED
#define CONTRATACION_H_INCLUDED
#define QTY_CONTRATACION 10

typedef struct {
    int id;
    char video[30];
    int dias;
    int IdPantalla;
    char CuitCliente[14];
    int isEmpty;
}Contratacion;

int arrayInitContra(Contratacion* contra,int length,int valor);
int getIndiceVacioContra(Contratacion* contra,int length);
int altaContratacion(Contratacion* contra,int lengthContra,int indexContra,int idPantalla);
int printContratacion(Contratacion* contra,int length);
int modificarContratacion(Contratacion* contra,int lengthContratacion,char* cuit,Pantalla* pp,int lengthPantalla);
int setContratacion(Contratacion* contra,int pos,char*cuit,char*video,int dias,int idPan);
#endif // CONTRATACION_H_INCLUDED
