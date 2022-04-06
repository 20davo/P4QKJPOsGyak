#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int pid;

	if(argc < 1)
	{
		perror("Nincs kinek");
		exit(1);
	}

	pid = atoi(argv[1]);
	kill(pid, SIGTERM);
}
