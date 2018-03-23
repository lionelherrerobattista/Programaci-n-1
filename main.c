#include <stdio.h>
#include <stdlib.h>

/* Se igresan numeros(distintos de cero), no se sabe cuantos.
Se pide mostrar:
    *Cantidad de pares e impares.
    *Porcentaje de numeros positivos y negativos
    *Maximo y minimo
    *Maximo numero par
    *Cantidad de numeros comprendidos entre 125 y 236.*/

int main()
{
    int numero;
    int respuesta='s';

    int contadorNumerosPares=0;
    int contadorNumerosImpares=0;
    int contadorNumerosTotal=0;
    int contadorNumeroPositivos=0;
    int contadorNumerosNegativos=0;

    int porcentajeNumerosPositivos;
    int porcentajeNumerosNegativos;

    int numeroMaximo;
    int numeroMinimo;

    int maximoNumeroPar;

    int cantidadDeNumerosMasCien;


    while(respuesta=='s')
    {
        printf("\nIngrese un numero: ");
        scanf("%d", &numero);

        while (numero==0)
        {
            printf("\nReingrese un numero: ");
            scanf("%d", &numero);
        }

        contadorNumerosTotal++;

        if (numero%2==0)
        {
            contadorNumerosPares++;

            if (contadorNumerosTotal==1)
            {
                maximoNumeroPar=numero;
            }
            else
            {
                if (numero > maximoNumeroPar)
                {
                    maximoNumeroPar=numero;
                }
            }
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

        if (contadorNumerosTotal==1)
        {
            numeroMaximo = numero;
            numeroMinimo = numero;
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
        }

        if (numero>125 && numero<236)
        {
            cantidadDeNumerosMasCien++;
        }

        printf("\nPara continuar escriba s: ");
        respuesta=getche();

    }

    printf("\nLa cantidad de numeros impares es: %d", contadorNumerosImpares);
    printf("\nLa cantidad de numeros pares es: %d",contadorNumerosPares);

    porcentajeNumerosPositivos=(contadorNumeroPositivos*100)/contadorNumerosTotal;
    printf("\nEl porcentaje de numeros positivos es: %d", porcentajeNumerosPositivos);

    porcentajeNumerosNegativos= (contadorNumerosNegativos*100)/contadorNumerosTotal;
    printf("\nEl porcentaje de numeros negativos es: %d", porcentajeNumerosNegativos);

    printf("\nEl numero maximo es: %d", numeroMaximo);
    printf("\nEl numero minimo es: %d", numeroMinimo);

    printf("\nEl maximo numero par es: %d", maximoNumeroPar);

    printf("\nLa cantidad de numeros entre 125 y 236 es: %d", &cantidadDeNumerosMasCien);



    return 0;
}
