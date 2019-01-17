#include <stdlib.h>
#include <stdio.h>

#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/wait.h>


void testProcess() {


	pid_t pid;

	if (0 == (pid = fork())) {
		// child process

		printf("This is child process: %d \n", getpid());
	}
	else {
		// parent process

		printf("This is father process: %d \n", getpid());

	}


	return;
}
