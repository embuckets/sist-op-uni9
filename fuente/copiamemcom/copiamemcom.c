#include "memcom.h"
int main(int argc, char **argv)
{
    int shmid1, shmid2, semid, ent, sal;
    key_t clavesem, clavemem1, clavemem2;
    datos *buffer1, *buffer2;
    pid_t pid;
    if (argc != 3)
    {
        fprintf(stderr, "\a Uso:\n");
        fprintf(stderr, "%s fuente destino \n", argv[0]);
        exit(1);
    }
    if (!strcmp(argv[1], argv[2]))
    {
        fprintf(stderr, "\a Fuente igual al destino \n");
        exit(2);
    }
    /* Obtener Claves ipc */
    clavesem = clavesipc(argv[1], 0);
    clavemem1 = clavesipc(argv[1], 1);
    clavemem2 = clavesipc(argv[1], 2);
    /* Inicializar semáforos */

    semid = inisem(clavesem);
    /* Crear y direccionar segmentos de memoria compartida */
    inimem(clavemem1, &shmid1, &buffer1, clavemem2, &shmid2, &buffer2);
    /* Abrir archivos */
    if ((ent = open(argv[1], O_RDONLY)) < 0)
        perror("No puede abrir fuente");
    if ((sal = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, PERM)) < 0)
        perror("No puede abrir destino");
    /* Crear hijo y hacer la copia */
    if ((pid = fork()) == -1)
        perror("fallo fork");
    else if (pid)
    {
        enviador(semid, buffer1, buffer2, ent);
        /* Cerrar archivos y liberar recursos */
        close(ent);
        close(sal);
        remover(shmid1, shmid2, semid);
    }
    else
        receptor(semid, buffer1, buffer2, sal);
    exit(0);
}