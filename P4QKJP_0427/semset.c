#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>

#define KEY 001213
#define PERM 00666

main( ) {
    int	id; 
 
	if ((id = semget(KEY, 1, 0)) < 0) { 
		if ((id = semget(KEY, 1, PERM | IPC_CREAT)) < 0) {
		 	perror(" A szemafor nem nyithat� meg. ");
			exit(-1);
		}
	}
	else    {
		perror(" M�r l�tezik a szemafor. ");
		exit(0);
	}

	if (semctl(id, 0, SETVAL, 1) < 0) {
		perror(" Nem lehetett inicializ�lni. ");
	} else {
		puts(" K�sz �s inicializ�lt a szemafor. ");
	}

	exit(0);
}

