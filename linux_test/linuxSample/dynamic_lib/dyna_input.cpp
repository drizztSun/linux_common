#include <stdlib.h>
#include <stdio.h>

#include "dyna_input.h"


/*
class testclass {
public:

	testclass();
	virtual ~testclass();

	int g();
	int p();

private:

	int s;
};


testclass::testclass() {

	s = 100;
}

testclass::~testclass() {


}


int testclass::g() {

	printf("out_put_class::g function \n");
	return 1;
}

int testclass::p() {

	printf("out_put_class::p function \n");
	return 1;
}
*/


extern "C" {


	int d_add(int a, int b) {
		return a + b;
	}

	int d_minus(int a, int b) {
		return a - b;
	}

	int d_multiply(int a, int b) {
		return a * b;
	}

	int d_divide(int a, int b) {
		return a / b;
	}
}



