#include <stdio.h>
#include <stdlib.h>
int main()
{
	char* ptr =getenv("mygod");
	if(ptr == NULL)
	{
	 printf("have no mygod\n");
	}
	printf("mygod = %s\n",ptr);
	return 0;
}
