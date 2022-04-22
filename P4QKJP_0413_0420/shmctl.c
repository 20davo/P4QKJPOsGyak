#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>

#define SHMKEY 20001213

int main()
{
	int shmid;		
	key_t key;		
	int size=512;
	int shmflg;		
	int rtn;		
	int cmd;		
	struct shmid_ds shmid_ds, *buf; 
	buf = &shmid_ds;	

	key = SHMKEY;

	shmflg = 0;	
	if ((shmid=shmget(key, size, shmflg)) < 0) {
	    perror("Az shmget() system-call sikertelen!\n");
	    exit(-1);
	}

	do
	{
		printf("\nAdd meg a parancs szamat:\n");
		printf("0. IPC_STAT (status)\n");
		printf("1. IPC_RMID (torles)\n> ");
		scanf("%d",&cmd);
	} while (cmd < 0 || cmd > 1);

	switch (cmd)
	{
	    case 0:
		rtn = shmctl(shmid, IPC_STAT, buf);
		printf("Szegmens merete: %ld\n",buf->shm_segsz);
		printf("Utolso shmop()-os processz pid-je: %d\n",buf->shm_lpid);
		break;
	    case 1:
		rtn = shmctl(shmid, IPC_RMID, NULL);
		printf("Szegmens torolve. Hibakod: %d\n", rtn);
	}

	exit(0);

}
