# Configure gcc for a production build
CFLAGS = -Wall -std=c99
EXE = lsc
OBJS = $(EXE).o

#------Build everything
all: $(EXE)

#------Build a DEBUG version
debug: CFLAGS += -DDEBUG -g -O0
debug: $(EXE)


#------Build the product
$(EXE): $(OBJS)
	gcc $(CFLAGS) $^ -o $@


#------This target builds a debug version and executes the product under valgrind
valgrind: debug
	valgrind --leak-check=yes --leak-check=full --show-leak-kinds=all  --track-origins=yes bugfest


#------Clean up the build artifacts
clean:
	rm -f *.o *~ $(EXE)

