#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
int main ()
{
	int pid = fork();
	int pipefd[2];
	int ret = pipe(pipefd);
	if(ret < 0)
	{
		perror("pipe error\n");
		return -1;
		}
	 else if(pid == 0)
	 {
		 //子进程读取数据
		 char buf[1024] = {0};
		  ret = read(pipefd[0],buf,1024);//如果没有数据 会堵塞，返回值不会出错
     if(ret< 0)
			{
				printf("child get data[%s]\n",buf);
				}
		}
		else
		{
			//父进程写入数据
			char* ptr = "jin tian !!!";
			ret = write(pipefd[1],ptr,strlen(ptr));// 返回的是写入长度的总长
			}
			if(ret < 0 )
			{
				perror("write error");
				return -1;
				}
			printf("%d\n",ret);

	}
