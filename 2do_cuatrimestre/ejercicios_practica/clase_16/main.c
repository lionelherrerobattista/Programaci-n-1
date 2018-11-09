#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "persona.h"
#define TAM_PERSONAS 5



int main()
{
    //Declaro la estructura y el puntero
    S_Person persona;
    S_Person* pPerson;

    //Asigno la direccion de memoria de la estructura al puntero
    pPerson=&persona;

    //Cargo los datos
    loadPerson(pPerson);

    //Muestro
    printPerson(pPerson);


    return 0;
}



