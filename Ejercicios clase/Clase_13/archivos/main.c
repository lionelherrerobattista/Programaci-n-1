#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* pArchivo;
    char cadena[50]="hola ";

    pArchivo= fopen("archivo.txt","w");//Abro el archivo en modo escritura

    /*if(pArchivo!=NULL)//Control de nulidad
    {
        fprintf(pArchivo,"%s %d\n",cadena,156);//Escribo el valor que esta en cadena y el número
        //fprintf solo guarda una cadena. Hay que utilizar máscaras.
        fprintf(pArchivo,"otra cadena");
        fclose(pArchivo);
        printf("Guardado!");

    }
    else
    {
        printf("Imposible guardar");
    }*/

    pArchivo=fopen("archivo.txt","r");

    if(pArchivo!=NULL)
    {
        while (!feof(pArchivo)) //PARA LEER LINEA POR LINEA. Se busca el end of file (feof).
                                //Mientras no sea el final del archivo itera.
        {
            fgets(cadena,50,pArchivo);
            puts(cadena);
        }
        fclose(pArchivo);

    }



    return 0;
}
