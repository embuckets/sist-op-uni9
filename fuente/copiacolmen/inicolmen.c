#include "colmen.h"

void inicolmen(key_t clavecolmen1, int *msgid1, key_t clavecolmen2, int *msgid2)
{
    /* Crear colas de mensajes */
    if ((*msgid1 = msgget(clavecolmen1, PERM | BANDERAS1)) == -1)
    {
        /* Si ya existen inicializar */
        if (errno == EEXIST)
            *msgid1 = msgget(clavecolmen1, 0);
        else
            perror("Fallo msgget 1");
        if ((*msgid2 = msgget(clavecolmen2, PERM | BANDERAS1)) == -1)
        {
            /* Si ya existen inicializar */
            if (errno == EEXIST)
                *msgid2 = msgget(clavecolmen2, 0);
            else
                perror("Fallo msgget 2");
        }
    }
}

void remover(int msgid1, int msgid2, int semid)
{
    /* Eliminar semáforos y colas de mensajes*/
    if (msgctl(msgid1, IPC_RMID, NULL) < 0)
        perror("fallo msgctl 1");
    if (msgctl(msgid2, IPC_RMID, NULL) < 0)
        perror("fallo msgctl 2");
    if (semctl(semid, 0, IPC_RMID, NULL) < 0)
        perror("fallo semctl ");
}