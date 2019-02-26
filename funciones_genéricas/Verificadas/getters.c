
int getNumber(void* pEstructura)
{
    eUsuario* pAuxUsuario;
    int retorno;

    if(pEstructura!=NULL)
    {
        pAuxUsuario=pEstructura;
        retorno=pAuxUsuario->id;
    }

    return retorno;
}

char* getString(void* pEstructura)
{
    eUsuario* pAuxUsuario=NULL;

    if(pEstructura!=NULL)
    {
        pAuxUsuario=pEstructura;
    }


    return pAuxUsuario->nombre;
}
