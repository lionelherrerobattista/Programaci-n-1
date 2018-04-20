#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define TAM 3

int buscarLibre(int[], int);
void mostrarAlumnos(int[], char[][20], int[], int[], float[], int);
float calcularPromedio(int, int);
int cargarAlumno(int[], char[][20], int[], int[], float[], int);
int buscarLegajo (int [],int ,int);

int main()
{
    int legajo[TAM]= {1,2,3};
    char nombre[TAM][20]={"juan","maria","pedro"};
    int nota1[TAM]={2,6,10};
    int nota2[TAM]={6,5,8};
    float promedio[TAM];
    int opcion;
    int index;
    int auxlegajo;
    do
    {
        printf("1. ALTAS\n2. MOSTRAR\n3. MODIFICAR\n4.BAJA\n5.ORDENAR (por nombre)\n9. SALIR\nElija una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:

            index=cargarAlumno(legajo,nombre,nota1,nota2,promedio,TAM);
            if(index == -1)
            {
                printf("No hay lugar");
            }
            else
            {
                printf("Alumno ingresado");
            }
            break;




        case 2:

                mostrarAlumnos(legajo,nombre,nota1,nota2,promedio,TAM);

        case 3:

                auxlegajo= buscarLegajo(legajo,TAM,);




        break;
        }

    }
    while(opcion!=9);




    return 0;
}

int buscarLibre(int legajos[], int tam)
{
    int index=-1;
    int i;

    for(i=0; i<tam; i++)
    {
        if(legajos[i]==0)
        {
            index = i; //si encuentro un cero es para guardar el dato
            break;
        }
    }
    return index;
}

int cargarAlumno(int legajos[], char nombres[][20], int nota1[], int nota2[], float promedio[], int tam)
{
    int index ;
    index = buscarLibre(legajos, tam);

            if(index!=-1)
            {
                //Pedir datos
                printf("\nIngrese el nombre: ");
                fflush(stdin);
                gets(nombres[index]);

                printf("\nIngrese el numero de legajo: ");
                scanf("%d",&legajos[index]);

                printf("\nIngrese nota 1: ");
                scanf("%d",&nota1[index]);
                printf("\nIngrese nota2: ");
                scanf("%d",&nota2[index]);

                promedio[index]= calcularPromedio(nota1[index],nota2[index]);
            }
            return index;
}


float calcularPromedio(int nota1, int nota2)
{
    float promedio;
    promedio = (float)(nota1+nota2)/2;
    return promedio;
}

void mostrarAlumnos(int legajos[], char nombres[][20], int nota1[], int nota2[], float promedio[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
            {
                if(legajos[i]!=0)
                {
                    printf("%d %s %d %d %f\n", legajos[i], nombres[i], nota1[i], nota2[i], promedio[i] );
                }

            }

}

int buscarLegajo (int legajos[],int tam,int auxlegajo)
{
    printf("Ingrese el legajo para buscarlo: ");
    scanf("%d",&auxlegajo);
    int i;
    for ( i=0; i<tam ; i++)
    {
        if(legajos[i]==auxlegajo)
        {
            return auxlegajo;
        }
        else
        {
            printf("-1");
        }
    }
}
