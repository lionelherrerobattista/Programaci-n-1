#include <stdio.h>
#include <stdlib.h>

float calcularPromedio(int, int);

int main()
{
    int legajos[3];
    char nombres[3][30];
    int notaUno[3];
    int notaDos[3];
    float promedios[3];


    int i;

    for (i=0; i<3; i++)
    {
        printf("Ingrese el legajo: ");
        scanf("%d",&legajos[i]);
        printf("Ingrese el nombre: ");
        fflush(stdin);
        gets(nombres[i]);
        printf("Ingrese la nota1: ");
        scanf("%d",&notaUno[i]);
        printf("Ingrese la nota2: ");
        scanf("%d",&notaDos[i]);
        promedios[i]=calcularPromedio(notaUno[i],notaDos[i]);

    }

    for(i=0; i<3;i++)
    {
        printf("\nLegajo: %d\n",legajos[i]);
        printf("Nombre: %s\n",nombres[i]);
        printf("Nota1: %d\n",notaUno[i]);
        printf("Nota2: %d\n",notaDos[i]);
        printf("Promedio: %.2f\n",promedios[i]);
    }





    return 0;
}

float calcularPromedio(int notaUno, int notaDos)
{
    float resultado;

    resultado=(float)(notaUno+notaDos)/2;

    return resultado;
}


