#include <stdio.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#define IPC_KEY 0x12345678

int main()
{
	int shmid = shmget(IPC_KEY,4096,IPC_CREAT | 0664);
	if(shmid <0)
	{
		printf("shmget error");
		return -1;
		}
	void *shm_start = shmat(shmid,NULL,0);// 建立映射关系
	if(shm_start ==(void*)-1)
	{
		perror("shmat error");
		return -1;
		}
		int i = 0;
		while(1)
		{
			sprintf(shm_start,"%s-%d\n","今天天气暖洋洋~\n",i++);
			sleep(1);


		}
		//解除映射关系
		shmdt(shm_start);
		//删除共享内存
		shmctl(shmid,IPC_RMID,NULL);
		return 0;
}
