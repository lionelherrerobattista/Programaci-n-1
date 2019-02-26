#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "parser.h"



//Parser logs
int archivo_cargarDesdeTexto(char* nombreArchivo, LinkedList* nombreLista)
{
    FILE* pArchivo;
    //Estructura auxiliar
    S_LogEntry* pAuxEstructura;

    retorno=-1;//No cargó

    //Variables auxiliares de estructura
    char auxFecha[32];
    char auxHora[32];
    char auxId[32];
    char auxGravedad[32];
    char auxMensaje[64];

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
                cantidadDatos=fscanf(pArchivo,"%[^;];%[^;];%[^;];%[^;];%[^\n]\n",auxFecha,auxHora,auxId,
                                     auxGravedad,auxMensaje);

                //Puedo hacer 1 falsa lectura:
                /*
                if(cantidadDatos==5 && flag==0)
                {
                    flag==1

                }*/

                if(cantidadDatos==5) /*&& flag==1)*///Compruebo que se haya copiado toda la linea
                {
                        //Creo una estructura en memoria
                        pAuxEstructura=newLog();

                        //Cargo los campos en la estructura (Hacer funcion que devuelva estructura cargada)
                        pAuxEstructura=cargarEstructuraArchivo;
                        strcpy(pAuxEstructura->date, auxFecha);
                        strcpy(pAuxEstructura->time, auxHora);
                        pAuxEstructura->serviceId=atoi(auxId);
                        pAuxEstructura->gravedad=atoi(auxGravedad);
                        strcpy(pAuxEstructura->msg,auxMensaje);

                        //Lo agrego a la lista
                        ll_add(nombreLista, pAuxEstructura);
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

int archivo_cargarDesdeBinario(char* nombreArchivo, LinkedList* nombreLista)
{
    FILE* pArchivo;

    //Estructura auxiliar
    S_LogEntry* pAuxEstructura;

    int retorno=-1;//No cargó

    if(nombreLista!=NULL)
    {

        pArchivo=fopen(nombreArchivo,"r");


        if(pArchivo!=NULL)
        {
            do
            {
                //Creo una estructura en memoria
                pAuxEstructura=newLog();

                //Copio los datos del archivo
                fread(pAuxEstructura, sizeof(S_LogEntry), 1, pArchivo);

                //Lo agrego a la lista
                ll_add(nombreLista, pAuxEstructura);

            }while(!feof(pArchivo));//Hasta el final del archivo

            //Cierro el archivo
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




//Crear archivos
int archivo_crearArchivoTexto(char* nombreArchivo, LinkedList* nombreLista)
{
    //puntero a estructura file
    FILE* pArchivo;

    int retorno=-1;//No cargó
    //variables para iterar en la lista
    int i=0;

    //Creo los punteros a estructura auxiliares
    S_LogEntry* pAuxEstructura;

    if(nombreLista != NULL)
    {

        //Abro el archivo en modo escritura o crea uno nuevo si no existe
        pArchivo=fopen(nombreArchivo, "w");

        if(pArchivo!=NULL)//Valido que se haya podido abrir
        {
            //escribo los datos de la lista
            while(i<ll_len(nombreLista))
            {
                pAuxEstructura=ll_get(nombreLista, i);

                fprintf(pArchivo,"%s;%s;%s;%s\n",pAuxEstructura->date, pAuxEstructura->time,
                            auxService->name, pAuxEstructura->msg);

                i++;
            }

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

int archivo_crearArchivoBinario(char* nombreArchivo, LinkedList* nombreLista)
{
    //puntero a estructura file
    FILE* pArchivo;

    int retorno=-1;//No cargó

    //variables para iterar en la lista
    int i=0;

    //Creo los punteros a estructura auxiliares
    S_LogEntry* pAuxEstructura;

    //Abro el archivo binario en modo escritura o crea uno nuevo si no existe
    pArchivo=fopen(nombreArchivo, "wb");

    if(nombreLista =! NULL)
    {

        if(pArchivo!=NULL)//Valido que se haya podido abrir
        {
            //guardo las estructuras
            while(i<ll_len(nombreLista))
            {
                pAuxEstructura=ll_get(nombreLista, i);

                fwrite(pAuxEstructura, sizeof(S_LogEntry), 1, pArchivo);

                i++;
            }

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


