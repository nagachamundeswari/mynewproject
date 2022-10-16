#include<stdio.h>
#include<pthread.h>
void*thread_fun1(void*);
void*thread_fun2(void*);
char str[100];
void main()
{
        pthread_t t1,t2;
        void*ptr;
	printf("enter the string name\n");
	scanf("%[^\n]s",str);
        pthread_create(&t1,NULL,thread_fun1,str);
        pthread_create(&t2,NULL,thread_fun2,str);
        pthread_join(t1,&ptr);
        pthread_join(t2,&ptr);
}
void*thread_fun1(void*ptr)
{
	int i;
	str[100]=*(char *)ptr;
	for(i=0;str[i]!='\0';i++)
	{	
		if(str[i]>=65 &&  str[i]<=90)
        	printf("capital letter %c\n",str[i]);
	}
}
void*thread_fun2(void*ptr)
{
	int i;
	str[100]=*(char *)ptr;
	for(i=0;str[i]!='\0';i++)
	{	
		if(str[i]>=97 && str[i]<=122)
        	printf("small letter %c\n",str[i]);
	}
}

