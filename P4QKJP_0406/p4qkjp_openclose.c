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

	buf[0] = 0;

	fd = open("fajl.txt", O_RDWR);

	if (fd == -1) {
		perror("open() hiba!");
		exit(-1);
	}

	ret = read(fd, buf, 32);
	printf("read() olvasott %d byteot, ami a kovetkezo: %s\n", ret, buf);
	strcpy(buf, "p4qkjp");

	ret = lseek(fd , 0, SEEK_SET);
	printf("lseek() mondja: %d\n", ret);

	ret = write(fd, buf, 6);
	printf("write() mondja: %d\n", ret);

	close(fd);
}

