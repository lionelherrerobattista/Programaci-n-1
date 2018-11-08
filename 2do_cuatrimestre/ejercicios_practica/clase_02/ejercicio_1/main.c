#include <stdio.h>
#include <stdlib.h>

//1) Realizar un programa que solicite cinco números
//e imprima por pantalla el promedio, el máximo y el mínimo.

int main()
{
    int numero;
    int i;

    //Acumulador para sacar el promedio
    int acumuladorNumeros=0;
    float promedio;

    //Variables para guardar máximo y mínimo
    int maximo;
    int minimo;

    //flag=0 primera iteracion maximo==minimo
    int flag=0;


    //Pido 5 numeros
    printf("Ingrese 5 numeros:\n");


    for(i=0;i<5;i++) //Uso for, se cuántas veces voy a iterar
    {
        scanf("%d",&numero);

        //Si itero por primera vez numero=maximo && numero=minimo
        //uso flag
        if(flag==0 || maximo<numero) //Uso || con que cumpla 1 de las 2 condiciones, entra
        {
            maximo=numero;
        }

        if (flag==0 || minimo>numero)
        {
            minimo=numero;

        }

        //Establecí máximo y mínimo entonces cambio flag=1
        flag=1;

        //Acumulador para sacar el promedio
        acumuladorNumeros+=numero;
    }


    promedio= (float)acumuladorNumeros/i; //División entre dos int, tengo que castear 1 a float

    //Imprimo por pantalla todo
    printf("\nPromedio: %.2f\n",promedio);
    printf("Maximo: %d\n", maximo);
    printf("Minimo: %d\n", minimo);

    return 0;
}
