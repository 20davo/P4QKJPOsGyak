#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>

#define KEY 41234L
#define PERM 00666

int main() {

    int id; 		

	if ((id = semget(KEY, 1, 0)) < 0) { 
		perror(" M?r nem l?tezik a szemafor. ");
		exit(-1);
	}

	if (semctl(id, 0, IPC_RMID, 0) < 0) {
		perror(" Nem siker?lt t?r?lni.");
		exit(-1);
	}

	puts(" A szemafort megsz?ntett?k. \n");
	exit(0);
}

