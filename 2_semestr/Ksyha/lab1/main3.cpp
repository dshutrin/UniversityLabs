#include <iostream>
using namespace std;

int main(){
	int a;
	cout << "Enter digit: ";
	cin >> a;
	cout << "Sum: " << (a/10 + a%10) << "\nProduct: " << (a/10 * a%10);
}