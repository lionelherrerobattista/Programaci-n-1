#include <stdio.h>
#include <stdlib.h>

int pedirEntero(char[]);
void sumarEntero(int, int);

int main()
{
    int numeroUno;
    int numeroDos;



    numeroUno=pedirEntero("un numero entero: ");
    numeroDos=pedirEntero("un numero entero: ");

    sumarEntero(numeroUno, numeroDos);



    return 0;
}

int pedirEntero(char mensaje[])
{
    int numero;

    printf("Ingrese %s", mensaje);
    scanf("%d", &numero);


    return numero;

}

void sumarEntero(int numeroUno, int numeroDos)
{
    int resultado;

    resultado= numeroUno + numeroDos;

}
