
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    int i;
    int j;
    //Creo auxiliar
    void* auxElementI=NULL;
    void* auxElementJ=NULL;

    if(this!=NULL && pFunc!=NULL)
    {
        if(order==0 || order==1)
        {

            for(i=1;i<ll_len(this);i++)
            {
                //Empiezo en indice 1 y voy avanzando hacia la derecha con cada iteración
                auxElementI=ll_get(this, i);
                j=i-1;

                if(order==1)
                {
                    //Comparo con el de la izquierda
                    while(j>=0 && pFunc(auxElementI,ll_get(this,j))<0)//Cantidad desc
                    {
                        auxElementJ=ll_get(this, j);
                        ll_set(this, j+1, auxElementJ);
                        //muevo todo para la derecha
                        j--;
                    }

                    //inserto en la ultima posición a la izquierda
                    ll_set(this, j+1, auxElementI);
                    returnAux=0;
                }

                if(order==0)
                {
                    //Comparo con el de la izquierda
                    while(j>=0 && pFunc(auxElementI,ll_get(this,j))>0)//Cantidad desc
                    {
                        auxElementJ=ll_get(this, j);
                        ll_set(this, j+1, auxElementJ);
                        //muevo todo para la derecha
                        j--;
                    }

                    //inserto en la ultima posición a la izquierda
                    ll_set(this, j+1, auxElementI);

                    returnAux=0;
                }
            }

        }


    }

    return returnAux;

}

//Función con el criterio de ordenamiento
int ordenar(void* tramiteUno, void* tramiteDos)
{
    //tengo que pasarlos a un auxiliar para utilizar el operador flecha
    S_TramiteUrgente* pAuxUrgenteUno;
    S_TramiteUrgente* pAuxUrgenteDos;

    pAuxUrgenteUno = (S_TramiteUrgente*) tramiteUno;
    pAuxUrgenteDos= (S_TramiteUrgente*) tramiteDos;

    int retorno = 0;

    if(pAuxUrgenteUno->dni <= pAuxUrgenteDos->dni)
    {
        retorno = -1; //ordeno
    }
    else
    {
        if(pAuxUrgenteUno->dni > pAuxUrgenteDos->dni)
        {
            retorno = 1;//no ordeno
        }
    }

    return retorno;
}
