#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "buffer.h"


int main(int argc, char *argv[])
{	
	// Test the buffer is initalized properly
	init_buffer_421();
	
	// Tests that print_buffer runs properly and the buffer is initialized properly with all node data set to 0
	print_buffer_421();
	
	// Test whether the buffer inserts 20 values properly
	// The print result should be: Node 1: 1	Node 2: 2 ... Node 20:20
	for (int i = 1; i <= 20; i++){
		insert_buffer_421(i);
	}
	print_buffer_421();
	
	// Edge case 1
	// Tests edge case when buffer is full and user tries to insert
	if (init_buffer_421() == -1){
		printf("Edge case 1 passed\n\n");
	}
	
	// Edge case 2
	// Tests edge case when buffer is full and user tries to insert
	if (insert_buffer_421(100) == -1){
		printf("Edge case 2 passed\n\n");
	}
	
	// Deletes and frees all allocated memory
	delete_buffer_421();
	
	// Edge case 3
	// Tests edge case when no buffer exists and user tries to delete
	if (delete_buffer_421() == -1){
		printf("Edge case 3 passed\n\n");
	}
	
	// Edge case 4
	// Tests edge case when no buffer exists and user tries to print
	if (print_buffer_421() == -1){
		printf("Edge case 4 passed\n\n");
	}
	
	// Edge case 5
	// Tests edge case when no buffer exists and user tries to insert
	if (insert_buffer_421(5) == -1){
		printf("Edge case 5 passed\n\n");
	}
	
	// Edge case 2
	// Tests edge case when no buffer exists and user tries to delete
	
	//print_buffer_421();
	return 0;
}
