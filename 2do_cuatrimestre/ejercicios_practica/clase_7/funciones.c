#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "funciones.h"

int getInt(char mensaje[])
{
    int numero;

    printf("%s:", mensaje);
    scanf("%d",&numero);

    return numero;
}


int esNumero (char auxiliar[])
{
    int i;
    int flag=1;//1 es entero

    for(i=0; i<strlen(auxiliar); i++)
    {
        if(auxiliar[i]<'0' || auxiliar[i]>'9')
        {
            flag=0;
            break;
        }
    }

    return flag;
}
