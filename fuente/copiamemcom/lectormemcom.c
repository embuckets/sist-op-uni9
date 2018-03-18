#include "memcom.h"

void enviador(int semid, datos *buffer1, datos *buffer2, int da)
{
    for (;;)
    {
        /* Leer en el buffer1 */
        buffer1->leidos = read(da, buffer1->buffer, TAM);
        /* Punto de sincronización */
        v(semid, 0);
        p(semid, 1);
        /* Prueba de que el receptor esta dormido */
        if (buffer1->leidos <= 0)
            return;
        /* Leer en el buffer2 */
        buffer2->leidos = read(da, buffer2->buffer, TAM);
        /* Punto de sincronización */
        v(semid, 0);
        p(semid, 1);
        /* Prueba de que el receptor esta dormido */
        if (buffer2->leidos <= 0)
            return;
    }
}