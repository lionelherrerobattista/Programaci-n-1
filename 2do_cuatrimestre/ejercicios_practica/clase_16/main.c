#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "persona.h"
#define TAM_PERSONAS 5

void printPerson(S_Person* pPerson);

int loadPerson(S_Person* pPerson);

int main()
{
    S_Person persona;
    S_Person* pPerson;

    pPerson=&persona;

    loadPerson(pPerson);

    printPerson(pPerson);


    return 0;
}



void printPerson(S_Person* pPerson)
{
    printf("\n|%-15s| %-15s| %-15s|\n", "Edad", "Nombre", "DNI");
    printf("---------------------------------------------------\n");
    printf("|%-15d| %-15s| %-15d|\n", pPerson->edad, pPerson->nombre, pPerson->dni);
}
