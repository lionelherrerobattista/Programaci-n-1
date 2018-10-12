
int pedirInt(char mensaje[], int min, int max)
{
    int numero;
    char auxiliar[10]={};

    printf("%s: ",mensaje);
    gets(auxiliar);


    numero = validarInt(esInt(auxiliar), min, max, mensaje);

    return numero;
}

int validarInt(int numero, int min, int max, char mensaje [])
{
    while(numero < min || numero > max)
    {
        printf("Error. Ingrese %s nuevamente: ",mensaje);
        scanf("%d", &numero);
    }

    return numero;
}

int esInt(char auxiliar[])
{
    int i;
    int flagEsInt;
    int numero;

    do
    {
        flagEsInt=1;

        for(i=0;i<strlen(auxiliar);i++)
        {
            if(!(isdigit(auxiliar[i])))
            {
                printf("Error. Debe ingresar un numero: ");
                gets(auxiliar);
                flagEsInt=0; //No es int
                break;
            }
        }

    }while(flagEsInt==0);

    numero=atoi(auxiliar);

    return numero;

}


float pedirFloat(char mensaje[], float min, float max)
{
    float numero;

    printf("%s: ",mensaje);
    scanf("%f",&numero);

    numero = validarFloat(numero, min, max, mensaje);

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
