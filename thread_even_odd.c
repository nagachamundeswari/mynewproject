#include<stdio.h>
#include<pthread.h>
void*thread_fun1(void*);
void*thread_fun2(void*);
void main()
{
        pthread_t t1,t2;
        void*ptr;
        pthread_create(&t1,NULL,thread_fun1,NULL);
        pthread_create(&t2,NULL,thread_fun2,NULL);
        pthread_join(t1,&ptr);
        pthread_join(t2,&ptr);
}
void*thread_fun1(void*ptr)
{
	int i;
	for(i=0;i<10;i++)
	{	
		if(i%2==0)
        		printf("even thread %d\n",i);
	}
}
void*thread_fun2(void*ptr)
{
	int i;
	for(i=0;i<10;i++)
	{
		if(i%2!=0)
        		printf("odd thread %d\n",i);
	}
}
