#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define T 2

typedef struct
{
    int legajo;
    char nombre[50];
    float promedio;
    //char email[30];

}eAlumno;

// void mostrar {int legajo, char nombre[], float promedio}; <-- Con vector
void mostrarUnAlumno(eAlumno unAlumno);

void mostrarClase(eAlumno unaClase[]);

int main()
{
    int i;

    eAlumno clase[T]; //en memoria defini espacio para guardar 5 estruc del tipo alumno

    eAlumno miAlumno; //= {1, "Juan", 3.25}; <- por extension
    //eAlumno otroAlumno;

    for (i=0; i<T; i++)
    {
        printf("Ingrese legajo: ");
        scanf("%d",&clase[i].legajo);
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(clase[i].nombre);
        printf("Ingrese promedio: ");
        scanf("%f", &clase[i].promedio);
    }

    //otroAlumno.legajo = 2;
    //strcpy(otroAlumno.nombre, "Maria");
    //otroAlumno.promedio=6;

    /*printf("Ingrese legajo: ");
    scanf("%d",&miAlumno.legajo);
    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(miAlumno.nombre);
    printf("Ingrese promedio: ");
    scanf("%f", &miAlumno.promedio);*/

    mostrarClase(clase);

    //mostrarUnAlumno(miAlumno);
    //mostrarUnAlumno(otroAlumno);

    /*for (i=0; i<T; i++)
    {
        mostrarUnAlumno(clase[i]);
    }*/


    return 0;
}

void mostrarUnAlumno(eAlumno unAlumno)
{
    printf("%d %s %f\n", unAlumno.legajo, unAlumno.nombre, unAlumno.promedio);
}

void mostrarClase(eAlumno unaClase[T])
{
    int i;

    for (i=0; i<T; i++)
    {
        mostrarUnAlumno(unaClase[i]);
    }
}
