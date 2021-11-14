#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	system("chcp 65001");

	int x, y, R;
	
	cout << "Введите кординату x" << endl;// Ввод
	cin >> x;
	cout << "Введите кординату y" << endl;//ВВод
	cin >> y;
	cout << "Введите радиус" << endl;//ВВод
	cin >> R;
	if ((x - R) * (x - R) + y * y <= R * R and x > 0 and y > 0)// Усдовие для первой четверти

	{
		cout << "Входит" << endl;
	}
	else
	{
		if (((x - R) * (x - R) + y * y >= R * R and x < 0 and y < 0 and y * y < R * R and x * x < R * R))//Условие для третьей четверти
		{
			cout << "Входит" << endl;
		}
		else
		{
			cout << "Не входит" << endl;
		}
	}


	return 0;
}