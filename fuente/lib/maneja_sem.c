#include "sem.h"

/* Inicialización y manejo de los
semaforos */
void maneja_sem(key_t clavesem)
{

    pid_t semid, pid = getpid();
    /* Creación e inicialización de los
semaforos */
    if ((semid = iniciasem(clavesem)) < 0)
        perror("Fallo iniciasem");
    printf("\nProceso %i ANTES de la sección crítica\n", pid);
    /* Intentar accesar sección crítica */
    p(semid);
    printf("\nProceso %i en la SECCIóN CRíTICA\n", pid);
    /* Hacer algo */
    sleep(10);
    /* Liberar sección crítica */
    v(semid);
    printf("\nProceso %i DESPUES de la sección crítica\n", pid);
    printf("\nProceso %i terminando \n\r", pid);
    exit(0);
}