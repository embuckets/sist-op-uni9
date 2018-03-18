#include "memcom.h"

void receptor(int semid, datos *buffer1, datos *buffer2, int da)
{
    for (;;)
    {
        /* Punto de sincronización */
        p(semid, 0);
        v(semid, 1);
        /* Prueba de que el enviador esta dormido */
        if (buffer1->leidos <= 0)
            return;
        /* escribir del buffer1 */
        write(da, buffer1->buffer, buffer1->leidos);
        /* Punto de sincronización */
        p(semid, 0);
        v(semid, 1);
        /* Prueba de que el enviador esta dormido */
        if (buffer2->leidos <= 0)
            return;
        /* Escribir del buffer2 */
        write(da, buffer2->buffer, buffer2->leidos);
    }
}