#include <stdio.h>
#include <stdlib.h>

#include "Polynomial.h"

int main(int argc, char* argv[])
{
    /* check commmand line */
    if (argc != 4)
    {
        fprintf(stderr, "Wrong number of arguments\n");
        exit(EXIT_FAILURE);
    }

    /* extract coefficients from arguments */
    double coef[3];
    int i;    
    for (i = 0; i < 3; i++)
    {
		if (sscanf(argv[i+1], "%lg", &coef[i]) !=1)
		{
			fprintf(stderr, "Invalid argument argv[%d] = \"%s\"\n", i, argv[i]);
			exit(EXIT_FAILURE);
		}
    }

	/* compute roots */
    struct roots r = getRoots(coef);

    /* print results */
    fprintf(stdout, "Roots of (%g, %g, %g) = \n", coef[0], coef[1], coef[2]);
    switch (r.length)
    {
        case 0:
            fprintf(stdout, "  No roots\n");
            break;

        case 1:
            fprintf (stdout, "  One root: %g\n", r.root[0]);
            break;

        case 2:
            fprintf (stdout, "  Root 1: %g\n", r.root[0]);
            fprintf (stdout, "  Root 2: %g\n", r.root[1]);
            break;
    }
	return 0;
}

