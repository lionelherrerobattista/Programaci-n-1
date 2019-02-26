int setNumber(void* pAuxEstructura, int number)
{
	int retorno = 0;
	
	if(pAuxEstructura != NULL)
	{
		pAuxEstructura->id = number;
		
		retorno = 1;
	}
    
    return retorno;
}

int setChar(void* pAuxEstructura, char* cadena)
{
	int retorno = 0;
	
	if(pAuxEstructura != NULL)
	{
		strcpy(pAuxEstructura->name, cadena);
		
		retorno = 1;
	}
    
    return retorno;
}
