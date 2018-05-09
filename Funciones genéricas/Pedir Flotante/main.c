#include <stdio.h>
#include <stdlib.h>

//prototipo pedirFlotante

float pedirFlotante(char[], float, float);
float validarFlotante(float, float, float, char[]);

int main()
{
    float numero;

    numero = pedirFlotante(" un numero con coma:", 0, 100);
    printf("El numero ingresado es: %f", numero);

    return 0;
}

//Función para pedir un número con coma.
float pedirFlotante(char mensaje[], float min, float max)
{
    float numero;

    printf("Ingrese %s", mensaje);
    scanf("%f", &numero);

    numero = validarFlotante(numero, min, max, mensaje);


    return numero;
}

float validarFlotante(float dato, float min, float max, char mensaje[])
{
    while (dato<min || dato>max)
    {
        printf("Error. Reingrese %s",mensaje);
        scanf("%f",&dato);
    }
    return dato;
}
