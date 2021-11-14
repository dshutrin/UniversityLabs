#include <iostream>
using namespace std;

int main(){
	system("chcp 65001");
	system("cls");
	int a;
	cout << "Enter digit: ";
	cin >> a;
	if ((a > 0) and (a < 6)){
		if (a == 1)
			cout << "плохо";
		if (a == 2)
			cout << "неудовлетворительно";
		if (a == 3)
			cout << "удовлетворительно";
		if (a == 4)
			cout << "хорошо";
		if (a == 5)
			cout << "отлично";
	}
	else
		cout << "ошибка";
}