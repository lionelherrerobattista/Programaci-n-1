#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "persona.h"
#define TAM_BUFFER 32

//Pido al usuario
int pedirCadenaLetras(char* mensaje, char* cadena)
{
    int flag=0;
    char auxiliar[50];

    cargarCadena(mensaje, auxiliar);

    while(esLetra(auxiliar)!=1)
    {
        printf("Error. No es valido.\n");
        cargarCadena(mensaje, auxiliar);
    }

    strcpy(cadena, auxiliar);

    if(stricmp(cadena, auxiliar)==0)
    {
        flag=1;
    }

    return flag;

}

int pedirCadenaInt(char* mensaje, int minimo, int maximo)
{
    int flag=0;//No esta cargado
    char auxiliar[50]={};
    int numeroAuxiliar;

    do
    {
        cargarCadena(mensaje, auxiliar);

        while(esNumero(auxiliar)!=1)
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


    return numeroAuxiliar;

}

int cargarCadena(char* mensaje, char* cadena)
{
    int flag=0;//No está cargada

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
        flag=1;
    }

    return flag;
}

//Comprobaciones
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

//Setters
void persona_setName(ePersona* persona, char nombre[])
{

    strcpy(persona->nombre, nombre);

}

void persona_setAge(ePersona* persona, int edad)
{

    persona->edad=edad;

}

//Getters
int persona_getAge(ePersona* persona)
{
    return persona->edad;//Accedo al dato con operador flecha (puntero)
}

char* persona_getName(ePersona* persona)
{
    return persona->nombre;//Accedo al dato con operador flecha (puntero)
}

//Mostrar
void mostrarPersona(ePersona* persona)
{
    printf("-----------------------------------\n");
    printf("Nombre:%s\nEdad:%d\n", persona_getName(persona), persona_getAge(persona));

}


//Constructores
ePersona* crearLista(int sizeArray)
{

    ePersona* listaPersonas; //Puntero donde se guarda el array de estructuras

    //Creo el array de estructuras persona de forma dinámica:
    listaPersonas= (ePersona*)malloc(sizeArray * sizeof(ePersona));

    return listaPersonas;

}

int cargarPersona(ePersona* listaPersonas, ePersona persona, int* index, int* sizeArray)
{
    int flag=0;//No cargada

    if(listaPersonas!=NULL)
    {
        *(listaPersonas+*index)=persona; //puntero, tengo que usar operador * !!
        //Me muevo a la posición del siguiente indice
        *(index)+=1;//puntero, tengo que usar operador * !!

        //Me fijo si no está completo el array
        if(*index>=*sizeArray)
        {
            printf("\nRedefino el array\n");
            *(sizeArray)+=2; //puntero, tengo que usar operador * !!
            listaPersonas=(ePersona*) realloc(listaPersonas, *sizeArray * sizeof(ePersona));
        }

        flag=1;//Cargada
    }


    return flag;

}

