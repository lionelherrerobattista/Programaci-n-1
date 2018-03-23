#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    int respuesta='s';

    int contadorNumerosPares=0;
    int contadorNumerosImpares=0;
    int contadorNumerosTotal=0;
    int contadorNumeroPositivos=0;
    int contadorNumerosNegativos=0;

    float porcentajeNumerosPositivos;
    float porcentajeNumerosNegativos;

    int numeroMaximo;
    int numeroMinimo;

    int flag=0;
    int flagPar = 0;

    int maximoNumeroPar;

    int cantidadDeNumerosMasCien=0;


    while(respuesta=='s')
    {
        printf("\nIngrese un numero: ");
        scanf("%d", &numero);

        while (numero==0)
        {
            printf("\nReingrese un numero: ");
            scanf("%d", &numero);
        }

        //contadorNumerosTotal++;

        if (numero%2==0)
        {
            contadorNumerosPares++;

            if (flagPar==0 || numero > maximoNumeroPar)
            {
                maximoNumeroPar=numero;
                flagPar = 1;
            }
            /*else
            {
                if (numero > maximoNumeroPar)
                {
                    maximoNumeroPar=numero;
                }
            }*/
        }
        else
        {
            contadorNumerosImpares++;
        }

        if (numero > 0)
        {
            contadorNumeroPositivos++;
        }
        else
        {
            contadorNumerosNegativos++;
        }

        if (flag ==0 || numero>maximo)
        {
            maximo=numero;

        }
        if (flag == 0 || numero<minimo)
        {
            minimo=numero;
            flag=1;
        }
        /*if (flag==0/*contadorNumerosTotal==1)
        {
            numeroMaximo = numero;
            numeroMinimo = numero;

            flag = 1;
        }
        else
        {
            if (numero > numeroMaximo)
            {
                numeroMaximo=numero;
            }
            else
            {
                if (numero < numeroMinimo)
                {
                    numeroMinimo=numero;
                }
            }
        }*/


        if (numero>125 && numero<236)
        {
            cantidadDeNumerosMasCien++;
        }

        printf("\nPara continuar ingresando numeros escriba s: ");
        respuesta=getche();

    }

    //contadorNumerosTotal= contadorNumeroPositivos+contadorNumerosNegativos;

    printf("\nLa cantidad de numeros impares es: %d", contadorNumerosImpares);
    printf("\nLa cantidad de numeros pares es: %d",contadorNumerosPares);

    porcentajeNumerosPositivos=(float)(contadorNumeroPositivos*100)/contadorNumerosTotal;
    printf("\nEl porcentaje de numeros positivos es: %f %%", porcentajeNumerosPositivos);

    porcentajeNumerosNegativos= 100 - porcentajeNumerosPositivos; //(contadorNumerosNegativos*100)/contadorNumerosTotal;
    printf("\nEl porcentaje de numeros negativos es: %f %%", porcentajeNumerosNegativos);

    printf("\nEl numero maximo es: %d", numeroMaximo);
    printf("\nEl numero minimo es: %d", numeroMinimo);

    printf("\nEl maximo numero par es: %d", maximoNumeroPar);

    printf("\nLa cantidad de numeros entre 125 y 236 es: %d", cantidadDeNumerosMasCien);
    return 0;
}
