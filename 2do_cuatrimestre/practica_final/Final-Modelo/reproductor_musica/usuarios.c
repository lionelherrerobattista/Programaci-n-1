#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "usuarios.h"


eUsuario* newUsuario()
{
    eUsuario* pUsuario=NULL;

    pUsuario=(eUsuario*)malloc(sizeof(eUsuario));

    return pUsuario;
}
