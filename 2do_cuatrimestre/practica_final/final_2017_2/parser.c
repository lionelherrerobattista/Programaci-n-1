#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "parser.h"
#include "LinkedList.h"
#include "logs.h"
#include "services.h"




//Parser logs
int archivo_cargarLogs(char* nombreArchivo, LinkedList* nombreLista)
{
    //Puntero a la estructura file
    FILE* pArchivo;
    //Estructura auxiliar
    S_LogEntry* pAuxEstructura;
    int retorno = -1;//No cargó

    //Variables auxiliares de estructura
    char auxDate[32];
    char auxTime[32];
    char auxServiceId[32];
    char auxGravedad[32];
    char auxMensaje[65];

    //Datos copiados
    int cantidadDatos=0;
    //int flag=0;//Flag para falsa lectura

    //Compruebo que los punteros no vengan NULL
    if(nombreLista!=NULL)
    {

        pArchivo=fopen(nombreArchivo,"r");

        //Si se pudo abrir el archivo
        if(pArchivo!=NULL)
        {
            do
            {
                //Copio los datos del archivo
                //Parser: todos los char menos: ';' y '\n' (al final)
                cantidadDatos=fscanf(pArchivo,"%[^;];%[^;];%[^;];%[^;];%[^\n]\n",auxDate,auxTime,auxServiceId,
                                     auxGravedad,auxMensaje);

                if(cantidadDatos==5)//Compruebo que se haya copiado toda la linea
                {
                        //Creo una estructura auxiliar en memoria
                        pAuxEstructura=newLog();

                        //Cargo los campos en la estructura (funcion)
                        cargarLogs(pAuxEstructura, auxDate, auxTime, auxServiceId,
                                         auxGravedad, auxMensaje);

                        //La agrego a la lista
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

int archivo_cargarServices(char* nombreArchivo, LinkedList* nombreLista)
{
    //Puntero a la estructura file
    FILE* pArchivo;
    //Estructura auxiliar
    S_Service* pAuxEstructura;
    int retorno = -1;//No cargó

    //Variables auxiliares de estructura
    char auxId[32];
    char auxName[32];
    char auxEmail[65];


    //Datos copiados
    int cantidadDatos=0;

    //Compruebo que los punteros no vengan NULL
    if(nombreLista!=NULL)
    {

        pArchivo=fopen(nombreArchivo,"r");

        //Si se pudo abrir el archivo
        if(pArchivo!=NULL)
        {
            do
            {
                //Copio los datos del archivo
                //Parser: todos los char menos: ';' y '\n' (al final)
                cantidadDatos=fscanf(pArchivo,"%[^;];%[^;];%[^\n]\n",auxId,auxName,auxEmail);

                if(cantidadDatos==3)//Compruebo que se haya copiado toda la linea
                {
                        //Creo una estructura auxiliar en memoria
                        pAuxEstructura=newService();

                        //Cargo los campos en la estructura (funcion)
                        cargarServices(pAuxEstructura, auxId, auxName, auxEmail);

                        //La agrego a la lista
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


//Crear archivos
int archivo_crearArchivoTexto(char* nombreArchivo, LinkedList* listaLogs, LinkedList* listaServices)
{
    //puntero a estructura file
    FILE* pArchivo;

    int retorno=-1;//No cargó
    //variables para iterar en la lista
    int i=0;
    int j=0;

    //Creo los punteros a estructura auxiliares
    S_LogEntry* pAuxLog;
    S_Service* pAuxService;

    if(listaLogs != NULL && listaServices)
    {

        //Abro el archivo en modo escritura o crea uno nuevo si no existe
        pArchivo=fopen(nombreArchivo, "w");

        if(pArchivo!=NULL)//Valido que se haya podido abrir
        {
            //escribo los datos de la lista
            while(i<ll_len(listaLogs))
            {
                pAuxLog=ll_get(listaLogs, i);

                while(j<ll_len(listaServices))
                {
                    pAuxService = ll_get(listaServices, j);

                    if(pAuxLog->serviceId == pAuxService->id)
                    {
                        break;
                    }

                    j++;
                }

                fprintf(pArchivo,"%s;%s;%s;%s;%s\n",pAuxLog->date, pAuxLog->time,
                            pAuxService->name, pAuxLog->msg, pAuxService->email);

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

