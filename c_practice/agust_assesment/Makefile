all: matrix process thread
      
#matrix.o: matrix.c
#	gcc -g -Wall -c matrix.c
#process.o: process.c 
#	gcc -g -Wall -c process.c
#thread.o: thread.c
#	gcc -g -Wall -c thread.c -lpthread

matrix: matrix.c
	gcc -g -Wall  matrix.c -o matrix 
process: process.c
	gcc -g -Wall  process.c -o process
thread: thread.c
	gcc -g -Wall  thread.c -o thread -lpthread

clean:
	rm *.o matrix process thread

