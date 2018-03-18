#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <error.h>

#define PERM 0600
#define BANDERAS (IPC_CREAT | IPC_EXCL)
/* Tamaño del buffer de lectura y
escritura */
#define TAM 5 * BUFSIZ
/* Estructura de datos para los
buffers */
typedef struct _datos
{
    int leidos;
    char buffer[TAM];
} datos;
int p(int, int);
int v(int, int);
int inisem(key_t);
void receptor(int, datos *, datos *, int);
void enviador(int, datos *, datos *, int);
void inimem(key_t, int *, datos **, key_t, int *, datos **);
void remover(int, int, int);
key_t clavesipc(char *,int);