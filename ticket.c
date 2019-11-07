#include <stdio.h>
#include <pthread.h>

#define MAX_THR 4
int tickets = 100;

void *cattle(void *arg)
{
	while(1)
	{
		if(tickets >0 )
		{
			printf(" %p  i get a ticket:%d\n",pthread_self(), tickets--);//获取线程id
			// usleep(1000);
			// ticket--;              //四个线程都判断还有票 一起进来执行 抢票 就会一个票几个线程抢的一样的状况出现
		}

			else
			{
				printf("have no tickets\n");
				pthread_exit(NULL);
				}
			}
	return NULL;
	}
int main()
{
	pthread_t tid[MAX_THR];
	int i;
	for( i = 0; i < MAX_THR; i++)
	{
		int ret = pthread_create(&tid[i],NULL,cattle,NULL);
	/*	if(ret!=0)
		{
			printf("thread create error\n");
			return -1;
			}
			*/
	}
	int j ;
	for( j = 0; j < MAX_THR; j++)// 线程等待
	{
		pthread_join(tid[j],NULL);
		}
		return 0; //因为这里要退出进程 所有线程都得退出，所以在退出前得线程等待
	 
}
