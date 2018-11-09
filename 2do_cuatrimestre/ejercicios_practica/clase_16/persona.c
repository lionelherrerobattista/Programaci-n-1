#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "persona.h"

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

int esNumeroFloat (char auxiliar[])
{
    int i;
    int contadorPunto=0;
    int flag=1;//1 es float

    for(i=0; i<strlen(auxiliar); i++)
    {
        if(auxiliar[i]=='.')
        {
            contadorPunto++;
        }

        if((auxiliar[i]<'0' || auxiliar[i]>'9') && (auxiliar[i]!='.'))
        {
            flag=0;
            break;
        }

        if(contadorPunto>1)
        {
            flag=0;
            break;
        }
    }

    return flag;
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


float pedirCadenaFloat(char mensaje[], float minimo, float maximo)
{
    int flag=0;//No esta cargado
    //int i;
    //int j=0;
    //int longitud;
    //int contadorDecimales=0;

    char auxiliar[50];
    //char auxiliarEntero[50]={};
    //char auxiliarDecimal[50]={};

    //int numeroParteEnt;
    //float numeroParteDec;
    float numero;



    do
    {
        cargarCadena(mensaje, auxiliar);

        while(esNumeroFloat(auxiliar)!=1)
        {
            printf("Error. No es un numero valido.\n");
            cargarCadena(mensaje, auxiliar);
        }

        /*
        //Prueba sin atof:
        longitud=strlen(auxiliar);

        for(i=0;i<longitud;i++)
        {
            if(auxiliar[i]=='.')
            {
                break;
            }
        }
        printf("%d", i);

        longitud=i;

        for(i=0;i<longitud;i++)
        {
            auxiliarEntero[i]=auxiliar[i];//Bien

        }



        for(i=longitud+1;i<strlen(auxiliar);i++)
        {
            auxiliarDecimal[j]=auxiliar[i];
            j++;
            contadorDecimales++;
        }

        printf("\n%d",contadorDecimales);

        //Paso las partes de string a numero
        numeroParteEnt=atoi(auxiliarEntero);
        numeroParteDec=(float)atoi(auxiliarDecimal)/pow(10,contadorDecimales);//pow() a la potencia

        numero=numeroParteEnt+numeroParteDec;
        */

        numero=strtof(auxiliar, NULL);

        if(numero>=minimo && numero<=maximo)
        {
            flag=1;//Cumple con las condiciones. Sale de la iteracion.
        }
        else
        {
            printf("Fuera de rango.\n");
        }


    }while(flag==0);


    return numero;

}


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

//Setters
int person_setNombre(S_Person* pPerson, char nombre[])
{
    int flag=0;//No se cargo

    strcpy(pPerson->nombre, nombre);

    if(stricmp(pPerson->nombre, nombre)==0)
    {
        flag=1; //Se cargó
    }

    return flag;
}

int person_setEdad(S_Person* pPerson, int edad)
{
    int flag=0;//No se cargo

    pPerson->edad=edad;

    if(pPerson->edad==edad)
    {
        flag=1; //Se cargó
    }

    return flag;
}

int person_setDni(S_Person* pPerson, long int dni)
{
    int flag=0;//No se cargo

    pPerson->dni=dni;

    if(pPerson->dni==dni)
    {
        flag=1; //Se cargó
    }

    return flag;
}

//*******************************************

int loadPerson(S_Person* pPerson)
{
    int flag=0;
    int auxiliarEdad;
    char auxiliarNombre[50];
    long int auxiliarDni;

    if(pPerson!=NULL)
    {
        pedirCadenaLetras("Ingrese el nombre", auxiliarNombre);
        person_setNombre(pPerson, auxiliarNombre);

        auxiliarEdad=pedirCadenaInt("Ingrese la edad", 0, 110);
        person_setEdad(pPerson, auxiliarEdad);

        //Hacer funcion para validar DNI
        auxiliarDni=pedirCadenaInt("Ingrese el DNI", 100000, 99999999);
        person_setDni(pPerson, auxiliarDni);


    }

    return flag;
}

