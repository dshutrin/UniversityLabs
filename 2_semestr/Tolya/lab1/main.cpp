#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	system("chcp 65001");

	double a, z, x;
	cout << "Введите кол во радианов" << endl; //ВВод радианов
	cin >> a;
	z = 4 * cos(a / 2) + cos(5 / 2 * a) + cos(4 * a);// расчет
	x = cos(a) + cos(2 * a) + cos(6 * a) + cos(7 * a); // расчет
	cout << z << endl;
	cout << x << endl;//вывод данных
	return 0;
}
