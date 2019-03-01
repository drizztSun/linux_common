/*
 * This head file isn's needed in a lot of computers, but the
 * X/OPEN standar that defines this semaphore library says that the
 * union need not be provided in standard library headers,
 * so you should include a file like this when you need them.
 * */

#if defined(__GNU_LIBRARY__) && !defined(_SEM_SEMUN_UNDEFINED)
	/* union semun is defined by #include<sys/sem.h>*/

#else
	/*according to x/OPEN, you have to define it by yourself*/
	union semun{
		int val;
		struct semid_ds *buf;
		unsigned short int *array;
		struct seminfo *__buf;
	};

#endif
