//============================================================================
// Name        : Linux_test.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


void test_semphone();

extern "C" {
	void test_epoll();
}



int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	// test_semphone();

	test_epoll();

	return 0;
}
