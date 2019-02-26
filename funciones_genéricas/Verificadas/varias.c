
//Funcion que muestra un menú de opciones
void mostrarMenu()
{
    printf("---------------------------\n");
    printf("1-opcion 1\n");
    printf("2-opcion 2\n");
    printf("3-opcion 3\n");
    printf("4-Salir\n");
    printf("---------------------------\n");

}

void mostrarInfo(void* auxLogs, void* auxServices)
{
	//Acá paso de void a tipo de dato de la estructura:
	/*S_LogEntry* pAuxLog;
	pAuxLog = newLog();
	pAuxLog = punteroUno;*/
	
    printf("%s;%s;%s;%s;%d\n", pAuxLog->date, pAuxLog->time, auxServices->name,
            pAuxLog->msg, pAuxLog->gravedad);
}

//Muestro elementos de dos listas
void mostrarTramites(LinkedList* listaTramitesUrgentes, LinkedList* listaTramitesRegulares)
{
    int i=0;
    int j=0;

    S_TramiteUrgente* pAuxTramiteUrgente;
    S_TramiteRegular* pAuxTramiteRegular;

    pAuxTramiteUrgente = newTramiteUrgente();
    pAuxTramiteRegular = newTramiteRegular();

    printf("%5s %15s\n", "Puesto","DNI");

    if(listaTramitesUrgentes != NULL && listaTramitesRegulares != NULL)
    {
        if(ll_len(listaTramitesUrgentes) != 0)
        {
            for(i = 0; i < ll_len(listaTramitesUrgentes); i++)
            {
                pAuxTramiteUrgente = ll_get(listaTramitesUrgentes, i);

                printf("%5d %15ld\n", i+1, pAuxTramiteUrgente->dni);
            }
        }

        if(ll_len(listaTramitesRegulares) != 0)
        {
            for(j = 0; j < ll_len(listaTramitesRegulares); j++)
            {
                pAuxTramiteRegular = ll_get(listaTramitesRegulares, j);
                printf("%5d %15ld\n", i+1, pAuxTramiteRegular->dni);
                i++;
            }
        }
    }
}

//Muestro el primer elemento de una lista (con datos cruzados de otra lista)
void mostrarProximoTurno(LinkedList* listaTramitesUrgentes, LinkedList* listaTramitesRegulares)
{

    S_TramiteUrgente* pAuxTramiteUrgente;
    S_TramiteRegular* pAuxTramiteRegular;

    pAuxTramiteUrgente = newTramiteUrgente();
    pAuxTramiteRegular = newTramiteRegular();

    printf("Siguiente turno: ");

    if(listaTramitesUrgentes != NULL && listaTramitesRegulares != NULL)
    {
        if(ll_len(listaTramitesUrgentes) != 0)
        {
            pAuxTramiteUrgente = ll_get(listaTramitesUrgentes, 0);

            printf("%ld ", pAuxTramiteUrgente->dni);
            printf("(Tramite urgente)\n");
        }
        else
        {

            if(ll_len(listaTramitesRegulares) != 0)
            {
                    pAuxTramiteRegular = ll_get(listaTramitesRegulares, 0);
                    printf("%ld", pAuxTramiteRegular->dni);
                    printf("(Tramite regular)\n");
            }
            else
            {
                printf("No hay turnos por atender.\n");
            }

        }


    }
}
