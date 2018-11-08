#include <stdio.h>
#include <stdlib.h>

int main()
{
    //Inicializar cadenas

    char saludo[10]="hola";

    printf("%s\n",saludo);

    char saludoDos[10] ={'h','i','\0'};

    printf("%s\n",saludoDos);

    char saludoTres[]="hola";

    printf("%s\n",saludoTres);

    char cadena[20];
    scanf("%s",cadena); //No se puede ingresar palabra con espacio
    printf("%s\n",cadena);

    //Permite espacios
    char cadenaDos[20];
    fflush(stdin);
    gets(cadenaDos);
    printf("%s\n",cadenaDos);

    return 0;
}
