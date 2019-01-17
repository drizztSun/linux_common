/**
 *
 * It is going to call function in static_lib
 *
 * */

#include <stdlib.h>
#include <stdio.h>

#include "../static_lib/static_lib.h"


void testLibfunc() {

	printf("Add(1, 2) == %d\n", add(1, 2));

	printf("Minus(3, 2) == %d\n", minus(3, 2));

	printf("Multiply(2, 3) == %d\n", multiply(2, 3));

}


