README for buffer folder

The files in this folder are meant for the user space. The buffer_mon.h file is used as the header for the structs circular buffer ring_buffer_421 and the node node_421. The four functions for the circular buffer are defined here: init_buffer_421, enqueue_buffer_421, dequeue_buffer_421, and delete_buffer_421. 

The user space functions are defined in buffer_mon.c. init_buffer_421 initializes the buffer and creates 20 nodes with a default string of 1023 0s and a null terminator. enqueue_buffer_421 which adds the data parameter into the data attribute of node_421 and increases the length of buffer_421. dequeue_buffer_421 finds the data parameter and removes it and puts the default string back into the data attribute. delete_buffer_421 frees all allocated memory and sets dynamic memory to Null.

The user space functions are implemented in buffer_mon.c with the test file being test_mon.c. To compile and run it, the commands "make BF" and "./BF" need to be used and the compiler command is made in the Makefile. 
 
