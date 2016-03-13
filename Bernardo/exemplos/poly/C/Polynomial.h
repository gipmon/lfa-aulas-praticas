#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

struct roots
{
	int length;
	double root[2];
};

struct roots getRoots(double coef[]);

#endif
