#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define TAM 5

//Solicitar al usuario 5 números,
//permitir listarlos por pantalla indicando el máximo, el mínimo y el promedio.
//Permitir Modificar el valor de cualquiera de los números cargados
// indicando el índice del mismo y su nuevo valor.



int main()
{
    int numeros[TAM];
    int opcion;


    printf("Ingrese 5 numeros:\n");
    if(cargarListaSecuencial(numeros, TAM)==1)
    {
        printf("-----------------------------\n");
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
        opcion=getInt();

        //Valido que la opción ingresada esté dentro del rango:
        opcion=validarRango(opcion, 1, 6);
        printf("-----------------------------");

        switch(opcion)
        {
            case 1:
                printf("\nNumeros ingresados:\n");
                mostrarLista(numeros, TAM);
                break;
            case 2:
                printf("\nEl numero maximo es: %d\n", obtenerMaximo(numeros, TAM));
                break;
            case 3:
                printf("\nEl numero minimo es: %d\n", obtenerMinimo(numeros, TAM));
                break;
            case 4:
                printf("\nEl promedio es: %.2f\n", calcularPromedio(numeros, TAM));
                break;
            case 5:
                printf("\nNumeros ingresados:\n");
                if(modificarLista(numeros,TAM)==1)
                {
                    printf("-----------------------------\n");
                    printf("Se modifico el numero con exito\n");

                }
                break;

        }

    }while(opcion!=6);

    return 0;
}
