#include <stdio.h>
#include <stdlib.h>

int pedirEntero(char[], int, int);

int validarEntero (int, int, int, char[]); //Recibe dato min y max

int main()
{
    int edad; //Entre 18-60
    int legajo; //Entre 1-1000
    int nota; //Entre 1-10

    edad = pedirEntero(" edad: ", 18, 60);

    legajo = pedirEntero(" legajo: ", 1, 1000);

    nota = pedirEntero(" nota: ", 1, 10);

    printf("La edad es: %d y el legajo es: %d y la nota es: %d", edad, legajo, nota);

    return 0;
}

int pedirEntero(char mensaje[], int min, int max)
{
    int numero;

    printf("Ingrese %s", mensaje);
    scanf("%d", &numero);

    numero = validarEntero(numero, min, max, mensaje);


    return numero;

}

int validarEntero(int dato, int min, int max, char mensaje[]) //el dato que entra es el dato que sale pero validado
{
    while (dato<min || dato>max)
    {
        printf("Error. Reingrese %s ", mensaje); //muestra el mensaje de la función main
        scanf("%d",&dato);
    }
    return dato;
}
