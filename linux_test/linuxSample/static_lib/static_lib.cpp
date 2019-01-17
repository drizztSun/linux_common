#include <stdlib.h>
#include <stdio.h>


extern "C" {

	int add(int a, int b){
		return a + b;
	}

	int minus(int a, int b){
		return a - b;
	}

	int multiply(int a, int b) {
		return a * b;
	}

	int divided(int a, int b){
		if (b == 0)
			return 0;

		return a / b;
	}
}


