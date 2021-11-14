#include <iostream>
#include <cmath>
#include <conio.h>
#include <Windows.h>
#pragma hdrstop
using namespace std;
char* rus(const char* text);//������� ��� ������������� ������� ��������
int main(int argc, char* argv[])
{
	const int maxiter = 500;//���������� ����������� ��������� (����������� ���������� ����������� ��������)
	int n;//���������� ����������
	double x, eps = DBL_EPSILON;
	cout << rus("������� ����� �������� �, ��� � ���������� �<=1:") << endl;
	cout << rus("������� �������� �="); cin >> x;//���� �
	long double arctg = 1, y = arctg;//���������� ���������� ��� ������ � �����
	for (n = 0; fabs(arctg) > eps; n++)
	{
		arctg *= (-1 * x * x * (2 * n + 1)) / (2 * n + 3);//���������� �������� ��������� � �������
		y += arctg;
		if (n < maxiter)
		{
			cout << rus("\n �������� ������ y=") << y; cout << rus("��� �=") << x;//�����
			cout << rus("��������� �����") << n + 1; cout << rus("��������") << endl;//�����
		}
		else
		{
			cout << rus("\n ��� ����������!");//��������� ��������� ���� ����������� �������� ������ ��� maxiter
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
