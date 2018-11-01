#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "funciones.h"
#define TAM_AGENDA 200

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

//int listarLegajos(int legajos[], char nombres[], char apellidos[], int longitud);

int main()
{
    //------Arrays paralelos--------//
    char nombre[TAM_AGENDA][50]={};
    char apellido[TAM_AGENDA][50]={};
    int legajos[TAM_AGENDA];
    //------------------------------//

    int indiceLibre;
    int indicelegajo;

    int auxiliarLegajo=0;
    int opcion=0;
    int i;
    int j;
    char auxiliarNombre[50];
    char auxiliarApellido[50];

    inicializarArrayEnteros(legajos, TAM_AGENDA, -1);

    while(opcion != 6)
    {
        printf("---------------------------------\n");
        printf("1-Alta\n");
        printf("2-Baja\n");
        printf("3-Modificacion\n");
        printf("4-Listar\n");
        printf("5-Ordenar apellido por orden alfabetico\n");
        printf("6-Salir\n");
        printf("---------------------------------\n");
        getCadenaNumeros(&opcion,"Ingrese una opcion", 1, 6);
        printf("---------------------------------\n");

        switch(opcion)
        {
            case 1: //Alta
                //Busco el indice de legajo libre:
                indiceLibre=buscarPrimeraOcurrenciaInt(legajos, TAM_AGENDA, -1);

                if(indiceLibre==-1)
                {
                    printf("No hay legajos libres!!\n");
                }
                else
                {
                    getCadenaNumeros(&auxiliarLegajo, "Ingrese el legajo", 1, 9999);
                    //Busco que no se repita el numero de legajo:
                    while(buscarPrimeraOcurrenciaInt(legajos, TAM_AGENDA, auxiliarLegajo)!=-1)
                    {
                        printf("El legajo ya existe.\n");
                        getCadenaNumeros(&auxiliarLegajo, "Ingrese el legajo", 1, 9999);
                    }

                    legajos[indiceLibre]=auxiliarLegajo;

                    //Pido los datos que faltan:
                    getCadenaLetras(nombre[indiceLibre],"Ingrese el nombre");
                    getCadenaLetras(apellido[indiceLibre],"Ingrese el apellido");
                }
                break;
            case 2:
                //Baja lógica, pido legajo_
                getCadenaNumeros(&auxiliarLegajo, "Ingrese el legajo que desea dar de baja", 1, 9999);
                //Busco el indice
                indicelegajo=buscarPrimeraOcurrenciaInt(legajos, TAM_AGENDA, auxiliarLegajo);
                if(indicelegajo!=-1)
                {
                    legajos[indicelegajo]=-1;//lo doy de baja (lógica)
                }
                else
                {
                    printf("No se encuentra el legajo\n");
                }
                break;

            case 3:
                //Modificación:
                getCadenaNumeros(&auxiliarLegajo, "Ingrese el legajo que desea modificar", 1, 9999);
                //Busco el legajo:
                indicelegajo=buscarPrimeraOcurrenciaInt(legajos, TAM_AGENDA, auxiliarLegajo);

                //Pido todo de nuevo:
                getCadenaNumeros(&auxiliarLegajo, "Ingrese el nuevo legajo", 1, 9999);

                //Busco que no se repita el numero de legajo:
                while(buscarPrimeraOcurrenciaInt(legajos, TAM_AGENDA, auxiliarLegajo)!=-1)
                {
                    printf("El legajo ya existe.\n");
                    getCadenaNumeros(&auxiliarLegajo, "Ingrese el legajo", 1, 9999);
                }

                legajos[indiceLibre]=auxiliarLegajo;
                getCadenaLetras(nombre[indiceLibre],"Ingrese el nombre");
                getCadenaLetras(apellido[indiceLibre],"Ingrese el apellido");
                break;

            case 4:
                printf("%-15s %-15s %-15s\n", "LEGAJO", "NOMBRE", "APELLIDO");
                for(i=0;i<TAM_AGENDA; i++)
                {
                    if(legajos[i]!=-1)
                    {
                        printf("%-15d %-15s %-15s\n",legajos[i], nombre[i], apellido[i]);
                    }
                }
                break;

            case 5:
                //Inserción
                for(i=1;i<TAM_AGENDA;i++)
                {
                    if(legajos[i]==-1)//Si está vacío
                    {
                        continue;//Paso a la proxima iteración
                    }
                    //Empiezo en indice 1 y voy avanzando hacia la derecha con cada iteración
                    strcpy(auxiliarApellido,apellido[i]);
                    strcpy(auxiliarNombre,nombre[i]);
                    auxiliarLegajo=legajos[i];
                    j=i-1;

                    //Comparo con el de la izquierda
                    while(j>=0 && stricmp(auxiliarApellido,apellido[j])<0)//Apellido A-Z
                    {
                        legajos[j+1] = legajos[j];//muevo todo para la derecha
                        strcpy(apellido[j+1],apellido[j]);
                        strcpy(nombre[j+1],nombre[j]);


                        j--;
                    }

                    legajos[j+1]=auxiliarLegajo;//inserto al final a la izquierda
                    strcpy(nombre[j+1], auxiliarNombre);
                    strcpy(apellido[j+1], auxiliarApellido);
                }
                printf("Se ordeno alfabeticamente por apellido.\n");

                break;

        }
    }


    return 0;
}

/*
int listarLegajos(int legajos, char nombres, char apellidos)
{
    int i;
    int flag=0;//No mostro todos

    printf("%s %-10s %-10s", "LEGAJO", "NOMBRE", "APELLIDO");

    for(i=0;i<longitud; i++)
    {
        if(legajos[i]!=-1)
        {
            printf("%d %s %s",legajos[i], nombres[i], apellidos[i]);
        }
    }

    if(i==longitud)
    {
        flag=1;//Mostró todos
    }

    return flag;
}*/

/*
void ordenarListaChar(int data[], int longitud)
{
    int i;
    int j;
    int temp;

    for(i=1;i<longitud;i++)
    {
        temp= data[i];
        j=i-1;

        while(j>=0 && temp<data[j])
        {
            data[j+1] = data[j];//muevo todo para la derecha
            j--;
        }
        data[j+1]=temp;//inserto temp en la ultima posicion
    }
}
*/
