#include <stdlib.h>
#include <stdio.h>
#include <iostream>


#include <unistd.h>
#include <pthread.h>

#include <boost/array.hpp>

int AMOUNT = 5;


struct threadContext {
	int threadLogicId;

	pthread_mutex_t * pMutex;
};

void* threadProcess(void* arg) {

	sleep(20);

	threadContext * pContext = reinterpret_cast<threadContext*> (arg);

	pthread_t id = pthread_self();

	pthread_mutex_lock(pContext->pMutex);

	std::cout << "Current Thread info : " << pContext->threadLogicId << " tid : " << id << std::endl;

	pthread_mutex_unlock(pContext->pMutex);

	for (int i = 0; i < 10; i++) {

		pthread_mutex_lock(pContext->pMutex);

		std::cout << "Coming text output from id: " << id << " logId : " << pContext->threadLogicId << std::endl;

		pthread_mutex_lock(pContext->pMutex);
	}

	return (void*)nullptr;
}

void sharedDocumentOutput() {

	boost::array<pthread_t, 5> threadId_array;
	boost::array<threadContext, 5> thread_context;
	pthread_mutex_t mutex; //  = PTHREAD_MUTEX_INITIALIZER;
	pthread_mutex_init(&mutex, NULL);


	pthread_mutexattr_t mutexAttr;
	int type = 0;
	if (pthread_mutexattr_gettype(&mutexAttr, &type) == 0) {
		// mutexAttr = PTHREAD_MUTEX_RECURSIVE;
		pthread_mutexattr_settype(&mutexAttr, PTHREAD_MUTEX_RECURSIVE);
	}


	for (unsigned int i = 0; i < thread_context.size(); i++) {
		thread_context[i].threadLogicId = i;
		thread_context[i].pMutex = &mutex;
	}

	for (int i = 0; i < AMOUNT; i++) {
		auto res = pthread_create(&threadId_array[i], NULL, threadProcess, (void*) &thread_context[i]);
	}


	// wait thread ends
	for (auto i = 0; i < AMOUNT; i++) {
		pthread_join(threadId_array[i], NULL);
	}

	pthread_mutex_destroy(&mutex);
}

void testMultiThread() {


	sharedDocumentOutput();

}



