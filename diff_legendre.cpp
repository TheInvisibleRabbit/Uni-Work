#include <cmath>
double diff_legendre(double x, int n)
{
	int i;
	double p[n+1];
	p[0] =0;
	p[1] =1;
	for (i = 1; i < n; i++){
		//Iterative method to work out next value
		p[i+1] = ((2*i+1)*x*p[i]/i-(i+1)*p[i-1]/i);
	}
return p[i];

}
