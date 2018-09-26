#include <iostream>

double legendre(double x, int n);

int main(int arc, char* argv[])
{
	double ans1, ans2, ans3;
	ans1 = legendre(0.3,2);
	ans2 = legendre(-0.5,6);
	ans3 = legendre(0.4,9);
	std::cout << "P2(0.3) = " << ans1 << "\n";
	std::cout << "P6(-0.5) = " << ans2 << "\n";
	std::cout << "P9(0.4) = " << ans3 << "\n";
	return 0;
}



