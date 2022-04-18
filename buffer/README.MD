README for buffer folder

The files in this folder are divided between the user space and kernel space. The buffer.h file is shared between both spaces as the header for the structs circular buffer ring_buffer_421 and the node node_421. The four functions for the circular buffer are defined here: init_buffer_421, enqueue_buffer_421, dequeue_buffer_421, and delete_buffer_421. 

The user space functions are defined in buffer_user.c. init_buffer_421 initializes the buffer and creates 20 nodes with a default integer of 0. enqueue_buffer_421 which adds the data parameter into the data attribute of node_421 and increases the length of buffer_421. dequeue_buffer_421 finds the data parameter and removes it and puts the default integer back into the data attribute. delete_buffer_421 frees all allocated memory and sets dynamic memory to Null.

The kernel space has it's own set of functions which are:

#define __NR_init_buffer_421 442
#define __NR_insert_buffer_421 443
#define __NR_print_buffer_421 444
#define __NR_delete_buffer_421 445

These functions do the same thing as their user space counterparts but need to be added to the syscall_64.tbl and compiled differently. 
The user space functions are implemented in buffer_user.c with the test file being test_user.c. To compile and run it, the commands "make buffer_user" and "./buffer_user" need to be used and the compiler command is made in the Makefile. 
The kernel space functions are implemented in buffer.c with the test file being test.c. To compile and run it, the commands "make buffer" and "./buffer" need to be used and the compiler command is made in the Makefile. 
