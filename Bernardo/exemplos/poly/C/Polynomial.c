#include <math.h>

#include "Polynomial.h"

struct roots getRoots(double coef[3])
{
    double s = coef[1] * coef[1] - 4 * coef[0] * coef[2];
    struct roots r;
    
    if (s < 0) 
    {
		r.length = 0;
		return r;
	}
    else if (s == 0)
    {
		r.length = 1;
		r.root[0] = -coef[1] / (2 * coef[0]);
		return r;
	}
	else
    {
		r.length = 2;
		r.root[0] = (-coef[1] - sqrt (s)) / (2 * coef[0]);
	    r.root[1] = (-coef[1] + sqrt (s)) / (2 * coef[0]);
	    return r;
	}
}


