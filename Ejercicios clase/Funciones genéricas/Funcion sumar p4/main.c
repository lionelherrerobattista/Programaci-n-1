#include <stdio.h>
#include <stdlib.h>

int sumarEntero();

int main()
{
    int resultado;

    resultado=sumarEntero();

    printf("El resultado de la suma es: %d", resultado);

    return 0;
}

int sumarEntero()
{
    int resultado;
    int numeroUno;
    int numeroDos;

    //usar el reloj del sistema para
    //que no se repita el número random
    srand (time(NULL));

    numeroUno= rand() %11; //nro. random del 0-10 % Nmax+1
    numeroDos= rand() %11;

    resultado= numeroUno + numeroDos;

    return resultado;
}
