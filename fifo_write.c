
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

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
	 int fd = open(file,O_WRONLY);//若文件以只读的方式打开 则会阻塞，直到文件以写的方式被其它进程打开
	 if(fd < 0 )
	 {
		 perror("open error");
		 return -1;
		 }
		printf("open success\n");
while(1)
{
			char buf[1024] = {0};
			scanf("%s",buf);
			int ret = write(fd,buf,strlen(buf));			
			if(ret == 0)
			{
				printf("管道没人读了~~所有写端被关闭\n");
				return 0;
			}
			else if(ret < 0 )
			{
				perror("write  error");
				return -1;
			}
				printf("buf:[%s]\n",buf);
}
	return 0;
	}
