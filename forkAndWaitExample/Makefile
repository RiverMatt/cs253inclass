CFLAGS = -Wall --std=c99

all: forkAndWait zombie

forkAndWait:  forkAndWait.o
	gcc $(CFLAGS) $^ -o $@

zombie:  zombie.o
	gcc $(CFLAGS) $^ -o $@

clean:
	rm -f *.o *~ forkAndWait zombie
