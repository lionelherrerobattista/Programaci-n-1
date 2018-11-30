#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "archivo.h"


int loadDataFile(char* fileName,S_Data* pdata, int arrayLen)
{
    FILE* pfile;

    char auxiliarKey[50];
    char auxiliarValue[50];

    int datos;
    int flag=0;
    int i=0;

    char* key;
    char* value;



    pfile=fopen(fileName, "r");

    if(pfile!=NULL)
    {
        do
        {
            //Parser
            datos=fscanf(pfile,"%[^=]=%[^\n]\n", auxiliarKey, auxiliarValue);


            //Primera lectura
            if(datos==2 && flag==0)
            {
                //Cambio el flag
                flag=1;
            }
            else
            {
                if(datos==2 && flag==1)
                {
                    //Asigno espacio en mem. a punteros de acuerdo con el valor de los auxiliares
                    key=malloc(sizeof(char)*strlen(auxiliarKey));
                    value=malloc(sizeof(char)*strlen(auxiliarValue));

                    //Copio los valores
                    strcpy(key, auxiliarKey);
                    strcpy(value, auxiliarValue);

                    pdata[i].key=key;
                    pdata[i].value=value;

                    i++;
                }

            }


        }while(!feof(pfile));
    }

    fclose(pfile);

    free(key);
    free(value);

    return 1;
}

//Constructor
void* data_newArrayData()
{
    S_Data* listaData;

    //Creo la lista de datos estatica de manera dinámica
    listaData=(S_Data*)malloc(sizeof(S_Data)*5);

    return listaData;

}


