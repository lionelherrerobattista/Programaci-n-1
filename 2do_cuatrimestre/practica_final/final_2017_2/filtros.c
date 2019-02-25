#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "logs.h"
#include "services.h"
#include "parser.h"
#include "LinkedList.h"



int filtrarWarnings(LinkedList* listaLogs, LinkedList* listaServices)
{
    int i; //busca los logs
    int j; //busca los warnings
    int total = 0;

    LinkedList* listaLogsWarnings;
    LinkedList* listaServicesWarnings;

    S_LogEntry* pAuxLog = NULL;
    S_Service* pAuxService = NULL;

    listaLogsWarnings = ll_newLinkedList();
    listaServicesWarnings = ll_newLinkedList();

    pAuxLog = newLog();

    for(i=0; i<ll_len(listaLogs); i++)
    {
        pAuxLog = ll_get(listaLogs, i);

        if(pAuxLog->gravedad == 3 && pAuxLog->serviceId != 45)
        {
            //Lo agrego a la otra lista
            ll_add(listaLogsWarnings, pAuxLog);
            for(j=0; j<ll_len(listaServices); j++)
            {
                pAuxService = ll_get(listaServices, j);

                if(pAuxLog->serviceId == pAuxService->id)
                {
                    ll_add(listaServicesWarnings, pAuxService);
                }
            }

            total++;
        }
    }

    archivo_crearArchivoTexto("warnings.txt", listaLogsWarnings, listaServicesWarnings);

    return total;
}

int filtrarGravedadMedia(LinkedList* listaLogs, LinkedList* listaServices)
{
    int i;
    int j;
    int contadorFallos = 0;

    S_LogEntry* pAuxLog;
    S_Service* pAuxService;

    if(listaLogs != NULL && listaServices != NULL)
    {
        for(i = 0; i < ll_len(listaLogs); i++)
        {
            pAuxLog = ll_get(listaLogs, i);

            if(pAuxLog->gravedad > 3 && pAuxLog->gravedad <= 7)
            {
                for(j = 0; j < ll_len(listaServices); j++)
                {
                    pAuxService = ll_get(listaServices, j);

                    if(pAuxLog->serviceId == pAuxService->id)
                    {
                        printf("%s;%s;%s;%s;%d\n", log_getDate(pAuxLog), log_getTime(pAuxLog),
                                services_getName(pAuxService), log_getMsg(pAuxLog),
                                 log_getGravedad(pAuxLog));
                    }
                }

                contadorFallos++;

            }
        }

    }

    return contadorFallos;
}

int filtrarErrors(LinkedList* listaLogs, LinkedList* listaServices)
{
    int i; //busca los logs
    int j; //busca los warnings
    int contadorFallos = 0;

    LinkedList* listaLogsErrors;
    LinkedList* listaServicesErrors;

    S_LogEntry* pAuxLog = NULL;
    S_Service* pAuxService = NULL;

    listaLogsErrors = ll_newLinkedList();
    listaServicesErrors = ll_newLinkedList();

    pAuxLog = newLog();

    for(i=0; i<ll_len(listaLogs); i++)
    {
        pAuxLog = ll_get(listaLogs, i);

        if(pAuxLog->gravedad > 7)
        {
            //Lo agrego a la otra lista
            ll_add(listaLogsErrors, pAuxLog);
            //Busco que el servicio que tiene el mismo id
            for(j=0; j<ll_len(listaServices); j++)
            {
                pAuxService = ll_get(listaServices, j);

                if(pAuxLog->serviceId == pAuxService->id)
                {
                    ll_add(listaServicesErrors, pAuxService);
                }
            }

            contadorFallos++;
        }
    }

    archivo_crearArchivoTexto("errors.txt", listaLogsErrors, listaServicesErrors);

    return contadorFallos;
}

int contarErroresMenores(LinkedList* listaLogs)
{
    int i;
    int contadorErroresMenores = 0;

    S_LogEntry* pAuxLog;

    for(i = 0; i < ll_len(listaLogs); i++)
    {
        pAuxLog = ll_get(listaLogs, i);

        if(pAuxLog->gravedad < 3)
        {
            contadorErroresMenores++;
        }
    }

    return contadorErroresMenores;

}

void mostrarServicioConMasErrores(LinkedList* listaLogs, LinkedList* listaServices)
{
    int i;
    int j;

    int contadorErrores=0;
    int masErrores=0;
    int flagPrimeraLectura = 1; //primera lectura

    S_LogEntry* pAuxLog;
    S_Service* pAuxService;

    for(i = 0; i < ll_len(listaServices); i++)
    {
        pAuxService = ll_get(listaServices, i);
        contadorErrores = 0;

        for(j = 0; j < ll_len(listaLogs); j++)
        {
            pAuxLog = ll_get(listaLogs, j);

            if(pAuxLog->serviceId == pAuxService->id)
            {
                contadorErrores++;
            }
        }

        if(flagPrimeraLectura == 1)
        {
            masErrores = contadorErrores;
            flagPrimeraLectura = 0;
        }
        else
        {
            if(masErrores < contadorErrores)
            {
                masErrores = contadorErrores;
            }
        }
    }

    for(i = 0; i < ll_len(listaServices); i++)
    {
        pAuxService = ll_get(listaServices, i);
        contadorErrores = 0;

        for(j = 0; j < ll_len(listaLogs); j++)
        {
            pAuxLog = ll_get(listaLogs, j);

            if(pAuxLog->serviceId == pAuxService->id)
            {
                contadorErrores++;
            }
        }

        if(contadorErrores == masErrores)
        {
            printf("Service con mas errores: %s Errores: %d\n", pAuxService->name, masErrores);
        }

    }


}

