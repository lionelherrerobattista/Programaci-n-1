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

eEstructura* cargarEstructura ();


int main()
{
    eEstructura* punteroEstructura;

    punteroEstructura = cargarEstructura();
    //Controlo que no me devuelva NULL por afuera de la función
    if(punteroEstructura==NULL)
    {
        printf("No hay espacio en memoria");
    }
    else
    {
        printf("%d--%c", punteroEstructura->numero,punteroEstructura->caracter);
    }



    return 0;
}

//Constructor:
eEstructura* cargarEstructura()
{
    eEstructura* punteroEstructura;

    punteroEstructura= (eEstructura*) malloc(sizeof(eEstructura));

    if(punteroEstructura != NULL)
    {
        punteroEstructura->numero = 2;
        punteroEstructura->caracter = 'a';
    }

    return punteroEstructura;

}
