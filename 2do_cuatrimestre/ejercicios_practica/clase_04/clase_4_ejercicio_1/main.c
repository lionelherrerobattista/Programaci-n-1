#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define TAM_BUFFER 8

float pedirCadenaFloat(char* mensaje, int minimo, int maximo);
int cargarCadena(char* mensaje, char* cadena);
int esFloat(char* auxiliar);

int main()
{
    float numero;
    char numeroDos[4]="4.36";
    float numeroDosFloat;

    numero=pedirCadenaFloat("Ingrese un numero entre -23 y 10", -23, 10);
    numeroDosFloat=atof(numeroDos);

    printf("El numero ingresado es: %.2f    %.2f", numero, numeroDosFloat);


    return 0;
}



float pedirCadenaFloat(char* mensaje, int minimo, int maximo)
{
    int flag=0;//No esta cargado
    char* auxiliar;
    float numeroAuxiliar;


    auxiliar=(char*)malloc(sizeof(char)*TAM_BUFFER);

    do
    {
        cargarCadena(mensaje, auxiliar);

        while(esFloat(auxiliar)!=1)
        {
            printf("Error. No es un numero valido.\n");
            cargarCadena(mensaje, auxiliar);
        }

        numeroAuxiliar=atof(auxiliar);//*Tomo el valor

        if(numeroAuxiliar>=minimo && numeroAuxiliar<=maximo)
        {
            flag=1;//Cumple con las condiciones. Sale de la iteracion.
        }
        else
        {
            printf("Fuera de rango.\n");
        }


    }while(flag==0);

    free(auxiliar);


    return numeroAuxiliar;

}


int cargarCadena(char* mensaje, char* cadena)
{
    int flag=0;//No está cargada

    if(cadena!=NULL)
    {

        printf("%s: ", mensaje);
        fflush(stdin);

        //Para no escribir de más en memoria uso fgets
        //(limita lo que se puede ingresar)
        fgets(cadena,sizeof(char)*TAM_BUFFER,stdin);

        //Agregar '\0' al final cuando cadena < al buffer
        //para que pueda validar (porque fgets escribe '\n' al final)
        if(strlen(cadena)<TAM_BUFFER-1)
        {
            *(cadena+(strlen(cadena)-1))='\0';
        }


        if(strlen(cadena)>0)
        {
            flag=1;
        }
    }

    return flag;
}

int esFloat(char* auxiliar)
{
    int i;
    int flag=1;//1 es entero
    int contadorPunto=0;
    int contadorNegativo=0;

    for(i=0; i<strlen(auxiliar); i++)
    {
        if(*(auxiliar+i)<'0' || *(auxiliar+i)>'9')
        {
            if(*(auxiliar+i)=='.')
            {
                contadorPunto++;
            }

            if(*(auxiliar+i)=='-')
            {
                contadorNegativo++;
            }

            if((*(auxiliar+i)!='.' && *(auxiliar+i)!='-')
                || (contadorPunto>1 || contadorNegativo>1))
            {

                flag=0;
                break;
            }
        }
    }

    return flag;
}
