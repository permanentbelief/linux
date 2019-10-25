#include <stdio.h>
#include <unistd.h>
#include<fcntl.h>
int main()
{
	close(1);
	int fd = open("./tmp.txt",O_RDWR);
	printf("%d\n",fd);
	fflush(stdout);
	close(fd);
	return 0;
	}
