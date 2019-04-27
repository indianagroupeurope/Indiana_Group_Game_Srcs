#include <stdio.h>
#include <stdlib.h>

void WriteVersion()
{
#ifndef __WIN32__
	FILE* fp(fopen("version.txt", "w"));

	if (NULL != fp)
	{
		fprintf(fp, "game perforce revision: %s\n", __DB_VERSION__);
		// fprintf(fp, "%s@%s:%s\n", __USER__, __HOSTNAME__, __PWD__);
		fclose(fp);
	}
	else
	{
		fprintf(stderr, "cannot open version.txt\n");
		exit(0);
	}
#endif
}

