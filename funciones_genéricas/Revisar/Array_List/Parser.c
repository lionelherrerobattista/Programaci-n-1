#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "Empleados.h"
#include "ArrayList.h"

int parseArchivo (char* nombreArchivo, ArrayList* listaEmpleados)
{
    int r;
    int i=0;
    int cantidadEstructuras=0;
    char id[50];
    char nombre[50];
    char sueldo[50];
    char edad[50];
    char profesion[50];
    //Devuelvo -1 si hay error
    int retorno=-1;

    if(listaEmpleados!=NULL)
    {

        FILE *pFile;

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
                    //para saber la cantidad de datos
                    cantidadEstructuras++;
                }
            }while(!feof(pFile));

            //Creo el puntero y asigno memoria de acuerdo a la cantidad de datos
            eEmpleados* auxEmpleado;
            auxEmpleado=(eEmpleados*)malloc(sizeof(eEmpleados)*cantidadEstructuras);

            //volver el indicador de posición al principio del archivo
            rewind(pFile);

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
                    listaEmpleados->add(listaEmpleados,auxEmpleado+i);
                    i++;
                }
            }while(!feof(pFile));

            //Cierro el archivo
            fclose(pFile);
            //No hay error, retorno= 1
            retorno=1;
        }

    }
    return retorno;
}
