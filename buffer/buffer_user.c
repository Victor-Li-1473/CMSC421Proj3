#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//#include <linux/syscalls.h>
#include "buffer.h"

struct ring_buffer_421* new_ring;

long init_buffer_421(void){
	
	new_ring = malloc(sizeof(struct ring_buffer_421));
	new_ring->length = 20;
	new_ring->read = NULL;
	new_ring->write = NULL;
	
	
	/*
	struct node_421 *head = malloc(sizeof(struct node_421));
	new_ring->read = head;
	head->data = 0;
	//head->next = NULL;
	head->next = new_ring->write;
	*/
	
	int i = 1;
	struct node_421 *prev;	
	while (i <= 20){
		new_ring->write = malloc(sizeof(struct node_421));

		if (i == 1){
			new_ring->read = new_ring->write;
			new_ring->write = malloc(sizeof(struct node_421));
			new_ring->write->data = 1;
			new_ring->write->next = NULL;
			printf("Node %d: %d\n", i, new_ring->write->data);
			new_ring->write = new_ring->write->next;
			new_ring->read->next = new_ring->write;
		}
		else if (i == 20){
			prev->next = new_ring->read;
			new_ring->write = new_ring->read;	
		}
		else {
			new_ring->write->data = i;
			new_ring->write->next = NULL;
			prev = new_ring->write;
			printf("Node %d: %d\n", i, new_ring->write->data);
			new_ring->write = new_ring->write->next;
			prev->next = new_ring->write;
			if (i == 2){
				printf("Node %d: %d\n", i, new_ring->read->data);	
				printf("Node %d: %d\n", i, new_ring->read->next->data);	
			}
		}
		i++;
	}
	printf("Node next head: %d\n", new_ring->read->next->data);
	
	//printf("Node %d: %d\n", i, ->data);

	/*
	new_ring = malloc(sizeof(struct ring_buffer_421));
	new_ring->length = 20;
	new_ring->write = NULL;
	int len = 0;
	new_ring->read = malloc(sizeof(struct node_421));
	new_ring->read->data = 0;
	new_ring->read->next = new_ring->write;
	len += 1;
	
	struct node_421 *prev;
	
	for (len; len++; len <= 20){
		new_ring->write = malloc(sizeof(struct node_421));
		
		if (new_ring->write->data != NULL){
			return 1;
		}
		else if (len == 20){
			prev->next = new_ring->read;
			new_ring->write = new_ring->read;	
		}
		else {
			new_ring->write->data = 0;
			prev = new_ring->write;
			new_ring->write = new_ring->write->next;
		}
	}
	printf("Node 1: %d\n",new_ring->read->data);
	return 0;
	*/
}

long insert_buffer_421(int i){
	if (new_ring == NULL){
		return -1;
	}
	return 0;
}

long print_buffer_421(void){
	if (new_ring == NULL){
		return -1;
	}
	printf("print");
	int i = 1;
	struct node_421 *temp = new_ring->read;
		
	while (i <= 20){
		printf("Node %d: %d\n", i, temp->data);
		temp = temp->next;
		i++;
	}
	
	/*
	struct node_421 *temp;
	temp = new_ring->read;
	int i = 1;
	while (temp != new_ring->write) {
		printf("Node %d: %d\n", i, temp->data);
		temp = temp->next;
	}*/
	return 0;
}
long delete_buffer_421(void){
	if (new_ring == NULL){
		return -1;
	}
	return 0;
}


