#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alumno.h"
#define TAM 3



int main()
{
    //Declaro una variable de tipo alumno
    //Cargo por extensión
    //eAlumno miAlumno = {14,"pepe",3.45};

    //creo una estructura con los datos vacios
    eAlumno listaDeAlumnos[TAM];

    cargarListado(listaDeAlumnos,TAM);
    mostrarListado(listaDeAlumnos,TAM);


    //cargo los datos de un Alumno por funcion





    /*
    miAlumno.legajo = 159;
    strcpy(miAlumno.nombre,"Juan");
    miAlumno.promedio = 4.57;*/

    /*
    //paso datos a otroAlumno:
    otroAlumno = miAlumno;*/

    //solo paso la estructura que quiero mostrar


    return 0;
}
