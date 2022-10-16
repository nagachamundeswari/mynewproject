#include<stdio.h>
#include<pthread.h>
pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond=PTHREAD_COND_INITIALIZER;
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
		if(i%2==0)
	        printf("even thread %d\n",i);
		pthread_cond_wait(&cond,&mutex);
	        pthread_mutex_unlock(&mutex);
	        sleep(1);
	}
}
void*thread_fun2(void*ptr)
{
	int i;
	for(i=0;i<10;i++)
	{
		pthread_cond_signal(&cond);
	        pthread_mutex_lock(&mutex);
		//pthread_cond_wait(&cond,&mutex);
		if(i%2!=0)
        		printf("odd thread %d\n",i);
		//pthread_cond_wait(&cond,&mutex);
        	pthread_mutex_unlock(&mutex);
        	sleep(1);
	}		
}

