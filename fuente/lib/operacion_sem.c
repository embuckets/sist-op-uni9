#include "sem.h"

/* Operación p de los semaforos */
int p(int semid)
{
    struct sembuf p_buf;
    /* llenar estructura sembuf */
    p_buf.sem_num = 0;
    p_buf.sem_op = -1;
    p_buf.sem_flg = SEM_UNDO;
    /* Realizar operación p */
    if (semop(semid, &p_buf, 1) == -1)
        perror("Fallo p(semid)");
    else
        return (0);
}

/* Operación v de los semaforos */
int v(int semid)
{
    struct sembuf v_buf;
    /* llenar estructura sembuf */
    v_buf.sem_num = 0;
    v_buf.sem_op = 1;
    v_buf.sem_flg = SEM_UNDO;
    /* Realizar operación v */
    if (semop(semid, &v_buf, 1) == -1)
        perror("Fallo v(semid)");
    else
        return (0);
}

//Inicializa semaforo
int inisem(key_t clavesem)
{

    int estado = 0, semid;
    if ((semid = semget(clavesem, 1, SEM_PERM | IPC_CREAT | IPC_EXCL)) == -1)
    {
        if (errno == EEXIST)
            semid = semget(clavesem, 1, 0);
    }
    else
    {
        estado = semctl(semid, 0, SETVAL, 1);
    }
    if (semid == -1 || estado == -1)
    {
        perror(“Fallo inisem”);
        return (-1);
    }
    else
    {
        return (semid);
    }
}