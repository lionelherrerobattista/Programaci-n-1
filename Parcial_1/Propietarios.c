#include <stdio.h>
#include "Propietarios.h"
#include <stdlib.h>
#include <strings.h>

#define LIBRE 1
#define OCUPADO 0

#define ALPHA_ROMEO 1
#define FERRARI 2
#define AUDI 3
#define OTRO 4

void inicializarPropietario (ePropietarios propietarios[], int limite)
{
    int i;

    for(i=0; i<limite; i++)
    {
        propietarios[i].estado=LIBRE;
        propietarios[i].idPropietario=0;
    }
}

void inicializarAutos (eAutos autos[], int limite)
{
    int i;

    for(i=0; i<limite; i++)
    {
        autos[i].estado=LIBRE;
        autos[i].idAuto=0;
    }
}

void inicializarPropietariosHardCode(ePropietarios propietarios[], int limite)
{
    int id[]= {1,2,3,4};
    char nombre[][20]= {"Juan","Luis","Maria","Jose"};
    char tarjeta[][20]= {"111-111","222-222","333-333","444-444"};
    char direccion[][20]= {"mitre","urquiza","belgrano","alsina"};


    int i;

    for (i=0; i<4; i++)
    {
        propietarios[i].idPropietario=id[i];
        strcpy(propietarios[i].nombreApellido, nombre[i]);
        strcpy(propietarios[i].numeroTarjeta,tarjeta[i]);
        strcpy(propietarios[i].direccion, direccion[i]);
        propietarios[i].estado=OCUPADO;
    }

}

void inicializarAutosHardCode(eAutos autos[], int limite)
{
    int id[]= {1,2,3,4,5,6,7,8,9,10};
    char patente[][20]= {"AAA","CCC","DDD","BBB","ZZZ","III","HHH","EEE","FFF","GGG"};
    int marca[]= {ALPHA_ROMEO,AUDI,AUDI,FERRARI,FERRARI,AUDI,AUDI,OTRO,AUDI,ALPHA_ROMEO};
    int propietario[]= {2,1,2,1,3,3,4,1,4,3};


    int i;

    for (i=0; i<10; i++)
    {
        autos[i].idAuto=id[i];
        strcpy(autos[i].patente, patente[i]);
        autos[i].marca=marca[i];
        autos[i].idPropietario=propietario[i];
        autos[i].estado=OCUPADO;
    }

}

void mostrarPropietarios (ePropietarios propietarios[], int limite)
{
    int i;

    printf("\n%-10s %-10s %-10s %-10s\n","Id:","Nombre:","Direccion:","Tarjeta:");
    for (i=0; i<limite; i++)
    {

        if (propietarios[i].estado==OCUPADO)
        {
            printf("%-10d %-10s %-10s %-10s\n",propietarios[i].idPropietario, propietarios[i].nombreApellido, propietarios[i].direccion, propietarios[i].numeroTarjeta);
        }

    }
}

void altaPropietario (ePropietarios propietarios[], int limite)
{
    int index;


    index=buscarLibre(propietarios, limite);

    if (index>=0)
    {
        printf("\nIngrese su nombre y apellido: ");
        fflush(stdin);
        gets(propietarios[index].nombreApellido);

        printf("Ingrese su direccion: ");
        fflush(stdin);
        gets(propietarios[index].direccion);

        printf("Ingrese su numero de tarjeta: ");
        fflush(stdin);
        gets(propietarios[index].numeroTarjeta);

        propietarios[index].idPropietario=siguienteId(propietarios, limite);

        propietarios[index].estado=OCUPADO;
    }
}

int buscarLibre (ePropietarios propietarios[], int limite)
{
    int i;
    int retorno=-2;

    for (i=0; i<limite; i++)
    {
        if(propietarios[i].estado==LIBRE)
        {
            retorno=i;
            break;
        }
    }

    return retorno;
}

int siguienteId(ePropietarios propietarios[], int limite)
{
    int retorno=0;
    int i;

    for(i=0; i<limite; i++)
    {
        if(propietarios[i].estado==OCUPADO)
        {
            if(propietarios[i].idPropietario>retorno)
            {
                retorno=propietarios[i].idPropietario;
            }
        }
    }


    return retorno+1;

}

void modificarPropietario (ePropietarios propietarios[], int limite)
{
    int id=0;
    int i;
    int flag=0;
    int respuesta;

    printf("\nIngrese el id del propietario que desea modificar: ");
    scanf("%d", &id);



    for (i=0; i<limite;i++)
    {
        if (propietarios[i].idPropietario==id)
        {
            printf("\nEsta seguro que quiere modificar su tarjeta? (s/n)");
            fflush(stdin);
            respuesta=getchar();

            if (respuesta=='s')
            {
               for (i=0; i<limite; i++)
                {
                    if (propietarios[i].idPropietario==id)
                    {
                        printf("\nIngrese su numero de tarjeta: ");
                        fflush(stdin);
                        gets(propietarios[i].numeroTarjeta);
                    }
                }
            }
            flag=1;
        }

    }
    if (flag==0)
    {
            printf("\nNo se encontro el id.");
    }




}

void bajaPropietario (ePropietarios propietarios[], int limite)
{
    int id;
    int i;
    int flag=0;
    char respuesta;

    printf("\nIngrese el id del propietario que quiere dar de baja: ");
    scanf("%d",&id);


    for (i=0; i<limite;i++)
    {
        if (propietarios[i].idPropietario==id)
        {
            printf("\nEsta seguro que quiere dar de baja? (s/n)");
            fflush(stdin);
            respuesta=getchar();

            if(respuesta=='s')
            {
                for (i=0; i<limite; i++)
                {
                    if (propietarios[i].idPropietario==id)
                    {
                       propietarios[i].estado=LIBRE;
                    }
                }
            }

            flag=1;
        }

    }

    if (flag==0)
    {
            printf("\nNo se encontro el id.");
    }

}

void altaAuto (eAutos autos[], int limite)
{
    int index;


    index=buscarLibreAuto(autos, limite);

    if (index>=0)
    {
        printf("\nIngrese la patente: ");
        fflush(stdin);
        gets(autos[index].patente);

        printf("\nIngrese marca: ");
        printf("\n1.ALPHA_ROMEO");
        printf("\n2.FERRARI");
        printf("\n3.AUDI");
        printf("\n4.OTRO\n");
        scanf("%d", &autos[index].marca);


        printf("Ingrese su id: ");
        scanf("%d", &autos[index].idPropietario);


        autos[index].idAuto=siguienteIdAuto(autos, limite);

        autos[index].estado=OCUPADO;
    }
}

int buscarLibreAuto (eAutos autos[], int limite)
{
    int i;
    int retorno=-2;

    for (i=0; i<limite; i++)
    {
        if(autos[i].estado==LIBRE)
        {
            retorno=i;
            break;
        }
    }

    return retorno;
}

int siguienteIdAuto(eAutos autos[], int limite)
{
    int retorno=0;
    int i;

    for(i=0; i<limite; i++)
    {
        if(autos[i].estado==OCUPADO)
        {
            if(autos[i].idAuto>retorno)
            {
                retorno=autos[i].idAuto;
            }
        }
    }


    return retorno+1;

}


void mostrarAutos(ePropietarios propietario[], int limitePropietario, eAutos autos[], int limiteAutos)
{
    int i;//autos
    int j;//propietarios
    char marca[][20]={"ALPHA_ROMEO","FERRARI","AUDI","OTRO"};



    printf("\n%-15s %-15s %-15s %-15s\n","Id:","Patente:","Marca:","Propietario:");


    for(i=0; i<limiteAutos; i++)
    {
        for (j=0; j<limitePropietario; j++)
        {
            if(autos[i].idPropietario==propietario[j].idPropietario && autos[i].estado==OCUPADO)
            {

                printf("%-15d %-15s %-15s %-15s\n", autos[i].idAuto, autos[i].patente, marca[autos[i].marca-1], propietario[j].nombreApellido);

            }


        }

    }
}

/*void egresoAutomovil ()
{

    int id;
    int i;
    int flag=0;
    char respuesta;

    printf("\nIngrese el id del auto que egresa: ");
    scanf("%d",&id);


    for (i=0; i<limite;i++)
    {
        if (propietarios[i].idPropietario==id)
        {
            printf("\nEsta seguro que quiere dar de baja? (s/n)");
            fflush(stdin);
            respuesta=getchar();

            if(respuesta=='s')
            {
                for (i=0; i<limite; i++)
                {
                    if (propietarios[i].idPropietario==id)
                    {
                       propietarios[i].estado=LIBRE;
                    }
                }
            }

            flag=1;
        }

    }

    if (flag==0)
    {
            printf("\nNo se encontro el id.");
    }

}*/


/*
int devolverHorasEstadia()
{
    int horas;

    srand(time(NULL));

    horas = (rand()%24)+1;

    return horas ;

}*/









