#include "memcom.h"

void inimem(key_t clavemem1, int *shmid1, datos **buffer1,
            key_t clavemem2, int *shmid2, datos **buffer2)
{
    /* Crear segmentos de memoria compartida */
    if ((*shmid1 = shmget(clavemem1, sizeof(datos), PERM | BANDERAS)) == -1)
    {
        /* Si ya existen inicializar */
        if (errno == EEXIST)
            *shmid1 = shmget(clavemem1, sizeof(datos), 0);
        else
            perror("Fallo shmget 1");
    }
    if ((*shmid2 = shmget(clavemem2, sizeof(datos), PERM | BANDERAS)) == -1)
    {
        /* Si ya existen inicializar */
        if (errno == EEXIST)
            *shmid2 = shmget(clavemem2, sizeof(datos), 0);
        else
            perror("Fallo shmget 2");
    }
    /* Direccionar segmentos de memoria compartida */
    if ((*buffer1 = (datos *)shmat(*shmid1, NULL, 0)) == (datos *)(-1))
        perror("Fallo shmat 1");
    if ((*buffer2 = (datos *)shmat(*shmid2, NULL, 0)) == (datos *)(-1))
        perror("Fallo shmat 2");
}

void remover(int shmid1, int shmid2, int semid)
{
    /* Eliminar semáforos y segmentos de memoria compartida */
    if (shmctl(shmid1, IPC_RMID, NULL) < 0)
        perror("fallo shmctl 1");
    if (shmctl(shmid2, IPC_RMID, NULL) < 0)
        perror("fallo shmctl 2");
    if (semctl(semid, 0, IPC_RMID, NULL) < 0)
        perror("fallo semctl ");
}