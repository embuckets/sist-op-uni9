#include "colmen.h"

void enviador(int semid, int colaid1, int colaid2, int da)
{
	datos buffer1, buffer2;
	long bytes;

	for (;;)
	{
		if ((bytes = read(da, buffer1.buffer, TAM)))
			buffer1.leidos = bytes;

		else
			buffer1.leidos = bytes + 1;

		if (msgsnd(colaid1, &buffer1, bytes, 0) < 0)
		{
			fprintf(stderr, " buffer1.leidos %i\n", buffer1.leidos);
			perror("Fallo msgsnd 1");
			return;
		}

		v(semid, 0);
		p(semid, 1);

		if (bytes <= 0)
			return;

		if ((bytes = read(da, buffer2.buffer, TAM)))
			buffer2.leidos = bytes;

		else
			buffer2.leidos = bytes + 1;

		if (msgsnd(colaid2, &buffer2, bytes, 0) < 0)
		{
			fprintf(stderr, " buffer2.leidos %i\n", buffer2.leidos);
			perror("Fallo msgsnd 2");
			return;
		}

		v(semid, 0);
		p(semid, 1);

		if (bytes <= 0)
			return;
	}
}