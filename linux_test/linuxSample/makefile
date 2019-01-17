SRC=linux_test.cpp
OBJS=linux_test.o
CC=gcc
CFLAGS=-o

# gcc -c <file.cpp> -o <target.o>  // compile a C++ file
# gcc -o test <target.o> -lstdc++ -ldl -lpthread // -o Executable file, -l<library>

test : linux_test.o
	$(CC) $(CFLAGS) test linux_test.o -ldl -lpthread -lstdc++

linux_test.o : linux_test.cpp
	$(CC) -c linux_test.cpp -o linux_test.o

clean:
	-rm -f *.o test