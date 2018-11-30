#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "persona.h"

//Pido al usuario
int pedirCadenaLetras(char mensaje[], char cadena[])
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

int pedirCadenaInt(char mensaje[], int minimo, int maximo)
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
void persona_setName(ePersona listaPersonas[], char name[], int index)
{

    strcpy(listaPersonas[index].name, name);

}

void persona_setSurname(ePersona listaPersonas[], char surname[], int index)
{

    strcpy(listaPersonas[index].surname, surname);

}

void persona_setAge(ePersona listaPersonas[], int age, int index)
{

    listaPersonas[index].age=age;

}

//Archivo
int crearBinario(ePersona listaPersonas[], char nombreArchivo[], int totalPersonas)
{
    FILE* pArchivo;
    int i;
    int totalCargado;

    pArchivo=fopen(nombreArchivo, "ab+"); //append binary

    if(pArchivo!=NULL)
    {
        for(i=0;i<totalPersonas;i++)
        {
            totalCargado=fwrite(&listaPersonas[i],sizeof(ePersona),totalPersonas, pArchivo);
        }
    }

    fclose(pArchivo);

    return totalCargado;
}

//Buscar
ePersona* persona_buscarApellido(char nombreArchivo[], char apellido[], int cantidadPersonas)
{
    FILE* pArchivo;
    int flag=0;//No se encontró a la persona

    //Creo un puntero auxiliar del tipo ePersona
    ePersona* auxPersona;
    //Le asigno espacio en memoria
    auxPersona=(ePersona*)malloc(sizeof(ePersona));

    pArchivo=fopen(nombreArchivo, "rb");

    if(pArchivo!=NULL)
    {
        while(!feof(pArchivo))
        {
            //Guardo la estructura 1 por 1
            fread(auxPersona, sizeof(ePersona), 1, pArchivo);

            //Comparo los apellidos
            if(stricmp(auxPersona->surname, apellido)==0)
            {
                flag=1;
            }
        }
    }

    fclose(pArchivo);

    if(flag==0)
    {
        free(auxPersona);
        auxPersona=NULL;
    }

    return auxPersona;
}


