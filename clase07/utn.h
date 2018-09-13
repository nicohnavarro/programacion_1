
#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED
#define QTY_EMPLEADOS 5
int utn_mostrar_array(int* pArray,int limite);
int utn_init_array(int* pArray,int limite,int valor);
int utn_calcular_maximo(int* pArray,int limite,int*pMaximo);
/**
    utn_getEntero : pide un entero al usuario
    @param pEdad: puntero a edad
    @param reIntentos: cantidad de reintentos
    @return : 0 OK, -1 error.
*/
int utn_getEntero(int* pNumero,int intentos,char* msj,char* msjEr,int minimo,int maximo);
int utn_getFloat(float* pNumero,int reintentos,char* pMsj,char* pMsjEr,float minimo,float maximo);
int utn_getChar(char* pCaracter,int intentos,char* pMsj);
int utn_es_numero(char* pArray);
int utn_ordenar_array(int* pArray,int limite,int orden);
void utn_qs(int* pArray,int limite);
void quick_sort(int* pArray, int limite_izq, int limite_der);
#endif // UTN_H_INCLUDED
