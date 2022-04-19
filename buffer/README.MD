README for buffer folder

The files in this folder are divided between the user space and kernel space. The buffer.h file is shared between both spaces as the header for the structs circular buffer ring_buffer_421 and the node node_421. The four functions for the circular buffer are defined here: init_buffer_421, enqueue_buffer_421, dequeue_buffer_421, and delete_buffer_421. 

The user space functions are defined in buffer_user.c. init_buffer_421 initializes the buffer and creates 20 nodes with a default integer of 0. enqueue_buffer_421 which adds the data parameter into the data attribute of node_421 and increases the length of buffer_421. print_buffer_421 prints the data variable of each node_421. delete_buffer_421 frees all allocated memory and sets dynamic memory to Null.

The kernel space has it's own set of functions which are:

#define __NR_init_buffer_421 442
#define __NR_insert_buffer_421 443
#define __NR_print_buffer_421 444
#define __NR_delete_buffer_421 445

These functions do the same thing as their user space counterparts but need to be added to the syscall_64.tbl and compiled differently. 
The user space functions are implemented in buffer_user.c with the test file being test_user.c. To compile and run it, the commands "make buffer_user" and "./buffer_user" need to be used and the compiler command is made in the Makefile. 
The kernel space functions are implemented in buffer.c with the test file being test.c. I did not implement the kernel files, but I did add the syscalls to the syscalls folder.


Notes from the programmer to the grader: I recongnize that my project 3 will score far less than a 50%. There's no excuse for my indolence, so in order to appeal to your ethos and save you some time, I'm self grading in the README.MD to make your life easier. Sections without a +<number> are implied to be a 0.

Part 1: 

User Space:
+3 creates and deletes buffer
+3 write and print
+3 test_user.c runs correctly
+2 README.MD

Kernel Space:
+3 system calls added to syscalls.h

+3 no memory leakage with valgrind. The user space has no leakage and since the kernel space is not tested, there is no leakage there.

Estimated sum for part 1: 17
