#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "buffer_sem.h"

char* Arr[] = {'0','1','2','3','4','5','6','7','8','9'};

int main(int argc, char *argv[])
{	
	// Test the buffer is initalized properly
	init_buffer_421();
	print_semaphores();
	
	// Edge case 1
	// Tests edge case when buffer is full and user tries to insert
	if (init_buffer_421() == -1){
		printf("Edge case 1 passed\n\n");
	}
	
	/*
	char item[1024];
	memset(item, Arr[4], 1023);
	item[1023] = '\n';
	
	enqueue_buffer_421(item);
	*/
	/*
	// Test code 
	char item[1024];
	memset(item, Arr[4], 1023);
	item[1023] = '\n';
	puts(item);
	
	
	int producerThreads = 1000;
	int consumerThreads = 1000;
	pthread_t producer_id[producerThreads];
	pthread_t consumer_id[consumerThreads];
	
	for(int i = 0; i < producerThreads; i++){
		pthread_create(&producer_id[i],NULL,&producer,NULL);
	}

	for(int j = 0; j < consumerThreads; j++){
		pthread_create(&consumer_id[j],NULL,&consumer,NULL);
	}
	for(int k = 0; k < producerThreads; k++){
		pthread_join(&producer_id[k],NULL);
	}
	for(int l = 0; l < consumerThreads; l++){
		pthread_join(&consumer_id[l],NULL);
	}
	*/
	
	delete_buffer_421();
	
	// Edge case 2
	// Tests edge case when no buffer exists and user tries to delete
	if (delete_buffer_421() == -1){
		printf("Edge case 2 passed\n\n");
	}
	return 0;
}
