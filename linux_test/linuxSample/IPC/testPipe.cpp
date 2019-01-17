#include <stdlib.h>
#include <stdio.h>

#include <pthread.h>

#include <unistd.h>
#include <sys/wait.h>


#include <string.h>

int pipe_default[2];

void testPipe() {

	if (pipe(pipe_default) < 0) {
		printf("failed to create pip \n");
		return;
	}

	pid_t pid;
	char buffer[32];
	memset(buffer, 0, 32);

	if (0 == (pid = fork()))
	{
		printf("child process %d \n", getpid());

		close(pipe_default[1]);
		sleep(10);

		if (read(pipe_default[0], buffer, 32) > 0) {
			printf("Receive data from server %s \n", buffer);
		}
		close(pipe_default[0]);
	}
	else {

		printf("parent process %d \n", getpid());

		close(pipe_default[0]);

		if (-1 != write(pipe_default[1], "hello", strlen("hello"))) {
			printf("send data to client hello\n");
		}

		close(pipe_default[1]);

		// wait the child process ends, which is equal to call 'wait()'
		waitpid(pid, NULL, 0);


	}

}
