#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "polinomios.h"

struct t_pol
{
	double *coef;
	unsigned int gr;
	double center;
};

pol create_pol(double *coef, unsigned int gr, double center)
{
	pol p = malloc(sizeof(struct t_pol));

	p->center = center;

	p->coef = (double *) calloc(gr + 1u, sizeof(double));

	for (unsigned int i = 0; i < gr + 1 ; ++i)
	{
		p->coef[i] = coef[i];
	}

	p->gr = gr;

	return p;
}
double try_pol(pol p, double x)
{
	double res = 0, aux0, aux1;
	
	if(p->gr == 0)
	{
		res = p->coef[0];
	}
	else
	{
		aux0 = p->coef[p->gr-1u];
		aux1 = p->coef[p->gr];

		res = aux0 + aux1 * x;

		for (unsigned int i = 2u; i < p->gr + 1u; ++i)
		{


			res = (p->coef[p->gr - i]) + res * x;
		}	
	}

	return res;
}

pol add_pols(pol p, pol q)
{
	unsigned int new_gr = (p->gr >= q->gr) ? p->gr : q->gr;
	double *new_coef = malloc((new_gr + 1u) * sizeof(double));		// NOTE: Needs to be improved
	bool still_zero;

	unsigned int i = new_gr;
	still_zero = 1;

	while(i >= 0)
	{
		new_coef[i] = p->coef[i] + q->coef[i];
		still_zero = still_zero && (new_coef[i] == 0);

		if(still_zero && new_gr > 0)
		{
			--new_gr;
		}

		new_coef[p->gr - i] = 		

		--i;
	}


	return r;
}

pol mul_pols(pol p, pol q);

void dump_pol(pol p)
{
	fprintf(stdout, " %.1lf+", p->coef[0]);

	for (unsigned int i = 1; i < p->gr; ++i)
	{
		fprintf(stdout, "%.1lf*(x-%.1lf)^%u+", p->coef[i], p->center, i);
	}

	fprintf(stdout, "%.1lf*(x-%.1lf)^%u", p->coef[p->gr], p->center, p->gr);

	fprintf(stdout, "\n");
}

pol destroy_pol(pol p)
{
	free(p->coef);
	free(p);
	p = NULL;

	return p;
}