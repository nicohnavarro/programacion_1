#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
//typedef int Persona;
/*struct S_Persona
{
    char nombre[70];
    int edad;
    char dni[20];
    float altura;
};
typedef struct S_Persona Persona;*/

typedef struct
{
    char nombre[70];
    int edad;
    char dni[20];
    float altura;
}Persona;
int altaPersona(Persona* pp);
void printPersona(Persona* p);


int main()
{
    Persona p;//{juan}
    p.edad=33;
    p.altura=1.82;
    //p.nombre="juan"; **NO
    strncpy(p.nombre,"juan",70);
    //fgets(p.nombre,70,stdin);
    //struct S_Persona p;
    //printf("La edad es: %d",p.edad);
    //printPersona(&p);
    //printf("La edad es: %d",p.edad);
    altaPersona(&p);
    printPersona(&p);

    /*int edades[5];
    int i;
    int k=6;
    for(i=0;i<5;i++)
    {
        edades[i]=k++;
        k=+i;
        printf("%d\n",edades[i]);
    }
    printf("Hello world!\n");

    insertion(edades,5);
    utn_mostrar_array(edades,5);*/



    return 0;
}

int altaPersona(Persona* pp)
{
    pp->edad=getInt("Ingrese edad:\n");
    pp->altura=getFloat("Ingrese altura\n");
    getStringLetras("Ingrese nombre\n",pp->nombre);
    printf("\n");
    return 0;
}

void printPersona(Persona* p)
{
    printf("NOMBRE: %s \nANIOS: %d \nALTURA:  %.2f metros",p->nombre,p->edad,p->altura);
}
