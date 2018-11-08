#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"


int cargarListaSecuencial(int lista[], int largo)
{
    int i;
    int flag;

    //Carga secuencial
    for(i=0;i<largo;i++)
    {
        lista[i]= getInt();

    }

    if(largo==i)
    {
        flag=1;//Se cargaron todos
    }

    return flag;

}

int mostrarLista(int lista[], int largo)
{
    int i;
    int flag=0;//No estan cargados

    for(i=0;i<largo;i++)
    {
        printf("%d-%d\n", i+1, lista[i]);
    }

    if(largo==i)
    {
        flag=1;//Se mostraron todos
    }

    return flag;
}

int obtenerMaximo(int lista[], int largo)
{
    int i;
    int maximo;

    for(i=0;i<largo;i++)
    {

        if(i==0) //Primer numero es máximo y mínimo. Uso i como flag
        {
            maximo= lista[i];
        }
        else
        {
            if(lista[i]>maximo)
            {
                    maximo=lista[i];
            }
        }
    }

    return maximo;
}

int obtenerMinimo(int lista[], int largo)
{
    int i;
    int minimo;

    for(i=0;i<largo;i++)
    {

        if(i==0) //Primer numero es máximo y mínimo. Uso i como flag
        {
            minimo= lista[i];
        }
        else
        {
            if(lista[i]<minimo)
            {
                    minimo=lista[i];
            }
        }
    }

    return minimo;
}

float calcularPromedio(int lista[], int largo)
{
    int i;
    int acumulador=0;
    float promedio;

    for(i=0;i<largo;i++)
    {
        acumulador+=lista[i];
    }

    promedio= (float)acumulador/largo;  //Casteo a float para no perder precisión decimal

    return promedio;
}

int modificarLista(int lista[], int largo)
{
    int indice;
    int flag=0;//No se modifico

    mostrarLista(lista, largo);


    printf("\nIngrese el indice: ");
    indice=getInt();

    while(indice-1>=largo || indice-1<0)
    {
        printf("-----------------------------\n");
        printf("Error no es un indice valido.");
        printf("\nIngrese el indice: ");
        indice=getInt();

    }

    printf("-----------------------------\n");
    printf("Ingrese el nuevo dato: ");
    lista[indice-1]=getInt();

    flag=1;//Se modifico


    return flag;
}

//Validar la cadena

int getInt()
{
    int numeroValidado;
    char buffer[64];

    fflush(stdin);
    fgets(buffer,sizeof(buffer),stdin); //stdin para que lea desde consola, segundo argum. limite de buffer
    buffer[strlen(buffer)-1]='\0';//para reemplazar el ultimo \n que queda con fgets

    while(esNumero(buffer)==0)
    {
        printf("-----------------------------\n");
        printf("Error. Debe ingresar un numero: ");
        fgets(buffer,sizeof(buffer),stdin);
        buffer[strlen(buffer)-1]='\0';
    }

    numeroValidado= atoi(buffer);//Pasa la cadena a int


    return numeroValidado;
}

int esNumero(char cadena[])
{
    int i=0;
    int flag=0;//No es numero

    while(cadena[i] != '\0')
    {
        if(cadena[i]<'0' || cadena[i]>'9') //Si no es un numero rompe
                break;
            i++;
    }

    if(cadena[i]=='\0')//Si llegó al final de la cadena
    {
        flag=1;//Es numero
    }

    return flag;
}

int validarRango(int numero, int minimo, int maximo)
{

    while(numero<minimo || numero>maximo)
    {
        printf("-----------------------------");
        printf("\nError. Ingrese un numero dentro del rango:");
        numero=getInt();
    }

    return numero;
}

/*
//Obtener numero y validar con punteros
int getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
    int flag;
    int numero; //donde voy a guardar el numero

    while(reintentos>0)
    {
        printf(mensaje);
        if(getInt(&numero)==1)
        {
            if(numero<=maximo && numero>=minimo)
            break;
        }

        fflush(stdin);
        reintentos--;
        printf(mensajeError);
    }

    if(reintentos==0)
    {
        flag=0; //Se acabaron los intentos
    }
    else
    {
        flag=1;//Se verifico el numero
        *pResultado = numero; //Se carga el numero
    }

    return flag;

}

int getInt(int* pResultado)
{
    int retorno=0;
    char buffer[64];

    fgets(buffer,sizeof(buffer),stdin); //stdin para que lea desde consola, segundo argum. limite de buffer
    buffer[strlen(buffer)-1]='\0';//para reemplazar el ultimo \n que queda con fgets

    if(esNumerica(buffer))
    {
        *pResultado = atoi(buffer);//Pasa la cadena a numero
        retorno=1;
    }


    return retorno;
}

int esNumerica(char* cadena)
{
    int retorno=-1;
    int i=0;

    if(cadena!=NULL)
    {
        while(cadena[i]!='\0')
        {
            if(cadena[i]<'0' || cadena[i]>'9') //Si no es un numero rompe
                break;
            i++;
        }

        if(cadena[i]=='\0')
            retorno=1;
    }

    return retorno;
}
*/



