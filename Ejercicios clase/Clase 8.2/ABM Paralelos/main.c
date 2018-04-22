#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 4

int buscarLibre(int[], int);
void mostrarAlumnos(int[], char[][20], int[], int[], float[], int);
float calcularPromedio(int, int);
int cargarAlumno(int[], char[][20], int[], int[], float[], int);
int buscarLegajo(int[], int, int);

int main()
{
    int legajo[TAM]= {50,51,52};
    char nombre[TAM][20]={"juan","pedro","maria"};
    int nota1[TAM]={10,6,7};
    int nota2[TAM]={8,4,2};
    float promedio[TAM]={9,5,4.5};
    int opcion;
    int index;
    int legajoAModificar=0;
    int i;
    int j;
    char auxiliarChar[TAM][20];
    int auxiliarInt[TAM];
    float auxiliarFloat[TAM];

    do
    {
        printf("1. ALTAS\n2. MOSTRAR\n3. MODIFICAR\n4.BAJA\n5.ORDENAR (por nombre)\n9. SALIR\nElija una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:

            index=cargarAlumno(legajo, nombre, nota1, nota2, promedio, TAM);
            if(index == -1)
            {
                printf("No hay lugar\n");
            }
            else
            {
                printf("Alumno ingresado\n");
            }
            break;

        case 2:


            mostrarAlumnos(legajo, nombre, nota1, nota2, promedio, TAM);
            break;

        case 3:

            printf("Ingrese el legajo del alumno a modificar: ");
            scanf("%d", &legajoAModificar);
            index=buscarLegajo(legajo, TAM, legajoAModificar);
            if(index!=-1)
            {
                printf("Ingrese el numero de legajo: ");
                scanf("%d", &legajo[index]);

                printf("Ingrese el nombre: ");
                fflush(stdin);
                gets(nombre[index]);

                printf("Ingrese la nota nro. 1: ");
                scanf("%d", &nota1[index]);

                printf("Ingrese la nota nro. 2: ");
                scanf("%d", &nota2[index]);

                promedio[index]=calcularPromedio(nota1[index],nota2[index]);

            }
            else
            {
                printf("No se encontro el legajo.\n");
            }
            break;

        case 4:
            printf("Ingrese el legajo del alumno a dar de baja: ");
            scanf("%d", &legajoAModificar);
            index=buscarLegajo(legajo, TAM, legajoAModificar);
            if(index!=-1)
            {
               legajo[index]='\0';
               nombre[index][20]='\0';
               nota1[index]=0;
               nota2[index]=0;
               promedio[index]=0;
            }
            else
            {
                printf("No se encontro el legajo.\n");
            }

        case 5:
            for (i=0; i<TAM-1; i++)
            {
                for(j=0; j<TAM;j++)
                {
                    if(stricmp(nombre[i],nombre[j])<0)
                    {
                        strcpy(auxiliarChar[i],nombre[i]);
                        strcpy(nombre[i],nombre[j]);
                        strcpy(nombre[j], auxiliarChar[i]);

                        auxiliarInt[i]=legajo[i];
                        legajo[i]=legajo[j];
                        legajo[j]=auxiliarInt[i];


                        auxiliarInt[i]=nota1[i];
                        nota1[i]=nota1[j];
                        nota1[j]=auxiliarInt[i];

                        auxiliarInt[i]=nota2[i];
                        nota2[i]=nota2[j];
                        nota2[j]=auxiliarInt[i];

                        auxiliarFloat[i]=promedio[i];
                        promedio[i]=promedio[j];
                        promedio[j]=auxiliarFloat[i];


                    }

                }
            }




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

    for (i=0; i<TAM; i++)
    {
        if (legajos[i]==0)
        {
            index=i;
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
                printf("Ingrese el numero de legajo: ");
                scanf("%d", &legajos[index]);

                printf("Ingrese el nombre: ");
                fflush(stdin);
                gets(nombres[index]);

                printf("Ingrese la nota nro. 1: ");
                scanf("%d", &nota1[index]);

                printf("Ingrese la nota nro. 2: ");
                scanf("%d", &nota2[index]);

                promedio[index]=calcularPromedio(nota1[index],nota2[index]);

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
    printf("\n");
    for(i=0; i<tam; i++)
            {
                if(legajos[i]!=0)
                {
                    printf("%d %s %d %d %f\n", legajos[i], nombres[i], nota1[i], nota2[i], promedio[i] );
                }

            }
    printf("\n");

}

int buscarLegajo(int legajos[], int tam, int legajoBuscado)
{
    int index=-1;
    int i;
    for(i=0; i<tam; i++)
    {
        if(legajos[i]==legajoBuscado)
        {
            index=i;
            break;
        }

    }

    return index;
}
