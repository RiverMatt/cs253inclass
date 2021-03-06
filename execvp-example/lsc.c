#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char** argv) {
	
	/*
	char* args[argc];
	for (int i = 0; i < argc - 1; i++) {
		args[i] = argv[i + 1]; 
	}
	
	args[argc - 1] = NULL;
	*/

	char* args[] = {"ls", "-lF", NULL, NULL};
	args[2] = argv[1];

	int pid = fork();
	
	if (pid == 0) {
		int result = execvp(args[0], args);
		if (result == -1) {
			return -1;
		}
	}

	if (pid > 0) {
		int exitStatus;
		wait(&exitStatus);
		return exitStatus;
	}

	return 0;

}
