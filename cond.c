#include <stdio.h>
#include <pthread.h>

int is_have_noodle = 0;
void *foodie(void* arg)
{
	while(1)
	{
		if(is_have_noodle==0)
		{
			continue;
			}
			printf("eat noodles,delicious~~!\n");
			is_have_noodle--;
			}
	}
void* chef(void* arg)
{
	while(1)
	{
		printf("cook noddles~~\n");
		is_have_noodle++;
		sleep(1);
		}
}

int main()
{
	pthread_t foodie_tid, chef_tid;
	int ret = 0;

	ret = pthread_create(&foodie_tid, NULL,foodie,NULL);

	ret = pthread_create(&chef_tid,NULL,chef,NULL);


	pthread_join(foodie_tid,NULL);
	pthread_join(chef_tid,NULL);
	}
