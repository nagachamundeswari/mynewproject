#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
void kill(int,int);
int main(int argc,char *argv[])
{
	int pid,signo;
	pid=atoi(argv[1]);
	signo=atoi(argv[2]);
	if(argc==3)
	{
		printf("start main\n");
		kill(pid,signo);
	}
	else
		printf("no.of arguments are invalid\n");
}
void kill(int pid,int signo)
{
	printf("start\n");
	int r=kill(pid,signo);
	printf("r %d\n",r);
	printf("end\n");
}
