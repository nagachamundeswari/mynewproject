#include<stdio.h>
#include<pthread.h>
pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex1=PTHREAD_MUTEX_INITIALIZER;
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
	pthread_mutex_lock(&mutex);
	printf("thread function 1\n");
	pthread_mutex_unlock(&mutex1);
	sleep(1);
}
}
void*thread_fun2(void*ptr)
{
int i;
for(i=0;i<10;i++)
{
	pthread_mutex_lock(&mutex1);
	printf("thread function 2\n");
	pthread_mutex_unlock(&mutex);
	sleep(1);
}
}
