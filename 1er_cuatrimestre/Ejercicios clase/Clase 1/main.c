#include <stdio.h>
#include <stdlib.h>
#include <conio.h> //Hacer el include para utilizar funcion getche()

int main()
{
    //Pedir al usuario:
    //-un numero entro
    //-un numero con coma
    //-un carácter
    //-sumar los numeros
    //-mostrar todo

    int numero1; //variable para guardar un entero
    float numero2; //variable para guardar un real

    char letra;//char guarda 1 SOLO carácter

    float resultado; //el resultado es un numero con coma

    printf("Escriba un numero entero: ");//-imprime un mensaje por pantalla
    scanf("%d", &numero1);//-lee nro. desde el teclado, agregar 1.máscara 2.dirección de memoria de la variable

    printf("Escriba un numero con coma: ");
    scanf("%f", &numero2);

    printf("Ingrese una letra: ");
    letra = getche();//Funcion que lee un caracter y lo guarda en una variable
                    // y lo muestra en la consola (eco) diferencia con getch() no muestra nada.

    printf("\nEl numero entero que ingreso es %d y el numero con coma %.2f", numero1, numero2);//%.2f muestra solo dos numeros después de la coma

    resultado=(float) numero1+numero2;//castear el numero entero a flotante para no perder precisión decimal
    printf("\nEl resultado de la suma de los numeros es: %.2f",resultado);

    printf("\nLa letra que ingreso es: %c",letra);



    return 0;
}
