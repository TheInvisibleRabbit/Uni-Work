#include <iostream>
#include <cmath>

double integrate_f(int n, double tol, double *w, double *xi);

int main(int arc, char* argv[])
{
	int n;
	double tol, approx,*w, *xi, actual_val, pi =M_PI;

	actual_val = -sinh(pi);
	tol = pow(10,-10);

	for (n=1;n<=10;n++){

	w = new double[n];
	xi = new double[n];

	approx = integrate_f(n,tol, w, xi);
	std::cout << "Approximation for n = "<< n <<" is " << approx << "\n";
	std::cout << "Absolute error is " << fabs(approx-actual_val) << "\n\n";
	}

	delete [] w;
	delete [] xi;

return 0;
}



