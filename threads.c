#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int a[1000];
int in = 0;
int sum = 0;


void * tfunction(void* w)
{
	for(int i = 0;i<100;i++)
	{
		sum += a[in];
		in++;
	}
}



int main()
{
	for(int i = 0;i<1000;i++)
	{
		a[i] = i;
	}

	pthread_t threads[10];

	for(int i = 0;i<10;i++)
	{
		pthread_create(&threads[i], NULL, tfunction, NULL);
	}
	
	sleep(1);

	//pthread_join(t1, NULL);

	printf("%d",sum);

	return 0;
}