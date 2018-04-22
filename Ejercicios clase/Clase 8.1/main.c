#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define T 5

int buscarInt (int [],int , int);

int main()
{
    int vectorInt [T]={1,2,3,4,5};
    char vectorString [T] [30] ={"juan","maria","pedro","luis","ana"};
    float vectorFloat [T]={5.3,2.9,1.5,8.7,3.3};
    int i;
    int j;
    char auxString [T][30];
    int auxInt;
    float auxFloat;

        auxInt = buscarInt(vectorInt,T,3);
        //printf("\nINDICE: %d",auxInt);
        if(auxInt!=-1)
        {
            printf("\n%s\n",vectorString);
        }


    for(i=0; i<T-1; i++)
    {
        for(j=i+1; j<T; j++)
        {
            if(strcmp(vectorString[i],vectorString[j])>0) //comparo los nombres y me devuelve 0 si tienen la mimsma letra
            {
                strcpy(auxString[i],vectorString[i]);
                strcpy(vectorString[i],vectorString[j]);
                strcpy(vectorString[j],auxString[i]);

                auxInt=vectorInt[i];
                vectorInt[i]=vectorInt[j];
                vectorInt[j]=auxInt;

                auxFloat=vectorFloat[i];
                vectorFloat[i]=vectorFloat[j];
                vectorFloat[j]=auxFloat;
            }
        }
    }


    for(i=0; i<T; i++)
    {
        if(vectorInt[i]!=0) //esta funcion hace el jarcodeo
        {
            printf("%d -- %s -- %.2f\n",vectorInt[i],vectorString[i],vectorFloat[i]);
        }
    }





    return 0;
}

 int buscarInt (int enteros[],int tam, int cual)
    {
        int indice=-1;
        int i;
        for(i=0; i<tam; i++)
        {
            if(enteros[i]==cual)
            {
                indice=1;
                break;
            }

        }
    }
