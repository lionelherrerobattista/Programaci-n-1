#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    int i;

    int acumuladorNumeros=0;
    float promedio;

    int numeroMaximo;
    int numeroMinimo;
    int flag=0;

    for (i=0; i<5; i++)
    {
        printf("Escriba un numero: ");
        scanf("%d",&numero);

        acumuladorNumeros=acumuladorNumeros+numero;

        //Junto ambas condiciones en un mismo if
        if (flag==0 || numero > numeroMaximo)
        {
            numeroMaximo=numero;
        }
        if (flag==0 || numero < numeroMinimo)
        {
            numeroMinimo=numero;
            flag=1;
        }

    }

    //Resultado entre int/int = a int
    //por eso hay que convertirlo a float
    promedio=(float)acumuladorNumeros/i;

    printf("El promedio de los numeros ingresados es: %.2f",promedio);
    printf("\nEl numero maximo es: %d",numeroMaximo);
    printf("\nEl numero minimo es: %d",numeroMinimo);
    
}
