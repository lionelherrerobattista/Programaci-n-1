#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*int num=50, i;

    for(i=1;i<=num;i++)
    {
        if(!(num%i))//Cualquier resultado TRUE(!=0) lo pasa a FALSE
        {
            printf("%d",i);
        }
    }*/

    int a=2;

    {
        int a=4; //solo tiene visibilidad dentro de las llaves

        printf("el valor de a es %d\n", a);
    }

    printf("el valor de a es %d\n", a);


    return 0;
}
