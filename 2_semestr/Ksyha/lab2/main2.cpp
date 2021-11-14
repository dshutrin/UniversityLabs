#include <iostream>
using namespace std;

int main(){
	int a;
	cout << "Enter digit: ";
	cin >> a;
	if (a > 0)
		a++;
	else
		if (a != 0)
			a -= 2;
	cout << a;
}