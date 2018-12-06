#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "parser.h"
#include "LinkedList.h"
#include "logs.h"
#include "services.h"


//Parser logs
void archivo_cargarLog(LinkedList* listaLogs)
{
    FILE* pArchivo;
    S_LogEntry* auxLog;

    pArchivo=fopen("log.txt","r");

    char auxFecha[32];
    char auxHora[32];
    char auxId[32];
    char auxGravedad[32];
    char auxMensaje[64];

    int cantidadDatos=0;


    if(pArchivo!=NULL)
    {
        do
        {
            cantidadDatos=fscanf(pArchivo,"%[^;];%[^;];%[^;];%[^;];%[^\n]\n",auxFecha,auxHora,auxId,
                                 auxGravedad,auxMensaje);

            if(cantidadDatos==5)
            {
                    //Creo un log en memoria
                    auxLog=newLog();

                    //Cargo los campos en la estructura
                    strcpy(auxLog->date, auxFecha);
                    strcpy(auxLog->time, auxHora);
                    auxLog->serviceId=atoi(auxId);
                    auxLog->gravedad=atoi(auxGravedad);
                    strcpy(auxLog->msg,auxMensaje);

                    //Lo agrego a la lista
                    ll_add(listaLogs, auxLog);

            }


        }while(!feof(pArchivo));

        fclose(pArchivo);





    }

}

//Parser service
void archivo_cargarService(LinkedList* listaServicios)
{
    FILE* pArchivo;
    S_Service* auxService;

    pArchivo=fopen("services.txt","r");

    char auxId[32];
    char auxNombre[32];
    char auxEmail[64];


    int cantidadDatos=0;


    if(pArchivo!=NULL)
    {
        do
        {
            cantidadDatos=fscanf(pArchivo,"%[^;];%[^;];%[^\n]\n",auxId,auxNombre,auxEmail);

            if(cantidadDatos==3)
            {

                    auxService=newService();
                    auxService->id=atoi(auxId);
                    strcpy(auxService->name,auxNombre);
                    strcpy(auxService->email,auxEmail);
                    //Agrego a la lista
                    ll_add(listaServicios, auxService);

            }


        }while(!feof(pArchivo));

        fclose(pArchivo);


    }

}
