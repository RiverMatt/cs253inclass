#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>
#include <stdlib.h>

void *theThread(void *);

static long counter = 0;
static int nRepetitions;
pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;

int main(int argc, char** argv) {

	/* Convert argument string to int */
	nRepetitions = atoi(argv[1]);
	
	/* Setting up the thread */
	pthread_t threadID;
	int result;
	int threadES;
	void *pThreadExitStatus = &threadES;
	
	/* Creating the thread */
	result = pthread_create(&threadID, NULL, theThread, NULL);	// NULL is passed in for the void* arg
	if (result != 0) {
		printf("thread creation failed, error %d\n", result);
	}

	/* Critical Section incrementing counter */
	pthread_mutex_lock(&mut);
	for (int i = 0; i < nRepetitions; i++) {
		counter++;
	}
	pthread_mutex_unlock(&mut);

	/* Waiting for the thread to exit */
	result = pthread_join(threadID, pThreadExitStatus);
	if (result != 0) {
		printf("Thread join failed! error %d\n", result);
	}
	printf("Thread exit status: %d\n", threadES);

	/* Print the counter */
	printf("counter = %ld\n", counter);

	return result;
}

void* theThread(void* arg) {
	
	/* Critical Section decrementing counter */
	pthread_mutex_lock(&mut);
	for (int i = 0; i < nRepetitions; i++) {
		counter--;
	}
	pthread_mutex_unlock(&mut);

	pthread_exit((void*)0);
}
