#include <stdlib.h>
#include <stdio.h>

#include <unistd.h>


#define MEGABYTE (1024 * 1024)


void memoryAllocation() {

	char* memory = (char*) malloc(MEGABYTE);
	int exit_code = EXIT_FAILURE;

	if (memory != NULL) {
		sprintf(memory, "Hello world\n");
		printf("%s", memory);
		exit_code = EXIT_SUCCESS;
	}


	free(memory);
	exit(exit_code);
}






void testMemory() {

}
