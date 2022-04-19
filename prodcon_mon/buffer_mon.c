#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <string.h>
#include "buffer_mon.h"


static ring_buffer_421_t *buffer = NULL;
static sem_t mutex;
static sem_t fill_count;
static sem_t empty_count;

#define SIZE_OF_BUFFER 20
#define DATA_LENGTH 1024


char* dataArr[] = {'0','1','2','3','4','5','6','7','8','9'};
int num = 0;
int enqueue = 0;
int dequeue = 0;
pthread_mutex_t mutex_var;

/*
void *producer(void *param){
	char item[1024];
	int i = 0;
	
	while(1) {
		sleep(10);
		sem_wait(&fill_count);
		//pthread_mutex_lock(&mutex);
		sem_wait(&mutex);
		char item[1024];
		memset(item, dataArr[num], 1023);
		item[1023] = '\n';
		puts(item);
		
		//item = dataArr[i]; //memset
		// set null terminator
		item[1023] = '\n';
		enqueue_buffer_421(item);
		num += 1;
		if (num > 9){
			num = 0;
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
*/

long init_buffer_421(void) {
	// Write your code to initialize buffer
	if (buffer != NULL){
		printf("Failed to initialize. Buffer already exisits.\n");
		return -1;
	}
	
	buffer = malloc(sizeof(struct ring_buffer_421));
	buffer->length = 0;
	buffer->read = malloc(sizeof(struct node_421));
	buffer->read->next = NULL;
	buffer->write = NULL;
	
	struct node_421 *temp = buffer->read;
	for (int i = 0; i < 19; i++){
		struct node_421 *newNode_421 = malloc(sizeof(struct node_421));
		newNode_421->next = NULL;
		
		temp->next = newNode_421;
		temp = temp->next;
	}	
	temp->next = buffer->read;
	buffer->write = buffer->read;
	return 0;

	// Initialize mutex
	pthread_mutex_init(&mutex_var, NULL);
	
	return 0;
}


long enqueue_buffer_421(char * data) {
	// Write your code to enqueue data into the buffer
	if (buffer == NULL){
		return -1;
	}
	
	if (buffer->length >= 20){
		printf("failed to insert");
		return -1;
	}
	memcpy(buffer->write->data, data, 1024);
	printf("Enqueued data: %s\n", buffer->write->data);
	enqueue += 1;
	printf("%d \n", enqueue);
	buffer->length += 1;
	buffer->write = buffer->write->next;
	
	enqueue += 1;
	printf("Enqueued: %d\n", enqueue);

	return 0;
}

long dequeue_buffer_421(char * data) {

	// Write your code to dequeue data from the buffer
	
	if (buffer == NULL){
		return -1;
	}
	
	if (buffer->length >= 20){
		printf("failed to insert");
		return -1;
	}

	memcpy(data, buffer->write->data, 1024);
	dequeue += 1;
	printf("%d \n", dequeue);
	buffer->length -= 1;
	buffer->write = buffer->write->next;
	
	dequeue += 1;
	printf("Dequeued: %d\n", dequeue);

	return 0;
}




long delete_buffer_421(void) {
	// Tip: Don't call this while any process is waiting to enqueue or dequeue.
	// write your code to delete buffer and other unwanted components
	
	if (buffer == NULL){
		printf("Failed to delete. No buffer exists.\n");
		return -1;
	}
	
	struct node_421 * temp;
	buffer->write = buffer->read->next;
	while (buffer->write != buffer->read){
		temp = buffer->write->next;
		free(buffer->write);
		buffer->write = NULL;
		buffer->write = temp;
	}
	free(buffer->read);
	buffer->write = NULL;
	buffer->read = NULL;
	buffer->length = 0;
	free(buffer);
	buffer = NULL;
	
	pthread_mutex_destroy(&mutex_var);
	return 0;
}



