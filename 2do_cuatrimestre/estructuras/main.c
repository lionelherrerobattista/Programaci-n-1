#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int legajo;
    char nombre[50];
    float promedio;
    char direccion[50];

}eAlumno;

void mostrarAlumno(eAlumno);


//Cargo un alumno
eAlumno cargarAlumno();

int main()
{
    //Declaro una variable de tipo alumno
    //Cargo por extensión
    //eAlumno miAlumno = {14,"pepe",3.45};

    //creo una estructura con los datos vacios
    eAlumno otroAlumno;

    //cargo los datos de un Alumno por funcion
    otroAlumno = cargarAlumno();




    /*
    miAlumno.legajo = 159;
    strcpy(miAlumno.nombre,"Juan");
    miAlumno.promedio = 4.57;*/

    /*
    //paso datos a otroAlumno:
    otroAlumno = miAlumno;*/

    //solo paso la estructura que quiero mostrar
    mostrarAlumno(otroAlumno);

    return 0;
}

void mostrarAlumno(eAlumno alumnoParametro)
{

    printf("%d--%s--%f--%s",alumnoParametro.legajo,alumnoParametro.nombre,alumnoParametro.promedio,alumnoParametro.direccion);

}

eAlumno cargarAlumno()
{
    eAlumno miAlumno;

    printf("Ingrese el legajo: ");
    scanf("%d", &miAlumno.legajo);

    printf("Ingrese el nombre: ");
    fflush(stdin);
    gets(miAlumno.nombre);

    printf("Ingrese el promedio: ");
    scanf("%f", &miAlumno.promedio);

    printf("Ingrese la direccion: ");
    fflush(stdin);
    gets(miAlumno.direccion);

    return miAlumno;
}
