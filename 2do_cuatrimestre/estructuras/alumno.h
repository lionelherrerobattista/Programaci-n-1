typedef struct
{
    int legajo;
    char nombre[50];
    float promedio;
    char direccion[50];

}eAlumno;

void mostrarAlumno(eAlumno);


//Cargo un alumno
eAlumno cargarAlumno();

//Cargar el listado
void cargarListado(eAlumno[],int);

void mostrarListado(eAlumno[],int);
