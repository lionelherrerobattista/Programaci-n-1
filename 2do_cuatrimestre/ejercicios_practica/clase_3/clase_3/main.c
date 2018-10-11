#include <stdio.h>
#include <stdlib.h>

/** \brief Pide un float al usuario y lo devuelve
 *
 * \param mensaje[] char mensaje al usuario
 * \param min float número mínimo que puede ingresar el usuario
 * \param max float número máximo que puede ingresar el usuario
 * \return float el número ingresado
 *
 */
float pedirFloat(char mensaje[], float min, float max);

/** \brief Valida un float
 *
 * \param numero float el número a validar
 * \param min float número mínimo que se puede ingresar
 * \param max float número máximo que se puede ingresar
 * \param [] char mensaje mensaje de error
 * \return float número validado
 *
 */
float validarFloat(float numero, float min, float max, char mensaje []);

/** \brief Calcula el área del círculo y la devuelve
 *
 * \param radio float radio del círculo
 * \return float área del círculo
 *
 */
float calcularAreaCirculo(float radio);

int main()
{
    float radio;
    float area;

    radio= pedirFloat("Ingrese el radio del circulo", 1, 100);

    area= calcularAreaCirculo(radio);

    printf("El area del circulo es: %.2f\n", area);

    return 0;
}


float pedirFloat(char mensaje[], float min, float max)
{
    float numero;

    printf("%s: ",mensaje);
    scanf("%f",&numero);

    numero = validarFloat(numero, min, max, mensaje);

    return numero;
}

float validarFloat(float numero, float min, float max, char mensaje [])
{
    while(numero < min || numero > max)
    {
        printf("Error. Ingrese %s nuevamente: ",mensaje);
        scanf("%f", &numero);
    }

    return numero;
}

float calcularAreaCirculo(float radio)
{
    float area;

    area= 3.14 * (radio * radio);

    return area;
}
