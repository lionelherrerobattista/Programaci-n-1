#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "Empleados.h"
#include "ArrayList.h"

int parseArchivo (char* nombreArchivo, ArrayList* listaEmpleados)
{
    FILE *pFile;

    eEmpleados* auxEmpleado;
    auxEmpleado=nuevoEmpleado();

    int r;
    int i=0;
    char id[50];
    char nombre[50];
    char sueldo[50];
    char edad[50];
    char profesion[50];
    //Devuelvo -1 si hay error
    int retorno=-1;

    //Abro el archivo en modo lectura
    pFile= fopen(nombreArchivo,"r");
    //Compruebo que no haya error
    if(pFile != NULL)
    {
        //Leo el archivo
        do
        {

            r= fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,sueldo,edad,profesion);
            if(r==5)
            {
                //Cargo todos los datos en la lista
                eEmpleados_setId(auxEmpleado+i,atoi(id));
                eEmpleados_setNombre(auxEmpleado+i,nombre);
                eEmpleados_setSueldo(auxEmpleado+i,atof(sueldo));
                eEmpleados_setEdad(auxEmpleado+i,atoi(edad));
                eEmpleados_setProfesion(auxEmpleado+i,profesion);
                al_add(listaEmpleados,auxEmpleado+i);
                i++;
            }
        }while(!feof(pFile));

        //Cierro el archivo
        fclose(pFile);
        //No hay error, retorno= 1
        retorno=1;
    }

    return retorno;
}
