#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numeroUsuario;
    char respuesta='n';

    int sumaNumerosNegativos=0;
    int sumaNumerosPositivos=0;


    int contadorNumerosNegativos=0;
    int contadorNumerosPositivos=0;
    int contadorCeros=0;
    int contadorNumerosPares=0;

    float promedioNumerosPositivos=0;
    float promedioNumerosNegativos=0;


    do
    {
        printf("Ingrese un numero:");
        scanf("%d",&numeroUsuario);

        if(numeroUsuario<0)
        {
            contadorNumerosNegativos++;
            sumaNumerosNegativos+=numeroUsuario;
        }
        else
        {
            if(numeroUsuario>0)
            {
                contadorNumerosPositivos++;
                sumaNumerosPositivos+=numeroUsuario;
            }
            else
            {
                contadorCeros++;
            }
        }

        if(numeroUsuario%2==0 && numeroUsuario!=0)
        {
            contadorNumerosPares++;
        }



        printf("Desea continuar s/n:");
        fflush(stdin);
        scanf("%c",&respuesta);


    }while(respuesta=='s');

    printf("\nSuma numeros positivos: %d\n",sumaNumerosPositivos);
    printf("Suma numeros negativos: %d\n",sumaNumerosNegativos);
    printf("Cantidad numeros positivos: %d\n",contadorNumerosPositivos);
    printf("Cantidad numeros negativos: %d\n",contadorNumerosNegativos);
    printf("Cantidad ceros: %d\n",contadorCeros);
    printf("Cantidad numeros pares: %d\n",contadorNumerosPares);

    if(contadorNumerosPositivos>0)
    {
        promedioNumerosPositivos=sumaNumerosPositivos/contadorNumerosPositivos;
    }

    printf("Promedio numeros positivos: %.2f\n",promedioNumerosPositivos);


    if(contadorNumerosNegativos<0)
    {
        promedioNumerosNegativos=sumaNumerosNegativos/contadorNumerosNegativos;
    }
    printf("Promedio numeros negativos: %.2f\n", promedioNumerosNegativos);



    return 0;
}
