
#include <stdlib.h>
#include "Funciones.h"

float pedirFlotante(char[], float, float);
char pedirChar(char[], char, char);

int main()
{
    int edad;
    int legajo;
    edad = pedirEntero("Ingrese edad: ", 18, 60);
    legajo = pedirEntero("Ingrese legajo: ", 1, 1000);

    return 0;
}




