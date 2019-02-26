#include <stdio.h>
#include <stdlib.h>

int pedirEntero(char[]);
int sumarEntero(int, int);

int main()
{
    int numeroUno;
    int numeroDos;
    int resultado;


    numeroUno=pedirEntero("un numero entero: ");
    numeroDos=pedirEntero("un numero entero: ");

    resultado=sumarEntero(numeroUno, numeroDos);

    printf("El resultado de la suma es: %d", resultado);

    return 0;
}

int pedirEntero(char mensaje[])
{
    int numero;

    printf("Ingrese %s", mensaje);
    scanf("%d", &numero);


    return numero;

}

int sumarEntero(int numeroUno, int numeroDos)
{
    int resultado;

    resultado= numeroUno + numeroDos;

    return resultado;

}
