#include <iostream>
using namespace std;
int main()
{
	// Initializing floating point variable
	float a = 1.999998f;
	float b = 2323.0f;
	char c = 'a';

	// Specifying precision
	cout.precision(8);

	// Printing normal values
	cout << "Normal values of floating point numbers\na = ";
	cout << a << "\nb = " << b << '\n';

	// Printing values using fixed ( till 4 )
	cout << "Values using fixed \n"
			 << std::fixed;
	cout << a << "\n"
			 << b << '\n';

	// Printing values using scientific ( till 4 )
	// after 4, exponent is used
	cout << "Values using scientific are : " << std::scientific << endl;
	cout << a << '\n'
			 << b << '\n';

	// Printing values using hexfloat ( till 4 )
	cout << "Values using hexfloat are : " << std::hexfloat << endl;
	cout << a << '\n'
			 << b << '\n';

	// Printing values using defaultfloat ( till 4 )
	// same as normal
	cout << "Values using defaultfloat are : " << std::defaultfloat << endl;
	cout << a << '\n'
			 << b << '\n';

	return 0;
}