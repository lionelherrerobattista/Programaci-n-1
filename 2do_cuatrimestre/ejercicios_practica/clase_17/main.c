#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "texto.h"


/**
Ejercicios
1) Construir una función llamada "getDynamicString"
     que permita al usuario ingresar un texto y devuelva un puntero a un espacio de memoria
      donde esta almacenado el texto ingresado. Se requiere el uso de memoria dinámica.

 */



int main()
{
    char* pTexto;

    pTexto=getDynamicString("Ingrese un mensaje");

    printf("%s",pTexto);

    //Liberar los espacios reservados con malloc
    free(pTexto);


    return 0;
}



