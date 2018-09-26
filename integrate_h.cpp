#include <iostream>
#include <cmath>

void gauss_quadrature(int n, double tol, double *w, double *xi);

double integrate_h(int n)
{
double nodepoints[6][2] = {{0.1,0},{0.7,0.2},{1,0.5},{0.75,0.85},{0.5,1},{0,0.25}};
double dx[2], diff_over_2[2], sum_over_2[2], norm, unitnorm[2], tol = 0.00001;
double *w, *xi, line_val = 0;
int i, j;
double h[n], area_val=0, ximap[n], yimap[n];
w = new double[n];
xi = new double[n];

//getting the gauss quad points and weights
gauss_quadrature(n,tol,w,xi);

for (j=0;j<6;j++){
	//For the last line segment it has to be works out using the first and
	//last points, this if statement checks for that
if (j==5){
	dx[0] = nodepoints[0][0] - nodepoints[5][0];
	dx[1] = nodepoints[0][1] - nodepoints[5][1];
	norm = pow(dx[0]*dx[0]+dx[1]*dx[1],0.5);
	unitnorm[0] = dx[1]/norm;
	unitnorm[1] = -dx[0]/norm;

	//getting the mapped values for xi and yi
	diff_over_2[0] = dx[0]/2;
	diff_over_2[1] = dx[1]/2;
	sum_over_2[0] = (nodepoints[0][0] + nodepoints[5][0])/2;
	sum_over_2[1] = (nodepoints[0][1] + nodepoints[5][1])/2;
}
else{
	//getting the unit norm values
	dx[0] = nodepoints[j+1][0] - nodepoints[j][0];
	dx[1] = nodepoints[j+1][1] - nodepoints[j][1];
	norm = pow(dx[0]*dx[0]+dx[1]*dx[1],0.5);
	unitnorm[0] = dx[1]/norm;
	unitnorm[1] = -dx[0]/norm;

	//getting the mapped values for xi and yi
	diff_over_2[0] = dx[0]/2;
	diff_over_2[1] = dx[1]/2;
	sum_over_2[0] = (nodepoints[j+1][0] + nodepoints[j][0])/2;
	sum_over_2[1] = (nodepoints[j+1][1] + nodepoints[j][1])/2;
}

	//getting the value for h
	for (i=0;i<n;i++){
		ximap[i] = xi[i]*diff_over_2[0]+sum_over_2[0];
		yimap[i] = xi[i]*diff_over_2[1]+sum_over_2[1];
		h[i] = pow(ximap[i],5)*pow(yimap[i],3);
	}


	//summing the line segments together
	for (i=0;i<n;i++){
		line_val = line_val+(ximap[i]*unitnorm[0]+yimap[i]*unitnorm[1])*w[i]*h[i];
	}
	//multiply by the norm of the midpoints
	line_val = line_val*pow(pow(diff_over_2[0],2)+pow(diff_over_2[1],2),0.5);


	area_val = area_val + (line_val);
	line_val = 0;
}
	//Divide by 2+q where q is 8
	area_val = area_val/10;
	delete [] w;
	delete [] xi;

return area_val;
}


