#include <stdio.h>
#include <stdlib.h>
/*Declaración/prototipo/firma de la función
tipo_de_dato_devuelto identificador ([parámetro de entrada]);
*/

//void mostrarMensaje(int);
int mostrarEincrementar(int);

int main()
{
    int numero;
    int incremento;

    printf("Ingrese un numero: ");
    scanf("%d", &numero);

    incremento=mostrarEincrementar(numero);

    printf("\nEl numero incrementado es: %d", incremento);

   //mostrarMensaje(numero);
    return 0;
}

int mostrarEincrementar(int numero)
{
    //Igual tipo de dato
    int retorno;

    printf("El numero ingresado es: %d", numero);

    retorno= numero + 10;

    //devolver y variable
    return retorno;

    }


/*void mostrarMensaje(int numero)
{
    //desarrollo de la función
    printf("El numero ingresado es: %d", numero);
}*/

