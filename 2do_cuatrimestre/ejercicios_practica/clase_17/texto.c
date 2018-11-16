#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "texto.h"
#define TAM_BUFFER 50


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

void* pedirCadenaLetras(char mensaje[], char* cadena)
{

    char* auxiliar;

    auxiliar=(char*)malloc(sizeof(char)*TAM_BUFFER);

    cargarCadena(mensaje, auxiliar);

    while(esLetra(auxiliar)!=1)
    {
        printf("Error. No es valido.\n");
        cargarCadena(mensaje, auxiliar);
    }

    cadena=auxiliar;


    return cadena;

}

int cargarCadena(char* mensaje, char* cadena)
{
    int flag=0;//No está cargada

    printf("%s: ", mensaje);
    //Para no escribir de màs en memoria
    fgets(cadena,sizeof(char)*TAM_BUFFER,stdin);
    //Siempre agregar \0 al final para que pueda validar
    *(cadena+strlen(cadena)-1)='\0';

    if(strlen(cadena)>0)
    {
        flag=1;
    }

    return flag;
}

void* getDynamicString(char* mensaje, char* texto)
{
    /*char* auxiliar;

    auxiliar=(char*)malloc(sizeof(char)*TAM_BUFFER);*/

    cargarCadena(mensaje, texto);

    while(esLetra(texto)!=1)
    {
        printf("Error. No es valido.\n");
        cargarCadena(mensaje, texto);
    }


    return texto;

}

