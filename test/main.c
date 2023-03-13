#include <stdio.h>
#include <stdlib.h>
#include "../src/avolitty-associator.h"

int main (void) {
	unsigned long int a;
	unsigned long int b;
	unsigned char c[1];
	unsigned char d;
	unsigned char * e;
	a = AvolittyAssociatorA(e, "key", "value", 3, 5, c);
	b = AvolittyAssociatorB(e, "key", 3, c);
	d = AvolittyAssociatorC(e, "key", 3, c);

/*
	unsigned char a[33];
	unsigned char b[33];
	b[0] = 's';
	b[1] = 't';
	b[2] = 'r';
	b[3] = 0;
	AvolittyAssociatorD(b, 3, a);
*/

	return 0;
}
