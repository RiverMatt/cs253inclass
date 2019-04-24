EXE = threads
CFLAGS = -Wall -std=c99 -pthread
OBJS = $(EXE).o

#------Build everything
all: $(EXE)

#------Build a DEBUG version
debug: CFLAGS += -DDEBUG -g -O0
debug: $(EXE)


#------Build the program
$(EXE): $(OBJS)
	gcc $(CFLAGS) $^ -o $@


#------This target builds a debug version and executes the program under valgrind
valgrind: debug
	valgrind --leak-check=yes --leak-check=full --show-leak-kinds=all  --track-origins=yes bugfest


#------Clean up the build artifacts
clean:
	rm -f *.o *~ $(EXE)

