#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define TAM 10



int main()
{
    char auxString[TAM]; //el string debe ser un char (lo que recibe isDigit)
    int x; //donde guardo lo que me devulve is digit
    int i;
    int retorno; //donde guardo el numero una vez que convierto el vector

    //inicio el string en 0 para no dejar basura
    for (i=0; i<TAM; i++)
    {
        auxString[i]='0';
    }

    //ingreso el numero como char
    fflush(stdin);
    gets(auxString);

    //me fijo todos los elementos del vector para saber si es un numero
    for (i=0; i<TAM; i++)
    {
       x=isdigit(auxString[i]);

    }

    //Si es un numero, pasamos el vector char a numero
    if(x==1)
    {
        printf("\nEs un numero.");
        retorno=atoi(auxString);
    }
    else
    {
        printf("\nNo es un numero.");
    }

    //devuelve el numero ingresado para operar
    printf("\n%d", retorno);






    return 0;
}


int buscarMayor (int vectorEnteros[], int limite)
{
    int i;
    int mayor;

    mayor= vectorEnteros [0];
    for (i=0; i<limite; i++)
    {
        if (vectorEnteros[i]>mayor)
        {
            mayor=vectorEnteros[i];
        }
    }

    return mayor;
}
