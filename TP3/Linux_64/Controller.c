#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno=0;
    FILE* pArchivoEmployee;
    pArchivoEmployee=fopen(path,"r");
    if(parser_EmployeeFromText(pArchivoEmployee,pArrayListEmployee))
    {
        retorno=1;
    }
    else
    {
        printf("Error de Archivo");
    }
    fclose(pArchivoEmployee);

    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno=0;
    FILE* pArchivoEmployee;
    pArchivoEmployee=fopen(path,"r");
    if(parser_EmployeeFromBinary(pArchivoEmployee,pArrayListEmployee))
    {
        retorno=1;
    }
    else
    {
        printf("Error de Archivo");
    }
    fclose(pArchivoEmployee);

    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=0;
    char auxNombre[50];
    int auxHorasTrabajadas;
    int auxSueldo;
    Employee *pEmpleado;
    pEmpleado=Employee_new();
    if(pEmpleado!=NULL)
    {
        if(!utn_getEntero(&auxSueldo,1,"Ingrese Sueldo: ","Error de Sueldo",0,100000) &&
           !utn_getLetras(auxNombre,30,1,"Ingrese Nombre: ","Error de Nombre") &&
           !utn_getEntero(&auxHorasTrabajadas,1,"Ingrese Horas Trabajadas: ","Error de Horas",0,10000))
        {
            if(!Employee_setSueldo(pEmpleado,auxSueldo) &&
               !Employee_setHorasTrabajadas(pEmpleado,auxHorasTrabajadas) &&
               !Employee_setNombre(pEmpleado,auxNombre) &&
               !Employee_setId(pEmpleado,-1))
            {
                ll_add(pArrayListEmployee,pEmpleado);
                retorno=1;
            }
        }
    }
    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    FILE *pArchivo=fopen(path,"w");
    Employee *pEmpleado;
    int i;
    char auxNombre[50];
    int auxHoras;
    int auxId;
    int auxSueldo;
    int lenArray=ll_len(pArrayListEmployee);
    if(pArchivo!=NULL)
    {
        for(i=0;i<lenArray;i++)
        {
            pEmpleado=(Employee*)ll_get(pArrayListEmployee,i);
            Employee_getId(pEmpleado,&auxId);
            Employee_getNombre(pEmpleado,auxNombre);
            Employee_getHorasTrabajadas(pEmpleado,&auxHoras);
            Employee_getSueldo(pEmpleado,&auxSueldo);

            fprintf(pArchivo,"%d,%s,%d,%d\n",auxId,auxNombre,auxHoras,auxSueldo);
        }
    }
    fclose(pArchivo);
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE *pArchivo=fopen(path,"wb");
    Employee *pEmpleado;
    int i;
    int lenArray=ll_len(pArrayListEmployee);
    if(pArchivo!=NULL)
    {
        for(i=0;i<lenArray;i++)
        {
            pEmpleado=(Employee*)ll_get(pArrayListEmployee,i);
            fwrite(pEmpleado,sizeof(Employee),1,pArchivo);
        }
    }
    fclose(pArchivo);
    return 1;
}

