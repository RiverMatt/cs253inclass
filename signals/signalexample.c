#include <stdio.h>
#include <unistd.h>
#include <signal.h>

#define _POSIX_SOURCE
extern char run = 1;

void myHandler(int sigNumber) {
	if (sigNumber == SIGUSR1) {
		printf("Event SIGUSR1 received.\n");
		run = 0;
	}
}

int main(int argc, char** argv) {
	
	signal(SIGUSR1, myHandler);
	while (run > 0) {
		sleep(1);
	}


	return 0;
}
