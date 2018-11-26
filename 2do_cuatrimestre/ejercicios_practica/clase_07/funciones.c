#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "funciones.h"

int cargarCadena(char mensaje[], char cadena[])
{
    int flag=0;//No está cargada

    printf("%s: ", mensaje);
    fflush(stdin);
    gets(cadena); //Pido la cadena y la guardo

    if(strlen(cadena)>0)
    {
        flag=1;
    }

    return flag;
}

int getCadenaNumeros(int* numeroEntero, char mensaje[], int minimo, int maximo)
{
    int flag=0;//No esta cargado
    char auxiliar[50]={}; //Donde se guarda el mensaje para no alterar el contenido de mensaje



    do
    {
        //Llamo a la función para cargar la cadena
        cargarCadena(mensaje, auxiliar);

        while(esNumero(auxiliar)!=1)
        {
            printf("Error. No es un numero valido.\n");
            cargarCadena(mensaje, auxiliar);
        }

        *numeroEntero=atoi(auxiliar);//*Tomo el valor

        if(*numeroEntero>=minimo && *numeroEntero<=maximo)
        {
            flag=1;//Cumple con las condiciones. Sale de la iteracion.
        }
        else
        {
            printf("Fuera de rango.\n");
        }


    }while(flag==0);


    return flag;

}

int getCadenaLetras(char cadena[], char mensaje[])
{
    int flag=0;//No esta cargado
    char auxiliar[50]={}; //Donde se guarda el mensaje para no alterar el contenido de mensaje

    //Llamo a la función para cargar la cadena
    cargarCadena(mensaje, auxiliar);

    //Compruebo que este conformada solo por letras
    while(esLetra(auxiliar)!=1)
    {
        printf("Error. No es valido.\n");
        cargarCadena(mensaje, auxiliar);
    }

    flag=1; //Validada

    strcpy(cadena,auxiliar); //Paso los datos a la cadena


    return flag;

}

int esLetra(char auxiliar[])
{
    int i;
    int flag=1;//1 es char

    for(i=0;i<strlen(auxiliar);i++)
    {
        if((auxiliar[i]!=' ') && (auxiliar[i]<'A' || auxiliar[i]>'Z') && (auxiliar[i]<'a' || auxiliar[i]>'z')) //Si hay espacio tambien es valido como letra
        {
            flag=0;//0 no es char
            break;
        }
    }

    return flag;
}


int esNumero (char auxiliar[])
{
    int i;
    int flag=1;//1 es entero

    for(i=0; i<strlen(auxiliar); i++)
    {
        if(auxiliar[i]<'0' || auxiliar[i]>'9')
        {
            flag=0;
            break;
        }
    }

    return flag;
}

int inicializarArrayEnteros(int arrayEnteros[],int longitud, int valor)
{
    int i;
    int flag=0;//No esta cargado

    for(i=0;i<longitud;i++)
    {
        arrayEnteros[i]=valor;
    }

    if(i==longitud)
    {
        flag=1;//Está cargado
    }

    return flag;

}

int buscarPrimeraOcurrenciaInt(int arrayEnteros[], int longitud, int valor)
{
    int i;
    int retorno=-1;

    for(i=0;i<longitud;i++)
    {
        if(arrayEnteros[i]==valor)
        {
            retorno=i;
            break;
        }
    }

    return retorno;
}





