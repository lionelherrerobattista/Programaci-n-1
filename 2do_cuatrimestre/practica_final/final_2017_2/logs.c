#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "parser.h"
#include "logs.h"

S_LogEntry* newLog()
{
    //Declaro el puntero
    S_LogEntry* pLogEntry = NULL;

    //Le asigno espacio en memoria dinámica
    pLogEntry = (S_LogEntry*)malloc(sizeof(S_LogEntry));

    return pLogEntry;

}

void cargarLogs(S_LogEntry* pAuxEstructura,char* auxDate,char* auxTime,char* auxServiceId,char* auxGravedad,char* auxMsg)
{

    strcpy(pAuxEstructura->date, auxDate);
    strcpy(pAuxEstructura->time, auxTime);
    pAuxEstructura->serviceId=atoi(auxServiceId);
    pAuxEstructura->gravedad=atoi(auxGravedad);
    strcpy(pAuxEstructura->msg,auxMsg);

}

//Getters
int log_getServiceId(S_LogEntry* pLogEntry)
{
    S_LogEntry* pAuxLog;
    int retorno;

    if(pLogEntry!=NULL)
    {
        pAuxLog=pLogEntry;
        retorno=pAuxLog->serviceId;
    }

    return retorno;
}

int log_getGravedad(S_LogEntry* pLogEntry)
{
    S_LogEntry* pAuxLog;
    int retorno;

    if(pLogEntry!=NULL)
    {
        pAuxLog=pLogEntry;
        retorno=pAuxLog->gravedad;
    }

    return retorno;
}

char* log_getDate(S_LogEntry* pLogEntry)
{
    S_LogEntry* pAuxLog=NULL;

    if(pLogEntry!=NULL)
    {
        pAuxLog=pLogEntry;
    }


    return pAuxLog->date;
}

char* log_getTime(S_LogEntry* pLogEntry)
{
    S_LogEntry* pAuxLog=NULL;

    if(pLogEntry!=NULL)
    {
        pAuxLog=pLogEntry;
    }


    return pAuxLog->time;
}

char* log_getMsg(S_LogEntry* pLogEntry)
{
    S_LogEntry* pAuxLog=NULL;

    if(pLogEntry!=NULL)
    {
        pAuxLog=pLogEntry;
    }


    return pAuxLog->msg;
}


void log_mostrarDatos(LinkedList* lista)
{
    int i;

    for(i=0; i<ll_len(lista);i++)
    {
        printf("%s----%s----%d----%d----%s\n", log_getDate(ll_get(lista, i)),
                log_getTime(ll_get(lista, i)), log_getServiceId(ll_get(lista, i)), log_getGravedad(ll_get(lista, i)),
                  log_getMsg(ll_get(lista, i)));
    }

}
