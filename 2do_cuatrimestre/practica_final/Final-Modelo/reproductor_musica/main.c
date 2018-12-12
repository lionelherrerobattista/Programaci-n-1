#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <conio.h>
#include "parser.h"
#include "usuarios.h"
#include "temas.h"
#include "LinkedList.h"

void mostrarInfoUsuario(eUsuario* auxUsuario);

int getNumber(void* pEstructura);
char* getString(void* pEstructura);

int main()
{
    int i;

    LinkedList* pListaUsuarios;
    LinkedList* pListaTemas;

    pListaUsuarios=ll_newLinkedList();
    pListaTemas=ll_newLinkedList();

    archivo_cargarUsuarios("usuarios.dat",pListaUsuarios);

    for(i=0;i<100;i++)
    {
        mostrarInfoUsuario(ll_get(pListaUsuarios, i));
    }

    system("pause");

    for(i=100;i<200;i++)
    {
        mostrarInfoUsuario(ll_get(pListaUsuarios, i));
    }


    return 0;
}

void mostrarInfoUsuario(eUsuario* auxUsuario)
{
    printf("%d,%s,%s,%s,%s,%s,%s \n", getNumber(auxUsuario), getString(auxUsuario), auxUsuario->email,
           auxUsuario->sexo, auxUsuario->pais, auxUsuario->password, auxUsuario->ip_address);
}

int getNumber(void* pEstructura)
{
    eUsuario* pAuxUsuario;
    int retorno;

    if(pEstructura!=NULL)
    {
        pAuxUsuario=pEstructura;
        retorno=pAuxUsuario->id;
    }

    return retorno;
}

char* getString(void* pEstructura)
{
    eUsuario* pAuxUsuario=NULL;

    if(pEstructura!=NULL)
    {
        pAuxUsuario=pEstructura;
    }


    return pAuxUsuario->nombre;
}

