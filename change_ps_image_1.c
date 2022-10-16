#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
void main()
{
	int x;
	char*const argv[]={"ls",0};
	x=execvp("ps",argv);
	printf("%d\n",x);
}




