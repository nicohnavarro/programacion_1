#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

typedef struct {
    int id;
    char name [128];
    int horasTrabajadas;
    int salario;
}Empleado;

Empleado* Empleado_new();
void Empleado_delete();
Empleado* Empleado_newConParametros(char* id,char* name ,char* horasTrabajadas,char* salario);

int Empleado_setId(Empleado* this,int id);
int Empleado_getId(Empleado* this,int* id);

int Empleado_setName (Empleado* this,char* name );
int Empleado_getName (Empleado* this,char* name );

int Empleado_setHorasTrabajadas(Empleado* this,int horasTrabajadas);
int Empleado_getHorasTrabajadas(Empleado* this,int* horasTrabajadas);

int Empleado_setSalario(Empleado* this,int salario);
int Empleado_getSalario(Empleado* this,int* salario);

int em_calcularSueldo(void* pEmpleado);
#endif // EMPLEADO_H_INCLUDED
