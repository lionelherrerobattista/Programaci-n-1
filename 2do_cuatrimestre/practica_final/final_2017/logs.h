

typedef struct{
    char date[11];
    char time[6];
    int serviceId;
    int gravedad;
    char msg[65];
}S_LogEntry;


S_LogEntry* newLog();

/** \brief Valida si el dato ingresado es de tipo int
 *
 * \param auxiliar[] char dato ingresado por el usuario
 * \return int 1 si es int, 0 si no es int
 *
 */
int esNumero(char auxiliar[]);

/** \brief Valida si el dato ingresado es de tipo char
 *
 * \param auxiliar[] char dato ingresado por el usuario
 * \return int 1 si es char, 0 si no es
 *
 */
int esLetra(char auxiliar[]);

/** \brief Valida que el dato ingresado sea alfanum�rico
 *
 * \param auxiliar[] char dato ingresado por el usuario
 * \return int 1 si es alfanum�rico, 0 si no lo es
 *
 */
int esAlfanumerico(char auxiliar[]);
