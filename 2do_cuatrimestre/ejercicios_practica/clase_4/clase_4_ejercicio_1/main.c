#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

float pedirFloat(char mensaje[], float min, float max);
float validarFloat(float numero, float min, float max, char mensaje []);
float esFloat(char auxiliar[]);

int main()
{
    float numero;

    numero=pedirFloat("Ingrese un numero entre 1 y 10", 1, 10);

    printf("El numero ingresado es: %.2f", numero);


    return 0;
}



float pedirFloat(char mensaje[], float min, float max)
{
    float numero;
    char auxiliar[10]={};

    printf("%s: ",mensaje);
    fgets(auxiliar,sizeof(auxiliar),stdin); //Limito el dato ingresado al tamaño del auxiliar
    auxiliar[strlen(auxiliar)-1]='\0';

    numero = validarFloat(esFloat(auxiliar), min, max, mensaje);

    return numero;
}

float validarFloat(float numero, float min, float max, char mensaje [])
{
    while(numero < min || numero > max)
    {
        printf("Error. Ingrese %s nuevamente: ",mensaje);
        scanf("%f", &numero);
    }

    return numero;
}

float esFloat(char auxiliar[])
{
    int i;
    int flagEsInt;

    float numero;

    do
    {
        flagEsInt=1;

        while(auxiliar[i]!='\0')
        {
            if(auxiliar[i]<'0' || auxiliar[i]>'9')
            {
                if(auxiliar[i]!='.')
                {
                    printf("Error. Debe ingresar un numero: ");
                    fgets(auxiliar,strlen(auxiliar),stdin);
                    auxiliar[strlen(auxiliar)-1]='\0';
                    flagEsInt=0; //No es int
                    break;
                }

            }
            i++;
        }

    }while(flagEsInt==0);

    numero=atof(auxiliar);

    return numero;

}
