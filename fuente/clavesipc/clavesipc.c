#include "clavesipc.h"
#include "memcom.h"

key_t clavesipc(char *archivo, int id)
{
    key_t clave;
    char mensaje[80];
    char num[10];
    if ((clave = ftok(archivo, id)) < (key_t)0)
    {
        strcpy(mensaje, "Fallo asignación de clave ipc(");
        strcat(mensaje, archivo);
        sprintf(num, "%i", id);
        strcat(mensaje, ") (");
        strcat(mensaje, num);
        strcat(mensaje, ")");
        perror(mensaje);
    }
    return (clave);
}
