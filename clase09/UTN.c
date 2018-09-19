#include "UTN.h"
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

static int getFloat(float*pBuffer);
static int getString(char* bufferString,int limite);
static int isFloat(char* pBuffer);
static int getInt(int*pBuffer);
static int isInt(char *pBuffer);
static int isLetras(char*pBuffer);

int utn_getEntero(int* pEntero,int reintentos,char* msg,char*msgError,int min,int max){
    int retorno = -1;
    int buffer;

    if(pEntero!=NULL&& msg !=NULL && msgError!=NULL && min<= max && reintentos>=0){
        do
        {
            reintentos--;
            printf("\n%s: ",msg);
            if(getInt(&buffer) == 0 && buffer >= min && buffer<=max){
                    *pEntero= buffer;
                    retorno = 0;
                    break;
            }else{
                printf("\n%s",msgError);
            }
        }while(reintentos >= 0);
    }
    return retorno;
}
int utn_getFloat(float*pFloat,int reintentos,char* msg,char*msgError,float min,float max){
    int retorno = -1;
    float buffer;

    if(pFloat!=NULL&& msg !=NULL && msgError!=NULL && min<= max && reintentos>=0){
        do
        {
            reintentos--;
            printf("\n%s: ",msg);
            if(getFloat(&buffer) == 0 && buffer >= min && buffer<=max){
                    *pFloat= buffer;
                    retorno = 0;
                    break;
            }else{
                printf("\n%s",msgError);
            }
        }while(reintentos >= 0);
    }
    return retorno;
}
static int getInt(int* pBuffer){
    char bufferString[200];
    int retorno =-1;
    if(getString(bufferString,200)==0 && isInt(bufferString)==0){
        *pBuffer=atoi(bufferString);
        retorno=0;
    }
    return retorno;
}
static int isInt(char *pBuffer){
    int retorno=-1;
    int i=0;
    do{
        if(*(pBuffer+i)<48||*(pBuffer+i)>57){
                break;
        }
        i++;
    }while (i<strlen(pBuffer));
    if(i==strlen(pBuffer)){
        retorno=0;
    }
    return retorno;
}
static int isFloat(char* pBuffer){
    int retorno=-1;
    int i=0;
    int contadorDePuntos=0;
    do{
        if(*(pBuffer+i)==','||*(pBuffer+i)=='.'){
            *(pBuffer+i)='.';
            contadorDePuntos++;
            if(contadorDePuntos==2){
                break;
            }
        }else if(*(pBuffer+i)<48||*(pBuffer+i)>57){
                break;
        }
        i++;
    }while (i<strlen(pBuffer));
    if(i==strlen(pBuffer)){
        retorno=0;
    }
    return retorno;
}
static int getString(char* pBuffer,int limite){
    char bufferString[4096];
    int retorno =-1;
    if (pBuffer != NULL && limite >0){
        __fpurge(stdin);
        fgets(bufferString,sizeof(bufferString),stdin);
        if (bufferString[strlen(bufferString)-1]=='\n'){
            bufferString[strlen(bufferString)-1]='\0';
        }
        if(strlen(bufferString)<= limite){
            strncpy(pBuffer,bufferString,limite);
            retorno=0;
        }
    }
    return retorno;
}
static int getFloat(float*pBuffer){
    char bufferString[200];
    int retorno =-1;
    if(getString(bufferString,200)==0 && isFloat(bufferString)==0){
        *pBuffer=atof(bufferString);
        retorno=0;
    }
    return retorno;
}
int utn_mostrarArray(int * pArray,int limite){
    int i;
    for (i=0;i<limite;i++){
        printf("\n%d",pArray[i]);
    }
    return 0;
}
int utn_calcularNumeroMaximo(int *pArray,int limite,int *maximo){
    int auxMax;
    int i;
    int retorno=-1;
    if(limite>0 && pArray!=NULL){
        retorno=0;
        for (i=0;i<limite;i++){
            if(i==0){
                auxMax=pArray[i];
            }else if(pArray[i]>auxMax){
                auxMax=*(pArray+i);
            }
        }
    }
    *maximo=auxMax;
    return retorno;
}
int utn_initArray(int * pArray,int limite,int valor){
    int i;
    int retorno=-1;
    if(limite>0 && pArray!=NULL){
        retorno=0;
        for (i=0;i<limite;i++){
            *(pArray+i)=valor;
        }
    }
    return retorno;
}
int utn_verificarNumeroEntero(int *pEntero,char* texto,char* textoError){
    int aux;
    printf("%s",texto);
    while(scanf("%d",&aux)==0){
        __fpurge(stdin);
        printf("%s",textoError);
        }
    *pEntero=aux;
    return 0;
}
int utn_verificarNumeroFloat(float *pFloat,char* texto,char* textoError){
    float aux;
    printf("%s",texto);
    while(scanf("%f",&aux)==0){
        __fpurge(stdin);
        printf("%s",textoError);
        }
    *pFloat=aux;
    return 0;
}
int utn_verificarNumeroChar(char *pChar,char* texto,char* textoError){
    char aux;
    printf("%s",texto);
    while(scanf("%c",&aux)==0){
        __fpurge(stdin);
        printf("%s",textoError);
        }
    *pChar=aux;
    return 0;
}
int utn_cargaNumeroAleatoriosEnArrays(int* pArray,int len,int min, int max){
    int i;
    srand(time(NULL));
    for (i=0;i<len;i++){
        pArray[i]= min+1 + rand() % (max+1-min);
    }
    return 0;
}
int utn_promedioArray(int*pArray,int limite,float *promedio,int valorOmision){
    int i;
    int cantidadValorOmision=0;
    int acumulador=0;
    int retorno=-1;

    for (i=0;i<limite;i++){
        if (pArray[i]==valorOmision){
            cantidadValorOmision++;
        }else{
            acumulador+=*(pArray+i);
            retorno=0;
        }
    }
    if(retorno==0){
        *promedio=acumulador/(limite-cantidadValorOmision);
    }
    return retorno;
}
int utn_ordenarArray(int *pArray,int limite,int flagMaxMin){
    int i=0;
    int aux;
    int retorno=-1;
    int flag=1;

    if(pArray!=NULL&&limite>0){
        retorno=0;
        aux=pArray[i];
        while(flag==1){
            flag=0;
            for(i=0;i<(limite-1);i++){
                if( (flagMaxMin==1&& pArray[i]>pArray[i+1]) ||
                    (flagMaxMin==0&&pArray[i]<pArray[i+1]))
                {
                    flag=1;
                    aux=pArray[i];
                    pArray[i]=pArray[i+1];
                    pArray[i+1]=aux;
                }
            }
        }

    }
    return retorno;
}
int utn_getLetras(char *pBuffer,int limite,int reintentos,char* msj,char*msjError){
    int retorno=-1;
    char buffer[limite];
    if(pBuffer!=NULL && limite >0 && reintentos >=0){
        do{
            reintentos--;
            printf("\n%s",msj);
            if(getString(buffer,limite)==0 && isLetras(buffer)==0){
                strncpy(pBuffer,buffer,limite);
                retorno=0;
                break;
            }else
                printf("\n%s",msjError);
        }while(reintentos>=0);
    }
    return retorno;
}
static int isLetras(char*pBuffer){
    int retorno=-1;
    int i=0;
    if(pBuffer!=NULL){
        do{
            if((*(pBuffer+i)<65||*(pBuffer+i)>90) && (*(pBuffer+i)<97||*(pBuffer+i)>122)){
                break;
            }
            i++;
        }while(i<strlen(pBuffer));
        if(i==strlen(pBuffer)){
            retorno=0;
        }
    }
    return retorno;
}
int ordenarInsertion(int* pArray,int limite){
    int i,j;
    int temp;
    for (i=1;i<limite;i++){
        temp=*(pArray+i);
        j=i-1;
        while (j>=0 && temp<*(pArray+j)){
            *(pArray+j+1)=*(pArray+j);
            j--;
        }
        *(pArray+j+1)=temp;
    }
    return 0;
}
int printPersona(Persona *pBuffer){
    printf("\tNombre\taltura\tedad:\n\n");
    printf("\t%s\t%.2f\t%d",pBuffer->nombre,pBuffer->altura,pBuffer->edad);
    return 0;
}
int utn_altaPersona(Persona* pPersona,int reintentos,int lenString,int min,int max){
    utn_getLetras(&pPersona->nombre,lenString,reintentos,"Ingrese el nombre : ","\n***ERROR INTENTE NUEVAMENTE***");
    utn_getEntero(&pPersona->edad,reintentos,"Ingrese la edad: ","Error intente nuevamente : ",min,max);
    utn_getFloat(&pPersona->altura,reintentos,"Ingrese su altura: ","Error amiguito: ",0,3);
    return 0;
}
