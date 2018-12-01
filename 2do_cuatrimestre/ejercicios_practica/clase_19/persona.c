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

//Constructores
ePersona** persona_crearLista(int cantidadPersonas)
{
    ePersona** listaPersonas;

    listaPersonas=(ePersona**)malloc(sizeof(ePersona*)*cantidadPersonas);

    return listaPersonas;
}

ePersona* persona_crearPersona()
{
    ePersona* persona;

    persona=(ePersona*)malloc(sizeof(ePersona));

    return persona;
}


//Setters
void persona_cargarPersona(ePersona* persona)
{
    char auxNombre[50];
    char auxApellido[50];
    int auxEdad;

    pedirCadenaLetras("Ingrese el nombre", auxNombre);
    pedirCadenaLetras("Ingrese el apellido", auxApellido);
    auxEdad=pedirCadenaInt("Ingrese la edad", 0, 100);

    persona_setName(persona, auxNombre);
    persona_setSurname(persona, auxApellido);
    persona_setAge(persona, auxEdad);

}


void persona_setName(ePersona* persona, char name[])
{

    strcpy(persona->name, name);

}

void persona_setSurname(ePersona* persona, char surname[])
{

    strcpy(persona->surname, surname);

}

void persona_setAge(ePersona* persona, int age)
{

    persona->age=age;

}

//Archivo
int crearBinario(ePersona** listaPersonas, char nombreArchivo[], int totalPersonas)
{
    FILE* pArchivo;
    int i;
    int totalCargado;

    pArchivo=fopen(nombreArchivo, "wb");

    if(pArchivo!=NULL)
    {
        for(i=0;i<totalPersonas;i++)
        {
            totalCargado=fwrite(*(listaPersonas+i),sizeof(ePersona),1, pArchivo);
            //Usar operador:* !!!! (Para pasar el puntero a la estructura)
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
                break;
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


