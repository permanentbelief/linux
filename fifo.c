#include <stdio.h>
#include <fcntl.h>
#include <errno.h>

int main()
{
	char *file ="./test.fifo";
	int ret = mkfifo(file,0644);
	if(ret < 0)
		{
			if(errno != EEXIST)
			{
			perror("mkfifo error");
			return -1;
				}
		}
	 int fd = open(file,O_RDWR);//若文件以只读的方式打开 则会阻塞，直到文件以写的方式被其它进程打开
	 if(fd < 0 )
	 {
		 perror("open error");
		 return -1;
		 }
		printf("open success\n");
	return 0;
	}
