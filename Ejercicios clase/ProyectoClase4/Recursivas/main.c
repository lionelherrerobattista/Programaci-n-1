#include <stdio.h>
#include <stdlib.h>


/** \brief Calcular el factorial de un numero
 *
 * \param Un numero
 * \return EL factorial de un numero que recibe como parametro
 *
 */

int factorial (int);

int main()
{
    int numero = 5;
    int factor;

    factor = factorial(numero);

    printf("El factorial es es: %d", factor);

    /*int numero;
    int factorial=1; // 1 = elemento neutro de la multiplicación.
    int i;

    printf("Ingrese un numero para calcular el factorial: ");
    scanf("%d",&numero);

    for(i=numero; i>=1; i--)
    {
        factorial= factorial*i;//(numero-1);
        //numero--;
    }

    printf("el resultado es: %d", factorial);*/

    return 0;
}

/* funcion está mal:
-No se debería poner más de un retorno por función.

int factorial(int numero)
{
    int respuesta;
    if (numero==1)
    {
        return 1;
    }

    respuesta= numero * factorial(numero-1);
    return respuesta;

}
*/

int factorial(int numero)
{
    int respuesta;
    if (numero==0)
    {
        respuesta = 1;
    }
    else
    {
        respuesta= numero * factorial(numero-1); //Vuelve a llamar a la función factorial y le pasa (5-1)=4 y ss.
    }

    return respuesta;

}
