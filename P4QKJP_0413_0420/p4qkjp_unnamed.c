#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
     int pipefd[2];	
     pid_t cpid;	
     char buf;		
     char szoveg[32];	
     int ret;

     if (pipe(pipefd) == -1) {	
	   perror("pipe");
	   exit(-1);
     }

     printf("%d: fd1: %d, fd2: %d\n",getpid(),pipefd[0],pipefd[1]);

     cpid = fork();
     if (cpid == -1) {
	   perror("fork");
	   exit(-1);
     }

     if (cpid == 0) {    
	   printf("%d: szulo vagyok\n",getpid());
	   close(pipefd[1]);    

	   printf("%d: megnezem mi van a csoben...\n%d: ",getpid(),getpid());
	   while (read(pipefd[0], &buf, 1) > 0) {	
		 printf("%c",buf);
	   }
	

	   close(pipefd[0]);	

   	   exit(0);	

     } else {	
	   printf("%d: gyerek vagyok\n",getpid());

   	   close(pipefd[0]);    

	   strcpy(szoveg,"p4qkjp\n");  
	   printf("%d: kuldom a szoveget: %s\n",getpid(),szoveg);

	   write(pipefd[1], szoveg, strlen(szoveg));	

	   close(pipefd[1]);    

	   wait(NULL);    

	   exit(0);
     }
}
