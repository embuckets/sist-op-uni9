#include "fifo.h"

char *ida = "ida";
char *vuelta = "vuelta";

int main(void)
{
    int descIda, descVuelta, caracteres_escritos;
    char mensajentrada[TAMEN - 1];
    char mensajesalida[TAMEN - 1];

    /* Abrir fifo para lectura y escritura*/
    if ((descIda = open(ida, O_RDWR)) < 0)
        perror("[Receptor]: Fallo el open al abrir el fifo ida");
    if ((descVuelta = open(vuelta, O_RDWR)) < 0)
        perror("[Receptor]: Fallo el open al abrir el fifo ida");

    /* Recibir mensaje */
    for (;;)
    {
        if (read(descIda, mensajentrada, TAMEN - 1) < 0)
            perror("[Receptor]: Fallo la recepción del mensaje");
        printf("[Receptor]: Mensaje Recibido: %s\n", mensajentrada);
        if (!strcmp(mensajentrada, "terminar"))
        {
            strcpy(mensajesalida, mensajentrada);
            if ((caracteres_escritos = write(descVuelta, mensajesalida, TAMEN - 1)) <= 0)
            {
                if (!caracteres_escritos)
                    errno = EAGAIN;
                perror("[Enviador]:Fallo el envio del mensaje");
            }
            printf("[Receptor]: Terminando la recepcion de mensajes\n");
            exit(0);
        }
        else
        {
            strcpy(mensajesalida, mensajentrada);
            if ((caracteres_escritos = write(descVuelta, mensajesalida, TAMEN - 1)) <= 0)
            {
                if (!caracteres_escritos)
                    errno = EAGAIN;
                perror("[Enviador]:Fallo el envio del mensaje");
            }
        }
        sleep(1);
    }
    exit(0);
}