#ifndef ASOCIADO_H_INCLUDED
#define ASOCIADO_H_INCLUDED
#include "asociado.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include"utn.h"
#define QTY_ASOCIADOS 6
typedef struct{
    int id;
    char name[51];
    char lastName[51];
    char dni[8];
    int age;
    int isEmpty;
}Asociado;

int asociado_init(Asociado* aso,int lengthAsociado,int value);
int asociado_set(Asociado* aso,int lengthAsociado,int index,char* name,char* lastName,char* dni,int age);
int asociado_getFreePlace(Asociado* aso,int lengthAsociado);
int asociado_alta(Asociado* aso,int lengthAsociado,int index);


#endif // ASOCIADO_H_INCLUDED
