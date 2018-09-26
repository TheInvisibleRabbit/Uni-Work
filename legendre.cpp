#include <cmath>
double legendre(double x, int n)
{
	double p[n+1];
	int i;
	p[0] = 1;
	p[1] = x;
	for (i = 1.0; i < n; i++){
		//Iterative method to work out next value
		p[i+1] = (2*i+1)*x*p[i]/(i+1)-i*p[i-1]/(i+1);
	}
return p[i];

}

