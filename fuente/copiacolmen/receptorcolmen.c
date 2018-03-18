#include "colmen.h"

void receptor(int semid, int colaid1, int colaid2, int da)
{

	datos buffer1, buffer2;
	for (;;)
	{
		p(semid, 0);
		v(semid, 1);

		if ((buffer1.leidos = msgrcv(colaid1, &buffer1, TAM, 0, BANDERAS2)) < 0)
			perror("Fallo msgrcv 1");

		if (buffer1.leidos <= 0)
			return;

		write(da, buffer1.buffer, buffer1.leidos);

		p(semid, 0);
		v(semid, 1);

		if ((buffer2.leidos = msgrcv(colaid2, &buffer2, TAM, 0, BANDERAS2)) < 0)
			perror("Fallo msgrcv 2");

		if (buffer2.leidos <= 0)
			return;

		write(da, buffer2.buffer, buffer2.leidos);
	}
}