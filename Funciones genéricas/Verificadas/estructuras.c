

//Estructuras:
int inicializarArrayEstructura(ePersona listaPersonas[],int longitud, int valor)
{
    int i;
    int flag=0;//No esta cargado

    for(i=0;i<longitud;i++)
    {
        listaPersonas[i].legajo=valor;
    }

    if(i==longitud)
    {
        flag=1;//Está cargado
    }

    return flag;

}

int agenda_buscarPrimeraOcurrencia(ePersona listaPersonas[], int longitud, int valor)
{
    int i;
    int retorno=-1;

    for(i=0;i<longitud;i++)
    {
        if(listaPersonas[i].legajo==valor)
        {
            retorno=i;
            break;
        }
    }

    return retorno;
}

//Estructuras y Listas:
int agenda_mostrarLista(ePersona listaPersonas[], int longitud)
{
    int i;
    int flag=0;//No mostró todo

    for(i=0;i<longitud; i++)
    {
        if(listaPersonas[i].legajo!=-1)
        {
            printf("%-15d %-15s %-15s\n",listaPersonas[i].legajo, listaPersonas[i].nombre, listaPersonas[i].apellido);
        }
    }

    if(i==longitud)
    {
        flag=1;//Mostró todo
    }

    return flag;
}

int agenda_ordenarListaApellidos(ePersona listaPersonas[], int longitud)
{
    int i;
    int j;
    int flag=0;//No está ordenado

    //Creo una estructura auxiliar
    ePersona auxiliarLista;



    for(i=1;i<longitud;i++)
    {
        if(listaPersonas[i].legajo==-1)//Si está vacío
        {
            continue;//Paso a la proxima iteración
        }

        //Empiezo en indice 1 y voy avanzando hacia la derecha con cada iteración
        auxiliarLista=listaPersonas[i];
        j=i-1;

        //Comparo con el de la izquierda
        while(j>=0 && stricmp(auxiliarLista.apellido,listaPersonas[j].apellido)<0)//Apellido A-Z
        {
            listaPersonas[j+1] = listaPersonas[j];//muevo todo para la derecha
            j--;
        }

        //inserto en la ultima posición a la izquierda
        listaPersonas[j+1]=auxiliarLista;
    }

    if(i==longitud)
    {
        flag=1;
    }

    return flag;
}
