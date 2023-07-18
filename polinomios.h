#ifndef POL
#define POL

typedef struct t_pol *pol;

/*	Creates a polinomial based on input. Allocates new memory for the coeficients. */
pol create_pol(double *coef, unsigned int gr, double center);

double try_pol(pol p, double x);

pol add_pols(pol p, pol q);

pol mul_pols(pol p, pol q);

void dump_pol(pol p);

pol destroy_pol(pol p);



#endif