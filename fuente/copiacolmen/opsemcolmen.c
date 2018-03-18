#include "colmen.h"

int p(int semid, int sem)
{
	struct sembuf bufferopp;
	char mensaje[15];
	char num[2];

	bufferopp.sem_num = sem;
	bufferopp.sem_op = -1;
	bufferopp.sem_flg = 0;

	if (semop(semid, &bufferopp, 1) == -1)
	{
		strcpy(mensaje, "Fallo p(");
		sprintf(num, "%i", sem);
		strcat(mensaje, num);
		strcat(mensaje, ")");
		perror(mensaje);
	}

	else
		return (0);
}

int v(int semid, int sem)
{
	struct sembuf bufferopv;
	char mensaje[15];
	char num[2];

	bufferopv.sem_num = sem;
	bufferopv.sem_op = 1;
	bufferopv.sem_flg = 0;

	if (semop(semid, &bufferopv, 1) == -1)
	{
		strcpy(mensaje, "Fallo v(");
		sprintf(num, "%i", sem);
		strcat(mensaje, num);
		strcat(mensaje, ")");
		perror(mensaje);
	}

	else
		return (0);
}

int inisem(key_t clavesem)
{
	int estado0 = 0, estado1 = 0, semid;

	if ((semid = semget(clavesem, 2, PERM | IPC_CREAT | IPC_EXCL)) == -1)
	{
		if (errno == EEXIST)
			semid = semget(clavesem, 2, 0);
	}

	else
	{
		estado0 = semctl(semid, 0, SETVAL, 0);
		estado1 = semctl(semid, 1, SETVAL, 0);
	}

	if (semid == -1 || estado0 == 1 || estado1 == -1)
		//horror("fallo inisem", 17);
		perror("fallo inisem");

	else
		return (semid);
}
