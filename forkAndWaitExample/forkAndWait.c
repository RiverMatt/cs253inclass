#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
	
	printf("Parent: The parent's PID is: %4d\n", getpid());

	fflush(stdout);
	int pid = fork();

	/* from here, the process doesn't know if it is the parent or 
	 * child, so we use an if statement to determine behavior
	 */

	if (pid == 0) {
		for (int i = 0; i < 500; ++i) {
			printf("Child message %4d\n", i);
		}
		printf("Exiting...\n");
		fclose(stdout);
		return 0;
	} else if (pid > 0) {
		printf("The child's PID is: %4d\n", pid);
		for (int i = 0; i < 500; ++i) {
			printf("Parent message %4d\n", i);
		}
		fflush(stdout);
		int exitStatus;
		wait(&exitStatus);
		printf("Parent: The child's exit status was %2d\n", exitStatus);
		return 0;
	} else {
		perror("Fork failed!");
	}

	return -1;
}
