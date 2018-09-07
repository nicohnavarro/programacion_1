#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

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

#endif // UTN_H_INCLUDED
