#include <stdio.h>
#include <stdlib.h>
#include "posts.h"

ePost* newPost()
{

    ePost* pPost=NULL;

    pPost=(ePost*)malloc(sizeof(ePost));

    return pPost;
}
