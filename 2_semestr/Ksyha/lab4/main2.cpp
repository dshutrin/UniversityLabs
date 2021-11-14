#include <iostream>
using namespace std;

int main(){
	int a, b, s = 0;
	cout << "Enter a: ";
	cin >> a;
	cout << "Enter b: ";
	cin >> b;
	for (int i = a; i <= b; i++){
		s += i;
	}
	cout << s;
}