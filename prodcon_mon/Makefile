CC=gcc
CFLAGS=-Wall

clean:
	rm -rf *.o
	rm -rf fcfs
	rm -rf sjf
	rm -rf rr
	rm -rf priority
	rm -rf priority_rr
	
	
BF: test_mon.o buffer_mon.o
	$(CC) $(CFLAGS) -o buffer_mon test_mon.o buffer_mon.o
	
BF.o: buffer_mon.c buffer_mon.h
	$(CC) $(CFLAGS) -c buffer_mon.c

BF.o: test_mon.c
	$(CC) $(CFLAGS) -c test_mon.c
