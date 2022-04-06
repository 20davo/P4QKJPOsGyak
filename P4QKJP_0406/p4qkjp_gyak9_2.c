#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>

void kezelo(int i)
{
	printf("Signal kezelese: %d\n", i);
	return;
}

int main (void)
{
	printf("PID = %d\n", getpid());
	printf("Szignal kezelo atvetele: %d\n", signal(SIGTERM, &kezelo));
	while(1){
		printf("lepes\n");
		sleep(3);
	}
}


