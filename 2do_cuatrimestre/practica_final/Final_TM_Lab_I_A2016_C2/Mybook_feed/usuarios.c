#include <stdio.h>
#include <stdlib.h>
#include "usuarios.h"

eUsuario* newUsuario()
{

    eUsuario* pUsuario=NULL;

    pUsuario=(eUsuario*)malloc(sizeof(eUsuario));

    return pUsuario;
}
