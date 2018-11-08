#include <stdio.h>
#include <stdlib.h>
#define MAX 100

/*De los 100 empleados de una fábrica se registra número de legajo (coincidente con
el índice), edad y salario. Se pide ingresar los datos consecutivamente y calcular el sueldo
promedio.*/


int main()
{
    int edad[MAX];
    int i;

    float sueldo[MAX];
    float suma = 0;
    float promedio;
    //float auxiliar;

    for(i=0;i<MAX;i++)
    {
        printf("Ingrese la edad del legajo %d: ", i+1);
        //i+1 porque el nro. de legajo siempre va a ser +1
        //de la posición en la que se cargan los datos
        fflush(stdin);
        scanf("%d",&edad[i]);

        printf("Ingrese el sueldo del legajo %d: ", i+1);
        fflush(stdin);
        scanf("%f",&sueldo[i]);
    }

    for (i=0;i<MAX;i++)
    {
        suma+=sueldo[i];
    }

    //Se debe calcular fuera del for para no repetir la operación
    promedio = suma / MAX;

    printf("El sueldo promedio es %.2f", promedio);




    return 0;
}
