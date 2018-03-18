#include "colmen.h"
#include "clavesipc.h"

int main(int argc, char **argv)
{
	int msgid1, msgid2, semid, ent, sal;
	key_t clavesem, clavecolmen1, clavecolmen2;
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

	clavesem = clavesipc(argv[1], 0);
	clavecolmen1 = clavesipc(argv[1], 1);
	clavecolmen2 = clavesipc(argv[1], 2);

	semid = inisem(clavesem);

	inicolmen(clavecolmen1, &msgid1, clavecolmen2, &msgid2);

	if ((ent = open(argv[1], O_RDONLY)) < 0)
		perror("No puede abrir fuente");

	if ((sal = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, PERM)) < 0)
		perror("No puede abrir destino");

	if ((pid = fork()) == -1)
		perror("fallo fork");

	else if (pid)
	{
		enviador(semid, msgid1, msgid2, ent);
		close(ent);
		close(sal);
		remover(msgid1, msgid2, semid);
	}

	else
		receptor(semid, msgid1, msgid2, sal);

	exit(0);
}