#include "fifo.h"

char *fifo = "fifo";
int main(void)
{
    int descriptorarchivo;
    char mensajentrada[TAMEN - 1];
    /* Abrir fifo para lectura y escritura*/
    if ((descriptorarchivo = open(fifo, O_RDWR)) < 0)
        perror("Fallo el open al abrir el fifo");
    /* Recibir mensaje */
    for (;;)
    {
        if (read(descriptorarchivo, mensajentrada, TAMEN - 1) < 0)
            perror("Fallo la recepción del mensaje");
        if (!strcmp(mensajentrada, "Terminar"))
        {
            printf("Terminando la recepcion de mensajes\n");
            exit(0);
        }
        else
            printf("Mensaje Recibido: %s\n", mensajentrada);
    }
    exit(0);
}