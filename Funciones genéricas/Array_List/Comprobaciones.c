int esChar (char auxiliar[])
{
    int i;
    int retorno;
    int limite;

    limite=strlen(auxiliar);

    for (i=0;i<limite;i++)
    {
        retorno=isalpha(auxiliar[i]);

        if (retorno==0)
        {
            break;
        }
    }



    return retorno;

}

int esInt(char auxiliar[])
{
    int i;
    int retorno;
    int limite;

    limite=strlen(auxiliar);

    for (i=0;i<limite;i++)
    {
        retorno=isdigit(auxiliar[i]);

        if (retorno==0)
        {
            break;
        }
    }

    //Si tiene punto:
    /*
    for(i=0; i<strlen(str); i++){
		if(46 == str[i] || (48 <= str[i] && 57 >= str[i])){
			if(46 == str[i])
			    printf("[%c] : is dot\n",str[i]);
			else
			    printf("[%c] : is digit\n",str[i]);
		}
		else{
			printf("[%c] : Not a digit or dot\n",str[i]);
		}
	}
	*/

    return retorno;
}

while (opcion>=6 || opcion <=0)
        {
            printf("\nNo es una opcion valida.\n");
            printf("\n1- Agregar persona\n");
            printf("2- Borrar persona\n");
            printf("3- Imprimir lista ordenada por nombre\n");
            printf("4- Imprimir grafico de edades\n\n");
            printf("5- Salir\n");
            printf("\nIngrese una opcion: ");
            scanf("%d",&opcion);

        }
