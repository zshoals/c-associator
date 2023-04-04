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
	a[0] = malloc(sizeof(unsigned long *));
	a[0][0] = malloc(sizeof(unsigned long) * 2);
	a[0][0][0] = 0;
	a[0][0][1] = 0;
	b[0] = 1;
	c[0] = malloc(sizeof(unsigned char * *));
	d[0] = malloc(sizeof(unsigned char * *));
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
	unsigned char t = 1;
	unsigned long * u;
	unsigned char v = 0;
	unsigned long w = 0;
	unsigned char * x;
	unsigned char y;
	unsigned long z = 0;
	q = malloc(32);

	if (e[l] < 32) {
		q = (unsigned char *) a[l];
		y = e[l];
	} else {
		AvolittyAssociatorF(e[l], q, (unsigned char *) a[l]);
		y = 32;
	}

	l++;
	m = c[0][0][0];
	n = m;

	while (m != 0) {
		m--;
		r = h[0][0][m];
		o = r[0];
		t = 0;
		w = o;

		while (o != 0) {
			o--;

			if (q[o] != r[w]) {
				o = 0;
				t = 1;
			}

			w--;
		}

		if (t == 0) {
			if (f == l) {
				if (f > 1) {
					o = 1;
					z = m;
					p = z;

					while (z != 0) {
						p /= 100;
						w = z - (p * 100);
						x[o] = w;
						o++;
						x = realloc(x, o + 1);
						z = p;
					}

					x[o] = 0;
				}

				o = g + 1;
				free(i[0][0][m]);
				i[0][0][m] = malloc(o + 1);
				r = i[0][0][m];
				r[0] = 1; /* .. */
				r[o] = 0;
				n = 0;
				p = 0;
				x = (unsigned char *) b;

				while (o != p) {
					p++;
					r[p] = x[n];
					n++;
				}
			} else {
				x = i[0][0][m];
			}

			m = 0;
		}
	}

	if (t == 1) {
		c[0][0][0] += 1;
		m = c[0][0][0];
		n = m * sizeof(unsigned char *);
		m--;
		h[0][0] = realloc(h[0][0], n);
		o = y;
		h[0][0][m] = malloc(o + 1);
		r = h[0][0][m];
		r[0] = o;
		p = o;

		while (o != 0) {
			p--;
			r[o] = q[p];
			o--;
		}

		i[0][0] = realloc(i[0][0], n);

		if (f == l) {
			i[0][0][m] = malloc(g + 1);
			r = i[0][0][m];
			r[0] = 1; /* .. */
			r[g] = 0;
			n = 0;
			o = 0;
			x = (unsigned char *) b;

			while (n != g) {
				n++;
				r[n] = x[o];
				o++;
			}
		} else {
			i[0][0][m] = malloc(2);
			x = i[0][0][m];
			x[0] = 0;
		}
	}

	while (l != f) {
		if (e[l] < 32) {
			q = (unsigned char *) a[l];
			y = e[l];
		} else {
			AvolittyAssociatorF(e[l], q, (unsigned char *) a[l]);
			y = 32;
		}

		m = d[0];
		o = 0;

		while (m != 0) {
			m--;

			if (c[0][m][1] == l) {
				if (c[0][m][0] != 0 && v == 0) {
					n = c[0][m][0];

					while (n != 0) {
						n--;
						r = h[0][m][n];
						p = r[0];
						t = 0;
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
							if (f == l + 1) {
								o = 1;
								z = m;
								p = z;

								while (z != 0) {
									p /= 100;
									w = z - (p * 100);
									x[o] = w;
									o++;
									x = realloc(x, o + 1);
									z = p;
								}

								x[o] = 0;
								o = g + 1;
								free(i[0][m][n]);
								i[0][m][n] = malloc(o + 1);
								r = i[0][m][n];
								r[0] = 1;
								r[o] = 0;
								n = 0;
								p = 0;
								x = (unsigned char *) b;

								while (n != o) {
									n++;
									r[n] = x[p];
									p++;
								}
							} else {
								x = i[0][m][n];
							}

							m = 0;
							n = 0;
							o = 0;
							t = 2;
						} else {
							v = 1;
						}
					}
				} else {
					if (t == 1) {
						o = m;
						t = 0;
					}
				}
			}
		}

		if (t == 0) {
			m = o;
			d[0] += 1;
			n = e[l];
			h[0][o] = malloc(sizeof(unsigned char *));
			h[0][o][0] = malloc(n + 1);
			r = h[0][o][0];
			r[0] = y;
			o = n;

			while (n != 0) {
				n--;
				r[o] = q[n];
				o--;
			}

			if (f == l + 1) {
				n = 1;
				z = m;
				o = z;

				while (z != 0) {
					o /= 100;
					p = z - (o * 100);
					x[n] = p;
					n++;
					x = realloc(x, n + 1);
					z = o;
				}

				x[n] = 0;
				o = g + 1;
				i[0][m][0] = malloc(o + 1);
				r = i[0][m][0];
				r[0] = 1;
				r[o] = 0;
				n = 0;
				p = 0;
				x = (unsigned char *) b;

				while (g != n) {
					n++;
					r[n] = x[p];
					p++;
				}
			} else {
				n = 1;
				z = m;
				o = z;

				while (z != 0) {
					o /= 100;
					p = z - (o * 100);
					x[n] = p;
					n++;
					x = realloc(x, n + 1);
					z = o;
				}

				x[n] = 0;
				i[0][m][0] = malloc(2);
				x = i[0][m][0];
				x[0] = 0;
			}
		} else {
			if (t == 1) {
				d[0] += 1;
				m = d[0];
				n = m * sizeof(unsigned char * *);
				m--;
				c[0] = realloc(c[0], n);
				c[0][m] = malloc(sizeof(unsigned long) * 2);
				c[0][m][0] = 1;
				c[0][m][1] = l;
				h[0] = realloc(h[0], n);
				h[0][m] = malloc(sizeof(unsigned char *));
				o = y;
				h[0][m][0] = malloc(o + 1);
				r = h[0][m][0];
				r[0] = o;
				p = o;

				while (o != 0) {
					p--;
					r[o] = q[p];
					o--;
				}

				i[0] = realloc(i[0], n);
				i[0][m] = malloc(sizeof(unsigned char *));

				if (f == l + 1) {
					n = 1;
					z = m;
					o = z;

					while (z != 0) {
						o /= 100;
						p = z - (o * 100);
						x[n] = p;
						n++;
						x = realloc(x, n + 1);
						z = o;
					}

					x[n] = 0;
					o = g + 1;
					i[0][m][0] = malloc(o + 1);
					r = i[0][m][0];
					r[0] = 1;
					r[o] = 0;
					n = 0;
					p = 0;
					x = (unsigned char *) b;

					while (g != n) {
						n++;
						r[n] = x[p];
						p++;
					}
				} else {
					n = 1;
					z = m;
					o = z;

					while (z != 0) {
						o /= 100;
						p = z - (o * 100);
						x[n] = p;
						n++;
						x = realloc(x, n + 1);
						z = o;
					}

					x[n] = 0;
					i[0][m][0] = malloc(2);
					x = i[0][m][0];
					x[0] = 0;
				}
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
