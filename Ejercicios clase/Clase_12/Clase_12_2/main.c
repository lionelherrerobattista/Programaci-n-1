#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int a;
    char b;



}dato;

int main()
{
    dato d;

    d.a=5;
    d.b='<';

    dato* pDato;
    pDato = &d; //Le paso la dirección de memoria para que apunte a d



    //printf("%d--%c", (*pDato).a, (*pDato).b);//Sobre el valor de pDato accedo con .a !!
    int i;
    dato l[2]={{1,'a'},{1,'b'}};
    dato* plista;

    plista = l;

    //Acceder a cada elemento del puntero a traves de la lista
    //Metodo más dificil
    for(i=0; i<2;i++)
    {
        //printf("%d--%c\n",(*(plista+i)).a, (*(plista+i)).b);
        //Operador flecha:
        printf("%d--%c\n",(plista+i)->a, (plista+i)->b);
    }

    //Operador flecha: más facil de leer.
    //printf("%d--%c", pDato->a, pDato->b);





    //printf("TAM: %d\n", sizeof(int)); //Me permite saber el tamaño que representa en memoria
                                      //Devuelve tam de datos expresados en bytes
    //printf("%d--%c", d.a,d.b);

    return 0;
}
