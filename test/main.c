#include <stdio.h>
#include <stdlib.h>
#include "../src/avolitty-associator.h"

int main (void) {
	unsigned long * * * a = malloc(sizeof(unsigned char * *));
	unsigned long b[1];
	unsigned char * * * * c = malloc(sizeof(unsigned char * * *));
	unsigned char * * * * d = malloc(sizeof(unsigned char * * *));
	char * e[3] = {"key1", "key2", "key3"};
	unsigned long f[3] = {4, 4, 4};
	unsigned char g;
	void * * h = malloc(sizeof(unsigned char *));
	unsigned long i[2] = {0, 0};
	unsigned long j[1] = {0};
	unsigned long k = 0;
	unsigned char l[1];
	unsigned char * m;

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
	printf("%u %c%c%c%c\n", c[0][1][0][0], c[0][1][0][1], c[0][1][0][2], c[0][1][0][3], c[0][1][0][4]);
	printf("%u %u %u\n", d[0][1][0][0], d[0][1][0][1], d[0][1][0][2]);
	printf("%u %c%c%c%c\n", c[0][2][0][0], c[0][2][0][1], c[0][2][0][2], c[0][2][0][3], c[0][2][0][4]);
	printf("%u %u %c%c%c%c%c%c\n", d[0][2][0][0], d[0][2][0][1], d[0][2][0][2], d[0][2][0][3], d[0][2][0][4], d[0][2][0][5], d[0][2][0][6], d[0][2][0][7]);
	e[1] = "key5";
	e[2] = "key4";
	g = AvolittyAssociatorB((void * *) e, "value", a, b, f, 3, 5, c, d, 1, 1);
	printf("\n");
	printf("%u %c%c%c%c\n", c[0][0][0][0], c[0][0][0][1], c[0][0][0][2], c[0][0][0][3], c[0][0][0][4]);
	printf("%u %u %u\n", d[0][0][0][0], d[0][0][0][1], d[0][0][0][2]);
	printf("%u %c%c%c%c\n", c[0][1][0][0], c[0][1][0][1], c[0][1][0][2], c[0][1][0][3], c[0][1][0][4]);
	printf("%u %u %u\n", d[0][1][0][0], d[0][1][0][1], d[0][1][0][2]);
	printf("%u %c%c%c%c\n", c[0][1][1][0], c[0][1][1][1], c[0][1][1][2], c[0][1][1][3], c[0][1][1][4]);
	printf("%u %u %u\n", d[0][1][0][0], d[0][1][0][1], d[0][1][0][2]);
	printf("%u %c%c%c%c\n", c[0][3][0][0], c[0][3][0][1], c[0][3][0][2], c[0][3][0][3], c[0][3][0][4]);
	printf("%u %u %c%c%c%c%c%c\n", d[0][2][0][0], d[0][2][0][1], d[0][2][0][2], d[0][2][0][3], d[0][2][0][4], d[0][2][0][5], d[0][2][0][6], d[0][2][0][7]);
	printf("%u %u %c%c%c%c%c%c\n", d[0][3][0][0], d[0][3][0][1], d[0][3][0][2], d[0][3][0][3], d[0][3][0][4], d[0][3][0][5], d[0][3][0][6], d[0][2][0][7]);
	printf("\n");

/*
	[e] - key
	[h] - value result
	[a] - global data
	[b] - global data length
	[f] - key lengths
	[i] - value result length
	[3] - key depth
	[c] - array of keys
	[d] - array of values
	[k] - value result data type
	[1] - key object type identifier
		0 - integral object
		1 - string object
*/
	g = AvolittyAssociatorC((void * *) e, h, a, b, f, j, 3, c, d, l, 1);
	printf("%lu\n", l[0]);
	m = (unsigned char *) h[0];

	while (k != j[0]) {
		printf("%c", m[k]);
		k++;
	}

	printf("\n");

/*
	[e] - key
	[a] - global data
	[b] - global data length
	[f] - key lengths
	[i] - memory allocation error indexes
	[3] - key depth
	[c] - array of keys
	[d] - array of values
	[1] - key object type identifier
		0 - integral object
		1 - string object
	[g] - memory allocation error status
*/
	g = AvolittyAssociatorD((void * *) e, a, b, f, i, 3, c, d, 1, g);

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
				3 int
				4 unsigned int
				5 long
				6 unsigned long
				7 double
				8 float
				etc
			1-n length
			2-n value
	global data (unsigned long)
		0 [
			0 value array length [value of 0 means unallocated],
			1 key multidimensional recursion level
			2 allocated byte count
			3 assigned byte count
		]
	global data length (unsigned long)
*/

	return 0;
}
