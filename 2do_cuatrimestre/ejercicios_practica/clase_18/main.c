#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "archivo.h"
#define TAM 5

/**
1) Crear una struct con dos campos de cadena de caracteres,
    uno llamado 'key' y otro llamado 'value'.

struct S_Data
{
  char* key;
  char* value;
};

Hacer una función que reciba el nombre de un archivo y un array de estas estructuras.
La función leerá un archivo de texto con el siguiente formato:

clave=valor
clave=valor

La función deberá leer cada línea del archivo y separar por el caracter '=' la clave
y el valor, y deberá cargarlo en una struct del array, generando de forma dinámica
las variables para almacenar ambas palabras, y luego guardando los punteros en la struct.
Prototipo de la función:

int loadDataFile(char* fileName,struct S_Data* array, int arrayLen)

La función devolverá la cantidad de items que se cargaron en el array,
y nunca se superará el tamaño del array
*/

int main()
{
    char nombreArchivo[50];
    int i;

    //Creo el array de estructuras
    S_Data listaData[TAM];

    //listaData=data_newArrayData();

    strcpy(nombreArchivo, "data.csv");

    loadDataFile(nombreArchivo,listaData,TAM);

    for(i=0;i<TAM;i++)
    {
        printf("%s---%s\n", listaData[i].key, listaData[i].value);
    }

    return 0;
}

