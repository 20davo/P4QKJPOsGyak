#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/file.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main()
{
	int fd, ret;
	char buf[32];

	buf[0]=0;


    ret=mkfifo("p4qkjp",00666);	// letrehozom a fifo-t a filerendszeren
	if (ret == -1) {
	    perror("mkfifo()");
	    exit(-1);
	}

	fd=open("p4qkjp",O_RDWR);	// megnyitom a fifot amit az iment hoztam letre
	if (fd == -1) {
	    perror("open() hiba!");
	    exit(-1);
	}

	strcpy(buf,"Szauter David\n");
	printf("irok a fifoba: %s\n",buf);
	write(fd,buf,strlen(buf)); // irok bele valamit, hogy ne legyen ures

	ret=read(fd,buf,32); // olvasok belole ugyanazt, ret: mennyit sikerult olvasni
	printf("read() olvasott %d byteot, ami a kovetkezo: %s\n",ret,buf);

	close(fd);

	unlink("p4qkjp");	// letorlom a fifomat az fs-rol
}
