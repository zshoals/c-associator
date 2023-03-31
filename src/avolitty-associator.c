#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

void AvolittyAssociatorF(unsigned long a, unsigned char * b, unsigned char * c) {
	unsigned short d[32] = {254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254};
	unsigned short e = 32;
	unsigned short f;
	unsigned char g;

	while (a != 0) {
		a--;
		f = (((c[a] + f + ((f + 2) >> 1))) & 16383) + 2;
		g = a & 31;
		d[g] = (d[g] + f) & 1023;
	}

	g = 0;

	while (e != 0) {
		e--;
		d[e] = f;
		f = ((d[e] + d[g] + e + ((e + f) >> 1)) & 16383) + 2;
		d[g] = f;
		b[e] = f & 255;
		g++;
	}

	return;
}

unsigned char AvolittyAssociatorA(unsigned long * * * a, unsigned long * b, unsigned char * * * * c, unsigned char * * * * d) {
	a[0] = malloc(sizeof(unsigned long * *));
	a[0][0] = malloc(sizeof(unsigned long *) * 2);
	a[0][0][0] = 0;
	a[0][0][1] = 0;
	b[0] = 0;
	c[0] = malloc(sizeof(unsigned char * * *));
	d[0] = malloc(sizeof(unsigned char * * *));
	return 0;
}

/*
	[a] - key
	[b] - value
	[c] - global data
	[d] - global data length
	[e] - key lengths
	[f] - key depth
	[g] - value length
	[h] - array of keys
	[i] - array of values
	[j] - key object type identifier
		0 - integral object
		1 - string object
	[k] - value object type identifier (not data type)
		0 - integral object
		1 - string object
		2 - pointer index to array (multidimensional associative arrays)

	adding error handling with each malloc() + realloc()
*/

unsigned char AvolittyAssociatorB(void * * a, void * b, unsigned long * * * c, unsigned long * d, unsigned long * e, unsigned long f, unsigned long g, unsigned char * * * * h, unsigned char * * * * i, unsigned char j, unsigned char k) {
	unsigned long l = 0;
	unsigned long m = 0;
	unsigned long n = 0;
	unsigned long o;
	unsigned long p = 0;
	unsigned char * q;
	unsigned char * r;
	unsigned char s;
	unsigned char t = 0;
	unsigned long * u;
	unsigned char v = 0;
	unsigned long w = 0;
	unsigned char * x;
	q = malloc(sizeof(unsigned char *) * 32);

	while (l != f) {
		m = d[0];

		if (e[l] < 32) {
			q = (unsigned char *) a[l];
		} else {
			AvolittyAssociatorF(e[l], q, (unsigned char *) a[l]);
		}

		o = 0;

		while (m != 0) {
			m--;

			if (c[0][m][0] != 0) {
				if (c[0][m][1] == l) {
					n = c[0][m][0];

					while (n != 0) {
						n--;
						r = h[0][m][n];
						p = r[0];
						w = p;

						while (p != 0) {
							p--;

							if (q[p] != r[w]) {
								p = 0;
								t = 1;
							}

							w--;
						}

						if (t == 0) {
							if (f == l) {
								o = e[l];
								free(i[0][m][n]);
								i[0][m][n] = malloc(o + 1);
								r = i[0][m][n];
								r[0] = 0;
								c[0][m][0] = o;
								n = o;
								x = (unsigned char *) b;

								while (o != 0) {
									o--;
									r[n] = x[o];
									n--;
								}
							} else {
								/* r[0] = 1, converting int to char array */
							}

							m = 0;
							n = 0;
							o = 0;
						}
					}
				}
			} else {
				if (t == 0) {
					o = m;
					t = 1;
				}
			}
		}

		if (o != 0) {
			n = e[l];
			h[0][o] = malloc(sizeof(unsigned char * *));
			h[0][o][0] = malloc(n + 1);
			r = h[0][o][0];
			r[0] = n;
			o = n;

			while (n != 0) {
				n--;
				r[o] = q[n];
				o--;
			}
		}

		l++;
	}

	/* .. */
	return 0;
}

unsigned char AvolittyAssociatorC(void * a, void * b, unsigned long c, unsigned char * d) {
	/* get */
	return 0;
}

unsigned char AvolittyAssociatorD(void * a, void * b, unsigned long c, unsigned char * d) {
	/* delete */
	return 0;
}

unsigned char AvolittyAssociatorE(void * a, void * b, unsigned long c, unsigned char * d) {
	/* string|float|int to char converter for B C D key strings */
	return 0;
}
