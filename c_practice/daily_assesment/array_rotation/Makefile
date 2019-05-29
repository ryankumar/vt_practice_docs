
all: array_rotation
CC: gcc
CFLAGS: -g -Wall
INCLUDE:= -I../


array_rotation: array_rotation.o left_rotation.o print_array.o
	$(CC) $(CFLAGS) -o $@ array_rotation.o print_array.o left_rotation.o

array_rotation.o:array_rotation.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $?
left_rotation.o:left_rotation.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $?

print_array.o:print_array.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $?

clean:
	rm -f *.o array_rotation
