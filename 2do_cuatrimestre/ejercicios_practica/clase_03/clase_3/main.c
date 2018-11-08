#include <stdio.h>
#include <stdlib.h>

/** \brief Pide un float al usuario y lo devuelve
 *
 * \param mensaje[] char mensaje al usuario
 * \param min float n�mero m�nimo que puede ingresar el usuario
 * \param max float n�mero m�ximo que puede ingresar el usuario
 * \return float el n�mero ingresado
 *
 */
float pedirFloat(char mensaje[], float min, float max);

/** \brief Valida un float
 *
 * \param numero float el n�mero a validar
 * \param min float n�mero m�nimo que se puede ingresar
 * \param max float n�mero m�ximo que se puede ingresar
 * \param [] char mensaje mensaje de error
 * \return float n�mero validado
 *
 */
float validarFloat(float numero, float min, float max, char mensaje []);

/** \brief Calcula el �rea del c�rculo y la devuelve
 *
 * \param radio float radio del c�rculo
 * \return float �rea del c�rculo
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
