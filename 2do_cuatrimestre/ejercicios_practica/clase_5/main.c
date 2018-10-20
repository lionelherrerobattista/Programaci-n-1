#include <stdio.h>
#include <stdlib.h>
#define TAM 5

//Solicitar al usuario 5 números,
//permitir listarlos por pantalla indicando el máximo, el mínimo y el promedio.
//Permitir Modificar el valor de cualquiera de los números cargados
// indicando el índice del mismo y su nuevo valor.

int mostrarLista(int lista[], int largo);
int cargarListaSecuencial(int lista[], int largo);
int obtenerMaximo(int lista[]);
int obtenerMinimo(int lista[]);
float calcularPromedio(int lista[], int largo);
int modificarLista(int lista[], int largo);

int main()
{
    int numeros[TAM];
    int opcion;


    printf("Ingrese 5 numeros:\n");
    if(cargarListaSecuencial(numeros, TAM)==1)
    {
        printf("Carga exitosa\n");
    }

    do
    {
        printf("-----------------------------");
        printf("\n1-Numeros ingresados");
        printf("\n2-Numero maximo");
        printf("\n3-Numero minimo");
        printf("\n4-Promedio");
        printf("\n5-Modificar numero");
        printf("\n6-Salir");
        printf("\n-----------------------------");

        printf("\nIngrese una opcion:");
        scanf("%d", &opcion);
        printf("-----------------------------");

        switch(opcion)
        {
            case 1:
                printf("\nNumeros ingresados:\n");
                mostrarLista(numeros, TAM);
                break;
            case 2:
                printf("\nEl numero maximo es: %d\n", obtenerMaximo(numeros));
                break;
            case 3:
                printf("\nEl numero minimo es: %d\n", obtenerMinimo(numeros));
                break;
            case 4:
                printf("\nEl promedio es: %.2f\n", calcularPromedio(numeros, TAM));
                break;
            case 5:
                printf("\nNumeros ingresados:\n");
                if(modificarLista(numeros,TAM)==1)
                {
                    printf("Se modifico el numero con exito\n");
                }
                break;

        }

    }while(opcion!=6);

    return 0;
}

int cargarListaSecuencial(int lista[], int largo)
{
    int i;
    int flag;

    //Carga secuencial
    for(i=0;i<largo;i++)
    {
        scanf("%d",&lista[i]);

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

int obtenerMaximo(int lista[])
{
    int i;
    int maximo;

    for(i=0;i<TAM;i++)
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

int obtenerMinimo(int lista[])
{
    int i;
    int minimo;

    for(i=0;i<TAM;i++)
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
    scanf("%d", &indice);

    while(indice-1>=largo || indice-1<0)
    {
        printf("Error no es un indice valido.");
        printf("\nIngrese el indice: ");
        scanf("%d", &indice);

    }

    printf("Ingrese el nuevo dato: ");
    scanf("%d", &lista[indice-1]);

    flag=1;//Se modifico


    return flag;

}
