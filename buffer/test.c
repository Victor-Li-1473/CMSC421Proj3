#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <linux/kernel.h>
#include <sys/syscall.h>

#include "buffer.h"
#define __NR_init_buffer_421 442
#define __NR_insert_buffer_421 443
#define __NR_print_buffer_421 444
#define __NR_delete_buffer_421 445


struct ring_buffer_421* new_ring;

long init_buffer_421(void){
	return syscall(__NR_init_buffer_421);
}

long insert_buffer_421(int i){
	return syscall(__NR_insert_buffer_421);
}

long print_buffer_421(void){
	return syscall(__NR_print_buffer_421);
}

long delete_buffer_421(void){
	return syscall(__NR_delete_buffer_421);
}


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
	delete_buffer_421();
	print_buffer_421();
	return 0;
}
