#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>


int main(void)
{
        pid_t pid;

        if( (pid = fork()) < 0){
                perror("fork error");
        }
        else if(pid == 0){
                if(execl("/usr/bin/date", "date", (char *) NULL) < 0)
                        perror("execl error");
        }
        if(waitpid(pid, NULL, 0) < 0){
                perror("wait error");
        }

        return 0;
}
