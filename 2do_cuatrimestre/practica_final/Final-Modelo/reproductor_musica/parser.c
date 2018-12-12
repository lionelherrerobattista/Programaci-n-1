#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "parser.h"
#include "usuarios.h"
#include "temas.h"
#include "LinkedList.h"


int archivo_cargarUsuarios(char* nombreArchivo, LinkedList* listaUsuarios)
{
    FILE* pArchivo;
    //Estructura auxiliar
    eUsuario* pAuxUsuario;

    int retorno=-1;//No cargó

    //Variables auxiliares de estructura
    char auxId[100];
    char auxNombre[100];
    char auxEmail[100];
    char auxSexo[100];
    char auxPais[100];
    char auxPassword[100];
    char auxIp_address[100];


    //Datos copiados
    int cantidadDatos=0;
    int flag=0;//Flag para falsa lectura

    if(listaUsuarios!=NULL)
    {

        pArchivo=fopen(nombreArchivo,"r");


        if(pArchivo!=NULL)
        {
            do
            {
                //Copio los datos del archivo
                //Parser: todos los char menos: ';' y '\n' (al final)
                cantidadDatos=fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxId,
                                     auxNombre,auxEmail, auxSexo, auxPais, auxPassword, auxIp_address);

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
                            pAuxUsuario=newUsuario();

                            //Cargo los campos en la estructura (Hacer funcion que devuelva estructura cargada)

                            setNumber(atoi(auxId));
                            setString(auxNombre);
                            strcpy(pAuxUsuario->email,auxEmail);
                            strcpy(pAuxUsuario->sexo,auxSexo);
                            strcpy(pAuxUsuario->pais,auxPais);
                            strcpy(pAuxUsuario->password,auxPassword);
                            strcpy(pAuxUsuario->ip_address,auxIp_address);


                            //Lo agrego a la lista
                            ll_add(listaUsuarios, pAuxUsuario);
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


void setNumber(void* pAuxEstructura, int auxNumero)
{
    pAuxUsuario->id=atoi(auxId);
}

void setString(void* pAuxEstructura, char* auxChar)
{
    strcpy(pAuxUsuario->nombre,auxNombre);
}
