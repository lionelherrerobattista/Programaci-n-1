#include <stdio.h>
#include <stdlib.h>
#include <strings.h>


int main()
{
    char* texto;
    char* auxiliar;
    int largo=5;

    auxiliar=(char*)malloc(sizeof(char)*largo);
    gets(auxiliar);

    while(strlen(auxiliar)>largo)
    {
        largo=largo*largo;
        printf("%d",largo);
        auxiliar=(char*)realloc(auxiliar, sizeof(char)*largo);
        gets(auxiliar);
        printf("%d", strlen(auxiliar));
    }

    texto=(char*)malloc(sizeof(char)*largo);
    texto=auxiliar;

    printf("%s", texto);
    printf("%d", strlen(texto));

    return 0;
}
