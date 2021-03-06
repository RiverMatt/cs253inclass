#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>


int main(int argc, char** argv) {

	int fd[2];
	char bfr[256];

	int result = pipe(fd);

	int pid = fork();

	if (pid > 0) {
		for (int i = 0; i < 10; i++) {		// Parent process
			write(fd[1], "Hello\n", 6);	// write to fd[1] (the inlet of the fd) from "Hello\n"
		}
		int exitStatus;
		wait(&exitStatus);
		return exitStatus;
	}

	if (pid == 0) {					// Child process
		for (int i = 0; i < 10; i++) {
			read(fd[0], bfr, 6);		// read from fd[0] (the outlet) into bfr
			printf("%s", bfr);
		}

		exit(0);
	}


	return result;
}
