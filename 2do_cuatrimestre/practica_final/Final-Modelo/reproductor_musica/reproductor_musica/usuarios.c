#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "usuarios.h"
#include "LinkedList.h"
#include "validaciones.h"

S_Usuario* newUsuario()
{
	//Creo un puntero del tipo estructura
    S_Usuario* pUsuario=NULL;

	//Asigno espacio en memoria
    pUsuario = (S_Usuario*)malloc(sizeof(S_Usuario)); //casteo

	//retorna el puntero
    return pUsuario;
}

int cargarUsuario(S_Usuario* pUsuario, char* auxId, char* nombre, char* email, char* sexo,
                  char* pais, char* password, char* ipAddress)
{
    int retorno = 0;//no cargo
    int id;

    //compruebo que el puntero no sea null
    if(pUsuario != NULL)
    {
        id = atoi(auxId);
        //Seteo los datos en la estructura
        usuario_setId(pUsuario, id);
        usuario_setNombre(pUsuario, nombre);
        usuario_setEmail(pUsuario, email);
        usuario_setSexo(pUsuario, sexo);
        usuario_setPais(pUsuario, pais);
        usuario_setPassword(pUsuario, password);
        usuario_setIpAddress(pUsuario, ipAddress);

        retorno = 1;//cargó
    }

    return retorno;
}

int usuario_setId(S_Usuario* pAuxEstructura, int id)
{
	int retorno = 0;

	if(pAuxEstructura != NULL)
	{
		pAuxEstructura->id = id;

		retorno = 1;
	}

    return retorno;
}

int usuario_setNombre(S_Usuario* pAuxEstructura, char* nombre)
{
	int retorno = 0;

	if(pAuxEstructura != NULL)
	{
		strcpy(pAuxEstructura->nombre, nombre);

		retorno = 1;
	}

    return retorno;
}
int usuario_setEmail(S_Usuario* pAuxEstructura, char* email)
{
	int retorno = 0;

	if(pAuxEstructura != NULL)
	{
		strcpy(pAuxEstructura->email, email);

		retorno = 1;
	}

    return retorno;
}

int usuario_setSexo(S_Usuario* pAuxEstructura, char* sexo)
{
	int retorno = 0;

	if(pAuxEstructura != NULL)
	{
		strcpy(pAuxEstructura->sexo, sexo);

		retorno = 1;
	}

    return retorno;
}

int usuario_setPais(S_Usuario* pAuxEstructura, char* pais)
{
	int retorno = 0;

	if(pAuxEstructura != NULL)
	{
		strcpy(pAuxEstructura->pais, pais);

		retorno = 1;
	}

    return retorno;
}

int usuario_setPassword(S_Usuario* pAuxEstructura, char* password)
{
	int retorno = 0;

	if(pAuxEstructura != NULL)
	{
		strcpy(pAuxEstructura->password, password);

		retorno = 1;
	}

    return retorno;
}

int usuario_setIpAddress(S_Usuario* pAuxEstructura, char* ipAddress)
{
	int retorno = 0;

	if(pAuxEstructura != NULL)
	{
		strcpy(pAuxEstructura->ip_address, ipAddress);

		retorno = 1;
	}

    return retorno;
}

void usuario_mostrarListaUsuarios(LinkedList* listaUsuarios)
{
    int i;
    S_Usuario* pAuxUsuario;

    for(i = 0; i < ll_len(listaUsuarios); i++)
    {
        pAuxUsuario = ll_get(listaUsuarios, i);

        printf("%d;%s;%s;%s;%s;%s;%s\n", usuarios_getId(pAuxUsuario), usuario_getNombre(pAuxUsuario),
                usuario_getEmail(pAuxUsuario), usuario_getSexo(pAuxUsuario), usuario_getPais(pAuxUsuario),
               usuario_getPassword(pAuxUsuario), usuario_getIpAddress(pAuxUsuario));
    }

}

///Getters
int usuarios_getId(void* pEstructura)
{
    int retorno = 0;

    S_Usuario* pAuxUsuario=NULL;

    if(pEstructura!=NULL)
    {
        pAuxUsuario=pEstructura;

        retorno = pAuxUsuario->id;
    }

    return retorno;
}

char* usuario_getNombre(void* pEstructura)
{
    S_Usuario* pAuxUsuario=NULL;

    if(pEstructura!=NULL)
    {
        pAuxUsuario=pEstructura;
    }


    return pAuxUsuario->nombre;
}

char* usuario_getEmail(void* pEstructura)
{
    S_Usuario* pAuxUsuario=NULL;

    if(pEstructura!=NULL)
    {
        pAuxUsuario=pEstructura;
    }


    return pAuxUsuario->email;
}

char* usuario_getSexo(void* pEstructura)
{
    S_Usuario* pAuxUsuario=NULL;

    if(pEstructura!=NULL)
    {
        pAuxUsuario=pEstructura;
    }


    return pAuxUsuario->sexo;
}

char* usuario_getPais(void* pEstructura)
{
    S_Usuario* pAuxUsuario=NULL;

    if(pEstructura!=NULL)
    {
        pAuxUsuario=pEstructura;
    }


    return pAuxUsuario->pais;
}

char* usuario_getPassword(void* pEstructura)
{
    S_Usuario* pAuxUsuario=NULL;

    if(pEstructura!=NULL)
    {
        pAuxUsuario=pEstructura;
    }


    return pAuxUsuario->password;
}

char* usuario_getIpAddress(void* pEstructura)
{
    S_Usuario* pAuxUsuario=NULL;

    if(pEstructura!=NULL)
    {
        pAuxUsuario=pEstructura;
    }


    return pAuxUsuario->ip_address;
}

int usuario_ordenarPorNombre(void* usuarioUno, void* usuarioDos)
{
    int retorno = 1;

    S_Usuario* pAuxUsuarioUno;
    S_Usuario* pAuxUsuarioDos;

    pAuxUsuarioUno = usuarioUno;
    pAuxUsuarioDos = usuarioDos;

    //estoy comparando con el de la izq
    if(stricmp(pAuxUsuarioUno->nombre, pAuxUsuarioDos->nombre)<0)
    {
        retorno = -1; //ordeno
    }

    return retorno;

}

int usuario_ordenarPorNacionalidad(void* usuarioUno, void* usuarioDos)
{
    int retorno = 1;//no ordena

    S_Usuario* pAuxUsuarioUno;
    S_Usuario* pAuxUsuarioDos;

    pAuxUsuarioUno = usuarioUno;
    pAuxUsuarioDos = usuarioDos;

    if(stricmp(pAuxUsuarioUno->pais, pAuxUsuarioDos->pais)<0)//ordeno
    {
        retorno = -1; //ordeno
    }
    else
    {
        if(stricmp(pAuxUsuarioUno->pais, pAuxUsuarioDos->pais)==0)//si son iguales
        {
            if(stricmp(pAuxUsuarioUno->nombre, pAuxUsuarioDos->nombre)<0)//ordeno por nombre
            {
                retorno = -1; //ordeno
            }
        }
    }


    return retorno;
}
int usuario_comprobarUsuario(LinkedList* listaUsuarios)
{
    int i;
    int retorno=-1; //no se encontro
    char nick[50];
    char password[300];

    S_Usuario* pAuxUsuario;

    pedirCadenaLetras("Ingrese su nick", nick);
    pedirCadenaLetras("Ingrese su password", password);


    for(i=0; i<ll_len(listaUsuarios); i++)
    {
        pAuxUsuario = (S_Usuario*)ll_get(listaUsuarios, i);

        if(stricmp(pAuxUsuario->nombre, nick)==0
           && stricmp(pAuxUsuario->password, password)==0)
        {
            retorno = pAuxUsuario->id;
            break;
        }
    }

    if(retorno == -1)
    {
        printf("Nick o password incorrectos\n");
    }

    return retorno;
}
