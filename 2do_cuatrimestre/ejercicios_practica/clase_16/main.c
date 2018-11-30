#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "persona.h"
#define TAM_PERSONAS 5

/**
1) Realizar una funci�n para cargar los datos de una persona en una struct, para ello se debe definir una estructura con los campos nombre, edad, dni.

A) La funci�n tendr� el siguiente prototipo:

int loadPerson(struct S_Person* pPerson);

B) La funci�n deber� devolver un 1 si los datos ingresados son correctos, y un 0 si no lo son.

C) Hacer otra funci�n que reciba un puntero a la estructura e imprima por pantalla los datos, el prototipo es:

void printPerson(struct S_Person* pPerson);

D) Escribir un programa para probar las funciones.
 */


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



