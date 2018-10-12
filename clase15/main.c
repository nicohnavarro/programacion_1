/*
Punteros : direccion de memoria a un dato, a una funcion a otro puntero

Que pasa en la memoria:
Hay direcciones y hay valores
Impirmir direccion de memoria con el & en el print (%p)
Cuanto ocupa es un tema de arquitectura siempre el sizeof(int)
en C 4bites
En un String el puntero es el nombre del string
Operador de indireccion *:
aceder al Valor de esa direccion de memoria

Declaracion de punteros
tipo de dato = para saber cuanto se tiene que desplazar en la memoria
guardan la direccion de memoria de una &variable
Asignar a NULL
Operador de direccion &

Puntero Generico
Tipo void----> Pierdo la magia de algebra de punteros

*(arrayChar+4)='#'

(array+i)->campo1
*(array+i).campo1
array[i].campo1


MEMORIA DINAMICA

malloc
realloc
free

-Heap : esas 3 funciones manejar la memoria en el Heap
-Segmento codigo se carga todo el programa en RAM variable Globales
-Segmento pila Stack

MALLOC
Devuelve un puntero a void
guarda un Bloque de bytes
sizeof(tipodeDato)*cantidad a guardar
el espacio que nos consigue es contiguo
Devuelve NULL si no consigue la memoria que pediste
-Desfragmentar la RAM Las aplicaciones no lo tienen

recibo un puntero a int y hago un casting
int* a;
a=(int*)malloc (sizeof(int))
if(a!=NULL)
*a=22;

REALLOC
Dame el puntero resta 1 lee lo que dejo MALLOC
Se encarga de copiar lo que tenias reservado porque no sabe que es
Devuelve NULL y no rompe el original
Ya LLama el free

int*a;
int*pAux;
a=(int*)malloc(sizeof(int)*20)

pAux=(int*)realloc(a,sizeof(int)*200);

if(pAux!=NULL)
a=pAux;

FREE

Si puede libera el espacio sino no!
int*a;
int *pAux;
a=(int*)malloc(sizeof(int)*20);

free(a);
*/

#include <stdio.h>
#include <stdlib.h>
#define QTY_ARRAY 10
int* new_array(int size); // Constructor
int init_array(int* arrayInt,int limite,int valor);
int show_array(int* arrayInt,int limite);
int delete_array(int* arrayInt);// Destructor

int main()
{
    /*int* a=NULL;
    int i;

    a=(int*)malloc(sizeof(int)*QTY_ARRAY);

    for(i=0;i<QTY_ARRAY;i++)
    {
        if(a!=NULL)
    {
        *(a+i)=i;
    }
        printf("%i\t",*(a+i));
        printf("%p\t",(a+i));
        printf("%p\n",&a);

    }
    free(a);*/

    int* arrayEnteros=NULL;
    arrayEnteros=new_array(100);
    init_array(arrayEnteros,100,1024);
    show_array(arrayEnteros,100);
    delete_array(arrayEnteros);


    return 0;
}


int* new_array(int size) //Constructor
{
    int* ret=NULL;
    int* arrayIntAux=NULL;
    if(size>0)
    {
        arrayIntAux=(int*)malloc(sizeof(int)*size);
        if(arrayIntAux!=NULL)
        {
            ret=arrayIntAux;
        }
    }
    return ret;
}


int init_array(int* arrayInt,int limite,int valor)
{
    int ret=-1;
    int i;
    if(arrayInt!=NULL && limite>0)
    {
        for(i=0;i<limite;i++)
        {
            *(arrayInt+i)=valor;
        }
        ret=0;
    }
    return ret;
}
int show_array(int* arrayInt,int limite)
{
    int ret=-1;
    int i;
    printf("\n----> i %p\n",&i);
    if(arrayInt!=NULL && limite>0)
    {
        for(i=0;i<limite;i++)
        {
            printf("%p - [%d] - %d\n",(arrayInt+i),i,*(arrayInt+i));
        }
        ret=0;
    }
    return ret;
}
int delete_array(int* arrayInt) //Destructor
{
    int ret=-1;
    if(arrayInt!=NULL)
    {
        free(arrayInt);
        ret=0;
    }
    return ret;
}
