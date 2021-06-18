#include <stdio.h>
#include <unistd.h> 
#include <pthread.h>
#include <time.h>
#include <stdlib.h>

#include "queue.h"

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

struct Queue *queue;

void *enqueueing()
{
    while(1)
	{
		printf("Enqueueing...\n");
		
		pthread_mutex_lock(&lock);
		int result = enqueue(queue, rand() % 20);
		pthread_mutex_unlock(&lock);
		
		if(result == 0)
		{
			printf("Queue is full\n");
		}
		else
		{
			printf("Size of my queue: %d\n", result);
		}

		sleep(1);
	}
}

void *dequeueing()
{
	sleep(2);
    while(1)
	{
		printf("Dequeueing...\n");

		pthread_mutex_lock(&lock);
		double *result = dequeue(queue);
		pthread_mutex_unlock(&lock);
	
		if(result == 0)
		{
			printf("Queue is empty\n");	
		}
		else
		{
			printf("That's your value: %f\n", *result);
		}

		sleep(1);
	}
}

int main()
{
	srand(time(NULL));

	queue = createQueue(5);

	pthread_t enqueueingThreadId;
    pthread_create(&enqueueingThreadId, NULL, enqueueing, NULL);

	pthread_t dequeueingThreadId;
    pthread_create(&dequeueingThreadId, NULL, dequeueing, NULL);

    pthread_join(enqueueingThreadId, NULL);
	pthread_join(dequeueingThreadId, NULL);

	return 0;
}
