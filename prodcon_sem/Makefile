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
	$(CC) $(CFLAGS) -pthread -o BFU test_user_sem.o buffer_user_sem.o
	
buffer_user_sem.o: buffer_user_sem.c buffer_sem.h
	$(CC) $(CFLAGS) -pthread -c buffer_user_sem.c

test_user_sem.o: test_user_sem.c
	$(CC) $(CFLAGS) -pthread -c test_user_sem.c
	
	
BFK: test_sem.o buffer_sem.o
	$(CC) $(CFLAGS) -pthread -o BFU test_sem.o buffer_sem.o
	
buffer_sem.o: buffer_sem.c buffer_sem.h
	$(CC) $(CFLAGS) -pthread -c buffer_sem.c

test_sem.o: test_sem.c
	$(CC) $(CFLAGS) -pthread -c test_sem.c
	
