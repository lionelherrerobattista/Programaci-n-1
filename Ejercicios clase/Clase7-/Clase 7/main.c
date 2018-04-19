#include <stdio.h>
#include <stdlib.h>
#define TAM 3

float calcularPromedio(int, int);
void mostrarAlumnos(int[], char[][30], int[], int[], float[], int);

int main()
{
    int legajos[TAM];
    char nombres[TAM][30];
    int notaUno[TAM];
    int notaDos[TAM];
    float promedios[TAM];


    int i;

    for (i=0; i<TAM; i++)
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

    /*for(i=0; i<TAM;i++)
    {
        printf("\nLegajo: %d\n",legajos[i]);
        printf("Nombre: %s\n",nombres[i]);
        printf("Nota1: %d\n",notaUno[i]);
        printf("Nota2: %d\n",notaDos[i]);
        printf("Promedio: %.2f\n",promedios[i]);
    }*/

    mostrarAlumnos(legajos, nombres, notaUno, notaDos, promedios, TAM);





    return 0;
}

float calcularPromedio(int notaUno, int notaDos)
{
    float resultado;

    resultado=(float)(notaUno+notaDos)/2;

    return resultado;
}

void mostrarAlumnos(int legajo[], char nombre[][30], int nota1[], int nota2[], float promedio[], int tam)
{
    int i;

    for(i=0; i<tam;i++)
    {
        printf("\nLegajo: %d\n",legajo[i]);
        printf("Nombre: %s\n",nombre[i]);
        printf("Nota1: %d\n",nota1[i]);
        printf("Nota2: %d\n",nota2[i]);
        printf("Promedio: %.2f\n",promedio[i]);
    }

}


