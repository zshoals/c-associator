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
					o = g + 3;
					free(i[0][0][m]);
					i[0][0][m] = malloc(o);
					r = i[0][0][m];

					if (r != 0) {
						r[0] = 1; /* .. */
						o = 2;
						p = g / 100;
						w = g - (p * 100);
						r[1] = w;
						z = p;

						while (z != 0 && r != 0) {
							p /= 100;
							w = z - (p * 100);
							r[o] = w;
							n++;
							o++;
							r = realloc(r, n);

							if (r != 0) {
								z = p;
							} else {
								u = 1;
							}
						}

						if (u == 0) {
							r[o] = 0;
							o++;
							n = 0;
							x = (unsigned char *) b;

							while (n != g) {
								r[o] = x[n];
								n++;
								o++;
							}
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
							n = g + 3;
							i[0][0][m] = malloc(n);
							r = i[0][0][m];

							if (r != 0) {
								r[0] = 1; /* .. */
								o = 2;
								p = g / 100;
								w = g - (p * 100);
								r[1] = w;
								z = p;

								while (z != 0 && r != 0) {
									p /= 100;
									w = z - (p * 100);
									r[o] = w;
									n++;
									o++;
									r = realloc(r, n);

									if (r != 0) {
										z = p;
									} else {
										u = 1;
									}
								}

								if (u == 0) {
									r[o] = 0;
									o++;
									n = 0;
									x = (unsigned char *) b;

									while (n != g) {
										r[o] = x[n];
										n++;
										o++;
									}
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
					m = (m * 100) + x[n];
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
							o = g + 3;
							free(i[0][m][n]);
							i[0][m][n] = malloc(o);
							r = i[0][m][n];

							if (r != 0) {
								r[0] = 1; /* .. */
								n = 2;
								p = g / 100;
								w = g - (p * 100);
								r[1] = w;
								z = p;

								while (z != 0 && r != 0) {
									p /= 100;
									w = z - (p * 100);
									r[n] = w;
									n++;
									o++;
									r = realloc(r, o);

									if (r != 0) {
										z = p;
									} else {
										u = 1;
									}
								}

								if (u == 0) {
									r[n] = 0;
									n++;
									o = 0;
									x = (unsigned char *) b;

									while (o != g) {
										r[n] = x[o];
										n++;
										o++;
									}
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

										if (x != 0) {
											z = p;
										} else {
											u = 1;
										}
									}

									if (u == 0) {
										x[o] = 0;

										if (f == l + 1) {
											o = g + 3;
											free(i[0][m][n]);
											i[0][m][n] = malloc(o);
											r = i[0][m][n];

											if (r != 0) {
												r[0] = 1; /* .. */
												n = 2;
												p = g / 100;
												w = g - (p * 100);
												r[1] = w;
												z = p;

												while (z != 0 && r != 0) {
													p /= 100;
													w = z - (p * 100);
													r[n] = w;
													n++;
													o++;
													r = realloc(r, o);

													if (r != 0) {
														z = p;
													} else {
														u = 1;
													}
												}

												if (u == 0) {
													r[n] = 0;
													n++;
													o = 0;
													x = (unsigned char *) b;

													while (o != g) {
														r[n] = x[o];
														n++;
														o++;
													}
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
						m = (m * 100) + x[n];
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

								if (x != 0) {
									z = o;
								} else {
									u = 1;
								}
							}

							if (u == 0) {
								x[w] = 0;

								if (f == l + 1) {
									o = g + 3;
									i[0][m][n] = malloc(o);
									r = i[0][m][n];

									if (r != 0) {
										r[0] = 1; /* .. */
										n = 2;
										p = g / 100;
										w = g - (p * 100);
										r[1] = w;
										z = p;

										while (z != 0 && r != 0) {
											p /= 100;
											w = z - (p * 100);
											r[n] = w;
											n++;
											o++;
											r = realloc(r, o);

											if (r != 0) {
												z = p;
											} else {
												u = 1;
											}
										}

										if (u == 0) {
											r[n] = 0;
											n++;
											o = 0;
											x = (unsigned char *) b;

											while (o != g) {
												r[n] = x[o];
												n++;
												o++;
											}
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
	[u] - array of values
	[v] - value result data type
	[i] - key object type identifier
		0 - integral object
		1 - string object
*/

unsigned char AvolittyAssociatorC(void * * a, void * * b, unsigned long * * * c, unsigned long * d, unsigned long * e, unsigned long * f, unsigned long g, unsigned char * * * * h, unsigned char * * * * u, unsigned char * v, unsigned char i) {
	unsigned long j = 0;
	unsigned char k = 0;
	unsigned long * l;
	unsigned long m;
	unsigned char * n;
	unsigned char o;
	unsigned char * p;
	unsigned char q;
	unsigned char r;
	unsigned char s;
	unsigned long t;

	while (g != j && k == 0) {
		if (e[j] < 32) {
			n = (unsigned char *) a[j];
			o = e[j];
		} else {
			AvolittyAssociatorF(e[j], n, (unsigned char *) a[j]);
			o = 32;
		}

		t = 0;

		while (t != d[0]) {
			if (c[0][t][1] == j) {
				m = c[0][t][0];

				while (m != 0) {
					m--;
					p = h[0][t][m];
					q = p[0];

					if (o == q) {
						r = q;
						s = 0;

						while (q != 0) {
							q--;

							if (n[q] != p[r]) {
								q = 0;
								s = 1;
							}

							r--;
						}

						if (s == 0) {
							k = 0;
							f[0] = m;
							m = 0;
						}
					}
				}

				if (s == 1) {
					k = 1;
				} else {
					m = t;
					t = d[0] - 1;
				}
			}

			t++;
		}

		if (k == 1) {
			g = j;
		} else {
			j++;
		}
	}

	if (k == 0) {
		g = f[0];
		f[0] = 0;
		p = u[0][m][g];
		g = 1;
		m = 0;

		while (p[g] != 0) {
			m = (m * 100) + p[g];
			g++;
		}

		v[0] = p[0];

		if (p[0] != 0) {
			b[0] = realloc(b[0], m);
			n = (unsigned char *) b[0];

			if (n != 0) {
				f[0] = m;
				g++;
				m = 0;

				while (m != f[0]) {
					n[m] = (unsigned char) p[g];
					g++;
					m++;
				}

				k = 1;
			}
		}
	}

	if (f[0] == 0 && k == 0) {
		k = 1;
	}

	return k;
}

/*
	[a] - key
	[b] - global data
	[c] - global data length
	[d] - key lengths
	[t] - memory allocation error indexes
	[e] - key depth
	[f] - array of keys
	[g] - array of values
	[h] - key object type identifier
		0 - integral object
		1 - string object
	[u] - memory allocation error status
*/

unsigned char AvolittyAssociatorD(void * * a, unsigned long * * * b, unsigned long * c, unsigned long * d, unsigned long * t, unsigned long e, unsigned char * * * * f, unsigned char * * * * g, unsigned char h, unsigned char u) {
	unsigned long i = 0;
	unsigned char j = 0;
	unsigned char * k;
	unsigned long l;
	unsigned long m;
	unsigned long n;
	unsigned char * o;
	unsigned char p;
	unsigned char q;
	unsigned char r;
	unsigned long s;

	if (u == 1) {
		l = t[0];
		m = t[1];
		k = g[0][l][m];
		free(k);
		f[0][l][m] = malloc(2);
		k = g[0][l][m];

		if (k != 0) {
			k[0] = 0;
			k[1] = 0;
			k = f[0][l][m];
			free(k);
			f[0][l][m] = malloc(2);
			k = f[0][l][m];

			if (k != 0) {
				k[0] = 0;
				k[1] = 0;
			} else {
				j = 1;
			}
		} else {
			j = 1;
		}
	}

	while (e != i && j == 0) {
		if (d[i] < 32) {
			k = (unsigned char *) a[i];
			l = d[i];
		} else {
			AvolittyAssociatorF(d[i], k, (unsigned char *) a[j]);
			l = 32;
		}

		m = 0;

		while (m != c[0]) {
			if (b[0][m][1] == i) {
				n = b[0][m][0];

				while (n != 0) {
					n--;
					o = f[0][m][n];
					p = o[0];

					if (l == p) {
						q = p;
						r = 0;

						while (p != 0) {
							p--;

							if (k[p] != o[q]) {
								p = 0;
								r = 1;
							}

							q--;
						}

						if (r == 0) {
							j = 0;
							s = n;
							n = 0;
						}
					}
				}

				if (r == 1) {
					j = 1;
				} else {
					n = m;
					m = c[0] - 1;
				}
			}

			m++;
		}

		if (j == 1) {
			e = i;
		} else {
			i++;
		}
	}

	if (j == 0) {
		o = g[0][n][s];
		e = 1;
		m = 0;

		while (o[e] != 0) {
			m = (m * 100) + o[e];
			e++;
		}

		if (o[0] == 0) {
			e = b[0][m][0];

			while (e != 0) {
				e--;
				o = g[0][m][e];

				if (o[1] != 0) {
					if (o[0] == 0) {
						/* .. */
					} else {
						free(o);
						g[0][m][e] = malloc(2);
						o = g[0][m][e];

						if (o != 0) {
							o[0] = 0;
							o[1] = 0;
						} else {
							j = 1;
							t[0] = m;
							t[1] = e;
						}
					}
				}
			}
		} else {
			free(o);
			g[0][n][s] = malloc(2);
			o = g[0][n][s];

			if (o != 0) {
				o[0] = 0;
				o[1] = 0;
			} else {
				j = 1;
				t[0] = m;
				t[1] = e;
			}
		}
	}

	/* delete/resize */
	return j;
}

unsigned char AvolittyAssociatorE(void * a, void * b, unsigned long c, unsigned char * d) {
	/* string|float|int to char converter for B C D key strings */
	return 0;
}
