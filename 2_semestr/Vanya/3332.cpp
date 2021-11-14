#include <iostream>
#include <cmath>
#include <conio.h>
#include <Windows.h>
#pragma hdrstop
using namespace std;
char* rus(const char* text);//функци€ дл€ распозновани€ русских символов
int main(int argc, char* argv[])
{
	const int maxiter = 500;//объ€вление именованной константы (максимально допустимое колличество итераций)
	int n;//объ€вление переменной
	double x, eps = DBL_EPSILON;
	cout << rus("¬ведите любые значени€ х, где х измен€етс€ х<=1:") << endl;
	cout << rus("¬ведите аргумент х="); cin >> x;//ввод х
	long double arctg = 1, y = arctg;//объ€вление переменных дл€ работы с р€дом
	for (n = 0; fabs(arctg) > eps; n++)
	{
		arctg *= (-1 * x * x * (2 * n + 1)) / (2 * n + 3);//вычисление значени€ аргумента и функции
		y += arctg;
		if (n < maxiter)
		{
			cout << rus("\n «начение фунции y=") << y; cout << rus("дл€ х=") << x;//вывод
			cout << rus("¬ычислено после") << n + 1; cout << rus("итераций") << endl;//вывод
		}
		else
		{
			cout << rus("\n –€д расходитс€!");//выводитс€ сообщение если колличество итераций больше чем maxiter
			break;
		}
	}
	return 0;
}
char bufrus[256];
char* rus(const wchar_t* text)
{
	CharToOem(text, bufrus);
	return bufrus;
}
