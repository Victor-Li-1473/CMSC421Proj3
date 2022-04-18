README for prodcon_sem folder

The files in this folder are divided between the user space and kernel space. The buffer_sem.h file is shared between both spaces as the header for the structs circular buffer bb_buffer_421 and the node bb_node_421. There in if statement to determine which semaphore library to include whether its user or kernel space. The four functions for the circular buffer are defined here: init_buffer, enqueue_buffer_421, dequeue_buffer_421, deleete_buffer_421, and print_semaphore. 

The user space functions are defined in buffer_user.c. init_buffer initializes the buffer and creates 20 nodes with a default string of 1023 0s and a null character. enqueue_buffer_421 which adds the data parameter into the data attribute of bb_node_421 and increases the length of bb_buffer_421. dequeue_buffer_421 finds the data parameter and removes it and puts the default string back into the data attribute. delete_buffer_421 frees all allocated memory and sets dynamic memory to Null. print_semaphores prints the values of the semaphores mutex, fill_count, and empty_count;

The kernel space has it's own set of functions, excluding print_semaphores which are:

#define NR_init_buffer_sem_421 446 
#define NR_enqueue_buffer_sem_421 447 
#define NR_dequeue_buffer_sem_421 448 
#define NR_delete_buffer_sem_421 449

These functions do the same thing as their user space counterparts but need to be added to the syscall_64.tbl and compiled differently. 
The user space functions are implemented in buffer_user_sem.c with the test file being test_user_sem.c. To compile and run it, the commands "make BFU" and "./BFU" need to be used and the compiler command is made in the Makefile. 
The kernel space functions are implemented in buffer_sem.c with the test file being test_sem.c. To compile and run it, the commands "make BFK" and "./BFK" need to be used and the compiler command is made in the Makefile. 
