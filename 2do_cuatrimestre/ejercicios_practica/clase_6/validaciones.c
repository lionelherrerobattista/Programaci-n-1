#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "validaciones.h"

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

int esLetra(char auxiliar[])
{
    int i;
    int flag=1;//1 es char

    for(i=0;i<strlen(auxiliar);i++)
    {
        if((auxiliar[i]!=' ') && (auxiliar[i]<'A' || auxiliar[i]>'Z') && (auxiliar[i]<'a' || auxiliar[i]>'z')) //Si hay espacio tambien es valido como letra
        {
            flag=0;//0 no es char
            break;
        }
    }

    return flag;
}

int esAlfanumerico(char auxiliar[])
{
    int i;
    int flag=1;//es alfanumerico

    //Si es todo numero o todo letras no es alfanumerico
    if(esLetra(auxiliar)==1 || esNumero(auxiliar)==1)
    {
        flag=0;
    }

    for(i=0;i<strlen(auxiliar);i++)
    {
            if(((auxiliar[i]!=' ') && (auxiliar[i]<'A' || auxiliar[i]>'Z') && (auxiliar[i]<'a' || auxiliar[i]>'z')) && (auxiliar[i]<'0' || auxiliar[i]>'9'))
            {
                flag=0;//No es alfanumerico
                break;
            }
    }

    return flag;
}

int esTelefonoFijo(char auxiliar[])
{
    int i;
    int flag=1;//Es telefono

    //Si el telefono no empieza con 4
    if((auxiliar[0]!='4' || strlen(auxiliar)!=9) || auxiliar[4]!='-')
    {
        flag=0;//No es telefono
    }
    else
    {
        for(i=0;i<strlen(auxiliar);i++)
        {
            if((auxiliar[i]<'0' || auxiliar[i]>'9') && (auxiliar[i]!='-'))
            {
                flag=0;//No es telefono
                break;
            }
        }
    }


    return flag;
}
