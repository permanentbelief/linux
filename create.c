#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

void *thr_start(void* arg)
{
	while(1)
	{
		sleep(1);
	}
		return NULL;
	}
int main()
{
  	pthread_t tid;//野指针 不知道指向哪里 指向一个内存空间，地址指向谁不知道，向tid拷贝数据的时候，拷贝出问题了
	 char* ptr = "this is thread\n";
	  int ret = pthread_create(&tid,NULL,thr_start,(void*)ptr);
		if(ret != 0)
		{
			perror("thread create error");
			return -1;
			}
			return 0;
	}
