#include <stdio.h>
#include <stdlib.h>
#include "../src/avolitty-associator.h"

int main (void) {
	unsigned long * * * a = malloc(sizeof(unsigned char * * *));
	unsigned long b[1];
	unsigned char * * * * c = malloc(sizeof(unsigned char * * * *));
	unsigned char * * * * d = malloc(sizeof(unsigned char * * * *));
	char * e[2] = {"key1", "key2"};
	unsigned long f[2] = {4, 4};
	unsigned char g;

	/*
		["key"] - key string
		["value"] - value string
		[a] - global data
		[b] - global data length
		[3] - key length
		[1] - key dimension level
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

	g = AvolittyAssociatorA(a, b, c, d);
	g = AvolittyAssociatorB((void * *) e, "value", a, b, f, 2, 5, c, d, 1, 1);
/*	printf("%c%c%c\n", c[0][0][0][2], c[0][0][0][3], c[0][0][0][4]); */

/*
	key (unsigned char)
		"34", [3, 4], (unsigned short int) 34, (unsigned char) 34 and (float) 34.1234 all update different keys
		indexes
			0 length (either raw value < 32 or hash)
			1-32 (hash numbers | key string)
	value (unsigned char)
		all data types converted to char array
			0 value type
				0 multidimensional array index in global data array
				1 char
				2 unsigned char
				etc
			1-n value
	global data (unsigned long)
		0 [
			0 value array length [value of 0 means unallocated],
			1 key multidimensional recursion level
		]
	global data length (unsigned long)
*/

	return 0;
}
