#include <stdio.h>
#include <stdlib.h>
/*Declaraci�n/prototipo/firma de la funci�n
tipo_de_dato_devuelto identificador ([par�metro de entrada]);
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
    //desarrollo de la funci�n
    printf("El numero ingresado es: %d", numero);
}*/

