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
int printContratacion(Contratacion*contra,int lengthContra,Pantalla* pp,int lengthPantalla);
int modificarContratacion(Contratacion* contra,int lengthContratacion,char* cuit,Pantalla* pp,int lengthPantalla);
int buscarPosicionPorCuit(Contratacion*contra,int lengthContratacion,char*cuit,int idPantalla);
int modificarDiasContratacion(Contratacion*contra,int lengthContratatacion,int pos);
int setContratacion(Contratacion* contra,int pos,char*cuit,char*video,int dias,int idPan);
int cancelarContratacion(Contratacion* contra,int lengthContratacion,int idPantalla);
int consultarFacturacion(Contratacion* contra,int lengthContratacion,char* cuit,Pantalla*pp,int lengthPantalla);
int listarClientes(Contratacion* contra,Pantalla* pp,int lengthContra,int lengthPantalla);
#endif // CONTRATACION_H_INCLUDED
