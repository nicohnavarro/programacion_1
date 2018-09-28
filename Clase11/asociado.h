#ifndef ASOCIADO_H_INCLUDED
#define ASOCIADO_H_INCLUDED
#define QTY_ASOCIADOS 6
typedef struct{
    int id;
    char name[50];
    char lastName[50];
    char dni[8];
    int age;
    int isEmpty;
}Asociado;

int asociado_init(Asociado* aso,int lengthAsociado,int value);
int asociado_set(Asociado* aso,int lengthAsociado,int index,char* name,char* lastName,char* dni,int age);
int asociado_getFreePlace(Asociado* aso,int lengthAsociado);
int asociado_alta(Asociado* aso,int lengthAsociado,int index);


#endif // ASOCIADO_H_INCLUDED
