#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    int i;
    int contadorDivisores=0;

    printf("\nEscriba un numero para saber si es primo: ");
    scanf("%d",&numero);

    for(i=1;i<=numero;i++)
    {
        if(numero%i==0)
        {
            contadorDivisores++;
        }

    }

    if(contadorDivisores==2 && numero!=0)
    {
        printf("\nEs un numero primo.");
    }
    else
    {
        printf("\nNo es un numero primo.");
    }

    return 0;
}
