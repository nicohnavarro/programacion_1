#include "Venta.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
static int isValidId(char* ventaId);
static int isValidFecha_venta(char* fecha);
static int isValidCodigo_producto(char* codigo);
static int isValidCantidad(char* cantidad);
static int isValidPrecioUnitario(char* precioUnitario);
static int isValidCuit_cliente(char* cuit);

Venta* Venta_new()
{
    Venta* this;
    this=malloc(sizeof(Venta));
    return this;
}

void Venta_delete(Venta* this)
{
    free(this);
}

Venta* Venta_newConParametros(char* id_venta,char* fecha_venta,char* codigo_producto ,char* cantidad,char* precio_unitario,char* cuit_cliente )
{
    Venta* this;
    this=Venta_new();

    if(
    !Venta_setId_venta(this,id_venta)&&
    !Venta_setFecha_venta(this,fecha_venta)&&
    !Venta_setCodigo_producto (this,codigo_producto )&&
    !Venta_setCantidad(this,cantidad)&&
    !Venta_setPrecio_unitario(this,precio_unitario)&&
    !Venta_setCuit_cliente (this,cuit_cliente ))
        return this;

    Venta_delete(this);
    return NULL;
}

int Venta_setId_venta(Venta* this,char* id_venta)
{
    int retorno=-1;
    if(this!=NULL && isValidId(id_venta)==0)
    {
        this->id_venta=atoi(id_venta);
        retorno=0;
    }
    return retorno;
}

int Venta_getId_venta(Venta* this,int* id_venta)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id_venta=this->id_venta;
        retorno=0;
    }
    return retorno;
}

static int isValidId(char* ventaId)
{
    int i=0;
    int retorno=0;
    int contadorDeGuiones=0;
    while(ventaId[i] != '\0')
    {
        if(ventaId[i] == '-' && contadorDeGuiones==0)
        {
            contadorDeGuiones++;
            i++;
            continue;
        }
        if(ventaId[i] < '0' || ventaId[i] > '9')
        {
            retorno=-1;
            break;
        }
        i++;
    }
    return retorno;
}

int Venta_setFecha_venta(Venta* this,char* fecha_venta)
{
    int retorno=-1;
    if(this!=NULL && fecha_venta!=NULL && isValidFecha_venta(fecha_venta)==0)
    {
        strcpy(this->fecha_venta,fecha_venta);
        retorno=0;
    }
    return retorno;
}

int Venta_getFecha_venta(Venta* this,char* fecha_venta)
{
    int retorno=-1;
    if(this!=NULL && fecha_venta!=NULL)
    {
        strcpy(fecha_venta,this->fecha_venta);
        retorno=0;
    }
    return retorno;
}

static int isValidFecha_venta(char* fecha)
{
     int i=0;
    int retorno=0;
    int contadorDeGuiones=0;
    while(fecha[i] != '\0')
    {
        if(fecha[i] == '/' && contadorDeGuiones<2)
        {
            contadorDeGuiones++;
            i++;
            continue;
        }
        if(fecha[i] < '0' || fecha[i] > '9')
        {
            retorno=-1;
            break;
        }
        i++;
    }
    return retorno;

}

int Venta_setCodigo_producto (Venta* this,char* codigo_producto)
{
    int retorno=-1;
    if(this!=NULL && codigo_producto !=NULL && isValidCodigo_producto(codigo_producto)==0)
    {
        strcpy(this->codigo_producto ,codigo_producto );
        retorno=0;
    }
    return retorno;
}

int Venta_getCodigo_producto (Venta* this,char* codigo_producto )
{
    int retorno=-1;
    if(this!=NULL && codigo_producto !=NULL)
    {
        strcpy(codigo_producto ,this->codigo_producto );
        retorno=0;
    }
    return retorno;
}

static int isValidCodigo_producto(char* codigo)
{
    int i=0;
    int retorno=0;
    int contadorDeGuiones=0;
    while(codigo[i] != '\0')
    {
        codigo[i]=toupper(codigo[i]);
        if(codigo[i] == '_' && contadorDeGuiones<=1)
        {
            contadorDeGuiones++;
            i++;
            continue;
        }
        i++;
    }
    return retorno;
}

int Venta_setCantidad(Venta* this,char* cantidad)
{
    int retorno=-1;
    if(this!=NULL && isValidCantidad(cantidad)==0)
    {
        this->cantidad=atoi(cantidad);
        retorno=0;
    }
    return retorno;
}

int Venta_getUnidades(Venta* this,int* cantidad)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *cantidad=this->cantidad;
        retorno=0;
    }
    return retorno;
}

static int isValidCantidad(char* cantidad)
{
    int i=0;
    int retorno=0;
    while(cantidad[i] != '\0')
    {
        if(cantidad[i] < '0' || cantidad[i] > '9')
        {
            retorno=-1;
            break;
        }
        i++;
    }
    return retorno;
}

int Venta_setPrecio_unitario(Venta* this,char* precio_unitario)
{
    int retorno=-1;
    if(this!=NULL && isValidPrecioUnitario(precio_unitario)==0)
    {
        this->precio_unitario=atof(precio_unitario);
        retorno=0;
    }
    return retorno;
}

int Venta_getPrecio_unitario(Venta* this,float* precio_unitario)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *precio_unitario=this->precio_unitario;
        retorno=0;
    }
    return retorno;
}

static int isValidPrecioUnitario(char* precioUnitario)
{
    int i=0;
    int retorno=0;
    int contadorDePuntos=0;
    while(precioUnitario[i] != '\0')
    {
        if(precioUnitario[i] == '.' && contadorDePuntos==0)
        {
            contadorDePuntos++;
            i++;
            continue;
        }
        if(precioUnitario[i] < '0' || precioUnitario[i] > '9')
        {
            retorno=-1;
            break;
        }
        i++;
    }
    return retorno;
}

int Venta_setCuit_cliente (Venta* this,char* cuit_cliente )
{
    int retorno=-1;
    if(this!=NULL && cuit_cliente !=NULL && isValidCuit_cliente(cuit_cliente)==0)
    {
        strcpy(this->cuit_cliente ,cuit_cliente );
        retorno=0;
    }
    return retorno;
}

int Venta_getCuit_cliente (Venta* this,char* cuit_cliente )
{
    int retorno=-1;
    if(this!=NULL && cuit_cliente !=NULL)
    {
        strcpy(cuit_cliente ,this->cuit_cliente );
        retorno=0;
    }
    return retorno;
}

static int isValidCuit_cliente(char* cuit)
{
       int i=0;
    int retorno=0;
    int contadorDeGuiones=0;
    while(cuit[i] != '\0')
    {
        if(cuit[i] == '-' && contadorDeGuiones<=1)
        {
            contadorDeGuiones++;
            i++;
            continue;
        }
        if(cuit[i] < '0' || cuit[i] > '9')
        {
            retorno=-1;
            break;
        }
        i++;
    }
    return retorno;
}

int venta_cantidadVendidas(void* element)
{
    Venta* auxVenta;
    int auxCantidad;
    auxVenta=(Venta*)element;
    if(auxVenta!=NULL)
    {
        auxCantidad=auxVenta->cantidad;
    }
    return auxCantidad;
}

int venta_cantidadTv(void* element)
{
    Venta* auxVenta;
    int retorno=0;
    auxVenta=(Venta*)element;
    char auxCodigo[20];
    if(auxVenta!=NULL)
    {
        Venta_getCodigo_producto(auxVenta,auxCodigo);
        if(strcmp(auxCodigo,"LCD_TV")==0)
        {
            retorno=1;
        }
    }
    return retorno;
}

int venta_mayores1(void* element)
{
    Venta* auxVenta;
    int retorno=0;
    auxVenta=(Venta*)element;
    float precio;
    if(auxVenta!=NULL)
    {
        Venta_getPrecio_unitario(auxVenta,&precio);
        if(precio>10000)
        {
            retorno=1;
        }
    }
    return retorno;
}

int venta_mayores2(void* element)
{
    Venta* auxVenta;
    int retorno=0;
    auxVenta=(Venta*)element;
    float precio;
    if(auxVenta!=NULL)
    {
        Venta_getPrecio_unitario(auxVenta,&precio);
        if(precio>20000)
        {
            retorno=1;
        }
    }
    return retorno;
}
