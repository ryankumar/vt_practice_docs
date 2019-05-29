# problems are in ../daily_assignament 
# executing multiple .c file in single makefile 

all: test_1017_05.09 test_1017_06.09 test_1017_07.09


test_1017_05.09.o: test_1017_05.09.c
	gcc -g -Wall -c test_1017_05.09.c

test_1017_06.09.o: test_1017_06.09.c
	gcc -g -Wall -c  test_1017_06.09.c 

test_1017_07.09.o: test_1017_07.09.c
	gcc -g -Wall -c test_1017_07.09.c 

test_1017_05.09: test_1017_05.09.o
	gcc -o test_1017_05.09 test_1017_05.09.o

test_1017_06.09: test_1017_06.09.o
	gcc -g -Wall -o test_1017_06.09 test_1017_06.09.o

test_1017_07.09: test_1017_07.09.o
	gcc -g -Wall -o test_1017_07.09 test_1017_07.09.o

clean:
	rm *.o test_1017_05.09 test_1017_06.09 test_1017_07.09
