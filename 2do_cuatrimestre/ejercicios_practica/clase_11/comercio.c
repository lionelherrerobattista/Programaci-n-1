#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <math.h>
#include "comercio.h"

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

//Getters

int getCadenaInt(char mensaje[], int minimo, int maximo)
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


float getCadenaFloat(char mensaje[], float minimo, float maximo)
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


int getCadenaLetras(char mensaje[], char cadena[])
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

int productos_setCodigo(eProducto listaProductos[], int indice, int codigo)
{
    int flag=0;//No se cargo

    listaProductos[indice].codigo = codigo;

    if(listaProductos[indice].codigo==codigo)
    {
        flag=1; //Se cargó
    }

    return flag;
}

int productos_setDescripcion(eProducto listaProductos[], int indice, char descripcion[])
{
    int flag=0; //No esta guardado

    strcpy(listaProductos[indice].descripcion,descripcion);

    if(stricmp(listaProductos[indice].descripcion, descripcion)==0)
    {
        flag=1;
    }

    return flag;
}

int productos_setImporte(eProducto listaProductos[], int indice, float importe)
{
    int flag=0;//No se cargo

    listaProductos[indice].importe = importe;

    if(listaProductos[indice].importe==importe)
    {
        flag=1; //Se cargó
    }

    return flag;
}

int productos_setCantidad(eProducto listaProductos[], int indice, int cantidad)
{
    int flag=0;//No se cargo

    listaProductos[indice].cantidad = cantidad;

    if(listaProductos[indice].cantidad==cantidad)
    {
        flag=1; //Se cargó
    }

    return flag;
}


int productos_inicializarArrayEstructura(eProducto listaProductos[],int longitud, int valor)
{
    int i;
    int flag=0;//No esta cargado

    for(i=0;i<longitud;i++)
    {
        listaProductos[i].estado=valor;
    }

    if(i==longitud)
    {
        flag=1;//Está cargado
    }

    return flag;

}

int productos_buscarEstado(eProducto listaProductos[], int longitud, int valor)
{
    int i;
    int retorno=-1;

    for(i=0;i<longitud;i++)
    {
        if(listaProductos[i].estado==valor)
        {
            retorno=i;
            break;
        }
    }

    return retorno;
}

int productos_buscarCodigo(eProducto listaProductos[], int longitud, int codigo)
{
    int i;
    int retorno=-1;

    for(i=0;i<longitud;i++)
    {
        if(listaProductos[i].codigo==codigo)
        {
            retorno=i;
            break;
        }
    }

    return retorno;
}

void productos_mostrarLista(eProducto listaProductos[], int longitud)
{
    int i;


    for(i=0;i<longitud; i++)
    {
        if(listaProductos[i].estado!=-1)
        {
            printf("%d %s %.2f %d\n", listaProductos[i].codigo, listaProductos[i].descripcion,
                    listaProductos[i].importe, listaProductos[i].cantidad);
        }

    }
}
