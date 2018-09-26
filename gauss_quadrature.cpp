#include <cmath>
#include <iostream>


double legendre(double x, int n);
double diff_legendre(double x, int n);

void gauss_quadrature(int n, double tol, double *w, double *xi)
{
	double pi = M_PI, error, xi_temp;
	int  j;

	//This gets the values for xi and puts them all in an array
	for (j=0;j<n;j++){
		error = 2*tol;
		xi[j] = -cos((2*double(j+1)-1)*pi/(2*double(n)));
		while (error>tol){
			xi_temp = xi[j];
			xi[j] = xi[j] - legendre(xi[j],n)/diff_legendre(xi[j],n);
			error = fabs(xi_temp-xi[j]);
		}
	}
	//Using the quad points, finds the weight values
	for (j=0;j<n;j++){
		w[j] = 2/((1-pow(xi[j],2))*pow(diff_legendre(xi[j],n),2));
	}

}
