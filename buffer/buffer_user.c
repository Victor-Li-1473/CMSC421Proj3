#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>

//#include <linux/syscalls.h>
#include "buffer.h"

struct ring_buffer_421* new_ring;

long init_buffer_421(void){
	new_ring = malloc(sizeof(struct ring_buffer_421));
	new_ring->length = 0;
	new_ring->read = malloc(sizeof(struct node_421));
	new_ring->read->data = 0;
	new_ring->read->next = NULL;
	new_ring->write = NULL;
	
	struct node_421 *temp = new_ring->read;
	for (int i = 0; i < 20; i++){
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
		return -1;
	}
	
	if (new_ring->length >= 20){
		printf("failed to insert");
		return -1;
	}
	new_ring->write->data = i;
	new_ring->length += 1;
	new_ring->write = new_ring->write->next;
	return 0;
}

long print_buffer_421(void){
	if (new_ring == NULL){
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
		return -1;
	}
	
	new_ring->write = new_ring->read;
	for (int i = 0; i < 20; i++){
		new_ring->write = new_ring->write->next;
		free(new_ring->read);
		new_ring->read = new_ring->write;
		printf("Node %d deleted\n", i);
	}	
	//free(new_ring->write);
	free(new_ring->read);
	new_ring->read = NULL;
	new_ring->write = NULL;

	new_ring->length = 0;
	free(new_ring);

	return 0;
}


