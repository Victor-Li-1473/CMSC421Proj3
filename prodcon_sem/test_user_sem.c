#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "buffer_sem.h"

void *producer(void *param){
	char* item;
	int i = 0;

	while(1) {
		sleep(10);
		sem_wait(&fill_count);
		//pthread_mutex_lock(&mutex);
		sem_wait(&mutex);
		
		item = dataArr[i];
		enqueue_buffer_421(item);
		i += 1;
		if (i > 9){
			i = 0;
		}

		printf("Producer %u produced %s \n", (unsigned int)pthread_self(), item);

		//pthread_mutex_unlock(&mutex);
		sem_post(&mutex);
		sem_post(&empty_count);
	}
}

void *consumer(void *param){
	char* item;

	while(1){
		sleep(10);
		sem_wait(&empty_count);
		//pthread_mutex_lock(&mutex);
		sem_wait(&mutex);
		

		dequeue_buffer_421(&item);
		printf("Consumer %u consumed %s \n", (unsigned int)pthread_self(), item);

		//pthread_mutex_unlock(&mutex);
		sem_post(&mutex);
		sem_post(&fill_count);
	}
}

int main(int argc, char *argv[])
{	
	// Test the buffer is initalized properly
	init_buffer_421();
	print_semaphores();
	
	/*
	int sleepTime, producerThreads, consumerThreads;
	int i, j;

	if(argc != 5)
	{
		fprintf(stderr, "Useage: <sleep time> <producer threads> <consumer threads> <start number>\n");
		return -1;
	}

	sleepTime = atoi(argv[1]);
	producerThreads = atoi(argv[2]);
	consumerThreads = atoi(argv[3]);
	START_NUMBER = atoi(argv[4]);

	//pthread_mutex_init(&mutex, NULL);
	sem_init(&full, 0, BUFFER_SIZE);
	sem_init(&empty, 0, 0);

	pthread_t pid, cid;

	for(i = 0; i < producerThreads; i++){
		pthread_create(&pid,NULL,&producer,NULL);
	}

	for(j = 0; j < consumerThreads; j++){
		pthread_create(&cid,NULL,&consumer,NULL);
	}

	sleep(sleepTime);
	*/
	return 0;
}
