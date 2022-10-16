#include<stdio.h>
#include<signal.h>
#include<unistd.h>
int main()
{
	int ret=signal(22,SIG_IGN);
	printf("%d\n",ret);
	while(1)
	{
		printf("3");
	}
}
