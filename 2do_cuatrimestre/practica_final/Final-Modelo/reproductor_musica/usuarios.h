

//id,nombre,email,sexo,pais,password,ip_address

typedef struct{

    int id;
    char nombre[100];
    char email[100];
    char sexo[100];
    char pais[100];
    char password[100];
    char ip_address[100];

}eUsuario;

eUsuario* newUsuario();
