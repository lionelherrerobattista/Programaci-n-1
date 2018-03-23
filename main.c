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


    while(respuesta=='s')
    {
        printf("\nIngrese un numero: ");
        scanf("%d", &numero);

        if (numero%2==0 && numero!=0)
        {
            contadorNumerosPares++;
        }
        else
        {
            if (numero!=0)
            {
                contadorNumerosImpares++;
            }
        }

        printf("\nPara continuar escriba s: ");
        respuesta=getche();

    }

    printf("\nLa cantidad de numeros impares es: %d", contadorNumerosImpares);
    printf("\nLa cantidad de numeros impares es: %d",contadorNumerosPares);



    return 0;
}
