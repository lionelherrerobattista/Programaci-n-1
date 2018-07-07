#include <stdio.h>
#include <stdlib.h>

int main()
{
    //int vector[5]={5,2,8,6,5};
    char vector[5]={'w','a','v','e','b'};
    char auxiliar;//Donde se guarda el dato.
    int i;
    int j;

    for(i=0; i<4; i++)//Termina cant de elementos del array -1.
    {
        for(j=i+1; j<5; j++)//Siempre empieza en i+1. Llega al último elemento.
        {
            if(vector[i]>vector[j])//(Criterio de ordenamiento) Se comparan los valores del vector y los intercambia (dejo el más chico adelante)
            {
                auxiliar=vector[i];
                vector[i]=vector[j];
                vector[j]=auxiliar;
            }

        }
    }

    for (i=0;i<5;i++)
    {
        printf("%c\n",vector[i]);
    }

    /*int a=9;
    int b=5;
    int c;

    //Swap:
    c=a;
    a=b;
    b=c;

    printf("a = %d -- b = %d", a, b);*/

    return 0;
}
