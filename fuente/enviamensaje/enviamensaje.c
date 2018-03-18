#include "fifo.h"

char *ida = "ida";
char *vuelta = "vuelta";

int main(int argc, char **argv)
{
    int descIda, descVuelta, contador, caracteres_escritos;
    char mensajesalida[TAMEN - 1];
    char mensajentrada[TAMEN - 1];

    if (argc < 2)
    {
        fprintf(stderr, "\aUso:\n");
        fprintf(stderr, "%smensaje\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    /* Abrir fifo con bandera O_NDELAY */
    if ((descIda = open(ida, O_WRONLY | O_NDELAY)) < 0)
        perror("[Enviador]: Fallo el open al abrir el fifo de ida");
    if ((descVuelta = open(vuelta, O_RDONLY)) < 0)
        perror("[Enviador]: Fallo el open al abrir el fifo de vuelta");

    /* Enviar mensaje */
    for (contador = 1; contador < argc; contador++)
    {
        if (strlen(argv[contador]) > TAMEN)
        {
            fprintf(stderr, "[Enviador]: Mensaje mur largo %s\n", argv[contador]);
            continue;
        }
        strcpy(mensajesalida, argv[contador]);
        if ((caracteres_escritos = write(descIda, mensajesalida, TAMEN - 1)) <= 0)
        {
            if (!caracteres_escritos)
                errno = EAGAIN;
            perror("[Enviador]:Fallo el envio del mensaje");
        }
    }

    //unlink(descIda);

    //sleep(2);

    for (;;)
    {
        if (read(descVuelta, mensajentrada, TAMEN - 1) < 0)
            perror("[Enviador]: Fallo la recepción del mensaje");
        if (!strcmp(mensajentrada, "terminar"))
        {
            printf("[Enviador]: Mensaje Recibido: %s\n", mensajentrada);
            printf("[Enviador]: Terminando la recepcion de mensajes\n");
            exit(0);
        }
        else
        {
            printf("[Enviador]: Mensaje Recibido: %s\n", mensajentrada);
        }
    sleep(1);
        
    }
    exit(0);
}