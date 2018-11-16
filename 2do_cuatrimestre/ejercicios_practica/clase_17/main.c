#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "texto.h"
#define TAM_BUFFER 50



int main()
{
    char* pTexto;
    char* texto;

    texto=(char*)malloc(sizeof(char)*TAM_BUFFER);

    pTexto=getDynamicString("Ingrese un mensaje", texto);

    printf("%s",pTexto);
    printf("largo: %d", strlen(texto));

    return 0;
}



