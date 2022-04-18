obj-y := init.o
obj-y := insert.o
obj-y := print.o
obj-y := delete.o



CC=gcc
CFLAGS=-Wall

clean:
	rm -rf *.o
	rm -rf fcfs
	rm -rf sjf
	rm -rf rr
	rm -rf priority
	rm -rf priority_rr
	
	
buffer_user: test_user.o buffer_user.o
	$(CC) $(CFLAGS) -o buffer_user test_user.o buffer_user.o
	
buffer_user.o: buffer_user.c buffer.h
	$(CC) $(CFLAGS) -c buffer_user.c

test_user.o: test_user.c
	$(CC) $(CFLAGS) -c test_user.c

	
buffer: test.o buffer.o
	$(CC) $(CFLAGS) -o buffer test.o buffer.o
	
buffer_user.o: buffer.c buffer.h
	$(CC) $(CFLAGS) -c buffer.c

test_user.o: test.c
	$(CC) $(CFLAGS) -c test.c


