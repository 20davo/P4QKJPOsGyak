#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>

#define KEY 001213
#define PERM 00666

int main() {

int 	id; 		
struct sembuf up[1]  =  {0,  1, SEM_UNDO};
struct sembuf down[1] = {0, -1, SEM_UNDO};

	if ((id = semget(KEY, 1, 0)) < 0) { 
		perror(" Még nem létezik a szemafor. ");
		exit(-1);
	}

	puts(" Itt fut a nem kritikus szakasz. ");

	semop(id, down, 1);   
	puts("    Itt fut a kritikus szakasz. ");	
	semop(id, up, 1);    

	puts(" Itt ismét nem kritikus szakasz fut. ");

	exit(0);
}

