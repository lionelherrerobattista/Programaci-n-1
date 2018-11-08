#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "validaciones.h"

/*
1) Agregar a la biblioteca utn.h funciones
para validar diferentes tipos de valores:

- Solo números, ej. 123436679
- Solo letras, ej. abBD
- Alfanumericos, ej. ab555gT6
- Teléfono, ej. 4XXX-XXXX

2) Realizar un programa que pida al usuario el ingreso de un dato
y determine con cuales de los tipos cumple.
*/

int main()
{
    printf("Ingrese un dato:");
    char auxiliar [50]={};

    gets(auxiliar);


    if(esNumero(auxiliar))
    {
        printf("\nEs numero.");
    }

    if(esLetra(auxiliar))
    {
        printf("\nEs letra.");
    }

    if(esAlfanumerico(auxiliar))
    {
        printf("\nEs alfanumerico.");
    }

    if(esTelefonoFijo(auxiliar))
    {
        printf("\nEs telefono.");
    }

    return 0;
}


