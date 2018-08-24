#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numeroUsuario;
    char respuesta;//no hace falta inicializar con do while

    int sumaNumerosNegativos=0;
    int sumaNumerosPositivos=0;


    int contadorNumerosNegativos=0;
    int contadorNumerosPositivos=0;
    int contadorCeros=0;
    int contadorNumerosPares=0;

    float promedioNumerosPositivos=0;
    float promedioNumerosNegativos=0;

    int diferenciaPositivosNegativos=0;


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



        do
        {
            printf("Desea continuar s/n:");
            fflush(stdin);//setbuf(stdin,NULL);
            scanf("%c",&respuesta);
        }while(respuesta!='s' && respuesta!='n');


    }while(respuesta=='s');

    printf("\n1-Suma numeros negativos: %d\n",sumaNumerosNegativos);
    printf("2-Suma numeros positivos: %d\n",sumaNumerosPositivos);
    printf("3-Cantidad numeros positivos: %d\n",contadorNumerosPositivos);
    printf("4-Cantidad numeros negativos: %d\n",contadorNumerosNegativos);
    printf("5-Cantidad ceros: %d\n",contadorCeros);
    printf("6-Cantidad numeros pares: %d\n",contadorNumerosPares);

    if(contadorNumerosPositivos>0)
    {
        promedioNumerosPositivos=sumaNumerosPositivos/contadorNumerosPositivos;
    }

    printf("7-Promedio numeros positivos: %.2f\n",promedioNumerosPositivos);


    if(contadorNumerosNegativos>0)
    {
        promedioNumerosNegativos=sumaNumerosNegativos/contadorNumerosNegativos;
    }
    printf("8-Promedio numeros negativos: %.2f\n", promedioNumerosNegativos);

    diferenciaPositivosNegativos=sumaNumerosPositivos-sumaNumerosNegativos;
    printf("9-Diferencia entre positivos y negativos: %d",diferenciaPositivosNegativos);





    return 0;
}
