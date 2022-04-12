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
	sem_init(&fill_count, 0, SIZE_OF_BUFFER);
	sem_init(&empty_count, 0, 0);
	sem_init(&mutex, 0, 0);
	
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
	buffer->write->data = i;
	buffer->length += 1;
	buffer->write = buffer->write->next;
	return 0;
}

long dequeue_buffer_421(char * data) {

	// Write your code to dequeue data from the buffer
	

	return 0;
}


long delete_buffer_421(void) {
	// Tip: Don't call this while any process is waiting to enqueue or dequeue.
	// write your code to delete buffer and other unwanted components
	if (buffer == NULL){
		return -1;
	}
	
	buffer->write = buffer->read;
	for (int i = 0; i < 20; i++){
		buffer->write = buffer->write->next;
		free(buffer->read);
		buffer->read = buffer->write;
		printf("Node %d deleted\n", i);
	}	
	free(buffer->read);
	buffer->read = NULL;
	buffer->write = NULL;

	buffer->length = 0;
	free(buffer);

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
	if (buffer == NULL){
		return -1;
	}
	
	int i = 1;
	struct bb_node_421 *temp = buffer->read;
		
	while (i <= 20){
		printf("Node %d: %s\n", i, temp->data);
		temp = temp->next;
		i++;
	}
	
	printf("\n");
	
	return 0;
}

