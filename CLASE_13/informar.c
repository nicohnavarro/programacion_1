#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Contratacion.h"
#include "utn.h"
#include "pantalla.h"
int informar_ListarPantallas(Pantalla* array,int limitePantalla,int orden)
{
    int retorno = -1;
    int i;
    int flagSwap;
    Pantalla auxiliarEstructura;

    if(limitePantalla > 0 && array != NULL)
    {
        do
        {
            flagSwap = 0;
            for(i=0;i<limitePantalla-1;i++)
            {
                if(!array[i].isEmpty && !array[i+1].isEmpty)
                {
                    if((array[i].precio<array[i+1].precio && orden) || (array[i].precio>array[i+1].precio && !orden)) //******
                    {
                        auxiliarEstructura = array[i];
                        array[i] = array[i+1];
                        array[i+1] = auxiliarEstructura;
                        flagSwap = 1;
                        retorno=0;
                    }
                    else if(array[i].precio==array[i+1].precio)
                    {
                        if((strcmp(array[i].nombre,array[i+1].nombre) > 0 && orden) || (strcmp(array[i].nombre,array[i+1].nombre) < 0 && !orden))
                        {
                            auxiliarEstructura = array[i];
                            array[i] = array[i+1];
                            array[i+1] = auxiliarEstructura;
                            flagSwap = 1;
                            retorno=0;
                        }
                    }
                }
            }
        }while(flagSwap);
    }
    return retorno;
}

int informarPantallasPorPrecio(Pantalla* panta,int lengthPantalla,float precio,int orden)
{
    int retorno=-1;
    int i;
    int flag=1;

    if(lengthPantalla > 0 && panta != NULL)
    {
        for (i=0;i<lengthPantalla-1;i++)
        {
            if(panta[i].isEmpty==0)
            {
                if((panta[i].precio<=precio && orden) || (panta[i].precio>precio && !orden))
                {
                    printf("ID[%d]- precio[%.2f] \n",panta[i].idPantalla,panta[i].precio);
                    retorno=0;
                    flag=0;
                }
            }
        }
        if(flag==1)
        {
            printf("No hay pantalla existentes para lo que se pide");
        }
    }
    return retorno;
}

float informarCalcularPromedio(Pantalla* panta,int lengthPantalla)
{
    //int retorno=-1;
    int i;
    float sumatoria=0;
    float promedio=0;
    int contador=0;
    if(lengthPantalla>0 && panta!=NULL)
    {
        for(i=0;i<lengthPantalla;i++)
        {
            if(panta[i].isEmpty==0)
            {
                contador++;
                sumatoria+=panta[i].precio;
            }
        }
        promedio=sumatoria/contador;
    }
    return promedio;

}

int informarContratacionPorDias(Contratacion* contra,int lengthContra,Pantalla* panta,int lengthPanta)
{
    int retorno=-1;
    return retorno;
}



int informar_ConsultaFacturacion(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas, char* cuit)
{
    int retorno = -1;

    return retorno;
}





int informar_ListarContrataciones(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas)
{
    int retorno = -1;

    return retorno;
}


int informar_ListarCantidadContratacionesImporte(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas)
{
    int retorno = -1;

    return retorno;
}

int informarRepeticionCuit(Contratacion*contra,int lengthContra,char* cuit)
{
    int i;
    int contadorRep=0;
    for (i=0;i<lengthContra;i++)
    {
        if(strcmp(cuit,contra[i].cuit)==0)
        {
            contadorRep++;
        }
    }
    return contadorRep;
}


int informarClientes(/*Cliente* client,int lengthCliente, */Contratacion* contra,int lengthContra, Pantalla* panta,int lengthPanta)
{
    int retorno=-1;
    int i;
    for(i=0;i<lengthContra;i++)
    {
        if(contra[i].isEmpty==0 && (informarRepeticionCuit(contra,lengthContra,contra[i].cuit)>=1))
        {
            printf("CUIT[%s]\n",contra[i].cuit);
            retorno=0;
        }
    }
    return retorno;
}
