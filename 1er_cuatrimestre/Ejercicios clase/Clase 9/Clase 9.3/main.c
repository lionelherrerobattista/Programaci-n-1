#include <stdio.h>
#include <stdlib.h>

/*Usuario                            Serie (1 usuario puede ver solo 1 serie)
  int idUsuario  (pk)                   idSerie(pk)
  char nombre                       nombre
  int estado(alta, baja, mod)       genero
  int idSerie     (fk)                cantidad de temporadas
                                    estado

1 BB Policial 5temp 1
2 GOT fantas�a 9    1
3 ST terror    2    1

10 Juan 1 | 2 GOT fantas�a 9 1
11 Mar�a 1| 3 ST  terror   2 1
12 Pedro 1| 2 GOT fantas�a 9 1


Composici�n dentro del usuario

Grupos repetitivos: genera redundancia                           */

int main()
{
    printf("Hello world!\n");
    return 0;
}
