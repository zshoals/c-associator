#include <stdio.h>
#include <stdlib.h>
#include "../src/avolitty-associator.h"

int main (void) {
	unsigned long * * * a = malloc(sizeof(unsigned char * * *));
	unsigned long b[3];
	unsigned char * * * * c = malloc(sizeof(unsigned char * * * *));
	unsigned char * * * * d = malloc(sizeof(unsigned char * * * *));
	unsigned char e;

	/*
		["key"] - key string
		["value"] - value string
		[a] - global data
		[b] - global data data [array length][malloc] (keys and values)
		[3] - key length
		[5] - value length
		[c] - array of keys
		[d] - array of values
		[1] - key object type identifier
			0 - integral
			1 - string
		[1] - value object type identifier
			0 - integral (signed or unsigned can be determined with -, floats determined with .)
			1 - string
			2 - pointer index to array (multidimensional arrays can be accessed using get method with raw a[0][0][0] etc without undefined index errors)
	*/

	e = AvolittyAssociatorA(a, b, c, d);
	e = AvolittyAssociatorB("key", "value", a, b, 3, 5, c, d, 1, 1);

/*
	key (unsigned char)
		"34", [3, 4], ((unsigned short int) 34), ((unsigned char) 34) and ((float) 34.1234) all update different keys
		indexes
			0 length (either raw value < 32 or hash)
			1 memory alloc length (to calculate percentage of unused memory)
			2-33 (hash digits | key string)
	value (unsigned char)
		all data types converted to char array
			0 memory alloc length
			1-n value
	global data (unsigned long)
		0 [
			0 value length [value of 0 means unallocated],
			1 multidimensional recursion level,
			2 key memory alloc length,
			3 value memory alloc length
		]
	global data data (unsigned long)
		0 global data length,
		1 key memory alloc length,
		2 value memory alloc length
*/

	return 0;
}
