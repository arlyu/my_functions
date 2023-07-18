#include <stdio.h>
#include <stdlib.h>
#include "polinomios.h"

int main(void)
{
	unsigned int gr = 5u;
	double *coef = malloc((gr + 1u)*sizeof(double));
	double center = 0;
	double some_value;
	int loop = 1;

	for (unsigned int i = 0u; i < gr + 1u; ++i)
	{
		coef[i] = i+1;
	}

	pol p = create_pol(coef, gr, center);

	while(loop)
	{
		dump_pol(p);
		fprintf(stdout, "Insert a value to try\n");
		fscanf(stdin, "%lf", &some_value);
		fprintf(stdout, "%lf\n", try_pol(p, some_value));
	}

	free(coef);
	destroy_pol(p);

	return EXIT_SUCCESS;
}