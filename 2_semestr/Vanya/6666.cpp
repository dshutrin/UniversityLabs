#include <iostream>
#include <math.h>
#include <conio.h>
#include <Windows.h>
#include <fstream>
#include <random>
#include <iomanip>
#pragma hdrstop
using namespace std;
char* rus(const char* text);
int main(int argc, char* argv[])
{
	ifstream fin("text.txt");
	if (!fin)
	{
		cout << rus("Oshibka otkririya fayla.") << endl;
		getch();
		return 1;
	}
	fin.seekg(0, ios::end);
	long len = fin.tellg();
	char* buf = new char[len + 1];
	char* buffer = new char[len + 1];
	fin.seekg(0, ios::beg);
	fin.read(buf, len);
	buf[len] = '\0';
	long n = 0, i = 0, j = 0, m = 0, cnt = 0, kol, num = 0;
	cout << rus("Vvedite kolli4estvo slov v predlojenii:"); cin >> kol;
	cout << endl;
	while (buf[i])
	{
		if (buf[i] == '.' || buf[i] == '?' || buf[i] == '!')
		{
			for (j = n, m + 0; j <= i; j++, m++)
			buffer[m] = buf[j];
			buffer[m] = '\0';
			int jpos = j;
			for (int k = 0; k, jpos; k++)
			{
				if (isalpha(buffer[k]))
				{
					if (isspace(buffer[k + 1]) || ispunct(buffer[k + 1]) || isdigit(buffer[k + 1]));
					cnt++;
				}
			}
			if (kol = cnt)
			{
				cout << buffer;
				num++;
			}
			cnt = 0;
			n = i + 1;
		}
		i++;
	}
	if (0 == num)cout << rus("Takih predlojeniy net!");
	fin.close();
	return 0;
}
char bufrus[256];
char* rus(const wchar_t* text)
{
	CharToOem(text, bufrus);
	return bufrus;
}