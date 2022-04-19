#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "buffer_mon.h"

char* Arr[] = {'0','1','2','3','4','5','6','7','8','9'};

int main(int argc, char *argv[])
{	
	// Test the buffer is initalized properly
	init_buffer_421();
	
	// Edge case 1
	// Tests edge case when buffer is full and user tries to insert
	if (init_buffer_421() == -1){
		printf("Edge case 1 passed\n\n");
	}
	
	delete_buffer_421();
	
	// Edge case 2
	// Tests edge case when no buffer exists and user tries to delete
	if (delete_buffer_421() == -1){
		printf("Edge case 2 passed\n\n");
	}
	return 0;
}
