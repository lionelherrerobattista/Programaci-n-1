#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "parser.h"
#include "logs.h"
#include "services.h"

S_Service* newService()
{
    //Declaro el puntero
    S_Service* pService = NULL;

    //Le asigno espacio en memoria dinámica
    pService = (S_Service*)malloc(sizeof(S_Service));

    return pService;
}

void cargarServices(S_Service* pAuxEstructura,char* auxId,char* auxName,char* auxEmail)
{
    if(pAuxEstructura != NULL)
    {
        pAuxEstructura->id=atoi(auxId);
        strcpy(pAuxEstructura->name, auxName);
        strcpy(pAuxEstructura->email, auxEmail);
    }
}

//Getters
int services_getId(void* pService)
{
    S_Service* pAuxService;
    int retorno;

    if(pService!=NULL)
    {
        pAuxService=pService;
        retorno=pAuxService->id;
    }

    return retorno;
}

char* services_getName(void* pService)
{
    S_Service* pAuxService=NULL;

    if(pService!=NULL)
    {
        pAuxService=pService;
    }


    return pAuxService->name;
}

char* services_getEmail(void* pService)
{
    S_Service* pAuxService=NULL;

    if(pService!=NULL)
    {
        pAuxService=pService;
    }


    return pAuxService->email;
}

void services_mostrarDatos(LinkedList* listaServices)
{
    int i;

    for(i=0; i<ll_len(listaServices);i++)
    {
        printf("%d----%s----%s\n", services_getId(ll_get(listaServices, i)),
                services_getName(ll_get(listaServices, i)), services_getEmail(ll_get(listaServices, i)));
    }

}
