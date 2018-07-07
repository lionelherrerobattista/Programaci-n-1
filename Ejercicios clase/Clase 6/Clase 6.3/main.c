#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char palabra1[15]; //se puede en la declaración
    char palabra2[15];
    char buffer[1024]; //para que el usuario ingrese caracteres
    int cantidad;
    int comparacion;

    printf("Ingrese una palabra: ");
    //scanf("%s", palabra);//si ponemos espacio lo interpreta como \0
    fflush(stdin);//Asegurarse de limpiar el buffer
    gets(buffer);

    //mientras el usuario siga ingresando mas de 14, le sigo pidiendo
    //me aseguro de que el buffer tiene un valor que entra en el string
    //y no sobrepase la cantidad de caracteres permitidos
    while(strlen(buffer)>14)
    {
        printf("Reingrese una palabra: ");
        fflush(stdin);
        gets(buffer);
    }

    strcpy(palabra1, buffer);//destino,asignación
    strcpy(palabra2, "perro");

    cantidad=strlen(palabra1); //cuenta la cantidad de caracteres
    //Sirve para validar el largo de la palabra

    //strupr();//convierte todo en mayusculas
    //strlwr();//convierte todo en minusculas

    strcat(buffer, palabra1);//Sirve para concatenar UN PAR de variables

    comparacion=strcmp(palabra1,palabra2);//Compara palabras
    printf("El resultado de la comparacion es: %d\n",comparacion);

    printf("Cantidad de caracteres de palabra 1: %d\n", cantidad);
    printf("%s\n", palabra1);
    printf("%s\n", palabra2);
    printf("%s\n", buffer);



    return 0;
}
