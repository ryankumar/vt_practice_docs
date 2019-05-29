#all: test_1017_05.09 test_1017_06.09 test_1017_07.09
SHELL =/bin/sh
OBJS =test_1017_05.09.o test_1017_06.09.o test_1017_07.09.o
CC: gcc
CFLAGS: -g -Wall
INCLUDE =
LIBS = -lm


#test_1017_05.09.o: 
#	$(CC) $(CFLAGS) -c test_1017_05.09.c

#test_1017_06.09.o: 
#	$(CC) $(CFLAGS) -c  test_1017_06.09.c 

#test_1017_07.09.o: 
#	$(CC) $(CFLAGS) -c test_1017_07.09.c 

common: $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $(OBJS) $(LIBS)

#test_1017_05.09: test_1017_05.09.o
#	$(CC) -o test_1017_05.09 test_1017_05.09.o

#test_1017_06.09: test_1017_06.09.o
#	$(CC) -o test_1017_06.09 test_1017_06.09.o

#test_1017_07.09: test_1017_07.09.o
#	$(CC) -o test_1017_07.09 test_1017_07.09.o

clean:
	rm *.o common

.cpp.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $<
