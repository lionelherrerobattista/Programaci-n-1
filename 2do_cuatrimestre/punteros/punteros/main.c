#include <stdio.h>
#include <stdlib.h>
//Crear estructura
//Crear funcion con un puntero a la estructura y cargarla con datos
//Mostrar los datos

typedef struct
{
    int numero;
    char caracter;

}eEstructura;

eEstructura* cargarEstructura (eEstructura this);


int main()
{
    eEstructura nuevaEstructura;
    eEstructura* punteroEstructura;

    punteroEstructura = cargarEstructura(nuevaEstructura);

    printf("%d", punteroEstructura->numero);
    printf("%c", punteroEstructura->caracter);

    return 0;
}

eEstructura* cargarEstructura(eEstructura this)
{
    eEstructura* punteroEstructura;
    punteroEstructura= &this;

    printf("Ingrese un numero: ");
    scanf("%d", punteroEstructura->numero);

    printf("Ingrese un caracter: ");
    fflush(stdin);
    scanf("%c", punteroEstructura->caracter);


    return punteroEstructura;

}
