#include <iostream>
#include <cmath>

void gauss_quadrature(int n, double tol, double *w, double *xi);

int main(int arc, char* argv[])
{
	double *w, *xi, tol;
	int n, j;
	tol = pow(10,-10);


	n = 2;
	//Dynamically allocating the quad points and weights
	w = new double[n];
	xi = new double[n];
	gauss_quadrature(n,tol,w,xi);
	std::cout <<"for n = 2 \n";
	for (j=0;j<n;j++){
		std::cout  << j+1 << " xi value is "<< xi[j] <<". weight value is "<< w[j] << "\n\n";
	}

	n = 4;
	w = new double[n];
	xi = new double[n];
	gauss_quadrature(n,tol,w,xi);
	std::cout <<"for n = 4 \n";
	for (j=0;j<n;j++){
		std::cout << j+1 << " xi value is "<< xi[j] <<". weight value is "<< w[j] << "\n\n";
	}

	n = 7;
	w = new double[n];
	xi = new double[n];
	gauss_quadrature(n,tol,w,xi);
	std::cout <<"for n = 7 \n";
	for (j=0;j<n;j++){
		std::cout << j+1 << " xi value is "<< xi[j] <<". weight value is "<< w[j] << "\n\n";
	}

	delete [] w;
	delete [] xi;

}

