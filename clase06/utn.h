#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED
#define QTY_EMPLEADOS 5
int mostrarArray(int* pArray,int limite);
int initArray(int* pArray,int limite,int valor);
int calcularMaximo(int* pArray,int limite,int*pMaximo);
/**
    utn_getEntero : pide un entero al usuario
    @param pEdad: puntero a edad
    @param reIntentos: cantidad de reintentos
    @return : 0 OK, -1 error.
*/
int utn_getEntero(int* pNumero,int intentos,char* msj,char* msjEr,int minimo,int maximo);
int utn_getDecimal(float* pNumero,int intentos,char* pMsj,char* pMsjEr,int minimo,int maximo);
int utn_getChar(char* pCaracter,int intentos,char* pMsj);
int esNumero(char* pArray);
int ordenarArray(int* pArray,int limite,int orden);
void qs(int* pArray,int limite);
void quick_sort(int* pArray, int limite_izq, int limite_der);
#endif // UTN_H_INCLUDED
