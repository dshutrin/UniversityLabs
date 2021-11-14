#include <iostream>
using namespace std;

int main(){
	int a;
	cout << "Enter digit: ";
	cin >> a;

	if ((a > 0) and (a < 13)){
		if ((a > 2) and (a < 6))
			cout << "весна";
		if ((a > 5) and (a < 9))
			cout << "лето";
		if ((a > 8) and (a < 12))
			cout << "осень";
		if ((a == 12) or (a == 1) or (a == 2))
			cout << "зима";
	}else
		cout << "ошибка";

}