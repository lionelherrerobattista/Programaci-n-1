#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "temas.h"
#include "LinkedList.h"
#include "validaciones.h"

S_Tema* newTema()
{
	//Creo un puntero del tipo estructura
    S_Tema* pTema=NULL;

	//Asigno espacio en memoria
    pTema = (S_Tema*)malloc(sizeof(S_Tema)); //casteo

	//retorna el puntero
    return pTema;
}

int tema_cargarTema(S_Tema* pTema, char* auxId, char* nombre_tema, char* artista)
{
    int retorno = 0;//no cargo
    int id;

    //compruebo que el puntero no sea null
    if(pTema != NULL)
    {
        id = atoi(auxId);
        //Seteo los datos en la estructura
        tema_setId(pTema, id);
        tema_setNombre(pTema, nombre_tema);
        tema_setArtista(pTema, artista);

        retorno = 1;//cargó
    }

    return retorno;
}

int tema_setId(S_Tema* pAuxEstructura, int id)
{
	int retorno = 0;

	if(pAuxEstructura != NULL)
	{
		pAuxEstructura->id = id;

		retorno = 1;
	}

    return retorno;
}

int tema_setNombre(S_Tema* pAuxEstructura, char* nombre)
{
	int retorno = 0;

	if(pAuxEstructura != NULL)
	{
		strcpy(pAuxEstructura->nombre_tema, nombre);

		retorno = 1;
	}

    return retorno;
}

int tema_setArtista(S_Tema* pAuxEstructura, char* nombre)
{
	int retorno = 0;

	if(pAuxEstructura != NULL)
	{
		strcpy(pAuxEstructura->artista, nombre);

		retorno = 1;
	}

    return retorno;
}

void tema_mostrarListaTemas(LinkedList* listaTemas)
{
    int i;
    S_Tema* pAuxTema;

    printf("%d", ll_len(listaTemas));

    for(i = 0; i < ll_len(listaTemas); i++)
    {
        pAuxTema = ll_get(listaTemas, i);

        printf("%d;%s;%s\n", temas_getId(pAuxTema), tema_getNombre(pAuxTema),
                tema_getArtista(pAuxTema));
    }

}

///Getters
int temas_getId(void* pEstructura)
{
    int retorno = 0;

    S_Tema* pAuxTema=NULL;

    if(pEstructura!=NULL)
    {
        pAuxTema=pEstructura;

        retorno = pAuxTema->id;
    }

    return retorno;
}

char* tema_getNombre(void* pEstructura)
{
    S_Tema* pAuxTema=NULL;

    if(pEstructura!=NULL)
    {
        pAuxTema=pEstructura;
    }


    return pAuxTema->nombre_tema;
}

char* tema_getArtista(void* pEstructura)
{
    S_Tema* pAuxTema=NULL;

    if(pEstructura!=NULL)
    {
        pAuxTema=pEstructura;
    }


    return pAuxTema->artista;
}

int tema_ordenarPorArtista(void* temaUno, void* temaDos)
{
    int retorno = 1;//no ordena

    S_Tema* pAuxTemaUno;
    S_Tema* pAuxTemaDos;

    pAuxTemaUno = temaUno;
    pAuxTemaDos = temaDos;

    if(stricmp(pAuxTemaUno->artista, pAuxTemaDos->artista)<0)//ordeno
    {
        retorno = -1; //ordeno
    }
    else
    {
        if(stricmp(pAuxTemaUno->artista, pAuxTemaDos->artista)==0)//si son iguales
        {
            if(stricmp(pAuxTemaUno->nombre_tema, pAuxTemaDos->nombre_tema)<0)//ordeno por nombre
            {
                retorno = -1; //ordeno
            }
        }
    }


    return retorno;
}

int tema_pedirTema(LinkedList* listaTemas)
{
    char tema[100];
    int retorno = -1;
    int i;

    S_Tema* pAuxTema;

    pedirCadenaLetras("Ingrese el tema que desea escuchar", tema);

    for(i = 0; i < ll_len(listaTemas); i++)
    {
        pAuxTema = (S_Tema*)ll_get(listaTemas, i);

        if(stricmp(pAuxTema->nombre_tema, tema) == 0)
        {
            retorno = pAuxTema->id;
            break;
        }
    }

    if(retorno == 0)
    {
        printf("No se encontró el tema.");
    }

    return retorno;
}

void tema_mostrarAutorConMasTemas(LinkedList* listaTemas)
{
    int i;
    int j;
    int contadorRepeticiones;
    int maxRepeticiones;
    int flag=0;

    S_Tema* pAuxTema;
    S_Tema* pAuxTemaSiguiente;

    printf("Autor con mas temas en el catalogo: ");
    if(listaTemas != NULL)
    {
        for(i = 0; i < ll_len(listaTemas)-1; i++)
        {
            pAuxTema = (S_Tema*)ll_get(listaTemas, i);

            contadorRepeticiones = 1;

            for( j = i+1; j < ll_len(listaTemas); j++) //Comparar con el que sigue a i (i+1)
            {
                pAuxTemaSiguiente = (S_Tema*)ll_get(listaTemas, j);

                if(stricmp(pAuxTema->artista, pAuxTemaSiguiente->artista) == 0)
                {
                    contadorRepeticiones++;
                }
            }

            if(flag == 0 || maxRepeticiones < contadorRepeticiones)
            {
                maxRepeticiones = contadorRepeticiones;
                flag = 1;
            }
        }

        //Muestro los artistas que mas se repiten:
        for(i = 0; i < ll_len(listaTemas)-1; i++)
        {
            pAuxTema = (S_Tema*)ll_get(listaTemas, i);

            contadorRepeticiones = 1;

            for(j = i+1; j < ll_len(listaTemas); j++)//Comparar con el que sigue a i (i+1)
            {
                pAuxTemaSiguiente = (S_Tema*)ll_get(listaTemas, j);

                if(stricmp(pAuxTema->artista, pAuxTemaSiguiente->artista) == 0)
                {
                    contadorRepeticiones++;
                }
            }

            if(maxRepeticiones == contadorRepeticiones)
            {
                printf("%s Cantidad de canciones:%d\n", pAuxTema->artista, maxRepeticiones);
            }
        }

    }
}

void tema_mostrarTemaMasEscuchado(LinkedList* listaTemasMasEscuchados)
{
    int i;
    int j;
    int contadorRepeticiones;
    int maxRepeticiones;
    int flag=0;

    S_Tema* pAuxTema;
    S_Tema* pAuxTemaSiguiente;

    printf("Tema mas escuchado:");
    if(listaTemasMasEscuchados != NULL)
    {
        for(i = 0; i < ll_len(listaTemasMasEscuchados)-1; i++)
        {
            pAuxTema = (S_Tema*)ll_get(listaTemasMasEscuchados, i);

            contadorRepeticiones = 1;

            for( j = i+1; j < ll_len(listaTemasMasEscuchados); j++) //Comparar con el que sigue a i (i+1)
            {
                pAuxTemaSiguiente = (S_Tema*)ll_get(listaTemasMasEscuchados, j);

                if(stricmp(pAuxTema->nombre_tema, pAuxTemaSiguiente->nombre_tema) == 0)
                {
                    contadorRepeticiones++;
                }
            }

            if(flag == 0 || maxRepeticiones < contadorRepeticiones)
            {
                maxRepeticiones = contadorRepeticiones;
                flag = 1;
            }
        }

        //Muestro los artistas que mas se repiten:
        for(i = 0; i < ll_len(listaTemasMasEscuchados)-1; i++)
        {
            pAuxTema = (S_Tema*)ll_get(listaTemasMasEscuchados, i);

            contadorRepeticiones = 1;

            for(j = i+1; j < ll_len(listaTemasMasEscuchados); j++)//Comparar con el que sigue a i (i+1)
            {
                pAuxTemaSiguiente = (S_Tema*)ll_get(listaTemasMasEscuchados, j);

                if(stricmp(pAuxTema->nombre_tema, pAuxTemaSiguiente->nombre_tema) == 0)
                {
                    contadorRepeticiones++;
                }
            }

            if(maxRepeticiones == contadorRepeticiones)
            {
                printf(" %s Cantidad de veces escuchado:%d\n", pAuxTema->nombre_tema, maxRepeticiones);
            }
        }

    }
}

void tema_mostrarAutorConMasRepeticiones(LinkedList* listaTemasMasEscuchados)
{
    int i;
    int j;
    int contadorRepeticiones;
    int maxRepeticiones;
    int flag=0;

    S_Tema* pAuxTema;
    S_Tema* pAuxTemaSiguiente;

    printf("Autor con mas repeticiones: ");
    if(listaTemasMasEscuchados != NULL)
    {
        for(i = 0; i < ll_len(listaTemasMasEscuchados)-1; i++)
        {
            pAuxTema = (S_Tema*)ll_get(listaTemasMasEscuchados, i);

            contadorRepeticiones = 1;

            for( j = i+1; j < ll_len(listaTemasMasEscuchados); j++) //Comparar con el que sigue a i (i+1)
            {
                pAuxTemaSiguiente = (S_Tema*)ll_get(listaTemasMasEscuchados, j);

                if(stricmp(pAuxTema->artista, pAuxTemaSiguiente->artista) == 0)
                {
                    contadorRepeticiones++;
                }
            }

            if(flag == 0 || maxRepeticiones < contadorRepeticiones)
            {
                maxRepeticiones = contadorRepeticiones;
                flag = 1;
            }
        }

        //Muestro los artistas que mas se repiten:
        for(i = 0; i < ll_len(listaTemasMasEscuchados)-1; i++)
        {
            pAuxTema = (S_Tema*)ll_get(listaTemasMasEscuchados, i);

            contadorRepeticiones = 1;

            for(j = i+1; j < ll_len(listaTemasMasEscuchados); j++)//Comparar con el que sigue a i (i+1)
            {
                pAuxTemaSiguiente = (S_Tema*)ll_get(listaTemasMasEscuchados, j);

                if(stricmp(pAuxTema->artista, pAuxTemaSiguiente->artista) == 0)
                {
                    contadorRepeticiones++;
                }
            }

            if(maxRepeticiones == contadorRepeticiones)
            {
                printf("%s Cantidad de veces escuchado:%d\n", pAuxTema->artista, maxRepeticiones);
            }
        }

    }
}
