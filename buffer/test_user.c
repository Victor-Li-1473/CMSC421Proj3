#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "buffer.h"


int main(int argc, char *argv[])
{	
	// Test the buffer is initalized properly
	init_buffer_421();
	print_buffer_421();
	
	// Test whether the buffer inserts 20 values properly
	// The printes result should be: Node 1: 1	Node 2: 2 ... Node 20:20
	for (int i = 1; i <= 20; i++){
		insert_buffer_421(i);
	}
	print_buffer_421();
	return 0;
}
