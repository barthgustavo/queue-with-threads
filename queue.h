#ifndef _QUEUE_
#define _QUEUE_
	struct Queue;
	
	extern struct Queue *createQueue(int capacity);

	int enqueue(struct Queue *queue, double value);

	double* dequeue(struct Queue *queue);
#endif
