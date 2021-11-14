#include <iostream>
using namespace std;

class Complex {
public:
	double a, b;

	Complex(double first = 0.0, double second = 0.0) {
		a = first;
		b = second;
	}

	void value() {
		if (b >= 0)
			cout << a << " + " << b << "i";
		else
			cout << a << " - " << 0 - b << "i";
	}
};

Complex operator + (Complex& var_1, Complex& var_2) {
	Complex ans(var_1.a + var_2.a, var_1.b + var_2.b);
	return ans;
}

Complex operator - (Complex& var_1, Complex& var_2) {
	Complex ans(var_1.a - var_2.a, var_1.b - var_2.b);
	return ans;
}

Complex operator * (Complex& var_1, Complex& var_2) {
	Complex ans((var_1.a * var_2.a - var_1.b * var_2.b), (var_1.a * var_2.b + var_1.b * var_2.a));
	return ans;
}

int main() {

	int program = 0;
	double a, b, c, d;
	Complex ans;

	cout << "Enter var1 a: ";	cin >> a;
	cout << "Enter var1 b: ";	cin >> b;

	Complex var1;
	var1.a = a;		var1.b = b;

	cout << "Enter var2 a: ";	cin >> c;
	cout << "Enter var2 b: ";	cin >> d;

	Complex var2;
	var2.a = c;		var2.b = d;

	cout << "var1 = ";	var1.value();	cout << endl;
	cout << "var2 = ";	var2.value();	cout << endl << endl;

	while (program != 5) {
		cout << "\nChoice operation:\n1) +  2) -  3) *  4) remap numbers  5) exit\n>>> ";
		cin >> program;

		if (program == 1) {
			cout << "var1 + var2 = ";
			ans = var1 + var2;
			ans.value();
			cout << endl;
		}

		if (program == 2) {
			cout << "var1 - var2 = ";
			ans = var1 - var2;
			ans.value();
			cout << endl;
		}

		if (program == 3) {
			cout << "var1 * var2 = ";
			ans = var1 * var2;
			ans.value();
			cout << endl;
		}

		if (program == 4) {
			cout << "Enter var1 a: ";	cin >> a;
			cout << "Enter var1 b: ";	cin >> b;
			var1.a = a;					var1.b = b;
			cout << "Enter var2 a: ";	cin >> c;
			cout << "Enter var2 b: ";	cin >> d;
			var2.a = c;					var2.b = d;

			cout << "var1 = ";	var1.value();	cout << endl;
			cout << "var2 = ";	var2.value();	cout << endl << endl;
		}
	}
}