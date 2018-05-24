#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* miArchivo;

    int numero;
    int lista[5];
    int i;

    miArchivo = fopen("prueba.txt","w");

    for(i=0; i<5; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d",&numero);

        fwrite(&numero,sizeof(int),1,miArchivo);//Estoy trabajando dentro del archivo
    }
    return 0;
}
