#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "funciones.h"

int cargarCadena(char mensaje[], char cadena[])
{
    int flag=0;//No está cargada

    printf("%s: ", mensaje);
    fflush(stdin);
    gets(cadena);

    if(strlen(cadena)>0)
    {
        flag=1;
    }

    return flag;
}

int getCadenaNumeros(int* numeroEntero, char mensaje[], int minimo, int maximo)
{
    int flag=0;//No esta cargado
    char auxiliar[50]={};

    do
    {
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
    char auxiliar[50]={};

    cargarCadena(mensaje, auxiliar);

    while(esLetra(auxiliar)!=1)
    {
        printf("Error. No es valido.\n");
        cargarCadena(mensaje, auxiliar);
    }

    flag=1;

    strcpy(cadena,auxiliar);


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

int inicializarArrayEstructura(ePersona listaPersonas[],int longitud, int valor)
{
    int i;
    int flag=0;//No esta cargado

    for(i=0;i<longitud;i++)
    {
        listaPersonas[i].legajo=valor;
    }

    if(i==longitud)
    {
        flag=1;//Está cargado
    }

    return flag;

}

int agenda_buscarPrimeraOcurrencia(ePersona listaPersonas[], int longitud, int valor)
{
    int i;
    int retorno=-1;

    for(i=0;i<longitud;i++)
    {
        if(listaPersonas[i].legajo==valor)
        {
            retorno=i;
            break;
        }
    }

    return retorno;
}

int agenda_mostrarLista(ePersona listaPersonas[], int longitud)
{
    int i;
    int flag=0;//No mostró todo

    for(i=0;i<longitud; i++)
    {
        if(listaPersonas[i].legajo!=-1)
        {
            printf("%-15d %-15s %-15s\n",listaPersonas[i].legajo, listaPersonas[i].nombre, listaPersonas[i].apellido);
        }
    }

    if(i==longitud)
    {
        flag=1;//Mostró todo
    }

    return flag;
}

int agenda_ordenarListaApellidos(ePersona listaPersonas[], int longitud)
{
    int i;
    int j;
    int flag=0;//No está ordenado

    //Creo una estructura auxiliar
    ePersona auxiliarLista;



    for(i=1;i<longitud;i++)
    {
        if(listaPersonas[i].legajo==-1)//Si está vacío
        {
            continue;//Paso a la proxima iteración
        }

        //Empiezo en indice 1 y voy avanzando hacia la derecha con cada iteración
        auxiliarLista=listaPersonas[i];
        j=i-1;

        //Comparo con el de la izquierda
        while(j>=0 && stricmp(auxiliarLista.apellido,listaPersonas[j].apellido)<0)//Apellido A-Z
        {
            listaPersonas[j+1] = listaPersonas[j];//muevo todo para la derecha
            j--;
        }

        //inserto en la ultima posición a la izquierda
        listaPersonas[j+1]=auxiliarLista;
    }

    if(i==longitud)
    {
        flag=1;
    }

    return flag;
}




