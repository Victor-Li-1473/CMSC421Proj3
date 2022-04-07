#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//#include <linux/syscalls.h>
#include "buffer.h"

struct ring_buffer_421* new_ring;

long init_buffer_421(void){
	
	new_ring = malloc(sizeof(struct ring_buffer_421));
	new_ring->length = 0;
	new_ring->read = NULL;
	new_ring->write = NULL;
	
	int i = 1;
	struct node_421 *prev;
	struct node_421 *temp;	
	while (i <= 20){
		if (i == 1){
			
			temp = malloc(sizeof(struct node_421));
			temp->data = 0;
			temp->next = NULL;
			new_ring->read = temp;
			new_ring->write = new_ring->read;
		}
		else if (i == 20){
			new_ring->write = new_ring->read;
			new_ring->write = new_ring->read;
		}	
		else {
			new_ring->write = malloc(sizeof(struct node_421));
			new_ring->write->data = 0;
			new_ring->write->next = NULL;
			new_ring->write = new_ring->write->next;
			if (i == 2){
				new_ring->read->next = temp;
			}
		}
		i++;
	}
}

long insert_buffer_421(int i){
	if (new_ring == NULL){
		return -1;
	}
	
	if (new_ring->length >= 20){
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
		printf("%p", temp);
		printf("Node %d: %d\n", i, temp->data);
		temp = temp->next;
		i++;
	}
	
	return 0;
}
long delete_buffer_421(void){
	if (new_ring == NULL){
		return -1;
	}
	
	int i = 1;
	new_ring->write = new_ring->read;
	while (i <= 20){
		if (i == 20){
			free(new_ring->write);
			new_ring->write = NULL;
			new_ring->read = NULL;
			new_ring->length = 0;
			
		}
		else{
			new_ring->write = new_ring->write->next;
			free(new_ring->read);
			new_ring->read = new_ring->write;
			printf("Node %d deleted\n", i);
			new_ring->write = new_ring->write->next;
			i++;
		}
	}
	
	return 0;
}


