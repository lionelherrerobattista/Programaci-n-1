#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

void sumar1(void);
void sumar2(int, int);
int sumar3();
int sumar4(int, int);


int main()
{

    //sumar1();
    //sumar2(4, 9);
    int resultado;
    resultado=sumar3(); //Necesito una variable de tipo entero
    printf("La suma es %d", resultado);

    return 0;
}

//Prototipo1 Es lo mismo que hacer todo en el main.
void sumar1(void)
{
    int numeroUno;
    int numeroDos;
    int suma;

    numeroUno = pedirEntero("Ingrese un numero: ", 1, 1000);
    numeroDos = pedirEntero("Ingrese un numero: ", 1, 1000);

    suma= numeroUno + numeroDos;

    printf("La suma es: %d", suma);

}

/*Prototipo2 Leve mejora de la anterior.
Atado a que la suma se muestre*/
void sumar2 (int n1, int n2)
{
    int suma;
    suma= n1 + n2;

    printf("La suma es: %d", suma);
}

/*Prototipo3 si quiero hacer una aplicación de escritorio no sirve.
La forma que se muestra la info es distinta. Debe ser totalmente indep. de las entradas
y de las salidas.
Atado a los numeros que ingrese el usuario por cosola.*/
int sumar3()
{
    int numeroUno;
    int numeroDos;
    int suma;

    numeroUno = pedirEntero("Ingrese un numero: ", 1, 1000);
    numeroDos = pedirEntero("Ingrese un numero: ", 1, 1000);

    suma= numeroUno + numeroDos;

    return suma;
}

//Prototipo4 ideal
int sumar4(int n1, int n2)
{
    int suma;

    suma= n1 + n2;

    return suma;
}
