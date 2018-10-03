#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Contratacion.h"
#include "utn.h"
#include "pantalla.h"



//Funciones privadas
static int proximoId(void);
static int buscarPorId(Contratacion* array,int limite, int id);
static int buscarLugarLibre(Contratacion* array,int limite);
//__________________



/** \brief
 * \param array Pantalla*
 * \param limite int
 * \return int
 *
 */
int cont_init(Contratacion* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            array[i].isEmpty=1;
        }
    }
    return retorno;
}

int cont_mostrarDebug(Contratacion* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            //printf("[DEBUG] - %d - %s - %s - %d - %d\n",array[i].id, array[i].cuit,array[i].archivo,array[i].dias, array[i].isEmpty);
        }
    }
    return retorno;
}

int cont_mostrar(Contratacion* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty)
                printf("[RELEASE] - %d - %s - %s - %d - %d\n",array[i].id, array[i].cuit,array[i].archivo,array[i].dias, array[i].isEmpty);
        }
    }
    return retorno;
}

int cont_alta(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas)
{
    int retorno = -1;
    int i;
    int idPant;
    int posPant;
    int diaAux;


    if(limite > 0 && arrayC != NULL)
    {
        i = buscarLugarLibre(arrayC,limite);
        if(i >= 0)
        {
            // alta
            //TODO
            getValidInt("ID?","\nNumero no valido\n",&idPant,0,999999,2);
            posPant = pantalla_buscarPorId(pantallas,lenPantallas,idPant);
            if(posPant>=0)
            {
                // la pantalla existe, idPant es valido
                getValidInt("dias?","\nNumero no valido\n",&diaAux,0,200,2);
                // hacer el resto
                arrayC[i].dias = diaAux;
                //TODO
                arrayC[i].idPantalla = idPant; // relacion
                arrayC[i].isEmpty=0;
                arrayC[i].id = proximoId();

            }
        }
        else
        {
            retorno = -2;
        }

    }
    return retorno;
}


int cont_baja(Contratacion* array,int limite, int id)
{
    int indiceAEliminar;
    int retorno=-1;
    indiceAEliminar = buscarPorId(array,limite,id);
    if(indiceAEliminar>=0)
    {
        array[indiceAEliminar].isEmpty=1;
        retorno=0;
    }
    return retorno;
}


static int buscarLugarLibre(Contratacion* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}



static int proximoId(void)
{
    static int proximoId = -1;
    proximoId++;
    return proximoId;
}


//int pantalla_buscarPorId(Pantalla* array,int limite, int id)
static int buscarPorId(Contratacion* array,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty && array[i].idPantalla==id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int cont_altaForzada(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas,
              int idPantalla,char* archivo,char* cuit,int dias)
{
    int retorno = -1;
    int i;
    int posPant;
    if(limite > 0 && arrayC != NULL)
    {
        i = buscarLugarLibre(arrayC,limite);
        if(i >= 0)
        {

            posPant = pantalla_buscarPorId(pantallas,lenPantallas,idPantalla);
            if(posPant>=0)
            {
                arrayC[i].dias = dias;
                strcpy(arrayC[i].cuit,cuit);
                strcpy(arrayC[i].archivo,archivo);
                //TODO
                arrayC[i].idPantalla = idPantalla; // relacion
                arrayC[i].isEmpty=0;
                arrayC[i].id = proximoId();
            }
        }
        retorno = 0;
    }
    return retorno;
}


int cont_ordenarCuit(Contratacion* array,int limite, int orden)
{
    int retorno = -1;
    int i;
    int flagSwap;
    Contratacion auxiliarEstructura;

    if(limite > 0 && array != NULL)
    {
        do
        {
            flagSwap = 0;
            for(i=0;i<limite-1;i++)
            {
                if(!array[i].isEmpty && !array[i+1].isEmpty)
                {
                    if((strcmp(array[i].cuit,array[i+1].cuit) > 0 && orden) || (strcmp(array[i].cuit,array[i+1].cuit) < 0 && !orden)) //******
                    {
                        auxiliarEstructura = array[i];
                        array[i] = array[i+1];
                        array[i+1] = auxiliarEstructura;
                        flagSwap = 1;
                    }
                }
            }
        }while(flagSwap);
    }
    return retorno;
}








