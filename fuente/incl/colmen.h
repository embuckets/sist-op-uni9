#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/sem.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define PERM 0600
#define BANDERAS1 (IPC_CREAT | IPC_EXCL)
#define BANDERAS2 (MSG_NOERROR | IPC_NOWAIT)
#define TAM (int)(BUFSIZ / 3)

typedef struct _datos
{
	int leidos;
	char buffer[TAM];
} datos;
int p(int, int);
int v(int, int);
int inisem(key_t);
void receptor(int, int, int, int);
void enviador(int, int, int, int);
void inicolmen(key_t, int *, key_t, int *);
void remover(int, int, int);