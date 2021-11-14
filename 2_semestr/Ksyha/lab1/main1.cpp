#include <iostream>
using namespace std;

//задание № 1

int main(){
	int a, b;
	cout << "Enter a: ";
	cin >> a;
	cout << "Enter b: ";
	cin >> b;

	int ans = 0;
	ans = a%b;

	cout << "Answer: " << ans;
}