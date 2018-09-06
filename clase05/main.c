#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#define QTY_EMPLEADOS 5
int mostrarArray(int* pArray,int limite);
int initArray(int* pArray,int limite,int valor);
int calcularMaximo(int* pArray,int limite,int*pMaximo);

int main()
{
    int edades[QTY_EMPLEADOS];
    int i;
    int maximo;

    for (i=0;i<QTY_EMPLEADOS;i++)
    {
        if(utn_getEntero(&edades[i],2,"Ingresa edad: ","Error\n",0,120))
        //&edades[i] => (edades+i)
        {
          edades[i]=-1;
        }
    }
    //initArray(edades,QTY_EMPLEADOS,-1);
    mostrarArray(edades,QTY_EMPLEADOS);
    printf("\n");
    //mostrarArray(edades+2,QTY_EMPLEADOS-2);
    calcularMaximo(edades,QTY_EMPLEADOS,&maximo);
    printf("el maximo es: %d",maximo);


    return 0;
}

int mostrarArray(int* pArray,int limite) //pArray[]
{
    int i;
    for(i=0;i<limite;i++)
    {
        printf("el empleado %d \t tiene la edad: %d -- %p \n",i,pArray[i],pArray+i);//*pArray+i -- &pArray[i]
    }
    return 0;
}

int calcularMaximo(int* pArray,int limite,int*pMaximo) //pArray!=NULL && limite>0
{
    int i;
    int auxMaximo;
    int flag=0;
    for(i=0;i<limite;i++)
    {
        if(flag==0)
        {
            auxMaximo=pArray[i];
            flag=1;
        }
        else if (pArray[i]>auxMaximo)
        {
            auxMaximo=pArray[i];
        }

    }
    *pMaximo=auxMaximo;
    return 0;
}

int initArray(int* pArray,int limite,int valor)
{
    int retorno=-1;
    int i;
    if(pArray!=NULL && limite>0)
    {
        for(i=0;i<limite;i++)
        {
            pArray[i]=valor;
            //*(pArray+1)=valor;
        }
        retorno=0;
    }



    return retorno;
}
