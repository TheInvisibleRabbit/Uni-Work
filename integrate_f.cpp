#include <iostream>
#include <cmath>

void gauss_quadrature(int n, double tol, double *w, double *xi);

double integrate_f(int n, double tol, double *w, double *xi)
{
	double diff_over_2, sum_over_2, pi = M_PI, upper_bound = pi, lower_bound = -pi, scaled_val =0;
	int j;
	gauss_quadrature(n,tol,w,xi);
	diff_over_2 = (upper_bound-lower_bound)/2;
	sum_over_2 = (upper_bound+lower_bound)/2;
	for (j=0;j<n;j++){
		//Scales the function using scaling factor found online
		scaled_val = scaled_val + w[j]*cos(diff_over_2*xi[j]+sum_over_2)*exp(diff_over_2*xi[j]+sum_over_2);
	}
	scaled_val = scaled_val*diff_over_2;


return scaled_val;
}




