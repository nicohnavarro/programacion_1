#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Contratacion.h"
#include "utn.h"
#include "pantalla.h"
#include "informar.h"

/*
G.  Listado de clientes en el cual se indique la cantidad
    de contrataciones que ha realizado y por que importe.
    Ordenado por los siguientes criterios:
        o Importe (descendentemente)
        o Cuit (ascendentemente)
*/

typedef struct
{
    char cuit[50];
    float importe;
    int cantidadCont;
    int isEmpty;
} InfoCliente;

InfoCliente arrayIC[1000];

static int estaCuitEnInfoCliente(InfoCliente arrayInfoC[],int limiteInfoC, char cuit[]);

static void initInfoCliente( Contratacion arrayCont[],int limiteCont,
                            InfoCliente arrayInfoC[],int limiteInfoC)
{
    int i;
    int proximoLibre=0;
    for(i=0;i<limiteInfoC;i++)
    {
        arrayInfoC[i].isEmpty = 1;
    }

    for(i=0;i<limiteCont;i++)
    {
        if(!estaCuitEnInfoCliente(arrayInfoC,limiteInfoC,arrayCont[i].cuit))
        {
            strcpy(arrayInfoC[proximoLibre].cuit,arrayCont[i].cuit);
            arrayInfoC[proximoLibre].isEmpty = 0;
            proximoLibre++;
        }
    }
}

static void cargaInfoCliente( Contratacion arrayCont[],int limiteCont,
                            InfoCliente arrayInfoC[],int limiteInfoC,
                            Pantalla* pantallas, int lenPantallas)
{
    int i,j;
    int qtyContrataciones = 0;
    Pantalla* auxPatalla;

    for(i=0;i<limiteInfoC;i++)
    {
        if(!arrayInfoC[i].isEmpty)
        {
            qtyContrataciones=0;
            arrayInfoC[i].importe = 0;
            for(j=0;j<limiteCont;j++)
            {
                if(!strcmp(arrayInfoC[i].cuit,arrayCont[j].cuit))
                {
                    qtyContrataciones++;
                    auxPatalla = getPantallaById(pantallas,lenPantallas,arrayCont[j].idPantalla);
                    arrayInfoC[i].importe += auxPatalla->precio * arrayCont[j].dias;
                }
            }
            arrayInfoC[i].cantidadCont = qtyContrataciones;
        }
    }
}



static int estaCuitEnInfoCliente(InfoCliente arrayInfoC[],int limiteInfoC, char cuit[])
{
    int i;
    int retorno = 0;
    for(i=0;i<limiteInfoC;i++)
    {
        if(!arrayInfoC[i].isEmpty && !strcmp(arrayInfoC[i].cuit, cuit))
        {
            retorno = 1;
            break;
        }
    }
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

/*
A.  Realizar un solo listado de las pantallas ordenadas
    por los siguientes criterios:
        o Precio (descendentemente)
        o Nombre (ascendentemente)
*/

int informar_listadoPantallas(Pantalla arrayPantallas[],int limiteArrayPantallas)
{
    int retorno = -1;
    if(arrayPantallas != NULL && limiteArrayPantallas > 0)
    {
        pantalla_ordenarPrecioNombre(arrayPantallas,limiteArrayPantallas);
        pantalla_mostrarDebug(arrayPantallas,limiteArrayPantallas);
    }
    return retorno;
}



















