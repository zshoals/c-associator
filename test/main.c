#include <stdio.h>
#include <stdlib.h>
#include "../src/avolitty-associator.h"

int main (void) {
	unsigned long int a;
	unsigned long int b;
	unsigned long int c;
	unsigned long int * d;
	unsigned char * e;
	unsigned char * f;
	unsigned char g;
	c = ((unsigned long int) 0UL);
	d = &c;
	g = ((unsigned char) 1U);

	/*
		["key"] - key string
		["value"] - value string
		[d] -  array length (keys and values)
		[3] - key length
		[5] - value length
		[e] - array of keys
		[f] - array of values
		[g] - key object type identifier
			0 - integral
			1 - string
		[g] - value object type identifier
			0 - integral (signed or unsigned can be determined with -, floats determined with .)
			1 - string
			2 - pointer index to array (multidimensional arrays can be accessed using get method with raw a[0][0][0] etc without undefined index errors)
	*/

	a = AvolittyAssociatorA("key", "value", d, ((unsigned long int) 3UL), ((unsigned long int) 5UL), e, f, g, g);

/*
	key (unsigned char)
		"34", [3, 4], ((unsigned short int) 34), ((unsigned char) 34) and ((float) 34.1234) all update the same key
		indexes
			0 length (either raw value < 32 or hash)
			1 memory alloc length (to calculate percentage of unused memory)
			2-33 (hash digits | key string)
	value (unsigned char)
		all data types converted to char array
			0 length
			1-n value
	value data
		0 [
			value length,
			memory alloc length
		]
*/

	return 0;
}
