#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "funciones.h"
#include "LinkedList.h"
#include "parser.h"
#include "logs.h"
#define TAM_BUFFER 60

int pedirCadenaInt(char* mensaje, int minimo, int maximo)
{
    int flag=0;//No esta cargado
    char* auxiliar;
    int numeroAuxiliar;

    auxiliar=(char*)malloc(sizeof(char)*TAM_BUFFER);

    do
    {
        cargarCadena(mensaje, auxiliar);

        while(esInt(auxiliar)!=1)
        {
            printf("Error. No es un numero valido.\n");
            cargarCadena(mensaje, auxiliar);
        }

        numeroAuxiliar=atoi(auxiliar);//*Tomo el valor

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



void mostrarMenu()
{
    printf("---------------------------\n");
    printf("1-Leer Log\n");
    printf("2-Procesar informacion\n");
    printf("3-Mostrar estadisticas\n");
    printf("4-Salir\n");
    printf("---------------------------\n");

}


