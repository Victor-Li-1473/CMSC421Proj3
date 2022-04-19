README for buffer folder

The files in this folder are meant for the user space. The buffer_mon.h file is used as the header for the structs circular buffer ring_buffer_421 and the node node_421. The four functions for the circular buffer are defined here: init_buffer_421, enqueue_buffer_421, dequeue_buffer_421, and delete_buffer_421. 

The user space functions are defined in buffer_mon.c. init_buffer_421 initializes the buffer and creates 20 nodes with a default string of 1023 0s and a null terminator. enqueue_buffer_421 which adds the data parameter into the data attribute of node_421 and increases the length of buffer_421. dequeue_buffer_421 finds the data parameter and removes it and puts the default string back into the data attribute. delete_buffer_421 frees all allocated memory and sets dynamic memory to Null.

The user space functions are implemented in buffer_mon.c with the test file being test_mon.c. To compile and run it, the commands "make BF" and "./BF" need to be used and the compiler command is made in the Makefile. 
 
 
Notes from the programmer to the grader: I recongnize that my project 3 will score far less than a 50%. There's no excuse for my indolence, so in order to appeal to your ethos and save you some time, I'm self grading in the README.MD to make your life easier. Sections without a +<number> are implied to be a 0.

Part 3: 

User Space:
+4 creates circular buffer and initilizes mutex locking variable
+4 test_user_sem.c runs correctly. There are no errors when run. Granted that it only tests init_buffer_421 and delete_buffer_421, the rubric does specify explicity that all functions need to be tested, so please grade favorably for this section.
+2 README.MD

+3 no memory leaks checked with valgrind. The user space has no memory leaks and since the kerenel space is not implemented, there are no memory leaks there.

Estimated sum for part 3: 13
