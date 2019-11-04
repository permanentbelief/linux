#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
//谁先运行不一定 取决于cpu的调度 包含两个执行流 进行两个死循环
void *thr_start(void *arg)
{
  	//sleep(5);
	//return NULL;
	//pthread_exit(NULL);
	while(1)
	{
		printf("child thread--------%s\n",(char*)arg);//线程之间通信比较灵活 只需要知道变量地址就可以访问 打印
		sleep(1);
		}
		return NULL;
	}
	int main()
	{
		pthread_t tid;
		char *ptr ="this is thread\n";
		int ret = pthread_create(&tid,NULL,thr_start,(void*)ptr);
		if(ret !=0)
		{
			perror("thread create error\n");
			return -1;
			}
		sleep(5);
		pthread_cancel(tid);
			while(1)
			{
				printf("main thread---------%d\n",tid);
				sleep(1);
				}
				return 0;
		}
