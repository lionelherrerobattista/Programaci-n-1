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

int productos_setEstado(eProducto listaProductos[],int indice, int estado)
{
    int flag=0;//No se cargo

    listaProductos[indice].estado=estado;

    if(listaProductos[indice].estado==estado)
    {
        flag=1;//Se cargó
    }

    return flag;
}

//Getters
int persona_getCodigo(eProducto listaProductos[], int indice)
{

    return listaProductos[indice].codigo;
}

char* persona_getDescripcion(eProducto listaProductos[], int indice)
{

    return listaProductos[indice].descripcion;

}

int persona_getCantidad(eProducto listaProductos[], int indice)
{
    return listaProductos[indice].cantidad;

}

float persona_getImporte(eProducto listaProductos[], int indice)
{

    return listaProductos[indice].importe;

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

    printf("%-20s| %-20s| %-20s| %-20s|\n", "Codigo", "Descripcion", "Importe", "Cantidad");
    printf("---------------------------------------------------------------------------------------\n");

    for(i=0;i<longitud; i++)
    {
        if(listaProductos[i].estado!=-1)
        {
            printf("%-20d| %-20s| %-20.2f| %-20d|\n", persona_getCodigo(listaProductos, i),persona_getDescripcion(listaProductos, i),
                    persona_getImporte(listaProductos, i), persona_getCantidad(listaProductos, i));
        }

    }
}

int productos_ordenarListaDescripcion(eProducto listaProductos[], int longitud)
{
    int i;
    int j;
    int flag=0;//No está ordenado

    //Creo una estructura auxiliar
    eProducto auxiliarLista;



    for(i=1;i<longitud;i++)
    {
        if(listaProductos[i].estado==-1)//Si está vacío
        {
            continue;//Paso a la proxima iteración
        }

        //Empiezo en indice 1 y voy avanzando hacia la derecha con cada iteración
        auxiliarLista=listaProductos[i];
        j=i-1;

        //Comparo con el de la izquierda
        while(j>=0 && stricmp(auxiliarLista.descripcion,listaProductos[j].descripcion)>0)//Productos Z-A
        {
            listaProductos[j+1] = listaProductos[j];//muevo todo para la derecha
            j--;
        }

        //inserto en la ultima posición a la izquierda
        listaProductos[j+1]=auxiliarLista;
    }

    if(i==longitud)
    {
        flag=1;
    }

    return flag;
}

int productos_ordenarListaCantidad(eProducto listaProductos[], int longitud)
{
    int i;
    int j;
    int flag=0;//No está ordenado

    //Creo una estructura auxiliar
    eProducto auxiliarLista;



    for(i=1;i<longitud;i++)
    {
        if(listaProductos[i].estado==-1)//Si está vacío
        {
            continue;//Paso a la proxima iteración
        }

        //Empiezo en indice 1 y voy avanzando hacia la derecha con cada iteración
        auxiliarLista=listaProductos[i];
        j=i-1;

        //Comparo con el de la izquierda
        while(j>=0 && auxiliarLista.cantidad<listaProductos[j].cantidad)//Cantidad desc
        {
            listaProductos[j+1] = listaProductos[j];//muevo todo para la derecha
            j--;
        }

        //inserto en la ultima posición a la izquierda
        listaProductos[j+1]=auxiliarLista;
    }

    if(i==longitud)
    {
        flag=1;
    }

    return flag;
}

void productos_mostrarMenorImporte(eProducto listaProductos[], int longitud)
{
    int i;
    int flag=0;//Primera iteración
    float menorImporte;

    //Busco el menor importe
    for(i=0; i<longitud; i++)
    {
        if(listaProductos[i].estado==-1)
        {
            continue;
        }
        else
        {

            if(flag==0 || menorImporte>listaProductos[i].importe)
            {
                    menorImporte=listaProductos[i].importe;
                    flag=1;
            }
        }


    }
    printf("****************PRODUCTOS DE MENOR IMPORTE************************\n");
    printf("%-20s| %-20s| %-20s| %-20s|\n", "Codigo", "Descripcion", "Importe", "Cantidad");
    printf("---------------------------------------------------------------------------------------\n");

    //Muestro todos los productos que son == a menor importe
    for(i=0; i<longitud; i++)
    {
        if(listaProductos[i].estado==-1)
        {
            continue;
        }
        else
        {
            //Comparacion de lo que quiero mostrar
            if(listaProductos[i].importe==menorImporte)
            {
                    printf("%-20d| %-20s| %-20.2f| %-20d|\n", persona_getCodigo(listaProductos, i),persona_getDescripcion(listaProductos, i),
                        persona_getImporte(listaProductos, i), persona_getCantidad(listaProductos, i));
            }
        }

    }

}


void productos_mostrarSuperanPromedio(eProducto listaProductos[], int longitud)
{
    int i;
    int contadorProductos;
    float acumuladorImporte=0;
    float importePromedio;


    //Calculo el promedio
    for(i=0; i<longitud; i++)
    {
        if(listaProductos[i].estado==-1)
        {
            continue;
        }
        else
        {
            acumuladorImporte+=listaProductos[i].importe;
            contadorProductos++;
        }
    }

    importePromedio=acumuladorImporte/contadorProductos;


    printf("************PRODUCTOS QUE SUPERAN EL IMPORTE PROMEDIO*******************\n");
    printf("%-15s| %-15s| %-15s| %-15s|\n", "Codigo", "Descripcion", "Importe", "Cantidad");
    printf("-------------------------------------------------------------------------------\n");

    //Busco los productos que superan el importe promedio y los muestro
    for(i=0; i<longitud; i++)
    {
        if(listaProductos[i].estado==-1)
        {
            continue;
        }
        else
        {
            if(listaProductos[i].importe>importePromedio)
            {
                    printf("%-20d| %-20s| %-20.2f| %-20d|\n", persona_getCodigo(listaProductos, i),persona_getDescripcion(listaProductos, i),
                        persona_getImporte(listaProductos, i), persona_getCantidad(listaProductos, i));
            }
        }

    }

}

