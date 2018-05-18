#include <stdio.h>
#include <stdlib.h>

int cargarArray(int*,int);//int forzar a que la función devuelva un estado

void mostrarArray(int*,int);

int main()
{
    int vector[3];
    //int* puntero; No hace falta si trabajamos en una funcion con el puntero
    //puntero = vector;//Saco directamente la dirección de memoria del primer elemento

    //Controlar lo que devuelve la función
    if(cargarArray(vector,3))//Espera un valor booleano. Si es 0 es falso.
    {
        printf("Carga exitosa.\n");
    }
    else
    {
        printf("Error al cargar los datos.\n");
    }

    mostrarArray(vector,3);







    return 0;
}

int cargarArray(int* array,int tam)
{
    int i;
    int retorno= 0;

    //Control de acceso
    //control de nulidad sobre los punteros antes de cualquier función!!
    if(array!=NULL)
    {
        retorno= 1;
        //Le pido números al usuario.
        for (i=0; i<tam; i++)
        {
            printf("Ingrese un numero: ");
            scanf("%d",array+i);//No hace falta &, ya es una dirección de memoria. Le suma el valor de la variable int
        }

    }

    return retorno;

}

void mostrarArray(int* vector,int tam)
{
    int i;

    //Muestro los números
    for (i=0; i<tam; i++)
    {
        printf("%d\n",*(vector+i));
    }

}
