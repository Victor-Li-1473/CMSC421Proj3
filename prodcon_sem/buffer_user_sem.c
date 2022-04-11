#include <stdlib.h>
#include <stdio.h>
#include "buffer_sem.h"

static bb_buffer_421_t buffer;
static sem_t mutex;
static sem_t fill_count;
static sem_t empty_count;

long init_buffer_421(void) {
	// Write your code to initialize buffer
	buffer = malloc(sizeof(struct ring_buffer_421));
	buffer->length = 0;
	buffer->read = malloc(sizeof(struct node_421));
	buffer->read->data = 0;
	buffer->read->next = NULL;
	buffer->write = NULL;
	
	struct node_421 *temp = buffer->read;
	for (int i = 0; i < 20; i++){
		struct node_421 *newNode_421 = malloc(sizeof(struct node_421));
		newNode_421->data = 0;
		newNode_421->next = NULL;
		
		temp->next = newNode_421;
		temp = temp->next;
	}	
	temp->next = buffer->read;
	buffer->write = buffer->read;
	return 0;

	// Initialize your semaphores here.
	
	return 0;
}


long enqueue_buffer_421(char * data) {
	// Write your code to enqueue data into the buffer
}

long dequeue_buffer_421(char * data) {

	// Write your code to dequeue data from the buffer

	return 0;
}


long delete_buffer_421(void) {
	// Tip: Don't call this while any process is waiting to enqueue or dequeue.
	// write your code to delete buffer and other unwanted components
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

