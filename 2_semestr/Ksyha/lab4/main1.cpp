#include <iostream>
using namespace std;

int main(){
	int a, b, n = 0;
	cout << "Enter a:";
	cin >> a;
	cout << "Enter b:";
	cin >> b;
	for (int i = a; i <= b; i++){
		n ++;
		cout << i << " ";
	}
	cout << endl << n;
}