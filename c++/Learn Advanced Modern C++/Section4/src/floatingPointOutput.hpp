#ifndef FLOATING_POINT_OUTPUT_H
#define FLOATING_POINT_OUTPUT_H

#include <iostream>
#include <iomanip>

using namespace std;

namespace floatingPointOutput
{
	void precision()
	{
		double pi{3.141'592'653'5};
		int precision{3}, default_precision{6};

		cout << "pi to " << precision << " significant figures is ";
		cout << setprecision(precision) << pi << endl;

		cout << "pi to " << default_precision << " significant figures is ";
		cout << setprecision(default_precision) << pi << endl;
	}
	void fixedManip()
	{
		double c{299'792'458};
		cout << fixed << c << endl; // padded - displays 299792458.000000
		double e{1.602e-19};
		cout << fixed << e << endl; // truncated - displays 0.000000
	}
	void scientificNotation()
	{
		double pi{3.141'592'653'5};
		cout << scientific << pi << endl;			   // displays 3.141593e+000
		cout << scientific << uppercase << pi << endl; // displays 3.141593E+000
	}
	int main()
	{
		// double pi{3.141'592'653'5}; // displays 3.14159
		// cout << pi << endl;

		// double c{299'792'458}; // displays .299792e+08
		// cout << c << endl;
		// scientificNotation();
		precision();
		return 0;
	}
}
#endif // FLOATING_POINT_OUTPUT_H