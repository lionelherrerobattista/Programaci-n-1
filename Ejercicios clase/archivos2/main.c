#include <stdio.h>
#include <stdlib.h>


void funcion2A();

int main()
{
//FILE* miArchivo; //puntero a file

    //funcion2A();
    funcion3B();

    //int numero=64;//quiero guardar este numero

    /*miArchivo=fopen("prueba1.txt","w");

    fwrite(&numero,sizeof(int),1,miArchivo); //escribe sobre el archivo cualquier tipo de dato
    //Recibe:dirección de memoria del tipo de dato,sizeof del tipo de dato,cantidad de datosm string de datos.

    //Resultado="@" veo el 64 en ASCII

    fclose(miArchivo);*/

   /* miArchivo =fopen("prueba1.txt","r");//Abro el archivo para lectura

    fread(&numero,sizeof(int),1,miArchivo);//REcibe lo mismo que el fwrite
    fclose(miArchivo);
    printf("NUMERO: %d", numero); //se muestra como un entero.*/



    return 0;
}

void funcion2A()
{
    FILE* miArchivo;
    int numero;
    int lista[5];
    int i;


    //miArchivo = fopen("prueba.txt","w");



    //int lista[5];



    /*for(i=0; i<5; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d",&numero);

        fwrite(&numero,sizeof(int),1,miArchivo);//Estoy trabajando dentro del archivo
    }

    fclose(miArchivo);*/

    miArchivo =fopen("prueba.txt","r");


    while(!feof(miArchivo))//hay casos en que no se da cuenta que llego al final porque coincide el dato
    {
        fread(&lista[i],sizeof(int),1,miArchivo);//le paso la direccion de memoria de cada elemento del array


        if(feof(miArchivo))
           break;

        //printf("%d\n",&numero);

        i++;//me muevo dentro del array


    }

    fclose(miArchivo);

    for(i=0;i<5;i++)
    {
        printf("&d\n",lista[i]);
    }

}

void funcion3A()
{
    FILE* miArchivo;
    int numero;
    int lista[5]={1,5,9,6,4};
    int i;

    miArchivo = fopen("prueba3.txt","w");

    for(i=0; i<5; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d",&numero);

        fwrite(&numero,sizeof(int),1,miArchivo);
    }

    fclose(miArchivo);

}

void funcion3B()
{
    FILE* miArchivo;
    eDato d= {1,'B'};//escribir este dato en un archivo binario

    /*miArchivo = fopen("miBinario.dat","wb");//tambien se puede usar la extensión .bin o no ponerle nada wb-modo de escritra binaria

    if (miArchivo!=NULL)
    {
        fwrite(&d,sizeof(eDato),1,miArchivo);
        fclose(miArchivo);
    }*/

    miArchivo = fopen("miBinario.dat","rb");//tambien se puede usar la extensión .bin o no ponerle nada wb-modo de escritra binaria

    if (miArchivo!=NULL)
    {
        fwrite(&d,sizeof(eDato),1,miArchivo);
        fclose(miArchivo);

        printf("%d---%c",d.a,d.b);
    }


}


