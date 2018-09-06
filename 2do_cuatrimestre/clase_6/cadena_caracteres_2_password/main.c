#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char password[20];

    printf("\nIngrese la clave:");
    gets(password);

    //compara sin tener en cuenta las mayus.
    if(stricmp(password,"1234")==0)
    {
        printf("\nClave correcta.");
    }
    else
    {
        printf("\nClave incorrecta.");
    }

    //Pasa un carácter(!!!) a mayúscula
    char c='a';

    c=toupper(c);
    printf("%c",c);

    return 0;

}
