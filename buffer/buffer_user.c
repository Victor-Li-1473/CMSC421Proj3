#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>

//#include <linux/syscalls.h>
#include "buffer.h"

struct ring_buffer_421* new_ring = NULL;

long init_buffer_421(void){
	if (new_ring != NULL){
		printf("Failed to initialize. Buffer already exisits.\n");
		return -1;
	}
	new_ring = malloc(sizeof(struct ring_buffer_421));
	new_ring->length = 0;
	
	// Initializes read, the first nide
	new_ring->read = malloc(sizeof(struct node_421));
	new_ring->read->data = 0;
	new_ring->read->next = NULL;
	new_ring->write = NULL;
	
	// Initializes the 19 remainig
	struct node_421 *temp = new_ring->read;
	for (int i = 0; i < 19; i++){
		struct node_421 *newNode_421 = malloc(sizeof(struct node_421));
		newNode_421->data = 0;
		newNode_421->next = NULL;
		
		temp->next = newNode_421;
		temp = temp->next;
	}	
	temp->next = new_ring->read;
	new_ring->write = new_ring->read;
	return 0;
}

long insert_buffer_421(int i){
	if (new_ring == NULL){
		printf("Failed to insert. No buffer exists.\n");
		return -1;
	}
	
	if (new_ring->length >= 20){
		printf("Failed to insert. Full.\n");
		return -1;
	}
	new_ring->write->data = i;
	new_ring->length += 1;
	new_ring->write = new_ring->write->next;
	return 0;
}

long print_buffer_421(void){
	if (new_ring == NULL){
		printf("Failed to print. No buffer exists.\n");
		return -1;
	}
	
	int i = 1;
	struct node_421 *temp = new_ring->read;
		
	while (i <= 20){
		printf("Node %d: %d\n", i, temp->data);
		temp = temp->next;
		i++;
	}
	
	printf("\n");
	
	return 0;
}

long delete_buffer_421(void){
	if (new_ring == NULL){
		printf("Failed to delete. No buffer exists.\n");
		return -1;
	}
	
	struct node_421 * temp;
	new_ring->write = new_ring->read->next;
	while (new_ring->write != new_ring->read){
		temp = new_ring->write->next;
		free(new_ring->write);
		new_ring->write = NULL;
		new_ring->write = temp;
	}
	free(new_ring->read);
	new_ring->write = NULL;
	new_ring->read = NULL;
	new_ring->length = 0;
	free(new_ring);
	new_ring = NULL;

	return 0;
}

