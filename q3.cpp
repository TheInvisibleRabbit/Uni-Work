#include <iostream>
#include <cmath>
#include <iomanip>

double integrate_h(int n);

int main(int arc, char* argv[])
{
double answer;
int n;

	for (n=1;n<=5;n++){
		answer = integrate_h(n);
		std::cout << std::setprecision(15) << "For n = " << n << " the answer is "<< answer << '\n';
	}
	return 0;
}

