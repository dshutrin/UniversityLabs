#include <iostream>
using namespace std;

int main(){
	int dey;
	double a, b;
	cout << "Choice dey:\n1) +\n2) -\n3) *\n4) /\n>>> ";
	cin >> dey;
	cout << "Enter a, b (10 13): ";
	cin >> a;
	cin >> b;
	if (dey == 1)
		cout << a+b;
	if (dey == 2)
		cout << a-b;
	if (dey == 3)
		cout << a*b;
	if (dey == 4)
		cout << a/b;
}