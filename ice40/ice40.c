#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>


int main(int argc, char** argv) {

	int fd[2];
	char out[256];

	int result = pipe(fd);

	int pid = fork();

	if (pid > 0) {
		for (int i = 0; i < 10; i++) {
			write(fd[1], "Hello\n", 6);
		}
		int exitStatus;
		wait(&exitStatus);
		return exitStatus;
	}

	if (pid == 0) {
		for (int i = 0; i < 10; i++) {
			read(fd[0], out, 6);
			printf("%s", out);
		}

		return 0;
	}


	return result;
}
