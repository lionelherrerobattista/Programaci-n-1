#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "temas.h"
#include "LinkedList.h"
#include "validaciones.h"
#include "estadistica.h"

S_Estadistica* newEstadistica()
{
	//Creo un puntero del tipo estructura
    S_Estadistica* pEstadistica=NULL;

	//Asigno espacio en memoria
    pEstadistica = (S_Estadistica*)malloc(sizeof(S_Estadistica)); //casteo

	//retorna el puntero
    return pEstadistica;
}
