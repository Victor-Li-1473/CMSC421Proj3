#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <string.h>
#include "buffer_sem.h"


static bb_buffer_421_t *buffer = NULL;
static sem_t mutex;
static sem_t fill_count;
static sem_t empty_count;

#define SIZE_OF_BUFFER 20
#define DATA_LENGTH 1024


char* dataArr[] = {'0','1','2','3','4','5','6','7','8','9'};
int num = 0;
int enqueue = 0;
int dequeue = 0;


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


long init_buffer_421(void) {
	// Write your code to initialize buffer
	if (buffer != NULL){
		printf("Failed to initialize. Buffer already exisits.\n");
		return -1;
	}
	
	buffer = malloc(sizeof(struct bb_buffer_421));
	buffer->length = 0;
	buffer->read = malloc(sizeof(struct bb_node_421));
	buffer->read->next = NULL;
	buffer->write = NULL;
	
	struct bb_node_421 *temp = buffer->read;
	for (int i = 0; i < 19; i++){
		struct bb_node_421 *newNode_421 = malloc(sizeof(struct bb_node_421));
		newNode_421->next = NULL;
		
		temp->next = newNode_421;
		temp = temp->next;
	}	
	temp->next = buffer->read;
	buffer->write = buffer->read;
	return 0;

	// Initialize your semaphores here.
	sem_init(&mutex, 0, 1);
	sem_init(&fill_count, 0, 0);
	sem_init(&empty_count, 0, SIZE_OF_BUFFER);
	
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
	print_semaphores();
	
	
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
	print_semaphores();
	
	return 0;
}




long delete_buffer_421(void) {
	// Tip: Don't call this while any process is waiting to enqueue or dequeue.
	// write your code to delete buffer and other unwanted components
	
	if (buffer == NULL){
		printf("Failed to delete. No buffer exists.\n");
		return -1;
	}
	
	struct bb_node_421 * temp;
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
	
	sem_destroy(&mutex);
	sem_destroy(&fill_count);
	sem_destroy(&empty_count);
	return 0;
}

void print_semaphores(void) {
	// You can call this method to check the status of the semaphores.
	// Don't forget to initialize them first!
	// YOU DO NOT NEED TO IMPLEMENT THIS FOR KERNEL SPACE.
	
	int value;
	sem_getvalue(&mutex, &value);
	printf("sem_t mutex = %d\n", value);
	sem_getvalue(&fill_count, &value);
	printf("sem_t fill_count = %d\n", value);
	sem_getvalue(&empty_count, &value);
	printf("sem_t empty_count = %d\n", value);
	return;
	
}

long print_buffer_421(void){
	
	/*
	if (buffer == NULL){
		return -1;
	}
	
	int i = 1;
	struct bb_node_421 *temp = buffer->read;
		
	while (i <= 20){
		printf("Node %i: %s\n", i, temp->data[0]);
		temp = temp->next;
		i++;
	}
	
	printf("\n");
	*/
	return 0;
}

