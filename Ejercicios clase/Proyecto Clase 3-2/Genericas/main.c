#include <stdio.h>
#include <stdlib.h>

int pedirEntero(char[], int, int);

int main()
{
    int edad; //Entre 18-60
    int legajo; //Entre 1-1000
    int nota; //Entre 1-10

    edad = pedirEntero("Ingrese edad: ", 18, 60);

    legajo = pedirEntero("Ingrese legajo: ", 1, 1000);

    nota = pedirEntero("Ingrese nota: ", 1, 10);

    printf("La edad es: %d y el legajo es: %d y la nota es: %d", edad, legajo, nota);

    return 0;
}

int pedirEntero(char mensaje[], int min, int max)
{
    int numero;

    printf("%s", mensaje);
    scanf("%d", &numero);

    while (numero<min || numero>max)
    {
        printf("Error: %s", mensaje);
        scanf("%d",&numero);
    }

    return numero;

}
