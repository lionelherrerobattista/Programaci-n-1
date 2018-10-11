#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* f;
    char msj[]="hola a todos";

    f= fopen("mihtml.html","w");

    if(f!=NULL)
    {
        fprintf(f,"<html><head>");//Escribo dentro de un string lo que va en el html
        fprintf(f,msj);//parte varibale
        fprintf(f,"</head></html>");//cierre de los tags
        fclose(f);
    }

    return 0;
}
