#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#include "semun.h"

static int sem_id;

int semphore_p() {

	struct sembuf sem_b;
	sem_b.sem_num = 0;
	sem_b.sem_op = -1;
	sem_b.sem_flg = SEM_UNDO;

	if (semop(sem_id, &sem_b, 1) == -1) {
		fprintf(stderr, "semphore_p failed \n");
		return 0;
	}

	return 1;
}

int semphore_v() {

	struct sembuf sem_b;
	sem_b.sem_num = 0;
	sem_b.sem_op = 1;
	sem_b.sem_flg = SEM_UNDO;

	if (semop(sem_id, &sem_b, 1) == -1) {
		fprintf(stderr, "semphore_v failed \n");
		return 0;
	}

	return 1;
}

int set_semvalue() {
	union semun sem_union;
	sem_union.val = 1;

	if (semctl(sem_id, 0, SETVAL, sem_union) == -1)
		return 0;

	return 1;
}



void test_semphone() {

	int pause_time;
	char op_char = 'O';

	srand((unsigned int)getpid());

	sem_id = semget((key_t)1234, 1, 0666 | IPC_CREAT);


	for (int i = 0; i < 10; i++) {

		if (!semphore_p())
			exit(EXIT_FAILURE);

		printf("%c", op_char);
		fflush(stdout);

		pause_time = rand() % 3;
		sleep(pause_time);

		printf("%c", op_char);
		fflush(stdout);

		if (!semphore_v())
			exit(EXIT_FAILURE);

		pause_time = rand() % 2;
		sleep(pause_time);

	}




}


