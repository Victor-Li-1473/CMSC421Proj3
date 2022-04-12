CC=gcc
CFLAGS=-Wall

clean:
	rm -rf *.o
	rm -rf fcfs
	rm -rf sjf
	rm -rf rr
	rm -rf priority
	rm -rf priority_rr
	
	
BFU: test_user_sem.o buffer_user_sem.o
	$(CC) $(CFLAGS) -o BFU test_user_sem.o buffer_user_sem.o
	
buffer_user_sem.o: buffer_user_sem.c buffer_sem.h
	$(CC) $(CFLAGS) -c buffer_user_sem.c

test_user_sem.o: test_user_sem.c
	$(CC) $(CFLAGS) -c test_user_sem.c
	
