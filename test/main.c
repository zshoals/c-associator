#include <stdio.h>
#include <stdlib.h>
#include "../src/avolitty-associator.h"

int main (void) {
	unsigned long * * * a = malloc(sizeof(unsigned char * * *));
	unsigned long b[1];
	unsigned char * * * * c = malloc(sizeof(unsigned char * * * *));
	unsigned char * * * * d = malloc(sizeof(unsigned char * * * *));
	char * e[3] = {"key1", "key2", "key3"};
	unsigned long f[3] = {4, 4, 4};
	unsigned char g;

	/*
		[e] - keys
		["value"] - value
		[a] - global data
		[b] - global data length
		[f] - key lengths
		[3] - key dimension level
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
	g = AvolittyAssociatorB((void * *) e, "value", a, b, f, 3, 5, c, d, 1, 1);
	printf("%u %c%c%c%c\n", c[0][0][0][0], c[0][0][0][1], c[0][0][0][2], c[0][0][0][3], c[0][0][0][4]);
	printf("%u %u %u\n", d[0][0][0][0], d[0][0][0][1], d[0][0][0][2]);
	printf("\n");
	printf("%u %c%c%c%c\n", c[0][1][0][0], c[0][1][0][1], c[0][1][0][2], c[0][1][0][3], c[0][1][0][4]);
	printf("%u %u %u\n", d[0][1][0][0], d[0][1][0][1], d[0][1][0][2]);
	printf("\n");
	printf("%u %c%c%c%c\n", c[0][2][0][0], c[0][2][0][1], c[0][2][0][2], c[0][2][0][3], c[0][2][0][4]);
	printf("%u %c%c%c%c%c%c\n", d[0][2][0][0], d[0][2][0][1], d[0][2][0][2], d[0][2][0][3], d[0][2][0][4], d[0][2][0][5], d[0][2][0][6]);

	/* e[1] = "key5"; */
	e[2] = "key4";
	g = AvolittyAssociatorB((void * *) e, "value", a, b, f, 3, 5, c, d, 1, 1);
	printf("%u %c%c%c%c\n", c[0][0][0][0], c[0][0][0][1], c[0][0][0][2], c[0][0][0][3], c[0][0][0][4]);
	printf("%u %u %u\n", d[0][0][0][0], d[0][0][0][1], d[0][0][0][2]);
	printf("\n");
	printf("%u %c%c%c%c\n", c[0][1][0][0], c[0][1][0][1], c[0][1][0][2], c[0][1][0][3], c[0][1][0][4]);
	printf("%u %u %u\n", d[0][1][0][0], d[0][1][0][1], d[0][1][0][2]);
	printf("\n");
	printf("%u %c%c%c%c\n", c[0][2][0][0], c[0][2][0][1], c[0][2][0][2], c[0][2][0][3], c[0][2][0][4]);

	printf("%u %c%c%c%c\n", c[0][2][1][0], c[0][2][1][1], c[0][2][1][2], c[0][2][1][3], c[0][2][1][4]);
	printf("%u %c%c%c%c%c%c\n", d[0][2][0][0], d[0][2][0][1], d[0][2][0][2], d[0][2][0][3], d[0][2][0][4], d[0][2][0][5], d[0][2][0][6]);

/*
	key (unsigned char)
		"34", [3, 4], (unsigned short int) 34, (unsigned char) 34 and (float) 34.1234 all update different keys
		indexes
			0 length (either raw value < 32 or hash)
			1-32 (hash numbers | key string)
	value (unsigned char)
		all data types converted to char array
			0 value type
				0 multidimensional array index in global data array, 1-n is index converted from unsigned long
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
