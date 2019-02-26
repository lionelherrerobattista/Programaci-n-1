#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "funciones.h"
#define TAM_BUFFER 30


void mostrarMenu()
{
    printf("---------------------------\n");
    printf("1-Tramite urgente\n");
    printf("2-Tramite regular\n");
    printf("3-Proximo cliente\n");
    printf("4-Listar\n");
    printf("5-Informar\n");
    printf("6-Salir\n");
    printf("---------------------------\n");

}

int esInt(char* auxiliar)
{
    int i;
    int flag=1;//1 es entero
    int contadorNegativo=0;//cuenta los '-'

    for(i=0; i<strlen(auxiliar); i++)
    {
        if(*(auxiliar+i)<'0' || *(auxiliar+i)>'9')
        {
            if(*(auxiliar+i)=='-')
            {
                contadorNegativo++;
            }


            if(contadorNegativo>1 || *(auxiliar+i)!='-')
            {
                flag=0;//No es numero entero
                break;
            }
        }
    }

    return flag;
}

long pedirCadenaInt(char* mensaje, long minimo, long maximo)
{
    int flag=0;//No esta cargado
    char* auxiliar;
    unsigned int numeroAuxiliar;

    auxiliar=(char*)malloc(sizeof(char)*TAM_BUFFER);

    do
    {
        cargarCadena(mensaje, auxiliar);

        while(esInt(auxiliar)!=1)
        {
            printf("Error. No es un numero valido.\n");
            cargarCadena(mensaje, auxiliar);
        }

        //strtoul convierte a long usar para > int
        numeroAuxiliar=strtoul(auxiliar,NULL,10);//*Tomo el valor

        if(numeroAuxiliar>=minimo && numeroAuxiliar<=maximo)
        {
            flag=1;//Cumple con las condiciones. Sale de la iteracion.
        }
        else
        {
            printf("Fuera de rango.\n");
        }


    }while(flag==0);

    free(auxiliar);


    return numeroAuxiliar;

}

int esLetra(char* auxiliar)
{
    int i;
    int flag=1;//1 es char

    for(i=0;i<strlen(auxiliar);i++)
    {
        if((*(auxiliar+i)!=' ') && (*(auxiliar+i)<'A' || *(auxiliar+i)>'Z') && (*(auxiliar+i)<'a' || *(auxiliar+i)>'z')) //Si hay espacio tambien es valido como letra
        {
            flag=0;//0 no es char
            break;
        }
    }

    return flag;
}

int esAlfanumerico(char* auxiliar)
{
    int i;
    int flag=1;//es alfanumerico

    //Si es todo numero o todo letras no es alfanumérico
    if(esLetra(auxiliar)==1 || esInt(auxiliar)==1)
    {
        flag=0;
    }

    for(i=0;i<strlen(auxiliar);i++)
    {
            if(((*(auxiliar+i)!=' ') && (*(auxiliar+i)<'A' || *(auxiliar+i)>'Z') && (*(auxiliar+i)<'a' || *(auxiliar+i)>'z'))
                && (*(auxiliar+i)<'0' || *(auxiliar+i)>'9') && (*(auxiliar+i)=='/'))
            {
                flag=0;//No es alfanumerico
                break;
            }
    }

    return flag;
}

int pedirCadenaLetras(char* mensaje, char* cadena)
{
    int flag=0;//No cargo
    char* auxiliar;

    if(cadena!=NULL)
    {
        auxiliar=(char*)malloc(sizeof(char)*TAM_BUFFER);

        cargarCadena(mensaje, auxiliar);

        while(esAlfanumerico(auxiliar)!=1)
        {
            printf("Error. No es valido.\n");
            cargarCadena(mensaje, auxiliar);
        }

        strcpy(cadena, auxiliar);


        if(stricmp(cadena, auxiliar)==0)
        {
            flag=1;//Cargo la cadena
        }

        free(auxiliar);

    }

    return flag;

}
//Carga la cadena
int cargarCadena(char* mensaje, char* cadena)
{
    int flag=0;//No está cargada

    if(cadena!=NULL)
    {

        printf("%s: ", mensaje);
        fflush(stdin);

        //Para no escribir de más en memoria uso fgets
        //(limita lo que se puede ingresar)
        fgets(cadena,sizeof(char)*TAM_BUFFER,stdin);

        //Agregar '\0' al final cuando cadena < al buffer
        //para que pueda validar (porque fgets escribe '\n' al final)
        if(strlen(cadena)<TAM_BUFFER-1)
        {
            *(cadena+(strlen(cadena)-1))='\0';
        }


        if(strlen(cadena)>0)
        {
            flag=1;//Está cargada
        }
    }

    return flag;
}
