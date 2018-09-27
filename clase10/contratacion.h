#ifndef CONTRATACION_H_INCLUDED
#define CONTRATACION_H_INCLUDED
#define QTY_CONTRATACION 10

typedef struct {
    int id;
    char video[30];
    int dias;
    int IdPantalla;
    int CuitCliente;
    int isEmpty;
}Contratacion;

int arrayInitContra(Contratacion* contra,int length,int valor);
int getIndiceVacioContra(Contratacion* contra,int length);
int altaContratacion(Contratacion* contra,int lengthContra,int indexContra,int idPantalla);
int printContratacion(Contratacion* contra,int length);
int buscarIdporCuit(Contratacion* contra,int length,int cuit);
#endif // CONTRATACION_H_INCLUDED
