//============================================================================
// Name        : linux_test.cpp
// Author      : ysun
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include <unistd.h>
#include <pthread.h>

/*
void testLibfunc();

void calldllfunc();

void testSignal();

void testPipe();

void testDllLoadDynamic();

void testSignal2();
*/

int main() {


	cout << "!!!Hello World!!!" << endl;

	cout << "Current Process ID" << getpid() << endl;

	// calldllfunc();

	// testLibfunc();

	// testSignal();

	// testPipe();

	// testDllLoadDynamic();

	// testSignal2();

	return 0;
}
