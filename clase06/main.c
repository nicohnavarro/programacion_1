#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
int main()
{
    int numero;
    utn_getEntero(&numero,3,"numero?","Error",-10,1000);
    printf("%d",numero);
    printf("Hello world!\n");
    return 0;
}
