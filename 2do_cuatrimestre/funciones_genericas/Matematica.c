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

float calcularAreaCirculo(float radio)
{
    float area;

    area= 3.14 * (radio * radio);

    return area;
}
