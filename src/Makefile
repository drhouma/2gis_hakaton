CC=g++
CFLAGS=#-Wall -Wextra -Werror
FILES_CPP=main.cpp interface.cpp string_find.cpp Knuth_Morris_Pratt.cpp model.cpp
# EXEC_NAME=finder.out

run: buildProject
	./program.out

buildProject:
	$(CC) $(CFLAGS) $(FILES_CPP) -o program.out


build_brutforce:
	$(CC) $(CFLAGS) $(FILES_CPP) -o $(EXEC_NAME)

clean:
	-rm -rf *.out

run_brutforce: build_brutforce
	./$(EXEC_NAME)