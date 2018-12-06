#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "LinkedList.h"
#include "services.h"


S_Service* newService()
{

    S_Service* pService=NULL;

    pService=(S_Service*)malloc(sizeof(S_Service));

    return pService;
}


