#include <stdio.h>
#include <stdlib.h>
#include "Venta.h"
#include "LinkedList.h"
#include"generadorInformes.h"

int generarInformes (char* fileName,LinkedList* listaVentas)
{
    int retorno=-1;
    FILE* pFile;
    pFile=fopen(fileName,"w");
    int unidadesVendidas;
    int ventasMayores1;
    int ventasMayores2;
    int tvVendidas;
    if(pFile !=NULL)
    {
        retorno=0;
        unidadesVendidas=ll_contadorUnidades(listaVentas,venta_cantidadVendidas);
        ventasMayores1=ll_count(listaVentas,venta_mayores1);
        ventasMayores2=ll_count(listaVentas,venta_mayores2);
        tvVendidas=ll_count(listaVentas,venta_cantidadTv);
        fprintf(pFile,"********************\n");
        fprintf(pFile,"Informe de Ventas\n");
        fprintf(pFile,"********************\n");
        fprintf(pFile,"- Cantidad de Unidades Vendidas totales: %d\n",unidadesVendidas);
        fprintf(pFile,"- Cantidad de ventas por un monton mayor a $10000 : %d\n",ventasMayores1);
        fprintf(pFile,"- Cantidad de ventas por un monton mayor a $20000 : %d\n",ventasMayores2);
        fprintf(pFile,"- Cantidad de TVs LCD Vendidas: %d\n",tvVendidas);

    }
    fclose(pFile);
    return retorno;
}
