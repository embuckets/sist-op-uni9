#include "fifo.h"

char *fifo = "fifo";
int main(int argc, char **argv)
{
    int descriptorarchivo, contador,
        caracteres_escritos;
    char mensajesalida[TAMEN - 1];
    if (argc < 2)
    {
        fprintf(stderr, "\aUso:\n");
        fprintf(stderr, "%smensaje\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    /* Abrir fifo con bandera O_NDELAY */
    if ((descriptorarchivo = open(fifo, O_WRONLY | O_NDELAY)) < 0)
        perror("Fallo el open al abrir el fifo");
    /* Enviar mensaje */
    for (contador = 1; contador < argc; contador++)
    {
        if (strlen(argv[contador]) > TAMEN)
        {
            fprintf(stderr, "Mensaje mur largo %s\n", argv[contador]);
            continue;
        }
        strcpy(mensajesalida, argv[contador]);
        if ((caracteres_escritos = write(descriptorarchivo, mensajesalida, TAMEN - 1)) <= 0)
        {
            if (!caracteres_escritos)
                errno = EAGAIN;
            perror("Fallo el envio del mensaje");
        }
    }
    exit(0);
}