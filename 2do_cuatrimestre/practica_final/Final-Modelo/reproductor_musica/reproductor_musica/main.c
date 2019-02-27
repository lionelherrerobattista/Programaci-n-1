#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "LinkedList.h"
#include "validaciones.h"
#include "parser.h"
#include "usuarios.h"
#include "temas.h"
#include "estadistica.h"

void mostrarTemaSegunNacionalidad(LinkedList* listaEstadisticas);

int main()
{
    int opcion;
    int respuesta=0;
    int idUsusario;
    int idTema;

    LinkedList* listaUsuarios;
    LinkedList* listaTemas;
    LinkedList* listaTemasMasEscuchados;
    LinkedList* listaEstadistica;

    listaUsuarios = ll_newLinkedList();
    listaTemas = ll_newLinkedList();
    listaTemasMasEscuchados = ll_newLinkedList();
    listaEstadistica = ll_newLinkedList();

    //Cargo las listas:
    archivo_cargarDesdeTexto("usuarios.dat", listaUsuarios);
    archivo_cargarTema("temas.dat", listaTemas);

    do
    {
        mostrarMenu();
        opcion = pedirCadenaInt("Opcion", 0, 6);
        printf("---------------------------\n");

        switch(opcion)
        {
            case 1:
                //Pido la forma de ordenar
                respuesta = pedirCadenaInt("1-Ordenar por nombre.\n2-Ordenar por nacionalidad.\nOpcion", 1,2);
                if(respuesta == 1)
                {
                    ll_sort(listaUsuarios, usuario_ordenarPorNombre, 1);
                }
                else
                {
                    if(respuesta ==2)
                    {
                        ll_sort(listaUsuarios, usuario_ordenarPorNacionalidad, 1);
                    }
                }
                //Muestro la lista
                usuario_mostrarListaUsuarios(listaUsuarios);
                break;
            case 2:
                ll_sort(listaTemas, tema_ordenarPorArtista, 1);
                tema_mostrarListaTemas(listaTemas);
                break;
            case 3:
                idUsusario = usuario_comprobarUsuario(listaUsuarios);
                if(idUsusario != -1)
                {
                    idTema = tema_pedirTema(listaTemas);
                    if(idTema != -1)
                    {
                        printf("Reproduciendo tema.\n");
                    }
                }
                break;
            case 4:
                if(idUsusario != -1)
                {
                    if(idTema != -1)
                    {
                        archivo_crearArchivoTexto("estadistica.dat", listaUsuarios, listaTemas,
                                                  idUsusario, idTema);
                    }
                }
                break;
            case 5:
                archivo_cargarTemasMasEscuchados("estadistica.dat", listaTemasMasEscuchados);
                tema_mostrarTemaMasEscuchado(listaTemasMasEscuchados);
                tema_mostrarAutorConMasRepeticiones(listaTemasMasEscuchados);
                archivo_cargarEstadistica("estadistica.dat", listaEstadistica);
                mostrarTemaSegunNacionalidad(listaEstadistica);
                tema_mostrarAutorConMasTemas(listaTemas);
                break;
        }

    }while(opcion != 6);

    return 0;
}

void mostrarTemaSegunNacionalidad(LinkedList* listaEstadisticas)
{
    int i;
    int j;
    int contadorRepeticiones;
    int maxRepeticiones;
    int flag=0;

    S_Estadistica* pAuxAnterior;
    S_Estadistica* pAuxSiguiente;
    S_Estadistica* pAuxActual;


    printf("Nacionalidad: ");
    if(listaEstadisticas != NULL)
    {
        for(i = 0; i < ll_len(listaEstadisticas)-1; i++)
        {
            pAuxActual = (S_Estadistica*)ll_get(listaEstadisticas, i);

            contadorRepeticiones = 1;

            for( j = i+1; j < ll_len(listaEstadisticas); j++) //Comparar con el que sigue a i (i+1)
            {
                pAuxSiguiente = (S_Estadistica*)ll_get(listaEstadisticas, j);

                if(stricmp(pAuxActual->pais, pAuxSiguiente->pais) == 0)
                {
                    if(stricmp(pAuxActual->nombreTema, pAuxSiguiente->nombreTema)==0)
                    {
                        contadorRepeticiones++;
                    }

                }
            }

            if(flag == 0 || maxRepeticiones < contadorRepeticiones)
            {
                maxRepeticiones = contadorRepeticiones;
                flag = 1;
            }
        }

        //Muestro los artistas que mas se repiten:
        for(i = 0; i < ll_len(listaEstadisticas)-1; i++)
        {
            pAuxActual = (S_Estadistica*)ll_get(listaEstadisticas, i);

            contadorRepeticiones = 1;
            pAuxSiguiente = (S_Estadistica*)ll_get(listaEstadisticas, i+1);

            if(pAuxActual->pais != pAuxSiguiente->pais)
            {
                printf("%s\n", pAuxActual->pais);
            }

            for( j = i+1; j < ll_len(listaEstadisticas); j++) //Comparar con el que sigue a i (i+1)
            {
                pAuxSiguiente = (S_Estadistica*)ll_get(listaEstadisticas, j);

                if(stricmp(pAuxActual->pais, pAuxSiguiente->pais) == 0)
                {
                    if(stricmp(pAuxActual->nombreTema, pAuxSiguiente->nombreTema)==0)
                    {
                        contadorRepeticiones++;
                    }

                }
            }

            if(maxRepeticiones == contadorRepeticiones && pAuxActual->pais != pAuxSiguiente->pais)
            {
                printf("%s Cantidad de veces escuchado:%d\n", pAuxActual->nombreTema, maxRepeticiones);
            }
        }

    }
}




