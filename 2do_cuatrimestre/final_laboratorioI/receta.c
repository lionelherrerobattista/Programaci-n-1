#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "validaciones.h"
#include "receta.h"

S_receta* newReceta()
{
	//Creo un puntero del tipo estructura
    S_receta* pReceta=NULL;

	//Asigno espacio en memoria
    pReceta = (S_receta*)malloc(sizeof(S_receta)); //casteo

	//retorna el puntero
    return pReceta;
}

int receta_cargarReceta(S_receta* pReceta, char* auxIdReceta, char* auxNombre, char* auxIdIngrediente,
                                     char* auxCantidad)
{
    int retorno = 0;//no cargo
    int id_receta;
    int id_ingrediente;
    float cantidad;

    //compruebo que el puntero no sea null
    if(pReceta != NULL)
    {

        id_receta = atoi(auxIdReceta);
        id_ingrediente = atoi(auxIdIngrediente);
        cantidad = atoi(auxCantidad);

        //Seteo los datos en la estructura
        receta_setIdReceta(pReceta, id_receta);
        receta_setNombre(pReceta, auxNombre);
        receta_setIdIngrediente(pReceta, id_ingrediente);
        receta_setCantidad(pReceta, cantidad);

        retorno = 1;//cargó
    }

    return retorno;
}


int receta_setIdReceta(S_receta* pAuxEstructura, int id_receta)
{
	int retorno = 0;

	if(pAuxEstructura != NULL)
	{
		pAuxEstructura->id_receta = id_receta;

		retorno = 1;
	}

    return retorno;
}

int receta_setNombre(S_receta* pAuxEstructura, char* nombre)
{
	int retorno = 0;

	if(pAuxEstructura != NULL)
	{
		strcpy(pAuxEstructura->nombre, nombre);

		retorno = 1;
	}

    return retorno;
}


int receta_setIdIngrediente(S_receta* pAuxEstructura, int id_ingrediente)
{
	int retorno = 0;

	if(pAuxEstructura != NULL)
	{
		pAuxEstructura->id_ingrediente = id_ingrediente;

		retorno = 1;
	}

    return retorno;
}

int receta_setCantidad(S_receta* pAuxEstructura, int cantidad)
{
	int retorno = 0;

	if(pAuxEstructura != NULL)
	{
		pAuxEstructura->cantidad = cantidad;

		retorno = 1;
	}

    return retorno;
}
