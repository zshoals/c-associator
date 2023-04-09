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
	unsigned char e = 0;
	a[0] = malloc(sizeof(unsigned long *));

	if (a[0] != 0) {
		a[0][0] = malloc(sizeof(unsigned long) * 2);

		if (a[0][0] != 0) {
			a[0][0][0] = 0;
			a[0][0][1] = 0;
			b[0] = 1;
			c[0] = malloc(sizeof(unsigned char * *));

			if (c[0] != 0) {
				d[0] = malloc(sizeof(unsigned char * *));

				if (d[0] == 0) {
					e = 1;
				}
			} else {
				e = 1;
			}
		} else {
			e = 1;
		}
	} else {
		e = 1;
	}

	return e;
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
*/

unsigned char AvolittyAssociatorB(void * * a, void * b, unsigned long * * * c, unsigned long * d, unsigned long * e, unsigned long f, unsigned long g, unsigned char * * * * h, unsigned char * * * * i, unsigned char j, unsigned char k) {
	unsigned long l = 0;
	unsigned long m = 0;
	unsigned long n = 0;
	unsigned long o;
	unsigned long p = 0;
	unsigned char * q;
	unsigned char * r;
	unsigned char s = 0;
	unsigned char t = 1;
	unsigned char u = 0;
	unsigned char v = 0;
	unsigned long w = 0;
	unsigned char * x;
	unsigned char y;
	unsigned long z = 0;
	q = malloc(32);

	if (q != 0) {
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

		while (m != 0 && u == 0) {
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
					o = g + 1;
					free(i[0][0][m]);
					i[0][0][m] = malloc(o + 1);
					r = i[0][0][m];

					if (r != 0) {
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
						u = 1;
					}
				} else {
					s = 1;
					x = i[0][0][m];
				}

				m = 0;
			}
		}

		if (t == 1 && u == 0) {
			c[0][0][0] += 1;
			m = c[0][0][0];
			n = m * sizeof(unsigned char *);
			m--;
			h[0][0] = realloc(h[0][0], n);

			if (h[0][0] != 0) {
				o = y;
				h[0][0][m] = malloc(o + 1);
				r = h[0][0][m];

				if (r != 0) {
					r[0] = o;
					p = o;

					while (o != 0) {
						p--;
						r[o] = q[p];
						o--;
					}

					i[0][0] = realloc(i[0][0], n);

					if (i[0][0] != 0) {
						if (f == l) {
							i[0][0][m] = malloc(g + 1);
							r = i[0][0][m];

							if (r != 0) {
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
								u = 1;
							}
						} else {
							i[0][0][m] = malloc(2);
							x = i[0][0][m];

							if (x != 0) {
								x[0] = 0;
								x[1] = 0;
							} else {
								u = 1;
							}
						}
					} else {
						u = 1;
					}
				} else {
					u = 1;
				}
			} else {
				u = 1;
			}
		}

		while (l != f && u == 0) {
			if (e[l] < 32) {
				q = (unsigned char *) a[l];
				y = e[l];
			} else {
				AvolittyAssociatorF(e[l], q, (unsigned char *) a[l]);
				y = 32;
			}

			if (s == 1) {
				m = 0;
				n = 1;

				while (x[n] != 0) {
					m = (m * 10) + x[n];
					n++;
				}

				n = c[0][m][0];

				while (n != 0 && u == 0) {
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
							o = g + 1;
							free(i[0][m][n]);
							i[0][m][n] = malloc(o + 1);
							r = i[0][m][n];

							if (r != 0) {
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
								u = 1;
							}
						} else {
							x = i[0][m][n];
						}

						n = 0;
						s = 1;
					} else {
						s = 0;
					}
				}
			}

			if (s == 0) {
				m = d[0];
				o = 0;

				while (m != 0 && u == 0) {
					m--;

					if (c[0][m][1] == l) {
						if (c[0][m][0] != 0 && v == 0) {
							n = c[0][m][0];

							while (n != 0 && u == 0) {
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
									o = 1;
									z = m;
									p = z;

									while (z != 0 && x != 0) {
										p /= 100;
										w = z - (p * 100);
										x[o] = w;
										o++;
										x = realloc(x, o + 1);
										z = p;
									}

									if (x != 0) {
										x[o] = 0;

										if (f == l + 1) {
											o = g + 1;
											free(i[0][m][n]);
											i[0][m][n] = malloc(o + 1);
											r = i[0][m][n];

											if (r != 0) {
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
												u = 1;
											}
										} else {
											x = i[0][m][n];
										}

										m = 0;
										n = 0;
										o = 0;
									} else {
										u = 1;
									}
								} else {
									v = 1;
								}
							}
						}
					}
				}

				if (t == 1 && u == 0) {
					m = 0;
					n = 1;

					while (x[n] != 0) {
						m = (m * 10) + x[n];
						n++;
					}

					if (m == 0) {
						d[0] += 1;
						m = d[0];
						n = m * sizeof(unsigned char * *);
						m--;
						c[0] = realloc(c[0], n);

						if (c[0] != 0) {
							c[0][m] = malloc(sizeof(unsigned long) * 2);

							if (c[0][m] != 0) {
								c[0][m][0] = 1;
								c[0][m][1] = l;
								h[0] = realloc(h[0], n);

								if (h[0] != 0) {
									h[0][m] = malloc(sizeof(unsigned char *));

									if (h[0][m] != 0) {
										i[0] = realloc(i[0], n);

										if (i[0] != 0) {
											i[0][m] = malloc(sizeof(unsigned char *));

											if (i[0][m] != 0) {
												n = 0;
											} else {
												u = 1;
											}
										} else {
											u = 1;
										}
									} else {
										u = 1;
									}
								} else {
									u = 1;
								}
							} else {
								u = 1;
							}
						} else {
							u = 1;
						}
					} else {
						n = c[0][m][0];
						c[0][m][0] += 1;
						o = (n + 1) * sizeof(unsigned char *);
						h[0][m] = realloc(h[0][m], o);

						if (h[0][m] != 0) {
							i[0][m] = realloc(i[0][m], o);
							u = i[0][m] == 0;
						} else {
							u = 1;
						}
					}

					if (u == 0) {
						o = y;
						h[0][m][n] = malloc(o + 1);
						r = h[0][m][n];

						if (r != 0) {
							r[0] = o;
							p = o;

							while (o != 0) {
								p--;
								r[o] = q[p];
								o--;
							}

							w = 1;
							z = m;
							o = z;

							while (z != 0 && x != 0) {
								o /= 100;
								p = z - (o * 100);
								x[w] = p;
								w++;
								x = realloc(x, w + 1);
								z = o;
							}

							if (x != 0) {
								x[w] = 0;

								if (f == l + 1) {
									o = g + 1;
									i[0][m][n] = malloc(o + 1);
									r = i[0][m][n];

									if (r != 0) {
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
										u = 1;
									}
								} else {
									i[0][m][n] = malloc(2);
									x = i[0][m][n];

									if (x != 0) {
										x[0] = 0;
										x[1] = 0;
									} else {
										u = 1;
									}
								}
							} else {
								u = 1;
							}
						} else {
							u = 1;
						}
					}
				}
			}

			if (u == 0) {
				l++;
			} else {
				f = l;
			}
		}
	} else {
		u = 1;
	}

	/* .. */
	return u;
}

/*
	[a] - key
	[b] - value result
	[c] - global data
	[d] - global data length
	[e] - key lengths
	[f] - value result length
	[g] - key depth
	[h] - array of keys
	[i] - key object type identifier
		0 - integral object
		1 - string object
*/

unsigned char AvolittyAssociatorC(void * * a, void * b, unsigned long * * * c, unsigned long * d, unsigned long * e, unsigned long * f, unsigned long g, unsigned char * * * * h, unsigned char i) {
	unsigned long j = 0;
	unsigned char k = 0;
	unsigned long * l;
	unsigned long m;
	unsigned char * n;
	unsigned char o;
	unsigned char * p;
	unsigned char q;
	unsigned char r;

	while (g != j && k == 0) {
		if (e[j] < 32) {
			n = (unsigned char *) a[j];
			o = e[j];
		} else {
			AvolittyAssociatorF(e[j], n, (unsigned char *) a[j]);
			o = 32;
		}

		l = c[0][j];

		if (l[1] == j) {
			m = l[0];

			while (m != 0) {
				m--;
				p = h[0][j][m];
				q = p[0];

				if (o == q) {
					r = q;

					while (q != 0) {
						r--;

						if (n[r] != p[q]) {
							/* .. */
						}

						q--;
					}
				}
			}
		}

		j++;
	}

	if (f[0] == 0 && k == 0) {
		k = 1;
	}

	return k;
}

unsigned char AvolittyAssociatorD(void * a, void * b, unsigned long c, unsigned char * d) {
	/* delete/resize */
	return 0;
}

unsigned char AvolittyAssociatorE(void * a, void * b, unsigned long c, unsigned char * d) {
	/* string|float|int to char converter for B C D key strings */
	return 0;
}
