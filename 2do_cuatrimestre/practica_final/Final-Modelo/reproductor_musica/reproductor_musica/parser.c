#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "parser.h"
#include "LinkedList.h"
#include "usuarios.h"
#include "temas.h"
#include "estadistica.h"

int archivo_cargarDesdeTexto(char* nombreArchivo, LinkedList* nombreLista)
{
    FILE* pArchivo;
    //Estructura auxiliar
    S_Usuario* pAuxEstructura;

    int retorno=-1;//No cargó
    int flag=0;

    //Variables auxiliares de estructura
    char auxId[32];
    char auxNombre[60];
    char auxEmail[60];
    char auxSexo[60];
    char auxPais[60];
    char auxPassword[150];
    char auxIpAddress[60];

    //Datos copiados
    int cantidadDatos=0;
    //int flag=0;//Flag para falsa lectura

    if(nombreLista!=NULL)
    {

        pArchivo=fopen(nombreArchivo,"r");


        if(pArchivo!=NULL)
        {
            do
            {
                //Copio los datos del archivo
                //Parser: todos los char menos: ';' y '\n' (al final)
                cantidadDatos=fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxEmail,
                                     auxSexo,auxPais, auxPassword, auxIpAddress);

                //Puedo hacer 1 falsa lectura:
                if(cantidadDatos==7 && flag==0)
                {
                    flag=1;
                }
                else
                {
                    if(cantidadDatos==7 && flag==1)//Compruebo que se haya copiado toda la linea
                    {
                            //Creo una estructura en memoria
                            pAuxEstructura=newUsuario();

                            //Cargo los campos en la estructura (Hacer funcion que devuelva estructura cargada)
                            cargarUsuario(pAuxEstructura, auxId, auxNombre, auxEmail, auxSexo, auxPais,
                                          auxPassword, auxIpAddress);

                            //Lo agrego a la lista
                            ll_add(nombreLista, pAuxEstructura);
                    }
                }



            }while(!feof(pArchivo));//Sigue iterando hasta el final del archivo

            fclose(pArchivo);

            retorno=1;//Cargo los datos
        }
        else
        {
            printf("No se pudo abrir el archivo.\n");
            retorno=0;//No se pudo abrir
        }
    }

    return retorno;

}

int archivo_cargarTema(char* nombreArchivo, LinkedList* nombreLista)
{
    FILE* pArchivo;
    //Estructura auxiliar
    S_Tema* pAuxEstructura;

    int retorno=-1;//No cargó
    int flag=0;

    //Variables auxiliares de estructura
    char auxId[32];
    char auxNombre[300];
    char auxArtista[300];


    //Datos copiados
    int cantidadDatos=0;
    //int flag=0;//Flag para falsa lectura

    if(nombreLista!=NULL)
    {

        pArchivo=fopen(nombreArchivo,"r");


        if(pArchivo!=NULL)
        {
            do
            {
                //Copio los datos del archivo
                //Parser: todos los char menos: ';' y '\n' (al final)
                cantidadDatos=fscanf(pArchivo,"%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxArtista);

                //Puedo hacer 1 falsa lectura:
                if(cantidadDatos==3 && flag==0)
                {
                    flag=1;
                }
                else
                {
                    if(cantidadDatos==3 && flag==1)//Compruebo que se haya copiado toda la linea
                    {
                            //Creo una estructura en memoria
                            pAuxEstructura=newTema();

                            //Cargo los campos en la estructura (Hacer funcion que devuelva estructura cargada)
                            tema_cargarTema(pAuxEstructura, auxId, auxNombre, auxArtista);

                            //Lo agrego a la lista
                            ll_add(nombreLista, pAuxEstructura);
                    }
                }



            }while(!feof(pArchivo));//Sigue iterando hasta el final del archivo

            fclose(pArchivo);

            retorno=1;//Cargo los datos
        }
        else
        {
            printf("No se pudo abrir el archivo.\n");
            retorno=0;//No se pudo abrir
        }
    }

    return retorno;

}

int archivo_cargarTemasMasEscuchados(char* nombreArchivo, LinkedList* nombreLista)
{
    FILE* pArchivo;
    //Estructura auxiliar
    S_Tema* pAuxEstructura;

    int retorno=-1;//No cargó
    int flag=0;

    //Variables auxiliares de estructura
    char auxId[32];
    char auxNombre[300];
    char auxArtista[300];
    char auxIdUsuario[300];
    char auxNombreUsuario[300];
    char auxPaisUsuario[300];


    //Datos copiados
    int cantidadDatos=0;
    //int flag=0;//Flag para falsa lectura

    if(nombreLista!=NULL)
    {

        pArchivo=fopen(nombreArchivo,"r");


        if(pArchivo!=NULL)
        {
            do
            {
                //Copio los datos del archivo
                //Parser: todos los char menos: ';' y '\n' (al final)
                cantidadDatos=fscanf(pArchivo,"%[^;];%[^;];%[^;];%[^;];%[^;];%[^\n]\n",auxIdUsuario, auxNombreUsuario, auxPaisUsuario,
                                     auxId, auxNombre, auxArtista);

                //Puedo hacer 1 falsa lectura:
                if(cantidadDatos==6 && flag==0)
                {
                    flag=1;
                }
                else
                {
                    if(cantidadDatos==6 && flag==1)//Compruebo que se haya copiado toda la linea
                    {
                            //Creo una estructura en memoria
                            pAuxEstructura=newTema();

                            //Cargo los campos en la estructura (Hacer funcion que devuelva estructura cargada)
                            tema_cargarTema(pAuxEstructura, auxId, auxNombre, auxArtista);

                            //Lo agrego a la lista
                            ll_add(nombreLista, pAuxEstructura);
                    }
                }



            }while(!feof(pArchivo));//Sigue iterando hasta el final del archivo

            fclose(pArchivo);

            retorno=1;//Cargo los datos
        }
        else
        {
            printf("No se pudo abrir el archivo.\n");
            retorno=0;//No se pudo abrir
        }
    }

    return retorno;

}

int archivo_cargarEstadistica(char* nombreArchivo, LinkedList* nombreLista)
{
    FILE* pArchivo;
    //Estructura auxiliar
    S_Estadistica* pAuxEstructura;

    int retorno=-1;//No cargó
    int flag=0;

    //Variables auxiliares de estructura
    char auxId[32];
    char auxNombre[300];
    char auxArtista[300];
    char auxIdUsuario[300];
    char auxNombreUsuario[300];
    char auxPaisUsuario[300];


    //Datos copiados
    int cantidadDatos=0;
    //int flag=0;//Flag para falsa lectura

    if(nombreLista!=NULL)
    {

        pArchivo=fopen(nombreArchivo,"r");


        if(pArchivo!=NULL)
        {
            do
            {
                //Copio los datos del archivo
                //Parser: todos los char menos: ';' y '\n' (al final)
                cantidadDatos=fscanf(pArchivo,"%[^;];%[^;];%[^;];%[^;];%[^;];%[^\n]\n",auxIdUsuario, auxNombreUsuario, auxPaisUsuario,
                                     auxId, auxNombre, auxArtista);

                //Puedo hacer 1 falsa lectura:
                if(cantidadDatos==6 && flag==0)
                {
                    flag=1;
                }
                else
                {
                    if(cantidadDatos==6 && flag==1)//Compruebo que se haya copiado toda la linea
                    {
                            //Creo una estructura en memoria
                            pAuxEstructura=newEstadistica();

                            //Cargo los campos en la estructura (Hacer funcion que devuelva estructura cargada)
                            strcpy(pAuxEstructura->nombreTema, auxNombre);
                            strcpy(pAuxEstructura->pais, auxPaisUsuario);

                            //Lo agrego a la lista
                            ll_add(nombreLista, pAuxEstructura);
                    }
                }



            }while(!feof(pArchivo));//Sigue iterando hasta el final del archivo

            fclose(pArchivo);

            retorno=1;//Cargo los datos
        }
        else
        {
            printf("No se pudo abrir el archivo.\n");
            retorno=0;//No se pudo abrir
        }
    }

    return retorno;

}

int archivo_crearArchivoTexto(char* nombreArchivo, LinkedList* listaUsuarios, LinkedList* listaTemas, int idUsuario, int idTema)
{
    //puntero a estructura file
    FILE* pArchivo;

    int retorno=-1;//No cargó
    int i;


    //Creo los punteros a estructura auxiliares
    S_Usuario* pAuxUsuario;
    S_Tema* pAuxTema;

    if(listaUsuarios != NULL && listaTemas!=NULL)
    {

        //Abro el archivo para agregar datos
        pArchivo=fopen(nombreArchivo, "a");

        if(pArchivo!=NULL)//Valido que se haya podido abrir
        {
            //Busco al usuario por id
            for(i=0; i < ll_len(listaUsuarios); i++)
            {
                pAuxUsuario=(S_Usuario*)ll_get(listaUsuarios, i);
                if(pAuxUsuario->id == idUsuario)
                {
                    break;
                }
            }

            //Busco al tema por id
            for(i=0; i < ll_len(listaTemas); i++)
            {
                pAuxTema=(S_Tema*)ll_get(listaTemas, i);
                if(pAuxTema->id == idTema)
                {
                    break;
                }
            }

            fprintf(pArchivo,"%d;%s;%s;%d;%s;%s\n",pAuxUsuario->id, pAuxUsuario->nombre,
                            pAuxUsuario->pais, pAuxTema->id, pAuxTema->nombre_tema,
                             pAuxTema->artista);

            //Cierro el archivo
            fclose(pArchivo);
            retorno=1;//Cargo los datos
        }
        else
        {
            printf("No se pudo crear el archivo.");
            retorno=0;//No se pudo abrir
        }
    }

    return retorno;

}
