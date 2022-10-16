#include<stdio.h>
#include<unistd.h>
main()
{
	pid_t pid;
	printf("%d\n",getpid());
	while(1);
}
