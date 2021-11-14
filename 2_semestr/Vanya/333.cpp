#include <iostream>
#include <cmath>
#include <conio.h>
#pragma hdrstop
#pragma argsused
using namespace std;
int main(int argc, int argv[])
{
	int ac, bc, cc, i = 0;
	double a, b, c, x, xn, xk, dx, F;
	cout << "Enter a = "; cin >> a;
	cout << "Enter b = "; cin >> b;
	cout << "Enter c = "; cin >> c;
	cout << "Enter xn = "; cin >> xn;
	cout << "Enter xk ="; cin >> xk;
	cout << "Enter dx"; cin >> dx;
	ac = a, bc = b, cc = c;
	cout << "\n\\n X " << ' ' << "F" << endl << endl;
	for (x = xn; x <= xk; x += dx)
	{
		if ((a < 0) && (x != 0))F = a * x * x + b * b * x;
		if ((a > 0) && (x == 0))F = x - (a / (x - c));
		else F = 1 + x / c;
		if (((~(ac | bc)) & (bc | cc)) != 0)
		{
			cout << ++i << "|" << x << "|" << F << endl;
		}
		else {
			cout << ++i << "|" << x << "|" << int(F) << endl;
		}
	}
	return 0;
}


