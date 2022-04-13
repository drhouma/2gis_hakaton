CC=g++
CFLAGS=#-Wall -Wextra -Werror
FILES_CPP=main.cpp
EXEC_NAME=finder.out


build:
	$(CC) $(CFLAGS) $(FILES_CPP) -o $(EXEC_NAME)

clean:
	-rm -rf *.out

run: build
	./$(EXEC_NAME)