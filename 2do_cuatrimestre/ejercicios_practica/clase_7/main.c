#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "funciones.h"
#define TAM 200

/*
1) Realizar una agenda para guardar los datos de hasta 200 personas
 de las cuales se toman los siguientes datos:

Nombre
Apellido
Legajo (NO SE PUEDE REPETIR)

a- Realizar un programa con un menú de opciones para hacer altas ,
 bajas y modificaciones (ABM) de una agenda.

b- Mostrar un listado ordenado por Apellido

*/



int main()
{
    char nombre[TAM][50]={};
    char apellido[TAM][50]={};


    int legajo;
    int opcion=0;

    while(opcion != 5)
    {
        printf("---------------------------------\n");
        printf("1-Alta\n");
        printf("2-Baja\n");
        printf("3-Modificacion\n");
        printf("4-Listar\n");
        printf("5-Salir\n");
        printf("---------------------------------\n");
        getCadenaNumeros(&opcion,"Ingrese una opcion", 1, 5);
        printf("---------------------------------\n");

        switch(opcion)
        {
            case 1:
                getCadenaNumeros(&legajo, "Ingrese el legajo", 1, 200);
                getCadenaLetras(nombre[legajo-1],"Ingrese el nombre");
                getCadenaLetras(apellido[legajo-1],"Ingrese el apellido");
                break;
            case 2:
                getCadenaNumeros(&legajo, "Ingrese el legajo que desea dar de baja",1,200);
                strcpy(nombre[legajo-1]," ");
                strcpy(apellido[legajo-1], " ");
                break;

            case 3:
                getCadenaNumeros(&legajo, "Ingrese el legajo que desea modificar", 1, 200);
                getCadenaLetras(nombre[legajo-1], "Ingrese el nombre");
                getCadenaLetras(apellido[legajo-1], "Ingrese el apellido");
                break;

            case 4:
                getCadenaNumeros(&legajo,"Ingrese el legajo",1,200);
                printf("---------------------------------");
                printf("\nLegajo: %d", legajo);
                printf("\nNombre: %s",nombre[legajo-1]);
                printf("\nApellido: %s\n",apellido[legajo-1]);
                break;

        }
    }


    return 0;
}



