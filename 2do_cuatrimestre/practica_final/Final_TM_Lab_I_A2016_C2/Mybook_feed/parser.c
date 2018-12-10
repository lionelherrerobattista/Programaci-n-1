#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "parser.h"
#include "usuarios.h"
#include "posts.h"
#include "LinkedList.h"



int archivo_cargarUsuarios(char* nombreArchivo, LinkedList* listaUsuarios)
{
    FILE* pArchivo;
    //Estructura auxiliar
    eUsuario* pAuxUsuario;

    int retorno=-1;//No cargó

    //Variables auxiliares de estructura
    char auxId[32];
    char auxNick[32];
    char auxPopularidad[32];


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
                cantidadDatos=fscanf(pArchivo,"%[^,],%[^,],%[^\n]\n",auxId,auxNick,auxPopularidad);

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
                            pAuxUsuario=newUsuario();

                            //Cargo los campos en la estructura (Hacer funcion que devuelva estructura cargada)

                            pAuxUsuario->id_usuario= atoi(auxId);
                            strcpy(pAuxUsuario->nick,auxNick);
                            pAuxUsuario->popularidad=atoi(auxPopularidad);

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


int archivo_cargarPosts(char* nombreArchivo, LinkedList* listaPosts)
{
    FILE* pArchivo;
    //Estructura auxiliar
    ePost* pAuxPost;

    int retorno=-1;//No cargó

    //Variables auxiliares de estructura
    char auxIdMensaje[32];
    char auxMensaje[5000];
    char auxPopularidad[32];
    char auxIdUsuario[32];


    //Datos copiados
    int cantidadDatos=0;
    int flag=0;//Flag para falsa lectura

    if(listaPosts!=NULL)
    {

        pArchivo=fopen(nombreArchivo,"r");


        if(pArchivo!=NULL)
        {
            do
            {
                //Copio los datos del archivo
                //Parser: todos los char menos: ',' y '\n' (al final)
                cantidadDatos=fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^\n]\n",auxIdMensaje,auxIdUsuario,auxPopularidad,
                                     auxMensaje);

                //Puedo hacer 1 falsa lectura:

                if(cantidadDatos==4 && flag==0)
                {
                    flag=1;
                }
                else
                {


                    if(cantidadDatos==4 && flag==1)//Compruebo que se haya copiado toda la linea
                    {
                            //Creo una estructura en memoria
                            pAuxPost=newPost();

                            //Cargo los campos en la estructura (Hacer funcion que devuelva estructura cargada)

                            pAuxPost->id_mensaje=atoi(auxIdMensaje);
                            strcpy(pAuxPost->mensaje, auxMensaje);
                            pAuxPost->popularidad=atoi(auxPopularidad);
                            pAuxPost->id_usuario=atoi(auxIdUsuario);

                            //Lo agrego a la lista
                            ll_add(listaPosts, pAuxPost);
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

int archivo_crearArchivoTexto(char* nombreArchivo, LinkedList* listaUsuarios, LinkedList* listaPosts)
{
    //puntero a estructura file
    FILE* pArchivo;

    int retorno=-1;//No cargó
    //variables para iterar en la lista
    int i=0;
    int j=0;
    int k=0;//popularidad

    eUsuario* auxUsuarioI=NULL;
    eUsuario* auxUsuarioJ=NULL;

    ePost* auxPostI=NULL;
    ePost* auxPostJ=NULL;


    //Creo los punteros a estructura auxiliares
    eUsuario* pAuxUsuario;
    ePost* pAuxPost;

    if(listaUsuarios != NULL && listaPosts!=NULL)
    {

        //Abro el archivo en modo escritura o crea uno nuevo si no existe
        pArchivo=fopen(nombreArchivo, "w");

        if(pArchivo!=NULL)//Valido que se haya podido abrir
        {
            /*
            for(i=1;i<ll_len(listaUsuarios);i++)
            {
                //Empiezo en indice 1 y voy avanzando hacia la derecha con cada iteración
                auxUsuarioI=ll_get(listaUsuarios, i);
                j=i-1;

                auxUsuarioJ=ll_get(listaUsuarios, j);
                //Comparo con el de la izquierda
                while(j>=0 && auxUsuarioI->popularidad>auxUsuarioJ->popularidad)//Mas popular al menos
                {

                        ll_set(listaUsuarios, j+1, auxUsuarioJ);
                        //muevo todo para la derecha
                        j--;
                    auxUsuarioJ=ll_get(listaUsuarios, j);
                }

                //inserto en la ultima posición a la izquierda
                ll_set(listaUsuarios, j+1, auxUsuarioI);
            }
            */

            for(i=0;i<(ll_len(listaUsuarios)-1);i++)
            {
                auxUsuarioI=ll_get(listaUsuarios, i);//Guardo usuario en posc i

                for(j=i+1;j<ll_len(listaUsuarios);j++)
                {
                    auxUsuarioJ=ll_get(listaUsuarios, j);//Guardo usuario en posc j

                    if(auxUsuarioI->popularidad <= auxUsuarioJ->popularidad)
                    {
                        if(auxUsuarioI->popularidad==auxUsuarioJ->popularidad)
                        {


                            //poularidad mensaje mayor
                            for(k=0; k<ll_len(listaPosts);k++)
                            {
                                auxPostI=ll_get(listaPosts, k);

                                if(auxUsuarioI->id_usuario==auxPostI->id_usuario)
                                {
                                    break;
                                }
                            }

                            for(k=0; k<ll_len(listaPosts);k++)
                            {
                                auxPostJ=ll_get(listaPosts, k);

                                if(auxUsuarioJ->id_usuario==auxPostJ->id_usuario)
                                {
                                    break;
                                }

                            }

                            if(auxPostI->popularidad<auxPostJ->popularidad)
                            {
                                //Cambiar a donde apuntan los punteros
                                pAuxUsuario=auxUsuarioI;
                                auxUsuarioI=auxUsuarioJ;
                                auxUsuarioJ=pAuxUsuario;

                               //Pasarlos de nuevo a la lista
                                ll_set(listaUsuarios, i, auxUsuarioI);
                                ll_set(listaUsuarios, j, auxUsuarioJ);


                            }
                        }
                        else//Si no son iguales y el de la izquiera es menos popular
                        {
                                //Cambiar a donde apuntan los punteros
                                pAuxUsuario=auxUsuarioI;
                                auxUsuarioI=auxUsuarioJ;
                                auxUsuarioJ=pAuxUsuario;

                                ll_set(listaUsuarios, i, auxUsuarioI);
                                ll_set(listaUsuarios, j, auxUsuarioJ);

                        }
                    }
                }
            }


            //Prueba función sort
            /*
            ll_sort(listaUsuarios, ordenarPorNombre, 1);
            */
            i=0;
            //escribo los datos de la lista
            while(i<ll_len(listaUsuarios))
            {
                pAuxUsuario=ll_get(listaUsuarios, i);

                for(j=0; j<ll_len(listaPosts);j++)
                {
                    pAuxPost=ll_get(listaPosts, j);

                    if(pAuxUsuario->id_usuario==pAuxPost->id_usuario)
                    {
                        fprintf(pArchivo,"%d,%s,%d,%d,%s,%d\n",pAuxPost->id_mensaje, pAuxPost->mensaje,
                            pAuxPost->popularidad, pAuxUsuario->id_usuario, pAuxUsuario->nick, pAuxUsuario->popularidad);

                    }

                }


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

//Función sort para pasar a ll_sort
int ordenarPorNombre(void* pElementoI, void* pElementoJ)
{
    int retorno;
    eUsuario* pUsuarioEnI;
    eUsuario* pUsuarioEnJ;

    pUsuarioEnI=pElementoI;
    pUsuarioEnJ=pElementoJ;

    retorno=stricmp(pUsuarioEnI->nick, pUsuarioEnJ->nick);

    return retorno;


}
